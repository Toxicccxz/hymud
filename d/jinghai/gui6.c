// Room: /d/jinghai/gui6.c

inherit ROOM;

void create()
{
	set("short", "侧门");
	set("long", @LONG
这是一间什麽也没有的空房间。


LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "eastup" : __DIR__"gui8",
  "south" : __DIR__"gui7",
  "west" : __DIR__"gui5",
]));

	setup();
	replace_program(ROOM);
}
