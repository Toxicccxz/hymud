// Room: /d/jinghai/moon7.c

inherit ROOM;

void create()
{
	set("short", "山寨中央空地");
	set("long", @LONG
好大一块碎石空地。中央立着一根圆木旗杆，三角旗上写着
几个大字[靖海明月]，随风飘舞。三名红巾水勇，腰跨钢刀。表
情严肃的站立在旗杆两侧。这里是明月寨的正中央。从这里分别
可以通向东南西北四个方向的主栈道。再向南隐约可以看见一面
帅旗在风中飘飞。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"moon6",
  "east" : __DIR__"moon10",
  "west" : __DIR__"moon11",
  "south" : __DIR__"moon8",
]));
        set("outdoors","jinghai");
        set("objects",([
        __DIR__"npc/yong1" : 3,
]));


	setup();

}
