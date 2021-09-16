// Room: /d/jinghai/moon8.c

inherit ROOM;

void create()
{
	set("short", "南栈道");
	set("long", @LONG
这是一条用碎石拼铺成的道路，道路两旁整齐的排列着圆木
围墙。道路向南北两个方向笔直的伸延开去。时不时有一队队红
巾水勇鱼贯而过。向南是水寨大帐。北边不远可以看见一大块空
地。东西两侧分别是水寨的书房和客房。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"moon7",
  "east" : __DIR__"moon19",
  "west" : __DIR__"moon18",
  "south" : __DIR__"moon9",
]));
        set("outdoors","jinghai");

	setup();
}

int valid_leave(object me,string arg)
{
	if( (arg =="east" || arg =="e")
	&& !wizardp(me)
	&& (me->query("class") != "jinghai" ) )
		return notify_fail("突然旁边窜出几个兵丁拦住你说道：书房重地外人不得人内！”\n");

	else
		return ::valid_leave(me,arg);
}
