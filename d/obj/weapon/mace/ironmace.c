//ironmace.c
//created 5-30-97 pickle

#include <weapon.h>
#include <ansi.h>

inherit STAFF;

void create()
{
  set_name("����", ({"iron mace", "mace", "ironmace"}));
  set_weight(7000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("value", 1000);
    set("material", "iron");
    set("long", "һ����ͨ����ڱޡ�\n");
    set("wield_msg", "$N����һ��$n�����˸���ʽ��\n");
    set("unwield_msg", "$N��$n������䡣\n");
  }
  
  init_staff(15);
  setup();
}
