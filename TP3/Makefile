CC:=gcc
RPI:=arm-buildroot-linux-uclibcgnueabihf-gcc

pc: main.c
	$(CC) myioctl.c -o myioctl_pc.o

target:
	$(RPI) myioctl.c -o myioctl_rpi.o
	#scp ./myioctl_rpi.o root@192.168.2.200:/root
	cp ./myioctl_rpi.o /home/etudiant/nfs/myioctl_rpi.o
	
clean:
	rm *.o
	
run:
	./myioctl_pc.o

#Adding BR to PATH:
#export PATH=$PATH:/home/jmfriedt/buildroot-2021.08_redpit/output/host/usr/bin/
#Mounting NFS:
#mount 192.168.2.1:/home/etudiant/nfs /mnt
