// Last Modified by winder on Aug. 25 2001
// yujizi.c

inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
	set_name("玉玑子", ({ "yuji zi", "zi", "yuji" }) );
	set("gender", "男性");
	set("class", "taoist");
	set("age", 45);
	set("attitude", "peaceful");
	set("str", 26);
	set("con", 30);
	set("dex", 30);
	set("int", 28);

	set("neili", 20000);
	set("max_neili", 20000);
	set("max_qi", 20000);
	set("max_jing", 12000);
	set("combat_exp", 2800000);
	set("shen_type", -1);
set_skill("taoism", 250);
	set_skill("strike", 230);
	set_skill("kuaihuo-strike", 320);
	set_skill("sword", 230);
	set_skill("taishan-sword", 320);
	set_skill("force", 230);
	set_skill("panshi-shengong", 320);
	set_skill("parry", 200);
	set_skill("dodge", 200);
	set_skill("fengshenjue", 320);
set_skill("shiba-pan", 320);
	set_skill("dramaturgy", 380);
	set_skill("horticulture", 380);
	map_skill("sword", "taishan-sword");
	map_skill("parry", "taishan-sword");
	map_skill("dodge", "fengshenjue");
	map_skill("force", "panshi-shengong");
	map_skill("strike", "kuaihuo-strike");
	prepare_skill("strike", "kuaihuo-strike");
	set("env/wimpy", 60);
	set("chat_chance_combat", 90);
	set("chat_msg_combat", ({
		(: perform_action, "sword.heru" :),
		(: perform_action, "sword.ruhe" :),
		(: perform_action, "sword.wuyue" :),
		(: perform_action, "sword.18pan" :),
		(: perform_action, "strike.zhouyu" :),
		(: exert_function, "powerup" :),
		(: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
	}) );

	set_temp("apply/attack",180);
	set_temp("apply/defense",180);
	set_temp("apply/armor",600);
	set_temp("apply/damage",600);

	create_family("泰山派", 12, "弟子");
	setup();

	carry_object(__DIR__"houjian")->wield();
	carry_object(__DIR__"daopao")->wear();
}

void attempt_apprentice(object ob)
{
	if((int)ob->query_skill("panshi-shengong",1) < 140)
		command("say 你的本门心法还得多多练习。");
	else
	{
		command("say 好啊，那我就收下你吧。");
		command("recruit " + ob->query("id") );
	}
}


