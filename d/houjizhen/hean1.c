// hean.c
// by dicky

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "河岸");
        set("long", @LONG
这里是光秃秃的河岸，下面河流(river)湪急，四下都是乱坟，地
上一条蜿蜒的小路铺满了鹅卵石(shi)。往周围看去，北边有一座寺庙，
土堆成的城墙，很多处都已坍塌。
LONG);

        set("outdoors", "houjizhen");

        set("exits", ([
		"south" : __DIR__"muqiao",
		"north" : __DIR__"miao",
        ]));

	set("item_desc", ([
		"river" : "小河很宽，河水下面隐隐约约有什么东西。你看不清。\n",
		"shi":"一块块大大小小的鹅卵石，你忍不住想捡(jian)起来看看。\n",
	]));

        setup();
//	replace_program(ROOM);
}

void init()
{
      add_action("do_jump", "jump");
      add_action("do_jian", "jian");
}

int do_jump(string arg)
{
        object me;

        me=this_player();
        if (me->is_busy() || me->is_fighting())
                return notify_fail("你正忙着哪！\n");
        if ( !arg || arg != "river")
                return notify_fail("你要往哪跳？\n");
        message_vision(HIY"$N扑通一声，涌身跳入了冰冷的河流。\n"NOR, me);
        me->set("water", me->max_water_capacity()+ 100);
        me->move(__DIR__"hemian");
        tell_room(environment(me), me->name() + "从岸边跳了下来。\n", ({ me }));
        return 1;
}

int do_jian(string arg)
{
        object me,ob;
        me=this_player();
        if (me->is_busy() || me->is_fighting())
                return notify_fail("你正忙着哪！\n");
        if ( !arg || arg != "shi")
                return notify_fail("你要捡起什么？\n");
        if ((int)me->query_encumbrance() * 100 / (int)me->query_max_encumbrance() >= 92) 
                return notify_fail("你的负荷不了太多的东西了！\n");
        switch  (random(3)){
        case 0: ob = new(__DIR__"obj/shi1"); break;
        case 1: ob = new(__DIR__"obj/shi2"); break;
        case 2: ob = new(__DIR__"obj/shi3"); break;
        }
        ob->move(me);
        message_vision("$N弯下腰，从地上捡起了一块"+ob->name()+"。\n",me);
        return 1;
}

int get_object(object ob)
{
       return userp(ob);
}