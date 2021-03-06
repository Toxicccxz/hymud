// tang liang.c 唐亮

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("唐亮", ({ "tang liang", "tang" }));
	set("nickname", HIW "千手千眼" NOR);
	set("long", 
		"他是唐门第一高手，传说他可以同时发出一千种不同暗器。\n"
		"也可以同时接下一千种暗器。\n"
		"他大约五十有余，双手总是笼在袖中。\n");
	set("gender", "男性");
	set("age", 50);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 28);
	set("int", 30);
	set("con", 30);
	set("dex", 32);
	
	set("max_qi", 11000);
	set("max_jing", 31000);
	set("neili", 13000);
	set("max_neili", 13000);
	set("jiali", 100);
	set("combat_exp", 6000000);
	set("score", 100000);

	set_skill("zhuihun-biao", 280);
		set_skill("liuxing-biao", 280);
	set_skill("pili-biao",280);
	set_skill("force", 250);
	set_skill("biyun-xinfa", 280);
	set_skill("dodge", 250);
	set_skill("qiulinshiye", 280);
	set_skill("strike", 250);
	set_skill("unarmed",280);
	set_skill("biye-wu", 280);
	set_skill("parry", 280);
	set_skill("throwing", 280);
	set_skill("zimu-zhen", 280);
	set_skill("literate", 150);
	
	set_skill("dusha-zhang", 280);
	set_skill("lansha-shou", 280);
	set_skill("hand", 280);
	set_skill("strike", 280);
	map_skill("strike", "dusha-zhang");
	map_skill("hand", "lansha-shou");
	map_skill("force", "biyun-xinfa");
	map_skill("dodge", "qiulinshiye");
	map_skill("strike", "dusha-zhang");
	map_skill("unarmed","biye-wu");
	map_skill("parry", "biye-wu");
	map_skill("throwing", "zimu-zhen");
	map_skill("strike", "dusha-zhang");
	map_skill("hand", "lansha-shou");
	prepare_skill("strike", "dusha-zhang");
	prepare_skill("hand", "lansha-shou");
	

	set("class", "tangmen");

	set("chat_chance_combat", 98);
	set("chat_msg_combat", ({
		(: perform_action, "throwing.poqizhen" :),
		(: perform_action, "throwing.dinhun" :),
                (: perform_action, "throwing.qizigangbiao" :),
                (: perform_action, "throwing.tanghua" :),
		(: perform_action, "parry.wandu" :),
		(: perform_action, "parry.meng" :),
		(: perform_action, "strike.tianxie" :),
		(: perform_action, "strike.hantian" :),
		(: perform_action, "hand.canglong" :),
		(: perform_action, "hand.xiangyi" :),
		(: perform_action, "hand.luanpo" :),									
						
	}) );
	
	        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 200);
        set_temp("apply/attack", 200);
	create_family("唐门", 6 ,"精益堂堂主");
	set("class", "tangmen");



	setup();
	carry_object("/d/tangmen/obj/zhuyebiao")->wield();
	carry_object("/d/tangmen/obj/qingduan")->wear();
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query_skill("biyun-xinfa", 1) < 80) {
		command("say 唐门虽然以暗器为主，但还是要辅以内力。"); 
		command("say " + RANK_D->query_respect(ob) + 
			"是否还应该在碧云心法上多下点功夫？");
		return;
	}
	if (ob->query_int() < 25) {
		command("say 唐门历来注重弟子的文学修为。");
		command("say 本派功夫要能熟练运用，必须能体会其中所含深远意境，悟性差了是不行的。");
		command("say " + RANK_D->query_respect(ob) + "的悟性还大有潜力可挖，还是请回吧。");
		return;
	}
	command("say 唐门武学精深博大，你好好修习，将唐门发扬光大。");
	command("recruit " + ob->query("id"));
}
