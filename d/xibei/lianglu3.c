//lianglu3.c

inherit ROOM;

void create()
{
        set("short", "黄土大道");
        set("long", @LONG
一条坦荡的黄土官道向东西延伸,路上人迹已经渐渐稀少.
偶尔有一两队客商骑马或步行与你擦肩而过,看他们风尘仆仆的样子,显然
走过一段漫长而艰辛的旅途.
LONG
         );
        set("exits", ([ 
                "east"          :       __DIR__ "lianglu2",            
                "northwest"     :       __DIR__ "lianglu4",
                ])
        );
//      replace_program(ROOM);
        setup();
}

