// Room: d/kyoto/longangate
// created by keinxin's roommaker

#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "����������");
set("long", @LONG
���������µ����ţ��Ʒ�ֱ��������ΡΡ׳�ۣ����ɫ�Ĵ�������
�е�ׯ�غ;�η��������ȥ���Ǹ�ɮ�Ƽ�֮���������п���ʹ��������
�������ǰ����ɮ�Դ���ˮ��
LONG );
set("exits",  ([
        "east"  : __DIR__"longandao2",
      ]));
        setup();
        replace_program(ROOM);
}