// Room: d/kyoto/zahuowu.c
// created by keinxin's roommaker

#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "�ӻ���");
set("long", @LONG
����һ����ʷ�ƾõ��ӻ��ݣ��ϰ弪���������������ƣ������������
�������ﲻ��������һЩ�����ʵ��Ľ�ʿ���֪���ı�����Ѻ�������˵
�������˸������﷢����ʧ���Ѿõ��������ķ�Ҫ����֮����ؽ��Ͷ�����
�ϣ�����г�һ����һ���������ϵ��伮������Կ�������(paizi)��
������������Щ�������ۡ�
LONG );
set("item_desc", ([
		"paizi": "���� \"list\" �г��������\"buy\" ���ϰ幺�\n",
	]));
set("exits",  ([
        "south"  : __DIR__"xijingting1",
      ]));
      set("objects", ([
		__DIR__"npc/jitian": 1,
	]));
        setup();
        replace_program(ROOM);
}