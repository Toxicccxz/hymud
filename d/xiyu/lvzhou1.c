/* lvzhou1.c
 * from XO Lib
 * a room of xiyu
 * created by hydra 19980427
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980427
 */
 
#include <ansi.h> 

inherit ROOM;

void create()
{
    set( "short","绿洲" );
    set( "long",@LONG
一个不小的湖泊，水面平静如镜、清澈见底，甚至在湖边也全无水沫，全无
涟漪的波动。湖畔全是草土，由于湖水的滋润，益发显得鲜艳，湖水里映出了鲜
丽无比的翠玉般的颜色。这里是沙漠边缘一块不小的绿洲，由于地势较低，天山
的雪水融化沿着小溪一直流到这里。往东走就是荒凉的大漠了。
LONG
    );

    set( "exits",([ /* sizeof() ==2 */
        "west" : __DIR__"lvzhou2",
        "east" : "/d/xibei/desert/shamo9",
    ]) );
    set( "outdoors","xiyu");
    setup();
}

void init()
{
    object me=this_player();
    me->set( "hydra/desert/from","西域" );
    if ( me->query_temp_marks("is_riding") == "只野骆驼" )
    {
        write( MAG"野骆驼见你走出了沙漠，轻轻把你掀在地上，一转身，消失茫茫沙漠中。\n"NOR);
        me->delete_temp_marks("is_riding");
    }    
}

