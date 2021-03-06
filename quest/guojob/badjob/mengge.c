// guojing.c 蒙哥
inherit NPC;
#include <ansi.h>
#include "menggujob.c"
//#include "teamjob.c"
string ask_newjob();
string ask_newover();
int job_over(string arg);

void create()
{
	set_name("蒙哥", ({"meng ge", "mengge", "ge"}));
	set("nickname", HIR"蒙古大汗"NOR);
	set("gender", "男性");
	set("age", 31);
	set("long", 
		"他是亲自来攻城的蒙古大汗，面目中透出一股杀气。此次带兵南来，势如破竹，兵锋毕露。\n");
	set("attitude", "friendly");
	set_max_encumbrance(100000000);
	set("per", 140);
	set("str", 140);
	set("int", 140);
	set("con", 140);
	set("dex", 140);
        set_temp("no_kill",1);
	set("chat_chance", 1);
	set("chat_msg", ({
		"蒙哥叹了口气道：“蒙古大军久攻襄阳不下,看来要靠武林人士为我们效力了!!\n",
	}));

	set("inquiry", ([
		 "job"   : (: ask_job :),
                 "fangqi": (: ask_fangqi :),
                "放弃"  : (: ask_fangqi :),
		]));

	set("qi", 28000);
	set("max_qi", 28000);
	set("jing", 28000);
	set("max_jing", 28000);
	set("neili", 28000);
	set("max_neili", 28000);
	set("jiali", 500);
	
	set("combat_exp", 8250000);
	set("score", 200000);
	 
        set("combat_exp", 3500000+random(900000));
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "blade.leitingpili" :),
                (: perform_action, "blade.kuang" :),
        }) );

        set_skill("unarmed", 580+random(180));
        set_skill("blade", 580+random(180));
        set_skill("parry", 580+random(180));
        set_skill("dodge", 580+random(180));
        set_skill("kuang-blade", 580+random(180));
        
        map_skill("blade", "kuang-blade");
        map_skill("parry", "kuang-blade");
        set_temp("apply/attack", 200);
        set_temp("apply/defense",200);
        set_temp("apply/armor", 950);
        set_temp("apply/damage", 920);

        setup();

        carry_object("quest/weiguo/menggu/obj/japancloth")->wear();
        carry_object("quest/weiguo/menggu/obj/japanblade")->wield();
}

