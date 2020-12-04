// shoproom.c   里间
// Ffox 98-4-30 10:09

inherit ROOM;

void create()
{
    set( "short", "里间");
    set( "long", @LONG
这里是小馆的里间，几间睡房，供远客住宿之用。几张简易的床铺，但是对
于远在他乡的游子来说，这也是不容易的了。
LONG );
    set( "sleep_room", "inn" );
    set( "exits", ([ /* sizeof() == 2 */
    "north" : __DIR__"shop",
]) );
    setup();
}

void init()
{
    this_player()->add_temp("hami/sleep",-1);
}
