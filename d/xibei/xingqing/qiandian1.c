//qiandian1.c.前殿
//date:1997.8.26
//by dan 

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short",YEL"前殿"NOR);
    set("long",@LONG
宫殿高四十丈，宽一百二十丈。连绵蜿蜒的雉堞，高耸在山崖上的城堡，连
同古老的寺院、禅房、碑碣、楼阁、算不清的窗牖帷帘，看来瑰丽而柔和，在背
后山势的衬托之下，显得格外的气派和豪华。宽阔整齐的寺前路上，你可以看见
一拨一拨的游人香客正在朝拜、进香。几个穿着怪异的藩僧双手合什，也夹杂在
其中。
LONG);
   
    set("exits",([
        "north"   : __DIR__"door5",
        "south"   : __DIR__"dadian1",
    ]));
    set("outdoors","lanzhou");
    setup();
}

