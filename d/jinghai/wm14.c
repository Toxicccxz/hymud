// Room: /d/jinghai/wm14.c

inherit ROOM;

void create()
{
	set("short", "议事厅");
	set("long", @LONG
大厅里庄严肃穆，门窗由名贵香木雕成，墙角有一雕玉狩猎
图花屏，厅中间放着一金边香炉，香炉里传来一阵阵清香。东面
有一高几，左右两排软椅。几个家丁站立两旁。也许是因为没有
人说话，厅上的气氛更加严肃。大概这里是开会的地方。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "westup" : __DIR__"wm18",
  "eastup" : __DIR__"wm17",
  "northup" : __DIR__"wm16",
  "south" : __DIR__"wm9",
]));
        set("objects",([
        __DIR__"npc/master6" : 1,
        __DIR__"npc/guan4.c" : 1 ,
]));


	setup();

}

int valid_leave(object me,string dir)
{
	if(dir == "eastup" && me->query("class") != "jinghai" && !wizardp(me))
		return notify_fail("旁边一个看守拦住你说道：非本派弟子不得入内！\n");
	return ::valid_leave(me,dir);
}
