#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
		set("short", RED"���Ҷ�"NOR);
	set("long", RED @LONG
    �����ҽ�����ɢ�������������˴�����������һЩǰ��
δ���ľ޴������������߶��š� 
LONG NOR);
	set("exits", ([
		"north" : __DIR__"dong97",
		"south" : __DIR__"dong01",
    "west" : __DIR__"dong2"+(random(9)+1),
    "east" : __DIR__"dong1"+(random(9)+1),
                	]));
          set("objects", ([
              __DIR__"npc/lev"+(random(9)+1) : 1,
             __DIR__"npc/lev"+(random(9)+1) : 1,
                ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}