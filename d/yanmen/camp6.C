#pragma save_binary
// ROOM:__DIR__"camp6"

inherit ROOM;
void create()
{
        set("coor",({-240,4240,0}));
	set("short","С�ӳ�Ӫ��");
	set("long",
"���Ʊ��ߵ�Ӫ�ʣ��տյ����ģ�������һ��Ҳ�����Ǿ�Ӫ��һ������ĸо�Ҳû�У�����Ҳ\n"
"�����Ѽ��׵����Σ���λ�ӳ���ƽ��С��û�������ǲ������Խ�������ģ��򶫱��Ǹ���Ӫ\n"
"�ʣ���û�о������������ǲ��ý���ġ�\n"
); // eof(long)
	
	set("exits",([ /* sizeof()==1 */
        	"north" : __DIR__"camp2",
	]) ); //eof(exits)

	set("objects",([
		__DIR__"npc/captain" : 1,
		__DIR__"npc/leader2" : 1,
	]) );
	
	setup();
	
	replace_program(ROOM);
} //EOF