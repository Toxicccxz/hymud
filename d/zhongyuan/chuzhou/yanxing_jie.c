// 楚州炎兴街 /d/city/chuzhou/yanxing_jie.c
// by lala, 1997-12-04

inherit ROOM;

void create()
{
    set("short", "炎兴街");
    set("long", @LONG
炎兴街不象其它街道上那么喧闹，静悄悄的，几乎没有人来往，偶尔有人通
过也是急急忙忙，不多作停留。原来州府衙门就在这条街上，大家都不愿意让六
扇门里的公人惹上身来，所以这里就很少有人走动了。不过这里还是有座名胜古
迹的——路南的祠堂是汉魏侯祠。
LONG
    );
    set("outdoors", "yangzhou");
    set("no_kill",  "yangzhou");
    set("exits", ([
//        "north"     : __DIR__"yamen",
        "east"      : __DIR__"dong_men",
        "south"     : __DIR__"hanxin_ci",
        "west"      : __DIR__"dongshi",
    ]));
    set("objects", ([
    ]));
    setup();
}
