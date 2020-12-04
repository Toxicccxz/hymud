// roar.c ����һЦ

#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
	object *ob;
	int i, skill, damage;

	if ((int)me->query("neili") < 100)
		return notify_fail("�������������\n");

	skill = me->query_skill("force");

	me->add("neili", -100);
	me->receive_damage("qi", 10);

	if (environment(me)->query("no_fight"))
		return notify_fail("���ﲻ�ܹ�������! \n");

	if( !me->is_fighting())
		return notify_fail("�㲻�ڴ�ܣ��������ʲô?\n");

	me->start_busy(5);
	message_combatd(HIC "$N" HIC "������Ц������ԶԶ�Ĵ���"
                        "��ȥ�����粨����һ�����˷���\n" NOR, me);

	ob = all_inventory(environment(me));
	for (i = 0; i < sizeof(ob); i++)
        {
		if (! ob[i]->is_character() || ob[i] == me)
			continue;

		if (skill / 2 + random(skill / 2) < (int)ob[i]->query("con") * 2)
			continue;

if( !ob[i]->is_fighting(me) ) continue;
if( !living(ob[i]) || ob[i]==me ) continue;
if( !ob[i]->is_character() || ob[i]->is_corpse() ) continue;
		
		damage = skill - ((int)ob[i]->query("max_neili") / 20);
		if (damage > 5000) damage=5000;
		if (damage > 0)
                {

			ob[i]->receive_damage("jing", damage * 2);
			if ((int)ob[i]->query("neili") < skill * 2)
				ob[i]->receive_wound("jing", damage, me);
		        tell_object(ob[i], "��ֻ������ǰһ����ڣ�������ѣ......\n");
		}
	}
	return 1;
}