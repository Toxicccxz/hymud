// gouzhizi.c ������

inherit ITEM;
#include <ansi.h>

void init()
{
	add_action("do_eat", "eat");
	add_action("do_eat", "fu");
}

void create()
{
	set_name(HIR"������"NOR, ({"gouzhizi"}));
	set_weight(500);
	set("vegetable", 2);
	set("value", 30);
	set("nostrum", 32);
	set("unit", "��");
	set("long", "����һ������������ӣ�����������ҩ��\n");
	set("pour_type", "1");set("yaocao",1);
	setup();
}

int do_eat(string arg)
{
	object me = this_player();

	if(!id(arg)) return notify_fail("��Ҫ��ʲô��\n");
	if(!present(this_object(), me))
		return notify_fail("��Ҫ��ʲô��\n");
	if( me->is_busy() )
		return notify_fail("�𼱣������ԣ�С�ı�ҭ���ˡ�\n");

	write("��������ҩ���ܳԡ�\n");
	return 1;
}