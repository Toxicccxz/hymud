// 楚州天宝路 /d/city/chuzhou/tianbao_lu.c
// by lala, 1997-12-03

inherit ROOM;

void create()
{
    set("short", "天宝路");
    set("long", @LONG
天宝路是楚州北门内第一条大街，向北可以出城，西北是楚州著名的名胜地
——文通塔，这座塔在远近都很有名气，每年都有不少人前来观光。不过大多数
人都是商人，他们对名胜不感兴趣，他们感兴趣的是天宝路东的北市，那里是本
城最热闹的四个市场之一，周围有很多店铺。
LONG
    );
    set("outdoors", "yangzhou");
    set("no_kill",  "yangzhou");
    set("exits", ([
        "north"     : __DIR__"bei_men",
        "east"      : __DIR__"beishi",
        "northwest" : __DIR__"wentongta",
    ]));
    set("objects", ([
    ]));
    setup();
}
