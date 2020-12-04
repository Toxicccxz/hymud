
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","卧室");
  set ("long", @LONG
这里是禅院弟子休息的地方。床上的被褥叠得整整齐齐，有几个弟
子正在那里熟睡。你来到这里不禁有些困了。
LONG);

  set("exits", ([ 
	  "west":__DIR__"caodi3",
       ]));

  set("sleep_room",1);
	set("objects", ([ /* sizeof() == 3 */
  __DIR__"npc/obj/jiudai" : 2,
  __DIR__"npc/obj/doufu" : 2,
  __DIR__"npc/obj/mifan" : 2,
]));
  set("valid_startroom", 1);
  setup();
 
}

int do_sleep(object ob)
{
   object obj;
   
   if(!ob->query_temp("try_bai_butan_actoin1"))
   return 1;

   obj=new(__DIR__"obj/jinfo");
   obj->move(ob);
   tell_object(ob,"\n你突然发现了一个金佛，连忙拣了起来！\n\n");
   ob->delete_temp("try_bai_butan_actoin1");
   ob->set_temp("try_bai_butan_actoin2",1);
   return 1;
}