//sgzl

inherit NPC;

int have_fu;

string give_fu(object who);
int do_yes(string arg);

void create()
{
set_name("风婆",({"feng po","feng shen","po"}));
set("gender", "女性");
set("age", 35);
set("long", "    \n天宫中负责起风的天神，想要刮风下雨时，没有她\n的帮助是不行的。\n");

set("attitude", "heroism");
set("class", "xian");

    set("combat_exp", 60000);
  set("daoxing", 100000);


set("qi", 600);
set("max_qi", 600);
set("jing", 650);
set("max_jing", 650);
set("neili", 800);
set("max_neili", 800);
set("mana", 1000);
set("max_mana", 1000);
set("force_factor", 20);
set("mana_factor", 30);
set("per", 18);


	set_skill("force", 250);
	set_skill("club", 300);
	set_skill("parry", 180);
	set_skill("dodge", 180);
	set_skill("yijinjing", 301);
	set_skill("hunyuan-yiqi", 200);
	set_skill("weituo-chu", 300);
	set_skill("shaolin-shenfa", 180);

	map_skill("force", "yijinjing");
	map_skill("club",  "weituo-chu");
	map_skill("parry", "weituo-chu");
	map_skill("dodge", "shaolin-shenfa");

	set_skill("blade", 150);
	set_skill("claw", 150);
	set_skill("club", 150);
	set_skill("cuff", 150);
	set_skill("finger", 150);
	set_skill("hand", 150);
	set_skill("staff", 150);
	set_skill("strike", 150);
	set_skill("sword", 150);

	set_skill("banruo-zhang", 190);
	set_skill("cibei-dao", 190);
	set_skill("damo-jian", 190);
	set_skill("fengyun-shou", 190);
	set_skill("fumo-jian", 190);
	set_skill("jingang-quan", 199);
	set_skill("longzhua-gong", 190);
	set_skill("luohan-quan", 190);
	set_skill("nianhua-zhi", 190);
	set_skill("pudu-zhang", 190);
	set_skill("qianye-shou", 190);
	set_skill("sanhua-zhang", 190);
	set_skill("weituo-gun", 390);
	set_skill("wuchang-zhang", 190);
	set_skill("xiuluo-dao", 190);
	set_skill("yingzhua-gong", 190);
	set_skill("yizhi-chan", 200);
	set_skill("zui-gun", 200);
	set_skill("buddhism", 200);
	map_skill("blade", "cibei-dao");
	map_skill("claw", "longzhua-gong");
	map_skill("club", "weituo-chu");
	map_skill("cuff", "luohan-quan");
	map_skill("finger", "nianhua-zhi");
	map_skill("hand", "fengyun-shou");
	map_skill("staff", "weituo-gun");
	map_skill("strike", "sanhua-zhang");
	map_skill("sword", "fumo-jian");

     set("chat_chance_combat", 90);
     set("chat_msg_combat", ({
                (: perform_action, "finger.fuxue" :),
                (: perform_action, "finger.fuxue" :),
                (: perform_action, "club.leidong" :),
                (: perform_action, "club.zuijiu" :),
                            }) );
      set_temp("apply/attack", 150);
        set_temp("apply/defense", 100);
        set_temp("apply/armor", 100);
        set_temp("apply/damage", 100);
set("inquiry", ([
  "下雨"   : "想求雨，光我一个人可不够。",
  "rain"   : "想求雨，光我一个人可不够。",
  "起风"   : (: give_fu :),
  "刮风"   : (: give_fu :),
  "wind"   : (: give_fu :),
  "name"   : "我就是负责起风的风神。",
  "here"   : "这就是天宫呀。",
]));


setup();
	carry_object("/d/shaolin/obj/jingangchu")->wield();
carry_object(__DIR__"obj/skirt")->wear();
carry_object(__DIR__"obj/shoes")->wear();
add_money("silver", 10);

}


void init()
{
  have_fu=1;
  add_action("do_yao", "yao");
}

string give_fu(object who)
{
  who=this_player();
  if ( (who->query("combat_exp")<10000) || (who->query("mana") < 500 ) )
    {
    return "看来你还不懂怎么呼风唤雨，再好好修炼修炼吧。\n";
    }
  else
    {
    who->set_temp("need_fengfu", 1);
    return "我有张灵符，用它可以起风，你想要吗(yao)？\n";
    }
}

int do_yao(string arg)
{
  object me=this_object();
  object who=this_player();
  object fu;
   if(who->query_temp("need_fengfu")) 
   {
      message_vision("$N答道：想要！\n", who);

      if (have_fu==1)    
         {
         message_vision("风婆说道：好吧！你来试试看这玩意灵不灵。\n", who);
         fu = new (__DIR__"obj/fenglingfu");
         fu ->move(who);
         message_vision ("$N交给$n一张风灵符。\n",me,who);
         have_fu=0;
         }
      else 
         {
         message_vision("风婆说道：哎呀，实在不好意思，我刚把它给别人了，你等会儿在来要吧。\n", who);
         }
      return 1;

  }
}
��
