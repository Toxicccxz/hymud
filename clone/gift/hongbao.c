// 红包

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIR"红包"NOR, ({"hong bao", "bao", "hong"}));
	set_weight(10);
set("no_drop", 1);
set("no_put", 1);
    set("no_bug", 1);
set("liwu",1);
    set("no_steal", 1);
    set("no_get", 1);
    set("value", 0);
	if (clonep())
		set_default_object(__FILE__);
	else {
    set("no_give","每个人只有一个，你都这么大方！\n");
set("no_drop", 1);
set("no_put", 1);
    set("no_get", 1);
    set("no_give", 0);
    set("value", 0);
		set("long", "一个用红纸制作而成的"+HIR"红包，"NOR+"似乎可以撕开(opengift)。\n");
		set("unit", "个");
	}
}
  void init()
{
  add_action("do_open","opengift");
}
int do_open()
{
object ob;
	int exp,pot,score;
object corpse;
        object me = this_player();
exp = 888+random(888);
pot = exp*2/3;
score=18;
me->add("combat_exp",exp);
me->add("potential",pot);
me->add("max_neili",score);


	this_player()->start_busy(50);
	message_vision("$N打开了红包，只觉得自己又变利害了一些 !\n", this_player());
tell_object(me,HIY"你被奖励了：\n" +
             chinese_number(exp) + "点实战经验\n"+
             chinese_number(pot) + "点潜能\n" +
            chinese_number(score)+"点内力\n"NOR);

	destruct(this_object());
	return 1;
}
void owner_is_killed()
{
	destruct(this_object());
}