// Room: /d/jinghai/zhuque9.c

inherit ROOM;

void create()
{
	set("short", "客厅");
	set("long", @LONG
这里是庄院内的客厅。室内宽大明亮，八根雕着飞龙云雾的
圆柱使屋内格局分成三块，正中是一张香案，左右两排坐椅倚柱
排列，每根柱后立着一个紫衣女孩，客厅下首花园的方向是一排
长窗，阵阵花香透过窗棂传了进来。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "up" : __DIR__"zhuque11",
  "east" : __DIR__"zhuque8",
  "south" : __DIR__"zhuque10",
  "west" : __DIR__"zhuque7",
]));
        set("objects",([
       __DIR__"npc/master4" : 1,
       __DIR__"npc/yong4" : 1,
]));

	setup();
}

int valid_leave(object me,string arg)
{
	if( (arg == "up")
	&& !wizardp(me)
	&& (me->query("class") != "jinghai") )
		return notify_fail("非本派弟子不得入内！\n");

	else
		return ::valid_leave(me,arg);
}

