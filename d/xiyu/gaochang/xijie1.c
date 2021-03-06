/* xijie1.c
 * from XO Lib
 * a room of gaochang
 * created by hydra 19980427
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980427
 */

inherit ROOM;

void create()
{
    set( "short","西大街 " );
    set( "long",@LONG
西街是高昌城最繁华的地方了，城里的主要商家店都开在这里，除此之外，
大街的两旁也摆满了个种摊子。走在街上，各种各样的人都有，卖熟食小吃的，
玩杂耍的，传教的，说唱的。人声鼎沸，车铃叮当，马嘶驼鸣。北面是一家波
斯人开的铺子，南面正好是一家印度人开的。
LONG
    );

    set( "exits",([ /* sizeof() ==2 */
        "west"  : __DIR__"ximen",
        "east"  : __DIR__"xijie2",
        "north" : __DIR__"bosipu",
        "south" : __DIR__"yindupu",
    ]) );
    set( "outdoors","xiyu");
    setup();
}


