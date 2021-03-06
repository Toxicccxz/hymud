/* loulan1.c
 * from XO Lib
 * a room of desert
 * created by hydra 19980327
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980408
 */

inherit ROOM;

void create()
{
    set( "short","古城墙" );
    set( "long",@LONG
这里是一段破旧的城墙，城墙用黄土垒成。因为经历代风雨的剥蚀，大部分
早已化为乌有，只是这里还留者残留着一小段，大约有普通的民房那么高。这里
有一座很高的土堆，由土坯、红柳枝、苇杆砌成，依稀可以看出是一座破了的佛
塔，上面有残存的塑像和壁画。
LONG
    );

    set( "outdoors","desert");
    set( "exits",([ /*sizeof() == 2 */
        "east" : __DIR__"loulan2",
        "west" : __DIR__"shamo"+random( 5 ),
    ]) );
    set( "not_startroom",1 );
    setup();
}


