//room2.c.平民区
//date:1997.8.26
//by dan

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short","平民区");
    set("long",@LONG
这里是平民区，多是简易低矮的土屋或覆土板屋，与周围金壁辉煌的宫殿以
及覆瓦的官署宅第形成鲜明对比。城内的平民以从事手工业为主，在家庭作坊制
造各种工艺品，卖给官府和过往客商，以换取生活所需。有许多工艺精品就是出
自这些工匠手中。
LONG);
   
    set("exits",([
        "north"   : __DIR__"road17",
    ]));  
    set("outdoors","xingqing");
    setup();
}

