//guan3.c.金工院官员
//date:1997.8.27
//by dan 

#include <ansi.h>
inherit NPC;
inherit F_VENDOR;

void create()
{
    set_name(RED"官员"NOR, ({ "guanyuan" }) );
    set("title","大夏金工院");
    set("gender", "男性" );
    set("combat_exp", 100000);
    set("max_qi", 400);
    set("max_sen", 300);
        set_skill("unarmed", 80+random(180));
        set_skill("sword", 80+random(180));
        set_skill("parry", 80+random(180));
        set_skill("dodge", 180+random(180));
        set_skill("kuang-jian", 80+random(380));
        
        map_skill("sword", "kuang-jian");
        map_skill("parry", "kuang-jian");
        set_temp("apply/attack", 20);
        set_temp("apply/defense",50);
        set_temp("apply/armor", 50);
        set_temp("apply/damage", 20);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.leitingpili" :),
                (: perform_action, "sword.kuang" :),
        }) );

    set("attitude", "friendly");
    set("env/attack", 78); 


	set("vendor_goods", ({
		__DIR__"obj/blade",
		__DIR__"obj/blade1",
		__DIR__"obj/jian1",
		__DIR__"obj/jian2",
		__DIR__"obj/kaijia",
		__DIR__"obj/kaijia1",
		
	}));
    set("talk_limit/combat_exp",10000); 
    set_temp("talk_npc_number", 10);
    set("talk_player_number/xingqing_guan3",3); 
    set("talk_mark/xingqing_first",1);
    set("talk_msg",({
"告诉你一个秘密，据说太阿剑流失在此城内。你可以去打听一下. \n",
        }) );

    setup();
    carry_object(__DIR__"obj/cloth3")->wear();
    carry_object(__DIR__"obj/jian3")->wield();
}

void init()
{
    object ob;
    ::init();
    if( interactive(ob = this_player()) && !this_object()->can_act() ) 
    {
        remove_call_out("greeting");
        call_out("greeting", 1, ob);
    }
	add_action("do_buy", "buy");
	add_action("do_list", "list");
}

void greeting(object ob)
{
    say("官员对你说：“这位"+RANK_D->query_respect(ob)+"想买点"
                "什么趁手的兵器呀？\n");
}

