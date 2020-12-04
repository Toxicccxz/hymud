// shenliwan.c 福缘丹

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIG "回春丹" NOR, ({ "hc wan", "wan"}) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", "一颗七彩的回春丹，据说吃了可以回春。\n");
                set("value", 10000);
		set("no_put",1);
		set("unit", "颗");
	}
}

void init()
{
	add_action("do_eat", "eat");
}

int do_eat(string arg)
{
	object me;

        if (! id(arg))
                return notify_fail("你要吃什么？\n");

        me = this_player();
        message_vision("$N一仰脖，吞下了一颗" + this_object()->name() +
                       "。\n", me);

                tell_object(me, HIR "你觉得似乎自己发生了变化。\n" NOR);
                me->set("age", 18);
                me->set("mud_age",400000);

        destruct(this_object());
	return 1;
}
