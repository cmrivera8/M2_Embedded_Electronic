CC:=gcc
RPI:=arm-buildroot-linux-uclibcgnueabihf-gcc

host: main.c
	$(CC) main.c -o main_pc.o

target:
	$(RPI) main.c -o main_rpi.o
	#scp ./main_rpi.o root@192.168.2.200:/root
	cp ./main_rpi.o /home/etudiant/nfs/main_rpi.o
	
clean:
	rm *.o
	
run:
	./main_pc.o

#Adding BR to PATH:
#export PATH=$PATH:/home/jmfriedt/buildroot-2021.08_redpit/output/host/usr/bin/
#Mounting NFS:
#mount 192.168.2.1:/home/etudiant/nfs /mnt
