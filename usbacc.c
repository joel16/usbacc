#include <common_imp.h>

SCE_MODULE_INFO("sceUSB_Acc_Driver", SCE_MODULE_KERNEL | SCE_MODULE_ATTR_EXCLUSIVE_LOAD | SCE_MODULE_ATTR_EXCLUSIVE_START, 1, 3);

// Function prototypes
int sceUsbAcc_internal_79A1C743(void)	__attribute__((alias("sceUsbAcc_79A1C743")));
int sceUsbAcc_79A1C743(void)	__attribute__((alias("sceUsbAcc_driver_79A1C743")));
int sceUsbAcc_driver_79A1C743(void);
int sceUsbAcc_internal_0CD7D4AA(void *buf)	__attribute__((alias("sceUsbAcc_0CD7D4AA")));
int sceUsbAcc_0CD7D4AA(void * buf)	__attribute__((alias("sceUsbAcc_driver_0CD7D4AA")));

// Imported Functions
extern unsigned int sceKernelCpuSuspendIntr(void);
extern void sceKernelCpuResumeIntr(u32 flags);
extern void sceKernelDcacheWritebackRange (const void *p, unsigned int size);
extern void sceKernelDcacheInvalidateRange(const void * p, unsigned int size);
extern int sceUsbbdReqSend(struct UsbdDeviceReq * req);	
extern int 	sceUsbbdUnregister(struct UsbDriver *drv);

/*
 Subroutine sceUsbAcc_internal_79A1C743 - Address 0x00000000 - Aliases: sceUsbAcc_79A1C743, sceUsbAcc_driver_79A1C743
 Exported in sceUsbAcc_internal
 Exported in sceUsbAcc
 Exported in sceUsbAcc_driver
*/
int sceUsbAcc_driver_79A1C743(void) { //sceUsbAccGetAuthStat
	int res = 0x80243007;
	u32 intrState = sceKernelCpuSuspendIntr(); //InterruptManagerForKernel_092968F4
	//0x28
	if (_lbu(0x0D53) != 0) {
		(sceUsbBus_driver_8A3EB5D2() == 0) ? res = 0x80243701 : res = 0;
	}
	sceKernelCpuResumeIntr(intrState); //InterruptManagerForKernel_5F10D406
	return res;
}

/*
 Subroutine sceUsbAcc_internal_0CD7D4AA - Address 0x00000068 - Aliases: sceUsbAcc_0CD7D4AA, sceUsbAcc_driver_0CD7D4AA
 Exported in sceUsbAcc_internal
 Exported in sceUsbAcc
 Exported in sceUsbAcc_driver
*/
int sceUsbAcc_internal_0CD7D4AA(u64 *buf) { //sceUsbAccGetInfo(u64 *buf);
	u32 intrState;
	s32 oldK1 = pspShiftK1();
	intrState = sceKernelCpuSuspendIntr(); //InterruptManagerForKernel_092968F4
	//0x9C
	if (_lbu(0x0D10 + 67) != 0) {
		//0xAC
		if (sceUsbBus_driver_8A3EB5D2() != 0) {
			//0xC0
			if (buf != 0) {
				//0xC8 - literal
				if ((((buf + 8) | buf) & (oldK1)) >= 0) {
					//0x104
					asm("lui $t0, 0x0");
					asm("addiu $t0, $t0, 3344");
					asm("lwl $v0, 3($t0)");
					asm("lwr $v0, 0($t0)");
					asm("lwl $v1, 7($t0)");
					asm("lwr $v1, 4($t0)");
					asm("swl $v0, 3(%0)" : "r" (buf));
					asm("swr $v0, 0(%0)" : "r" (buf));
					asm("swl $v1, 7(%0)" : "r" (buf));
					asm("swr $v1, 4(%0)" : "r" (buf));
					sceKernelCpuResumeIntr(intrState); //InterruptManagerForKernel_5F10D406
					return 0;
				}
			}
			//0xD0
			sceKernelCpuResumeIntr(intrState); //InterruptManagerForKernel_5F10D406
			return 0x80243002;
		}
		//0x12C
		sceKernelCpuResumeIntr(intrState); //InterruptManagerForKernel_5F10D406
		return 0x80243701;
	}
	//0x140
	sceKernelCpuResumeIntr(intrState); //InterruptManagerForKernel_5F10D406
	return 0x80243007;
}

