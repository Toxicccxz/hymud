// Last Modified by winder on Sep. 12 2001
// lian.c ���㽣���������־�

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
#define PNAME "�������־�"
int perform(object me, object target)
{
	object weapon;
	string msg;
	int i, attack_time,sword_lvl;
	int flag;
	string fskill,sskill,bskill,pfname,pskill;

	sskill = explode(__FILE__,"/")[<2];
	pfname = explode(__FILE__,"/")[<1][0..<3];


	if( !objectp(target) ) {flag =1;target = offensive_target(me);}
	
	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )
		return notify_fail(PNAME"ֻ�ܶ�ս���еĶ���ʹ�á�\n");
		
	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");

        if( me->query_skill("nei-bagua",1) <=50)
                 return notify_fail("�ڰ��Եȼ�������\n");
	bskill = "luoyan-jianfa";



	if( (int)me->query_skill(sskill, 1) < 120 )
		return notify_fail("���"+to_chinese(sskill)+"������죬����ʹ��"+PNAME+"��\n");

	if( (int)me->query("max_neili") < 500 )
		return notify_fail("���������Ϊ������\n");

	if( (int)me->query("neili") < 400 )
		return notify_fail("�������������\n");

	me->add("neili", -200);

	msg = HIY"$N"HIY"ʹ�����㽣���������־�����ʽ��Ȼ��죬��������$n��\n"NOR;
	message_combatd(msg, me, target);
	if(random(me->query("combat_exp"))>(int)target->query("combat_exp")/20)
	{
		attack_time = random((int)me->query_skill(bskill, 1)/20);
		sword_lvl=(int)me->query_skill(bskill,1)/10;
		if(attack_time < 2) attack_time = 2;
		if(attack_time > 10) attack_time = 10;
		if(attack_time > 5) 
		{
			attack_time = attack_time - 4;
			attack_time = 5 + random(attack_time);
		}
if (random(3)==0) target->start_busy(2);
	 msg = YEL"���$p��$Pһ�ּ��������޻�����ԣ��\n"NOR;
			me->add_temp("apply/damage",500);	
			me->add_temp("apply/attack",80);
		for(i = 0; i < attack_time; i++)
		{
			if (flag == 1) target = offensive_target(me);
			if (!objectp(target)) break;
			COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
		}
		me->add_temp("apply/damage",-500);
		me->add_temp("apply/attack",-80);
		me->start_busy(2);
		//target->start_busy(1);
	}
	else
	{
		msg = CYN"����$p�������ȣ�һ�¾���ס��$P�Ľ�·��\n"NOR;
		me->start_busy(1);
	}
	message_combatd(msg, me, target);

	return 1;
}
string name() {return replace_string(replace_string(PNAME,"��",""),"��","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"֮"+name()+WHT"��"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		�Ե�����������

	����Ҫ��
		���㽣��120��
		������Ϊ500
		����400
HELP
	);
	return 1;
}
