// Room: /d/yueyang/nanmen.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
�����������ǵ����š���ʯ��������¥̨����쳣��Ρ������Ĺ�
�γ����Ϸ������š�����������������֡�������һ����������ͨ��
������
LONG );
	set("outdoors", "yueyang");
	set("no_clean_up", 0);
	set("objects", ([
		__DIR__"npc/bangzhong" : 3,
		__DIR__"npc/li-chunlai" : 1,
	]));
	set("exits", ([
		"north"     : __DIR__"nanjie",
		"southeast" : "/d/changsha/dadao3",
	]));
	set("coor/x", -1410);
	set("coor/y", -2290);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}