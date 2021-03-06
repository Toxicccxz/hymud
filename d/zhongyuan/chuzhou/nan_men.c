// 楚州南门 /d/city/chuzhou/nan_men.c 
// by lala 1997-12-03

inherit ROOM;
#include <ansi.h>
#include <men.h>

void create()
{
    set("short", CYN"楚州南门"NOR);
    set("long", @LONG
楚州位于南北大运河同淮水的交汇处，因而位置十分重要，每年都有无数的
商贾乘船来到这里，楚州作为真楚运河的北端起点很快就发展成为一个重要的商
业城市。这里是城市的南门，许多南方商人都是从这里进城或者从这里出城到著
名的扬州去做生意的。城门口有几个士兵站岗，但是显得十分松懈，大概是因为
江淮一带久无战乱的缘故。门洞里贴着张榜文，几个闲汉正在围观。东面是楚州
的名胜——龙光阁。
LONG
    );
    set("outdoors", "yangzhou");
    set("no_kill",  "yangzhou");
    set("exits", ([
        "south"     :  "/d/zhongyuan/yunhe0",
        "northwest" :  __DIR__"wuhua_jie",
        "east"      :  __DIR__"longguangge"
    ]) );
    set("objects", ([
        __DIR__"npc/xiaowei"    :   2,
        __DIR__"npc/shibing1"   :   1,
        __DIR__"npc/shibing2"   :   1,
    ]) );
    
    setup();
}
                               
int valid_leave( object me, string dir )
{
    if( me->query("no_leave_chuzhou")
    && dir != "north" )
        return notify_fail("你现在不能离开楚州。\n");
    return ::valid_leave( me, dir );
}
