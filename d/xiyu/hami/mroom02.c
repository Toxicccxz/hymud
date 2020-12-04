// mroom02.c   民居
// Ffox 98-4-30 10:09

inherit ROOM;

void create()
{
    set( "short", "民居");
    set( "long", @LONG
当地人的一间民居，这里开着门，门口正对门外的青石板路。当地的回鹘人
，对住宅并不是很讲究，屋子里面就一张桌子，还有一个大炕。这屋子的主人是
一个艺人，特别好客。
LONG );
    set( "exits", ([ /* sizeof() == 2 */
    "north" : __DIR__"shiban03",
]) );
    set( "objects", ([
    __DIR__"npc/huosan" : 1,
]) );
    setup();
}

