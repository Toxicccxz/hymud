// Room: /d/jinghai/moon23.c

inherit ROOM;

void create()
{
	set("short", "山顶小亭");
	set("long", @LONG
这里是山冈的顶端，一座七角桐木亭被建筑在这里。四下摇
望，海天一色。蓝蓝的让人感觉心旷神怡。脚下的小山路伸延向
南边的山下。路边的野草丛生，像是人迹罕至的样子。清风吹过
杂草瑟瑟做响。不时，有海鸟鸣叫着风过你的头顶。
LONG
	);
	set("outdoors", "jinghai");
	set("exits", ([ /* sizeof() == 2 */
  "northdown" : __DIR__"moonlu1",
  "south" : __DIR__"moon2",
]));

	setup();
	replace_program(ROOM);
}
