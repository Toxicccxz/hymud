#include <ansi.h>
//inherit "/d/taiping/npc/smart_npc";  
inherit NPC;
void create()
{
    set_name("飞天蜘蛛",({"feitian zhizhu","feitian","zhizhu" }));
//    set("title","虬髯巨汉");
    set("long","这人身手之快，做事之周到，当真不愧‘细若游丝，快如闪电’这八个字。\n");
        set("gender","男性");
        set("age",32);
                
        set("int",22);
        set("cor",30);
        set("cps",20);
        set("str",40);
                set("neili",1500);
        set("max_neili",1500);
        set("force_factor",120);
        set("max_atman",500);
        set("atman",500);
        set("max_mana",500);
        set("mana",500);
        set("combat_exp",4000000);  
set("class", "bat");
        
           set_skill("force", 120);
    set_skill("bibo-force", 100);
    set_skill("blade", 220);
    set_skill("wind-blade", 220);
    set_skill("unarmed", 150);
    set_skill("dodge", 150);
    set_skill("luoriquan", 220);
    set_skill("move", 320);
    set_skill("fengyu-piaoxiang", 320);
    set_skill("parry", 120);
    set_skill("literate",180);
    set_skill("stealing",320);
    
    map_skill("blade"  , "wind-blade");
    map_skill("force"  , "bibo-force");
    map_skill("unarmed", "luoriquan");
    map_skill("dodge"  , "fengyu-piaoxiang");
    map_skill("move"  , "fengyu-piaoxiang");


        
        set("attitude", "friendly");               
       // set("death_msg",CYN"\n$N懊悔不已：“我。。就是。。。。。太。。懒了。。。”\n"NOR);          
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([ 
        ]) );           
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
        	          (: perform_action, "unarmed.luori" :),

        }) );
       /* set("chat_chance",1);
        set("chat_msg",({
                "乐先生正色道：“洗澡最伤元气，那是万万洗不得的。”\n"
        }) );                   */
           
//        CHAR_D->setup_char(this_object());
//        auto_npc_setup("wang",200,160,0,"/obj/weapon/","fighter_w","lianxin-blade",2);
        
        setup();
        carry_object("/clone/misc/cloth")->wear();    
        
    
}
void die()
{
        object me, owner;
        if(objectp(me=query_temp("last_damage_from") ))     
        if(owner=me->query("possessed")) {
                me = owner;
        } 
        me->set_temp("wanma/杀客人a",1);
        ::die();
}  
