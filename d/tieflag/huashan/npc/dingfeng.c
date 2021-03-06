#include <ansi.h>
inherit NPC;
void goto_batdao(object ob);
void create()
{
    set_name("丁枫", ({ "ding feng", "ding", "feng" }));
    set("long", "
这轻衫少年袍袖飘飘，不但神情很潇洒，人也长得很英俊，
脸上更永远都带着笑容。\n" );
 set("nickname", HIC "玉树临风"NOR);
 set("gender", "男性");
 set("age", 27);
 set("str", 25);
 set("int", 24);
 set("con", 25);
 set("qi", 1000);
 set("max_qi", 1000);
 set("jing", 1000);
 set("max_jing", 1000);
 set("neili", 2500);
 set("max_neili", 1000);
 set("force_factor", 50);
 set("combat_exp", 800000);
 set("attitude", "friendly");
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
        
         set("chat_chance", 1);
 set("chat_msg", ({
"丁枫喃喃道：华山派这一套“清风十三式”的确是曼妙无铸，非人能及，
连昆仑的“飞龙大九式”都自愧不如。\n ",
"丁枫微笑道：“清风十三式”妙就妙在“清淡”两字,讲究的正是：似有似无，
似实似虚，似变未变 。\n",
 }) );
 set("inquiry",([
  "清风十三式" : "此书乃华山震山之宝，可是却失传了，唉！\n",
 ]) );
 set_skill("unarmed", 70);
   set_skill("move", 100);

        setup();
    carry_object("/clone/misc/cloth")->wear();
    carry_object("/clone/weapon/gangjian")->wield(); 
}    
