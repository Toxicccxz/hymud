// tie@fengyun

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	int i,a;
	object weapon;
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
                return notify_fail("�ٲ������Ĳ�����ӿֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");

	if( (int)me->query("neili") < 400  ) 
		return notify_fail("�������������\n");
        if( (int)me->query_skill("xuantie-sword", 1) < 50 )
                return notify_fail("����ٲ�����������죬�����ò�����ӿ��\n");

        extra = me->query_skill("xuantie-sword",1) / 10;
        me->add_temp("apply/attack", 100);
        me->add_temp("apply/damage", 2000);

        msg = HIR  "$Nʹ�����ٲ������УݵĲ�����ӿ�����е�"+ weapon->name() +" һ������һ�������Ļ���$n��" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        msg =  HIW "һ�����˴�������ʧ��������\n" NOR;
        message_vision(msg, me, target);
a=extra/4;
if (a> 10) a=10;
        for(i=0;i<a;i++)
	{
        msg = HIY "$N���Ƴ���һ�����ˣ�����������\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	}
	i = extra/4;
        me->add_temp("apply/attack", -100);
        me->add_temp("apply/damage", -2000);
	me->add("neili", - 40 * i);
	me->start_busy(2);
	return 1;
}
