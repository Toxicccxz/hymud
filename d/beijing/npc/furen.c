// furen.c
inherit NPC;
#include <ansi.h>
int ask_me2();
void create()
{
	set_name("庄夫人", ({ "san furen", "san","furen"}));
	set("title", "庄家三少奶奶" );
	set("nickname", HIW "未亡人" NOR);
	set("long",  "\n只见她约莫二十六七年纪,全身缟素,不施脂粉,脸色苍白.\n");
	set("gender", "女性");
	set("age", 25);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 30);
	
	set("max_qi", 5000);
	set("max_jing", 5400);
	set("neili", 5000);
	set("max_neili", 5000);
	set("jiali", 100);
	set("combat_exp", 100000);
	set("score", 50000);

	set_skill("force", 220);
	set_skill("dodge", 220);
	set_skill("unarmed", 220);
	set_skill("sword", 220);
	set_skill("taiji-jian", 220);
	set_skill("tiyunzong",220);
	map_skill("dodge", "tiyunzong");
	map_skill("parry", "tiaji-jian");
	map_skill("sword", "tiaji-jian");

	set_temp("apply/attack", 35);
	set_temp("apply/attack", 35);
	set_temp("apply/damage", 35);
        set("inquiry", ([
		"鳌拜" : "鳌拜是我家的大仇人。",
		"陈近南" :  (: ask_me2 :),
		"吴之荣" :"我一定要手刃了这个奸贼。",
		"礼物" :  "这样礼物可不一般,她就是我的好丫环双儿。",
		"双儿" :  "这小丫头跟随我多年,做事也还妥当。",
	]) );
	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
}

void init()
{
	object ob; 
	ob = this_player();

	if( interactive(ob) && !is_fighting() ) 
	say( "庄夫人说道：很久没有人来了,\n这位" + RANK_D->query_respect(ob)
				+ "，可知道我相公的下落吗?\n");
}

int accept_object(object me, object ob)
{
	int i;
	if( !me || environment(me) != environment() ) return 0;
	if ( !objectp(ob) ) return 0; 
	if ( !present(ob, me) ) return notify_fail("你没有这件东西。");
	if ( (string)ob->query("id") == "wu zhi rong") 
	{
	i=(int)this_player()->query("weiwang");
        if(i>=50&&i<70)
	{
	i=i+10;
	this_player()->set("weiwang",i);
	message_vision(HIC "\n$N的江湖威望提高了！\n" NOR,me);
	command("tell "+this_player()->query("id")+" 你现在的江湖威望是 " +(string)(i));
	write(HIC "\n庄夫人大喜道：狗贼,看打!想不到你也有今天!!!\n");
        ob->die();
	}
         if(this_player()->query("weiwang")>=70)
	 {
	 write(HIC "\n庄夫人说道：这位" + RANK_D->query_respect(ob)+",如此大恩大德,妾身实不知何以为报.\n");
	 write(HIC "我想送恩公一件礼物,务请勿却是幸.\n");
	 }
        }		
	if ( (string)ob->query("name") == "明史辑略") 
	{
	 write(HIC "\n庄夫人说道：这位" + RANK_D->query_respect(ob)+",多谢了.\n");
	 write(HIC "唉,你要能帮我找到吴之荣这狗贼就好了.\n");
        }		
	if ( (string)ob->query("name") == "庄允城") 
	{
	 write(HIC "\n庄夫人说道：这位" + RANK_D->query_respect(ob)+",多谢了.\n");
	 write(HIC "唉,你要能帮我找到吴之荣这狗贼就好了.\n");
        }		
 return 1;
}

int ask_me2()
{
	int i;
        object fang;
	object who = this_player();
	object where = environment(who);
	
		  	if(((int)who->query("jinyong/book7")!=1))
	{
		message_vision("$N对$n说道： 你见了陈总舵主了吗?\n",this_object(),who);
		return 1;	
	}

		  	if(!(int)who->query_temp("book721"))
	{
		message_vision("$N对$n说道： 你见了陈总舵主了吗?\n",this_object(),who);
		return 1;	
	}


		  	if((int)who->query_temp("book722")<=5)
	{
		message_vision("$N对$n说道： 你帮我对付在我家的神龙弟子了吗?\n",this_object(),who);
		return 1;	
	}

		  	if(!(int)who->query_temp("book723"))
	{
		message_vision("$N对$n说道： 你帮我对付在我家的章老三了吗?\n",this_object(),who);
		return 1;	
	}
	
        if( who->is_fighting())
        {
		message_vision("$N对$n说道： 你打玩再说吧！\n",this_object(),who);
		return 1;	
	}
	

		
		
  
 

if(((int)who->query("jinyong/book7")==1))
{
	
	i = 400+random(800);
	who->set("jinyong/book7",2);
	who->add("combat_exp",i+10880);
	who->add("potential",i*12);
	who->add("mpgx",10);
	who->add("expmax",2);

	tell_object (who,"你赢得了"+chinese_number(i+10880)+"点经验"+
	           chinese_number(i*12)+"点潜能"+"十点门派贡献 二点成长上限！！\n");
	who->save();	
	command("thank " + who->query("id"));
	message_vision("$N对$n说道： 多谢 帮我赶走了这帮坏人。\n",this_object(),who);
	message_vision("$N对$n说道： 可怜庄允城被抓走 能帮我救出他吗?\n",this_object(),who);
	message_vision("$N对$n说道： 鳌拜祸国 能为国除贼不?\n",this_object(),who);

}
	//call_out("destroying", 0); 
	//this_object()->kill_ob(who);
	return 1;
}