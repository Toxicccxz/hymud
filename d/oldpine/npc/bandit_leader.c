 // bandit_leader.c
inherit NPC; 
void create()
{
        set_name("土匪首领", ({ "bandit leader", "chief", "leader" }) );
        set("gender", "男性");
        set("age", 47);
        set("long",     "这家伙眼神凶恶，一双精光四射的眼珠正盯著你的脖子。\n");
        set("combat_exp", 50000);
        set("score", 7700);
        set("bellicosity", 3000);
        set("attitude", "friendly"); 
        set("max_neili", 700);
        set("force", 1300);
        set("force_factor", 4); 
        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                "\n土匪首领阴恻恻地说道：这种三脚猫的功夫也敢上老云寨来撒野？！\n",
                "\n土匪首领说道：去你的，老子今天要剁下你的头来练练毒爪！\n",
                "\n土匪首领虎吼一声，欺身上前。\n"
        }) );
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
        set_skill("blade", 80+random(180));
        set_skill("parry", 80+random(180));
        set_skill("dodge", 180+random(180));
        set_skill("kuang-blade", 280+random(380));
        
        map_skill("blade", "kuang-blade");
        map_skill("parry", "kuang-blade");
        set_temp("apply/attack", 20);
        set_temp("apply/defense",50);
        set_temp("apply/armor", 50);
        set_temp("apply/damage", 20);
        setup();
        carry_object(__DIR__"obj/blade")->wield();
        carry_object(__DIR__"obj/leather")->wear();
        add_money("coin", 300);
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