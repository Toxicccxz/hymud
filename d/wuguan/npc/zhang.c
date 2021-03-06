//zongguan.c武馆总管
//by cool 98.3.25
#include <ansi.h>

inherit NPC;
string *names = ({"打扫马房","锯木头","劈柴","浇菜地","锄草",});


string ask_job();

void create()
{
	set_name("张风", ({ "zhang feng","zhang","zong guan", "zongguan" }));
	set("title", "襄阳武馆总管");
	set("gender", "男性");
	set("age", 45);
	set("str", 27);
	set("dex", 26);
	set("long", "这人相貌和蔼，笑呵呵的，一手拿个旱烟袋。\n");
	set("combat_exp", 700000);
	set("shen_type", 1);
	set("attitude", "friendly");
       set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: exert_function, "recover" :),(: perform_action, "strike.diezhang" :),
        }) );

	set_skill("unarmed", 120);
	set_skill("force", 130);
       set_skill("strike", 160);
	set_skill("hammer", 100);
       set_skill("kunlun-zhang", 160);
       set_skill("xuantian-wuji", 160);
       set_skill("kunlun-shenfa", 160);
       set_skill("dodge", 160);
	set_skill("parry", 160);
      map_skill("dodge", "kunlun-shenfa");
      map_skill("parry", "kunlun-zhang");
      map_skill("force", "xuantian-wuji");
      map_skill("strike", "kunlun-zhang");
      prepare_skill("strike","kunlun-zhang");


	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/armor", 100);
	set_temp("apply/damage", 100);


       set("qi", 2000);
	set("max_qi", 2000);
	set("neili", 2500); 
	set("max_neili", 2500);
	set("jiali", 150);
 set("inquiry", 
                ([
                     	"工作" : (: ask_job :),
                            "job" : (: ask_job :),
                         	"工具" : "你去物品房找老李要吧！",
  
                ]));


	setup();
}
void init()
{
        object ob;

        ::init();
if (interactive(ob = this_player()) && 
		(int)ob->query_condition("killer"))
       {      command("say 你竟敢在武馆杀人! \n");

		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob);
	} else
       { 
       if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
       }
		add_action("do_task","task");
}
string ask_job()
{
        object me;
        object ob;
        string target;
        ob=this_player();
        me=this_object();
       target = names[random(sizeof(names))];
        if (ob->query_temp("job_name"))
                return ("你不是已经领了工作吗？还不快去做。\n");
            if (ob->query("combat_exp")>=30000)
                     return ("你功夫这么高，这里没有什么适合你的工作了。\n");
	ob->set_temp("job_name",target);
       ob->apply_condition("wuguan_job",random(3)+4);
	return "正好现在有好多事要做，你先去东物品房领工具，然后去后院"+ target+ "吧。";
}
int do_task(string arg)
{
	object ob,me;
	ob=this_player();
	me=this_object();
	if(!(arg||arg=="ok")) return 0;
       if(!ob->query_temp("job_name")) 
            return notify_fail("没给你工作，你怎么跑来覆命了？\n");
              if (interactive(ob)&&(int)ob->query_condition("wuguan_job")) {
                 command("slap "+ob->query("id"));
                 return notify_fail(RED "你这么快回来了，是不是还没做完啊，吩咐你回来了吗？"NOR);
                 }    
       if(!ob->query_temp("mark/还了")) 
            return notify_fail("你先把工具还到老李那再来覆命吧。\n");
      	if(!(ob->query_temp("mark/劈完了")||ob->query_temp("mark/浇完了")||ob->query_temp("mark/锄完了")||ob->query_temp("mark/锯完了")||ob->query_temp("mark/扫完了")||ob->query_temp("mark/挑完了")))
            return notify_fail("你偷懒啊，叫你干活你不去干，跑来领功! \n");
	if(arg=="ok"&&(ob->query_temp("mark/劈完了")||ob->query_temp("mark/锯完了")||ob->query_temp("mark/扫完了")||ob->query_temp("mark/浇完了")||ob->query_temp("mark/锄完了")||ob->query_temp("mark/挑完了")))
	{
		command("smile "+ob->query("id"));
		command("say 好，"+RANK_D->query_respect(ob)+"，做得好，这是给你的奖赏！");
             if (random(10)<7)
            {
              me->add_money("coin",(int)(ob->query_skill("force",1)/2)+65);
              command("give "+ob->query("id")+" "+((int)(ob->query_skill("force",1)/2)+50)+" coin");
             }else{
              me->add_money("silver",(int)(ob->query_skill("force",1)/5)+1);
              command("give "+ob->query("id")+" "+((int)(ob->query_skill("force",1)/5)+1)+" silver");
              }
             	ob->add("potential",(int)(ob->query_skill("force",1)/5)+30);
             if(ob->query("potential") > ob->query("max_pot")) ob->set("potential", ob->query("max_pot"));
              ob->add("combat_exp",(int)(ob->query_skill("force",1)/5)+60);
		ob->delete_temp("job_name");
	       ob->delete_temp("mark");
		return 1;
	}
	return 1;
}
void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
         
 //     if (interactive(ob)&&(int)ob->query_condition("wuguan_job")) {
 //                ob->apply_condition("wuguan_job",random(3)+7);
 //               command("slap"+ob->query("id"));
 //               return notify_fail(RED "不做完就回来了，给我回去继续做! "NOR);
 //               }   
      if(ob->query_temp("job_name")) return; 
//      if(ob->query_temp("mark/还了")&&(ob->query_temp("mark/劈完了")||ob->query_temp("mark/浇完了")||ob->query_temp("mark/锄完了")||ob->query_temp("mark/锯完了")||ob->query_temp("mark/扫完了")||ob->query_temp("mark/挑完了")))
//	{ command("nod" +ob->query("id"));
//         command("say 你工作做的不错，可以跟我覆命了(task ok)! \n");
//         return; 
//        }
       if ( ob->query("combat_exp") < 30000 ) {
       command("bow "+ob->query("id"));
       command("say 这位" + RANK_D->query_respect(ob)
				+ "，我们这缺人手，你可以找我领工作"HIR"(ask zhang about job)"NOR"来做。\n");
       }
}				
