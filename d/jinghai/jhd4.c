// Room: /d/jinghai/jhd4.c

inherit ROOM;

void create()
{
	set("short", "树林中");
	set("long", @LONG
这是树林中。

LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "southwest" : __DIR__"jhd3",
]));
        set("outdoors","jinghai");

	setup();
	replace_program(ROOM);
}
