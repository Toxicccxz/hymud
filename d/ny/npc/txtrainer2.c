
// trainer.c

#include <ansi.h>
inherit NPC;

void create()
{	
	//string *fname=({"饭","汤","粥"});
        set_name("袁崇焕", ({ "yuan chonghuan", "yuan" }) );
        set("title", "总督");
        set("gender", "男性" );
        set("nickname", HIC "关宁总督" NOR);
        set("shen_type",-1);
	set("age", 30);
        set("str", 26);
        set("int", 14);
        set("long", 
      "袁崇焕是个孔武有力的大块头，他正在训练他的手下参将。\n" 
	);
               set("bellicosity",random(1000));
        set("combat_exp", 5110000);
        set("attitude", "heroism");

        set("force", 820);
        set("max_force", 820);
        set("force_factor", 1);


  set("max_neili",18500);
    set("neili",18500);
    set("qi",18500);
    set("eff_qi",18500);
    set("max_qi",18500);

    set("jing",18500);
    set("eff_jing",18500);
    set("max_jing",18500);
        set_skill("force", 180+random(180));

        set_skill("unarmed", 380+random(180));
        set_skill("blade", 380+random(180));
        set_skill("parry", 380+random(180));
        set_skill("dodge", 380+random(180));
        set_skill("kuang-blade", 280+random(180));
        map_skill("blade", "kuang-blade");
        map_skill("parry", "kuang-blade");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "blade.leitingpili" :),
                (: perform_action, "blade.kuang" :),

        }) );
        set_skill("unarmed", 350);
	set_skill("sword", 380);
        set_skill("dodge", 380);
        setup();
	carry_object("/d/city/npc/obj/gangdao")->wield();
	carry_object("/d/city/npc/obj/tiejia")->wear();
}

