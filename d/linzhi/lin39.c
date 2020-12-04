// Room: /d/linzhi/lin39.c

inherit ROOM;

void create()
{
	set("short", "高原侧道");
	set("long", @LONG
这里是高原侧道，四下荒无一人。你走在路上，不时地注意
着周围的变化。一阵风吹来，你不禁觉得有些凉。东面不时传来
哗哗的水声。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"lin36",
  "east" : __DIR__"lin40",
  "south" : __DIR__"lin41",
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 3800);
	setup();
	replace_program(ROOM);
}
