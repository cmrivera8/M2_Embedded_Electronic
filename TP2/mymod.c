#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/init.h>
//Second part:
#include<linux/fs.h>
#include<linux/uaccess.h>

//First part
static int my_open(struct inode *inod,struct file *fil);
static int my_release(struct inode *inod,struct file *fil);
//Second part
static ssize_t my_read(struct file *fil,char *buff,size_t len,loff_t *off);
static ssize_t my_write(struct file *fil,const char *buff,size_t len,loff_t *off);
//Third part
static long my_ioctl(struct file *f, unsigned int cmd, unsigned long arg);

char buf[15]="Hello read\n\0";

// First part: Inserting module
int hello_start(void);
void hello_end(void);

// Second part: Communication
static struct file_operations fops=
{
	.read=my_read,
	.open=my_open,
	.release=my_release,
	.write=my_write,
	.unlocked_ioctl=my_ioctl,
};

static int my_open(struct inode *inod,struct file *fil){
	printk(KERN_INFO "Test open\n");
	return 0;
}

static int my_release(struct inode *inod,struct file *fil){
	printk(KERN_INFO "Test release\n");
	return 0;
}

//Read and write
static ssize_t my_read(struct file *fil,char *buff,size_t len,loff_t *off){
	printk(KERN_INFO "Test read\n");
	//Printing to cat the content of "buf" = "Hello read"
	int readPos=0;
	while (len && (buf[readPos]!=0)){
		put_user(buf[readPos],buff++);
		readPos++;
		len--;
	}
	//
	return readPos;
}
static ssize_t my_write(struct file *fil,const char *buff,size_t len,loff_t *off){
	printk(KERN_INFO "Test write\n");
	//Printing to dmesg an echo of the written text
	int i=0;
	int mylen;
	if (len>14) mylen=14; else mylen=len;
	for (i=0;i<mylen;i++) get_user(buf[i],buff+i);
	buf[mylen]=0;
	printk(KERN_ALERT "%s \n",buf);
	//
	return len;
}

//Third part: Adding ioctl
static long my_ioctl(struct file *f, unsigned int cmd, unsigned long arg){
	switch(cmd)
		case 0: printk(KERN_ALERT "ioctl 0");break;
		case 1: printk(KERN_ALERT "ioctl 1");break;
		default 0: printk(KERN_ALERT "unknown ioctl");break;
	return 0;
}



int hello_start(void){
	printk(KERN_INFO "Hello\n");
	// Second part
	register_chrdev(91,"ppp", &fops);
	return 0;
}

void hello_end(void){
	printk(KERN_INFO "Goodbye\n");
	// Second part
	unregister_chrdev(91,"ppp");
}

module_init(hello_start);
module_exit(hello_end);
MODULE_LICENSE("GPL");
