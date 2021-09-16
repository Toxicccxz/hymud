// Room: /d/jinghai/wm11.c

inherit ROOM;

void create()
{
	set("short", "无名堡水寨大门");
	set("long", @LONG
这里是无名堡的水寨。只见寨前有一处偌大的空地，上方有
一座敌楼，而空地是堡中集会之处。水寨大门岗哨密布，戒备森
严，一般的百姓到此截然止步，不敢擅自逾越。从大门再往下去
就是无名堡停泊战船的西码头了。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "up" : __DIR__"wm13",
  "east" : __DIR__"wm10",
    "down" : __DIR__"wm1",
]));
        set("objects",([
        __DIR__"npc/yong6" : 1,
]));


        set("outdoors","jinghai");

	setup();
	replace_program(ROOM);
}
