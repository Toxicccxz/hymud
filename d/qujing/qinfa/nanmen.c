// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

�����ĳ�ǽ��ʯ�����ͣ�������Ļ��Ǻ��Ѽ����ɺԣ�������
һ����¥���������Ȼ�ͭ��Ӳľ���ţ�����һ˫��ʯ������
ͨ������⡣

LONG);

  set("exits", ([
        "north"    : __DIR__"jiedao8",
        "south"    : __DIR__"dalu10",
      ]));
  set("objects", ([
        __DIR__"npc/junshi"    : 2,
      ]));
  set("outdoors", "xy31");
  setup();
}

int valid_leave (object who, string dir)
{
  if (! interactive (who) &&
      dir == "south")
    return 0;
  return ::valid_leave(who,dir);
}