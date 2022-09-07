obj-m += mymod.o
BR:=/home/jmfriedt/buildroot-2021.08_redpit

host:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD)  modules

target:
	make ARCH=arm CROSS_COMPILE=arm-linux- -C $(BR)/output/build/linux-xilinx-v2019.1 \
	M=$(PWD) modules
	cp ./mymod.ko /home/etudiant/nfs/mymod.ko

clean:
	rm ./*.mod* ./*.ko ./*.symvers ./*.order ./*.o
