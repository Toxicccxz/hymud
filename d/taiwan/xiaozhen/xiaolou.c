// Room: /d/taiwan/xiaolou.c

inherit ROOM;

void create()
{
	set("short", "依红楼");
	set("long", @LONG
这是一座两层的小楼,看不见上面的情况,四下里静悄悄的,没一个人
影,清风吹过,你似乎又听到了少女的哭泣,这里可以休息一下。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"huayuan",
  "north" : __DIR__"tingtang",
]));
	set("outdoors", "/d/taiwan");
  set("sleep_room",1);
	set("objects", ([ /* sizeof() == 3 */
  __DIR__"npc/obj/jiudai" : 1,
  __DIR__"npc/obj/mifan" : 1,
  __DIR__"npc/obj/kaoya" : 1,
  __DIR__"npc/obj/niurou" : 1,
]));
	setup();
	replace_program(ROOM);
}
