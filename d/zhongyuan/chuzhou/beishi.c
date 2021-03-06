// 楚州北市 /d/city/chuzhou/beishi.c
// by lala, 1997-12-03

inherit ROOM;
#include <ansi.h>

void create()
{
    set("short", GRN"北市"NOR);
    set("long", @LONG
楚州的北市很有名气，北方来的商人，包括从山东和东京来的，都在这里做
买卖，他们带来了许多北方的商品，用北方话大喊大叫，夹杂着不时传来的争吵
声，使得市场上显得热闹非凡。市场的西边是出城的天宝路，远远的可以看见文
通塔的尖顶，东面人来人往的那家铺子是钱庄，大笔的银子和铜钱在进进出出真
让人眼红。东北的青云路通向城里有名的道观——上清宫。
LONG
    );
    set("outdoors", "yangzhou");
    set("no_kill",  "yangzhou");
    set("exits", ([
        "east"      : __DIR__"qianzhuang",
        "west"      : __DIR__"tianbao_lu",
        "northeast" : __DIR__"qingyun_lu",
        "southwest" : __DIR__"jiulou",
    ]));
    set("objects", ([
        __DIR__"npc/xunbu"  :   1,
        __DIR__"npc/north_seller" + random(4)  : 1,
        __DIR__"npc/north_seller" + random(4)  : 1,        
    ]));
    setup();
}
    
