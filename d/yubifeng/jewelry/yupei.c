// yupei.c ����

#include <armor.h>
#include <ansi.h>

inherit NECK;

void create()
{
	set_name(HIC"����"NOR, ({ "yu pei", "yu" }));
	set("long", "����һ�鵭��ɫ�ı���Ө�����󣬹����覣�����ϡ�����С�\n");
	set("weight", 300);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "ö");
		set("value", 10000);
		set("material", "��");
		set("armor_prop/armor", 32);
		set("female_only", 1);
	}
	setup();
}	

