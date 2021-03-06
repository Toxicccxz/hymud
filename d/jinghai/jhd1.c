// Room: /d/jinghai/jhd1.c
#define CROSS_RIVER_BOAT	__DIR__"cross_river/boat"
#define CROSS_RIVER_BANK	__DIR__"cross_river/bank"
#define CROSS_RIVER_MASTER	__DIR__"cross_river/chuanfu"

inherit CROSS_RIVER_BANK;


void create()
{
	set("short", "靖海岛码头");
	set("long", @LONG
踏上这个小小的码头，你的心情不禁紧张了起来，这倒不完
全是因为威震四海的靖海帮的总坛就是设在这个小岛上，而是这
个码头被一片黑乎乎的树木紧紧的围了起来，只空出向海的一面
，从繁密的树梢上看去，一座极陡峭的石山直插天际，在山的顶
端片石崖斜斜地伸向这个岛上唯一的出口，便似一只择人而巫的
异兽正俯视着嘴边鲜美的食物。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"jhd2",
  "west" : __DIR__"jhd3",
]));

	set_boat_file(__DIR__"dum_ws");
	set_max_passenger(6);
        set("outdoors","jinghai");

	setup();
	//replace_program(ROOM);
}
