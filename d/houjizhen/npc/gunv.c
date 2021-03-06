// gunu.c 
// dicky.c


#include <ansi.h>;
inherit NPC;

void create()
{
	set_name("孤女", ({ "gu nv", "girl"}));
	set("nickname", HIG"天涯孤女"NOR);
	set("long", 
"孤女固执地守在客栈外，眼睛死死的盯着客栈里面正在吃喝的人群。\n"
"每个人都会坚持自己的信念，在别人看来，是浪费时间，她却觉得很重要。\n");
	set("gender", "女性");
	set("age", 28);
	set("title", HIB"靖海遗孤"NOR);
	set("attitude", "heroism");
	set("shen_type", 1);
	set("str", 30);
	set("int", 40);
	set("con", 30);
	set("dex", 30);	
        set("per", 21);

        set("combat_exp", 800000);
        set("combat_exp", 6500000);
        set("per", 29);
        set("str", 35);
        set("max_qi",35000);
        set("max_jing",35000);
        set("max_sen",35000);
        set("neili", 50000);
        set("max_neili", 50000);
        set("atman", 50000);
        set("max_atman", 50000);
        set("mana", 50000);
        set("max_mana", 50000);
        set("force_factor", 350);




set_skill("jinshe-jian",380);
set_skill("liancheng-jian",380);
set_skill("hujia-daofa",380);


set_skill("ningxue-shenzhua",380);
set_skill("tiexian-quan",380);
set_skill("demon-strike",380);
set_skill("nine-moon-claw",380);
set_skill("ill-quan",380);
set_skill("doomstrike",380);
set_skill("deisword",380);
set_skill("cloudstaff",380);
set_skill("siqi-sword",380);
set_skill("sharen-sword",380);
set_skill("chaos-steps",380);
set_skill("longfenghuan",380);
set_skill("blood-sword",380);
set_skill("luoriquan",380);
set_skill("jueqing-bian",380);
set_skill("qinnashou",380);
set_skill("taixuan-gong",380);

        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 600);
        set_temp("apply/damage", 650);
        set_skill("jingyiforce",380);
        set_skill("demon-blade",280);
        set_skill("literate",380);
        set_skill("unarmed",380);
        set_skill("dodge",290);
        set_skill("parry",280);
	set_skill("force",380);
	set_skill("blade",280);
	set_skill("changquan",380);
        //set_skill("doomsword",380);
        //set_skill("chilian-shenzhang",380);
        //set_skill("softsword",280);
        //set_skill("nine-moon-sword",380);
        set_skill("luohua-jian",380);
        set_skill("sword",380);
        set_skill("feixian-sword",380);
        set_skill("bat-blade",380);
        set_skill("fengyu-piaoxiang",390);

        map_skill("unarmed","changquan");
        map_skill("sword","jinshe-jian");
        map_skill("force","taixuan-gong");
        map_skill("dodge","fengyu-piaoxiang");
        map_skill("parry","liancheng-jian");
      set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: exert_function, "hun" :),
                (: exert_function, "jing" :),
                (: exert_function, "po" :),
                (: exert_function, "taixuan" :),		
                (: exert_function, "xuan" :),			
                (: perform_action, "unarmed.yuhuan" :),
                (: perform_action, "sword.kuangwu" :),
                (: perform_action, "sword.wan" :),
                (: perform_action, "sword.kun" :),	
                (: perform_action, "sword.shi" :),	
                (: perform_action, "sword.suo" :),	                	
                (: perform_action, "parry.ci" :),
                (: perform_action, "parry.erguang" :),
(: perform_action, "parry.gan" :),
(: perform_action, "parry.qian" :),
(: perform_action, "parry.qu" :),		             
(: perform_action, "parry.zhai" :),		             
(: perform_action, "parry.zhu" :),		             	             
(: perform_action, "dodge.zonghengsihai" :),		             	             
(: perform_action, "dodge.zonghengsihai" :),		             	              
        }) );

	set("chat_chance", 1);
	set("chat_msg", ({
		"孤女恨恨的说道:为了了却百般莫解的仇怨，我宁愿在这里等一辈子。\n",
	}) );
	set("inquiry", ([
		"理由" : "杀一人需要理由么？等你爱上一个人，你就能体会这道理！\n",
		"拒绝" : "从小我就懂得保护自己，我知道要想不被人拒绝，最好的办法就是先拒绝别人。\n",
		"分离" : "我曾经听人说过，当你不能够再拥有的时候，你唯一可以做的就是令自己不要忘记。\n",
		"爱情" : "你最爱的女人是不是我？但是我现在已经不想知道。如果有一天我忍不住问你，你一定要骗我。就算你心里多不情愿，也不要告诉我你最爱的人不是我。\n",
	]));

        setup();

        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/gangjian")->wield();
}


