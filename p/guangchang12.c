// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "邪月广场中庭");
	set("long", @LONG
这里是一个很宽阔的广场，铺着青石地面。周围聚集着江湖上不少邪魔外道，
很多邪派武林人物都喜欢来这里，因为这是通向各门派的必进之路，正派人士
往往都敬而远之此处。这里有块牌子(sign)。
LONG );
        
        set("type", "xie");
        set("no_npc",1);
	set("owner", "public");
	set("item_desc", ([
		"sign" : "各门派的掌门人可以在此处划出(buildroom)一块地盘为己用。\n",
	]));

	set("exits", ([
		"eastdown" : __DIR__"guangchang1",
			"westup" : __DIR__"guangchang13",
				]));
	
	setup();
}

void init()
{
        add_action("do_quit","buildrest");
        add_action("do_quit","buildeat");
        add_action("do_quit","buildweapon"); 
        add_action("do_quit","buildjob2");
        add_action("do_quit","buildjob");
        add_action("do_quit","buildfight");
}
int do_quit(string arg)
{
        write(this_player()->query("name")+"，这里只能buildroom！\n");
        return 1;
}
