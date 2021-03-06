// yao.c

inherit NPC;

#include <ansi.h>
void create()
{
	set_name("乐厚", ({ "yao hou", "hou", "yao" }) );
	set("long","他矮矮胖胖，面皮黄肿，约莫五十来岁年纪，两只手掌肥肥的又小又厚。\n");
	set("nickname", "大阴阳手");
	set("gender", "男性");
	set("class", "swordsman");
	set("age", 54);
	set("attitude", "peaceful");
	set("str", 26);
	set("con", 30);
	set("dex", 30);
	set("int", 28);

	set("neili", 30000);
	set("max_neili", 30000);
	set("jiali", 30);
	set("max_qi",30000);
	set("max_jing",30000);
	set("combat_exp", 3000000);
	set("shen_type", 1);
	set("no_get",1);

	set_skill("literate", 50);
	set_skill("strike", 300);
	set_skill("hand", 300);
	set_skill("sword", 300);
	set_skill("force", 300);
	set_skill("parry", 300);
	set_skill("dodge", 300);
	set_skill("songshan-sword", 300);
	set_skill("songyang-strike", 300);
	set_skill("poyun-hand", 300);
	set_skill("hanbing-zhenqi", 300);
	set_skill("fuguanglueying", 300);
	map_skill("strike", "songyang-strike");
	map_skill("hand", "poyun-hand");
	map_skill("sword", "songshan-sword");
	map_skill("parry", "songshan-sword");
	map_skill("dodge", "fuguanglueying");
	map_skill("force", "hanbing-zhenqi");
	prepare_skill("strike", "songyang-strike");
	prepare_skill("hand", "poyun-hand");
	set("env/wimpy", 60);
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "sword.shuiyuan" :),
		(: perform_action, "sword.jianqi" :),
		(: perform_action, "sword.feiwu" :),
		(: perform_action, "strike.yinyang" :),
		(: perform_action, "hand.chanyun" :),
		(: exert_function, "powerup" :),
		(: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
	}) );
	create_family("嵩山派", 13, "弟子");
	setup();

	carry_object(__DIR__"obj/kuojian")->wield();

	carry_object(__DIR__"obj/yellow-cloth")->wear();
}