/*
 Subroutine sceUsbAcc_internal_2A100C1F - Address 0x00000154 
 Exported in sceUsbAcc_internal
*/
int sceUsbAcc_internal_2A100C1F(int a0) { //sceUsbAcc_internal_2A100C1F(struct UsbdDeviceReq *req)
	int s0 = a0;
	int s1 = _lw(a0 + 4);
	//0x174
	if (_lbu(0x0D53) != 0) {
		//0x190
		if ((_lbu(s1 + 3) < 61) != 0) {
			sceKernelDcacheWritebackRange(s1, _lw(s0 + 8)); //UtilsForKernel_3EE30821
			_sw(0x0CAC, s0);
			_sw(_lbu(s1 + 3) + 4, s0 + 8);
			return sceUsbbdReqSend(s0); //sceUsbBus_driver_23E51D8F
		}
		//0x1C4
	return 0x80243002
}
	//0x1C4
	return 0x80243007;
}

/*
 Subroutine sceUsbAcc_internal_2E251404 - Address 0x000004AC 
 Exported in sceUsbAcc_internal
*/
int sceUsbAcc_internal_2E251404(int a0) { //sceUsbAccRegisterType(int arg 0);
	//0x4C8
	if (((_lhu(0x01D0) & 0xFFFF) & a0) == 0) {
		_sh(_lhu(0x01D0) | a0, 0x01D0 + 64);
		return 0;
	}
	//0x4D8
	return 0x80243001;
}

/*
 Subroutine sceUsbAcc_internal_18B04C82 - Address 0x000004E0 
 Exported in sceUsbAcc_internal
*/
int sceUsbAcc_internal_18B04C82(int a0) { //sceUsbAccUnRegisterType(int arg 0);
	//0x500
	if (((_lhu(0x1D10 + 64) & 0xFFFF) & a0) != 0) {
		_sh(_lhu(0x1D10 + 64) & ((~0) | (~a0)), 0x1D10 + 64);
		return 0;
	}
	//0x510
	return 0x80243005;
}

/*
 Subroutine module_start - Address 0x00000518 
 Exported in syslib 
*/
int module_start(void) {
	//0x534
	if (sceUsbBus_driver_B1644BE7(0x0CC4) >= 0) {
		_sh(0, 0x0D10 + 64);
		_sb(0, 0x0D10 + 66);
		return 0;
	}
	//0x548
	return 1;
}

/*
 Subroutine module_stop - Address 0x00000558 
 Exported in syslib
*/
int module_stop(void) {
	int res = sceUsbbdUnregister(0x0CCA); //sceUsbBus_driver_C1E2A540
	return (res < 0) ? 0 : res;
}

/*
 Subroutine sub_00000670 - Address 0x00000670 
*/
int sub_00000670(int a0, int a1, int a2, int a3) {
	int s0 = _lw(a2 + 4);
	int s1 = _lw(a2 + 8);
	int s2 = a1;
	int s3 = a0;
	int tempA = 0x0B84 | 16;	//t1
	int tempB = 0x0B84;
	_sw(a3, a2);
	_sw(a3 + 24, a2 + 4);
	_sw((a3 + 24) + 12, a2 + 8);
	_sw(a1, a2 + 12);
	//0x6D4
	if (((s2 | 0x0B84) & 0x3) != 0) {
		asm("move $a2, $s2");
		do {
			asm("lwl $v1, 3(%0)" : "r" (tempB));
			asm("lwr $v1, 0(%0)" : "r" (tempB));
			asm("lwl $a0, 7(%0)" : "r" (tempB));
			asm("lwr $a0, 4(%0)" : "r" (tempB));
			asm("lwl $a1, 11(%0)" : "r" (tempB));
			asm("lwr $a1, 8($%0)" : "r" (tempB));
			asm("lwl $a3, 15($%0)" : "r" (tempB));
			asm("lwr $a3, 12(%0)" : "r" (tempB));
			asm("swl $v1, 3($a2)");
			asm("swr $v1, 0($a2)");
			asm("swl $a0, 7($a2)");
			asm("swr $a0, 4($a2)");
			asm("swl $a1, 11($a2)");
			asm("swr $a1, 8($a2)");
			asm("swl $a3, 15($a2)");
			asm("swr $a3, 12($a2)");
			asm("addiu %0, %1, 16" : "r" (tempA) : "r" (tempA));
			asm("addiu $a2, $a2, 16");
		} while (tempA != tempB);
		//0x6E0
		asm("lwl $v0, 3(%0)" : "r" (tempB));
		asm("lwr $v0, 0(%0)" : "r" (tempB));
		asm("swl $v0, 3($a2)");
		asm("swr $v0, 0($a2)");
		goto end;
	}
	//0x864
	do {
	_sw(_lw(tempA), a2);
	a2 += 16;
	_sw(_lw(tempA + 4), a2 - 12);
	_sw(_lw(tempA + 8), a2 - 8);
	_sw(_lw(tempA + 12), a2 - 4);
	tempA += 16;
	} while (tempA != (0x0B84 | 16));
	//0x898
	_sw(_lw(0x0B84 | 16), a2);
	//0x740
	end: _sw(_lw(0x0B98), a3);
	_sw(_lw(0x0B98 + 4), a3 + 4);
	a2 = s1;
	_sw(_lw(0x0B98 + 8), a3 + 8);
	_sw(_lw(0x0B98 + 12), a3 + 12);
	_sw(_lw(0x0B98 + 16), a3 + 16);
	_sw(_lw(0x0B98 + 20), a3 + 20);
	_sw(_lw(0x0BB0), s0);
	_sw(_lw(0x0B98 + 4), s0 + 4);
	_sw(_lw(0x0BB0 + 8), s0 + 8);
	
	//0x7A4
	tempA = 0x0BBC;	// t5
	do {
		_sw(_lw(tempA), a2);
		a2 += 16;
		_sw(_lw(tempA + 4), a2 - 12);
		_sw(_lw(tempA + 8), a2 - 8);
		_sw(_lw(tempA + 12), a2 - 4);
		tempA += 16;
	} while (tempA != _lw(0x0B98 + 4));

	_sw(_lw(0x0BEC), a1);
	_sw(_lw(0x0BEC + 4), a1 + 4);
	_sw(_lw(0x0BEC + 8), a1 + 8);
	_sw(_lw(0x0BEC + 12), a1 + 12);
	_sw(_lw(0x0BEC + 16), a1 + 16);
	_sw(_lw(0x0BEC + 20), a1 + 20);
	_sw(_lw(0x0BEC + 24), a1 + 24);
	_sw(_lw(0x0BEC + 28), a1 + 28);
	_sw(s0, a3 + 12);
	_sw(s1, s0);
	s0 = 2;
	_sw(a1, s1 + 12);
	s1 = 64;
	_sb(a3, s2 + 7);
	//0x838
	if (s3 != 0) {
		_sh(s1, a1 + 4);
	}
	//0x844
	return a1 + 32;
}

