// Room: /d/jinghai/gui14.c

inherit ROOM;

void create()
{
	set("short", "兵器仓库");
	set("long", @LONG
这是一间什麽也没有的空房间。

LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"gui5",
]));

	setup();
	replace_program(ROOM);
}
