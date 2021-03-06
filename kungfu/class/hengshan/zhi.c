// Last Modified by Sir on May. 22 2001
// zhi.c
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
#include <command.h>
void create()
{
	set_name("仪质", ({ "yi zhi", "zhi" }) );
	set("long", "她是一位年青女尼，慈眉善目。\n");
	set("gender", "女性");
	set("class", "bonze");
	set("age", 25);
	set("attitude", "peaceful");
	set("per", 24);
	set("str", 26);
	set("con", 30);
	set("dex", 30);
	set("int", 28);

	set("neili", 3400);
	set("max_neili", 3400);
	set("jiali", 30);
	set("max_qi", 3000);
	set("max_jing", 3800);
	set("combat_exp", 500000);
	set("shen_type", 1);

	set_skill("unarmed", 90);
	set_skill("sword", 100);
	set_skill("force", 90);
	set_skill("parry", 90);
	set_skill("dodge", 100);
	set_skill("strike", 90);
	set_skill("hand", 90);
	set_skill("buddhism", 100);
	set_skill("baiyun-xinfa",90);	
	set_skill("hengshan-jian", 150);
	set_skill("chuanyun-shou",120);
	set_skill("tianchang-zhang",120); 
	set_skill("lingxu-bu", 150);

	map_skill("force","baiyun-xinfa");
	map_skill("sword", "hengshan-jian");
	map_skill("strike","tianchang-zhang");
	map_skill("hand","chuanyun-shou");
	map_skill("parry", "hengshan-jian");
	map_skill("dodge", "lingxu-bu");
	prepare_skill("strike", "tianchang-zhang");
	prepare_skill("hand", "chuanyun-shou");
	set("env/wimpy", 60);
	set("chat_chance_combat", 90);
	set("chat_msg_combat", ({
		(: perform_action, "sword.yuyin" :),		
		(: exert_function, "powerup" :),
		(: exert_function, "regenerate" :),		
		(: exert_function, "recover" :),
	}) );

	create_family("恒山派", 14, "弟子");
	setup();

	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/shaolin/obj/cheng-cloth")->wear();
}

void attempt_apprentice(object ob)
{
	if (ob->query("age") > 19 && ob->query("family/family_name")!="恒山派") 
	{
		command("say 我恒山派注重清修，对弟子要求能忍受寂寞。");
		command("say 在江湖阅历方面，" + RANK_D->query_respect(ob) +
			"经历丰富，是否能在恒山修道？");
		return;
	}
	if ((int)ob->query("shen") < 0) {
		command("say 我恒山乃是堂堂五岳剑派之一，对弟子要求极严。");
		command("say 在德行方面，" + RANK_D->query_respect(ob) +
			"是否还做得不够？");
		return;
	}
	if (ob->query("gender") != "女性") 
	{
		command("say 我恒山只收女徒。");		
		return;
	}
	command("say 好吧，我就收下你了。");
	command("recruit " + ob->query("id"));
}
