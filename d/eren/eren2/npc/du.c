 inherit NPC;
inherit F_VENDOR; 
void create()
{
        set_name("杜老爹", ({ "du laodie" }) );
        set("gender", "男性" );
        set("age", 60);
        set("long",
                "杜老爹据说是血手杜杀的堂叔，不过大家最感兴趣的还是他制作的暗
器，相传老爹年轻时在唐门和霹雳堂里是领班工匠，端的是赫赫有名。\n");
        set("combat_exp", 800000);
        
        set("neili",800);
        set("max_neili",800);
        set("force_factor",40);
        set("mana",500);
        set("max_mana",500);
        
        set_skill("unarmed",100);
        set_skill("changquan",200);
        set_skill("dodge",100);
        set_skill("move",100);
        map_skill("unarmed","changquan");
        
	set("vendor_goods", ({
		"/d/city/npc/obj/jitui",
		"/d/city/npc/obj/jiudai",
		"/d/city/npc/obj/baozi",
               __DIR__"obj/zhen",
               __DIR__"obj/lei",
               __DIR__"obj/jili",

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
        message_vision("$N看了你一眼，又转身打铁去了。\n",this_object());
}      
