 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_MASTER; 
void smart_fight();
void smart_busy();
void smart_attack(); 
int leave();
#include <ansi.h>
void create()
{
    set_name("荆无命", ({ "master jin", "master", "master jinwu" }) );
    set("nickname", RED"左手剑"NOR);
    set("gender", "男性" );
    set("age", 44);
    set("class","assassin");
    set("reward_npc", 1);
    set("difficulty", 10); 
    set("cor", 40);
    set("cps", 30);
    set("int", 30);
    set("str", 15);
    set("pubmaster",1);
    set("per", 3);
    set("agi",25);
        set("ill_boss",5);
    set("attitude","friendly");
    set("max_neili", 52500);
    set("neili", 52500);
    set("force_factor", 20);  
    set("long",
        "
这人的身子站得更直，更挺，就像是一杆枪。他整个人似已麻木，既不知痛痒，
也不知哀乐。
\n"
        );
    create_family("金钱帮", 2, "护法");
    set("rank_nogen",1); 
    set("combat_exp", 2000000);
    set("score", 2000);
    
    set("inquiry",  ([
                "leave": (: leave :),
                ]));
      set("combat_exp", 8000000);
        set("score", 200000);
        set("agi",25);
        set("int",30);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.duxin" :),
		(: perform_action, "sword.sharenruma" :),
		(: perform_action, "dodge.canglongyixian" :),
        }) );
          set("max_neili", 55000);
        set("neili", 55000);
        set("force_factor", 30);
	set("max_qi",99999);
        set("max_jing",99999);
	set("eff_qi",99999);
	set("qi",99999);
	set("eff_jing",99999);
	set("jing",99999);
        set_skill("dodge", 50);
        set_skill("parry", 60);
        set_skill("dodge", 60);
        set_skill("force", 60);
        set_skill("literate", 30);
	set_skill("jingxing",160);
	set_skill("sword", 90);
	set_skill("jinhong-steps",560);
	set_skill("lefthand-sword",500);
	set_skill("sharen-sword",550);
        map_skill("dodge", "jinhong-steps");
	map_skill("sword", "sharen-sword");
	map_skill("force", "jingxing");

    
    set("ranks",({"帮众","副香主","香主","副堂主","堂主",
                   "副坛主","坛主","副舵主","舵主",
                      "护法","大护法","副帮主"}));
    set("rank_levels",({ 32000,64000,128000,256000,512000,
                             1024000,1536000,2304000,3456000,
                             5187000,26244000 })); 
    setup();
    carry_object(__DIR__"obj/whitecloth")->wear();
    carry_object(__DIR__"obj/leftsword")->wield();
}  

 
void init()
{       
        ::init();
        add_action("do_killing", "kill");
    
} 
int do_killing(string arg)
{
    object player, victim;
    string id,id_class;
    player = this_player();
    if(!arg || arg == "") return 0;
    victim = present(arg, environment(player));
    if(!objectp(victim))
                return notify_fail("这里没有这个人。\n");
    if(living(victim))
    {
        id_class=victim->query("class");
        id=victim->query("id");
        if(id_class == "assassin"&& userp(victim)&& player!=victim)
        {
            message_vision(HIW
"$N喝道：在我面前杀我的弟子，不想活了！\n"NOR, this_object());
            this_object()->kill_ob(player);
            player->kill_ob(this_object());
            if (!player->is_busy()) player->start_busy(2);
            return 0;
        } 
    }
    return 0;
}  
int leave() {
        if (this_player()->query("class")!="assassin") return 0;
        message_vision(CYN"$N向你瞧了瞧说：“人各有志，我不勉强。“\n"NOR, this_object());
   message_vision(CYN"$N说：只是我的金虹步伐的妙处你是体会不到了。\n"NOR,this_object());
        return 1;
}  
smart_fight()
{
        int i;
        object *enemy;
        enemy = this_object()->query_enemy();
        i = sizeof(enemy);
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        if (enemy[i]->query_skill("iron-cloth")>200) {
                                if (this_object()->query_temp("weapon")){
                                command( "say 好厉害的硬功！会一会我的烈焰寒冰掌！");
                                command("unwield sword");
                                }
                        } else  command("wield sword");
                        
                        if (!enemy[i]->query_temp("till_death/lockup"))
                        {
                                this_object()->smart_busy();
                        } else this_object()->smart_attack();
                        
                }
        }
} 
smart_busy() {
        this_object()->perform_action("dodge.canglongzhaxian");
}
smart_attack() {
        this_object()->perform_action("sword.duxin");      
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
