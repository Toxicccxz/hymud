// Room: /d/city2/matou1
// Date:  inca    98/08/18

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIW "������ͷ" NOR);
	set("long", @LONG
�����Ǿ��Ǹ۵���ͷ��������ͣ�����ബ(chuan)����ͷ��ʮ����
�֣����˻���Ĺ��������ػ��»���һЩ�����ڴ˵Ⱥ���������������
һ�Σ��⴬�Ĵ���æ�Ĳ����ֺ���ϲЦ�Կ���
LONG
	);
	set("no_fight",1);
	set("item_desc", ([
		"chuan":"�����кܶബ�����Ҫ�����Ļ��������Ҵ�����һ����\n",
		]));
	set("exits", ([
                "east" :"/d/beijing/yongding",
			]));
	set("objects", ([
		 __DIR__"npc/shaogong1" :1,
	]));
	set("outdoors", "beijing");
	setup();
	
}
void init()
{
        add_action("do_enter", "enter");
}

int do_enter(string arg)
{
        object me,room;
        me=this_player();
        
        if (!arg || arg=="" || arg != "chuan" )  return 0;
       if (arg=="chuan")
                {
                if ( !(int)me->query_temp("ok"))
                        return notify_fail("�㻹û���⵽�����������ӵĴ�����\n");
			else
			 if (!(int)me->query_temp("ok1")) 
			  return notify_fail("����˵�����͹�����˵�õ����С�Ĳź�׼����\n");
			 if( !(room = find_object(__DIR__"xiaozhou1")) )
            			room = load_object(__DIR__"xiaozhou1");
        		if( room = find_object(__DIR__"xiaozhou1") ) 
            			if((int)room->query("yell_trigger")==1 ) 
				 return notify_fail("����˵�����͹ٲ�Ҫ��������ûͣ�ȣ����Ժ\n");
			else {room->set("yell_trigger", 1);
                        message("vision", me->name() + "����С����\n", environment(me), ({me}) );
                        message("vinson","��̤��ľ�壬ҡҡ�λε�����С�� \n"+
					  "��������һ�ţ����뿪��ͷ������ʻȥ\n" ,me);
                        me->move(__DIR__"xiaozhou1");}
                }
        return 1;
}

