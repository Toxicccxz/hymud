 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "白云山庄");
        set("long", @LONG
山庄里摆着一百二十张八仙桌，每张桌旁都坐满了客人，只是，每个客人都板着
脸，紧张得神经兮兮的样子。似乎发生了什么意外之事。几个满头珠翠的妇人，手里
捧着碗茶，在和旁边的女伴窃窃私语。
LONG       );
        set("exits", ([ 
                "west": __DIR__"yuanvillage2",
               "east": __DIR__"yuanvillage3",
                "south": __DIR__"yuanvillage3",
                "north": __DIR__"yuanvillage3",
        ]));
        set("objects", ([
                
        ]) );
set("coor/x",-1090);
        set("coor/y",195);
        set("coor/z",0);

        setup();
        //replace_program(ROOM);
}       
