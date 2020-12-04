// 楚州钱庄 /d/city/chuzhou/qianzhuang.c
// by lala, 1997-12-03

inherit BANK;
#include <ansi.h>

void create()
{
    set("short", YEL"钱庄"NOR);
    set("long", @LONG
这里是楚州的钱庄，因为楚州地处淮水和真楚运河的交汇处，又有水路可以
出海，商业相当发达，各地的商号都和这里有银钱来往。钱庄里有很多人在存取
钱，也有人在兑换银两。看着这么多的钱财滚来滚去，真是让人眼馋啊。钱庄的
伙计在高大的红木柜台后面忙个不休地应付客人。
LONG
    );
    set("no_kill", "yangzhou");
    set("exits", ([
        "west"      : __DIR__"beishi",
        ]));
    set("objects", ([
        __DIR__"npc/bankboss"   :   1,
    ]));        
    setup();
}
