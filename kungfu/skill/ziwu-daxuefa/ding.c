#include <ansi.h>
#include <combat.h>

#define DING "「" HIC "透骨钉" NOR "」"

inherit F_SSERVER;
 
int perform(object me)
{
        string msg;
        object weapon, target;
        int skill, ap, dp, damage;

	int  neili_wound, qi_wound;

        int  i;
	


        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! me->is_fighting(target))
                return notify_fail(DING "只能对战斗中的对手使用。\n");

        weapon = me->query_temp("weapon");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "dagger")
                return notify_fail("你所使用的武器不对，难以施展" DING "。\n");

        skill = me->query_skill("ziwu-daxuefa", 1);
        if (me->query_skill_mapped("force") != "bluesea-force")
                return notify_fail("你使用的内功必须是南海玄功。\n");
        if (me->query_skill("force",1) < 150)
                return notify_fail("你的内功修为不够，难以施展" DING "。\n");

        if (me->query("neili") < 500)
                return notify_fail("你现在的真气不足，难以施展" DING "。\n");

        if (skill < 100)
                return notify_fail("你子午打穴法修为有限，难以施展" DING "。\n");

        if (me->query_skill_mapped("dagger") != "ziwu-daxuefa")
                return notify_fail("你没有激发子午打穴法，难以施展" DING "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = HIC "$N" HIC "侧身将手中" + weapon->name() + HIC "斜刺而出，一式「"
              HIR "透骨钉" NOR + HIC "」卷带着呼呼风声，将$n" HIC "包围紧裹。\n" NOR;
 
        ap = me->query_skill("dagger");
        dp = target->query_skill("parry");
        if (ap / 2 + random(ap) > dp)
        {
                me->add("neili", -100);
                damage = 500 + ap / 3 + random(ap / 3);
                 damage = 500 + ap  + random(ap / 5);
 target->add("qi",-damage);
		target->add("eff_qi",-damage);
		//target->start_busy(3);
                		target->apply_condition("no_perform",2);
                msg += HIR "顿时只听得“噗嗤”一声，$n" HIR
                                           "胸口被$N" HIR "这一招刺中，溅出一柱鲜血。\n" NOR;
 

                me->start_busy(1);
                if (ap / 3 + random(ap) > dp && ! target->is_busy())
                        target->start_busy(ap / 25 + 1);
        } else
        {
                msg += CYN "可是$p" CYN "的看破了$P" CYN
                       "的招式，巧妙的一一拆解，没露半点"
                       "破绽！\n" NOR;
                me->add("neili", -50);
                me->start_busy(3);
        }
        message_combatd(msg, me, target);

if (skill>300 || !userp(me))
{
msg = HIR "制气钉 $N大笔一起，向$n丹田连点三点，正是那“裴”字的起首三笔，自上而下的划将下来。\n";
	message_vision(msg, me, target);
 
	ap = me->query_skill("dagger") + skill;
	dp = target->query_skill("force") / 3;
	if( dp < 1 )
		dp = 1;
	if( random(ap) > dp )
	{
		if(userp(me))
			me->add("neili",-100);
		msg = HIR"$N笔尖丝毫不差的点中对方要害, $n顿时觉得丹田上一阵刺痛，\n";
		msg += HIR"全身真气狂泄而出！\n" NOR;

		neili_wound = 1000 + (skill*2);
		if(neili_wound > target->query("neili"))
			neili_wound = target->query("neili");

		qi_wound = neili_wound / 5;
		if(qi_wound > target->query("qi"))
			qi_wound = target->query("qi");
		if(qi_wound < 0) qi_wound = 0;
		target->apply_condition("no_perform",3);
		target->add("neili", -neili_wound);
		target->add("qi", -qi_wound);
		target->add("eff_qi", -qi_wound);
		target->start_busy(3);

}
	else
	{
		if(userp(me))
			me->add("neili",-80);
		msg = HIW"可是$n瞬间反应过来，腾挪跳跃，躲过了这次重创。\n"NOR;
		me->start_busy(2);
	}
	message_vision(msg, me, target);	
	
}	

if (skill>600 || !userp(me))
{
 msg = HIY "$N" HIY "一声叱喝，天蝎藏针 手中" + weapon->name() + HIY "连环五刺，招数"
              "层出不穷，闪电般朝$n" HIY "射去！\n" NOR;
        message_combatd(msg, me, target);
        me->add("neili", -80);
                                me->add_temp("apply/attack", 100);
                me->add_temp("apply/damage", 1200);
        for (i = 0; i < 5; i++)
        {

	msg = HIR "天蝎第"+ chinese_number(i+1) +"刺！" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        }
                                me->add_temp("apply/attack", -100);
                me->add_temp("apply/damage", -1200);    
        return 1;
}
        me->start_busy(3);
        return 1;
}