// ok~
// Address 0x000001DC
int sub_001DC(int a0, int a1, int a2) {
	int s0 = a2;
	int s1 = 0x0D20;
	int s2;
	int i;
	int tempA;	// t0

	asm("lwl $v0, 3(%0)" : "r" (s0));
	asm("lwr $v0, 0(%0)" : "r" (s0));
	asm("lwl $v1, 7(%0)" : "r" (s0));
	asm("lwr $v1, 4(%0)" : "r" (s0));
	asm("swl $v0, -5(%0)" : "r" (s1));
	asm("swr $v0, -8(%0)" : "r" (s1));
	asm("swl $v1, -1(%0)" : "r" (s1));
	asm("swl $v1, -4(%0)" : "r" (s1));
	//0x21C
	if (a1 >= 0) {
		a0 = 0x0C0C;
		a2 = _lbu(s0) & 0xFF;
		for (i = 0; i < 2; i++) {
			tempA = _lbu(a0);
			//0x23C
			if (a2 == tempA) {	//FINISH
				//0x330
				if (_lbu(s0 + 1) != _lbu(a0 + 1)) {
					i++;
					continue;
				}
				a2 = 2;
				goto top;
			}
			a0 += 8;
		}
		top:
		//0x258
		if (a1 != 2) {
			asm("seb $a1, $a3");
			//0x264
			if (a1 >= 0) {
				//0x270
				if (_lbu(s0 + 1) == 1) {
					sceKernelDcacheInvalidateRange(_lw(s1 + 4), 64); //UtilsForKernel_BFA98062 
					sceUsbBus_driver_913EC15D(s1);
					_sw(64, s1 + 8);
					return 0;
				}
				//0x29C
				return -1;
			}
			//0x2B4
			s2 = _lbu(s0 + 1);
			//0x2BC
			if (s2 == 1) {
				int res = sceUsbBus_driver_48CCE3C1();
				//0x2CC
				if (res != 0) {
					//0x2E8 - literal
					if ((_lhu(0x0D50) & 0xFFFF) == (_lhu(0x0D50) & _lhu(s0 + 2))) {
						//0x31C
						_sb(0, _lw(s1 + 4));
						sceUsbBus_driver_FBA2072B();
						goto end;
					}
					s0 = _lw(s1 + 4);
				}
				//0x2F4
				_sb(s2, s0);
				_sw(s2, s1 + 8);
				end: sceKernelDcacheWritebackRange(_lw(s1 + 4), 1); //UtilsForKernel_3EE30821 
				sceUsbbdReqSend(s1); //sceUsbBus_driver_23E51D8F
				return 0;
			}
			//0x29C
			return -1;
		}
		//0x298
		return -1;
	}
	//0x298
	return -1;
}

