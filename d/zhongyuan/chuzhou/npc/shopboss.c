// 杂货铺老板 /d/city/chuzhou/npc/shopboss.c
// by lala, 1997-12-13

#include <ansi.h>

inherit NPC;

inherit F_VENDOR;

void create()
{
    set_name( "莫飞云", ({ "mo feiyun", "mo", "boss", }) );
    set( "title", MAG"杂货铺"GRN"老板"NOR );
    set( "gender", "男性" );
    set( "age", 38 );
    set( "long", @LONG
这是个极为随和的人，就象他的杂货铺一样，什么都有，没有一定的规律，也没
有什么限制。在他这里可以买到许多乱七八糟的东西，虽然有些你都不一定知道
它有什么用。
LONG
    );
    set( "attitude", "friendly" );


    
	set("vendor_goods", ({
		__DIR__"obj/map_chuzhou",
		__DIR__"obj/hulu",
		__DIR__"obj/bag",
		__DIR__"obj/finger",
	}));    
    set( "talk_msg",({
    }));
    set("qi",400);
    set("max_qi",400);
    set("eff_kee",400);
    set("sen",400);
    set("max_sen",400);
    set("eff_sen",400);
    set("max_force", 600);
    set("force",     600);
    set("force_factor", 20);
    set("combat_exp", 500000);
    set("social_exp", 500000);
    set("positive_score", 2000);
    set("negative_score", 1000);

 
    setup();
      
    carry_object( "/clone/misc/cloth")->wear();
    add_money( "coin", 20 + random(31) );
}          

void init()
{       
    ::init();
	add_action("do_buy", "buy");
	add_action("do_list", "list");
}

