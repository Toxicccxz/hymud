// Room: /d/jinghai/jhd20.c

inherit ROOM;

void create()
{
	set("short", "山庄后厅");
	set("long", @LONG
千军易得，一将难求。为了保证靖海派的不断壮大，派内每
年都要从各地前来受训的兵丁及弟子中选出一部份杰出之士，以
把他们培养成可以独挡一面的人才。而这里就是靖海派门下弟子
学习更高深武功夫的地方，派中的各级首脑多半都是在这里学习
各种文韬武略。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"jhd22",
  "east" : __DIR__"jhd16",
  "west" : __DIR__"jhd23",
  "south" : __DIR__"jhd21",
]));
        set("objects",([
        __DIR__"npc/master2" : 1,
  __DIR__"npc/master5.c" : 1,
  __DIR__"npc/master3.c" : 1,
]));


	setup();
	replace_program(ROOM);
}
