//Cracked by Roath
inherit NPC;

void create()
{
  set_name("�ƺ���", ({"xianhong xing","xing"}));
  set("gender", "����");
  set("age", 10);
  set("title", "���ƶ�����");
  set("long","һ����ü���۵�С������\n");
  set("combat_exp", 100000+random(3000));
  set("combat_exp", 100000);

  set("per", 15);
  set_skill("dodge", 60);
  set_skill("parry", 60);
  set_skill("unarmed", 60);
  set_skill("force", 60);
  set_skill("spells", 60);
  set("max_jing",800);
  set("max_qi",800);
  set("max_jing",800);

  setup();

  carry_object("/d/qujing/kusong/obj/tongjia")->wear();
}

