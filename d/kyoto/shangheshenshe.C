// Room: d/kyoto/shangheshenshe
// created by keinxin's roommaker

#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "�Ϻ�����");
set("long", @LONG
���ܵ�������ӳ�У���Լ�ɼ�һ���ɲ��ԭ����������Ϻ����磬��
˵�����ӡ���Ϲ�ʱ�ڿ��µ�������ֻ���ػ�����֮�Ļ���������˼��
�˲��ܻ������������Ȼ�������˼�ȴ��������ֽ�Ȼ��ͬ�Ľ����
LONG );
set("exits",  ([
        "west"  : __DIR__"juechuan",
      ]));
        setup();
        replace_program(ROOM);
}