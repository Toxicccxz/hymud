// created by snowcat.c 11/16/1997

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

ɽ�����ݵش����Ĵ��ǽ�ˮ�����������޷���š������Ǹ�ɽ
���룬���߽���ˮ������������ϱ���һ���¡�

LONG);

  set("exits", ([
        "up"    : __DIR__"jiandi5",
      ]));
  set("objects", ([
        __DIR__"npc/shuizhi" : 1,
      ]));
  set("outdoors", "xy27");
  setup();
}
