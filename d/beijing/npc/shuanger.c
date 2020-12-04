// shuanger.c
#include <ansi.h>

inherit NPC;
inherit F_UNIQUE;
int ask_go();
int ask_kiss();
int ask_me2();
void create()
{
	set_name("˫��", ({ "shuang er", "shuang","er"}));
	set("title", HIW "������˫" NOR);
	set("nickname", HIM "�󹦸��" NOR);
	set("gender", "Ů��");
	set("age", 15);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 15);
	set("int", 25);
	set("con", 25);
	set("dex", 30);
	set("per",26);
	set("max_qi", 8500);
	set("max_jing", 8500);
	set("neili", 8500);
	set("max_neili", 8500);
	set("jiali", 50);
	set("combat_exp", 390000+random(310000));
	set("score", 20000);

	set_skill("force", 180);
	set_skill("dodge", 180);
	set_skill("unarmed", 180);
	set_skill("sword", 220);
	set_skill("taiji-jian", 180);
	set_skill("taiji-quan", 220);
	set_skill("tiyunzong",220);
	set_skill("taiji-shengong",180);
	map_skill("dodge", "tiyunzong");
	map_skill("parry", "taiji-jian");
	map_skill("sword", "taiji-jian");
	map_skill("force", "taiji-shengong");
	map_skill("unarmed", "taiji-quan");

	set_temp("apply/attack", 15);
	set_temp("apply/attack", 15);
	set_temp("apply/damage", 15);
	set("inquiry", ([
		"��Ը��Ը�������" : (: ask_go :),
		"�󹦸��" : (: ask_kiss :),
		"ׯ���˵���" :  (: ask_me2 :),
	]));
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.zong" :),
                (: perform_action, "unarmed.zhenup" :),
                (: perform_action, "unarmed.zhan" :),
                (: perform_action, "unarmed.ji" :),
                (: perform_action, "unarmed.jielidali" :),
                (: perform_action, "sword.lian" :),
                (: perform_action, "sword.chan" :),
                (: perform_action, "sword.chanup" :),
                (: perform_action, "sword.sui" :),
                (: perform_action, "sword.lian" :),
                (: perform_action, "sword.lian" :),
                (: perform_action, "sword.lian" :),                
        }) );
	
	setup();
	carry_object("/clone/cloth/female1-cloth")->wear();
	carry_object("/clone/cloth/female-shoe")->wear();
	carry_object("/clone/weapon/changjian")->wield();
}


int init()
{
	add_action("do_attack","gongji");
	add_action("do_attack","attack");
	add_action("do_stop","stop");
	add_action("do_send","sendto");
	add_action("do_sha","sha");
}

int ask_kiss()
{
	object me;
	string new_name,new_id,host_id;
	me=this_player();
	if(query("id")!="shuang er")
	{
		sscanf(query("id"),"%s's shuang er",host_id);
		if(me->query("id")==host_id)
		{
			if(random(10)<1)
			{
				say(query("name")+ "�����ߵ�ͨ�죬����ͷ���������ĵ��˵�ͷ��\n");
//				add("combat_exp",2000);
			}
			else 
				say(query("name")+ "����һ����һ����������ȥ��˵�������Ҫ��\n");
			return 1;
		}
	}
	say(query("name")+"˵�����ޣ��Ҳ��ɡ�\n");
	return 1;
}

