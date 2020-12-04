// yaoboss.c
// by dicky

inherit NPC;
inherit F_DEALER;


void create()
{
        set_name("张济世", ({ "zhang jishi","boss","jishi"}) );
        set("title", "药铺老板");
        set("gender", "男性" );
        set("age", 55);
        set("long", "他就是药铺的张板王济世，一位忠厚老者。\n");

       	set("combat_exp", 100);
        set("attitude", "friendly");
        set_skill("unarmed", 50);
        set_skill("parry", 50);
        set_skill("dodge", 50);
	set("sell_all_day",1);

        set("inquiry", ([
                "抓药" : "这里是附近最好的药店，您要什么？",
        ]) );

	set("vendor_goods", ({
		__DIR__"obj/yao",
		__DIR__"obj/xuelian",
	}));


        setup();
        add_money("silver", 10);
        carry_object("/clone/misc/cloth")->wear();
}
void init()
{	
	object ob; 
	mapping myfam; 

	ob = this_player();

	::init();

	add_action("do_buy", "buy");
	add_action("do_list", "list");
}
