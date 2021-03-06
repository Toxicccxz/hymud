// liumang.c
// by dicky

inherit NPC;
int ask_shoujuan();

void create()
{
        set_name("小流氓", ({"xiao liumang","liumang"}) );
        set("gender", "男性" );
        set("age", 18);
        set("long", "这是一个游手好闲的小流氓。\n");
        set_temp("apply/attack", 10);
        set_temp("apply/defense", 10);
        set("combat_exp", 500);
	set("shen_type", -1);
        set("str", 25);
        set("dex", 20);
        set("con", 18);
        set("int", 15);
        set("attitude","heroism");
        set("inquiry", ([
		"春花":(: ask_shoujuan :),
        ]));

        set("chat_chance", 2);
        set("chat_msg", ({
                "流氓骂骂咧咧的说道：这真他妈的邪唬，老子手里一对天牌，这\n"
                "小杂种居然就摸出一对至尊来。\n",
                "流氓靠着墙角打起瞌睡来了，睡梦中也不知想到了什麽，嘴里哼\n"
                "哼道：我看见你那雪白的大腿，我就起～了～坏～心～喽。\n",
                "流氓摸了摸自己的口袋，叹了口气说道：唉，钱都让小杂种骗去\n"
                "了，不能去找春花了。\n",
                "流氓嘴角露出一丝邪笑，说道：春花这娘儿们真够劲儿，真她奶\n"
                "奶的够～劲～儿！\n",
        }) );

        setup();
        carry_object("/clone/misc/cloth")->wear();
	add_money("coin", 3);
}

int ask_shoujuan()
{
	object ob;
	ob=this_player();
	if (ob->query_temp("ganjiang/have_ask"))
	{
	command("kick "+ob->query("id")+"\n");
	command("say 你刚才不是来问过了么？我现在很忙，不要再来打搅我！");
	return 1;
	}
	
	if (!ob->query_temp("ganjiang/shoujuan"))
	{
	command("hehe");
	command("say "+RANK_D->query_respect(ob)+"，你想知道她呀，哈哈......这你可是找对人了，
我们可是老相好哦！\n");
	command("say "+RANK_D->query_respect(ob)+"，我告诉你吧,春花这娘儿们真够劲儿，真她奶
奶的够～劲～儿!\n");
	command("say "+RANK_D->query_respect(ob)+"，你要不要也去试试，我这里可是有她的信物哦！
只要你拿这去找她，她一定能让你欲仙欲死！\n");
	command("haha");
	ob->set_temp("ganjiang/shoujuan",1);
	ob->set_temp("ganjiang/have_ask",1);
	message_vision(
                "\n小流氓给$N一条手绢。\n",
                this_player(), this_object() );
	new(__DIR__"obj/shoujuan")->move(ob);
	return 1;
	} 
	else 
	{
	command("say 哈哈......你也常用这个姿势么？");
	return 1;
	}
}
