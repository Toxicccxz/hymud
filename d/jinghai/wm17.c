// Room: /d/jinghai/wm17.c

inherit ROOM;

void create()
{
	set("short", "寝室");
	set("long", @LONG
这里是靖海派弟子卧房。睡房中整齐的摆着十几个软榻，上
面铺着玄色的被子。室中非常的安静，懒懒的阳光透过窗棂，有
意无意地洒落满室，屋角香炉里传来一阵阵清香。处处浮溢着一
种恬静的感觉。让人不觉昏昏欲睡。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "westdown" : __DIR__"wm14",
]));

	
        set("sleep_room", 1);

	setup();
	replace_program(ROOM);
}
