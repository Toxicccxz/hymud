// spear.c

#include <weapon.h>

inherit CLUB;

void create()
{
	set_name( "��ӧǹ", ({ "spear" }) );
	set_weight(6000);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "֦");
		set("long", "һ֦���ɶ�ĺ�ӧǹ��\n");
		set("value", 500);
		set("material", "iron");
		set("wield_msg", "$N����һ֦$n���������е���������\n");
		set("unwield_msg", "$N�������е�$n��\n");                
	}

	init_club(90);
	setup();
}