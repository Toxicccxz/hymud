 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
#include <ansi.h>
inherit F_MASTER; 
void create()
{
        set_name("小慕容", ({ "mu rong","mu","rong"}) );
        set("gender", "女性" );
        set("age",18);
        set("long", "一个活泼伶俐的黄山派弟子。\n");
        create_family("黄山派", 5, "弟子");
        set("combat_exp", 2500000);
        set("attitude", "friendly");
        set("skill_public",1);        
        set_skill("unarmed", 160);
        set_skill("blade", 200+random(50));
        set_skill("sword", 200+random(50));
        set_skill("force", 180);
        set_skill("move", 160);
        set_skill("literate", 150);
        set_skill("dodge", 160);
        set_skill("meihua-shou", 130+random(20));
        set_skill("parry",160);

        set_skill("huashan-sword",random(100));
        
        map_skill("unarmed","meihua-shou");
        map_skill("sword","huashan-sword");
        
        set("chat_chance", 1);
        set("chat_msg", ({
                name()+"说道：师傅最喜欢我了．．．\n",
        }) );
        
        set("max_neili",1000);
        set("neili",1000);
        set("force_factor",60);
        
   setup();
        carry_object("/clone/misc/cloth")->wear();
} 
void init()
{       
        object me;
        ::init();
        if( interactive(me = this_player()) && !is_fighting())
        if (me->query("marks/黄山学艺") && me->query("class")=="legend") {
                remove_call_out("greeting");
                call_out("greeting", 1, me);
        }   
} 
int greeting(object me)
{
    message_vision(CYN"$N说：去年我到你们那儿，铁少奶奶教了我几招，你看成不成？\n"NOR,this_object());
    message_vision(CYN"$N说：你多呆几天吧,师傅说我们可以互相学学。\n"NOR,this_object());  
    return 1;
} 
int recognize_apprentice(object ob)
{
        if (ob->query("marks/黄山学艺") && ob->query("class")=="legend") {
                return 1;
        }   
        return 0;
} 
