inherit NPC;



void create()
{
        set_name("少年弈者", ({ "yi zhe","zhe" }) );
        set("gender", "男性" );
        set("age", 16);
        set("str", 26);
        set("cor", 40);
        set("cps", 40);
        set("per", 40);
        set("int", 40);
        set("team_member",({
                "yi zhe",
                }) );

        set("attitude", "peaceful");

        set("force_factor", 1);
        set("max_gin", 200);
        set("max_kee", 200);
        set("max_sen", 200);
        set("eff_gin", 200);
        set("eff_kee", 200);
        set("eff_sen", 200);
        set("gin", 200);
        set("kee", 200);
        set("sen", 200);
        set("max_force", 500);
        set("force", 500);

        set("long",     "一名稚气未干而聪明伶俐的少年。\n");


        set("combat_exp", 20000);
   set("combat_exp", 1000000);
        set("str", 55);
        set("max_qi",5000);
        set("max_jing",5000);
        set("max_sen",5000);
        set("neili", 10000);
        set("max_neili", 10000);
        set("atman", 10000);
        set("max_atman", 50000);
        set("mana", 50000);
        set("max_mana", 50000);
        set("force_factor", 350);




set_skill("jinshe-jian",380);
set_skill("liancheng-jian",380);
set_skill("hujia-daofa",380);
set_skill("demon-strike",380);
set_skill("nine-moon-claw",380);
set_skill("ill-quan",380);
set_skill("doomstrike",380);
set_skill("luoriquan",380);
set_skill("qinnashou",380);
set_skill("taixuan-gong",380);

        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 600);
        set_temp("apply/damage", 650);
        set_skill("jingyiforce",380);
        set_skill("demon-blade",280);
        set_skill("literate",380);
        set_skill("unarmed",380);
        set_skill("dodge",290);
        set_skill("parry",280);
	set_skill("force",380);
	set_skill("blade",280);
	set_skill("changquan",380);
        //set_skill("doomsword",380);
        //set_skill("chilian-shenzhang",380);
        //set_skill("softsword",280);
        //set_skill("nine-moon-sword",380);
        set_skill("luohua-jian",380);
        set_skill("sword",380);
        set_skill("feixian-sword",380);
        set_skill("bat-blade",380);
        set_skill("fengyu-piaoxiang",390);

        map_skill("unarmed","changquan");
        map_skill("sword","jinshe-jian");
        map_skill("force","taixuan-gong");
        map_skill("dodge","fengyu-piaoxiang");
        map_skill("parry","liancheng-jian");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: exert_function, "hun" :),
                (: exert_function, "jing" :),
                (: exert_function, "po" :),
                (: exert_function, "taixuan" :),		
                (: exert_function, "xuan" :),			
                (: perform_action, "unarmed.yuhuan" :),
                (: perform_action, "sword.kuangwu" :),
                (: perform_action, "sword.wan" :),
                (: perform_action, "sword.kun" :),	
                (: perform_action, "sword.shi" :),	
                (: perform_action, "sword.suo" :),	                	
                (: perform_action, "parry.ci" :),
                (: perform_action, "parry.erguang" :),
(: perform_action, "parry.gan" :),
(: perform_action, "parry.qian" :),
(: perform_action, "parry.qu" :),		             
(: perform_action, "parry.zhai" :),		             
(: perform_action, "parry.zhu" :),		             	             
(: perform_action, "dodge.zonghengsihai" :),		             	             
(: perform_action, "dodge.zonghengsihai" :),		             	              
        }) );

        set("positive_score",100);
        setup();

        carry_object(__DIR__"obj/yifu4")->wear();
}
int refuse_killing(object ob)
{
        message_vision("那少年对$N叱道：“恶贼安敢如此，给我拿下！”\n",ob);
        return 0;
}
