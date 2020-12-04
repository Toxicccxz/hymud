// Room: /jyguan/dongmen.c �����ض���
// Ver 0.1 08/14/1998 by Freeze

#include <ansi.h>
inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", HIY "�� �� ��"NOR);
	set("long", @LONG
���Ƕ����ţ��������Ϸ����š����š�����������֣�һ���ǽ�����ż���
�ٸ���ʾ(gaoshi)���ٱ��Ǿ����ע���Ź������ˣ������С��Ϊ�һ����ֱ
����ש��������������졣�����ǹٵ����ɼ��̶Ӻ��۷����������������߾�
���������ˡ�
LONG
	);
        set("outdoors", "jyguan");

	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));
	set("exits", ([
		"east" : __DIR__"road5",
//		"north" : __DIR__"beimen",
		"west" : __DIR__"guangchang",
	]));

	set("objects", ([
		__DIR__"npc/wujiang" : 2,
		__DIR__"npc/bing" : 5,
	]));

	setup();
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n�������ܱ�\n    ��־��\n";
}
