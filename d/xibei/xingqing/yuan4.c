//yuan4.c.绢织院
//date:1997.8.26
//by dan 

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short",YEL"绢织院"NOR);
    set("long",@LONG
西夏专设有生产武器装备和军备物资的官府手工业作坊，直接为军队服务。
城市平民的商业活动也很活跃。“绢织院”可制世界上最好的毛毡, 这里所产毛
毡以白毡最为名贵。现在据说又要打仗，所有工匠都在忙于军服的制作，无暇编
制毛毡了。
LONG);
   
    set("exits",([
        "east"    : __DIR__"road2",
    ]));
    set("objects", ([
          __DIR__"npc/guan4" : 1,
    ]) );
    setup();
}

