//cheng1.c

inherit ROOM;

void create()
{
        set("short","城上");
        set("long", @LONG
凉州四围的城墙之上,整座墙体由大块的青石砌成,厚重坚固, 城垛高
大.由于凉州位于河西走廊的咽喉之处,是西域与北方民族东入中原的必经
之路,因此历代君主对凉州城进行了不停地加固与修赡,使它固若金汤.
LONG
        );
        set("outdoors","liangzhou");
        set("exits", ([ 
                "south"         :       __DIR__ "madao1",            
                ])
        );
//      replace_program(ROOM);
        setup();
}

