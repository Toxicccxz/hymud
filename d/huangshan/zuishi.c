 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "醉石");
        set("long", @LONG
传说这是李白醉酒卧眠之处，石上人形依稀可见，观其形状恰似酒至鼾处，石
侧有醉石二字，笔力遒劲，边上立有牌坊一座，历代文人题字皆在此处。由醉石继
续南行便是试剑石。
LONG
        );
        set("exits", ([ 
  "south"  : __DIR__"shijian",
  "northeast" : __DIR__"qingluan",
  "westdown" : __DIR__"sandie",
]));
        set("objects", ([
        __DIR__"obj/stone2" : 1,
                        ]) );
        set("outdoors", "huangshan");
                set("NONPC",1);

        set("coor/x",-550);
        set("coor/y",-520);
        set("coor/z",10);
        setup();
} 
