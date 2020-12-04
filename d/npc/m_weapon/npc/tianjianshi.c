// npc: /d/npc/m_weapon/npc/tianjianshi.c
// Jay 3/26/96
#include <ansi.h>
inherit NPC;

string ask_met();
int do_weapon();
object creat_weapon();

void create()
{
        set_name("ŷұ��", ({ "ouye zi", "zi" }) );
        set("nickname", RED "���Ľ���" NOR );
	set("gender", "����" );
        set("age", 60);
        set("long", 	
            "��ͷ�ϰ���ͷ�������Ƴ���Ʈ����ǰ����Ŀ���ݵ������й⣬\n"
            "��Ŀ��������˸˸���ž��������ݵĽ��⣬�����ƺ�����Χ\n"
	    "��һ�ɽ���֮�С�\n");
        set("str", 25);
        set("dex", 20);
        set("con", 17);
        set("int", 30);
        set("shen_type", 0);
	set("max_neli",5000);
	set("jiali",50);

        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_skill("claw",200);
        set_skill("jiuyin-baiguzhao",200);
        set_skill("force",150);
        set_skill("sword",150);
        set_skill("bibo-shengong",100);
        set_skill("luoying-shenjian",100);
        set_skill("parry",90);
        set_skill("anying-fuxiang",100);
        set_temp("apply/attack", 50);
        set_temp("apply/defense", 50);
        set_temp("apply/damage",50);

	create_family("������",1,"����");

        set("combat_exp", 250000);
	set("score",0);
	
        map_skill("force","bibo-shengong");
	map_skill("parry","luoying-shenjian");
	map_skill("sword","luoying-shenjian");
	map_skill("claw","jiuyin-baiguzhao");
	map_skill("dodge","anying-fuxiang");

	
	set("attitude", "peaceful");
        
	set("inquiry", ([
            "����"  : "������,����������ȥ�����ݵĸɽ��򸾰ɡ�\n",
	    "ԭ��"  : "������,����������ȥ�����ݵĸɽ��򸾰ɡ�\n",
	    //"����"  :  (: do_weapon() :),
	    //"����"  :  (: ask_met() :),
       ]) );

        setup();
        set("chat_chance", 5);
        set("chat_msg", ({
             "ŷұ�Ӹ������裺��������⣬�����͡����������⣬��Ӣ�ۣ�\n",
	     "ŷұ�ӵ�ͷ������������,����������ȥ�����ݵĸɽ��򸾰ɡ�\n"
	     "ŷұ��̾��һ������������,����������ȥ�����ݵĸɽ��򸾰ɡ���\n"
       }) );
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();
}

void init()
{
        ::init();
        //add_action("do_answer","answer");
}


int accept_object(object who, object ob)
{	

		say("ŷұ��һ��ãȻ������������ȥ�����ݵĸɽ��򸾰ɡ�\n");
		return 2;

	switch ((string)ob->query("name") ) 
	{
		case "������"  :
		case "�л���"  :
		case "����":
		case "��а����":
		case "�׻�������":
			if( (who->query_temp("condition")) != (string)ob->query("name")  )
			{
				message_vision(HIC "ŷұ��һ㶣��Ҷ���˵����Ҫ��������ô��\n" NOR, who);
				return 2;
			}
			else {
			who->delete_temp("condition");
			message_vision(HIG "ŷұ��΢Ц�ţ��ܺúܺã����ҾͰ�����һ�ΰɣ�\n" NOR, who);
			who->set_temp("condition_ok",1);
			do_weapon();
			return 2;
			}
	}
	if((int)(who->query("weapon/make")) ){
		say("ŷұ��һ��ãȻ�����Ѿ���һ������������ˣ�������ʲô���ѵ�������ô��\n");
		return 2;
	}
//	switch ((string)ob->query("name") ) 
	switch ((string)ob->query("id") ) 
	{
//		case "ǧ����ľ": 
		case "shen mu": 
			who->set_temp("or",1);
			who->set_temp("get_orc",1);
                destruct(present("shen mu",ob));
			break;
//		case "���׽�ĸ":
		case "jin mu":
			who->set_temp("or",2);
			who->set_temp("get_orc",1);
                destruct(present("jin mu",ob));
			break;
//		case "��˿����": 
		case "han zhu": 
			who->set_temp("or",3);
			who->set_temp("get_orc",1);
                destruct(present("han zhu",ob));
			break;
		default :
			message("vision","����ʲô���ⲻ���������������",who);
			return 2;
	}
	message("vision","ŷұ�ӵ�ͷ������һ�����е�"+(string)ob->query("name")+
			"���˵�ͷ˵��\n",who);
	write("��������Դ������±�����\n"+
	      "     ��(sword)\n"+
	      "     ��(blade)\n"+
	      "     ��(stick)\n"+
	      "     ��(staff)\n"+
	      "     ��(hammer)\n"+
	      "     ��(whip)\n");	  	
	say("��λ"+RANK_D->query_respect(who)+"Ҫ��ʲô�����������˸�����(answer)��\n");
	return 2;

}

