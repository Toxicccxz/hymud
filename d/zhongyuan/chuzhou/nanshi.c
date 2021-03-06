
// 楚州南市 /d/city/chuzhou/nanshi.c
// by lala, 1997-12-03

inherit ROOM;
#include <ansi.h>

void create()
{
    set("short", GRN"南市"NOR);
    set("long", @LONG
南市是个三教九流什么人都来的地方。西边的茶肆里整天坐着一些闲人，在
喝茶之余，说个张家长李家短的，是他们最大的乐趣。南面的赌场里面传来吆五
喝六的赌色子押大小的声音，十分的热闹。东南的升平街通向城里的妓院，传来
一阵阵浪荡的笑声。北面是通向东市的跨下桥。
LONG
    );
    set("outdoors", "yangzhou");
    set("no_kill",  "yangzhou");
    set("exits", ([
        "north"     : __DIR__"kuaxiaqiao",
        "west"      : __DIR__"chasi",
        "southeast" : __DIR__"shengping_jie",
//        "southwest" : __DIR__"duchang",
    ]));
    set("objects", ([
        __DIR__"npc/xunbu"  :   1,
        __DIR__"npc/south_seller" + random(5) : 1,
        __DIR__"npc/south_seller" + random(5) : 1,
        __DIR__"npc/south_seller" + random(5) : 1,        
    ]));
    setup();
}
