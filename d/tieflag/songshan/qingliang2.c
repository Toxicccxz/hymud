 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "清凉寺");
        set("long", @LONG
已接近山脚，独处一隅，数千株翠柏苍松密密的把寺庙围在当
中，即便在夏日之中，依旧阴凉无比，故此寺名清凉。每年秋天松
果盈树，清香扑鼻。此间有松茶最为吸引人，常有人不远千里来品
尝寺中长老调制的松茶。每年春天这里的松针落得满地，都需要人
略做打扫，否则便会积成淤泥。
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"qingliang",
]));
        set("coor/x",-220);
        set("coor/y",380);
        set("coor/z",50);
        set("objects", ([
                "/kungfu/class/shenlong/heshang" : 1,
        ]) );
        setup();
        //replace_program(ROOM);
}      
