// zahuopu.c
// by dicky

inherit ROOM;

void create()
{
	set("short", "杂货铺");
	set("long", @LONG
这是一家专卖一些零碎用品的小店铺，虽然旁边不远就是有
间客栈，但是这里的毛巾、梳子、针线之类的日常用品却并不好
卖，由于这里靠近天山不远，所以这里也卖人参、蛇药一类的江
湖人常用的物品。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  	"north" : __DIR__"shilu2",
	]));

	set("objects",([
	__DIR__"npc/yang" : 1,
	]));

	setup();
	replace_program(ROOM);
}
