 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
inherit ROOM;
void create()
{
  set("short","հ³̨");
  set("long",@LONG
�˴�����̩ɽ��ּ���������Զ������³��ؾ����۵ͣ�������Ϊհ
³̨��̨��һ����ͤ����������ЪϢ��
LONG
  );
  set("exits",([
        "west" : __DIR__"bixia",
        "north" : __DIR__"riguan",
               ]));
        set("outdoors", "taishanfy");
    
        
        set("coor/x",340);
        set("coor/y",2390);
        set("coor/z",120); 
        set("objects", ([
               __DIR__"npc/shengdaniang" : 1,
                        ]) );  
        setup();
        replace_program(ROOM);
}     