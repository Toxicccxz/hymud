// pi.c 裨将

inherit NPC;
//inherit F_SKILL;

void create()
{
	set_name("裨将", ({ "pi jiang", "pi", "jiang" }));
	set("gender", "男性");
	set("age", random(10) + 30);
	set("str", 25);
	set("dex", 16);
	set("long", "这是一个大宋年轻将领，满脸征尘。\n");
	set("combat_exp", 45000);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set("combat_exp", 810000);
	set("shen_type", 1);

    set("max_neili",8500);
    set("neili",8500);
    set("qi",8500);
    set("eff_qi",8500);
    set("max_qi",8500);

    set("jing",8500);
    set("eff_jing",8500);
    set("max_jing",8500);
        set_skill("force", 180+random(180));

        set_skill("unarmed", 180+random(180));
        set_skill("blade", 180+random(180));
        set_skill("parry", 180+random(180));
        set_skill("dodge", 180+random(180));
        set_skill("kuang-blade", 280+random(180));
        map_skill("blade", "kuang-blade");
        map_skill("parry", "kuang-blade");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "blade.leitingpili" :),
                (: perform_action, "blade.kuang" :),

        }) );


	set("jiali", 10);

	setup();
	carry_object("/clone/weapon/gangjian")->wield();
	carry_object("/d/city/npc/obj/tiejia")->wear();
}

void init()
{
	object ob;
	::init();
	if (interactive(ob = this_player()) && 
		(int)ob->query_condition("killer")) {
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob);
	}
}
