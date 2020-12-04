// Room: /huanghe/shamo.c
// Java. Sep 21 1998

#include <room.h>
#include <ansi.h>

inherit ROOM;
void create()
{
	set("short", "ɳĮ");
	set("long", @LONG
����һƬû�߼ʵ�ɳĮ�������ǽ����׸ߵľ޴�ɳ����һ�߽���
�ͷ·�����·��
LONG );
	set("exits", ([
		"north" : __FILE__,
		"south" : __DIR__"shamo1",
		"east"  : __FILE__,
		"west"  : __FILE__,
	]));
	set("no_clean_up", 0);
	set("outdoors", "huanghe");
	setup();
}
void init()
{
	object ob = this_player();
	if (ob->query("water") > 10)
		ob->set("water", ob->query("water") -10 );
	else
		ob->set("water", 0 );
	message_vision(HIY"�����ɳ��$N�е�����ð�̣��ɿ��Ѱ���\n"NOR, ob);
}

int valid_leave(object me, string dir)
{
	object ob,obj ;
	int total_steps = random(9)+1;
	ob=me;
	if ( dir == "north")
		me->add_temp("shamo/steps",1);
	if ( dir == "south")
		me->add_temp("shamo/steps",-1);
	if (me->query_temp("shamo/steps") == total_steps)
	{
		obj=present(ob->query("id")+" "+"wulin renwu", environment(ob));
if (obj) obj->move(__DIR__"jingyuan");
		me->move(__DIR__"jingyuan");
		me->delete_temp("shamo/steps");
		return notify_fail("�����˰��죬�����߳�������ɳĮ��\n");
	}
	if (me->query_temp("shamo/steps") == - total_steps )
	{
		
				obj=present(ob->query("id")+" "+"wulin renwu", environment(ob));
if (obj) obj->move(__DIR__"qingcheng");
		me->move(__DIR__"qingcheng");
		me->delete_temp("shamo/steps");
		return notify_fail("�����˰��죬�����߳�������ɳĮ��\n");
     	}
	return ::valid_leave(me,dir);
}
