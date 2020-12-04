//square.c
inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "��Ժ");
        set("long", @LONG
���߽��������ܶ�㳡��ȴ���������������У���ɢ��Ⱥ
���ڴˣ�������Ҫ�·����ˡ��������ڴҴ�ææ���㳡������
���ڷ��ã����׾��ǽ�����֮��ɫ�����á������߾��ǹ�����
�����ܶ��ˡ�
LONG );
        set("exits", ([
                "west"    : __DIR__"fangtang",
                "northup" : __DIR__"qiandian",
                "east"    : __DIR__"xingtang",
                "south"   : __DIR__"tianweitang",
                "north"   : __DIR__"xiuximj",
        ]));
        set("roomif","$botten#��������|��������|�������|�Ͻ���Ʒ|��ȡ����|ȡ������:job|quest|ask shi about teamjob|give <��Ʒ> to shi|ask shi about gongxian|give 20 silver to shi$#");
        set("objects",([
             __DIR__"npc/shuobude":1,
             __DIR__"npc/zhangzhong":1,
             __DIR__"npc/pengyingyu":1,
             "/d/biwu/champion_mj":1,
             __DIR__"npc/zhoudian":1,
           "quest/menpai/mingjiao/shi" : 1,
        ]));
        set("valid_startroom","1");
        set("outdoors", "mingjiao");
        setup();
        "/clone/board/mingjiao_b"->foo();
}

int valid_leave(object me, string dir)
{
        mapping mypar;
        me = this_player();
        mypar=(mapping)me->query("party");
//if (!mypar)          return notify_fail("������ɢ����ס��˵���˴��������صأ���ֹ����\n");
        if ((!mypar || mypar["party_name"]!=HIG "����" NOR) &&
            (dir!="south") &&
            ((objectp(present("peng yinyu", environment(me)))) ||
             (objectp(present("zhang zhong", environment(me)))) ||
             (objectp(present("shuo bude", environment(me)))) ||
             (objectp(present("zhou dian", environment(me))))))
         return notify_fail("������ɢ����ס��˵���˴��������صأ���ֹ����\n");
        return ::valid_leave(me, dir);
}