// tie@fengyun

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon;
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�۵�ħʽ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	extra = me->query_skill("tmquan",1) ;
	if(extra < 70 ) return notify_fail("��ģ���ħȭ�ݲ���������\n");

	if( (int)me->query("neili", 1) < 500 )
		return notify_fail("�����ڵ�����������\n");

	msg = HIR "\n$N˫�۱�����һ�У۵�ħʽ�ݣ�˫��£��$n��" NOR;
	if(random((int)me->query("combat_exp")) >= (int)target->query("combat_exp")/2 || random(8)==0)
	{
	message_vision(msg+"\n",me,target);
	message_vision( HIR "$N����������ȫ��������Ӱ��ס�� һ��Ѫ����$N������ӿ������\n" NOR,target);
	target->receive_wound("qi",extra*3);
	me->receive_heal("qi",extra*3);
COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
	}	
	else{
        weapon = me->query_temp("weapon");
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
	}
	me->add("neili", -200);
	me->start_busy(2);
	return 1;
}