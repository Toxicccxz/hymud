#include <ansi.h>
#include <combat.h>

#define HAI "「" HIG "苦海无边" NOR "」"

inherit F_SSERVER;

string final(object me, object target, int damage);

string *finger_name = ({ "左手中指", "左手无名指", "左手食指",
                         "右手中指", "右手无名指", "右手食指", }); 

int perform(object me, object target)
{
        int damage;
        string msg, name;
        object weapon;
        int lvl, ap, dp;

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(HAI "只能对战斗中的对手使用。\n");

        if (weapon = me->query_temp("weapon"))
        {
                if (weapon->query("skill_type") != "staff" && weapon->query("skill_type") != "dagger")
                        return notify_fail("你手里拿的武器不对，怎么施展" HAI "？\n");
        } else
        {

        }

        if ((int)me->query_skill("bluesea-force", 1) < 260)
                return notify_fail("你的南海玄功不够娴熟，难以施展" HAI "。\n");

        if ((int)me->query("max_neili") < 3700)
                return notify_fail("你的内力修为不足，难以施展" HAI "。\n");

        if (me->query("neili") < 300)
                return notify_fail("你现在的真气不足，难以施展" HAI "。\n");
                
        if (me->query_skill_mapped("force") != "bluesea-force")
                return notify_fail("你使用的内功不对。\n");


        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");


        if (me->query_temp("weapon"))
                name = "手中" + weapon->name();
        else
                name = finger_name[random(sizeof(finger_name))];

        msg = HIB "$N" HIB "气贯双臂，向地一击，一股气浪卷着飞石如狂涛般袭向$n" HIB "，对方惊魂未定之际，忽闻三声轻响。\n"
              HIB "自$N" HIB "的" + name + HIB "中射出三道玄劲，分袭$n" HIB "三处死穴“云门穴、章门穴、哑门穴”。\n\n" NOR;

        ap = me->query_skill("force");
        dp = target->query_skill("dodge");

        if (ap / 2 + random(ap) > dp)
        {
                damage = me->query_skill("force")+500;
                damage = 150+me->query_skill("unarmed");
   target->add("qi",-damage);
		target->add("eff_qi",-damage);
		target->start_busy(3);
                msg += HIY "$n" HIY "只觉眼前飞沙走石，目不能视，忽觉身上要穴"
               "刺痛，三道血柱自身上射出。\n$p陡然间一提真气，"
               "竟觉得丹田之内空虚若谷，全然无法运气。\n" NOR;
                me->start_busy(2);
                me->add("neili", -500);
        } else
        {
                msg += CYN "$n" CYN "慌乱中一个鸽子翻身，跃出数丈，"
                       "侥幸躲开了这一招。\n" NOR;
                me->start_busy(3);
                me->add("neili", -350);
        }
        message_combatd(msg, me, target);
        return 1;
}

