#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

static int hello_init(void)
{
	pr_debug("Hello Kernel World!\n");
	return 0;
}

static void hello_exit(void)
{
	pr_debug("Goodbye Cruel Kernel World!\n");
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPLV2");
