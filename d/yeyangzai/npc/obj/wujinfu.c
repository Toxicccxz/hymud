// blade.c

#include <weapon.h>
#include <ansi.h>

inherit AXE;

void create()
{
	set_name(RED"乌金斧"NOR,({"wujinfu","fu","axe"}));
	set_weight(12000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("value",5000);
		set("material", "iron");
		set("long","微微发出金光的大斧头。可以作为第二兵器装备。\n");
		set("wield_msg","$N从身后抽出$n，在胸前晃了两晃。\n");
		set("unequip_msg","$N手腕微转，将$n插入身后。\n");
	}
	init_axe(190);
	setup();
}
