// Room: /d/yueyang/gaibangtang.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "马大元居");
	set("long", @LONG
这里是丐帮帮众聚会场所，地上横七竖八排着不少草蒲团。虽然看
起来似乎很凌乱，其实却甚是合乎帮规：何人做何职司，前后顺序，一
目了然。
LONG );
	set("exits", ([
		"south" : __DIR__"xuanyuantai",
	]));
	set("objects", ([
		__DIR__"npc/kangming" : 1,
	]));

	set("coor/x", -1420);
	set("coor/y", -2240);
	set("coor/z", 0);
	setup();

	
}
