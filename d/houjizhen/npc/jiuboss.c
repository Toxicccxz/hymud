// jiuboss.c
// by dicky

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("梅世杰", ({ "mei shijie", "boss" }));
	set("title", "酒馆老板");
	set("shen_type", 1);
	set("gender", "男性");
	set("age", 50);
	set("per", 10);
	set("long",
		"\n他神情比较冷淡，左腿有点跛，走起路来一瘸一瘸。\n");

        set("max_sen",4000);
        set("max_qi", 4000);
        set("qi", 4000);
	set("max_jing", 4000);
	set("jing", 4000);
	set("max_neili", 400);
	set("neili", 400);
	set("force_factor", 40);

	set("combat_exp", 200000);
	set_skill("force", 200);
	set_skill("dodge", 200);
	set_skill("unarmed", 200);
	set_skill("parry", 200);

	set_temp("apply/attack", 35);
	set_temp("apply/attack", 35);
	set_temp("apply/damage", 25);
	set("combat_exp", 400000);
	set("attitude", "friendly");
	set("chat_chance", 1);
	set("chat_msg", ({
	"梅世杰忽然说：不知道什么时候这里才有个安宁。\n",
	"梅世杰忽然说：唉，我的脾气不大好，大家可要小心了。\n",
	}));

        set("inquiry", ([
		"here" :  "这里都不知道是什么地方，等你见了阎王就知道了。\n",
		"酒与水" :  "你知道喝酒跟喝水的分别吗？酒，越喝越暖，水会越喝越寒。。\n",
		"杀人" :  "\n总有些事你是不愿再提，或是有些人你不想再见，有的人曾经对不起你，也许你\n想过要杀了他们，但是你不敢。哈，又或者你觉得不值，其实杀人，很容易。我\n有个朋友，他的武功非常好，不过最近生活有点困难，只要你随便给他一点银两\n，他一定可以帮你杀了那个人，你尽管考虑一下。其实杀一个不是很容易，不过\n为了生活，很多人都会冒这个险，不知道你愿意么(decide)？\n",
       ]) );

	setup();
        add_money("silver", 10);
        carry_object("/clone/misc/cloth")->wear();
}

void init()
	{
        add_action("do_decide", "decide");
	}

int do_decide(string arg)
{
	object ob;
    	ob=this_player();

	if (!arg)
	{
	command("?");
	command("say 你想决定什么呀？你只需要回答yes或者no。\n");
	return 1;
	}
	
	if (arg=="yes")
	{	
	command("haha");
	command("say 好样的，从今以后，你就是我们组织的一员了！\n");	
	command("say 好好干，你一定会有出息！\n");
	ob->set_temp("heiyi/pass",1);
	return 1;
	}

	if (arg=="no")
	return notify_fail("嘿嘿，既然这样，那我也不勉强你，等你决定好了再来吧。\n");
	return 0;
}
