// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "��Ұ");
  set ("long", @LONG

��Ұ�Ĵ�������Զ���ɼ�Ⱥɽ�����ͱڣ�������С·������С
ɭ����ľ���紵������֮�����ϣ���ˮ������ʱ�Ų����ƽУ�
ʱ�Ŷ���������

LONG);

  set("exits", ([
        "west"    : __DIR__"huangye2",
        "east"    : __DIR__"huangye4",
      ]));
  set("outdoors", "xy32");
  setup();
}
