#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{	
         set("short", BLU"ɽ��"NOR);
	set("long", BLU @LONG
 ��Խ��Խ���Χ��ǽ���ƺ���Щ�����ˡ� 
LONG NOR);
	set("exits", ([
		"east" : __DIR__"dong87",
		"west" : __DIR__"dong12",
    "south" : __DIR__"dong5"+(random(9)+1),
    "north" : __DIR__"dong2"+(random(9)+1),
                	]));
        set("objects", ([
              __DIR__"npc/lev"+(random(9)+1) : 1,
             __DIR__"npc/lev"+(random(9)+1) : 1,
                ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}