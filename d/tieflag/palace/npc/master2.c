 inherit NPC;
inherit F_MASTER;
#include <ansi.h>
#include <combat.h>
int testing(object me);
void check_answer(object me);
void check_accept(object me);
void create()
{
    set_name("蓝天锤", ({ "master lan", "lan","master" }) );
    set("gender", "男性" );
    set("nickname",HIB "蓝大先生" NOR);
    set("reward_npc", 1);
    set("difficulty", 2);
    set("age", 45);
    set("int", 30);
    set("str",60);
    set("per", 30);
    set("class","yinshi");
    set("apprentice_available", 50);
    create_family("天锤山庄", 1, "庄主");
    set("rank_nogen",1);
    set("ranks",({"弟子","小侠","少侠","大侠","奇侠","狂侠","侠圣","隐侠"})); 
    
    set("long",
        "蓝天锤的一柄大锤用的出神入化．．．
每年都和帝王谷主绝顶一战，致今胜负不分． 
蓝天锤的脾气爆如烈火，经常无缘无故的将弟子打成死伤或逐出墙门．\n"
        );
    set("force_factor", 60);
    set("max_atman", 300);
    set("atman", 300);
    set("max_neili", 1000);
    set("neili", 1000);
    set("max_mana", 300);
    set("mana", 300);
    set("skill_public",1);
    set("chat_chance", 1);
    set("chat_msg", ({
        "蓝天锤笑骂道：这个箫老儿，又和他不分胜负．\n",
            }) );
    set("combat_exp", 2000000);
         set("combat_exp", 99999999);
        set("score", 90000);
        set_skill("unarmed", 100);
        set_skill("hammer", 350);
        set_skill("force", 200);
        set_skill("parry", 100);
        set_skill("literate", 100);
	set_skill("dodge", 100);

	set_skill("pangu-hammer", 550);
	set_skill("pofeng-strike", 520);
	set_skill("putiforce", 550);
	set_skill("nodust-steps", 500);

	map_skill("unarmed", "pofeng-strike");
        map_skill("hammer", "pangu-hammer");
        map_skill("force", "putiforce");
        map_skill("parry", "pangu-hammer");
        map_skill("dodge", "nodust-steps");
	//set_skill("magic",100);
//	set_skill("qiankunwuxing",100);
//	map_skill("magic","qiankunwuxing");
        set("str",35);
        set("int",30);
set("pubmaster",1);
        set("max_neili", 95000);
        set("neili", 95000);
        set("force_factor", 30);
	set("max_qi",99999);
        set("max_jing",99999);
	set("eff_qi",99999);
	set("qi",99999);
	set("eff_jing",99999);
	set("jing",99999);
      set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.luanpofeng" :),
                (: perform_action, "hammer.kaitianpidi" :),
        }) );
	set_temp("apply/attack", 200);set_temp("apply/defense", 200);set_temp("apply/armor", 500);set_temp("apply/damage", 600);setup();

        set_temp("apply/defense", 200);
        set_temp("apply/armor", 2500);
        set_temp("apply/damage", 2200);
        set_temp("apply/attack", 200);

    setup();
    carry_object(__DIR__"obj/bluecloth")->wear();
    carry_object(__DIR__"obj/jumbohammer")->wield();
} 
void init()
{
        add_action("do_challenge","challenge");
        add_action("do_challenge","tiaozhan");
        add_action("do_answer","answer");
        ::init();
} 

