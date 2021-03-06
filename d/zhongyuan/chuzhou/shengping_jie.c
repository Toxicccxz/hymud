// 楚州升平街 /d/city/chuzhou/shengping_jie.c
// by lala, 1997-12-04

inherit ROOM;

void create()
{
    set("short", "升平街");
    set("long", @LONG
升平街真是个歌舞升平的地方，路东是城里最大的妓院弄玉坊，不时有达官
贵人、风流公子进出。从半掩的黑漆大门里面飞出一阵阵欢歌笑语，不知有多少
人在此醉生梦死、寻欢作乐。高高的围墙上面，一枝红艳艳的杏花迎风招展。
    街的西北是充斥着三教九流的南市，街的南面就是出南门的物华街了。
LONG
    );
    set("outdoors", "yangzhou");
    set("no_kill",  "yangzhou");
    set("exits", ([
//        "east"      : __DIR__"nongyu_fang",
        "south"     : __DIR__"wuhua_jie",
        "northwest" : __DIR__"nanshi",
    ]));
    set("objects", ([
    ]));
    setup();
}
