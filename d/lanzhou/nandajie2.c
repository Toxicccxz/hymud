// Room: /lanzhou/nandajie2.c
// xws 1998/10/14 
inherit ROOM;
void create()
{
	set("short", "南大街");
	set("long", @LONG
你走在一条繁忙的街道上，看着操着南腔北调的人们行色匆匆，许多人都往北
边走去，那里有一个热闹的广场。
LONG
	);
        set("outdoors", "lanzhou");
	set("exits", ([
		"south" : __DIR__"nanmen",
		"north" : __DIR__"nandajie1",
	]));
	setup();
	replace_program(ROOM);
}

