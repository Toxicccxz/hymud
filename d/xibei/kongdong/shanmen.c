//1997-3-10 by qyz
#include <room.h>

inherit ROOM;



void create()
{
        set("short","崆峒山门");
        set("long",@LONG
一片苍松古柏之间，掩映着崆峒山门，此地环境清幽静谧，入口处，一栋高
大的门楼，古色古香，顶上书“崆峒胜境”三个烫金大字，门柱上是一副笔走龙
蛇，字体遒劲的石刻楹联：“洞天福地，名山宝刹”，往里进去是一条平坦的青
石大道，一直引向里面的庭院。
LONG);
        set("exits",
        ([
          "southdown" : __DIR__"juxian_qiao",
          "west" : __DIR__"qipan_ling",
          "north" : __DIR__"tingyuan",
        ]));
        
	set("objects" , ([
"/clone/misc/dache" : 1,	
		]) );
        
        create_door("north","红漆木门","south",DOOR_CLOSED );
        setup();
}
