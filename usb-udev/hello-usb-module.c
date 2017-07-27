#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/usb.h>
#include <linux/hid.h>

static struct usb_driver hello_usb_driver = {
	.owner = THIS_MODULE,
	.name = "hello-usb-module",
	.id_table = id_table, 
	.probe = hello_probe,
	.disconnect = hello_disconnect,
};

static int __init hello_init(void)
{
	int retval;

	dev_info("hello-usb-module initialized!\n");
	retvalue = usb_register(&hello_usb_driver);
	
	if (retvalue)
		err("usb_register for hello_usb_driver. Error number %d\n", retval); 

	return retval;
}

static void __exit hello_exit(void)
{
	dev_info("Goodbye cruel Linux Drivers World!\n");
	usb_deregister(&hello_usb_driver);
}

const struct usb_device_id id_table = {
	{USB_INTERFACE_INFO(USB_INTERFACE_CLASS_HID, USB_INTERFACE_SUBCLASS_BOOT,
				USB_INTERFACE_PROTOCOL_KEYBOARD)},
	{},
};

MODULE_DEVICE_TABLE(usb, id_table);

static int hello_probe(struct usb_interface *interface, const struct usb_device_id *id)
{
	dev_info("USB Keyboard was plugged in!\n");
	return 0;
}

static int hello_disconnect(struct usb_interface *interface)
{
	dev_info("USB Keyboard was disconnected.\n");
	return 0;
}


module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPLV2");
