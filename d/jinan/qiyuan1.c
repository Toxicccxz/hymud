 //��Է
#include <room.h>
#include <ansi.h>
inherit ROOM; 
string look_string(); 
void  create  ()
{
    set  ("short",  "������Է");
    set  ("long", 
"��Է�����ĸ���䣬����̸���ܵĺõط���������ϱ�����������
�����һ�����ң���ÿ�����ҵ����ⶼ����"HIY"����������"NOR"��
���ӣ��ڷ�������������ϻ�����һ������ָ��(book)��
"); 
    set("item_desc", ([
    "book" : ( : look_string : ),
    ])); 
    set("exits",  ([
    "west" : __DIR__"qiyuan2",
    "south" : __DIR__"qiyuan3",
    "north" : __DIR__"qiyuan4",
    "eastup" : __DIR__"street3",
    ])); 
        set("coor/x",20);
    set("coor/y",1930);
        set("coor/z",1);
        set("no_magic",1);
    set("no_fight",1);
//        set("throw_exit","eastup");
        set("NONPC",1);
    setup();
} 
string look_string()
{
        string  msg  =  "��ӭ����Է�����壡\n"  +
"
��������������Χ��������壬����������Ĳ��裺
һ�����Һö��֣�Ȼ��ֱ���  sit black  ��  sit white  ������
����ʹ�� start ��ʼһ���µ���֣�start [-5] [-b(numbers)] [-h(numbers)]
    ���� -5  �����������壬��ѡ��Ϊ��Χ�壻
      �� -b  ָ���������̵Ĵ�С��
         -h  ָ�����ӵ���Ŀ��
�������磺
����Χ�� start
    �þ���Χ�壺start -h9
    ʮ���ʮ��������壺start -5 -b15
����ʹ�� play ��������
    ���� play d4 �ȵȡ�
�ġ�ʹ�� refresh �ۿ����̡�
�塢ʹ�� leave �뿪���̡�
����ʹ�� pass �������䡣
�ߡ�ʹ�� undo ���塣Ŀǰֻ�ṩ������Ļ��幦�ܡ� 
";
        return  msg;
} 