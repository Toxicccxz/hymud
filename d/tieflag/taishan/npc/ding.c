#include <ansi.h>
inherit NPC;
int showpower();
int wieldblade();
void create()
{
        set_name("丁鹏", ({ "ding peng" }) );
        set("gender", "男性");
        set("age",35);
        set("combat_exp", 3900000);
        set("reward_npc", 1);
        set("class","bandit");
        set("fly_target",1);
        set("intellgent",1);
        set("difficulty", 50);
        set("no_busy", 50);
        set("moonblade", 5);
        set("long",
                "丁鹏已经变了，已经不是以前那个冲动无知的年轻人。现在不但
成熟而稳重，而且带着种超越一切的自信。\n"
        );
        set("max_neili",53000);
        set("neili",53000);
        set("force_factor",30);
        set("str", 50);
        set("dex", 50);
        set("con", 50);
        set("int", 50);
        set("per", 50);
        set("per",23);
        set("tianyu_1",1);
        set("jing", 20000);
        set("eff_jing", 20000);
        set("max_jing", 20000);        
        set("qi", 22000);
        set("eff_qi", 22000);
        set("max_qi", 22000);
        set("max_jingli", 22000);
        set("neili", 40000);
        set("max_neili", 40000);
        set("max_jingqi",1000);
        set("combat_exp", 9000000);
        set_skill("dodge",300);
        set_skill("cuff",320);
        set_skill("unarmed",300);
        set_skill("parry",300);
        set_skill("blade",380);

         set_skill("wuxing-dun",280);
        set_skill("shayi",280);
         set_skill("aikido",280);
         set_skill("shayi-xinfa",320);
        set_skill("shiren-jianfa",280);
        set_skill("shiren-quanfa",280);
        set_skill("force",300);
set_skill("huoxinliu-jianfa",180);

set_skill("xuanhualiu-quanfa",280);
set_skill("ninjitsu",380);
set_skill("ittouryu",380);
set_skill("enmeiryu",380);
set_skill("hand",320);
        set_skill("literate",250);
        map_skill("blade", "ittouryu");
        map_skill("force", "shayi-xinfa");
        
        map_skill("dodge", "wuxing-dun");
        map_skill("parry", "shiren-jianfa");
        
        map_skill("hand", "enmeiryu");
        map_skill("cuff", "xuanhualiu-quanfa");
	prepare_skill("cuff", "xuanhualiu-quanfa");
	prepare_skill("hand", "enmeiryu");
        
       // create_family("飞天御剑流", 5, "家督");
         set("chat_chance_combat", 98);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.break" :),
                (: perform_action, "hand.mukuha" :),
                (: perform_action,"hand.shiden" :),
                (: perform_action, "hand.shimon" :),  
                (: perform_action, "hand.chuyao" :), 
                (: perform_action, "hand.linfengguilong" :), 		
                (: perform_action, "blade.gobankiri" :), 
                (: perform_action, "blade.hyakki" :), 
                (: perform_action, "blade.daoshen" :), 
                (: perform_action, "blade.shiwanshenmo" :), 
                (: exert_function, "berserk" :),
                (: exert_function, "durup" :),
                (: exert_function, "shayi" :),
                (: exert_function, "shenzu" :),	
                (: exert_function, "powerup" :),		
        }));
        setup();
   carry_object("/clone/misc/cloth")->wear();
        carry_object(__DIR__"obj/wandao")->wield();
}
int showpower()
{
command("wield moonblade");
tell_object(environment(this_object()),"可是这把刀已出鞘。刀光一闪，
带着种奇异的弧度，往路边的青石劈了下去。那块看来比钢铁
还硬的青石，竟然在刀光下被劈成两半！\n");
command("unwield moonblade");
return 1;
}
int wieldblade()
{
command("wield moonblade");
perform_action("blade.yuanyue");
command("unwield moonblade");
return 1;
}
