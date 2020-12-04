//xihua_men.c.西化门
//date:1997.8.26
//by dan 

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short",YEL"西化门"NOR);
    set("long",@LONG
这是兴庆府的西门，向东的大路直通兴庆府中心广场。自李德明迁都到这里，
谴官筹划经营，扩建城池，构筑门阙宫殿及宗社坛庙，兴庆府已具规模，与宋汴
京、辽上京鼎足而立. 城门口人来人往，不时有商人经过。东门内就是兴庆府的
著名的元昊宫和承天寺。
   往城外看，远处是峰峦重叠的贺兰山。
LONG);
    set("exits",([
        "east"      : __DIR__"road19",
        "southwest" : __DIR__"xing7",
///        "northwest" : "/d/zuzhi/yipin_tang/xuanwu_tang/x_x7",
    ]));
    set("objects", ([
          __DIR__"npc/bing1" : 3,
    ]) ); 
    set("outdoors","xingqing");
    setup();
}

