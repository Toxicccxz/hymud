// created 12/18/1997 by snowcat

inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
  set_name("银角大王", ({ "yinjiao dawang", "yinjiao", "dawang", "wang" }));
  set("title", "莲花洞");   
  set("long", "一位神态傲然的莲花洞妖王。\n");
  set("gender", "男性");
  set("age", 54);
  set("attitude", "heroism");
  set("per", 30);
  set("max_qi", 1800);
  set("max_jing", 1800);
  set("max_jing", 1800);
  set("neili", 1200);
  set("max_neili", 1200);
  set("force_factor", 80);
  set("max_neili", 1200);
  set("neili", 1200);
  set("mana_factor", 80);
  set("combat_exp", 950000);
  set("combat_exp", 18200000);


  setup();
  initlvl((320+random(330)),60);
  carry_object("/d/obj/cloth/shoupipifeng")->wear();
  if (clonep())
  {
    object ob = new("/d/qujing/pingding/obj/pingreal");
    if (!ob) ob = new("/d/qujing/pingding/obj/pingfake");
    ob->move(this_object());
  }
}

void destruct_me (object me)
{
  destruct (me);
}

void die ()
{
  object me = this_object();
  object ob = query_temp("my_killer");
  object fabao = present ("fabao",me);
object taishang = new ("/d/qujing/pingding/npc/taishang");
  if (ob)
  {
    ob->set_temp("obstacle/pingding_yinjiao_killed",1);
    taishang->announce_success (ob);
  destruct (taishang); 
  }
  message_vision ("\n$N无可奈何地现了真身，原来是太上老君的银角童子。\n",me);
  message_vision ("\n银角童子鞠了个躬：时辰已到，去见太上老君也。\n",me);
  message_vision ("银角童子往外奔去",me);
  if (fabao)
  {
    message_vision ("，丢下一只$n。\n",me,fabao);
    fabao->move(environment(me));
  }
  else
    message_vision ("。\n",me);
::die();
}



void unconcious ()
{
  die ();
}

int accept_fight(object ob)
{
  
  kill_ob(ob);
  return 1;
}

void kill_ob (object ob)
{
  object me = this_object();

  set_temp("my_killer",ob);
  call_out ("hurting",random(5)+5,me,ob);  
  ::kill_ob(ob);
}

void hurting (object me, object ob)
{
  object fabao = present ("fabao",me);

  if (fabao)
    fabao->ji_ob (ob);

  remove_call_out ("hurting");  
  call_out ("hurting",random(10)+10,me,ob);  
}

�
