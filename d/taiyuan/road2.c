// /d/taiyuan/road2.c
// Room in ̫ԭ
// modify by yang

#include <room.h>
inherit ROOM;
void create()	
{
	set("short", "������");
	set("long", @LONG
��������ɽ����,��Χ�ǲ��͵��ֵ�ɽ��,�����ľ�.���ڽ�����Ϊ����ʱ������
��η������������¡���Ҫ������ǧ������á�����ȣ�����ǧ�������Ԫ��
���������𣬸�6�ף�ÿ���Ը����������������������Ҳ���һ������ʱ���͵�
���ӣ������ɴ��������λ����Ժ���У����ڹ�������Ĳ���񣬵��ϵ�����
¬��Զɽ��ˮһ�����ࡣ����ɽ�ţ���������ĳ������������鷨���ҵı��ģ�
�������ס�
LONG
        );
set("outdoors", "taiyuan");
set("exits", ([
                "east":__DIR__"road1", 
                "southwest":__DIR__"road3", 
                
	]));
       setup();
       replace_program(ROOM);
}

