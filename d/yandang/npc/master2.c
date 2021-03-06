#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
	int i;
        set_name("落雁老人", ({ "luoyan master", "master", "luoyan" }) );

        set("gender", "男性");
        set("age", 74);
        set("class", "xiake");
        set("title","庄主");
	set("max_qi", 36000);
	set("max_jing", 36000);
	set("max_jingli", 36000);
	set("neili", 13000);
	set("max_neili", 33000);
	set("food",250);
	set("water",250);
	set("mingwang",200000);

        set("str", 150);
        set("int", 100);
        set("con", 30);
        set("per", 30);
        set("cps", 30);
        set("dex", 130);
        set("spi", 30);
        set("car", 50);

        set("force", 4000);
        set("max_force", 4000);
        set("force_factor", 50);
  set("combat_exp", 9000000);
        set("str", 55);
        set("max_qi",35000);
        set("max_jing",35000);
        set("max_sen",35000);
        set("neili", 50000);
        set("max_neili", 50000);
        set("atman", 10000);
        set("max_atman", 50000);
        set("mana", 50000);
        set("max_mana", 50000);
        set("force_factor", 350);




set_skill("flying-dragon",380);

set_skill("touch",380);
set_skill("softsword",380);



set_skill("qiusheng-blade",380);
set_skill("siqi-sword",380);
set_skill("qingpingsword",380);
set_skill("sharen-sword",380);
set_skill("lefthand-sword",380);
set_skill("longfenghuan",380);
set_skill("feidao",380);
set_skill("feixian-sword",380);









        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 600);
        set_temp("apply/damage", 650);

        set_skill("literate",380);
        set_skill("unarmed",380);
        set_skill("cuff",380);
        set_skill("dodge",290);
        set_skill("parry",280);
	set_skill("force",380);
	set_skill("strike",280);
	set_skill("finger",380);
        //set_skill("doomsword",380);
        //set_skill("chilian-shenzhang",380);
        //set_skill("softsword",280);
        //set_skill("nine-moon-sword",380);
        set_skill("luohua-jian",380);
        set_skill("sword",380);
        set_skill("dagger",380);
        set_skill("feixian-sword",380);

        set_skill("fengyu-piaoxiang",390);
set_skill("martial-cognize",380);
set_skill("luteplaying",380);
set_skill("painting",380);



        map_skill("strike","bluesea-force");
set_skill("ziwu-daxuefa",380);
set_skill("bluesea-force",380);
        set_skill("love-sword",380);
       set_skill("nei-bagua",380);
       set_skill("wai-bagua",380);
       set_skill("bagua-bu",380);
        prepare_skill("strike", "bluesea-force");
        prepare_skill("cuff", "wai-bagua");
        map_skill("dagger","ziwu-daxuefa");
        map_skill("force","bluesea-force");
        map_skill("dodge","bagua-bu");
        map_skill("parry","ziwu-daxuefa");
        map_skill("strike","bluesea-force");
        map_skill("cuff","wai-bagua");
        map_skill("sword","love-sword");
        
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: exert_function, "powerup" :),
                (: exert_function, "shield" :),
                (: exert_function, "rorar" :),
                (: perform_action, "cuff.gua" :),
                (: perform_action, "cuff.wuliang" :),                
                (: perform_action, "strike.bo" :),
                (: perform_action, "strike.hai" :),
                (: perform_action, "strike.jue" :),
                (: perform_action, "strike.nan" :),
                (: perform_action, "strike.xuan" :),
                (: perform_action, "dagger.dian" :),
                (: perform_action, "dagger.ding" :),
                (: perform_action, "dagger.feng" :),	
                (: perform_action, "dagger.jing" :),	
                (: perform_action, "dagger.kuangcao" :),	                	
(: perform_action, "dodge.bagua" :),		             	             
(: perform_action, "dodge.zhen" :),		             	              
        }) );
i=0;	
if (random(2)==0)
{
	set_skill("love-sword",399);
i=1;
map_skill("sword","love-sword");
}	
	
        create_family("雁荡派", 1, "掌门");
        setup();
if (i==0)
        carry_object(__DIR__"obj/zizhuzhang")->wield();
else
        carry_object(__DIR__"obj/zizhusword")->wield();

	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/book/ninebookok");
        //carry_object("/obj/zijin");
}

void init()
{      object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");

                call_out("greeting", 1, ob);
        }
}
void greeting(object ob)
{
  if (ob&&environment(ob)!=environment()) return;
if (ob->query("score")>10000)
message_vision("落雁老人赞赏的看了$N一眼,摸着胡子点了点头!\n",ob);
  else 
 message_vision("落雁老人失望的看着$N,深深叹了口气,嘴边的胡子都飞了起来!\n",ob);
}
void attempt_apprentice(object ob)
{
	
		if( (string)ob->query("family/family_name")!="雁荡派")
        {
                command("hmm");
                command("say 你先找我几个徒弟学好基本功吧!\n");
                return;
        }


		if( (int)ob->query("combat_exp",1)<=1000000)
        {
                command("hmm");
                command("say 你的经验太少，先找我几个徒弟学好基本功吧!\n");
                return;
        }

	
        if( (int)ob->query("PKS") > 10 ) 
        {
                command("hmm");
                command("say 你手上血腥浓重，怎能修身得道？\n");
                return;
        }
        if ( ob->query("gender") == "无性" )
        {
                command("heihei");
                command("say 你是一个阉割之人，怎能修身得道？\n");
                return;
        }
        command("en");
        say("落雁老人笑道：“这位"+RANK_D->query_respect(ob)+"真是个可造之才呀！\n"
            "将来必能发扬我落雁派门庭！\n");
        command("recruit "+ob->query("id") );

}


