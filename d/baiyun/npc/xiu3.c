 // weitianpeng.c
#include <ansi.h> 
inherit NPC; 
void create()
{
        set_name("孙秀青", ({ "sun xiuqin","sun" }) );
        set("gender", "女性" );
        set("title", "峨嵋派 侠女" );
        set("nickname", HIR"三英四秀之"NOR );
        set("long",
"风姿绰约，一把佩剑令她看上去愈发英气勃勃，不让须眉。\n"
                );
        set("attitude", "peaceful");
        set("age", 27);
        set("cps", 40);
        set("int", 50);
        set("per", 30);
        set("cor", 40);
        set("agi", 30);
        set("combat_exp", 100000);
        
        set("force", 500);
        set("max_neili", 500);
        set("mana", 1000);
        set("max_mana", 1000);
        set("force_factor", 10);
        set("inquiry",  ([
                "叶孤城" : "叶城主的飞仙剑法想必有独步天下之处，师傅也很是佩服啊。\n",
                "master ye" : "叶城主的飞仙剑法想必有独步天下之处，师傅也很是佩服啊。\n",
                  "西门吹雪" :"唉，西门公子能否赢得了叶城主？这紫禁之战真让人挂怀。。\n",
                  "master ximen" :"唉，西门公子能否赢得了叶城主？这紫禁之战真让人挂怀。。\n",
        ])                      );
       set_temp("apply/armor",50);
        set_temp("apply/attack", 50);
        set("chat_chance", 1);
        set("chat_msg", ({
                "孙秀青眉头微皱，轻轻理了理被海风吹散的长发。。\n",
                }) ); 
    set_skill("persuading", 550);
        set_skill("throwing", 200);
        set_skill("force", 200);
        set_skill("dodge", 200);
        set_skill("finger", 200);
        set_skill("parry", 200);
        set_skill("strike", 200);
        set_skill("sword", 250);
        set_skill("blade", 200);
        set_skill("literate", 100);
        set_skill("mahayana", 500);
        set_skill("buddhism", 250);
        set_skill("jinding-zhang", 300);
        set_skill("tiangang-zhi", 300);
        set_skill("huifeng-jian", 300);
        set_skill("yanxing-dao", 300);
        set_skill("zhutian-bu", 300);
        set_skill("linji-zhuang", 250);
        map_skill("force","linji-zhuang");
        map_skill("finger","tiangang-zhi");
        map_skill("dodge","zhutian-bu");
        map_skill("strike","jinding-zhang");
        map_skill("sword","huifeng-jian");
        map_skill("blade","yanxing-dao");
        map_skill("parry","huifeng-jian");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.mie" :),
                (: perform_action, "sword.sanqing" :),
                (: perform_action, "sword.sanqing" :),
                (: perform_action, "strike.bashi" :),
                (: perform_action, "finger.lingkong" :),
                (: exert_function, "daxiao" :),
                (: exert_function, "fengyun" :),
                (: exert_function, "longhe" :),
                (: exert_function, "tiandi" :),                                
                (: exert_function, "zhixin" :), 
        }) ); 
                
        setup(); 
        carry_object("/clone/weapon/changjian")->wield();
        add_money("gold",1);
        carry_object(__DIR__"obj/w_skirt3")->wear();
}    
