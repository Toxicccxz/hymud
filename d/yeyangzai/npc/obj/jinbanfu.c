// blade.c

#include <weapon.h>
#include <ansi.h>

inherit AXE;

void create()
{
	set_name("金板斧",({"jinbanfu","jinban fu","fu","axe"}));
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("value",3000);
		set("material", "iron");
		set("long","一把沉甸甸的大斧头，可用做第二武器装备。\n");
		set("wield_msg","$N从腰间拔出一把沉甸沉的$n握在手中。\n");
		set("unequip_msg","$N将手中的$n插于腰间。\n");
	}
	init_axe(180);
	setup();
}
