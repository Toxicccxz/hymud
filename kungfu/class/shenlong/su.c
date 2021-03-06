// su.c 苏荃

#include <ansi.h>
inherit NPC;
inherit F_UNIQUE;
inherit F_MASTER;

void create()
{
	set_name("苏荃", ({ "su quan", "su" }));
	set("title",  HIY"神龙教"NOR"夫人" );
	set("long", "她就是神龙教教主洪安通的夫人。\n");
	set("gender", "女性");
        set("per",30);
	set("age", 23);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 35);
	set("int", 30);
	set("con", 30);
	set("dex", 38);
	
	set("max_qi", 19000);
	set("max_jing", 19000);
	set("neili", 28000);
	set("max_neili", 28000);
//	set("jiali", 100);
	set("combat_exp", 1500000);
	set("score", 2400000);
        set_skill("claw", 100);
        set_skill("strike", 100);
	set_skill("dulong-shenzhua", 250);
	set_skill("xuanming-zhang", 250);
        set_skill("force", 150);
	set_skill("shenlong-xinfa", 250);
        set_skill("dodge", 150);
	set_skill("yixingbu", 200);
        set_skill("hand", 200);
	set_skill("shenlong-bashi", 250);
        set_skill("strike", 200);
	set_skill("huagu-mianzhang", 250);
        set_skill("parry", 150);
        set_skill("staff", 150);
        set_skill("sword", 150);
        set_skill("zhaosheshu", 250);
        set_skill("juehu-shou", 150);
        set_skill("yangsheshu", 250);
	set_skill("shedao-qigong", 250);
	set_skill("literate", 190);

	
	map_skill("force", "shenlong-xinfa");
	map_skill("dodge", "yixingbu");
	map_skill("hand", "juehu-shou");
	map_skill("strike", "huagu-mianzhang");
	map_skill("parry", "juehu-shou");
        map_skill("staff", "shedao-qigong");
	prepare_skill("strike", "huagu-mianzhang");
	prepare_skill("hand", "shenlong-bashi");
	//prepare_skill("hand", "juehu-shou");

	create_family("神龙教",1,"教主夫人");

        set("inquiry", ([
		"神龙教" :  "\n一般人是入不了我神龙教的(join shenlongjiao).\n",
		"入教" :  "\n一般人是入不了我神龙教的(join shenlongjiao).\n",
		"口号" : "\n万年不老!永享仙福!寿与天齐!文武仁圣!\n",
       ]) );
	set("chat_chance_combat", 50);  
	set("chat_msg_combat", ({
		(: command("smile") :),
(: perform_action, "strike.bujue" :),
(: perform_action, "strike.hua" :),
(: perform_action, "strike.lianhuan" :),
                (: perform_action, "strike.bujue" :),
                                (: perform_action, "strike.hua" :),
                (: perform_action, "strike.lianhuan" :),
                (: perform_action, "hand.bada" :),
                (: perform_action, "hand.shenlongtuwu" :),
                (: perform_action, "hand.shewu" :),
                (: perform_action, "hand.flower" :),
                (: perform_action, "hand.meinu" :),                
                (: perform_action, "hand.yingxiong" :),                
                (: perform_action, "parry.luanhuan" :),
                (: perform_action, "parry.juehu	" :),                   

                (: exert_function, "recover" :),
                (: exert_function, "recover" :),
                      }) );
	setup();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver", 50);
}

void init()
{
	object ob;

	::init();

}

void attempt_apprentice(object ob)
{
    if ((int)ob->query_skill("shenlong-xinfa",1) < 80 ) {
        command("say 你的本门内功心法太低了,还是努努力先提高一下吧!");
		return;
    }
    if ((int)ob->query_skill("shedao-qigong",1) < 80 ) {
        command("say 你的蛇岛奇功太低了,还是努努力先提高一下吧!");
		return;
    }
    if ((int)ob->query("shen") > -10000  ) {
        command("say 我神龙教与世隔绝，向来不与您这种白道人物打交道，您请回吧！");
		return;
	}
    command("say 很好，很好。");
    command("recruit " + ob->query("id"));
}
 
void die()
{
	int i;
        object who = this_object()->query_temp("last_damage_from");
  	if (!who) return;
  	who->add_temp("book753",1);
	::die();
}