void check_answer(object me)
{
        if (me)
        {
                me->delete_temp("answering_lan");
                if (present(me,environment()))
                {
                        message_vision("$N对$n不耐烦道：“大丈夫，有一说一，有二说二，婆婆妈妈做什么。”\n",this_object(),me);
                        message_vision("$N扭过头不再理$n。\n",this_object(),me);
                } 
        }
} 
int do_answer(string arg)
{
        object me;
   me=this_player();
        
        if(!me->query_temp("answering_lan"))
                return 0;
        if (arg !="yes" && arg !="no")
        {
                return notify_fail("你只可答yes/no");
        } 
        remove_call_out("check_answer");
        me->delete_temp("answering_lan");
        if (arg == "yes")
        {
                message_vision(HIW"$N笑得更得意了：“那你就拜我为师吧！再见到箫老儿，我得好好羞羞他，
连徒弟都拢不住了！” \n"NOR,this_object());
                  command("recruit " + me->query("id") ); 
                  me->add("betrayer",-1);

//                me->set_temp("despite_xiao",1);
        }
        if (arg == "no")
        {
                message_vision( HIW"$N双目炯炯盯着$n：“箫老儿的徒弟也有这份骨气？嗯。。。 
你代我约战(challenge)你师傅，我就教你两手！”(accept yes/no) \n"NOR,this_object(),me );
                add_action("do_accept","accept");
                me->set_temp("accepting_lan",1);
                call_out("check_accept",40,me);
        }
        return 1;
} 
void check_accept(object me)
{
        if (me)
        {
                delete_temp("accepting_lan");
                if (present(me,environment()))
                {
                        message_vision("$N对$n挥挥手，道：“不愿意就算了。”\n",this_object(),me);
                }
        }
} 
int do_accept(string arg)
{
        object me;
   me = this_player();
        if(!me->query_temp("accepting_lan"))
                return 0;
        if (arg !="yes" && arg !="no")
        {
                return notify_fail("你只可接受yes/no");
        }
        remove_call_out("check_accept");
        me->delete_temp("accepting_lan");
        if (arg == "yes")
        {
                message_vision(HIW"$N点点头，说到：“好，我就在这里等他” \n"NOR,this_object());
                me->set("marks/challenge_xiao_forlan",1);
        }
        if (arg == "no")
        {
                message_vision(HIW"$N正色道：“以为师之尊，如何能与你这等山野村民交战。这事我万万不能答应。”\n"NOR,me);
        }
        return 1;
}  

int do_challenge(string arg)
{
        object me;
        me = this_player(); 
        if (arg != "master" && arg != "master lan" && arg != "蓝天锤" && arg != "lan")
        {
                return 0;
        }
        if (!me->query("marks/challenge_lan") || (string) me->query("class") != "yinshi")
        {
                message_vision(HIW"$N不屑一顾对$n说道：“你是什么东西，要老夫出手？” \n"NOR,this_object(),me);
                return 1;
        }
        message_vision(HIG"$n对$N朗声道："+RANK_D->query_self(me) + me->name() + "愿代师出战。\n"NOR,this_object(),me);
   if((int)me->query("marks/failed_lan") + 10800 > time())
    {
        say(HIW"\蓝天锤说道：你不久前才输给我！过两天再比吧！\n"NOR);
        return 1;
    }
        if (!me->query("marks/fight_lan"))
        {
                message_vision(HIW"$N惊异的对$n说道：“怎么是你。。。也好，接招吧！” \n"NOR,this_object(),me);
        }else
        {
                message_vision(HIW"$N对$n大喝一声：“好的，招到！” \n"NOR,this_object(),me);
        }
        testing(me);    
        return 1;       
}  
int testing(object me)
{
        object weapon,skl;
    if (this_object()->is_fighting() || this_object()->is_busy())
        command("say 我现在正忙，等会吧。。。"); 
    me->set("marks/fight_lan",1);
        delete_temp("last_damage_from");
    heal_up();
        weapon =me->query_temp("weapon");   
        COMBAT_D->do_attack(me,this_object(),me->query_temp("weapon"));
        say(HIR"\n蓝大先生说道：第一招．．．．\n"NOR);
    if(query_temp("last_damage_from") == me)
    {
                if(!weapon ||weapon->query("skill_type")!="whip"||me->query_skill_mapped("whip")!="thunderwhip")
                {
                        say("\n蓝大先生喃喃道：“原来这世上还有这么厉害的武功。。。” \n");
                        say("\n蓝大先生心灰意冷的叹了口气。 \n");
                }else
                {
                        message_vision(HIG"蓝大先生对$N说道：“天雷破果然名不需传，不过我的武功却恰恰能克制它，想学的话，我就教你。”\n"NOR,me);
                me->set("marks/master_lan",1);
                        
                }
                return 1;
    }
   
   COMBAT_D->do_attack(me,this_object(),me->query_temp("weapon"));
        say(HIR"\n蓝大先生说道：第二招．．．．\n"NOR);
    if(query_temp("last_damage_from") == me)
    {
                if(!weapon ||weapon->query("skill_type")!="whip"||me->query_skill_mapped("whip")!="thunderwhip")
                {
                        say("\n蓝大先生喃喃道：“原来这世上还有这么厉害的武功。。。” \n");
                        say("\n蓝大先生心灰意冷的叹了口气。 \n");
                }else
                {
                        message_vision(HIG"蓝大先生对$N说道：“天雷破果然名不需传，不过我的武功却恰恰能克制它，想学的话，我就教你。”\n"NOR,me);
                me->set("marks/master_lan",1);
                        
                }
                return 1;
    }  
COMBAT_D->do_attack(me,this_object(),me->query_temp("weapon"));
        say(HIR"\n蓝大先生说道：第三招．．．．\n"NOR);
        if(query_temp("last_damage_from") == me)
    {
                if(!weapon ||weapon->query("skill_type")!="whip"||me->query_skill_mapped("whip")!="thunderwhip")
                {
                        say("\n蓝大先生喃喃道：“原来这世上还有这么厉害的武功。。。” \n");
                        say("\n蓝大先生心灰意冷的叹了口气。 \n");
                }else
                {
                        message_vision(HIG"蓝大先生对$N说道：“天雷破果然名不需传，不过我的武功却恰恰能克制它，想学的话，我就教你。”\n"NOR,me);
                me->set("marks/master_lan",1);
                        
                }
                return 1;
    }
        me->set("marks/failed_lan",time());
        if(!weapon ||weapon->query("skill_type")!="whip"||me->query_skill_mapped("whip")!="thunderwhip")
        {
                say("\n蓝大先生摇了摇头，说道：“普天只下只有天雷破可以和我的锤法抗衡。” \n");                 
        }else
        {
                command("shake");
           command("say 你的武功太差，不要来自讨苦吃了。等练好了再来吧。");
        }
        return 1;
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