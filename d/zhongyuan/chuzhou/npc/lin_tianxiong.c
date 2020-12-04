// 镖局的镖头 /d/city/chuzhou/npc/lin_tianxiong.c
// by lala, 1997-12-23

#include <ansi.h>

inherit NPC;

void create()
{
    set_name( "林天雄", ({ "lin tianxiong", "lin", "tianxiong", }) );
    set( "title", REV BBLU WHT"扬威镖局"YEL"镖  师"NOR );
    set( "gender", "男性" );
    set( "age", 25 );
    set( "long", @LONG
林天保是林总镖头的幼子，自幼和父亲学武，但是年头还少，功夫也差些。现在
也帮爹爹赚钱养家。
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

