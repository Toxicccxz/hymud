 inherit NPC;
void smart_fight();
void smart_busy();
void smart_attack(); 
void create()
{
        set_name("关东豪客", ({ "guandong haoke", "haoke" }) );
        set("gender", "男性" );
        set("age", 32+ random(10));
        set("long", "这是一位从白山黑水来的大汉，手下带着一群行旅商人。\n");
        set("combat_exp", 3200000);
        set("attitude", "aggrensive");
        set("class","knight");
        set("chat_chance", 1);
        set("chat_msg", ({
                "关东大汉豪爽得向你大笑！\n",
        }) );
        
        set("force",1200);
        set("max_neili",1200);
        set("force_factor", 30);
              
        set_skill("unarmed", 580);
        set_skill("dodge", 580);
        
        setup();

        carry_object("/clone/misc/cloth")->wear();
        carry_object(__DIR__"obj/xuechang");
} 
