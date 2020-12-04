//tianjing1.c.天井
//date:1997.8.26
//by dan 

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short",YEL"天井"NOR);
    set("long",@LONG
承天寺的天井，这是一个小小的地方。大概也就两、三丈见方吧，四面的地
下都是青石铺就，看得出有新铺的痕迹。往南不远，就是承天寺的大殿，你能看
见大殿里烟雾缭绕，无数善男信女正在菩萨面前焚香磕头。整个天井完全笼罩在
承天寺的高塔的阴影下面，几个和尚正坐在阴影里念经。虽然不是离大殿很远，
但你听着远处传来的详和的钟声，耳边清净了许多，感觉真是如在仙境，如在神
界。
LONG);
   
    set("exits",([
        "north"   : __DIR__"dadian1",
        "south"   : __DIR__"ta",
    ]));
    set("outdoors","xingqing");
    setup();
}