int ask_go()
{
	object me;
	string new_name,new_id,host_id;
	int exp,pot,score;
	me=this_player();
	if(query("id")!="shuang er")
	{
		sscanf(query("id"),"%s's shuang er",host_id);
		if(query("id")==host_id)
		{
			say(query("name")+"�����۾����˿�"+me->query("name")+"��˵����ȻԸ�������Ҷ�����ġ�\n");
			return 1;
		}
		if(me->query("id")!=host_id)
		{
			say(query("name")+"�����۾����˿�"+me->query("name")+"��˵�����еģ��ҵ��������˵ġ�\n");
			return 1;
		}
	}

		  	if(!(int)me->query_temp("book731"))
	{
		message_vision("$N��$n˵���� ��ɱ����֮���⹷������?\n",this_object(),me);
		return 1;	
	}


		  	if(!(int)me->query_temp("book732"))
	{
		message_vision("$N��$n˵���� ��ɱ�������⹷������?\n",this_object(),me);
		return 1;	
	}
	if ((int)this_player()->query("weiwang")>=70)
	{
		write( HIY "˫���������˴��Ҷ�����ɽ�����˶���ׯ�����д����\n" NOR);
		write( HIY "����Ҫ�ҷ�������,��һ�����ġ�\n" NOR);
		command("nod");	
		set_leader(me);
		new_name = me->query("name")+"��Ѿ��˫��";
		new_id=me->query("id")+"'s shuang er";
		set("name",new_name);
		set("id",new_id);
				set("combat_exp",me->query("combat_exp",1));
				set("max_qi",me->query("max_qi",1));
		set("eff_qi",me->query("max_qi",1));
		set("qi",me->query("max_qi",1));
		write( "����ָ��:\nattack sb ����ĳ��.\nsha sb ɱ��ĳ��.\nstop ֹͣս��.\nsendto sb.--��˫���͸�sb.\n");
		set("long","����"+new_name+"��\n����һ��ʮ���������Ů����Լʮ��������ͣ�\nһ��ѩ�׵����ӣ�ü����С��Ц���绨����Ц�����ؿ����㡣\n");
    if (!me->query("skybook/luding/shuanger"))
     {
     	me->set("skybook/luding/shuanger",1);
      exp=500+random(500);
      pot=exp/2;
      score=pot/2;
     	me->add("combat_exp",exp);
     	me->add("potential",pot);
     	tell_object(me,HIC"��ɹ��õ���ׯ���˵����Σ�\n�����������������"+
     	         chinese_number(exp)+"�㾭�顢"+
               chinese_number(pot)+"��Ǳ���Լ�"+
               chinese_number(score)+"�㽭��������\n\n"NOR);
     	}
	}
	else say(query("name")+"�����۾�����"+
		me->query("name")+"��˵�����еģ�����û��ͬ�⡣\n");
	return 1;
}

int do_attack(string arg)
{
	object ob; 
	string host_id;
	object me=this_player();
	if(query("id")=="shuang er")
	{
		say("����Ȩʹ�ô����\n");
		return 0;
	}
	sscanf(query("id"),"%s's shuang er",host_id);
	if(me->query("id")!=host_id) return notify_fail("˫�������������㣡\n");
	if(!arg||!objectp(ob=present(arg,environment(me))))
		return notify_fail("˫��ɵɵ�������㣬�����������˼��\n");
	if(!living(ob)) 
		return notify_fail("˫��˵:"
			+ob->query("name")+"�Ѿ��������㻹Ҫ...����\n");
	if(ob->query("age")< 16 ) 
		return notify_fail("˫��˵:"
			+ob->query("name")+"���Ǹ�С���ӣ����˰ɡ�\n");
		if (userp(ob))
	return notify_fail("������ͷ��С����������Ϊ�\n");

	if (!userp(ob) && !ob->accept_hit(me)) return 0;
	if(!environment(ob)->query("no_fight"))
	{
		message_vision("˫��������$N��ͷ��: �ţ��õġ�\n",me);
		fight_ob(ob);
	}
	return 1;
}

int do_stop()
{
	string host_id;
	object me=this_player();
	if(query("id")=="shuang er") return notify_fail("����Ȩʹ�ô����\n");
	sscanf(query("id"),"%s's shuang er",host_id);
	if(me->query("id")!=host_id) return notify_fail("˫�������������㣡\n");
	if(!is_fighting()) return notify_fail("˫������û���˴򶷡�\n");
	command("halt");
	message_vision("˫��������$N΢΢һЦ��\n",me);
	return 1;
}

int do_send(string arg)
{
	object ob; string host_id,new_name,new_id;
	object me=this_player();
	if(query("id")=="shuang er") return notify_fail("����Ȩʹ�ô����\n");
	sscanf(query("id"),"%s's shuang er",host_id);
	if(me->query("id")!=host_id) return notify_fail("˫�������������㣡\n");
	if(!arg||!objectp(ob=present(arg,environment(me))))
		return notify_fail("��Ҫ��˫���͸�˭��\n");
	if(!living(ob)) 
		return notify_fail("��ֻ�ܰ�˫�������ˣ�\n");
message_vision("˫��������������������$N��˵�����˴��Һã��������ã����˴��Ҳ��ã�����������ˡ�\n",me);
	set_leader(ob);
	new_name = ob->query("name")+"��Ѿ��˫��";
	set("long","����"+new_name+"��\n����һ��ʮ���������Ů����Լʮ��������ͣ�\nһ��ѩ�׵����ӣ�ü����С��ȴ���Ǹ������۸������������ؿ����㡣\n");
	new_id=ob->query("id")+"'s shuang er";
	set("name",new_name);
	set("id",new_id);
	write( HIY "˫����������"+ob->query("name")+"����������ӯӯһ�ݡ�\n" NOR);
	message_vision("����ָ��:\nattack sb ����ĳ��.\nsha sb ɱ��ĳ��.\nstop ֹͣս��.\nsendto sb.--��˫���͸�sb.\n",me);
	return 1;
}

