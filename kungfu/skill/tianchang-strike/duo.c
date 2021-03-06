// duo.c 空手夺白刃

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
      string msg;
      object weapon, weapon2;
      int skill;
	int exp1,exp2,comb1,comb2;
	int skill1,skill2,neili1,neili2,str1,str2;

      me->clean_up_enemy();
      target = me->select_opponent();

      skill = me->query_skill("tianchang-strike",1);

      if( !(me->is_fighting() ))
              return notify_fail("空手夺白刃只能对战斗中的对手使用。\n");

      if (objectp(weapon2 = me->query_temp("weapon")))
              return notify_fail("你必须空手。\n");

      if (!objectp(weapon = target->query_temp("weapon")))
         return notify_fail("对方没有兵刃，你不用担心。\n");

      if( skill < 100)
              return notify_fail("你的天偿掌法等级不够, 不能使用空手夺白刃！\n");

	if ((int)me->query_skill("lengyue-shengong", 1)<100)
		return notify_fail("你的冷月神功火候不够。\n");



	if( me->query("neili") < 300 )
		return notify_fail("你的内力不够，无法使用空手折梅！\n");

        if( !living(target))
                return notify_fail("对方都已经这样了，还夺什么，去捡好了！\n");

	message_vision(CYN"\n$N闪电般伸出右手，瞅准$n武功破绽之处，抓向$n手中的"+weapon->query("name")+CYN"。\n\n"NOR,me,target);

	exp1 = me->query("combat_exp");
	exp2 = target->query("combat_exp");
	skill1 = me->query_skill("tianchang-strike");
	skill2 = target->query_skill("parry");
	neili1 = me->query("neili");
	neili2 = target->query("neili");
	str1 = me->query_str();
	str2 = target->query_str();

	if (exp1 < exp2/3)
	{
		message_vision("谁知$n露出此破绽乃是诱敌，一个变招反而向$N猛攻而至。\n",me,target);
		me->start_busy(1+random(3));
		me->add("neili",-50);
		COMBAT_D->do_attack(target,me,me->query_temp("weapon"));
		return 1;
	}

	if (exp1 > random(exp2))
	{
	message_vision(HIR"$n眼睛一花，手中"+weapon->query("name")+HIR"已被$N反手抓到。\n\n"NOR,me,target);
		comb1 = str1*neili1*skill1;
		comb2 = str2*neili2*skill2;
	
		if (comb1 > comb2 * 3/5 )
		{
if (!weapon->query("systemmake") && !weapon->query("ownmake"))
{
			message_vision(HIW"$n只觉一股寒气自"+weapon->query("name")+HIW"传了过来，整个手臂一阵冰凉，手中"+weapon->query("name")+HIW"脱手而出！\n"NOR,me,target);
			weapon->move(environment(me));
			me->add("neili",-50);
}
			return 1;
		}
			message_vision(HIW"$N默运冷月寒气，催动寒冷真气注入"+weapon->query("name")+HIW"，$n见状赶紧催动体内真气与其相抗。\n\n"NOR,me,target);
			message_vision(HIG"$N只觉$n手中的"+weapon->query("name")+HIG"传来一阵炎热的气劲，将自己的冷月寒气消弭于无形，只好放手，飘身退开。\n"NOR,me,target);
			me->start_busy(1+random(2));
			me->add("neili",-150);
			return 1;

	}
	message_vision("可是$n的看破了$N的企图，立刻采取守势，飘身躲开$N的攻击。\n",me,target);
	me->add("neili",-50);
	me->start_busy(1+random(2));
	return 1;
}
