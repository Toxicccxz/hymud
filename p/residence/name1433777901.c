// a skeleton for user rooms
inherit ROOM;
void create()
{
set("short", "练功房");
set("long", @LONG
这里是新手联盟的练功房
这里是新手联盟的练功房
这里是新手联盟的练功房
这里是新手联盟的练功房
这里是新手联盟的练功房
这里是新手联盟的练功房

LONG
);
        set("exits", ([
"west" : "/p/residence/beg1434617478",
"south" : "/p/residence/name1433777592.c",
]));
set("objects", ([
        "/p/npc/master":1,
       ]) );
	set("owner", "name");
	set("class", "新手联盟　");
	set("no_fight",1);
        set("no_clean_up", 1);
	set("sleep_room", "1");

setup();
}
