// created by angell 1/1/2001
// room: /d/qujing/huangfeng/huangfeng5.c


inherit ROOM;

void create ()
{
  set ("short", "�Ʒ���");
  set ("long", @LONG

����Ƶ������ط��ᡣ���۵Ĳ��ɴ�أ��̲�������һ��
СϪ��·������ˮ�����ˣ���Ȼһ��������ɫ����ֻС��
���������Ӳ���������һת���ܵò�֪���١�

LONG);

  set("exits", ([
        "southwest" : __DIR__"huangfeng4",
      ]));
        set("outdoors", "xy6");
       
  setup();
}