#include <ansi.h>
inherit NPC; 
void create()
{
        set_name("月神", ({ "moon spirit","spirit" }) );
        set("nickname",HIC"月光如水"NOR);
        set("title","月神山庄   大小姐");
        set("gender", "女性");
        set("quality","good");
        set("reward_npc", 1);
       set("difficulty", 2);
        set("age",19);
        set("combat_exp", 25300000);
         set("long",
"月色水波间，仿佛有层淡淡的烟雾升起，烟雾间仿佛有一条淡淡的人影。云开，
月现，月光谈淡的照下来，恰巧照在她的脸上。苍白的股，苍白如月。\n"
        );
        set("max_neili",50000);
        set("neili",50000);
        set("force_factor",900);
                set("max_jing",33000);
                set("max_jing",33000);
                set("con",40);
                set("int",27);
                set("str",25);
                set("cor",80);
                set("agi",40);
                set("per",100);
        set_skill("move",150);
        set_skill("parry", 300);
        set_skill("blade",300);
        set_skill("dodge",150);
          
        setup();
        set_temp("shield_force/type","force");
        set_temp("shield_force/ratio",10000);
        set_temp("shield_force/msg",
                CYN"$n身上的光华消融了$N的攻势。\n"NOR);
        set("revival",1);
} 
