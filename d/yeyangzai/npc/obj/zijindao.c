// blade.c

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
	set_name(MAG"紫金剑"NOR,({"zijindao","sword","jian"}));
	set_weight(9000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("value",3000);
		set("material", "iron");
		set("long","传说是西域冶炼高手打造的兵器，十分沉重。\n");
		set("wield_msg","$N一按剑柄，$n“噌”的一声跃入$N的手中。\n");
		set("unequip_msg","$N右手微抬，手中$n“嗖”的一下钻入剑鞘中。\n");
	}
        init_sword(90);
	setup();
}