//
// Address 0x00000340
int sub_00340(void) {
	u8 data[16] = 0;
	int s0 = 0x0CC4;
	int s1 = 0x0D10;
	int tempA;
	int tempB;
	int res = sceKernelCreateFpl("SceUsbAcc", 1, 0x100, 0x170, 1, 0); //ThreadManForKernel_C07BB470
	_sw(res, s1 + 60);
	//0x384
	if (res == 0) {
		//0x398
		if (sceKernelTryAllocateFpl(res, data) >= 0) { //ThreadManForKernel_623AE665
			_sw(data[0], s1 + 56);
			_sw(data[0] + 64, s0 + 16);
			_sw(data[0] + 84, s0 + 20);
			int res1 = sub_00000670(2, data[0] + 64, data[0] + 84, data[0] + 100);
			_sw(data[0] + 100, data[0]);

			_sw(res1, s0 + 24);
			_sw(res1 + 20, s0 + 28);
			_sw(res1 + 36, data[0]);
			res = sub_00000670(1, res1, res1 + 20, res1 + 36);
			
			_sw(res, data[0]);
			_sw(0, 0x0D10);
			_sw(0, s1 + 4);
			_sb(0, s1 + 67);

			//0x420 - Hue :B
			tempA = 0x0CA0 + 8;
			tempB = 1;
			do {
				tempB += -1;
				_sw(0, tempA);
				tempA++;
			} while (tempB >= 0);

			_sw(0x0CA0, 0x0D20);
			_sw(_lw(0x0D20 + 56), 0x0D20 + 4);
			_sw(64, 0x0D20 + 8);
			_sw(0x05B4, 0x0D20 + 16);
			_sw(0, 0x0D20 + 24);
			_sw(1, 0x0D20 + 12);
			_sw(0, 0x0D20 + 28);
			_sw(0, 0x0D20 + 32);
			_sw(0, 0x0D20 + 20)
			sceUsbBus_driver_90B82F55();
			_sb(1, (0x0D20 + -16) + 66);
			return 0;
			}
		//0x0x49C
		sceKernelDeleteFpl(_lw(s1 + 60)); //ThreadManForKernel_ED1410E0
		return -1;
	}
	//0x480
	return -1;
}

// ok~
// Address 0x0000057C
int sub_0057C(void) {
	int s0 = 0x0D10;
	sceUsbBus_driver_7B87815D();
	sceKernelDeleteFpl(_lw(s0 + 60)); //ThreadManForKernel_ED1410E0
	_sb(0, s0 + 66);
	return 0;
}

// ok~
// Address 0x000005B4
void sub_005B4(int a0) {
	int temp;
	//0x5BC
	if (_lw(a0 + 24) == 0) {
		//0x5C8
		if (_lb(0x0D10 + 8) >= 0) {
			//0x5D4
			if (_lbu(0x0D10 + 9) == 1) {
				temp = _lw(a0 + 4);
				asm("lui $t0, 0x0");
				asm("addiu $t0, $t0, 3344");
				asm("lwl $v1, 3(%0)" : "r=" (temp));
				asm("lwr $v1, 0(%0)" : "r=" (temp));
				asm("lwl $a0, 7(%0)" : "r=" (temp));
				asm("lwr $a0, 4(%0)" : "r=" (temp));
				asm("swl $v1, 3($t0)");
				asm("swr $v1, 0($t0)");
				asm("swl $a0, 7($t0)");
				asm("swr $a0, 4($t0)");
				return;
			}
			//0x5DC
			return;
		}
		//0x5DC
		return;
	}
	//0x5DC
	return;
}

// ok~
// Address 0x0000060C
void sub_0060C(void) {
	//0x618
	if (_lbu(0x0D10 + 67) == 0) {
		_sb(1, 0x0D10 + 67);
	}
	//0x624
	return;
}

// ok~
// Address 0x0000062C
void sub_0062C(void) {
	int tempA = 1;
	int tempB = 0;
	//0x638
	if (_lbu(0x0D10 + 67) != 0) {
		_sw(0, 0x0D10 + 4);
		_sb(0, 0x0D10 + 67);
		_sw(0, 0x0D10);
		do {
			tempA--;
			_sw(0, (0x0CA0 + 8) + tempB);
			tempB += 12;
		} while (tempA >= 0);
	}
	//0x668
	return;
}