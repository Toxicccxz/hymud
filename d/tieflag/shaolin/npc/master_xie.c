 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
    set_name("谢晓峰", ({ "master xie", "master", "xiexiaofeng" }) );
    set("nickname", HIG"剑圣"NOR);
    set("gender", "男性" );
        set("class","swordsman");
    set("reward_npc", 1);
    set("difficulty", 30); 
    set("age", 34);
    set("cor", 30);
    set("cps", 80);
    set("int", 30);
    set("per", 30);
    set("attitude","friendly");
    
    set("resistance/kee",90);
    set("resistance/sen",90);
    set("resistance/gin",90);
    
    set("max_neili", 5000);
    set("neili", 5000);
    set("force_factor", 200);
    set("max_mana",4000);
    set("mana",4000);
    
    set("long",
        "谢晓峰五岁学剑,十六岁剑成,十九岁败华少坤,一手清风细雨温柔剑法当世无双
更兼风度潇洒绝伦,得七星塘慕容秋荻芳心,惹来一生情债．．\n");
    set("rank_nogen",1);
    create_family("神剑山庄", 1, "庄主");
    set("ranks",({"剑奴","剑手","剑士","剑侠","剑王","剑帝","剑圣",BLU"剑魂"NOR,
                      YEL"剑罡"NOR,HIC"剑煞"NOR,HIW"剑仙"NOR,HIR"剑神"NOR}));
    set("rank_levels",({ 32000,64000,128000,256000,512000,
                             1024000,1536000,2304000,3456000,
                             5187000,26244000 }));     
    set("combat_exp", 10000000);
    set("score", random(200000)); 
   set("max_qi", 152000);
	set("max_jing", 151000);
	set("neili", 153000);
	set("max_neili", 153000);
	set("jiali", 100);
	set("combat_exp", 8800000);
	set("score", 500000);
set("pubmaster",1);
	  set("combat_exp", 80000000);
        set("score", 200000);
        set_skill("parry", 100);
        set_skill("dodge", 120);
        set_skill("force", 100);
        set_skill("literate", 100);
	set_skill("sword",530);
	set_skill("softsword",550);
        set_skill("cloudforce",520);
        set_skill("shadowsteps",520);
	map_skill("force", "cloudforce");
	map_skill("parry","softsword");
        map_skill("sword","softsword");
        map_skill("dodge","shadowsteps");
        map_skill("dodge","shadowsteps"); 
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 600);      
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.bajian" :),
                (: perform_action, "sword.yixiao" :),
                (: perform_action, "dodge.lianhuanjiao" :),
        }) );
    setup();
    carry_object(__DIR__"obj/qingcloth")->wear();
    carry_object(__DIR__"obj/xiesword")->wield();
} 
void init()
{
        object me;
        ::init();
        add_action("do_killing", "kill");
        if((random(20) == 6) && interactive(me = this_player()))
   {
                if(  !me->is_fighting() && userp(me) && me->query("marks/东林_神剑_死亡之剑") && !me->query("marks/东林_神剑_谢晓峰"))
                {
                        if (me->query("marks/yan13xieaction"))
                        {
                                remove_call_out("actthree");
                                call_out("actthree",4,me);
                        }else
                        {
                                remove_call_out("fight_yan13");
                                call_out("fight_yan13",2,me);
                        }
                        add_action("do_answer","answer");
                }
        } 
}
void fight_yan13(object me)
{
        object yan13;
        if (objectp(me) && present(me,environment(this_object())))
        {
                if (!yan13 = present("yan13",environment(this_object())))
                {
                        if (!yan13 = find_living("yan13"))
                                yan13 = new(__DIR__"yan13");    
                        yan13->set("marks/inaction",1);
                        yan13->move(environment());
                        message_vision("$N静静地走来。\n\n",yan13);
                        message_vision(HIR"夕阳红如血，竹林也红如血，天地间充满了杀气。\n"NOR,this_object());
                        message_vision("$N终於长长叹息，道：“燕十叁果然不愧是燕十叁，想不到我们总算见面了。”\n\n",this_object());
                        message_vision(HIC"没有人能看得见他们拔剑的动作，他们的剑忽然间就已经闪电般击出。 \n\n剑气纵横，满天竹叶飞舞。\n\n"NOR,this_object());
                        message_vision(HIW"$N盯着自己手里的剑锋，眼睛彷佛有火焰在燃烧，又彷佛有寒冰在凝结。 \n"NOR,yan13);
                        message_vision(HIW"满天飞舞的竹叶，忽然全都散了，本来在动的，忽然全都静止。 \n\n"NOR,this_object());
                        me->set("marks/yan13xieaction",1);
                        call_out("acttwo",3,me,yan13);
                }
        }
} 
void acttwo(object me,object yan13)
{
   
        message_vision(RED"$N脸上忽然露出种恐惧之极的表情。 \n\n"NOR,this_object());
        message_vision(HIR"$N的眼睛里，忽然也露出种恐惧之极的表情，甚至远比谢晓峰更恐惧。 
然後他就做出件任何人都想不到。任何人都无法想像的事。他忽然回转了剑锋， 
割断了他自己的咽喉。 \n"NOR,yan13);
         yan13->die();
         if (objectp(me) && present(me,environment(this_object())))
         {
                 call_out("actthree",4,me);
         }
}
void actthree(object me)
{
         if (objectp(me) && present(me,environment(this_object())))
         {
                message_vision( "$N动也不动的站在那里，良久，忽向$n问道：“他为什麽要做这种事？” (answer) \n ",this_object(),me);
                me->set_temp("xieask",1);
         }
}
int do_answer(string arg)
{
        object me;
        me = this_player();
        if (!me->query_temp("xieask"))
        {
                return 0;
        }
        me->delete_temp("xieask");
        if (arg == "安禅制毒龙" || arg == "毒龙")
        {
                message_vision("$N疲倦失神的眼睛里忽然有了光，忽然长长吐出口气喃喃道:“我明白了，我明白了……”\n\n",this_object());
                if (!me->query("marks/安禅制毒龙"))
                {
                        me->set("marks/安禅制毒龙",1);
                        me->add("combat_exp",10000);
                        me->add("potential",2000);
                        me->add("score",400);
                        tell_object(me,"你被奖励了：\n 四千点实战经验\n四百点潜能\n四百点综合评价\n\n");
                } 
        }else
   {
                command("shake");
        }
       message_vision("$N黯然道：“因为他的生命骨肉，都已经和这条毒龙融为一体，因为这条 
毒龙本来就是他这个人的精粹，所以他要消灭这条毒龙，就一定要先把自己毁灭。”\n",this_object());
         me->delete("marks/东林_神剑_死亡之剑");
         me->set("marks/东林_神剑_谢晓峰",1);
         return 1;
}
void attempt_apprentice(object me)
{       object book;
        if (me->query("marks/东林_面壁成功")) {
                command ("smile");
                command ( "say 达摩大师的传人，难道还放不下争强斗胜之心么？");
        }       
        else {
        if (me->query("class") == "shaolin" && me->query("marks/东林_神剑_谢晓峰"))
        {
                command("smile");
                if (me->query("combat_exp")<2000000)
                        command("say 你很有天赋，只是火候不够，好好锤炼几年后再来找我。\n");
                else    {
                
                        if ( (random(100)>15 
                                && !me->query("marks/东林_神剑_拜师") 
                                && me->query("宿命B/常春_海潮") 
                              ) 
                             || me->query("family/master_name") == "谢晓峰" ) {
                                command("recruit " + me->query("id") );
                                if (!me->query("marks/东林_神剑_拜师")) me->add("betrayer", -1);                                
                                me->set("marks/东林_神剑_拜师", 2);
                        } else {
                                if ( me->query("marks/东林_神剑_拜师") ==1) 
                                        message_vision("$N叹了口气，心灰意懒地对$n说，“贪心的人永远也不会懂燕十叁的剑法。”\n", this_object() ,me);    
                                else {
                                        me->set("marks/东林_神剑_拜师", 1);
                                // Get a book                              
                                        book = new(__DIR__"obj/yanbook" );
                                        book->move(me);
                                        message_vision("$N忽然取出一段$n早已熟悉的梅枝，说：“燕十叁剑法的精华，尽在这一剑中。\n你是有缘人，不妨好好研习，或可发扬光大此剑。”\n$N把梅枝交到$n手中。\n", this_object(), me);
                           }
                                
                        }
                }
        }
        }
} 

void die()
{
    object yan13;
    if(yan13 = present("yan13",environment(this_object())))
        {
                message_vision("$N一言不发，静静离开。\n",yan13);
                destruct(yan13);
        }
    ::die();
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
        if(id_class == "swordsman"&& userp(victim)&&player!=victim)
        {
            message_vision("$N对着$n喝道：" + RANK_D->query_rude(player) 
                                                + "竟敢杀" + RANK_D->query_self_rude(this_object()) 
                                                + "的徒弟，去死吧。\n", this_object(), player);
            this_object()->kill_ob(player);
            player->kill_ob(this_object());
            player->start_busy(2);
            return 0;
        } 
    }
    return 0;
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
