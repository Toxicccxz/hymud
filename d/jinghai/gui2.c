// Room: /d/jinghai/gui2.c

inherit ROOM;

void create()
{
	set("short", "小土路");
	set("long", @LONG
这是一间什麽也没有的空房间。

LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "northup" : __DIR__"gui18",
  "east" : __DIR__"gui3",
  "west" : __DIR__"gui1",
]));

	setup();
	replace_program(ROOM);
}
