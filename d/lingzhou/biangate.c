// Room: /lingzhou/biangate.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
�����ǻʹ��ı��ţ��������������ǳ���֮�ã���������Ķ���һ
�㶼�ɴ����룬��Ϊ�Ƚ�ƫƧ����������ʿҲ���ࡣ
LONG );
	set("exits", ([
		"west"  : __DIR__"bianmen",
		"east"  : __DIR__"xiaolu3",
	]));
	set("objects", ([
		__DIR__"npc/gongweishi" : 4,
	]));
	setup();
//      create_door("west" , "���Ṭ��", "east" , DOOR_CLOSED);
}

int valid_leave(object me, string dir)
{
        if (dir == "west" && 
            objectp(present("wei shi", environment(me))))
           return notify_fail("��ʿ������һ�����������ǲ������ܽ�ȥ�ĵط���\n");

        return ::valid_leave(me, dir);
}
