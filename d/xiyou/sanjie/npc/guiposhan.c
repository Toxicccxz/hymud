// guiposhan.c ����ɽ

#include <ansi.h>
inherit NPC;

void create()
{
  string str;
  int i = random(5)+1;
  set_name(HIR"����ɽ"NOR, ({"gui poshan","gui"}));
  set("gender", "����");
  set("age", 40);
  set("long","�������ӣ����Ժö�\n");
  set("title", HIC"��ʬ��"NOR);
  set("attitude", "aggressive");
  set("combat_exp", 1000000*i);
  set("daoxing", 1000000*i);
  set("per", 40);
  set_skill("parry", 40*i);
  set_skill("unarmed", 40*i);
  set_skill("dodge", 40*i);
  set_skill("blade", 40*i);

  set("max_sen",2000*i);
  set("max_gee",2000*i);
  set("max_gin",2000*i);
  set("force",2000*i);
  set("mana",2000*i);
  set("max_force",2000*i);
  set("max_mana",2000*i);
  set("force_factor",20*i);
  setup();
  carry_object("/d/xiyou/sanjie/obj/jinjia")->wear();
  carry_object("/d/xiyou/sanjie/obj/qinghong")->wield();
}