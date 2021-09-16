// jiuguan.c
// by dicky

inherit ROOM;
void create()
{
	set("short", "小酒馆");
	set("long", @LONG
    你一走进来，就看到几双眼睛盯在自己的身上，心里一惊。
几张破旧的木桌一字排开，零星的做着几位客人，或低头饮酒，或交
头接耳，他们神态各异，一看就知道不是什么好人，如果没有什么事
情，尽量不要去惹他们。
LONG
	);

	set("resource/water", 1);
	set("exits", ([
		"south" : __DIR__"shilu4",
	]));
	set("objects", ([
		__DIR__"npc/jiuboss" : 1,
	]));

	setup();
	replace_program(ROOM);
}
