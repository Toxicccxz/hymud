#include <ansi.h>
#include <combat.h>

#define SHEN "「" HIY "噬天" NOR "」"

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
                return notify_fail(SHEN "只能在战斗中对对手使用。\n");

        if (! objectp(weapon = me->query_temp("weapon"))
           || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对，难以施展" SHEN "。\n");

        if ((int)me->query_skill("yubi-jian", 1) < 200)
                return notify_fail("你剑法不够娴熟，难以施展" SHEN "。\n");

        if (me->query_skill_mapped("sword") != "yubi-jian")
                return notify_fail("你没有激发剑法，难以施展" SHEN "。\n");

        if ((int)me->query_skill("force", 1) < 240)
                return notify_fail("你的内功火候不够，难以施展" SHEN "。\n");

        if ((int)me->query_skill("dodge", 1) < 240)
                return notify_fail("你的轻功火候不够，难以施展" SHEN "。\n");  

        if ((int)me->query("max_neili") < 2500)
                return notify_fail("你的内力修为不足，难以施展" SHEN "。\n");

        if ((int)me->query("neili") < 400)
                return notify_fail("你现在的真气不够，难以施展" SHEN "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        wn = weapon->name();

        msg = HIY "一道金光划过，$N" HIY "消失得无影无踪，猛然间只见一条\n"
              "金蛇从天而下，" + weapon->name() + HIY "已将$n" HIY "笼罩。\n" NOR;


        
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
                // 十分之一的几率可被招架
                if (random(10) <= 1 && ap / 2 < dp)
                {
                        damage = damage / 3;

                        target->add("qi",-damage/2+100);
                        target->add("qi",-damage/3+100);
                        msg +=                   HIG "$n" HIG "见$N" HIG "一道金光闪过\n"
                                                  "，急忙收敛心神奋力招架。\n哪知$P这"
                                                  "招力道非凡，$p一声闷哼，连退几步，喷\n"
                                                  "出一口鲜血。\n" NOR;
                        me->add("neili", -100);
                        me->start_busy(2 + random(2));
                } else 
                {
                        target->add("qi",-damage+100);
                        target->add("qi",-damage/2+100);

                        msg +=                    HIR "$n" HIR "见$N" HIR "金光划过，心"
                                                  "底不由大惊，\n登时听得“噗嗤”一声，剑"
                                                  "气透体而过。\n" NOR;
                        me->add("neili", -100);

                }
        } else
        {
                msg = CYN "\n然而$n" CYN "以快对快，飞身一跳"
                      "已然躲过$N" CYN "这一招。\n" NOR;
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
