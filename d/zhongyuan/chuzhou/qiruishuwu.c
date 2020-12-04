//楚州七瑞书屋 /d/city/chuzhou/qiruishuwu.c

inherit ROOM;

#include <ansi.h>

void create()
{
    set("short", YEL"七瑞书屋"NOR);
    set("long", @LONG
这里实际上卖的多是旧书，别看不少书都破破烂烂的了，但是据说经常有人
从中发现珍本，而且价钱非常便宜。书屋里有不少买书的人，也有很多的人并不
买书，只是站在这里看，书屋的老板也并不管他们，任由他们翻看。
LONG
    );
    set("no_kill",  "yangzhou");
    set("exits", ([
        "southeast" : __DIR__"qingyun_lu",
        ]));
    set("objects", ([
        __DIR__"npc/bookboss"   :   1,
        __DIR__"npc/reader"     :   random(2),
    ]));        
    setup();
}
