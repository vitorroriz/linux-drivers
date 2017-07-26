ifneq ($(KERNELRELEASE),)
	obj-m:= hello_mod.o
else
	KERNELDIR ?= /lib/modules/$(shell uname -r)/build
	PWD := $(shell pwd)

default:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules
clean:
	$(MAKE) -c $(KERNELDIR) M=$(PWD) clean
endif

