// shanlu4
// by dicky

inherit ROOM;

void create()
{
set("short", "山路");
	set("long", @LONG
你正走在一片郁郁葱葱的小树林里，偶尔听到一阵阵的野兽叫声，头顶
有一些不知名的小鸟在跳来跳去，四周丛林密布，野花绿草若隐若现，随着
山谷里吹来的阵阵清风，传来哗哗的松涛声和一些淡淡的花香，身临其境，
古朴、幽静之感油然而生。
LONG
	);

        set("outdoors", "houjizhen");

	set("exits", ([ /* sizeof() == 1 */
        "southeast" : __DIR__"shanlu2",
        "northdown" : __DIR__"xiaoxi",
        "westup" : __DIR__"shanlu5",
	]));

	set("objects",([
		"/clone/npc/man" : 2,
	]));

	setup();
	replace_program(ROOM);
}


