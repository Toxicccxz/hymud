// bing.c �ٱ�

inherit NPC;

void create()
{
	set_name("�����ٷ�", ({ "guan bing", "bing" }));
	set("age", 22);
	set("gender", "����");
	set("long", "��Ȼ�����ٷ򳤵����ղ��ܺ�������ʿ��ȣ��������ǽ��������˶�������\n");
	set("attitude", "peaceful");
//	set("vendetta_mark", "authority");
//      set("pursuer", 1);

	set("str", 24);
	set("dex", 16);
	set("combat_exp", 1310000);
	set("shen_type", 1);

    set("max_neili",15500);
    set("neili",15500);
    set("qi",15500);
    set("eff_qi",15500);
    set("max_qi",15500);

    set("jing",5500);
    set("eff_jing",5500);
    set("max_jing",5500);
        set_skill("force", 380+random(180));

        set_skill("unarmed", 380+random(180));
        set_skill("blade", 380+random(180));
        set_skill("parry", 380+random(180));
        set_skill("dodge", 380+random(180));
        set_skill("kuang-blade", 380+random(180));
        map_skill("blade", "kuang-blade");
        map_skill("parry", "kuang-blade");
        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                (: perform_action, "blade.leitingpili" :),
                (: perform_action, "blade.kuang" :),
        }) );


//	if (random(2) == 1) {
//		set("chat_chance", 10);
//		set("chat_msg", ({
//			(: random_move :),
//		}));
//	}

        set("chat_chance_combat", 10);
	set("chat_msg_combat", ({
		"�����ٷ򳤺ȵ����󵨵��񣬾����췴���ɣ�\n",
		"�����ٷ򳤺ȵ����ܵ��˺����ܲ��������㻹�ǿ�����־��ܣ�\n",
                (: perform_action, "blade.leitingpili" :),
                (: perform_action, "blade.kuang" :),
	}));
	setup();
	carry_object("/d/city/npc/obj/gangdao")->wield();
	carry_object("/d/city/npc/obj/junfu")->wear();
	carry_object("/d/city/npc/obj/jitui")->wear();
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

int accept_fight(object me)
{
	command("say ��ү����������ɱ�ţ��������㵹ù��\n");
//	me->apply_condition("killer", 500);
	kill_ob(me);
	return 1;
}