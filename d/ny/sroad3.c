
// Room: /d/snow/sroad3.c

inherit ROOM;

void create()
{
	set("coor",({-100,4600,10}));
	set("short", "青石官道");
	set("long",
"这是一条宽敞坚实的青石板铺成的大道，路上车马的痕迹已经在路面上留下一条条明显的凹\n"
"痕。\n"
);
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"sroad0",

]));
	set("outdoors", "ny");
//         set("objects", ([
//                 __DIR__"npc/crazy_dog": 1 ]) );

	setup();
	replace_program(ROOM);
}
