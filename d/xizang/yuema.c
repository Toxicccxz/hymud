 inherit ROOM;
void create()
{
      set("short", "Ծ��Ͽ"); 
        set("long", @LONG
һ·��������³�ز���������ӿ������������Ϊ����ɽ���µ�ѩˮ��������һ
����ɫ�ľ����������򶫱�������ظ�ԭ���ϲ���һ·�γ��˿����ĺӹȣ�������
��Ľ��紦����ϲ������ɽ������߷����Ȱ��߷嵲סȥ·�����ȸ����γ�����
�����µĵġ������Ρ������Ͽ�ȣ����˳�Ϊ��Ծ��Ͽ��������ֱ�佭�棬��һ��
��ˮ����Ƕ�ھ޸�������ʯ����������ڣ�����ɽϿ��
LONG); 
         set("exits", ([ 
                "east" : __DIR__"hutiao",
        "north" : __DIR__"nujiang",	
        ]));
        set("outdoors", "xizang"); 
        set("type","street");
        set("objects", ([
        ]) ); 
        set("coor/x",-880);
    set("coor/y",-500);
        set("coor/z",0);   
        set("objects", ([
                __DIR__"npc/yema2" : 1,
       ]) ); 
        setup();
        replace_program(ROOM);
}       