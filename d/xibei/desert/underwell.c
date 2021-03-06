/* underwell.c
 * from XO Lib
 * a room of desert
 * created by hydra 19980421
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980421
 */

inherit ROOM;

void create()
{
    set( "short","井下" );
    set( "long",@LONG
你钻进了一个古老的井的下面，这里光线非常黑，你刚可以看清三尺远的地
方。由于天气的干燥，这里的水其实早一干枯，底下是一片平整而又结实的泥土。
井壁东侧的土墙上，泥土有些剥落，上面留有一个小洞。
LONG
    );

    set( "outdoors","desert");
    set( "exits",([ /*sizeof() == 2 */
        "up" : __DIR__"loulan2",
    ]) );
    set( "detail",([
        "洞":"一个很小的洞，你试试能否钻(zuan)过去。\n",
        "hole":"一个很小的洞，你试试能否钻(zuan)过去。\n",
    ]) );
    set( "not_startroom",1 );
    setup();
}

void init()
{
    add_action( "EnterHole","zuan" );
}

int EnterHole( string arg )
{
    object me;
    me = this_player();
    if( arg !="hole" && arg !="洞" )
        return notify_fail( "你要钻什么？\n" );
    message( "vision",me->name()+"从洞了钻了进去。。\n",environment(me),me);
    me -> move( __DIR__"oldtomb" );
    write( "你使足了劲，终于钻进了小洞。。。\n" );
    message( "vision",me->name()+"钻了进来。。。\n",environment(me),me);
    return 1;
}
