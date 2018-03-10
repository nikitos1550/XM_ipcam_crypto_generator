#!/bin/sh

#ENCRYPT="/opt/encrypt_ar030"
#ENCRYPT="/opt/encrypt_imx122"
#ENCRYPT="/opt/encrypt_imx122_fm"
ENCRYPT="/opt/encrypt_imx122_new"
#ENCRYPT="/opt/encrypt_imx278_fm"

PRE="00:12:14:01:"
ITR=1
AMOUNT=10

echo "#!/bin/sh"

for i in `seq 1 254`
do
	for j in `seq 1 254`
	do
		MAC=${PRE}`printf '%02X' ${i}`:`printf '%02X' ${j}`
		echo ${ENCRYPT} ${MAC} #echo ${PRE}${i}:${j}

		if [ $ITR -eq $AMOUNT ]
		then
			exit
		fi
		ITR=`expr ${ITR} + 1`
		#echo ${ITR}
	done
done
