 // bandit.c
inherit NPC; 
void create()
{
        set_name("土匪", ({ "bandit" }) );
        set("gender", "男性");
        set("age", 33);
        set("long",
                "这家伙满脸横肉，一付凶神恶煞的模样，令人望而生畏。\n");
        set("combat_exp", 600);
        set("score", 60);
        set("attitude", "friendly");
 set("combat_exp", 400000+random(900000));
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action, "blade.leitingpili" :),
                (: perform_action, "blade.kuang" :),
        }) );

	set("max_qi", 3000);
	set("max_jing", 3000);
	set("neili", 3000);
	set("max_neili", 3000);

        set_skill("unarmed", 80+random(180));
        set_skill("sword", 80+random(180));
        set_skill("parry", 80+random(180));
        set_skill("dodge", 180+random(180));
        set_skill("kuang-jian", 80+random(380));
        
        map_skill("sword", "kuang-jian");
        map_skill("parry", "kuang-jian");
        set_temp("apply/attack", 20);
        set_temp("apply/defense",50);
        set_temp("apply/armor", 50);
        set_temp("apply/damage", 20);
        setup();
        carry_object("/clone/misc/cloth")->wear(); 
        carry_object(__DIR__"obj/short_sword")->wield();
        add_money("coin", 3);
}
void init()
{
        object ob; 
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) 
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
} 
void greeting(object ob)
{   
        if( !ob || environment(ob) != environment() )
                return;
        if (ob->query("class") != "bandit")
        {
                message_vision("$N看着你大声呼喊到：“兄弟们，肥羊入口！”\n", this_object() );
                this_object()->kill_ob(ob);
                ob->kill_ob(this_object());
        }
        else if(ob->query("class")=="bandit")
        {
                message_vision("$N对你阴笑道：兄弟今天又到哪里打家劫舍？\n", this_object() );
        }
        return;
}     