 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors. 
inherit NPC;
#include <ansi.h>
void create()
{
        set_name("蒙面客", ({ "figure"}) );
        set("nickname", HIR "刀不留人"NOR);
        set("gender", "男性" );
        set("age", 41);
        set("per", 30);
        set("agi",25);
        set("int",30);
        set("cor",40);
        set("attitude","friendly");
        set("bellicosity",30000);
        set("cps",200);
        set("max_neili", 2000);
        set("neili", 2000);
        set("force_factor", 90);
        set("mana",2000);
        set("max_mana",2000);
        set("atman",500);
        set("max_atman",500);
        set("str",40);
        set("figure_friend",1);
        
        set("resistance/gin",50);
        set("resistance/kee",50);
        set("resistance/sen",50);
        
        set("long",
"这人的脸上戴着黑布面具，在星光下看来，显得狰狞而怪异。令人瞩目的是他的
腰带上斜插着一柄弯刀，刀鞘上缀满了明珠美玉。
\n"
        );
       set("qi", 25000);
	set("max_qi", 25000);
	set("jing", 22400);
	set("max_jing", 22400);
	set("neili", 58000);
	set("max_neili", 58000);
	set("jiali", 300);
	
	set("combat_exp", 8000000);
	set("score", 200000);
	set("shen", 100000);
	 
		set_skill("fengmo-zhang",380);
	set_skill("liuhe-zhang",380);
	set_skill("strike",390);
	set_skill("force", 300);             // 基本内功
	set_skill("huntian-qigong", 380);    // 混天气功
	set_skill("unarmed", 260);           // 基本拳脚
	set_skill("xianglong-zhang", 380);   // 降龙十八掌
	set_skill("dodge", 260);      	     // 基本躲闪
	set_skill("xiaoyaoyou", 380);        // 逍遥游
	set_skill("parry", 260);             // 基本招架
	set_skill("staff", 380);             // 基本棍杖
	set_skill("dagou-bang", 380);        // 打狗棒法
	set_skill("begging", 380);           // 叫化绝活
	set_skill("checking", 380);          // 道听途说
	set_skill("training", 380);         // 驭兽术
	
	map_skill("force", "huntian-qigong");
	map_skill("unarmed", "xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("parry", "dagou-bang");
	map_skill("staff", "dagou-bang");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "staff.chan" :),
                (: perform_action, "staff.ban" :),
                (: perform_action, "staff.feng" :),
                (: perform_action, "staff.zhuan" :),
                (: perform_action, "staff.luanda" :),
                (: perform_action, "staff.luanda" :),
                (: perform_action, "staff.luanda" :),
                (: perform_action, "staff.wugou" :),                
                (: command("unwield yuzhu zhang") :),
                (: command("wield yuzhu zhang") :),
                (: perform_action, "unarmed.kanglongwuhui" :),                
                (: perform_action, "unarmed.kanglongwuhui" :),                
                (: perform_action, "unarmed.kanglongwuhui" :),                
                (: perform_action, "unarmed.hui" :),                
                (: perform_action, "unarmed.fei" :),                
                (: perform_action, "unarmed.qu" :),                
                (: perform_action, "unarmed.zhen" :),                
                (: perform_action, "unarmed.leiting" :),                
                (: perform_action, "unarmed.xianglong" :),                                
                (: perform_action, "dodge.canghaiyixiao" :),                                
                (: perform_action, "dodge.maishou" :),                                
        }) );
        
        setup();
        carry_object("/clone/misc/cloth")->wear();
        //carry_object("/obj/weapon/sword_katana")->wield();
                
} 
void init()
{
        object ob; 
        ::init();
        add_action("do_get","get");
        if( interactive(ob = this_player())) 
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
} 
void greeting(object ob)
{   
        if( !interactive(ob) || environment(ob) != environment() ){
           return;
        }
        if (!ob->query("figure_friend")){
            message_vision("$N叫道：杀！\n", this_object() );
                this_object()->kill_ob(ob);
                ob->kill_ob(this_object());
        }
        return;
} 
int do_get(string arg)
{
if(!arg) return 0;
message_vision("$N笑道：没有这么便宜的事吧？\n",this_object(),this_player());
if (!this_player()->is_busy()) this_player()->start_busy(1);
return 1;
}     
