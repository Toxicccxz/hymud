#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
		set("short", WHT"钟乳石洞"NOR);
	set("long", WHT @LONG
 洞顶都是尖尖的钟乳石，四周不停的有水珠滴下。 
LONG NOR);
	set("exits", ([
		"north" : __DIR__"dong75",
		"south" : __DIR__"dong7",
                	]));
if (random(3)==0)
	set("exits", ([
		"east" : __DIR__"dong7",
		"west" : __DIR__"dong75",

                	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
