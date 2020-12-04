//yaopu.c.药铺
//date:1997.8.28
//by dan

#include <ansi.h>
inherit ROOM;

string look_sign(object me);

void create()
{
    set("short",MAG"泰仁堂兴庆分号"NOR);
    set("long",@LONG
药铺新开张不久，是兰州泰仁堂开的分号，很受大家欢迎，因此生意不错。
药铺不大，却异常的整洁；正面是柜台，柜台后面是个大柜子, 几百个小抽屉上
一一用红纸标着药材的名称. 地下几个伙计正在分拣刚刚收购来的草药。一个伙
计在招待客人。老郎中有时也带小霞从兰州过来看看。
LONG);
    set("exits",([
        "west"   : __DIR__"road6",
    ]));
    set("objects",([
        __DIR__"npc/huoji" : 1,
    ]));
    setup();
}


