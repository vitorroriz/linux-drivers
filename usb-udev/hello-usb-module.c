#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/usb.h>
#include <linux/hid.h>

/* A USB driver need to provide the USB subsystem with five things
 * .owner      - a pointer to the moduler that owns this driver 
 * .name       - the name of the USB driver
 * .id_table   - list of USB IDs for the hot-plug matching scheme
 * .probe      - a probe function called when there is a match
 * .disconnect - function called when the device is removed from the system
 */

const struct usb_device_id id_table[] = {
	{USB_INTERFACE_INFO(USB_INTERFACE_CLASS_HID, USB_INTERFACE_SUBCLASS_BOOT,
				USB_INTERFACE_PROTOCOL_KEYBOARD)},
	{},
};

MODULE_DEVICE_TABLE(usb, id_table);

static int hello_probe(struct usb_interface *interface, const struct usb_device_id *id)
{
	pr_info("USB Keyboard was plugged in!\n");
	return 0;
}

static void hello_disconnect(struct usb_interface *interface)
{
	pr_info("USB Keyboard was disconnected.\n");
}

static struct usb_driver hello_usb_driver = {
	.name = "hello-usb-module",
	.id_table = id_table, 
	.probe = hello_probe,
	.disconnect = hello_disconnect,
};

static int __init hello_init(void)
{
	int retval;

	pr_info("hello-usb-module initialized!\n");
	retval = usb_register(&hello_usb_driver);
	
	if (retval)
		pr_err("usb_register for hello_usb_driver. Error number %d\n", retval); 

	return retval;
}

static void __exit hello_exit(void)
{
	pr_info("Goodbye cruel Linux Drivers World!\n");
	usb_deregister(&hello_usb_driver);
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL");
