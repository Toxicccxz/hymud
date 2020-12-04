// mroom01.c   民居
// Ffox 98-4-30 10:09

inherit ROOM;

void create()
{
    set( "short", "民居");
    set( "long", @LONG
当地人的一间民居，这里开着门，门口正对门外的青石板路。这里的主人平
时偶尔也作一点小生意的。当地的回鹘人，对住宅并不是很讲究，屋子里面就几
个莆团，一张桌子，还有一个大炕。
LONG );
    set( "exits", ([ /* sizeof() == 2 */
    "south" : __DIR__"shiban03",
]) );
    set( "objects", ([
    __DIR__"npc/afanti" : 1,
    __DIR__"npc/nvren"  : 1,
]) );
    setup();
}

