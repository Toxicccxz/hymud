#include <ansi.h>
inherit NPC;
void goto_batdao(object ob);
void create()
{
    set_name("小铃儿", ({ "xiao linger", "linger" }));
    set("long", "她身材娇小，漆黑的长发娩成一对垂髻，闪亮著的大眼中充满好奇。\n" );
        set("title", "华山派 第十七代弟子");
        set("gender", "女性");
        set("age", 13);
        set("per", 27);
        set("str", 30);
        set("int", 24);
        set("con", 25);
        set("agi", 20);
//      set("max_qi", 600);
//      set("max_jing", 600);
        set("neili", 1000);
        set("max_neili", 800);
        set("force_factor", 50);
        set("combat_exp", 80000+random(50000));
        set("attitude", "friendly");
        set("chat_chance", 5);
        set("chat_msg", ({
                "小铃儿小声说：“我师傅晚上练功夫，一把就抓进树干了耶。” \n",
                "小铃儿自言自语道：“华真真师姐好像在教师傅功夫，真是奇怪呀。”\n", 
                "小铃儿道：“华师姐喜欢在晚上弹琴的。”\n", 
        }) ); 
        set_skill("unarmed", 43);
        set_skill("move", 50);
        set_skill("dodge", 45);
        set_skill("parry", 35);
        set_skill("force", 49);
        set_skill("sword", 30);
      set("neili", 36400);
        set("max_neili", 36400);
        set("jiali", 50);
        set("max_qi",18200);
        set("max_jing",15200);

        set("combat_exp", 5400000);
        set("shen", 20000);
        set_temp("xunshan", 200);
        set("apprentice_available", 3);

        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.jm" :),
                (: perform_action, "sword.jianzhang" :),
                (: perform_action, "sword.jie" :),
                (: perform_action, "sword.xian" :),                
                (: perform_action, "dodge.huiyanfeiwu" :),                
                (: exert_function, "powerup" :),
        }) );


        set_skill("unarmed", 180);
        set_skill("sword", 290);
        set_skill("force", 200);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("literate", 200);
        set_skill("huashan-sword", 290);
        set_skill("zixia-shengong", 320);
        set_skill("hunyuan-zhang", 290);
        set_skill("poyu-quan", 290);
        set_skill("feiyan-huixiang", 290);
        set_skill("pixie-sword",280);
        set_skill("zhengqijue",200);

        map_skill("sword", "huashan-sword");
        map_skill("parry", "huashan-sword");
        map_skill("force", "zixia-shengong");
        map_skill("unarmed", "huashan-ken");
        map_skill("dodge", "feiyan-huixiang");
        setup();
    carry_object(__DIR__"obj/gcloth")->wear();
    carry_object("/clone/weapon/gangjian")->wield(); 
}
