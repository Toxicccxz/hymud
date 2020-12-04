 inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void smart_fight(); 
void create()
{
    set_name("柳无眉", ({ "master liu", "master","liu" }) );
    set("gender", "女性" );
    set("nickname", HIG"拥翠山庄少夫人"NOR);
    set("apprentice_available", 50);
    create_family("黄山派", 3, "掌门");
    set("long",
        "柳无眉黄山派掌门夫人\n"
        );
    set("age", 26);
    set("int", 30);
    set("per", 30);
    set("cor",  50);
    set("reward_npc", 1);
    set("difficulty", 30);  
       set("ill_boss",5);
    set("chat_chance", 1);
    set("chat_msg", ({
        name()+"嘀咕道：噫．．我的温玉怎么不见了？\n",
            }) );
   set("max_neili", 99000);
        set("neili", 99000);

        set("combat_exp", 99999999);
        set_skill("unarmed", 100);
        set_skill("sword", 150);
        set_skill("force", 100);
        set_skill("literate", 100);
	set_skill("dodge", 100);
        set("max_neili", 95000);
        set("neili", 95000);
        set("force_factor", 30);
	set("max_qi",99999);
        set("max_jing",99999);
	set("eff_qi",99999);
	set("qi",99999);
	set("eff_jing",99999);
	set("jing",99999);
        set_skill("yunwu-strike", 500);
        set_skill("siqi-sword", 520);
        set_skill("xianjing", 550);
        set_skill("liuquan-steps", 500);

        map_skill("unarmed", "yunwu-strike");
        map_skill("sword", "siqi-sword");
        map_skill("force", "xianjing");
        map_skill("dodge", "liuquan-steps");
        set("chat_chance", 5);
        set("chat_msg", ({
                (: random_move :),
        }) );
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.liushuichanchan" :),
                (: perform_action, "unarmed.miwu" :),
                (: perform_action, "sword.siqi" :),
        }) );
        set("pubmaster",1);
    
    set("ranks",({"弟子","小侠","少侠","大侠","奇侠","长老","元老","副掌门"}));
    setup();
    carry_object(__DIR__"obj/yellowcloth")->wear();
    carry_object(__DIR__"obj/yusword")->wield();
}
void reset()
{
        delete_temp("learned");
        set("apprentice_available", 20);
} 
void init()
{ 
        object ob;
        ::init();
        if( interactive(ob = this_player()) ) {
                remove_call_out("punish_betray");
                call_out("punish_betray",2 , ob);
        }
}
/*void punish_betray(object ob)
{
        if( ( ob->query("once_huangshan")) && ( (ob->query("class"))!= "huangshan"))
          {      
                tell_object(ob, YEL"\n柳无眉对你冷笑道：“你既然判出本门，就不配再有本门的武功！”\n"NOR);              
                message("vision", "柳无眉对"+ ob->name() +"冷笑道：“"+ ob->name() + "！ 你既然判出本门，就不配再有本门的武功！\n", environment(ob), ob);
           tell_object(ob, HIW"柳无眉手一扬，一支牛毛般细小的飞针射入你手臂！\n"NOR);              
                message("vision", HIW"柳无眉对着"+ ob->name() +"手一扬，射出一支牛毛般细小的飞针！\n"NOR, environment(ob), ob);
                
                if (ob->query_skill("liuquan-steps",1)) ob->delete_skill("liuquan-steps",0);
                if (ob->query_skill("qiusheng-blade",1)) ob->delete_skill("qiusheng-blade",0);
                if (ob->query_skill("yunwu-strike",1)) ob->delete_skill("yunwu-strike",0);
                if (ob->query_skill("siqi-sword",1)) ob->delete_skill("siqi-sword",0);
                tell_object(ob, HIR"你只觉血脉一阵逆流，武功全失！！\n"NOR);
                ob->delete("once_huangshan");
          }
} */ 

int recruit_apprentice(object ob)
{
    if( ::recruit_apprentice(ob) )
        ob->set("class", "huangshan");
    add("apprentice_availavble", -1);
}
int accept_fight(object me)
{
                return 0;
} 
int accept_object(object who, object ob)
{
	int i;

	if (!(int)who->query_temp("learn_timeb"))      
		who->set_temp("learn_timeb", 0);

	if( ob->query("money_id") )
{
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
	
        if(ob->query("id") == "old jade")
        {
        command("smile");
        command("thank "+who->query("id"));
        if((int)ob->query("max_cure") < 5)
        call_out("give_pena",3,who);
        else
        call_out("give_reward",3,who);
        return 1;
        } 
}
int give_reward(object who)
{
if(environment() != environment(who)) return 1;
if(!who->query("m_success/找玉石"))
        {
                who->set("m_success/找玉石",1);
                who->add("score",700); 
        }
return 1;
} 
int give_pena(object who)
{
if(environment() != environment(who)) return 1;
command("say 你竟然敢偷用本夫人的玉石？！！\n");
kill_ob(who);
who->kill_ob(this_object());
return 1;
}  
smart_fight()
{
        int i;
        object *enemy, who,count,j;
        who = this_object();
        enemy = this_object()->query_enemy();
        i = sizeof(enemy);
        if (who->query("qi")<8000) {
                count=0;
                for (j=0;j<sizeof(enemy);j++) {
                        if (enemy[j]->is_zombie()) count++;
                }
                if (count>=3)
                        command("perform zombie-wp1");
        }
        if (!random(3)) who->perform_action("sword.siqi");
        return;
}       


int recognize_apprentice(object ob)
{
	if( ob->query_temp("learn_timeb") <= 0) return 0;
else         
ob->add_temp("learn_timeb",-1);
return 1;
}