#include <ansi.h>;
inherit NPC;
int ask_job2();
void create()
{
   set_name("程瑶迦",({"chen yaojia"}));
	set("gender","女性");
   set("score",25000);
   set("combat_exp",80000);
   set("title",HIG"大小姐"NOR);
set("per",30);
set("age",19);
   set("qi",28000);
   set("max_qi",28000);
set("food",250);
set("water",250);
   set("neili",50000);
   set("max_neili",50000);
   set("force_factor",30);

  set_skill("taoism", 180);
	set_skill("force", 100);
	set_skill("taiji-shengong", 180);
	set_skill("dodge", 100);
	set_skill("tiyunzong", 180);
	set_skill("unarmed", 100);
	set_skill("taiji-quan", 180);
	set_skill("parry", 100);
	set_skill("sword", 100);
	set_skill("taiji-jian", 180);
	set_skill("wudang-jian", 180);
	set_skill("literate", 50);
	set_skill("raozhi-roujian", 180);
	set_skill("wudang-mianzhang", 280);
set_skill("claw", 150);
set_skill("strike", 150);
	set_skill("hand", 180);
	set_skill("paiyun-shou", 250);
	set_skill("shenmen-jian", 250);
	set_skill("yitian-zhang", 250);
	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "paiyun-shou");
	map_skill("sword", "taiji-jian");
		map_skill("hand", "paiyun-shou");
			map_skill("strike", "yitian-zhang");
prepare_skill("hand", "paiyun-shou");
prepare_skill("strike", "yitian-zhang");

        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.zong" :),
                (: perform_action, "unarmed.zhenup" :),
                (: perform_action, "unarmed.tu" :),
                (: perform_action, "unarmed.zhan" :),
                (: perform_action, "unarmed.ji" :),
                (: perform_action, "unarmed.jielidali" :),
                (: perform_action, "hand.leiting" :),
                (: perform_action, "hand.mian" :),
                (: perform_action, "strike.zheng" :),	
                (: perform_action, "sword.lian" :),
                (: perform_action, "sword.chan" :),
                (: perform_action, "sword.chanup" :),
                (: perform_action, "sword.sui" :),
                (: perform_action, "sword.lian" :),
                (: perform_action, "sword.zhenwu" :),
                (: perform_action, "sword.lian" :),                
        }) );
   
        set("inquiry", ([
        "坏人" : (:ask_job2:) ,
        "淫贼" : (:ask_job2:) ,
         ]) );

   setup();
   add_money("silver",5);
carry_object("/d/yanjing/npc/obj/skirt")->wear();
carry_object("/d/yanjing/npc/obj/xiuhuaxie")->wear();
}


int ask_job2()
{

        object me = this_player();
        object ob,who,fang;
        mapping quest;
        mapping skl; 
        string *sname, place;        
        int i, skill = 0;
        who=me;
        if(((int)me->query("jinyong/book5")!=3))
           {
                      message_vision("$N对着$n说道。你说什么啊。\n", this_object(), me);
	                      return 1;
            }

        if(!me->query_temp("book541"))
           {
                      message_vision("$N对着$n说道。谁知道 你是不是和那坏人一伙的?\n", this_object(), me);
	                      return 1;
            }    

 

      if(!query("iskillok"))
      {
      message_vision("突然一阵淫笑 欧阳克从窗外杀了过来 说道：小美人 我来了!\n",this_object(),who);	
      	fang = load_object(__DIR__"ouyangke");
	fang->move(environment(who));	
	fang->kill_ob(who);
     this_object()->set("iskillok",1);
     set("iskillok",1);
return 1;
      }	



                    
        if(!me->query_temp("book542"))
           {
                      message_vision("$N对着$n说道。你打赢欧阳克吗?\n", this_object(), me);
	                      return 1;
            } 
if((int)me->query("jinyong/book5")==3)
{
message_vision("$N说道：多谢多次相助，只是欧阳克逃走了，听说他要去桃花岛求亲！\n" NOR,this_object());
		i = 800+random(2000);
		who->set("jinyong/book5",4);
		who->add("combat_exp",i+13000);
		who->add("potential",i*18);
		who->add("mpgx",10);
		who->add("expmax",2);
		//command("chat "+this_player()->query("name")+"胆色过人，义惩青城恶霸。");
		tell_object (who,"你赢得了"+chinese_number(i+13000)+"点经验"+
		           chinese_number(i*18)+"点潜能"+"十点门派贡献 二点成长上限！！\n");
		who->save();
}		
                return 1;
                           
}