// /yubifeng/changlang.c
// Last modified by winder 2003.9.2

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ�����������ȣ��Ĵ�͸��ŨŨ�ĺ�������ȥ�������ɽׯ��
���ţ��������߹�ȥ����ֱ���������Χһ����Ⱦ���ǳ�������
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
		"north" : __DIR__"dating",
		"out"   : __DIR__"damen"
	]));
	set("objects", ([ /* sizeof() == 4 */
		__DIR__"npc/xuanmingzi" : 1,
		__DIR__"npc/lingqing" : 1,
		__DIR__"npc/jiang" : 1,
	]));

	set("coor/x", 6120);
	set("coor/y", 5170);
	set("coor/z", 100);
	setup();
	//replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
	if ( objectp(present("jiang", environment(me))) && 
		dir == "north")
		return notify_fail("����ȭʦ��ס�����ȥ·��\n");

	if ( objectp(present("xuanming zi", environment(me))) && 
		dir == "north")
		return notify_fail("��ڤ����ס�����ȥ·��\n");

	if ( objectp(present("lingqing jushi", environment(me))) && 
		dir == "north")
		return notify_fail("�����ʿ��ס�����ȥ·��\n");

		

	return ::valid_leave(me, dir);
}