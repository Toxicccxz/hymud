inherit NPC;
inherit F_MASTER; 
void create()
{
    object armor;
    set_name("日后", ({ "sun queen", "sun","queen" }) );
    set("gender", "女性" );
    set("class","tieflag");
    set("age", 46);
    set("agi",35);
    set("int", 30);
    set("per", 30);
    set("cor",50);
    set("pubmaster",1);
    set("apprentice_available", 50);
    set("rank_nogen",1);
    create_family("常春岛", 1, "掌门");
    set("ranks",({"弟子","小侠女","侠女","大侠女","仙女","神女","圣女",
                      "副掌门"})); 
    set("long",
        "日后乃铁血大旗门第七代掌门人云翼之妻，因看不惯铁血大旗门人对其\n"
        "妻子的无情，开创常春岛一派，以收容世上所有伤心女子。\n"
        );
        set("fly_target",1);
    set("max_neili", 2000);
    set("neili", 2000);
    set("force_factor",50);
        set("atman",1000);
        set("max_atman",1000);
        set("mana",1500);
        set("max_mana",1500);
        
    set("reward_npc", 1);
    set("difficulty", 15);
    set("no_busy",6);
    set("attitude", "peaceful");
    
    set("combat_exp", 9000000);
    set("score", random(90000));
    
        
       set("max_neili", 95000);
        set("neili", 95000);
        set("force_factor", 30);
	set("max_qi",99999);
        set("max_jing",99999);
	set("eff_qi",99999);
	set("qi",99999);
	set("eff_jing",99999);
	set("jing",99999);

        set("attitude", "peaceful");
        set("combat_exp", 9000000);
        set("score", 90000);
        set_skill("unarmed", 200);
        set_skill("sword", 100);
        set_skill("force", 100);
        set_skill("parry", 100);
        set_skill("literate", 100);
		set_skill("dodge", 100);
		set_skill("ill-quan", 500);
		set_skill("fy-sword", 550);
		set_skill("jiayiforce", 520);
		set_skill("tie-steps", 550);
    	
		map_skill("unarmed", "ill-quan");
        map_skill("sword", "fy-sword");
        map_skill("force", "jiayiforce");
        map_skill("parry", "fy-sword");
        map_skill("dodge", "tie-steps");
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
(: perform_action, "sword.fengqiyunyong" :),
                (: perform_action, "unarmed.qiankun" :),
                (: perform_action, "dodge.chansi" :),
        }) );
    setup();
    carry_object(__DIR__"obj/longsword")->wield();
    armor=new(__DIR__"obj/corclot");
    armor->set_name("天青丝衣",({"cloth"}) );
    armor->move(this_object());
    armor->wear(); 
}

void init()
{
    object me;
    me = this_player();
    if(userp(me) && interactive(me) && me->query("class") == "tieflag" 
       &&  me->query("marry"))
    {
        command("say 大胆！竟敢触犯门规！");
        this_object()->kill_ob(me);
    }
    ::init();
}     

int accept_object(object who, object ob)
{
	int i;

	if (!(int)who->query_temp("learn_timeb"))      
		who->set_temp("learn_timeb", 0);

	if( !ob->query("money_id") )
		return 0;		


	if(who->query_skill("unarmed",1)<30)
		i=ob->value() / 50;
	else
	{
		if(who->query_skill("unarmed",1)<60)
			i=ob->value() / 100;
		else
		{
			if(who->query_skill("unarmed",1)<100)
				i=ob->value() / 100;
			else
				i=ob->value() / 100;
		}
	}
	who->add_temp("learn_timeb",i);
command("say 既然你诚心想学我的武功，我就成全成全你吧。");
	return 1;
}

int recognize_apprentice(object ob)
{
	if( ob->query_temp("learn_timeb") <= 0) return 0;
else         
ob->add_temp("learn_timeb",-1);
return 1;
}