int do_sha(string arg)
{
	int i ;
	object me,ob;
	object* obj;
	me = this_object();
	if(!arg||!objectp(ob=present(arg,environment(me))))
		return notify_fail("˫��˵: ������Ҫ˫��ɱ˭��\n");
	if(ob->query("age")< 16 ) 
		return notify_fail("˫��˵:"+ob->query("name")+"���Ǹ�С���ӣ����˰�...��\n");
	if (userp(ob))
	return notify_fail("������ͷ��С����������Ϊ�\n");
	
	//if (!userp(ob) && !ob->accept_kill(me)) return 0;
	if(!environment(ob)->query("no_fight"))
	{
		message_vision("˫����$N��ͷ˵��: �ţ��õġ�\n",me);
		command("say �ߣ�����Ҫ��ɱ���㣡");
		//fight_ob(ob);
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob); 
	}
	return 1;
}

int ask_me2()
{
	int i;
        object fang;
        object me;
        string new_name,new_id,host_id;
	object who = this_player();
	object where = environment(who);
	me=who;
		  	if(((int)who->query("jinyong/book7")!=2))
	{
		message_vision("$N��$n˵���� �����ׯ��������?\n",this_object(),who);
		return 1;	
	}

		  	if(!(int)who->query_temp("book731"))
	{
		message_vision("$N��$n˵���� ��ɱ����֮���⹷������?\n",this_object(),who);
		return 1;	
	}


		  	if(!(int)who->query_temp("book732"))
	{
		message_vision("$N��$n˵���� ��ɱ�������⹷������?\n",this_object(),who);
		return 1;	
	}

		  	if(!(int)who->query_temp("book733"))
	{
		message_vision("$N��$n˵���� ��̳�ׯ��ү����?\n",this_object(),who);
		return 1;	
	}
	
        if( who->is_fighting())
        {
		message_vision("$N��$n˵���� �������˵�ɣ�\n",this_object(),who);
		return 1;	
	}
	

		
		
  
 

if(((int)who->query("jinyong/book7")==2))
{
	
	i = 400+random(800);
	who->set("jinyong/book7",3);
	who->add("combat_exp",i+10880);
	who->add("potential",i*15);
	who->add("mpgx",10);
	who->add("expmax",3);

	tell_object (who,"��Ӯ����"+chinese_number(i+10880)+"�㾭��"+
	           chinese_number(i*15)+"��Ǳ��"+"ʮ�����ɹ��� ����ɳ����ޣ���\n");
	who->save();	
	command("thank " + who->query("id"));
write( HIY "˫���������˴��Ҷ�����ɽ�����˶���ׯ�����д����\n" NOR);
		write( HIY "����Ҫ�ҷ�������,��һ�����ġ�\n" NOR);
		command("nod");	
		set_leader(me);
		
		new_name = me->query("name")+"��Ѿ��˫��";
		new_id=me->query("id")+"'s shuang er";
		set("name",new_name);
		set("id",new_id);
		set("combat_exp",me->query("combat_exp",1));
		set("max_qi",me->query("max_qi",1));
		set("eff_qi",me->query("max_qi",1));
		set("qi",me->query("max_qi",1));
		write( "����ָ��:\nattack sb ����ĳ��.\nsha sb ɱ��ĳ��.\nstop ֹͣս��.\nsendto sb.--��˫���͸�sb.\n");
		set("long","����"+new_name+"��\n����һ��ʮ���������Ů����Լʮ��������ͣ�\nһ��ѩ�׵����ӣ�ü����С��Ц���绨����Ц�����ؿ����㡣\n");
}
	//call_out("destroying", 0); 
	//this_object()->kill_ob(who);
	return 1;
}