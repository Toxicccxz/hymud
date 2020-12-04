// Room: /d/fuzhou/fzroad5.c
// Date: May 12, 98  Java

inherit ROOM;
void fighting(object who);

void create()
{
	set("short", "闽赣古道");
	set("long", @LONG
福建境内数不尽的山坎相连。密林幽谷相继，终日不见天光。
山中毒虫猛兽出没无常，行路艰辛。路边有一年轻汉子倚在树上
冷眼看着你。
LONG );
	set("exits", ([
		"south" : "/d/fuzhou/fzroad5",
	]));
        set("objects", ([
		__DIR__"npc/fangrenzhi" : 1,
		__DIR__"npc/linpingzhi" : 1,
	]));
	set("outdoors", "quanzhou");
	setup();
	replace_program(ROOM);
}
