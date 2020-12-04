#include <ansi.h>
inherit NPC;
string  smart_fight( object who);
void create()
{
        set_name("黄衣卫统领", ({ "guard leader"}) );
        set("gender", "男性" );
        set("age", 42);
        set("class","assassin");
        set("long", "这是一位金钱帮总舵的黄衣卫统领。\n");
//        set("vendetta_mark","jinqian");
        set("combat_exp", 1500000);
        set("attitude", "friendly");
        
        set("max_neili",500);
        set("neili",500);
        set("force_factor",30); 
          set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.duxin" :),
		(: perform_action, "sword.sharenruma" :),
		(: perform_action, "dodge.canglongyixian" :),
        }) );

        set_skill("dodge", 50);
        set_skill("parry", 60);
        set_skill("dodge", 60);
        set_skill("force", 60);
        set_skill("literate", 30);
	set_skill("jingxing",160);
	set_skill("sword", 90);
	set_skill("jinhong-steps",160);
	set_skill("lefthand-sword",200);
	set_skill("sharen-sword",250);
        map_skill("dodge", "jinhong-steps");
	map_skill("sword", "sharen-sword");
	map_skill("force", "jingxing");

        
        set("chat_chance", 1);
        set("chat_msg", ({
                "黄衣统领喝道：没有帮主的口喻，谁都不准通过。\n",
        }) );
   
        setup();
        add_money("coin", 5);
        carry_object(__DIR__"obj/tangfu")->wear();
        carry_object("/clone/weapon/gangjian")->wield();
} 
string smart_fight(object who)
{
        int i;
        object *enemy;
        enemy = this_object()->query_enemy();
        i = sizeof(enemy);
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                if (enemy[i]->query_skill("iron-cloth")>200) {
                        if (this_object()->query_temp("weapon")){
                        command( "say 好厉害的硬功！会一会我的烈焰寒冰掌！");
                        command("unwield sword");
                        }
                } else  command("wield sword");
                if (enemy[i]->query_temp("till_death/lockup"))
                        command("perform duxin" );
                        else command("perform dodge.canglongzhaxian");
        }
        }
        return "1";
}  
int accept_object(object who, object ob)
{
                if( (int)ob->value() >= 50000 ) {
                        say( name()+"偷偷将"+ob->name()+"放入怀内，笑道：啊？？客气客气。\n");
                        who->set_temp("jinqian", 1);
                        return 1;
                } else {
                        command("puke");
                        return 0;
                }
        return 0;
}  