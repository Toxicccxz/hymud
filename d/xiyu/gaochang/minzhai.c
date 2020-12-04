/* minzhai.c 民宅
 * from XO Lib
 * a room of gaochang
 * created by hydra 19980427
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980427
 */

inherit ROOM;

void create()
{
    set( "short","民宅" );
    set( "long",@LONG
一家普通的民宅，虽然地处西域，但是这里的主人却是个中原人。据说他知
识渊博，但是在科举的时候，却未能中榜，一气之下，随一支商队穿过大漠来到
了这里。然后以向当地商人教授中原话为生，并出售自己抄写的一些典籍，但是
日子过的还是很紧。
LONG
    );

    set( "exits",([ /* sizeof() ==1 */
        "east"   : __DIR__"nanjie",
    ]) );
    set( "objects",([
        __DIR__"npc/teacher":1,
    ]) );
    setup();
}


