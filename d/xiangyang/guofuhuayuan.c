// Room: /d/xiangyang/guofuhuayuan.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "郭府后花园");
	set("long", @LONG
这里是郭府的后花园，园内假山林立，西边种着一些青竹，
东边是几棵枝叶茂盛的木笔花树。你一走进来，就闻到一阵阵
清新的、淡淡的花香。
LONG );
	set("exits", ([
		"east"  : __DIR__"guofuwoshi",
		"west"  : __DIR__"guofukefang",
		"south" : __DIR__"guofuting",
		"north" : __DIR__"guofushufang",
	]));

	set("roomif","$botten#任务|功劳|放弃:ask huang about job|ask huang about 功劳|ask huang about fangqi$#");
	
	set("objects", ([
		"/quest/huang/huang" : 1,
	]));
	setup();
	replace_program(ROOM);
}

