
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"岩盘的裂目"NOR);
	set("long", HIY @LONG
    你现在在一个黑暗潮湿的洞穴里，不过奇怪的是虽然这里弥漫著很重
的湿气，墙壁上却是一点青苔也没有。处於这个阴森森的洞穴里，你不由
得打了个机伶伶的冷战 .... 你觉得还是赶快离开这个鬼地方比较好。
LONG NOR);
set("magicroom",1);set("outdoors","migong");
set("magicset",1);
	set("exits", ([
		"west" : __DIR__"dong42",
                "east" : __DIR__"dong3"+(random(9)+1),
		"south" : __DIR__"dong3"+(random(9)+1),
                "north" : __DIR__"dong47",
	]));
if (random(3)==0)
	set("exits", ([
		"east" : __DIR__"dong4"+(random(4)+4),
                "west" : __DIR__"dong4"+(random(4)+4),
	]));
if (random(3)==0)
	set("exits", ([
		"west" : __DIR__"dong4"+(random(4)+4),
                "east" : __DIR__"dong3"+(random(9)+1),
	]));
         set("objects", ([
              __DIR__"npc/player" : 1,
              __DIR__"npc/lev7" : 1,
              __DIR__"npc/lev1" : 1,
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

