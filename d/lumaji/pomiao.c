// pomiao.c
// by dicky

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "破山神庙");
	set("long", @LONG
这是一间破破烂烂的山神庙，庙里破败不堪，山神神像推在一旁，
梁上地下也布满了灰尘。一看就知道已经很久没有人来清理过了。正中
放着个大香案，上面零乱地扔着几根吃剩下来的鸡骨头。也许正是因为
隐蔽的原因吧，丐帮的一个分舵就被设在此处。
LONG);
	set("exits", ([
		"west" : __DIR__"lu16",
		"north" : __DIR__"ygbz/qiao",
		"south" : __DIR__"ygbz/yuanzi",
	]));

	set("objects", ([
		"/clone/npc/npc" : 1,
	]));

        setup();
        replace_program(ROOM);


}