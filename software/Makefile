CC=/opt/hisi-linux-nptl/arm-hisiv100-linux/bin/arm-hisiv100-linux-uclibcgnueabi-gcc
LD=/opt/hisi-linux-nptl/arm-hisiv100-linux/bin/arm-hisiv100-linux-uclibcgnueabi-ld

CFLAGS=-lcrypto -ldvr -pthread -L ./libs -DLIBCRYPTV1
#CFLAGS=-lcryptoV2 -ldvr -pthread -L ./libs -DLIBCRYPTV2

all: encrypt_ar030 encrypt_imx122 encrypt_imx122_fm encrypt_imx122_new encrypt_imx278_fm decrypt

encrypt_ar030:
	$(CC) $(CFLAGS) -DCMOS_AR030 encrypt.c -o encrypt_ar030
encrypt_imx122:
	$(CC) $(CFLAGS) -DCMOS_IMX122 encrypt.c -o encrypt_imx122
encrypt_imx122_fm:
	$(CC) $(CFLAGS) -DCMOS_IMX122_FM encrypt.c -o encrypt_imx122_fm
encrypt_imx122_new:
	$(CC) $(CFLAGS) -DCMOS_IMX122_NEW encrypt.c -o encrypt_imx122_new
encrypt_imx278_fm:
	$(CC) $(CFLAGS) -DCMOS_IMX278_FM encrypt.c -o encrypt_imx278_fm


decrypt:
	$(CC) $(CFLAGS) decrypt.c -o decrypt

clean:
	rm -f decrypt
	rm -f encrypt_ar030
	rm -f encrypt_imx122
	rm -f encrypt_imx122_fm
	rm -f encrypt_imx122_new
	rm -f encrypt_imx278_fm
