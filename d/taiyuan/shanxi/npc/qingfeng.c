// hu.c
inherit NPC;
#include <ansi.h>
int wieldblade();
 
void create()
{
        set_name("顾青枫", ({ "gu qingfeng", "qingfeng" }) );
        set("gender", "男性" );
        set("age", 52);
        set("str", 30);
        set("str", 111);
        set("cor", 40);
        set("cps", 1);
        set("no_busy", 10);
                 set("reward_npc", 1);
        set("difficulty", 35);

        set("class","huashan");
            set("resistance/kee",99);
    set("resistance/sen",99);
    set("resistance/gin",99);

    set("long",
"这黄袍道人宽袍大袖，两鬃已斑白瘦消清矍的脸上，带着种很严肃的表情，脚步
虽然很轻健，看来却不像练武功的样子。 \n"
    );
        set("force_factor", 100);
        set("combat_exp", 7000000+random(3000000));
        set("attitude", "friendly");
	set("max_qi", 38000);
	set("max_jing", 38000);
	set("neili", 98000);
	set("max_neili", 98000);
	set("jiali", 150);
	set("combat_exp", 9800000);
	set("score", 500000);
 set_temp("fanzhen",1);
	set_skill("buddhism", 500);
	set_skill("literate", 300);
	set_temp("apply/attack",150);
	set_temp("apply/defense",150);
	set_temp("apply/armor",500);
	set_temp("apply/damage",400);
	set_skill("unarmed", 300);
	set_skill("blade", 300);
	set_skill("claw", 300);
	set_skill("club", 300);
	set_skill("cuff", 300);
	set_skill("dodge", 300);
	set_skill("finger", 300);
	set_skill("force", 300);
	set_skill("hand", 300);
	set_skill("parry", 300);
	set_skill("staff", 300);
	set_skill("strike", 300);
	set_skill("sword", 300);
	set_skill("whip", 300);

set_skill("weituo-zhang", 380);
set_skill("shaolin-tantui", 380);
set_skill("jingang-zhang", 380);
set_skill("jimie-zhua", 380);
set_skill("duoluoye-zhi", 380);
set_skill("mohe-zhi", 380);
set_skill("boluomi-shou", 380);
	set_skill("banruo-zhang", 380);
	set_skill("cibei-dao", 380);
	set_skill("damo-jian", 380);
	set_skill("fengyun-shou", 380);
	set_skill("fumo-jian", 380);
	set_skill("hunyuan-yiqi", 380);
	set_skill("jingang-quan", 380);
	set_skill("longzhua-gong", 380);
	set_skill("luohan-quan", 380);
	set_skill("nianhua-zhi", 380);
	set_skill("pudu-zhang", 380);
	set_skill("qianye-shou", 380);
	set_skill("sanhua-zhang", 380);
	set_skill("riyue-bian", 380);
	set_skill("shaolin-shenfa", 380);
	set_skill("weituo-gun", 380);
	set_skill("wuchang-zhang", 380);
	set_skill("xiuluo-dao", 380);
	set_skill("yingzhua-gong", 380);
	set_skill("yijinjing", 380);
	set_skill("yizhi-chan", 380);
	set_skill("zui-gun", 380);
	set_skill("weituo-chu", 380);
	set_skill("ranmu-daofa", 380);
	set_skill("wuying-jian", 380);
	map_skill("blade", "cibei-dao");
	map_skill("claw", "longzhua-gong");
	map_skill("club", "wuchang-zhang");
	map_skill("cuff", "jingang-quan");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("finger", "nianhua-zhi");
	map_skill("force", "yijinjing");
	map_skill("hand", "fengyun-shou");
	map_skill("parry", "nianhua-zhi");
	map_skill("staff", "weituo-gun");
	map_skill("strike", "sanhua-zhang");
	map_skill("sword", "wuying-jian");
	map_skill("whip", "riyue-bian");

	prepare_skill("finger", "nianhua-zhi");
	prepare_skill("strike", "sanhua-zhang");
        set("chat_chance_combat", 99);
        set("chat_msg_combat", ({
(: perform_action, "cuff.fumo" :),
	(: perform_action, "cuff.jin" :),
		(: perform_action, "cuff.jingang" :),
			(: perform_action, "cuff.qixing" :),
                (: perform_action, "finger.fuxue" :),
                (: perform_action, "sword.wuying" :),
                (: perform_action, "sword.lidichenfo" :),
                (: perform_action, "sword.ruying" :),
                 (: perform_action, "sword.foxing" :),	
                (: exert_function, "jiuyang" :),
                (: exert_function, "tong" :),
                (: exert_function, "roar" :),		 	
                (: exert_function, "chang" :),		 		
                (: exert_function, "jingang" :),		 			
        }) );
        set("chat_chance", 1);
        set("chat_msg", ({
                "青枫道人喃喃道，“世事无常，如白云苍狗，又有谁能想到，这一局残棋犹在，他的人却已经不在了。”\n",
                "青枫道人凄然而笑，“这一子摆下，黑棋就不输了。”\n",  
                "青枫道人忽然挥袖拂乱了这局残棋，悠悠慨叹，“人生岂非，也正如一局棋．输赢又何必太认真呢？”\n",
        }));
        //set("skill_public", 1);

        setup();
        carry_object("/clone/misc/cloth")->wear();
        //carry_object("/d/resort/npc/obj/bqi");
        
} 

int wieldblade()
{
command("wield piece");
perform_action("throwing.tanzhijinghun");
command("unwield piece");
return 1;
}
