// migong lev7 ���� ���

#include <ansi.h>

inherit NPC;


string* names = ({
"��","Ǯ","��","��","��","��","֣","��","��","��","��","��",
"��","��","��","��","��","��","��","��","��","��","ʩ","��",
"��","��","��","��","��","κ","��","��","��","л","��","��",
"��","ˮ","�","��","��","��","��","��","��","��","��","��",
"³","Τ","��","��","��","��","��","��","ɵ","��","Ԭ","��",
"��","��","ʷ","��","��","��","�","Ѧ","��","��","��","��",
"��","��","��","��","��","��","��","��","��","��","ʱ","��",
"Ƥ","��","��","��","��","��","Ԫ","��","��","ӯ","ƽ","��",
"��","��","Ф","��","Ҧ","��","տ","��","��","ë","��","��",
"��","��","��","��","��","��","��","��","̸","��","é","��",
"��","��","��","��","��","ף","��","��","��","��","��","��",
"��","��","֧","��","��","��","¬","Ӣ","��","��","��","˧",
"˾��","�Ϲ�","ŷ��","�ĺ�","���","����","����","����","�ʸ�",
"ξ��","����","�̨","����","����","���","����","����","̫��",
"����","����","����","ԯ��","���","����","����","����","Ļ��",
"˾ͽ","ʦ��","��","��ľ","����","����","���","����","����",
"����","��ֺ","�й�","�׸�","����","����","�ַ�","��۳","Ϳ��",
"��ǧ","����","����","�Ϲ�","����","�麣","����","΢��","����",
"����","����","����","����","�Ϲ�",

"��","��","��","��","��","��","��","Ĳ","��","��","ī","��",
"��","��","��","��","١","��","��","��","��","��","��","��",
"��","ʯ",
});

string* nm2 = ({
"��","Т","��","��","��","��","��","��","��","��","��","»","��","С","��",
"��","��","��","��","��","��","��","֮","��","��","ʱ","��","��","��","��",
"��","��","��","��","��","��","��","��","Ϊ","��","","","","","","","","",
"","","","","","","","","","","","","","",
});

string* nm3 = ({
"��","��","��","��","��","��","��","��","��","��","��","��",
"��","��","��","��","��","�","��","��","��","��","��",
"��","��","��","��","��","��","��","��","��","��","��",
"��","��","��","��","��","��","��","��","ǿ","��","ɽ",
"̩","��","ͦ","ΰ","��","��","��","��",
"��","�","��","��","��","��",
});


void create()
{
  
       int i = random(sizeof(names));
   set_name(names[i]+nm2[random(sizeof(nm2))]+nm3[random(sizeof(nm3))], 
 ({ "man" }));
 
set("title", HIC"����ͽ"NOR);
   set("gender", "����" );
 set("long",
"����ʦ�ţ����������ķ�ͽ��\n");
        set("attitude", "aggressive");
        set("vendetta/authority",1);
	  set("force_factor",100+random(200));
  set("max_qi",4000+random(2000));
  set("max_jing",4500+random(2000));
  set("max_sen",4500+random(2000));
  set("max_neili",4500+random(2000));
  set("max_mana",4500+random(2000));
  set("eff_neili",4500+random(2000));
  set("neili",4000+random(2000));
        set("per", 1);
        set("age", 32);

       set("jiali" , 100);
        set("shen", -10000);
        set("intellgent",1);
	set("pursuer",1);
        set("combat_exp", 1700000+random(500000));
                 set_skill("unarmed", 250+random(40));

 set_skill("claw", 250+random(40));

set_skill("huagong-dafa", 250+random(40));

set_skill("force", 250+random(40));
set_skill("chousui-zhang", 250+random(40));

set_skill("parry", 250+random(40));

set_skill("dodge", 250+random(40));

set_skill("zhaixinggong", 250+random(40));

set_skill("sanyin-wugongzhao", 250+random(40));

  
        map_skill("unarmed", "chousui-zhang");
  
      map_skill("parry", "qianye-shou");

 map_skill("force", "huagong-dafa");

 map_skill("dodge", "zhaixinggong");
 
map_skill("claw"  , "sanyin-wugongzhao");
prepare_skill("unarmed", "chousui-zhang");
prepare_skill("claw", "sanyin-wugongzhao");
set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
              	
      (: perform_action, "unarmed.zhaohuo" :),
	
       (: perform_action, "unarmed.zhaohuo" :),
	
(: perform_action, "unarmed.biyan" :),
	
(: perform_action, "unarmed.huoqiu" :),
	
(: perform_action, "unarmed.huoqiang" :),

(: perform_action, "unarmed.yinhuo" :),

          (: exert_function, "recover" :),
    (: exert_function, "powerup" :),
  }) );
            set_temp("apply/attack", 100);
        set_temp("apply/defense", 100);
 
          set_temp("apply/armor", 100);
        set_temp("apply/damage", 100);


        setup();

        carry_object("/d/migong/obj/cloth")->wear();
    
add_money("silver", random(10));


}

void init( )
{
	object ob;	
        remove_call_out("hunting");
	if( interactive(ob = this_player())  ) {
ob->start_busy(1);
        call_out("hunting",0);
        }
	if(!environment()->query("no_fight") && random(10) < 5)
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
        me->add("shen",10);

        message_vision(WHT"$N������Ѫ����,���ض�����\n"NOR,ob,me);
exp=8+random(5);
        if((int)me->query("combat_exp") < 4500000) exp=exp*5;
pot=exp*3/4;
        message("vision", me->name() + "�����"+exp+"�㾭���"+pot+"��Ǳ�ܡ�\n", me);
        me->add("combat_exp",exp);
        me->add("potential",pot);

	::die();
}
