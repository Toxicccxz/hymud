// Create by lonely@NT
inherit ROOM;
#include <ansi.h>;
void create()
{
        set("short", HIW"��ʯ·"NOR);
        set("long",
"���������Źص���ʯ·,�Ƕ����ϱ��Ľ�ͨ�ؾ�֮·������Ϊ���ұ�\n"
"��֮�أ���ɽ�����ƶ��£�ֻ��һ����խ����С�����������Ƕ�����ʯ��\n"
"���󰵸�ɱ����\n"
);
        set("outdoors", "yanmen");
        set("exits", ([
                "north" :  __DIR__"luanshi6",
                "south" :  __DIR__"luanshi8",
        ]));
        set("no_fly",1);
        setup();
        replace_program(ROOM);
}