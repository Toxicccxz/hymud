/* nanjiang0.c
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
    set( "short","沙漠" );
    set( "long",@LONG
你走在一片沙漠上，脚下凹凸起伏，沙质松软，人行其上极其困难。迎面如
雨似的狂风沙，焦烈的大地，象天空伸长着手臂呼唤的仙人掌，千万年前干枯了
的河床，黑色的山峦，深蓝色的天空，满不乱石的荒漠，这一切的景象使你感到
有点意乱神迷。
LONG
    );

    set( "exits",([ /* sizeof() ==2 */
        "north" : __DIR__"guizi",
        "south" : __DIR__"nanjiang1",
        "west"  : __FILE__,
        "east"  : __FILE__,
        "southeast" : __DIR__"nanjiang"+random(3),
        "northwest" : __DIR__"nanjiang"+random(3),
        "northeast" : __DIR__"nanjiang"+random(3),
        "southwest" : __DIR__"nanjiang"+random(3),
    ]) );
    set( "outdoors","xiyu");
    setup();
}

int valid_leave( object me,string dir )
{
    int current_water;
    
    me = this_player();
    current_water = me->query( "water" );
    if( current_water == 0 ) 
    {
        return notify_fail( "你由于缺水严重，再也迈不动步子了。\n" );
    }
    if( current_water <= 5 )
    {
        write( RED"由于水分的过度蒸发，你感到快要虚脱了。\n"NOR );
        me -> set( "water",0 );
        if( random( 3 ) == 0 )
        {
            write( RED"你只觉得眼前一阵天旋地转。。。\n"NOR );
            call_out( "die",1,me );
            return 1;
        }
    }
    else
    {
//骑上骆驼的时候水的消耗减少。
        if ( !me->query_temp_marks( "is_riding" ) )  
            me -> add( "water",-10 );
        else
            me -> add( "water",-5 );
    }
    return ::valid_leave( me,dir );
}

void die( object me )
{
    me -> die();
}
