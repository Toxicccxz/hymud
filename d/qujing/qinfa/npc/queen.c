
inherit NPC;

void create()
{
  set_name("����", ({"wang hou", "hou", "queen"}));
  set ("long", "�շ�������������������ֹ��ׯ��\n");
  set("title", "�շ���");
  set("gender", "Ů��");
  set("age", 30);
  set("combat_exp", 100000);
  set("combat_exp", 50000);
set("can_sleep",1);
  set_skill("blade", 20);
  set_skill("dodge", 20);
  set_skill("parry", 20);
  set_skill("unarmed", 20);
  set_skill("force", 20);
  set("max_jing", 5000);
  set("max_qi", 5000);
  set("max_neili", 5000);
  set("neili", 5000);
  set("force_factor", 4);

  set("can_sleep",1);
  setup();
 
  carry_object("/d/obj/cloth/gongpao")->wear();
}

void check_hair ()
{
  object me = this_object();

  if (me->query("disable_type") == "<˯����>" &&
      me->query_temp("disabled"))
  {
    call_out("check_hair",1);
    return;
  }

  if (me->query_temp("has_said"))
    return;

  message_vision ("$NͻȻ����ʶ��������ͷ�����ţ��Դ�ȫ����ˣ�\n",me);
  message_vision ("$Nһ��ѣ�Σ����ˤ���ڵأ�\n",me);
  me->set_temp("has_said",1);
}
