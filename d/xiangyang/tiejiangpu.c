// Room: /d/xiangyang/tiejiangpu.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����ԭ����һ�Ҽ����ª�������̡��������ɹŴ���Ŵ�
������������������̱��ٸ����ã���Ϊ�ٰ�������Ŀǰ��ģ
�ܴ�һ������Ϊ�����ؾ��������ס������ȣ�������������
�ﱸ�س����ʣ��������֮��Ҳ����һЩ��ǥ����������ľ��
ͷ�ȡ�ֻ����ʮ������������������æ����ͣ��
LONG );
	set("exits", ([
		"west" : __DIR__"southjie3",
		"east" : "quest/skills2/wakuang/zhujia",
	]));
	
set("roomif","$botten#����|Ѱ��|���|����|�ķ�|����:give 20 silver to huoji|ask huoji about job|cuihuo|dapi|gu|ask tiejiang about job$#");  
	
	
	set("objects", ([
		__DIR__"npc/tiejiang" : 1,
		__DIR__"npc/huoji" : 1,
	]));
	setup();
	replace_program(ROOM);
}
