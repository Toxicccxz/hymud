// /kaifeng/caidi3.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "�˵�");
	set("long", @LONG
��Ƭ��԰�Ӽ����������һЩʱ���߲ˡ������м���ľ׮����Ĳ�
���ӣ���һЩ���ٵ��߲��������������Ŀ��ȥ���ϴ��һƬ��԰�ӣ�
��Ȼ���������û�м��òˡ�
LONG);
	set("no_clean_up", 0);
	set("exits", ([
		"west"  : __DIR__"caifang",
		"south" : __DIR__"caidi1",
	]));
	set("objects", ([
		__DIR__"npc/qigai" : 1,
		"quest/skills2/wunon/non/nontian" : 2,
		"/clone/npc/man" : 2,	
	]));	
	set("outdoors", "xiangguosi");

	setup();
	replace_program(ROOM);
}