inherit NPC;
#include <ansi.h>
void create()
{
        set_name("马芳玲", ({ "ma fangling" }) );
        set("gender", "女性" );
        set("age", 18);
        set("title", HIW "万马堂"NOR);
        set("str", 6);
        set("cor", 24);
        set("cps", 11);
        set("per", 27);
        set("int", 27);
        
        set("intellgent",1);
        set("attitude", "peaceful");
        set("chat_chance", 50);
        set("chat_msg", ({
                (: random_move :),
        }) );
        set("fly_target",1);
        set("max_atman", 300);
        set("atman", 300);
        set("max_neili", 500);
        set("neili", 500);
        set("max_mana", 300);
        set("mana", 300); 
        set("long",     "马空群的宝贝女儿。\n");  
        set("combat_exp", 999999); 
        set("combat_exp", 20000000);
        set("score", 200000);

        set_skill("parry", 120);
        set_skill("dodge", 120);
        set_skill("force", 100);
        set_skill("literate", 100);
	set_skill("sword", 100);
	set_skill("unarmed",80);
	set_skill("changquan",200);
	set_skill("feixian-steps",200);
	set_skill("feixian-sword",250);
	set_skill("jingyiforce",200);
        map_skill("dodge", "feixian-steps");
	map_skill("sword", "feixian-sword");
	map_skill("force", "jingyiforce");
	map_skill("parry", "feixian-sword");
	map_skill("unarmed", "changquan");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.tianwaifeixian" :),
                (: perform_action, "dodge.tianwaifeixian" :),
        }) );
        
                
        setup(); 
        //carry_object(__DIR__"obj/stone")->wield();
        carry_object("/d/xinjiang/npc/obj/blackcloth")->wear();
} 
void die()
{
        int i;
        object killer,owner; 
        if(objectp(killer = query_temp("last_damage_from"))) {
             if(owner=killer->query("possessed")) killer = owner;
             killer->set_temp("wanma/杀马芳玲_ma", 1);
        }
        
        ::die(); 

}
