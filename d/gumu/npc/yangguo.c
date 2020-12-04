// yangguo.c ���
// By Kayin @ CuteRabbit Studio 99-4-16 21:10 new
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_me();

void create()
{
	set_name("���", ({ "yang guo", "yang" }));
	set("nickname", HIG "������" NOR);
	set("gender", "����");
	set("age", 30);
	set("per",30);
	set("con",30);
	set("str", 30);
	set("class","gumu");
	set("dex", 30);
	set("long", "����һλ�ߴ�����ӣ���ò���㡣\n"+
	"һֻ����տ���Ҳ�����Ƕ���һ�ۣ�������ˣ�\n"+
	"��Ȼ�ڲ�ס�����˵ķ�ɡ�����Ը����д�(qiecuo)\n");
	set("combat_exp", 10000000);
	set("score", 10000);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set_skill("sword", 350);
	set_skill("force", 400);
	set_skill("unarmed", 400);
	set_skill("dodge", 350);
	set_skill("parry", 350);
	set_skill("anranxiaohun-zhang",350);
	set_skill("xuantie-sword", 350);
	set_skill("xiantian-qigong", 100);
	set_skill("yunv-shenfa",300);
	map_skill("sword", "xuantie-sword");
	map_skill("parry", "anranxiaohun-zhang");
	map_skill("unarmed","anranxiaohun-zhang");
	map_skill("dodge", "yunv-shenfa");
	set("chat_chance_combat", 80);
       set("chat_msg_combat", ({
                (: perform_action, "parry.xiaohun" :),
                (: perform_action, "sword.feihongrudian" :),
                
        }) );
	set_temp("apply/attack", 200);
	set_temp("apply/defense", 200);
	set_temp("apply/armor", 1000);
	set_temp("apply/damage", 600);
	set("neili", 25000); 
	set("max_neili", 25000);
	set("max_jing", 25000);
	set("max_qi", 25000);
	set("qi",25000);
        set("inquiry", ([
                "С��Ů" : "������С���\n",
"��ʦ": "��������������书��Ȼ���پ����ղ����㡣��������(accept test)��\n",
"�д�":"����Ը��ҽ����д�(qiecuo)\n",
"����֮��" : (: ask_me :),
       ]) );
       
	set_temp("apply/attack",150);
	set_temp("apply/defense",150);
	set_temp("apply/armor",500);
	set_temp("apply/damage",400);
       
       create_family("��Ĺ��", 3, "����");
	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object(__DIR__"obj/tiesword")->wield();
	add_money("gold", 1);
}

void init()
{
        ::init();
        add_action("do_accept", "accept");
	add_action("do_qiecuo","qiecuo");
	add_action("do_killing", "kill");
	add_action("do_killing", "touxi");
	add_action("do_killing", "hit");
	add_action("do_killing", "ansuan");
}

void attempt_apprentice(object ob)
{ 
  if(!ob->query("marks/beguo"))
	  return;
else {
 command("recruit " + ob->query("id") );
ob->set("title",HIW"����մ�����"NOR);
}
 return;
}
int recognize_apprentice(object ob)
{
  if(!ob->query("marks/win_guo_time"))
	  return 0;
  if((time() - ob->query("marks/win_guo_time") ) > 900)
  {
    say("���˵�����������ѧ�˲����ˣ�������������(qiecuo)һ�°ɣ�\n");
    return 0;
  }
 return 1;
}

