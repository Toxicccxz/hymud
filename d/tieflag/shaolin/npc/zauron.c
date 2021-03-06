 inherit NPC;
#include <ansi.h>
  
void create()
{
        set_name("莲蓉", ({ "lianrong" }) );
        set("gender", "女性" );
        set("age",18);
        set("long", @TEXT
她长得十分漂亮！全身半裸，让你忍不住多瞧她几眼，从她身上
你闻到淡淡的香气。优雅的动作，轻盈的步伐，好美哦!
TEXT
);
        set("class", "dancer");
        set("combat_exp", 200000);
        set("no_arrest",1);
   set("max_qi", 22000);
	set("max_jing", 21000);
	set("neili", 43000);
	set("max_neili", 43000);
	set("jiali", 100);
	set("combat_exp", 8800000);
	set("score", 500000);

	set_skill("literate", 260);
	set_skill("force", 260);
	set_skill("dodge", 260);
	set_skill("unarmed", 260);
	set_skill("parry", 260);
	set_skill("whip", 300);
	set_skill("blade", 300);
	set_skill("sword", 300);
	set_skill("hand", 260);
	set_skill("claw", 300);
	set_skill("cuff", 300);
	set_skill("strike", 300);
	set_skill("houquan", 390);
	set_skill("yunlong-xinfa", 380);
	set_skill("yunlong-shengong", 380);
	set_skill("wuhu-duanmendao", 380);
	set_skill("yunlong-jian", 380);
	set_skill("yunlong-shenfa", 380);
	set_skill("yunlong-bian", 380);
	set_skill("yunlong-shou", 380);
	set_skill("yunlong-zhua", 380);
	set_skill("baihua-cuoquan", 380);
set_skill("bazhen-zhang", 380);

	map_skill("dodge", "yunlong-shenfa");
	map_skill("force", "yunlong-shengong");
	map_skill("unarmed", "baihua-cuoquan");
	map_skill("blade", "wuhu-duanmendao");
	map_skill("hand", "yunlong-shou");
	map_skill("parry", "baihua-cuoquan");
	map_skill("claw", "yunlong-zhua");
	map_skill("sword", "yunlong-jian");
	map_skill("whip", "yunlong-bian");

	map_skill("cuff", "baihua-cuoquan");
	map_skill("strike", "bazhen-zhang");
	
	prepare_skill("cuff", "baihua-cuoquan");
	prepare_skill("strike", "bazhen-zhang");

set("chat_chance_combat", 90);  
	set("chat_msg_combat", ({
                (: perform_action, "sword.slj" :),
                (: perform_action, "sword.duoming" :),
                (: perform_action, "sword.guang" :),
                (: perform_action, "sword.shen" :),
                (: perform_action, "sword.xunlei" :),
                (: perform_action, "sword.xian" :),

                (: perform_action, "cuff.hong" :),
                (: perform_action, "cuff.luan" :),
                (: perform_action, "cuff.yi" :),                	                	
                                
                (: perform_action, "strike.bafang" :),
                (: perform_action, "strike.baxianzuijiu" :),
                (: perform_action, "strike.jueming" :),                	                	


                (: perform_action, "claw.ji" :),
                (: perform_action, "claw.ningxue" :),
	}) );
        set("neili", 3000);
        set("max_neili", 600); 
        set("force_factor", 10);
        setup();
        carry_object(__DIR__"obj/clasp")->wear();
        carry_object(__DIR__"obj/deer_boot")->wear();
        carry_object(__DIR__"obj/skirt2")->wear();
        carry_object(__DIR__"obj/bamboo_sword")->wield(); 
} 
void init()
{
       object ob; 
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        } 
}
void greeting(object ob)
{
        if( !ob || !present(ob, environment(this_object())) ) return;
        switch( random(2) ) {
                case 0:
                  say( "莲蓉对你微笑，和善的对你说：你是十年来进来的第一个外人。\n");
                        break;
                case 1:
                  say( "莲蓉对你微笑，轻轻地晃动着从薄纱中露出的白玉香肩 \n 说道：这位" +
RANK_D->query_respect(ob)
                   + "，你好！欢迎来到邸园！\n");
        }
}        
