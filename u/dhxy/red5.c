// lingzhi.c ǧ����֥
//����(lywin)2000/4/22

#include <ansi.h>
inherit ITEM;

void setup()
{}

void init()
{
      add_action("do_eat", "smile")
;

}
void create()
{
set_name(HIC"������"NOR, ({"duu"}))
;
	if (clonep())
		set_default_object(__FILE__);
	else {
//set("no_give","ÿ����ֻ��һ�����㶼��ô�󷽣�\n")
//d
set("value", 50000)
;
//set("liwu",1)
set("no_steal",1);
set("no_beg",1)
;
//set("no_put",1)
//
//set("no_get","ÿ����ֻ��һ������Ҫ��ô̰�ģ�\n")
    set("no_drop","��ô���Ķ�����Ҳ�ӣ���\n");

                set("unit", "��");
;

set("value", 50000)
;
	}
	setup();
}

int do_eat(string arg)
{
	if (!id(arg))
      return notify_fail("��Ҫ��˭΢Ц��\n")
;
        this_player()->start_busy(20);
        this_player()->add("max_neili",10);
        this_player()->add("potential",500);
this_player()->add("combat_exp",1000)
;
this_player()->add("expmax",1)
;
message_vision("$N������������һЦ����е�����������\n", this_player())
;
	destruct(this_object());
	return 1;
}

void owner_is_killed()
{
	destruct(this_object());
}