//Cracked by Roath
// rewritten by snowcat on 12.12.1997

inherit NPC;
#include "/d/migong/romnpc2.c"
#include <ansi.h>
void create()
{
  set_name("李天王", ({"li tianwang", "li", "tianwang"}));
  set("gender", "男性");
  set("age", 100);
  set("attitude", "friendly");
  set("combat_exp", 1250000);
  set("combat_exp", 2000000);

  set("per", 25);
  set_skill("dodge", 180);
  set_skill("force", 180);

  set("max_jing",1800);
  set("max_qi",1800);
  set("max_jing",1800);
  set("neili",1800);
  set("max_neili",1800);
  set("max_neili",1800);
  set("force_factor",125);
  setup();
  initlvl((500+random(500)),32);
  carry_object("/d/obj/armor/jinjia")->wear();

}

void announce_success (object who)
{
  int i;

  if (who->query("combat_exp") < 10000)
    return;
  if (who->query("obstacle/jilei") == "done")
    return;
  if (who->query("obstacle/firemount") != "done")
    return;
  if (! who->query_temp("obstacle/jilei_yumian_killed"))
    return;
  if (! who->query_temp("obstacle/jilei_niumo_killed"))
    return;
  i = random(800);
  who->add("obstacle/number",1);
  who->set("obstacle/jilei","done");
  who->add("combat_exp",i+33000);
   who->add("potential",i*8);
   who->add("mpgx",10);who->add("expmax",2);
  command("chat "+who->query("name")+"积雷山显神通，摩云洞降牛魔！");
  message("channel:chat",HIY"【过关斩将】观音菩萨(guanyin pusa)："+who->query("name")+"闯过西行取经[1;37m第二十一关！\n"NOR,users());
  tell_object (who,"你赢得了"+chinese_number(i+32000)+"点经验"+
               chinese_number(i*8)+"点潜能"+"十点门派贡献 二点成长上限！！\n");
  who->save();
}


