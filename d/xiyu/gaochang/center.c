/* center.c
 * from XO Lib
 * a room of gaochang
 * created by hydra 19980427
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980427
 */

inherit ROOM;

void create()
{
    set( "short","宫城外" );
    set( "long",@LONG
这里是高昌城的中心，在高昌宫城的外面，门口是两条大街的交汇处，而北
面是高昌的宫城，是以前高昌国王居住的地方，而现在已经被回鹘人占据了。高
昌城地处东西贸易的要冲，往来的商人大多要经过于此，所以这里发展成了西域
一个不小的城市。这里货物也很丰富，突厥马，中原丝绸，波斯骆驼，印度药材，
各种店铺很多。商业的发展带来了高昌的繁荣。
LONG
    );

    set( "exits",([ /* sizeof() ==2 */
        "west"  : __DIR__"xijie2",
        "east"  : __DIR__"dongjie",
        "south" : __DIR__"nanjie",
    ]) );
    set( "outdoors","xiyu");
    setup();
}


