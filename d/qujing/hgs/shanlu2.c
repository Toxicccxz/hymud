//sgzl

#include <room.h>
inherit ROOM;

int grass_number;

void create()
{
set("short", "ɽ·");
set("long", @LONG
    
һ�����������ɽ·���Ĵ�������������Ӣ�ͷס���Χ������
��ż��ߥ����ֻ���ӣ�������������ȥ��·�ߵ�С��(grass)
���Ʈ�衣
LONG );

set("item_desc",(["grass":"
һЩ�����͵�С�ݣ���(ba)����������\n"
]));

set("exits", ([
"west"   : __DIR__"xiaoxiqian",
//"northup"   : __DIR__"shanya",
"northup"   : __DIR__"qitian",
"southdown"   : __DIR__"shanlu1",
]));


set("objects", ([
]));



set("outdoors", "xy19");
setup();
}



void init()
{
   grass_number=5;

   add_action("do_ba", "ba");
}


int do_ba(string arg)
{
   object me = this_player();
   object cao;

   if ( !arg || ( arg != "grass" ) ) 
     return notify_fail("��Ҫ��ʲô��\n");
   else if(grass_number==0)  
     return notify_fail("���Ѿ����ι��ˣ���Ѿ��ˡ�\n");
   else if(me->query("qi")<10) 
     {
     me->unconcious();
     return 1;
     }
   else 
     {
     me->add("qi",-10);
     cao = new (__DIR__"obj/grass");
     cao->move(me);
     message_vision("$N����һ��С�ݡ�\n", me);
     grass_number--;
     }
     return 1;
}
