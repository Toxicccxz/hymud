// migong lev14

#include <ansi.h>

inherit NPC;


void create()

{
    
   set_name(WHT"����"NOR, ({ "yin long" , "long" , "dragon" }));
                set("race", "Ұ��");
       set("long",
"һ���޴����ɫ�������������㣬�������˹�����
��\n");
              set("attitude", "aggressive");
                set("vendetta/authority",1);

set("limbs", ({ "ͷ��", "����", "β��" }) );
        set("verbs", ({ "bite" , "claw"}) );
  set("max_jing",25000+random(10000));
  set("max_qi",30000+random(10000));
  set("neili",39999);
  set("max_neili",39999);
  
      set("dex",50);
      set("con",50);
     set("str" ,50);
       
    set("age", 80);

       set("shen_type", -1);

        set("intellgent",1);

	set("pursuer",1);

        set("combat_exp", 9000000+random(2000000));
            set_temp("apply/attack", 100);
        set_temp("apply/damage", 800);
        set_temp("apply/armor", 800);
        set_temp("apply/defence",100);
      set_skill("dodge", 400+random(100));

      set_skill("unarmed", 400+random(100));

       set_skill("dragon", 400+random(100));

      map_skill("unarmed", "dragon");

      map_skill("dodge", "dragon");

    prepare_skill("unarmed", "dragon");
 set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
               
    (: perform_action, "unarmed.penhuo" :),

    (: perform_action, "unarmed.tuwu" :),

 }) );
     
   setup();

    
carry_object("/d/migong/obj/longdan");
     

}

void init( )

{
	object ob;	
        remove_call_out("hunting");
	if( interactive(ob = this_player())  ) {
ob->start_busy(1);
        call_out("hunting",0);
        }
	if(!environment()->query("no_fight"))
        call_out("hunting",0);
}

void hunting()
{
	int i;
        object *ob;
        ob = all_inventory(environment());
        for(i=sizeof(ob)-1; i>=0; i--) {
        if( !ob[i]->is_character() || ob[i]==this_object() || !living(ob[i])) continue;
        if(ob[i]->query("vendetta/authority")) continue;
                kill_ob(ob[i]);
                ob[i]->fight(this_object());
        }
}

void die()
{
        object ob, me, corpse;int exp,pot;
        
        ob = this_object();
        me = query_temp("last_damage_from");
if (!me) return;            
              me->add("score",1);
        message_vision(WHT"$Nһ��ŭ�𣬻�����Ѫֱ���������ɵ��ڵء�\n"NOR,ob,me);
  exp=60+random(20);
        if((int)me->query("combat_exp") < 28000000) exp=exp*5;
pot=exp*3/4;
        message("vision", me->name() + "�����"+exp+"�㾭���"+pot+"��Ǳ�ܡ�\n", me);
        me->add("combat_exp",exp);
        me->add("potential",pot);

	::die();
}

