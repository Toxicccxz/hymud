#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIR"�ص�"NOR);
        set("long", @LONG
�����������ص���ɽ�����������죬��֪ͨ���δ���ǰ��ĵ�·Խ��
Խ�������Ҫ�����������ˡ�����������ǣ���������һ�ɴ̱ǵ�ζ����
��һ�߹��������ͷ�Է��Σ������ж��ˡ�
LONG);        
        set("objects", ([
                    __DIR__"npc/zhuye" : 1,
                    __DIR__"npc/fushe" : 1,   
                    __DIR__"npc/hama" : 1,                         
                    __DIR__"npc/jumang2" : 1,
        ]));
        set("exits", ([
              "west" : __DIR__"midao7",
              "north" : __DIR__"midao6",
              "south" : __FILE__,
              "east" : __FILE__,
        ]));
        setup(); 
}

void init()
{    
  	object me = this_player();
     	if (random(me->query("kar")) <14 && me->query_con() < 38){ 
        	tell_object(me, HIB "���Ȼ�е�����һ����ԭ��������Ŀ������ǡ���ͨ������\n" NOR );      
             	tell_room(environment(me), me->name()+"ͻȻ��ɫ��ü�Ϊ�ѿ�������������˿�����\n" NOR,({ me }));
//             	me->receive_damage("neili", 90);
             	me->receive_damage("jing", 50);
             	me->receive_wound("jing", 30);
             	}              
       add_action("do_use", "use");
}

int do_use(string arg)
{
        object me;
        me = this_player();
        if( !arg || arg=="" ) return 0;
        if (!present("fire", me))  return 0;
        if( arg=="fire" ) {
             write("���ȼ�˻��ۣ�ֻ������������һ�Ѷѵ��߹ǣ�����Ķ�����
���������ѻ��Ķ���ʬ�������������ڴ˴���������ͨ������
����Խ��Խ�࣬�������޷����ܡ�\n");
             this_player()->set_temp("learn_poison", 1);
             return 1;
       }
}