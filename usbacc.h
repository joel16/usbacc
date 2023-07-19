/* Copyright (C) 2023 The uOFW team
   See the file COPYING for copying permission.
*/

#ifndef _USBACC_H
#define _USBACC_H

typedef struct SceUsbInfoParam {
    int unk0;
    int unk1;
} SceUsbInfoParam;

// Some error codes are derived from -> https://github.com/xerpi/psp-uvc-usb-video-class/blob/master/include/usb.h
#define SCE_ERROR_USB_INVALID_ARGUMENT        0x80243002
#define SCE_ERROR_USB_DRIVER_NOT_FOUND        0x80243005
#define SCE_ERROR_USB_BUS_DRIVER_NOT_STARTED  0x80243007
#define SCE_USBACC_ERROR_INVALID_ACCESSORY    0x80243701

#endif /* _USBACC_H */
