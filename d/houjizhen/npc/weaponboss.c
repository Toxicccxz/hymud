// weaponboss.c
// by dicky

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("兵器铺老板", ({ "weapon boss", "boss" }) );
	set("gender", "男性" );
	set("age", 40);
	set("long", "兵器铺老板个脸上有一道伤疤中年人，一笑起来份外诡异。\n");
	set("combat_exp", 30000);
	set("attitude", "friendly");
	set("max_qi",1000);
	set("max_neili",1000);
	set("force_factor",40);
	set_skill("unarmed", 100);
	set_skill("dodge", 100);
	set_skill("sword", 100);
	set_skill("parry", 120);
	
	set("sell_all_day",1);
	set("inquiry", ([
		"兵器" : "本店专卖各种长短兵器", 
	]) );

        set("vendor_goods",({
                   "/d/city/obj/changjian",
                   "/d/city/obj/hammer",
                   "/d/city2/obj/tudao",
		"/d/city/obj/dagger",
                  "/d/xingxiu/obj/tiegun",
                  "/d/city/obj/gangdao",
        }));

	setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/gangjian")->wield();
}
void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}