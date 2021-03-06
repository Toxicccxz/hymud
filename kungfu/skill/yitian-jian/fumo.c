#include <ansi.h>
#include <combat.h>

#define FUMO "「" HIR "伏魔剑诀" NOR "」"

inherit F_SSERVER;


string final(object me, object target, int damage);

int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp;
        int damage;
        int skill;
        int lvl;
        lvl=me->query_skill("yitian-jian");
        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(FUMO "只能对战斗中的对手使用。\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对，无法施展" FUMO "。\n");

        if ((int)me->query_skill("yitian-jian", 1) < 120)
                return notify_fail("你的倚天剑法不够娴熟，无法施展" FUMO "。\n");

        if (me->query("neili") < 200)
                return notify_fail("你现在真气不够，无法施展" FUMO "。\n");

        if (me->query_skill_mapped("sword") != "yitian-jian") 
                return notify_fail("你没有激发倚天剑法，无法施展" FUMO "。\n");

        if (! living(target))
               return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = HIW "$N" HIW "一声冷哼，手中" + weapon->name() +
              HIW "一振，剑身微颤，声若龙吟，剑光携着数个剑花"
              "同时洒向$n" HIW "。\n" NOR;

        me->add("neili", -150);
        ap = me->query_skill("sword");
        dp = target->query_skill("parry");
        if ((int)target->query("shen") < 0) ap += ap / 5;

        me->start_busy(3);
        if (ap / 2 + random(ap) > dp)
        {
                damage = me->query_skill("sword");
   target->add("qi",-damage);
		target->add("eff_qi",-damage);
                msg += HIR "只听$n" HIR "一声惨叫，被这一剑穿胸而入，顿"
                "时鲜血四处飞溅。\n" NOR;
        } else
        {
                msg += HIC "可$n" HIC "却是镇定逾恒，一丝不乱，"
                       "全神将此招化解开来。\n" NOR;
        }
        message_combatd(msg, me, target);
if (lvl>300)
{
	
 msg = CYN "\n$N默运神功，使出「"RED"孤注一掷"CYN"」，双掌平推攻向$n。\n"NOR;

        ap = me->query_skill("strike");
        dp = target->query_skill("force");
             
        if (ap / 2 + random(ap) > dp || random(3)==0)
        {
                me->start_busy(random(2));
                target->start_busy(random(3));

                target->receive_damage("qi", lvl*4);
                target->receive_wound("qi", lvl*3);

                if( damage < 40 )
                        msg += HIY"结果$n被$N双掌打在胸口，闷哼一声。\n"NOR;
                else if( damage < 80 )
                        msg += HIY"结果$n被$N以双掌打在胸口，「嘿」地一声退了两步。\n"NOR;
                else if( damage < 160 )
                        msg += RED"结果$n被$N以双掌打在胸口，有如受到一记重锤，连退了五六步！\n"NOR;
                else
                        msg += HIR"结果$n被$N的双掌打在胸口，眼前一黑，象一捆稻草一样飞出去好几丈远！\n"NOR;
                
        }
        else 
        {
                me->start_busy(1 + random(2));
                msg += CYN"可是$p看破了$P的企图，身形一转，反掌回击。\n"NOR;
        }
        message_combatd(msg, me, target);	
 
}

if (lvl>600)
{
 msg = HIR "\n$N" HIR "聚气于掌，仰天一声狂啸，刹那间双掌交错，一招"
                  "「夺命催心」带着阴毒内劲直贯$n" HIR "！\n"NOR;

        ap = me->query_skill("strike") + lvl;
        dp = target->query_skill("parry");

        if (dp < 1) dp = 1;

        if ( ap / 2 + random(ap) > dp + random(dp) || random(3)==0 )
        {
        damage = lvl * 4 + random(lvl);
target->apply_condition("cuixin_zhang",35 );
   target->add("qi",-damage);
		target->add("eff_qi",-damage);
                msg += HIR "只听$n" HIR "惨叫一声，只感两耳轰"
               "鸣，目不视物，喷出一大口鲜血，软软瘫倒。\n" NOR;

        me->start_busy(2);
        }
    else
        {
        msg += HIY "$p见$P来势汹涌，急忙纵身一跃而起，躲开了这致命的一击！\n" NOR;
        me->add("neili", -300);
        me->start_busy(3);
        }
        message_combatd(msg, me, target);
}
        return 1;
}

string final(object me, object target, int damage)
{
        return  HIR "只听$n" HIR "一声惨叫，被这一剑穿胸而入，顿"
                "时鲜血四处飞溅。\n" NOR;
}

