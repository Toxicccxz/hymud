#pragma save_binary
// ROOM:__DIR__"camp7"

inherit ROOM;
void create()
{
        set("coor",({-230,4250,0}));
	set("short","����Ӫ��");
	set("long",
"��������������ܵľ���������˲������ţ���ǰ��ľ�Ӫ������ͬ����Ƥ���ھ��Σ�\n"
"�������ںڸ���ʯ���ϣ���Ϊ��Ե˫����ͼ������������������ȣ�����������ë��Ƥ�̳�\n"
"����ȷʵ�и���Ӫ�ʵ�ζ����\n"
); // eof(long)
	
	set("exits",([ /* sizeof()==2 */
		"east" : __DIR__"camp8",
		"west" : __DIR__"camp2",
	]) ); //eof(exits)

	set("objects",([
		__DIR__"npc/vice_general" : 1,
	]) );
	
	setup();
	
}

int valid_leave(object me,string dir)
{
	if ( dir=="east" && !(string)me->query("marks/��Ӫ") )
        return notify_fail("�㻹û������\����ม�\n");
	
	return ::valid_leave(me,dir);
}