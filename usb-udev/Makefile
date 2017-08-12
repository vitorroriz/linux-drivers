ifneq ($(KERNELRELEASE),)
	obj-m:= hello-usb-module.o 
else
	KERNELDIR ?= /lib/modules/$(shell uname -r)/build
	PWD := $(shell pwd)

default:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules
clean:
	$(MAKE) -c $(KERNELDIR) M=$(PWD) clean
endif

