
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","后门");
  set ("long", @LONG
这里是净念禅院的后门。这里人很少，平时几乎没有什么人来这里。
LONG);

  set("exits", ([ 
	 
	  "west":__DIR__"shilu5",
//	  "east":"/d/xingyang/shanlu3",
  
         ]));

  set("outdoors","chanyuan");
  set("valid_startroom", 1);
  setup();
 
}

