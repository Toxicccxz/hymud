#include <ansi.h>
#include <combat.h>
#define TONG "「" HIR "破元通虚" NOR "」"
#define JING "「" HIM "惊虹一笔" NOR "」"

inherit F_SSERVER;

string *finger_name = ({ "左手中指", "左手无名指", "左手食指",
                         "右手中指", "右手无名指", "右手食指", }); 
 
int perform(object me)
{
        string msg,wp;
        object weapon, target;
        int skill, ap, dp, damage,i;



        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! me->is_fighting(target))
                return notify_fail(JING "只能对战斗中的对手使用。\n");

        weapon = me->query_temp("weapon");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "dagger")
                return notify_fail("你所使用的武器不对，难以施展" JING "。\n");

        skill = me->query_skill("ziwu-daxuefa", 1);

        if (me->query_skill("force",1) < 150)
                return notify_fail("你的内功修为不够，难以施展" JING "。\n");
        if (me->query_skill_mapped("force") != "bluesea-force")
                return notify_fail("你使用的内功必须是南海玄功。\n");
        if (me->query("neili") < 500)
                return notify_fail("你现在的真气不足，难以施展" JING "。\n");

        if (skill < 100)
                return notify_fail("你这门武功修为有限，难以施展" JING "。\n");

        if (me->query_skill_mapped("dagger") != "ziwu-daxuefa")
                return notify_fail("你没有激发这门武功，难以施展" JING "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = HIM "$N" HIM "手中" + weapon->name() + HIM "大开大合，宛若天马行"
              "空，难测阴阳，化作一道道疾光射向$n" HIM "！\n" NOR;
 
        ap = me->query_skill("dagger");
        dp = target->query_skill("parry");
        if (ap / 2 + random(ap) > dp)
        {
                me->add("neili", -200);
                damage = 300 + ap / 2 + random(ap / 2);

   target->add("qi",-damage);
		target->add("eff_qi",-damage);
		//target->start_busy(3);
                msg += HIR "顿时只听得“噗嗤”一声，$n" HIR
                                           "胸口被$N" HIR "一笔刺中，溅出一柱鲜血。\n" NOR;
  

                me->start_busy(1);
                if (ap / 3 + random(ap) > dp && ! target->is_busy())
                        target->start_busy(7);
        } else
        {
                msg += CYN "可是$p" CYN "的看破了$P" CYN
                       "的招式，巧妙的一一拆解，没露半点"
                       "破绽！\n" NOR;
                me->add("neili", -50);
                me->start_busy(3);
        }
        message_combatd(msg, me, target);

if (skill >300 || !userp(me))
{

        msg = HIW "$N" HIW "纵步上前， 诗意纵横 手中" + weapon->name() + HIW "大开大"
              "合，招数连绵不绝，荡气回肠，瞬间向$n" HIW "攻出数招！\n" NOR;
        message_combatd(msg, me, target);
        me->add("neili", -50);
                                me->add_temp("apply/attack", 100);
                me->add_temp("apply/damage", 1200);
        for (i = 0; i < 5; i++)
        {
if (!target->is_busy()) target->start_busy(2);
	msg = HIR "惊虹第"+ chinese_number(i+1) +"笔！" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        }	
                                me->add_temp("apply/attack", -100);
                me->add_temp("apply/damage", -1200);
}

if (skill >600 || !userp(me))
{

 if (weapon)
                wp = "手中" + weapon->name();
        else
                wp = finger_name[random(sizeof(finger_name))];

        msg = HIG "$N" HIG "翻转" + wp + HIG "，接连变化数种打穴手法，一式「"
              HIR "破元通虚" HIG "」直捣$n" HIG "胸前要穴。\n" NOR;

        ap = me->query_skill("ziwu-daxuefa", 1);
        dp = target->query_skill("force", 1);

        if (ap / 2 + random(ap) > dp)
        {
                  damage = ap*3 + random(ap)+1000;
     target->add("qi",-damage);
		target->add("eff_qi",-damage);
		//target->start_busy(3);
                msg += HIR "$n" HIR "只觉胸口一麻，已被$N" HIR "点中"
                "要穴，登时全身真气阻滞，苦不堪言！\n" NOR;

        
                me->add("neili", -50);
                me->start_busy(3);
        } else
        {
                msg += CYN "可是$n" CYN "早已看破$N"
                       CYN "招中虚实，单手一挥，登将这招化于无形。\n" NOR;
                me->add("neili", -50);
                me->start_busy(4);
        }
        message_combatd(msg, me, target);	
	
}

me->start_busy(2);
        return 1;
}
