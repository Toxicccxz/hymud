// 林玉姣 /d/city/chuzhou/npc/daughter.c
// by lala, 1997-12-17

#include <ansi.h>

inherit NPC;

void create()
{
    set_name( "林玉姣", ({ "lin yujiao", "lin", "yujiao", }) );
    set( "gender", "女性" );
    set( "title", REV BBLU WHT"扬威镖局"MAG"镖  师"NOR );
    set( "age", 28 );
    set( "long", @LONG
林玉姣是林老镖头的女儿，现在帮爹爹的忙。因为有很多的远路客商是骑马到本
地来的，马匹没有人照管很不放心，所以特地开了这个马厩挣点钱补贴家用。
LONG
    );
    set( "peaceful", "friendly" );
    set( "talk_msg",({
    }));
    set("qi",400);
    set("max_qi",400);
    set("eff_kee",400);
    set("sen",400);
    set("max_sen",400);
    set("eff_sen",400);
    set("max_force", 600);
    set("force",     600);
    set("force_factor", 10);
    set("combat_exp", 8000);
    set("social_exp", 80000);
    set("positive_score", 2000);
    set("negative_score", 300);

 
    setup();
      
    carry_object( "/clone/misc/cloth" )->wear(); 
    carry_object( "/clone/weapon/gangdao" )->wield();
}          
