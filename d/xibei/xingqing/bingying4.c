//bingying4.c.铁鹞营
//date:1997.8.26
//by dan 

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short",YEL"铁鹞营"NOR);
    set("long",@LONG
西夏连年对外战争，特别注重军事建设，城内驻军占全国兵员总数的六分之
一，分近卫军、侍卫军、铁鹞军。近卫军为正式部队，负责护卫京畿重地，铁鹞
军和侍卫军以贵族的亲属中擅长弓马技击者组成，为宫城的护卫军。这是铁鹞营
营地。
LONG);
    set("exits",([
         "east"  : __DIR__"road22",
    ]));
    set("objects", ([
          __DIR__"npc/bing2" : 3,
    ]) );
    set("outdoors","xingqing");
    setup();
}

