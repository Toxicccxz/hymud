// xiaolu02   哈密小路
// Ffox 98-4-30 10:09

#include <ansi.h>
inherit ROOM;

void create()
{
    set( "short", "小路");
    set( "long", @LONG
一条青石小路，已经邻近一个西域小镇，在这边远的地方，是如此的平静、
安宁，一扫大漠的黄沙，这里四周的田地是一片青翠，树木郁郁葱葱，十分茂盛
，树盖和树林枝繁叶茂，色泽浓重。
LONG );
    set( "exits", ([ /* sizeof() == 2 */
    "west" : __DIR__"xiaolu01",
    "east" : __DIR__"shiban01",
]) );
    set( "outdoors", "西域" );
    setup();
}

int valid_leave( object me, string dir )
{
//     if( dir == "east" )
//      write( YEL"^G^A^G^A^U^X^C^L^D^C^]^X^H^K^A^K^U^B^X^V^N^W^S^R^P^A^U^R^A^M^A^M^A^M^A^M\n"NOR );
    return :: valid_leave( me, dir );
}