int do_answer(string arg)
{
	object me,w_or;
	me = this_player();

		write("����������ȥ�����ݵĸɽ��򸾰ɡ�\n");
		return 0;

	if(!(me->query_temp("get_orc") ) ){
		write("���ҵ�ԭ������\n");
		return 0;
	}
	
	if(!arg){
	   write("��Ҫ��ʲô������\n");
	  return 0;
	}
	message("vision",me->name()+"��ŷұ������˵�˼��䡣\n",environment(me), ({me}) );
	
	switch (arg) {
	  case "sword" :
		me->add_temp("sword",1);
		write("����ԭ��ȥ���̽��ɣ�\n");
		message("vision","ȥ�ɣ�"+me->name()+"��\n",me);
		break;
	  case "blade" :
		me->add_temp("blade",1);
		write("����ԭ��ȥ���̵��ɣ�\n");
		message("vision","ȥ�ɣ�"+me->name()+"��\n",me);
		break;
	  case "stick" :
		me->add_temp("club",1);
		write("����ԭ��ȥ���̹��ɣ�\n");
		message("vision","ȥ�ɣ�"+me->name()+"��\n",me);
		break;
	  case "staff" :
		me->add_temp("staff",1);
		write("����ԭ��ȥ�����Ȱɣ�\n");
		message("vision","ȥ�ɣ�"+me->name()+"��\n",me);
		break;
	  case "hammer" :
		me->add_temp("hammer",1);
		write("����ԭ��ȥ���̴��ɣ�\n");
		message("vision","ȥ�ɣ�"+me->name()+"��\n",me);
		break;
	  case "whip" :
		me->add_temp("whip",1);
		write("����ԭ��ȥ���̱ްɣ�\n");
		message("vision","ȥ�ɣ�"+me->name()+"��\n",me);
		break;
	  default :
		message_vision(HIC "ŷұ��һ�����ɣ�ʲô������\n" NOR,me);
		return notify_fail("ŷұ����ϸ��˵�����²��ɶ�Ϸ��������!!\n");
	}
if (!me->query_temp("weaponok"))
{
	switch ( me->query_temp("or") ) {
	  case 1:
		w_or = new("/d/npc/m_weapon/tan/item/shenmu",1);
		w_or->move(me);
		message_vision(HIC "ŷұ�Ӹ���$Nһ��ǧ����ľ��\n" NOR, me);
		break;
	  case 2:
		w_or = new("/d/npc/m_weapon/tan/item/jinmu",1);
		w_or->move(me);
		message_vision(HIC "ŷұ�Ӹ���$Nһ�麣�׽�ĸ��\n" NOR, me);
		break;
	  case 3:
		w_or = new("/d/npc/m_weapon/tan/item/hanzhu",1);
		w_or->move(me);
		message_vision(HIC "ŷұ�Ӹ���$Nһ�麮˿����\n" NOR, me);
		break;
	}
}
me->set_temp("weaponok",1);
	return 1;
}

