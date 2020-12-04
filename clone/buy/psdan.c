// shenliwan.c 福缘丹

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIG "平民丹" NOR, ({ "ps wan", "wan"}) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", "一颗七彩的平民丹，据说吃了可以改变你的师门。\n");
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
int max;
        if (! id(arg))
                return notify_fail("你要吃什么？\n");

        me = this_player();
        max = me->query_skill("force")*10 + me->query("combat_exp")/1000;
        message_vision("$N一仰脖，吞下了一颗" + this_object()->name() +
                       "。\n", me);

        me->delete("family");
        me->delete("class");
        me->delete("quest");
        me->delete("quest_count");
        me->set("title", "普通百姓");
        me->set("class","0");
        me->delete("party");
//me->clear_condition("killer");
tell_object(me, HIR "你觉得似乎自己发生了变化。\n" NOR);

        destruct(this_object());
	return 1;
}
