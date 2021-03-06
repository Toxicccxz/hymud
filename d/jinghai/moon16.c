// Room: /d/jinghai/moon16.c

inherit ROOM;

void create()
{
	set("short", "水寨码头");
	set("long", @LONG
绕过栈道，你发现这里有个大港湾。一排高大的木桩整齐的
排列在岸边空地上，形成了围墙。显然这里是个水寨码头。一根
两丈高的圆木立在门前空地，顶端悬挂着，一面大旗，上书几个
大字[明月水寨]。港湾里停靠着几艘大木船。几个头匝红巾的水
勇手持长矛来回的巡逻着。大木门前贴着一副文字[gaoshi]。
LONG
	);
        set("item_desc",([
        "gaoshi" : "
靖海水路通喻：

凡持有靖海令牌者，方可登船。
违者格杀勿论。

             靖海水总 邓\n",
]));

	set("exits", ([ /* sizeof() == 4 */
  "up2" : __DIR__"moon25",
  "up3" : __DIR__"moon26",
  "up1" : __DIR__"moon24",
  "south" : __DIR__"moon10",
  "east" : __DIR__"moon38",
]));
        set("outdoors","jinghai");
        set("objects",([
        __DIR__"npc/yong1" : 2,
]));


	setup();
	replace_program(ROOM);
}