int do_weapon()
{
	object me,weapon,obj;
	string w_id;
	me = this_player();
	w_id = me->query("weapon/id");
		
return notify_fail("����������ȥ�����ݵĸɽ��򸾰ɡ�\n");

	if( !(me->query("weapon/make")) )
		return notify_fail("�����������\n");

	if( objectp(obj = present(w_id, me)) )
	{
		say("ŷұ����ɫһ���������������������ֱ�ô��������ʲô��\n");
		return 1;
	}
	if (me->query_temp("condition") )
	{
		say("ŷұ����ɫһ������������ȥ��"+(me->query_temp("condition") )+
"��ô����û�õ��������\n");
		return 1;
	}

	if( !(me->query_temp("condition_ok")) ) {
		message_vision(HIY "��λ"+RANK_D->query_respect(me)+"��Ҫ���µõ��������ⲻ�ѡ�����......\n" NOR, me);
		message_vision(HIY "ŷұ�ӳ�����һ��˵������ҵ���Ҫ�Ķ�����\n" NOR, me);
		switch( random(5) ) {
			case 0:
				message_vision("�õ������ӣ������ɣ�\n",me);
				me->set_temp("condition","������");
				break;
			case 1:
				message_vision("���ҽл������ҾͰ��㣡��\n",me);
				me->set_temp("condition","�л���");
				break;
			case 2:
				message_vision("��...����ú�ľ�°׻������������ɣ���\n",me);
				me->set_temp("condition","�׻�������");
				break;
			case 3:
				message_vision("....���뿴��������������\n",me);
				me->set_temp("condition","����");
				break;
			case 4:
				message_vision("������������ҵ���а���׵Ļ�......\n",me);
				me->set_temp("condition","��а����");
				break;
			}
		}
	else	{
		me->delete_temp("condition_ok");
		weapon = creat_weapon();
		weapon->move(me);
	}
	return 1;
}

object creat_weapon()
{
	object me,weapon;
	string mask;	//the verible that record the type of weapon
	me = this_player();
	mask = me->query("weapon/type");
	switch(mask)	{
		case "��":
			weapon = new("/d/npc/m_weapon/weapon/m_sword",1);
			return weapon;
		case "��":
			weapon = new("/d/npc/m_weapon/weapon/m_blade",1);
			return weapon;
		case "��":
			weapon = new("/d/npc/m_weapon/weapon/m_club",1);
			return weapon;
		case "��":
			weapon = new("/d/npc/m_weapon/weapon/m_staff",1);
			return weapon;
		case "��":
			weapon = new("/d/npc/m_weapon/weapon/m_hammer",1);
			return weapon;
		case "��":
			weapon = new("/d/npc/m_weapon/weapon/m_whip",1);
			return weapon;
	}
}

string ask_met() 
{ 
	object weapon;
	object gold;
	object *inv;
	int i;
        object me = this_player(); 
	inv = all_inventory(me);

return ("����������ȥ�����ݵĸɽ��򸾰ɡ�\n");

	for(i=0; i<sizeof(inv); i++) {
        if((int)(inv[i]->query("weapon_prop")&&inv[i]->query("ownmake")))
        return "�����ϲ�����������"; 


        if(me->is_busy())
        return "����һ��������û����ɡ�";

        gold = present("gold_money", this_player());
        if( !gold) return "������û�н��ӡ�";

        if((int) gold->query_amount() < 101)
        return "������û����һ�������ӡ�";

	if (me->query("weapon/type")) {
		switch((string)me->query("weapon/type"))
		{
			case "��":
			weapon = new("/d/npc/m_weapon/weapon/m_sword");
			weapon->move(me);
        gold->add_amount(-100);
        me->start_busy(5);
                        return "�޺���,��quit,�����µ�½һ��!"; 
			case "��":
			weapon = new("/d/npc/m_weapon/weapon/m_blade");
			weapon->move(me);
        gold->add_amount(-100);
        me->start_busy(5);
			return "�޺���,��quit,�����µ�½һ��!"; 
			case "��":
			weapon = new("/d/npc/m_weapon/weapon/m_whip");
			weapon->move(me);
        gold->add_amount(-100);
        me->start_busy(5);
			return "�޺���,��quit,�����µ�½һ��!"; 
			case "��":
			weapon = new("/d/npc/m_weapon/weapon/m_staff");
			weapon->move(me);
        gold->add_amount(-100);
        me->start_busy(5);
			return "�޺���,��quit,�����µ�½һ��!"; 
			case "��":
			weapon = new("/d/npc/m_weapon/weapon/m_club");
			weapon->move(me);
        gold->add_amount(-100);
        me->start_busy(5);
			return "�޺���,��quit,�����µ�½һ��!"; 
		}
          }
else return "�����������"; 
}

}