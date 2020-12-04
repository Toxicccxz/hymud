// xiaolu2.c
// by dicky

inherit ROOM;

void create()
{
set("short", "小路");
	set("long", @LONG
你正走在一片步满青苔的小路上，由于长时间没有人行走，路面显得
非常的滑，你情不自禁的放慢了脚步。小路一直想前延伸过去，一条宽土
路出现在你眼前。
LONG
	);
        set("outdoors", "houjizhen");

	set("exits", ([ /* sizeof() == 1 */
        "north" : __DIR__"tulu1",
        "southeast" : __DIR__"xiaolu1",
]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
