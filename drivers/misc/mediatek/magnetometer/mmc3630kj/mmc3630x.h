/*
 * Definitions for mmc3630x magnetic sensor chip.
 */
#ifndef __MMC3630x_H__
#define __MMC3630x_H__

#include <linux/ioctl.h>

#define MMC3630x_I2C_NAME		"mmc3630x"
#define CALIBRATION_DATA_SIZE	12
#define SENSOR_DATA_SIZE 9
#ifndef TRUE
	#define TRUE 1
#endif
#define MMC3630x_I2C_ADDR		0x60	// 8-bit    7-bit  0x30

/* MMC3630x register address */
#define MMC3630X_REG_CTRL		0x08
#define MMC3630X_REG_BITS		0x09
#define MMC3630X_REG_DATA		0x00
#define MMC3630X_REG_DS			0x07
//#define MMC3630X_REG_PRODUCTID_0		0x2F
#define MMC3630X_REG_PRODUCTID_1		0x2F

/* MMC3630x control bit */
#define MMC3630X_CTRL_TM			0x01
#define MMC3630X_CTRL_CM			0x02
#define MMC3630X_CTRL_50HZ		0x00
#define MMC3630X_CTRL_25HZ		0x04
#define MMC3630X_CTRL_12HZ		0x08
//<--[SM31][Sensors][JasonHsing] Fix M-sensor memsic3630 magnetic interference 20161024 BEGIN --
#define MMC3630X_CTRL_SET  	        0x08
#define MMC3630X_CTRL_RESET              0x10
#define MMC3630X_CTRL_REFILL             0x20
//-->[SM31][Sensors][JasonHsing] Fix M-sensor memsic3630 magnetic interference 20161024 END --
#define MMC3630X_BITS_SLOW_16            0x00
#define MMC3630X_BITS_FAST_16            0x01
#define MMC3630X_BITS_14                 0x02

// conversion of magnetic data (for mmc3630x) to uT units
// conversion of magnetic data to uT units
// 32768 = 1Guass = 100 uT
// 100 / 32768 = 25 / 8192
// 65536 = 360Degree
// 360 / 65536 = 45 / 8192


#define CONVERT_M			25
#define CONVERT_M_DIV		8192
#define CONVERT_O			45
#define CONVERT_O_DIV		8192

// sensitivity 512 count = 1 Guass = 100uT

#define MMC3630X_OFFSET_X		32768
#define MMC3630X_OFFSET_Y		32768
#define MMC3630X_OFFSET_Z		32768
#define MMC3630X_SENSITIVITY_X		1024
#define MMC3630X_SENSITIVITY_Y		1024
#define MMC3630X_SENSITIVITY_Z		1024



#define MMC3630X_MODE_SNG_MEASURE	0x01
#define MMC3630X_MODE_SELF_TEST		0x10
#define MMC3630X_MODE_FUSE_ACCESS	0x1F
#define MMC3630X_MODE_POWERDOWN		0x00
#define MMC3630X_RESET_DATA			0x01
#define COMPAT_MMC3630X_IOC_READ_REG           _IOWR(MSENSOR, 0x32, unsigned char)
#define COMPAT_MMC3630X_IOC_WRITE_REG          _IOW(MSENSOR, 0x33, unsigned char[2])
#define COMPAT_MMC3630X_IOC_READ_REGS          _IOWR(MSENSOR, 0x34, unsigned char[10])
#define MMC3630X_IOC_READ_REG		    _IOWR(MSENSOR, 0x23, unsigned char)
#define MMC3630X_IOC_WRITE_REG		    _IOW(MSENSOR,  0x24, unsigned char[2])
#define MMC3630X_IOC_READ_REGS		    _IOWR(MSENSOR, 0x25, unsigned char[10])
#endif /* __MMC3630x_H__ */

