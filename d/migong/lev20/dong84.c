#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"王家的灵墓"NOR);
	set("long", HIM @LONG
这是传说中光神的的灵墓，通路的中央飘浮著一颗颗闪亮
的红水晶。四周的墙壁和天花板上满布著美丽的壁画和精致
的石雕。四周散发著神秘的光芒。
LONG NOR);
set("magicroom",1);set("outdoors","migong");
set("magicset",1);

	set("exits", ([
		"west" : __DIR__"dong8"+(random(4)+1),
            	"east" : __DIR__"dong85",
	]));
if (random(2)==0)
	set("exits", ([
		"west" : __DIR__"dong8"+(random(4)+1),
            	"east" : __DIR__"dong8"+(random(4)+1),
		"south" : __DIR__"dong85",
		"north" : __DIR__"dong8"+(random(4)+1),
	]));
if (random(3)==0)
	set("exits", ([
		"west" : __DIR__"dong7"+(random(4)+1),
		"east" : __DIR__"dong85",
	]));
if (random(3)==0)
	set("exits", ([
		"south" : __DIR__"dong85",
		"north" : __DIR__"dong7"+(random(3)+1),
	]));
        set("objects", ([
              __DIR__"npc/lev9" : 3,
              __DIR__"npc/player" : 3,
              "/clone/box/gboxm" : 1,
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
