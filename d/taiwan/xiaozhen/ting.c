// Room: /d/taiwan/ting.c

inherit ROOM;

void create()
{
	set("short", "大厅");
	set("long", @LONG
高大威武的大厅,四角的大柱子破地而起,两排客椅擦得明亮,来往 
的仆人丫鬟不息.正中的镶玉大屏风前一张雕龙太师椅子.铺上了当地 
少见的锦缎. 
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"dayuan",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/caizhu.c" : 1,
  __DIR__"npc/obj/jiudai" : 1,
  __DIR__"npc/obj/kaoya" : 1,
  __DIR__"npc/obj/niurou" : 1,

]));
	setup();
	replace_program(ROOM);
}
