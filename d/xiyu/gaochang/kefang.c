/* kefang.c
 * from XO Lib
 * a room of gaochang
 * created by hydra 19980427
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980427
 */

inherit ROOM;

void create()
{
    set( "short","二楼客房" );
    set( "long",@LONG
虽然客房比较小，墙壁上也没有什么装饰的东西，但是这里的客房打扫的干
干净净，床上被子也都很整齐，给人以一种舒心的感觉。你感觉到有些累了，觉
得该在这里睡一觉了。虽然南边的大街上非常热闹，但是这里却很安静。
LONG
    );
    set( "sleep_room","inn" );
    set( "exits",([ /* sizeof() == 1 */
        "down" : __DIR__"kezhan",
    ]) );
    setup();
}

