
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", GRN"���߲�ԭ"NOR);
	set("long", GRN @LONG
 ���������������ϳ��������̵��ʲݣ�����׺���ϵ�С�׻���ʹ��
�����˾��þ�����죬վ��������Կ���Զ���Ĵ󺣣�������Ϊ���ﶼû
�иߴ��ֲ�
LONG NOR);
set("magicroom",1);
set("magicset",1);
	set("exits", ([
		"south" : __DIR__"dong1"+(random(8)+2),
                "north" : __DIR__"dong21",
	]));
if (random(4)==0)
	set("exits", ([
		"east" : __DIR__"dong1"+(random(8)+2),
                "west" : __DIR__"dong21",
	]));
if (random(5)==1)
	set("exits", ([
		"south" : __DIR__"dong1"+(random(8)+1),
                "north" : __DIR__"dong1"+(random(9)+1),
	]));
         set("objects", ([
"/clone/box/gboxm" : random(2),
              __DIR__"npc/lev1" : random(4),
              __DIR__"npc/lev2" : random(4),
         ]));

	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}