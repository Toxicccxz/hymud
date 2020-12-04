// lifeheal.c

#include <ansi.h>

int exert(object me, object target)
{
    if ((!target)||target->query("id")==me->query("id"))
		return notify_fail("��Ҫ������Ϊ˭���ˣ�\n");

	if( me->is_fighting() || target->is_fighting())
		return notify_fail("ս�����޷��˹����ˣ�\n");

	if(target == me)
		return notify_fail("��û��Ϊ�Լ����˵�������\n");

	if ((int)me->query_skill("jiuyin-zhengong", 1) < 50)
		return notify_fail("��ľ����湦��Ϊ��������\n");

	if( (int)me->query("max_neili") < 300 )
		return notify_fail("���������Ϊ������\n");

	if( (int)me->query("neili") < 150 )
		return notify_fail("�������������\n");

	if( (int)target->query("eff_qi") >= (int)target->query("max_qi") )
		return notify_fail( target->name() + "��δ���ˣ�\n");

	message_combatd(
		HIB "$N�������������ڹ�������������$n���ģ����վ����ͽ�ƪ��ʼ�˹�����....\n\n"
		"���˲��ã�$N��ͷ��ð������ĺ��飬$n�³�һ����Ѫ����ɫ������������ˡ�\n" NOR,
		me, target );

	target->receive_curing("qi", 10 + (int)me->query_skill("force") );
	target->add("qi", 10 + (int)me->query_skill("force") );
	if( userp(target) && (int)target->query("qi") > (int)target->query("eff_qi") ) target->set("qi", (int)target->query("eff_qi"));
	if( !userp(target) && (int)target->query("qi") > (int)target->query("max_qi")*5 ) target->set("qi", (int)target->query("max_qi"));

if (target->query("eff_jing",1) < target->query("max_jing",1))
{
	target->receive_curing("jing", 10 + (int)me->query_skill("force") );
	target->add("jing", 10 + (int)me->query_skill("force") );
	if( (int)target->query("jing") > (int)target->query("eff_jing") )
		target->set("jing", (int)target->query("eff_jing"));
}
	me->add("neili", -50);
        target->start_busy(2);
	return 1;
}