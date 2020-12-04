// jinyang_chengxia.c
inherit ROOM;

void create()
{   
    set("short","晋阳城下");
    set("long",@LONG
东边即是晋阳城。晋阳城之城坚池广，自“三家分晋”是就颇为有名。史书
上说，隋唐二朝皆发迹于此。太宗皇帝水淹晋阳城，灭北汉于此，因攻城甚久，
迁怒之下，下令尽毁城池，另筑新城，并挖掉了城北系舟山的山巅龙角，有在新
城中只修丁字路，以钉破其龙脉。现在的晋阳城比原来就小多了。
LONG );
    set("exits",([
        "southwest" : __DIR__"jinci",
        "north" : __DIR__"yidao1",
        "east"  : __DIR__"yidao9"     ]) );
    set("outdoors","zhongyuan");
    setup();
}
