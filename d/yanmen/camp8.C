#pragma save_binary
// ROOM:__DIR__"camp8"

inherit ROOM;
void create()
{
        set("coor",({-220,4250,0}));
	set("short","����Ӫ��");
	set("long",
"��ͷ����Ӫ������Ƥ�������ϣ������ޱȣ������������죬˫������ͼ����ǰ����Ȼ������\n"
"֮�ƣ���������������������ǡ�����������ȫ��һ�ࡢһ�ġ�һ�ϡ�һ�ѡ�һ������ī\n"
"�±������ԣ��������ϣ���ı���ң��ɲ���������η��\n"
); // eof(long)
	
	set("exits",([ /* sizeof()==1*/
        	"west" : __DIR__"camp7",
        	"east" : __DIR__"blackmarket",	
	"north" : "/d/tieflag/dreamland/shanpo",
	]) ); //eof(exits)

	set("objects",([
		__DIR__"npc/general" : 1,
		__DIR__"npc/adviser" : 1,
	]) );
	
	setup();
	
} //EOF
int valid_leave(object me, string dir)
{


	if ( objectp(present("master general", environment(me))) && 
		dir == "east")
		return notify_fail("��͢����ס�����ȥ·��\n");


	return ::valid_leave(me, dir);
}
       