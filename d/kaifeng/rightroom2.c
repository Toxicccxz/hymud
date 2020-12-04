//Room: /u/lots/d/rightroom2.c
// LOTS 1998/10/14
// modified by wind

inherit ROOM;

void create()
{
	set("short", "带刀侍卫休息处");
	set("long", @LONG
这里是带刀侍卫的休息处,请保持安静.
LONG
	);
	set("outdoors", "kaifeng");

	set("exits", ([
		"east" : __DIR__"road2",
		"west" : __DIR__"rdang2",
		"south" : __DIR__"rightroom1",
		"north" : __DIR__"rightroom3",
	]));

	set("objects", ([
		"/d/kaifeng/npc/shiwei" : 2,
	]));

	setup();
	replace_program(ROOM);
}
