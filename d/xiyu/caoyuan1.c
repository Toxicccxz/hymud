/* caoyuan1.c
 * from XO Lib
 * a room of xiyu
 * created by hydra 19980427
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980427
 */

inherit ROOM;

void create()
{
    set( "short","草原" );
    set( "long",@LONG
一望无际的大草原，绿油油的青草刚好没脚，踩上去非常舒服。不远处牛羊
成群的在吃着草，天空中飘着几多白云，一眼望去，你分不清哪是羊群，哪是白
云。一只雁从草丛中飞起，飘逸多姿地浮游在空气的蓝色的波浪里，一会儿就在
高处消失影踪，只留下一个小黑点在闪动。
LONG
    );

    set( "exits",([ /* sizeof() ==2 */
        "north" : __DIR__"caoyuan2",
        "northeast" : __FILE__,
        "southwest" : __FILE__,
    ]) );
    set( "outdoors","xiyu");
    setup();
}

int valid_leave( object me,string dir )
{
    if( dir == "northeast" && me->query_temp( "steps/caoyuan1" ) >= 5)
    {
        me -> delete_temp( "steps/caoyuan1" );
        me -> move( __DIR__"gaochang/nanmen" );
        return notify_fail( "\n" );
    }

    if( dir == "southwest" && me->query_temp( "steps/caoyuan1" ) <= -5 )
    {
        me -> delete_temp( "steps/caoyuan1" );
        me -> move( __DIR__"yanqi" );
        return notify_fail( "\n" );
    }
    switch( dir )
    {
        case "northeast":
            me -> add_temp( "steps/caoyuan1",1 );
            break;
        case "southwest":
            me -> add_temp( "steps/caoyuan1",-1 );
            break;
    }
    return ::valid_leave( me,dir );
}

