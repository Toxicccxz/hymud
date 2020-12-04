#include <ansi.h>
#include <room.h> 
inherit ROOM; 
void create()
{
        set("short", "沙河底");
        set("long", @LONG
原来这里是一道暗河，冰冷的水让你忘却了身在沙漠，周围一片昏暗，都是迷
迷蒙蒙的沙水，你可以感觉到水中的沙子轻轻地摩擦着你的面颊，并住一口气，你
微微睁眼向四周望去，透出微微红光的洞口更加清楚了，就在你的正上方。 
LONG
        );
        set("exits", ([ 
                "up" : __DIR__"shaxue",
        ])); 
        set("indoors", "quicksand"); 
        set("coor/x",-1100);
        set("coor/y",-10);
        set("coor/z",0);
        setup();
} 
