// Room: /d/nanshaolin/banruo4.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "�������Ĳ�");
	set("long", @LONG
����һ�伫Ϊ��ª���������������ܣ����˼�������⣬���ڿյ�
���ر��������������İڷ��ż��������ҷ��ڵĻƲ����ţ���λ��
�����׵���ɮ�������������Ŀ�붨�������Ǳ���ʮ���޺��������е�
�ط������پ����书�����ڴ������
LONG );
	set("exits", ([
		"south" : __DIR__"banruo3",
		"north" : __DIR__"banruo5",
	]));
	set("objects",([
		__DIR__"nanshaolin/yuanhuan" : 1,
	]));
	set("coor/x", 1880);
	set("coor/y", -6250);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
