// �ھֵ���ͷ /d/city/chuzhou/npc/lin_tianhao.c
// by lala, 1997-12-23

#include <ansi.h>

inherit NPC;

void create()
{
    set_name( "�����", ({ "lin tianhao", "lin", "tianhao", }) );
    set( "title", REV BBLU WHT"�����ھ�"YEL"��  ʦ"NOR );
    set( "gender", "����" );
    set( "age", 35 );
    set( "long", @LONG
���챣��������ͷ�Ĵ��ӣ����׺͸���ѧ�䣬Ҳ��һ���ĺù�������Ҳ�����
׬Ǯ���ҡ�
LONG
    );
    set( "attitude", "friendly" );
    set( "talk_msg",({
    }));
    set("qi",400);
    set("max_qi",400);
    set("eff_kee",400);
    set("sen",400);
    set("max_sen",400);
    set("eff_sen",400);
    set("max_force", 1600);
    set("force",     1600);
    set("force_factor", 20);
    set("combat_exp", 10000);
    set("social_exp", 10000);
    set("positive_score", 3000);
    set("negative_score",  800);


 
    setup();
      
    carry_object( "/clone/misc/cloth")->wear();
    carry_object( "/clone/weapon/gangdao")->wield();        
}          