int do_qiecuo()
{
    mapping guild;
    int skee,dkee;
    object me,target;
	
	me=this_player();
	target=this_object();
	skee=target->query("qi");
	
	if((time()-me->query("marks/win_guo_time"))<900)
	{
     command("say ��Ĺ����治�����������д�����\n");
	 return 1;
	}
	//if who have qiecuo,and the time have beyond 2 hours,then he can qiecuo
	if(time() - me->query("marks/qiecuo_last_time")>72000)
	{
     
     COMBAT_D->do_attack(me,target,me->query_temp("weapon"));
	 say("\n�������һ�У�������\n");
     COMBAT_D->do_attack(me,target,me->query_temp("weapon"));
     say("\n����������У�������\n");
     COMBAT_D->do_attack(me,target,me->query_temp("weapon"));
     say("\n����������У�������\n");
	 dkee=target->query("qi");
     if(!(dkee<skee)) 
	 {
      say("���˵�����������书���У���������Щ�����ɣ�\n");
	  me->set("marks/qiecuo_last_time",time());
     }
	 else
	 {
            
      say("\n���˵������Ĺ����治�����ӽ��Ժ����Ǿ��໥ѧϰ�ɣ�\n");
	  me->set("marks/win_guo_time",time());
	 }
	 return 1;
	}
    say("���˵�����㲻��ǰ������ң��������ٱȰɣ�\n");
    return 1;
}
int do_accept(string arg)
{
        mapping guild;

        if( arg== "test" ) {
	if((string)this_player()->query("family/family_name") != "��Ĺ��") 
		{
			command("say ����ȥ���ҹùðɡ�\n");
			return 1;
		}
	else if(this_player()->query("shen")>50000)
		{
			command("say �������������������Щ��ν����������򽻵���\n");		return 1;}
	else if(this_player()->query("shen")<-50000)
		{
			command("say �����������ʹ��������Ща���������ҹ���\n");		return 1;}
	else if(this_player()->query("str")<28)
		{
			command("say �����̫�ѧ�����ҵ��书��\n");
		return 1;}
	else if(this_player()->query("combat_exp")<1000000)
		{
			command("say �㵱����˭������Ҳ��ѧ���书����\n");
		return 1;}

	else if(this_player()->query("family/master_id") == this_object()->query("id"))
	{
	say("\n����������ͷ�����㽫���ض���һ������֮���ˣ�\n");
	return 1;
	}
	
                say("\n������˵�ͷ��˵�����ܺã����������У����ǵ�һ��....\n\n");
                COMBAT_D->do_attack(this_object(), this_player(), 
query_temp("weapon"));
                if( (int)this_player()->query("qi") < 1 ) {
                        
say("���̾�˿�����˵��������һ�ж��Ų����������Բ�����....\n");
                 this_player()->die();
	       return 1;
		}
                say("\n���˵�������������ǵڶ���....\n\n");
                COMBAT_D->do_attack(this_object(), this_player(), 
query_temp("weapon"));
                if( (int)this_player()->query("qi") < 1 ) {
                        
say("������ߡ���һ����˵���������������಻�����ļһ�....\n");
                this_player()->die();     
	   return 1;
                }
                say("\n���˵��������������....\n\n");
                COMBAT_D->do_attack(this_object(), this_player(), 
query_temp("weapon"));
                if( (int)this_player()->query("qi") < 1 ) {
                        
say("���̾������ϧ����������Ե��....\n");
                       this_player()->die();
 return 1;
                }
                
say("\n���������Ц��˵������������ٵ�һ������֮�ţ�\n\n");
                this_player()->set("marks/beguo",1);
	return 1;
        }
        return 0;
}
int do_killing(string arg)
{
	
	object player, victim, weapon;
	string name;
	player = this_player();
	if( !arg) return 0;
	if( objectp(victim = present(arg, environment(this_object()))) && living(victim))
	{
		name = (string)victim->name();
		if( (string)name == "С��Ů")
		{
		message_vision("$N��Цһ��������ɱ�ҹùã��ҿ�����̫���ˡ�\n", this_object());
		this_object()->kill_ob(player);
		player->kill_ob(this_object());
		return 1;
		}
	}
	return 0;		
}


string ask_me()
{ 
       mapping fam; 
       object ob;
       ob = this_player();
//       if (!(fam = this_player()->query("family")) || fam["family_name"] != "��Ĺ��")
//               return RANK_D->query_respect(this_player()) + 
//               "���ҹ�Ĺ����,��֪���˻�����?";
            if (!ob->query_temp("xth_hm"))
            return RANK_D->query_respect(this_player()) + 
               "��֪��ʲ������֮����?";
                      ob->delete_temp("xth_hm");
               ob->set_temp("make/xtj_look1",1);
            ob->set_temp("yg_pbask",1);
       return "������Ϣ,��������,˫�����,���ص���,�����ں�ˮ�������ľ���,��ú�ȥ����һ��.";
}