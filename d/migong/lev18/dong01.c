
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", GRN"古代遗迹"NOR);
	set("long", GRN @LONG
   这里是个危险的区域，很大且很容易迷路，从不少死里逃生的居民口中
获知这区域内除了一些毒物之外还住著专门猎人头的矮灵族，已经有不少
居民进去之後就没有回来过。
LONG NOR);
set("magicroom",1);set("outdoors","migong");
set("magicset",1);

	set("exits", ([
		"south" : __DIR__"dong02",
                "north" : __DIR__"dong0"+(random(3)+1),
		"east" : __DIR__"dong02",
                "west" : "/d/migong/lev17/dong21",
	]));
set("no_npc",1);
         set("objects", ([
              __DIR__"npc/lev5" : random(3),
         ]));
if (random(2)==0)
	set("exits", ([
		"east" : __DIR__"dong0"+(random(3)+1),
                "west" : "/d/migong/lev17/dong21",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
