 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
inherit ROOM;
void create()
{
  set("short","天外村");
  set("long",@LONG
天外村在建岱桥边，东南侧是香油湾。这里有一个美丽的传说：传说吕洞
宾与张果老在此下棋，一卖油郎在旁观棋，后见油挑子已腐烂，香油漂在水湾，
回家后村民皆不识，只言油郎进山200多年未归，方知误入仙界。油郎返回后不
见仙人，只见西北飞鸦峰上有一对仙人影。如今站在桥上，远望飞鸦峰南崖，
仍有仙人对拱而立，西方稍白者已被翠柏所掩。
LONG
  );
  set("exits",([
         "southdown":__DIR__"daizong",
         "up" :__DIR__"wanxian",
        "westup" : __DIR__"puzhao",
        "eastdown" : __DIR__"wangmu",
               ]));
        set("objects", ([
        __DIR__"npc/songzong" : 1,
                        ]) );
        set("outdoors", "taishanfy");
        set("coor/x",310);
        set("coor/y",2380);
        set("coor/z",10);
        setup();
        replace_program(ROOM);
}  
