// /guanwai/bingmian.c

inherit ROOM;

void create()
{
	set("short", "松花江大桥");
	set("long", @LONG
这里是松花江上的大桥，行人或马匹，车辆均可横逾而绝无危险。
桥面上留有厚厚的积雪，与两岸连成一片，只有中间经常行走之
出，露出一条青色的冰路。
LONG );
	set("exits", ([
		"eastdown"  : __DIR__"damenkan",
		"westdown"  : __DIR__"chuanchang",
	]));
	set("no_clean_up", 0);
	set("outdoors", "guanwai");
	setup();
	replace_program(ROOM);
}
