
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"�¸�֮��"NOR);
	set("long", HIC @LONG
   ����һ�����ڸ�ɽ�ϵĳǱ���ǽ�ڼ��ذ嶼���Դ���ʯ����� ǽ��
���м�ֻ���ȼ���������컨���������������ֵ�С�ף�Ӧ���Ǵ˳�
����ͨ��ף������ܵľ��￴���˵رض���ǧ�����ϵ���ʷ�����Ǿ���
�����ҿ�������.
LONG NOR);

set("magicroom",1);set("outdoors","migong");
set("magicset",1);
set("no_npc",1);
set("no_fight",1);
	set("exits", ([
		"south" : __DIR__"dong23",
		"north" : __DIR__"dong0"+(random(6)+1),
	]));
         set("objects", ([
              __DIR__"npc/player" : random(2),
         ]));

	set("no_clean_up", 0);
	setup();
}
/*
int valid_leave(object me, string dir)
{
	object *inv,kicker;
	int sizeinv,n,tt;
	
       if ( !present("water jian", me) && dir == "north" )
        return notify_fail("һ��ʿ����ס���㣺��ͨ��ˮ֮����ʹ�Ŀ�������??\n");
       if ( !present("water armor", me) && dir == "north" )
        return notify_fail("һ��ʿ����ס���㣺��ͨ��ˮ֮�������Ŀ�������??\n");

	if (dir =="north")
	{

		inv=all_inventory(me);
		sizeinv=sizeof(inv);
	
		while (sizeinv--)
		{
       			if (inv[sizeinv]->is_character())  
     				return notify_fail("�����ȥ�����˿ڣ�\n");
       		
		}
		
	}

	return ::valid_leave(me, dir);
}
*/