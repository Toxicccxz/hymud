//feixu.c.废墟
//date:1997.8.26
//by dan

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short","废墟");
    set("long",@LONG
这里原来是平民区和商业区，几十年前一场大火，所有房屋均付之一炬。只
留下一片瓦砾。现在，邻街的地面已开设了一些店铺，逐步恢复了生机。
LONG);
   
    set("exits",([
        "out"   : __DIR__"yaopu",
    ]));  
    set("search_things",([
                "瓦砾" :  __DIR__"npc/obj/jian4",
                ]) );
    set("outdoors","xingqing");
    setup();
}

