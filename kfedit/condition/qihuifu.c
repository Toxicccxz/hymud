// bonze_drug.c
#include <ansi.h>
#include <login.h>

int update_condition(object me, int duration)
{
	int huifusl;
	if (duration < 1) return 0;

        huifusl=(int)me->query_temp("huifusl",1);
        if (!huifusl) huifusl=100;
	me->apply_condition("qihuifu", duration - 1);
message_vision(HIY"只见$N的伤口红光流动！\n"NOR, me);

if (!me->query_condition("qihuifu"))
{
message_vision(HIG"只见$N的伤口恢复了正常！\n"NOR, me);
message_vision(HIG"只见$N的伤口恢复了正常,妙伤决的作用已经结束！\n"NOR, me);
me->delete_temp("huifusl");
return 1;
}

		
	call_out("check_fight", 5, me, huifusl);

	return 1;
}

string query_type(object me)
{
	return "job";
}


void spec_recover(object me, int sl)
{
	int i,huifusl;
        huifusl=(int)me->query_temp("huifusl",1);
        if (!huifusl) huifusl=100;
        if (!sl) sl=huifusl;
		if (me->query("max_qi") > me->query("eff_qi") || me->query("eff_qi") > me->query("qi")
		&& random(2)==0) {
			message_vision(HIR"只见$N的伤口在妙伤决的作用下红光流动，血流顿时止住了，连伤口似乎也开始渐渐愈合！\n"NOR, me);
			me->add("eff_qi", 100 + sl);
			if (me->query("eff_qi") > me->query("max_qi"))
				me->set("eff_qi", me->query("max_qi"));
			me->add("qi", 100 + sl);
			if (me->query("qi") > me->query("eff_qi"))
				me->set("qi", me->query("eff_qi"));
		}

	return;
}

void check_fight(object me,int sl)
{

	if (!me) return;

	
if (!me->query_condition("qihuifu"))
{
return;
}


if (me->query_condition("qihuifu"))
{
spec_recover(me, sl);
call_out("check_fight", 5, me,sl);
}
}

void remove_effect(object me)
{
message_vision(HIG"只见$N的伤口恢复了正常,妙伤决的作用已经结束！\n"NOR, me);
        return;
}