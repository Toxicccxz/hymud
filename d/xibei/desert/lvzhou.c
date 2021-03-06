/* lvzhou.c
 * from XO Lib
 * a room of desert
 * created by hydra 19980327
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980402
 */

inherit ROOM;

void create()
{
    set( "short","绿洲" );
    set( "long",@LONG
你在沙漠中走了那么就，终于来到了一块有生命的地方，这个地方其实并不
很大，只不过在中央有一处水源，湖面平静如镜，湖的四周长满青草，其间还夹
着一些柳树。这水是不远处的雪山上积雪融化，流到此处汇集而成的。在绿地与
沙漠的交接出长着几棵梭梭树。
LONG
    );
    set( "not_startroom",1 );
    set( "exits", ([/*sizeof() == 8 */
        "north":__DIR__"shamo"+random( 9 ),
        "south":__DIR__"shamo"+random( 9 ),
        "west":__DIR__"shamo"+random( 9 ),
        "east":__DIR__"shamo"+random( 9 ),
        "southeast":__DIR__"shamo"+random( 9 ),
        "northeast":__DIR__"shamo"+random( 9 ),
        "southwest":__DIR__"shamo"+random( 9 ),
        "northwest":__DIR__"shamo"+random( 9 ),
    ]) );
    set( "outdoors","lvzhou");

    set( "item_desc",([
        "梭梭树":"你发现在树根处寄生着一种黄色的植物。\n",
        "青草":"这里的青草长的很茂盛，你试试是否能拔(ba)一些。\n",
    ]) );
    set( "search_things",([
        "梭梭树":__DIR__"obj/congrong",
    ]) );
    set( "grass_remain",3 );
    setup();
}

void init()
{
    add_action( "do_drink",({ "drink","he" }) );
    add_action( "do_ba","ba" );
}

int do_drink( object me,string arg )
{
    int current_water,max_water;
    me = this_player();
    current_water = me->query( "water" );
    max_water = me->max_water_capacity();

    if( arg ) return 0;
    if( current_water >= max_water )
        return notify_fail( "遇着了不要钱的水也不至于那么喝嘛:-) \n" );
    message( "vision",me->name() + "用手捧起湖水，不要命地喝了起来，看起来一定"
"多年没喝过水了。\n",environment( me ),({ me }) );
    write( "你喝了湖里的水，觉得一股惬意直透心底，爽啊。。。爽呆了。。。\n" );
    me -> add( "water",20 );
    return 1;
}

int do_ba( string arg )
{
    object me,ob;
    me = this_player();

    if ( arg != "青草" && arg != "cao" ) return 0;
    if ( ! query( "grass_remain" ) ) 
        return notify_fail( "这里的草已经被拔光了。\n" );
    ob = new( __DIR__"obj/grass" );
    ob -> move( me );
    message_vision( "$N弯下腰，拔了一$n在手中。\n",me,ob );
    add( "grass_remain",-1 );
    return 1;
}
   

