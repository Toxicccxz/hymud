// ROOM:__DIR__"canyon3"

inherit ROOM;
void create()
{
        set("coor",({-300,4300,0}));
	set("short","����С·");
	set("long",
"��������ʯ����ƽ����С·�ϣ���᫵ĵ�·���������Ǳȱ���ƽ�����ˣ����϶�ʮ�������\n"
"�չؿ��ˣ�����Ϊ��Ӫ������Ӫ����Ϊ��դ����Χ�������������Ӫ���ƺ��ǲ�̫���ܡ�\n"
); // eof(long)
	
	set("exits",([ /* sizeof()==2 */
        	"north" : __DIR__"canyon2",
        	"south" : __DIR__"canyon4",
	]) ); //eof(exits)
	
        set("outdoors","yanmen");
	setup();
	
	replace_program(ROOM);
} //EOF