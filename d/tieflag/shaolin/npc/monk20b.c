 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
#include <ansi.h>
void smart_fight();
void smart_attack(); 
void create()
{
        set_name("壮年和尚", ({ "shaolin monk", "monk"}) );
        create_family("东林寺", 18, "弟子");
        set("gender", "男性" );
        set("class", "shaolin");
        set("age",random(20)+ 32);
        set("nickname",HIG"专攻一项"NOR);
        set("long", "这是东林寺专门研究各派武功，寻找破解各派绝招的和尚．\n");
        set("vendetta_mark","shaolin");
        set("cps",80);
        set("combat_exp", 4500000);
        set("attitude", "friendly");
        
        set("neili",1000);
        set("max_neili",1000);
        set("force_factor",50);
        set("max_mana",1000);
        set("mana",1000);
                  
        set_skill("unarmed",200);
        set_skill("jingang-quan",200);
        set_skill("staff", 200);
        set_skill("pudu-zhang",200);
        set_skill("move",200);
        set_skill("dodge",200);
        set_skill("force",200);
        set_skill("parry",200);
        set_skill("spells",100);
        set_skill("kwan-yin-spells",100); 
        map_skill("spells","kwan-yin-spells");
                
        set("resistance/kee",40);
   set("resistance/sen",50);
        set("resistance/gin",20+random(80));
        
        map_skill("staff", "pudu-zhang");
        map_skill("parry", "pudu-zhang");
        map_skill("dodge","shaolin-shenfa");
        map_skill("unarmed","jingang-quan");
        map_skill("move","shaolin-shenfa");
        
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                name()+"笑道：在东林寺撒野？\n",
                (: smart_fight() :),
        }) );
        
        set("chat_chance", 1);
        set("chat_msg", ({
                name()+"叹道：难哪！这［天地人魔连环八式］真是毫无破绽！\n",
                name()+"笑道：也不知这李玉函，柳无眉夫妇如何在江湖
立足！这黄山派武功一招中有不下十个破绽！\n",
                name()+"道：这七仙女阵也不过如此！\n",
                name()+"叫道：终于被我找出破绽了！\n"
        }) );
        setup();
        carry_object(__DIR__"obj/monk20b_cloth")->wear();
        carry_object(__DIR__"obj/stick")->wield();
} 
smart_fight()
{
        int j,i;
        object *enemy, who;
        who = this_object();
        enemy = this_object()->query_enemy();
        
/*      for(j=0;j<sizeof(enemy);j++)
        {
                if (enemy[j]->is_zombie())
                {       who->cast_spell("zombie-bolt");
                        return;
                }               
   }*/
        who->smart_attack();
        return;
} 
smart_attack() {
        if (this_object()->query_temp("weapon"))
                this_object()->perform_action("staff.hequhecong");      
                else this_object()->perform_action("unarmed.qianshouqianbian");         
        return;
        }  
