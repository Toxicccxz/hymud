inherit ROOM;


void create()
{
   set("short","����ƽԭ");
   set("long",@LONG
�Ĵ����������ůʪ�����ط������ɽ��ˮ�㣬����ḻ��һ���С���
��֮���������ơ��������칫�����������˳����Ȼ�ٸ������տ�����˰������
Ҳ���ܹ���ȥ��
    ������һƬ���ʵ�Ⱥɽ����������һƬ��ƽԭ��
LONG);
   set("exits",([
      "north"   : __DIR__"pingyuan1",
      "south"  : __DIR__"pingyuan3",
       ]));
   setup();
        set("outdoors","xinan");
}