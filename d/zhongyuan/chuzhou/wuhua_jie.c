// 楚州物华街 /d/city/chuzhou/wuhua_jie.c
// by lala, 1997-12-04

inherit ROOM;

void create()
{
    set("short", "物华街");
    set("long", @LONG
物华街和城北的天宝路相对应，合取“物华天宝”之意。从这条街向东南走，
就可以出南门走上去扬州城的大路了。街北是升平街，传来一阵阵笑闹声；街西
是家当铺，不少在这个销金窝子里面花尽了钱财的人不得不到当铺去凑足回家的
盘缠；街的东面是家镖局，门口蹲着一对石狮子，宝蓝色的镖旗呼啦啦的飘着，
上面写的似乎是“扬威”两个字。
LONG
    );
    set("outdoors", "yangzhou");
    set( "no_kill",  "yangzhou" );
    set("exits", ([
        "east"      : __DIR__"biaoju",
        "southeast" : __DIR__"nan_men",
        "north"     : __DIR__"shengping_jie",
        "west"      : __DIR__"dangpu",
    ]));
    set("objects", ([
    ]));
    setup();
}
