// Room: /d/jinghai/bank1.c

inherit ROOM;

void create()
{
	set("short", "海边");
	set("long", @LONG
只觉眼前一阔，慰蓝色的大海像缀满蓝宝石的地毯般从天的
尽头直铺到你的脚下，踩在金色的沙滩上，呼吸着清新的带着咸
味的空气，你的心情一片宁静，只觉得俗世的烦恼全都一扫而空。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"bank2",
  "southwest" : __DIR__"zhuque5",
]));

	set("outdoors", "jinghai");
	setup();
	replace_program(ROOM);
}
