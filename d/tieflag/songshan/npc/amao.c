 // waiter.c
inherit NPC;
inherit F_DEALER;
void create()
{
        set_name("阿毛", ({ "amao" }) );
        set("gender", "男性" );
        set("age", 34);
        set("long",
                "阿发的弟弟\n");
        set("combat_exp", 50);
        set("attitude", "friendly");
        set("per",30);
 	set("vendor_goods", ({
		"/d/city/npc/obj/jitui",
		"/d/city/npc/obj/jiudai",
		"/d/city/npc/obj/baozi",
		"/d/city/npc/obj/sniurou",
		"/d/city/npc/obj/sjiudai",
	//"/clone/misc/newpaper",
	}));
        set_skill("unarmed",5);
        setup();
        carry_object("/clone/misc/cloth")->wear();
} 
void init()
{       
        object ob; 
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
	add_action("do_buy", "buy");
	add_action("do_list", "list");
} 
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(10) ) {
                case 0:
message_vision("$N对$n说：顶该这塔各么犀利！莫得顶？\n",this_object(),ob);
                        break;
        }
}      
