// shilu6.c
// by dicky

inherit ROOM;

void create()
{
       set("short", "碎石路");
	set("long", @LONG
这是一段碎石路，路是用许多石块铺成的，铺的整整齐齐，
大路由东向西，一直通向侯集镇的尽头，南边就是驿站，供过往
官吏暂做休息场所。
LONG
	);

        set("outdoors", "houjizhen");

	set("exits", ([ 
	    "west" : __DIR__"muqiao",
	    "south" : __DIR__"yizhan",
	    "east" : __DIR__"shilu5",
	]));

	setup();
	replace_program(ROOM);
}
