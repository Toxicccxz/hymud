#include <ansi.h>
inherit NPC;


int ask_me();
void create()
{
        set_name("程灵素", ({ "cheng lingsu", "cheng" }));
        set("gender", "女性");
        set("age", 24);
        set("long", @long
她看上去双眉紧缩，不知道有什么心事，长得相貌平平，并不出众。
身材瘦小，穿着粗布衣衫。
long);
        set("title", HIG"药王谷传人"NOR); 
        set("attitude", "peaceful");
        set("str", 22);
        set("int", 35);
        set("con", 31);
        set("dex", 27);
        set("per", 25);
        set("chat_chance", 10);
        set("chat_msg", ({
                "程灵素哀哀的叹了口气。\n",
        }));

        set("qi", 15900);
        set("max_qi", 15900);
        set("jing", 9900);
        set("max_jing", 9900);
        set("neili", 9900);
        set("max_neili", 9900);
        //set("jiali", 40);
        set("combat_exp", 900000);
     
        set_skill("force", 150);
        set_skill("poison", 370);
        //set_skill("dispel-poison", 270);
	set_skill("miaoshouhuichun", 370);
	//set_skill("yaowang-miaoshu", 270);

set_skill("cuff", 300);
set_skill("cuff", 300);
set_skill("lingshe-quan", 180);
set_skill("zhaosheshu", 180);
set_skill("yangsheshu", 180);
	set_skill("sword", 280);
	set_skill("force", 250);
	set_skill("unarmed", 250);
	set_skill("dodge", 250);
	set_skill("parry", 250);
	set_skill("strike",220);
	set_skill("hand",320);
	
	set_skill("staff", 250);
	set_skill("hamagong", 180);
	set_skill("chanchu-bufa", 180);
	set_skill("shexing-diaoshou", 180);
	set_skill("lingshe-zhangfa", 180);
	set_skill("hamashengong", 180);
	set_skill("xiyu-tiezheng", 180);
set_skill("shentuo-zhang", 282);
set_skill("martial-cognize", 180);

	map_skill("strike", "hamagong");
	map_skill("force", "hamagong");
	map_skill("dodge", "chanchu-bufa");
	map_skill("unarmed", "shexing-diaoshou");
	map_skill("hand", "xiyu-tiezheng");
	map_skill("parry", "hamagong");
	map_skill("staff", "lingshe-zhangfa");
	prepare_skill("strike", "hamagong");
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({

                (: perform_action, "staff.saoluoye" :),
                (: perform_action, "staff.shewu" :),
                (: perform_action, "staff.shoot" :),
                (: perform_action, "staff.saoluoye" :),
         
             
        }) );
        set("inquiry",([
                "七心海棠" : (: ask_me :), 
                "胡斐":     "他...他...\n",
                "袁紫衣":   "我...你提他干什么？\n"
        ]));

        setup();
        	carry_object("/clone/weapon/gangzhang")->wield();
        carry_object("/clone/misc/cloth")->wear();
}


int ask_me()
{
	int i;
        object fang;
	object who = this_player();
	object where = environment(who);
	
		  	if(((int)who->query("jinyong/book1")!=4))
	{
		message_vision("$N对$n说道： 你在说什么啊！\n",this_object(),who);
		return 1;	
	}
	
	  	if(((int)who->query("jinyong/book1")>=5))
	{
		message_vision("$N对$n说道： 你在说什么啊！\n",this_object(),who);
		return 1;	
	}
	
        if( who->is_fighting())
        {
		message_vision("$N对$n说道： 你打玩再说吧！\n",this_object(),who);
		return 1;	
	}
	
	
        fang = present("jiang tieshan",where);
	if(fang)
	{
		who->start_busy(3);
		message_vision("$N对$n说道： 这位"+ RANK_D->query_respect(who) +"先帮我战败我大师兄吧。\n",this_object(),who);
		return 1;
	}

        fang = present("xue que",where);
	if(fang)
	{
		who->start_busy(3);
		message_vision("$N对$n说道： 这位"+ RANK_D->query_respect(who) +"先帮我战败我二师姐吧。\n",this_object(),who);
		return 1;
	}


 
		  	if((!(int)who->query_temp("killyao2")))
	{
		message_vision("$N对$n说道： 你帮我对付了我二师姐了吗?\n",this_object(),who);
		return 1;	
	}
	
		  	if((!(int)who->query_temp("killyao1")))
	{
		message_vision("$N对$n说道： 你帮我对付了我大师兄了吗?\n",this_object(),who);
		return 1;	
	}


	command("bow " + who->query("id"));
	message_vision("$N对$n说道： 多谢 舍命相救。\n",this_object(),who);
	message_vision("$N对$n说道： 我这就去给苗大侠解毒。\n",this_object(),who);


	
	i = 400+random(800);
	who->set("jinyong/book1",5);
	who->add("combat_exp",i+10880);
	who->add("potential",i*12);
	who->add("mpgx",10);
	who->add("expmax",2);

	tell_object (who,"你赢得了"+chinese_number(i+10880)+"点经验"+
	           chinese_number(i*12)+"点潜能"+"十点门派贡献 二点成长上限！！\n");
	who->save();
	call_out("destroying", 0); 
	//this_object()->kill_ob(who);
	return 1;
}

void destroying()
{   
object ob=this_object();
   message_vision(HIM"$N说完闪了闪身就消失在门外......\n"NOR,ob);
destruct(this_object());
   return;      
}