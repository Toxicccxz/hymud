
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", RED"龙之谷"NOR);
	set("long",HIW @LONG
   你现在在一个空汤的山谷里，四周一片空空汤汤，只有碧蓝的天空和天
空中的白云静静地立著。凛冽的寒风由四面八方吹来，令你觉得有些寒冷。
「哪来的这麽大风？」你的心中不由得纳闷著。  
LONG NOR);

set("magicroom",1);set("outdoors","migong");
set("magicset",1);

	set("exits", ([
		"south" : __DIR__"dong61",
		"east" : __DIR__"dong5"+(random(9)+1),
		"west" : __DIR__"dong5"+(random(9)+1),
		"north" : __DIR__"dong56",
	]));
if (random(3)==0)
	set("exits", ([
		"south" : __DIR__"dong61",
		"north" : __DIR__"dong57",
	]));
if (random(3)==0)
	set("exits", ([
		"east" : __DIR__"dong59",
		"west" : __DIR__"dong58",
	]));

if (random(3)==0)
	set("exits", ([
		"west" : __DIR__"dong5"+(random(5)+3),
		"east" : __DIR__"dong5"+(random(5)+3),
		"south" : __DIR__"dong5"+(random(5)+3),
		"north" : __DIR__"dong61",
	]));
        set("objects", ([
              __DIR__"npc/lev8" : 5,
              "/clone/box/gboxm" : 1,
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

