//Cracked by Roath
//  ����֮�� ������
//  by happ@YSZZ 2000.4.5
//  /d/qujing/heifeng/shandao.c

inherit ROOM;

void create ()
{
  set ("short", "ɽ��");
  set ("long", @LONG

�ɴ˿��Ե���ɽ��̨��������ʯ�����ɣ�һ��һ�׸���������·
�������ϣ��·���ߵ��Ʋʾ����Աߣ���һ���־Ϳ���ץ��һ�䡣

LONG);

  set("exits", ([
        "westup"    : __DIR__"shandao3",
        "eastdown"  : __DIR__"shandao",
      ]));
  set("outdoors", "xy4");
  setup();

}