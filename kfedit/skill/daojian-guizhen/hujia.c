// This is player's own perform (Write by Lonely@nt2)
// Create by ��ݶ(Xiaot) at Fri Mar 10 11:38:48 2006
// ����ʮ����(hujia)

#include <ansi.h>
#include <combat.h>

#define PFM "��" HIW "����ʮ����" NOR "��"

inherit F_SSERVER;


string *weapon_sk = ({
        "sword", "blade", "staff", "whip", "club", "hammer", "axe"
});

int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp;
        int count;
        int i, attack_time;


        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail(PFM "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (member_array("sword", weapon_sk) != -1)
        {
        if (! objectp(weapon = me->query_temp("weapon"))
           || (string)weapon->query("skill_type") != "sword"
           && (string)weapon->query("skill_type") != "blade" )
                return notify_fail("����ʹ�õ��������ԣ�����ʩչ" PFM "��\n");
        } else
        {
                if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                        return notify_fail(PFM "ֻ�ܿ���ʹ�á�\n");             
        }
        
        if ((int)me->query_skill("daojian-guizhen", 1) < 400)
                return notify_fail("��" + to_chinese("daojian-guizhen") + "������죬����ʩչ" PFM "��\n");

        if (member_array("sword", weapon_sk) == -1)
        {
                if (me->query_skill_prepared("sword") != "daojian-guizhen")
                        return notify_fail("��û��׼��" + to_chinese("daojian-guizhen") + "������ʩչ" PFM "��\n");
        }
        	if( me->is_busy() )
		return notify_fail("( ����һ��������û����ɣ�����ʩ���ڹ���)\n");
        if (me->query("neili") < 300)
                return notify_fail("�����ڵ���������������ʩչ" PFM "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIW "$N����֧�ã���������ӳ�����̾һ�������ּ���֮�⣬����һ�С�����ʮ���ġ���" + "\n" + NOR;

        ap = me->query_skill("blade",1);
        dp = target->query_skill("dodge",1);
        attack_time = 6;

        if (ap * 2 / 3 + random(ap * 2) > dp)
        {
                msg += HIM "$n��ȻĿ���ڴ��������ܶ�ÿ��������������У�" + "\n" NOR;
                count = ap / 10;

        } else
        {
                msg += NOR + CYN "����$pʶ����$P��һ�У�С��Ӧ��$P�Ĺ�����" + "\n" NOR;
                count = 0;
        }

        message_combatd(msg, me, target);

        attack_time += random(6);
        if (attack_time > 12)
                attack_time = 12;

        me->add("neili", -attack_time * 10);
                me->add_temp("apply/attack", count);
                me->add_temp("apply/damage", 1200);
        for (i = 0; i < attack_time; i++)
        {
                if (! me->is_fighting(target))
                        break;

                if (random(2) && ! target->is_busy()) target->start_busy(2);

                COMBAT_D->do_attack(me, target, (member_array("sword", weapon_sk) == -1 ? 0 : weapon), 0);
        }
        me->add_temp("apply/attack", -count);
        me->add_temp("apply/damage", -1200);
        me->start_busy(3 + random(attack_time/ 3));

        return 1;
}
