
#include <ansi.h>

inherit ROOM;

#define SHIPDIR __DIR__"ship"
#define FROM __DIR__"huanghe_dukou1"
#define TO __DIR__"huanghe_dukou2"
#include "shiproom.c"

void create ()
{
  set ("short","南江渡口");
  set ("long", @LONG
这里是南江的渡口。面前南江水滚滚，气势惊人。只有一叶扁舟载来
往的行人。
LONG);

  set("exits", ([ 
"south":__DIR__"huanghe_dukou2",
  "north":"/d/henshan/hsroad4",
  "east":__DIR__"huanghe4",
         ]));
set("outdoors","guizhou");
  set("valid_startroom", 1);
  setup();
 
}
