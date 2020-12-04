// by victori
inherit NPC;
#include <ansi.h>

void create()
{
        set_name("�����",({"wu gong"}));
	set("race", "Ұ��");
        set("long", "һ�����߶೤��������צ�Ķ���򼡣\n");
	set("age", 1000);
	set("attitude", "peaceful");

	set("max_jing", 5500);
	set("max_qi", 5500);
	set("jing", 6600);
	set("qi", 6600);
       set_skill("unarmed",180);
       set_skill("parry",180);
       set_skill("dodge",180);
       set_skill("force",180);
	set("str", 30);
	set("con", 50);

	set("limbs", ({ "ͷ��", "����", "β��" }) );
	set("verbs", ({ "bite" }) );

	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/armor", 100);
       set_skill("unarmed",180);
       set_skill("parry",180);
       set_skill("dodge",180);
       set_skill("force",180);

	set("combat_exp", 150000);
 
        set_weight(500000);
	setup();
}
void init()
{
        object me;
        add_action("do_xun", "xun");
//       object me,ob;
//        ::init();
        if (interactive(me = this_player()))
        {
      	       remove_call_out("kill_ob");
              call_out("kill_ob", 1, me);
        }
        ::init();
}
int do_xun(string arg)
{
	object me,who;
	me =this_object();
	who=this_player();
	if (!arg || (arg != "wu gong"))
		return notify_fail("��Ҫѱ��ʲô��\n");
	if(me->is_fighting())
		return notify_fail("��ֻ�������ս����\n");
	if((string)who->query("family/family_name")!="�嶾��")
		return notify_fail("ʲô��\n");
	
	message_vision("$N��$nһ���Х���󵨣�����ѱ��������ʱ��\n\n", who,me);
	message_vision("$N��Ȼ��ŭ��������˭ѱ˭����һ���ġ�\n
��������$nŤ��һ��\n",me,who);
	me->kill_ob(who);
	who->kill_ob(me);
        COMBAT_D->do_attack(me, who, query_temp("weapon"));
	me->set("owner",who->query("id"));
	return 1;
}

void die()
{
	string owner,name;
	object owner_ob;            
       object ob;
	owner = query("owner");
	if(owner) owner_ob= find_player(owner);
	if(owner_ob &&  (object)query_temp("last_damage_from") == owner_ob ) {
		message_vision("$Nſ�ڵ��ϣ�һ��Ҳ���Ҷ��ˡ�\n",this_object());	
	ob=new(__DIR__"wugong2.c");
	ob->move(environment(owner_ob));
	ob->set_leader(owner_ob);
       ob->set("host_id",owner_ob->query("id"));
       name=this_object()->query("name");
       ob->set_name(name,({"wu gong"}));
	destruct(this_object());

		return;
	}
       else {
            message_vision("$N���ڵ��ϣ����ˣ�\n", this_object());
            ob=new(__DIR__"obj/wugongdu.c");
	      ob->move(environment(this_object()));
	      destruct(this_object());
       }
//     return 1;
//	::die();
}

int hit_ob(object me, object ob, int damage)
{
       if ((string)ob->query("family/family_name") != "�嶾��") {
	     	ob->apply_condition("wugong_poison", 20
              +(int)ob->query_condition("wugong_poison") );
              tell_object(ob, HIG "����ñ�ҧ�еĵط�һ����ľ��\n" NOR );
	}
}
