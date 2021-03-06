 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
    set_name("白三空", ({ "bai sankong" }) );
    set("nickname", HIY"清平剑客"NOR);
    set("gender", "男性" );
    set("class","shenshui");
    set("reward_npc", 1);
    set("difficulty", 5);
    set("age", 54);
    set("cor", 30);
    set("cps", 30);
    set("int", 30);
    set("per", 20);
    set("str",40);
    set("skill_public",1);
    set("attitude","peaceful");
    
    set("no_busy",10);
    
    set("atman",1000);
    set("max_atman",55000);
    set("max_neili", 55500);
    set("force", 500);
    set("force_factor", 100);
    set("fly_target",1);
    set("long", "清平山庄庄主\n");
    create_family("清平山庄", 1, "庄主");
    set("rank_nogen",1);
    set("ranks",({"剑童","剑手","剑士","剑老","剑仙","剑神"}));
    set("rank_levels",({64000,256000,1536000,3456000,26244000}));
    
    set("resistance/kee",50);
    set("resistance/gin",50);
    set("resistance/sen",50);
        
    set("combat_exp", 7800000);
     set_skill("dodge", 100);
        set_skill("parry", 100);
        set_skill("dodge", 120);
        set_skill("force", 100);
        set_skill("unarmed", 80);
        set_skill("bai-quan",580);
        set_skill("literate", 100);
        set_skill("sword",330);
        set_skill("qingpingsword",550);
        set_skill("qingpingforce",520);
        set_skill("chaos-steps",520);
        map_skill("force", "qingpingforce");
        map_skill("parry","qingpingsword");
        map_skill("sword","qingpingsword");
        map_skill("dodge","chaos-steps");
        map_skill("dodge","chaos-steps"); 
        map_skill("unarmed","bai-quan"); 
set("pubmaster",1);
        set("max_neili", 55000);
        set("neili", 55000);
        set("force_factor", 30);
	set("max_qi",99999);
        set("max_jing",99999);
	set("eff_qi",99999);
	set("qi",99999);
	set("eff_jing",99999);
	set("jing",99999);
	set("env/wimpy", 60);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.choushen" :),
                (: perform_action, "sword.youzijue" :),
        }) );

    setup();
    carry_object("/clone/misc/cloth")->wear();
    carry_object("/clone/weapon/gangjian")->wield();
    carry_object(__DIR__"obj/shuzhi")->wield();  
    set("chat_chance", 2);
    set("chat_msg", ({
        "白三空摇头叹道：＂清平山庄横祸不断，人丁衰弱．．．＂\n",       
        "白三空打量了你一眼，“若是神水弟子，我到可以指点你几招。”\n"
            }) ); 
} 

void init()
{
    object me; 
    ::init();
    if( interactive(me = this_player()) && !is_fighting())
    if (me->query("combat_exp")>3200000 && me->query("class")=="shenshui" 
        && !me->query("marks/胜白衣人") && !me->query_temp("marks/ask_bai")) {
        remove_call_out("greeting");
        add_action("do_accept", "accept");
        me->set_temp("bai_in_ask",1);
        call_out("greeting", 1, me);
    }
        add_action("do_killing", "kill");
} 
int greeting(object me)
{
    message_vision(HIY"\n$N深深地看了$n一眼说道：“你跟我学艺业已有成，可愿代我完成一个心愿？（accept yes/no）\n" NOR, this_object(), me);
    return 1;
}  
int do_accept(string arg)
{
        string name;
        if (!this_player()->query_temp("bai_in_ask"))
                return notify_fail("什么？\n");
        if( arg != "yes" &&  arg != "no") 
                return notify_fail("你要接受什么？\n");
        if( arg == "yes") {
                this_player()->set_temp("marks/bai_ask",1);
                message_vision(CYN "$N说道：十年前扶桑白衣人挑战武林，四日内连杀青鹤柳松、双环赵士鸿、
八仙剑李青风、八手镖金大非，为师亦不是对手，幸有紫衣侯仗义出手。。。。\n"NOR,this_object());
                message_vision(CYN"而今紫衣侯已逝，白衣人又卷土重来，连伤我中原武人数名。\n"NOR,this_object());
                message_vision(CYN"$N说：你已尽得神水武功精髓，又融清平武功之心得，可速赴东海与其一战。\n"NOR,this_object());
                message_vision(CYN"中原武林兴衰，在此一役，可胜不可败！\n"NOR,this_object());
        }
        else 
                command("sigh");
        this_player()->delete_temp("bai_in_ask");
        return 1;
} 
int accept_object(object who, object ob)
{
		int i;

	if (!(int)who->query_temp("learn_timeb"))      
		who->set_temp("learn_timeb", 0);

	if( ob->query("money_id") )
{	if(who->query_skill("unarmed",1)<30)
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
	
        if(!who->query("marks/胜白衣人")) return 0; 
        if( ob->query("id")!="katana" ) return 0;
                message_vision(CYN"$N大笑道：好，好，太好了。\n"NOR,this_object());
                message_vision(CYN"$N说:老夫这几日悟出了将清平与神水内功融汇之法，就传授给你吧。\n"NOR,this_object());
                tell_object(who,HIW"你可以用九阴心法疗伤和倒转乾坤了！！！\n"NOR);
                who->delete_temp("marks/bai_ask");
                who->set("marks/九阴疗伤",1);
                message_vision(CYN"$N又道：其实神水宫里深藏不露之人甚多，多走走，会有收获的。\n"NOR,this_object());
        return 1;
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
        if(id_class == "shenshui"&& userp(victim)&&player!=victim)
        {
            message_vision(HIW
"$N对$n喝道：老夫既是神水宫的客人，就容不得你在这里撒野！\n"NOR, this_object(),player);
            this_object()->kill_ob(player);
            player->kill_ob(this_object());
            if (!player->is_busy()) player->start_busy(2);
            return 0;
        } 
    }
    return 0;
}
int recognize_apprentice(object ob)
{
	if( ob->query_temp("learn_timeb") <= 0) return 0;
else         
ob->add_temp("learn_timeb",-1);
return 1;
}
