inherit ITEM;
#include <ansi.h>
void init()
{
	add_action("do_find", "findbook");
}
void create()
{
	set_name(HIR"��"+HIC+"��"+HIY+"��"+HIM+"��"+HIG+"ʯ"NOR, ({"xdshi"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("no_put",1);
		set("no_drop",1);
		set("long", "����������������λ�õ���ʯ���������(findbook)��������\n");
		set("no_pawn",1);
	}
	setup();
}
int do_find(string str)
{
        object me =this_player();
	string output = "";
        if(!str) return notify_fail("ָ���ʽ: findbook <��Ʒ>\n");
      if( me->is_busy() )
      return notify_fail("����æ���أ�\n");  
	output = ("/adm/daemons/questd")->locate_obj(str);
	write(output);
me->start_busy(1);
	return 1;
}
