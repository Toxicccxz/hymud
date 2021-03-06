// Room: /d/jinghai/jhd25.c

inherit ROOM;

void create()
{
	set("short", "山庄厨房");
	set("long", @LONG
锅盆叮当声中，你走进了靖海府的厨房，只见数十位厨师和
仆役在忙碌着，这里的蔬菜水果都是岛上产的居多，有时也到陆
地上去采购一些岛上缺乏的物品，这里的厨师手艺极佳，尤其是
靖海派厨师手炙的鱼翅更是天下一绝。想要喝水可以用勺舀着水
缸里的水(drink)。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"jhd23",
]));

        set("objects", ([
            __DIR__"obj/mifan"       : 10,
]));

	setup();
}

void init()
{
        add_action("do_drink", "drink");
}

int do_drink(string arg)
{
        object me = this_player();

        if( (int)me->query("water") >= (int)me->max_water_capacity() )
                return notify_fail("你已经再也喝不下一滴水了。\n");

        message_vision("$N在水缸边用杯子舀起水喝了几口。\n", me);
        me->add("water", 20);
        return 1;
}
