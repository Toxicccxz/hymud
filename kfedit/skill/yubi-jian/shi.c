#include <ansi.h>
#include <combat.h>

#define SHEN "��" HIY "����" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        int damage,i;
        string msg, wn;
        object weapon;
        int ap, dp;
        me = this_player();


        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(SHEN "ֻ����ս���жԶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon"))
           || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" SHEN "��\n");

        if ((int)me->query_skill("yubi-jian", 1) < 200)
                return notify_fail("�㽣��������죬����ʩչ" SHEN "��\n");

        if (me->query_skill_mapped("sword") != "yubi-jian")
                return notify_fail("��û�м�������������ʩչ" SHEN "��\n");

        if ((int)me->query_skill("force", 1) < 240)
                return notify_fail("����ڹ���򲻹�������ʩչ" SHEN "��\n");

        if ((int)me->query_skill("dodge", 1) < 240)
                return notify_fail("����Ṧ��򲻹�������ʩչ" SHEN "��\n");  

        if ((int)me->query("max_neili") < 2500)
                return notify_fail("���������Ϊ���㣬����ʩչ" SHEN "��\n");

        if ((int)me->query("neili") < 400)
                return notify_fail("�����ڵ���������������ʩչ" SHEN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        wn = weapon->name();

        msg = HIY "һ����⻮����$N" HIY "��ʧ����Ӱ���٣���Ȼ��ֻ��һ��\n"
              "���ߴ�����£�" + weapon->name() + HIY "�ѽ�$n" HIY "���֡�\n" NOR;


        
        ap = me->query_skill("yubi-jian", 1) +
             me->query_skill("force", 1);

        dp = target->query_skill("dodge", 1) +
             target->query_skill("parry", 1);

        if (ap * 2 / 3 + random(ap) > random(dp) || random(3)==0)
        {
                damage = me->query_skill("yubi-jian", 1) +
                         me->query_skill("force", 1) +
                         me->query_skill("sword", 1);

                damage += random(damage / 2);
damage=damage+600;
                // ʮ��֮һ�ļ��ʿɱ��м�
                if (random(10) <= 1 && ap / 2 < dp)
                {
                        damage = damage / 3;

                        target->add("qi",-damage/2+100);
                        target->add("qi",-damage/3+100);
                        msg +=                   HIG "$n" HIG "��$N" HIG "һ���������\n"
                                                  "����æ������������мܡ�\n��֪$P��"
                                                  "�������Ƿ���$pһ���ƺߣ����˼�������\n"
                                                  "��һ����Ѫ��\n" NOR;
                        me->add("neili", -100);
                        me->start_busy(2 + random(2));
                } else 
                {
                        target->add("qi",-damage+100);
                        target->add("qi",-damage/2+100);

                        msg +=                    HIR "$n" HIR "��$N" HIR "��⻮������"
                                                  "�ײ��ɴ󾪣�\n��ʱ���á����͡�һ������"
                                                  "��͸�������\n" NOR;
                        me->add("neili", -100);

                }
        } else
        {
                msg = CYN "\nȻ��$n" CYN "�Կ�Կ죬����һ��"
                      "��Ȼ���$N" CYN "��һ�С�\n" NOR;
                me->add("neili", -50);

        }
        message_vision(msg, me, target);
if (me && target)
	{
        me->add_temp("apply/attack", 80);
        me->add_temp("apply/damage", 500);
	for (i = 0; i < 5; i++)
	{

                if (! target->is_busy() && random(3) == 1)
                       target->start_busy(3);
 
	        COMBAT_D->do_attack(me, target, weapon, 0);
	}


        me->add_temp("apply/attack", -80);
        me->add_temp("apply/damage", -500);
}
                me->start_busy(2);
        return 1;
}