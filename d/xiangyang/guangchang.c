// Room: /d/xiangyang/guangchang.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "中央广场");
	set("long", @LONG
这里是襄阳的中央广场，铺着青石地面。东面通向青龙门，
西面通向白虎门，南面直达朱雀门，远远地你可看到北面是襄
阳安抚使衙门。近年来蒙古大军屡次攻打襄阳，官府为防止蒙
古奸细混杂进来，已经不允许人们在此聚集。只见一队官兵在
此往来巡逻，你还是快离开吧。
LONG );
        set("outdoors", "xiangyang");
	set("item_desc", ([
		"dong" : "\n",
	]));
set("roomif","$botten#保护任务|守城任务|组队任务|任务放弃|放弃守城|领取功劳:ask guo about job|ask guo about job2|ask guo about 奸细|ask guo about 放弃|ask guo about 撤退|ask guo about 功劳$#");
	set("exits", ([
		"east"  : __DIR__"eastjie1",
		"west"  : __DIR__"westjie1",
		"south" : __DIR__"southjie1",
		"north" : __DIR__"anfupailou",
	]));

	set("objects", ([
	//	__DIR__"npc/pian" : 1,
		"/d/city/npc/xunbu" : 5,
                "/d/npc/walker": 2,
	  "/quest/guojob/guo" : 1, 
		]));
	setup();
	replace_program(ROOM);
}

