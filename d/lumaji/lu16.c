// Room: /d/lumaji/lu16.c

inherit ROOM;

void create()
{
	set("short", "树林");
	set("long", @LONG
四周的树木郁郁葱葱，一眼看不到边。你向里走了几步，却
有些找不到方向的感觉，不由得又退了出来。林间草地上有一些
散落地树枝，像是有人遗下的。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
	"west" : __DIR__"lu15",
	"east" : __DIR__"pomiao",
]));
	set("outdoors", "lumaji");
	setup();
	replace_program(ROOM);
}
