#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIM"������Թ�"NOR);
	set("long", HIM @LONG
   ��������һ���ƾɵķ��棬����ɢ�������ܵ�ʯ����ʯ�顣���д����
���ﱻ�����Ѹ������ˡ���Ƭ���������ľ���ͳ��Ÿ�����ΰ�����Ľ���
���Ǹ���Ϊ���̵ĶԱȣ����ֱ�������㻹�������߲����ҵ���·��
LONG NOR);
set("magicroom",1);set("outdoors","migong");
set("magicset",1);

	set("exits", ([
		"west" : __DIR__"dong80",
		"east" : __DIR__"dong7"+(random(5)+3),
		"north" : __DIR__"dong7"+(random(5)+3),
		"south" : __DIR__"dong7"+(random(4)+1),
	]));
if (random(2)==0)
	set("exits", ([
		"west" : __DIR__"dong80",
		"east" : __DIR__"dong7"+(random(5)+4),
	]));
if (random(2)==0)
	set("exits", ([
		"south" : __DIR__"dong7"+(random(3)+1),
		"north" : __DIR__"dong80",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}