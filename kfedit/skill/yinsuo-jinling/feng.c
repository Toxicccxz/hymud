// feng.c �������� ��Ѩ
// By Kayin @ CuteRabbit Studio 1999/3/21 new

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	object ob;
	string msg;
	int i;
	ob=me->query_temp("weapon");
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("��Ѩֻ�ܶ�ս���еĶ���ʹ�á�\n");
	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "whip")
			return notify_fail("��ʹ�õ��������ԡ�\n");

	if((int)me->query_skill("yunv-xinfa",1) < 100)
		return notify_fail("����Ů�ľ��Ĺ����������ܷ�ס����Ѩ��!\n");

	if((int)me->query_skill("yinsuo-jinling",1) < 150)
		return notify_fail("�������������Ϊ����,Ŀǰ�����ܷ�ס����Ѩ��!\n");

	if((int)me->query("neili") < 800)
		return notify_fail("���������ڲ���, ���ܷ�Ѩ! \n");

	if( target->is_busy() )
		return notify_fail(target->name() + "��Ѩ���Ѿ������ס�ˣ��㻹��ʲô\n");

	msg = HIC "$Nʹ��"HIY"��������"HIC"���ϳ˵�Ѩ��������"+ ob->name() +""HIC"��ס��$n��ȫ��ҪѨ, ʹ$n�������á�\n";

	if(random(me->query("combat_exp")) >= target->query("combat_exp")/2)
	 {
		msg += "���$p��̴�д�Ѩ���㣬���ܶ�����\n" NOR;
		target->start_busy( (int)me->query_skill("yinsuo-jinling",1) / 40 + 4);
		me->add("neili", -150);
	} else {
		msg += HIG "����$p�����������ڶ����$P�Ĺ�����\n" NOR;
		me->start_busy(1);
	}
	message_vision(msg, me, target);
 
 if((int)me->query_skill("yinsuo-jinling",1) > 200)
 {
  me->add_temp("apply/attack", 80);
        me->add_temp("apply/damage", 800);
        me->add("neili", -100);
	for (i = 0; i < 7; i++)
	{
                if (! target->is_busy() && random(3) == 1)
                       target->start_busy(2);
 
         msg = HIC "һ��������У�$N�������"+(i+1)+"�ޣ�\n"NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

	}
        me->add_temp("apply/attack", -80);
        me->add_temp("apply/damage", -800);
}
	return 1;
}