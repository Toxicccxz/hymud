// Room: d/kyoto/heyuan1
// created by keinxin's roommaker

#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "��ԭ");
set("long", @LONG
���Ǿͺ�ԭ���Ǿ��������Ĵ������ͨ�����ݺύ���ĵ�·������
����������Ǿ����ľ�ס���������Ǻ�ԭ�������͵������еĵ�
��������ѧ�յ������ﲻ���������Ƿɼ��ڻ��Ǻ��ϵĽ��ţ����Կ���
ׯ�����µľ����������������ջʹ���
LONG );
set("exits",  ([
        "east"  : __DIR__"heyuanting1",
        "south"  : __DIR__"jinqiao",
        "west"  : __DIR__"xijingting1",
        "north"  : __DIR__"longandao3",
      ]));
        setup();
        replace_program(ROOM);
}