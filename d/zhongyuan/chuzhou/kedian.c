// 楚州燕归客店 /d/city/chuzhou/kedian.c
// by lala, 1997-12-04

inherit ROOM;

#include <ansi.h>

void create()
{
    set("short", MAG"燕归客店"NOR);
    set("long", @LONG
你现在正站在楚州城东边的一家小客栈里，这家客栈的屋檐下每年初春都有
无数的燕子飞来筑巢。店主人是位好心肠的老人，从来不让活计去毁坏燕儿们辛
辛苦苦修筑的巢。他常说燕子和人一样眷恋自己的家园，因此每年都会飞回来。
这家客栈总给人宾至如归的感觉，所以南来北往的旅人对它都有很好的印象。
    客店一楼供应饮食，二楼提供住宿。
LONG
    );
    set("no_kill",  "yangzhou");
    set("exits", ([
        "south"      : __DIR__"dongshi",
        "up"         : __DIR__"kedian2",
        ]));
    set("objects", ([
        __DIR__"npc/xiaoer1"    :   1,
        __DIR__"npc/keshang"    :   random(3),
    ]));        
    setup();
}
