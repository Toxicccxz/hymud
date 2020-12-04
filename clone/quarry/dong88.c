#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", GRN"原始森林"NOR);
	set("long", GRN @LONG
这是一个原始森林，森林中烟雾腾腾，水气弥漫。到处都是各种动物。
LONG NOR);
	set("exits", ([
		"east" : __DIR__"dong87",
		"south" : "/clone/quarry2/dong88",
		"northwest" : "/clone/quarry3/dong88",
		"north" : "/d/welcome/fight3",
		"west" : __DIR__"dong12",
                	]));
         set("objects", ([
              __DIR__"npc/"+(random(38)+1) : 1,
             //__DIR__"npc/"+(random(38)+1) : 1,
             __DIR__"npc/2" : 1,
             __DIR__"npc/5" : 1,
                ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
