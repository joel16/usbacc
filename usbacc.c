/* Copyright (C) 2023 The uOFW team
   See the file COPYING for copying permission.
*/

#include <common_imp.h>
#include <interruptman.h>
#include <sysmem_utils_kernel.h>
#include <usbbus.h>
#include "usbacc.h"

SCE_MODULE_INFO("sceUSB_Acc_Driver", SCE_MODULE_KERNEL | SCE_MODULE_ATTR_EXCLUSIVE_LOAD | SCE_MODULE_ATTR_EXCLUSIVE_START, 1, 3);
SCE_SDK_VERSION(SDK_VERSION);

// Globals
struct UsbDriver g_drv;      // 0x00000CC4
u32 g_unk0;                  // 0x00000D10
u32 g_unk1;                  // 0x00000D14
u8 g_usbBusDriverStarted;    // 0x00000D53
u16 g_type;                  // 0x00000D50
u8 g_unk2;                   // 0x00000D52
struct UsbdDeviceReq *g_req; // 0x00000CAC

// Subroutine sceUsbAccGetAuthStat - Address 0x00000000 - Aliases: sceUsbAcc_79A1C743, sceUsbAcc_driver_79A1C743 -- Done
// Exported in sceUsbAcc_internal, sceUsbAcc and sceUsbAcc_driver
s32 sceUsbAccGetAuthStat(void)
{
    int intr = sceKernelCpuSuspendIntr();
    s32 ret = 0;
    
    if (g_unk0) {
        if (sceUsbBus_driver_8A3EB5D2() == 0) {
            ret = SCE_USBACC_ERROR_INVALID_ACCESSORY;
        }
    }
    else {
        ret = SCE_ERROR_USB_BUS_DRIVER_NOT_STARTED;
    }
        
    sceKernelCpuResumeIntr(intr);
    return ret;
}

// Subroutine sceUsbAccGetInfo - Address 0x00000068 - Aliases: sceUsbAcc_0CD7D4AA, sceUsbAcc_driver_0CD7D4AA
// Exported in sceUsbAcc_internal, sceUsbAcc and sceUsbAcc_driver
s32 sceUsbAccGetInfo(SceUsbInfoParam *param)
{
    s32 ret = 0;
    s32 oldK1 = pspShiftK1();
    int intr = sceKernelCpuSuspendIntr();
    
    if (g_usbBusDriverStarted) {
        if (sceUsbBus_driver_8A3EB5D2() != 0) {
            if (param != NULL && pspK1StaBufOk(param, sizeof(SceUsbInfoParam))) {
                param->unk0 = g_unk0;
                param->unk1 = g_unk1;
            }
            else {
                ret = SCE_ERROR_USB_INVALID_ARGUMENT;
            }
        }
        else {
            ret = SCE_USBACC_ERROR_INVALID_ACCESSORY;
        }
    }
    else {
        ret = SCE_ERROR_USB_BUS_DRIVER_NOT_STARTED;
    }

    sceKernelCpuResumeIntr(intr);
    pspSetK1(oldK1);
    return ret;
}

// Subroutine sceUsbAcc_internal_2A100C1F - Address 0x00000154 -- TODO: Verify
// Exported in sceUsbAcc_internal
s32 sceUsbAcc_internal_2A100C1F(struct UsbdDeviceReq *req)
{
    s32 ret = 0;
    u8 *data = req->data;

    if (g_usbBusDriverStarted) {
        if ((data[3]) < 0x3D) {
            sceKernelDcacheWritebackRange(data, req->size);
            *req = *g_req;
            req->size = data[3] + 4;
            ret = sceUsbbdReqSend(req);
        }
        else {
            ret = SCE_ERROR_USB_INVALID_ARGUMENT;
        }
    }
    else {
        ret = SCE_ERROR_USB_BUS_DRIVER_NOT_STARTED;
    }
    
    return ret;
}

// Subroutine sceUsbAccRegisterType - Address 0x000004AC -- Done
// Exported in sceUsbAcc_internal
s32 sceUsbAccRegisterType(u16 type)
{
    s32 ret = 0;

    if ((g_type & type) == 0) {
        g_type = g_type | type;
    }
    else {
        ret = SCE_ERROR_USB_DRIVER_NOT_FOUND;
    }
    
    return ret;
}

// Subroutine sceUsbAccUnregisterType - Address 0x000004E0 -- Done
// Exported in sceUsbAcc_internal
s32 sceUsbAccUnregisterType(u16 type)
{
    s32 ret = 0;
    
    if ((g_type & type) != 0) {
        g_type = g_type & ~type;
    }
    else {
        ret = SCE_ERROR_USB_DRIVER_NOT_FOUND;
    }
    
    return ret;
}

// Subroutine module_start - Address 0x00000518 -- Done
s32 module_start(SceSize args __attribute__((unused)), void *argp __attribute__((unused)))
{
    if ((sceUsbbdRegister(&g_drv)) >= 0) {
        g_type = 0;
        g_unk2 = 0;
        return 0;
    }
    
    return 1;
}

// Subroutine module_stop - Address 0x00000558 -- Done
s32 module_stop(SceSize args __attribute__((unused)), void *argp __attribute__((unused)))
{
    if (sceUsbbdUnregister(&g_drv) >= 0)
        return 0;

    return 1;
}
