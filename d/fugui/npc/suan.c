 // suan.c
#include <ansi.h> 
inherit NPC; 
void create()
{
        set_name("酸梅汤", ({ "suanmei tang","tang" }) );
        set("gender", "女性" );
        set("vendetta_mark","fugui");
        set("age", 24);
        set("str", 22);
        set("cor", 30);
        set("cps", 30);
        set("int", 26);
        set("per", 23);
        set("con", 24);
        set("spi", 30);
        set("kar", 25);
        set("no_arrest",1);
        set("long",
"酸梅汤非但漂亮，而且漂亮极了。她身上穿的虽然是件粗布衣服，但无\n论什么衣服穿在她身上，都会变得很好看。\n\n"); 
        set("combat_exp", 500000);
        set("attitude", "friendly");
        set("max_neili", 300); 
        set("force", 600);             
        set("force_factor", 10);
  set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.tianwaifeixian" :),
        }) ); 
        set("combat_exp", 4000000);
        set_temp("apply/damage",30);
        set_skill("unarmed", 100);
        set_skill("force",100);
        set_skill("parry",180);
        set_skill("dodge", 200);
        set_skill("move",200);
        set_skill("sword",100);
        set_skill("feixian-sword",540);
        set_skill("feixian-steps",540);
        set_skill("jingyiforce",100);
        set_skill("literate",100);
        map_skill("sword","feixian-sword");
        map_skill("dodge","feixian-steps");
        map_skill("move","feixian-steps");
        map_skill("force","jingyiforce"); 
        set("chat_chance",2);
        set("chat_msg", ({
        "酸梅汤似乎在四处寻找着些什么，喃喃自语道：“奇怪，前些日子我\n明明把那几箱财宝藏在这柴房的呀。”\n\n",
                                })  );
        setup();
        
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/gangjian")->wield();
} 
void init()
{
        object  ob;
        ::init();
        ob = this_player();
        call_out("greeting", 1, ob);       
}  
int greeting(object ob)
{
        if (!random(10))
                message_vision("$N皱着眉头，用袖子挡着脸埋怨道：“这柴房也实在脏到家了，\n哦，麻烦这位"+RANK_D->query_respect(ob)+"帮我打扫一下,好么？”\n",this_object());
        return 1;
}   
