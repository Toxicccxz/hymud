 // tea_waiter.c
inherit NPC;
inherit F_VENDOR; 
void create()
{
    set_name("小二哥", ({ "waiter" }) );
    set("gender", "男性" );
    set("age", 23);
    set("long", 
        "小二哥长的浓眉大眼，正在忙碌地招呼客人。\n");
        set("combat_exp", 5);
    set("attitude", "friendly");
    set("rank_info/respect", "小二哥");

    
	set("vendor_goods", ({
		"/d/city/npc/obj/jitui",
		"/d/city/npc/obj/jiudai",
		"/d/city/npc/obj/baozi",
		__DIR__"obj/wineskin",
		__DIR__"obj/taopian",
	}));    
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
        say( "小二哥笑眯眯地说到：这位" + RANK_D->query_respect(ob)
                             + "，进来喝杯清茶，歇歇腿吧。\n");
}        
