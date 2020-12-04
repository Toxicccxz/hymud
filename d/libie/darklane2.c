 // Room: darklane2.c --- by MapMaker
#include <ansi.h>
inherit ROOM; 
void create()
{
        set("short", "���ﾡͷ"); 
        set("long", @LONG
С����խ�ְ���һ������ʪ����ķ��ƹ����ʱ��ʱ�ޣ��㲻��
���˸���ս��Ѫ��֮�������ڿ���֮�У�һ��Ī���Ŀֲ���ǿ�ҵĿ�
�������ʰ�ѹס�������ͷ��Ѫ����ص�Ѫ��ʬ������ȱ��ʬ������
����ͻȻ������һ����Ұ�ް��������һ������ĺ����͸�����
���裬��͸������ġ�
LONG); 
        set("type","street");
        set("exits",([
        "south":__DIR__"darklane1",
        ]) ); 
    set("objects", ([
        __DIR__"npc/huzi" : 1,
        "/kungfu/class/honghua/wen-tailai" : 1,
    ]) );
        set("indoors", "libie");
        set("coor/x",40);
        set("coor/y",220);
        set("coor/z",0);
        setup();
} 
void init()
{
        
  add_action("do_heal","heal"); 
} 
int do_heal(string arg)
{
    object me, ob, ob1, ob2;
    me = this_player();
    ob = present("huzi", this_object());
    ob1 = present("snow lotus", this_player());
    ob2 = present("pill", this_player());
        if( !ob || userp(ob)) return 0;
        if( !arg || (arg != "xiao huzi"&&arg!="huzi" &&arg!="С����")) return notify_fail("��Ҫ��˭��\n");
        if( !ob1 && !ob2 ) return notify_fail("���ֿտվ�����ˣ�\n");
        if( me->is_busy() ) return notify_fail("����һ��������û����ɡ�\n");
        if( !ob->query_temp("is_unconcious")) return notify_fail("�������أ�\n");
        if( ob1 )
        {
            message_vision(HIG"$N����С���ӵ��°ͣ���һ����ɽѩ��С�����������������ڣ�\n"NOR,this_player());
            destruct(ob1);
        }
        else if( ob2 )
        {
            message_vision(HIG"$N����С���ӵ��°ͣ���һ�ž�ת���굤С�����������������ڣ�\n"NOR,this_player());
            destruct(ob2);
        }
        ob->revive();
        ob->set("������",me);
        return 1;
}       