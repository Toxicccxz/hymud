// 新罗坊 /d/city/chuzhou/xinluo_fang.c
// by lala, 1997-12-13

inherit ROOM;
#include <ansi.h>

void create()
{
    set("short", MAG"新罗坊"NOR );
    set("long", @LONG
新罗坊，顾名思义是给新罗人住的地方，不过其实现在新罗已经被高丽所灭
掉，这里应该叫做高丽坊的。可是大家已经习惯了，于是便还这么叫。这里住着
许多高丽商人，也有些高丽的使臣进东京城路过楚州，便也住在这里。这里的高
丽商人总有很多很好的货物，大家都喜欢来买，于是这里就非常的热闹了。    
LONG
    );
    set("exits", ([
        "north"      : __DIR__"xishi",
        ]));
    set("objects", ([
        __DIR__"npc/gaoli_shangren" :   1,
    ]));        
    set( "no_kill",  "yangzhou" );
    setup();
}
