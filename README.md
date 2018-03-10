# XM_ipcam_crypto_generator
Generator of crypto data for XM ip cameras

Sometimes crypto data is stored in additional 1024 i2c eeprom chip (called FM chip), sometimes in main spi memory chip with offset 0x1fc00.

Crypto data contains MAC address and device info

## Struct

`000 * * * * * * * *	* * * * * * * *`<br />
`010 * * * * * * * *   [d d d d M M M M`<br />
`020 M M d d d d d d	d d d d d d d d`<br />
`030 d d d d d d d d	d d d d d d d d`<br />
`040 d d d d d d d d	d d d d d d d d`<br />
`050 d d d d d d d d]	* * * * * * * * MD5 hash block1`<br />
`060 * * * * * * * *	* * * * * * * *`<br />
`070 * * * * * * * *	* * * * * * * *`<br />
`080 * * * * * * * *	* * * * * * * *`<br />
`090 * * * * * * * *	X X X X X X X X`<br />
`0a0 X X X X X X X X	X X X X X X X X`<br />
`0b0 X X X X X X X X	X X X X X X X X`<br />
`0c0 X X X X X X X X	X X X X X X X X`<br />
`0d0 X X X X X X X X	* * * * * * * *`<br />
`0e0 * * * * * * * *	* * * * * * * *`<br />
`0f0 * * * * * * * *	* * * * * * * *`<br />
`100 * * * * * * * *	* * * * * * * *`<br />
`110 * * * * * * * *	* * * * * * * *`<br />
`120 * * * * * * * *	* * * * * * * *`<br />
`130 * * * * * * * *   [d d d d d d d d`<br />
`140 d d d d d d d d	d d d d d d d d`<br />
`150 d d d d d d d d	d d d d d d d d`<br />
`160 d d d d d d d d	d d d d d d d d`<br />
`170 d d d d d d d d]	* * * * * * * * CRC T16`<br />
`180 * * * * * * * *	* * * * * * * *`<br />
`190 * * * * * * * *	* * * * * * * *`<br />
`1a0 * * * * * * * *	* * * * * * * *`<br />
`1b0 * * * * * * * *	X X X X X X X X`<br />
`1c0 X X X X X X X X	X X X X X X X X`<br />
`1d0 X X X X X X X X	X X X X X X X X`<br />
`1e0 X X X X X X X X	X X X X X X X X`<br />
`1f0 X X X X X X X X	* * * * * * * *`<br />
`200 * * * * * * * *	* * * * * * * *`<br />
`210 * * * * * * * *	* * * * * * * *`<br />
`220 * * * * * * * *	* * * * * * * *`<br />
`230 * * * * * * * *	* * * * * * * *`<br />
`240 * * * * * * * *	* * * * * * * *`<br />
`250 * * * * * * * *   [d d d d d d d d`<br />
`260 d d d d d d d d	d d d d d d d d`<br />
`270 d d d d d d d d	d d d d d d d d`<br />
`280 d d d d d d d d	d d d d d d d d`<br />
`290 d d d d d d d d]	* * * * * * * * CRC T16`<br />
`2a0 * * * * * * * *	* * * * * * * *`<br />
`2b0 * * * * * * * *	* * * * * * * *`<br />
`2c0 * * * * * * * *	* * * * * * * *`<br />
`2d0 * * * * * * * *	X X X X X X X X`<br />
`2e0 X X X X X X X X	X X X X X X X X`<br />
`2f0 X X X X X X X X	X X X X X X X X`<br />
`300 X X X X X X X X	X X X X X X X X`<br />
`310 X X X X X X X X	* * * * * * * *`<br />
`320 * * * * * * * *	* * * * * * * *`<br />
`330 * * * * * * * *	* * * * * * * *`<br />
`340 * * * * * * * *	* * * * * * * *`<br />
`350 * * * * * * * *	* * * * * * * *`<br />
`360 * * * * * * * *	* * * * * * * *`<br />
`370 * * * * * * * *   [d m d m d m d m`<br />
`380 d m d m d d d d	d d d d d d d d`<br />
`390 d d d d d d d d	d d d d d d d d`<br />
`3a0 d d d d d d d d	d d d d d d d d`<br />
`3b0 d d d d d d d d]	* * * * * * * * MD5 hash block4`<br />
`3c0 * * * * * * * *	* * * * * * * *`<br />
`3d0 * * * * * * * *	* * * * * * * *`<br />
`3e0 * * * * * * * *	* * * * * * * *`<br />
`3f0 * * * * * * * *	* * * * * * * * CRC T16`

* \* any data
* X data that taked into account for CRC/MD5 calculation
* M,m MAC data
* Device info seems to be in first bytes, check encrypt.c to compare different versions of devices

---

**Tests were done on hi3516cv100(hi3518cv100) based cameras, but same method supposed to work on all XM devices. arm-hisiv100-linux toolchain from original HiSilicon SDK was used for cross compilation.**

* software/decrypt.c    util for check 1024 bytes crypto data
* software/encrypt.c	crypto generator
* software/bin/encrypt_*			precompiled binaries
* rootfs_toburn						rootfs for hi3516cv100/hi3518cv100 (all crypto related software is in /opt dir)

>Example usage: encrypt_imx122 XX:XX:XX:XX:XX:XX _(util will generate .enc file in current dir)_

# How to generate crypto with new MAC
**Supposed you have hi3516cv100/hi3518cv100 device with burned uImage/rootfs.romfs from this repo**

#### Prepare FAT32 USB FLASH
1. Put file generate_task.sh
2. Edit generate_task.sh:
choose which encryption tool to use
edit first 4 bytes for MAC

#### Start camera module and connect via USB-Serial adapter (115200 speed)
1. run `/opt/mount_usb.sh`
2. run `cd /mnt`
3. run `./generate_task.sh > ./do.sh`
4. run `sh ./do.sh`
5. Wait...
6. run `cd /`
7. run `/opt/umount_usb.sh`

#### Unplug power, take off usb flash
