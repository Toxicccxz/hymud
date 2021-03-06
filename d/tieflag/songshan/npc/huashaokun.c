 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int jian(); 
void create()
{
    set_name("华少坤", ({ "hua shaokun", "hua" }) );
    set("nickname", HIC"游龙剑客"NOR);
    set("title", "名门之後"NOR);
    set("gender", "男性" );
        set("class","huashan");
    set("reward_npc", 1);
    set("difficulty", 30); 
    set("age", 50);
    set("cor", 30);
    set("cps", 80);
    set("con", 80);
    set("str", 80);
    set("dur", 80);
    set("int", 30);
    set("per", 30);
    set("attitude","friendly");
    
    set("resistance/kee",90);
    set("resistance/sen",90);
    set("resistance/gin",90);
    
    set("max_neili", 5000);
    set("neili", 5000);
    set("force_factor", 200);
    set("max_mana",4000);
    set("mana",4000);
    
    set("long",
        "二十年前，力战武当的八大弟子得意青年，现在已经是个白发苍苍的老者，
但他腰肢也还是笔直的，身上缠着个长长的黄布袋。\n");
    set("rank_nogen",1);
    /*create_family("神剑山庄", 1, "庄主");
    set("ranks",({"剑奴","剑手","剑士","剑侠","剑王","剑帝","剑圣","剑魂",
                      "剑罡","剑煞","剑仙","剑神"}));
    set("rank_levels",({ 32000,64000,128000,256000,512000,
                             1024000,1536000,2304000,3456000,
                             5187000,26244000 }));     */
    set("combat_exp", 10000000);
   set("qi", 39800);
	set("max_qi", 39800);
	set("jing", 38600);
	set("max_jing", 38600);
	set("neili", 54400);
	set("max_neili", 54400);
	set("jiali", 200);

	set("combat_exp", 15050000);
	set("score", 200000);

	set("fengset",1);
	set_skill("cuff", 250);
	set_skill("force", 280);
	set_skill("blade", 200);
	set_skill("dodge", 180);
	set_skill("parry", 200);
	set_skill("sword", 380);
	set_skill("strike", 250);
	set_skill("kuangfeng-jian", 380);
	set_skill("zixia-shengong", 380);
	set_skill("zixia-shengong", 380);
	set_skill("ziyunyin", 380);
	set_skill("zhengqijue", 380);
	set_skill("fanliangyi-dao", 380);
	set_skill("huashan-sword", 380);
	set_skill("hunyuan-zhang", 380);
	set_skill("lonely-sword", 380);
	set_skill("feiyan-huixiang",380);
	set_skill("literate", 200);
        set_skill("zhengqijue",380);
        set_skill("hunyuan-zhang", 380);
        set_skill("poyu-quan", 380);        
        set_skill("huashan-neigong", 380);        
        set_skill("chongling-jian", 380);
        set("fengset",1);
	map_skill("cuff", "poyu-quan");
	map_skill("force", "zixia-shengong");
	map_skill("dodge", "feiyan-huixiang");
	map_skill("parry", "lonely-sword");
	map_skill("sword", "lonely-sword");
	map_skill("blade", "fanliangyi-dao");
	map_skill("strike", "hunyuan-zhang");


	set_temp("apply/attack",150);
	set_temp("apply/defense",150);
	set_temp("apply/armor",500);
	set_temp("apply/damage",400);
	set("chat_chance_combat", 90);
	set("chat_msg_combat", ({
		(: perform_action, "sword.wanjian" :),
		(: perform_action, "sword.jiushi" :),
		(: perform_action, "sword.pozhao" :),
		(: perform_action, "sword.poqi" :),
		(: perform_action, "sword.pozhang" :),
		(: perform_action, "sword.pojian" :),
		(: perform_action, "sword.podao" :),
		(: perform_action, "sword.zongjue" :),
	}) );
        set("inquiry", ([
                "谢晓峰": (: jian()  :),
                "master xie": (: jian()  :),
        ]) );
            set("chat_chance", 10);
            set("chat_msg", ({
            	"华少坤叹了口气，谢晓峰果然是谢晓峰。。。\n",
                (: random_move :),
        }) );

    setup();
    carry_object("/d/fugui/npc/obj/m_cloth4")->wear();
    carry_object(__DIR__"obj/gunsword")->wield();
} 
void init() {
        ::init();
        add_action("do_answer","answer");
 }  
int jian() {
        object me;
        me=this_player();
        command("hmm");
        command("say 你找的可是神剑山庄的谢叁少？（answer yes/no）");
        me->set_temp("songshan/ask_hua",1);
        return 1;
} 
int do_answer(string arg)
{
        
          if(arg == "yes" ) {
                if (!this_player()->query_temp("songshan/ask_hua")) {
                        command("say 是甚麽？你在跟我说话麽？");
                        return 1;
                }
                command("sigh");
                command("say 何必去送死呢。。。也好，成全你吧。\n");
                this_player()->delete_temp("songshan/ask_hua");         
                 message_vision("$N突然伸手点住$n身上所有穴道，顺势一捉，提着$n踏树而去。\n",this_object(),this_player());
                 this_player()->unconcious();
                this_player()->move("/d/shaolin/guangchang1");
                destruct(this_object()); 
                return 1;
        }
        if(arg == "no" ) {
                if (!this_player()->query_temp("songshan/ask_hua")) {
                        command("say 甚麽不是？你在跟我说话麽？");
                        return 1;
                }
                command("heng");
                command("say 闲杂人等，你也配问起谢晓峰？！\n");
                return 1;
        }  
       
}  

