// 楚州茶博士 /d/city/chuzhou/npc/cha_boshi.c
// by lala, 1997-12-14

#include <ansi.h>
 
inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name( "茶博士", ({ "cha boshi","waiter"}) );
        set("gender", "男性" );
        set("age", 36);
        set("long",
           "手拎个大茶壶，站在柜台边上的茶博士正在沏一壶茶。\n"
        );
        set("combat_exp", 8000);
        
        set_temp("apply/attack", 20);
        set_temp("apply/attack", 30);
        set("chat_chance_combat", 10);
        set("attitude", "friendly");
	set("vendor_goods", ({
		"/d/city/npc/obj/jitui",
		"/d/city/npc/obj/jiudai",
		"/d/city/npc/obj/baozi",
	}));
        setup();
        carry_object("/clone/misc/cloth" )->wear();
    add_money( "coin", 10 + random(200) );
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
        say( "茶博士说：“这位" + RANK_D->query_respect(ob)
                + "，您想喝茶还是吃点心？楚州的‘金丝茶馓’不吃可惜啊！”\n");
}

