// luo.c ���

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("���", ({ "luo bing", "luo","bing" }));
	set("title", HIR "�컨��"HIG"ʮһ����" NOR);
	set("nickname", HIG "ԧ�쵶" NOR);
	set("long", 
"����һ���������ٸ���һ�̵ֶ���һ������һ��������\n");
	set("gender", "Ů��");
	set("class", "fighter");
	set("age", 24);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("per", 28);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("max_qi", 18400);
	set("max_jing", 11700);
	set("neili", 20000);
	set("max_neili", 20000);
	set("jiali", 100);
	set("combat_exp", 950000);

	set_skill("literate", 200);
	set_skill("force", 200);
	set_skill("dodge", 200);
	set_skill("parry", 200);
	set_skill("blade", 200);
	set_skill("hand", 200);
	set_skill("claw", 200);
	set_skill("yunlong-shengong", 300);
	set_skill("wuhu-duanmendao", 300);
	set_skill("yunlong-shenfa", 200);
	set_skill("yunlong-shou", 300);
	set_skill("yunlong-zhua", 300);

	map_skill("dodge", "yunlong-shenfa");
	map_skill("force", "yunlong-shengong");
	map_skill("blade", "wuhu-duanmendao");
	map_skill("hand", "yunlong-shou");
	map_skill("parry", "yunlong-shou");
	map_skill("claw", "yunlong-zhua");

	prepare_skill("hand","yunlong-shou");
	prepare_skill("claw","yunlong-zhua");
	set("env/wimpy", 20);

 	setup();
	carry_object("/d/city2/obj/jinduan")->wear();
	carry_object("/clone/weapon/gangdao")->wield();
}
