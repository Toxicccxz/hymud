// Room: d/kyoto/chitianwu
// created by keinxin's roommaker

#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "������");
set("long", @LONG
��������������ĳ����ݣ�ʮ��ǰ���ݵ�Ļ��ά��־ʿ���������ܼ�
�ᣬ���������׫�飬˫��������ս��ά��־ʿ���˲��أ��ҿ�糴彣��
��ʱ�ϵ������˹�С���ɺ�������Ҫ���쵼�ߣ�ά���˶����ܳɹ�������
����Ѿ���Ϊ����Ҫ����ʷ����أ����λͬ�й����й�һ���ַ��ࡣ
LONG );
set("exits",  ([
        "south"  : __DIR__"qianbending2",
      ]));
        setup();
        replace_program(ROOM);
}