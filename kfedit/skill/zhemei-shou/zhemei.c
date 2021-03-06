// zhemei.c
// /kungfu/skill/zhemei-shou/
// Program by ying

#include <ansi.h>
#define ZHE "「" HIC "折梅式" NOR "」"
inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon;
        int damage;
        string msg;

        object weapon2;
        int skill, ap, dp;
        skill=(int)me->query_skill("zhemei-shou", 1);
        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() )
                return notify_fail("折梅展只能对对手使用。\n");
       if( environment(me)->query("no_fight") )
                       return notify_fail("这里不能攻击别人! \n");
        if( (int)me->query_skill("zhemei-shou", 1) < 80 )
                return notify_fail("你的折梅手不够娴熟，不会使用折梅展。\n");
	if( !(me->is_fighting() ))
		return notify_fail("折梅手只能对战斗中的对手使用。\n");

        if( (int)me->query_skill("beiming-shengong", 1) < 120 && (int)me->query_skill("bahuang-gong", 1)<120 )
                return notify_fail("你的本派内功不够娴熟，不会使用折梅展。\n");

        if( (int)me->query("neili", 1) < 350 || (int)me->query("max_neili",1)<200 )
                return notify_fail("你现在内力太弱，不能使用折梅展。\n");

        msg = HIC "$N手法突然加快，迅速扑向$n，抓住$n一只手臂，用力弯折。\n"NOR;

       // if( !target->is_fighting(me) ) me->kill_ob(target);

        if (random(me->query("combat_exp")) > target->query("combat_exp")/3 )
        {
                me->start_busy(3);

                damage = (int)me->query_skill("zhemei-shou", 1) + (int)me->query_skill("force",1);

                damage = damage/2 + random(damage/2 + 30) ;

                target->receive_damage("qi", damage );
		target->receive_damage("qi", damage );
                target->start_busy(6);
                me->add("neili", -200);

                msg += HIR"结果$n的手臂被$N弯折得无法动弹，只觉一阵疼痛难忍。\n"NOR;
		message_combatd(msg, me, target);
		COMBAT_D->report_status(target);
        }
        else
        {
                me->start_busy(2);
                msg += CYN"可是$p用力一震，震了开去。\n"NOR;
		message_combatd(msg, me, target);
		target->start_busy(1);
        }

if (skill>300 && me && target)
{
 msg = HIC "\n$N" HIC "合逍遥折梅手诸多变化为一式，随手轻轻挥出，虚虚"
              "实实笼罩$n" HIC "全身诸处要穴。\n" NOR;
 
        ap = me->query_skill("hand");
        dp = target->query_skill("parry");
        

        if (ap / 2 + random(ap) > dp || random(3)==0)
        {
               
                msg += HIR "$n" HIR "心头一颤，想不出破解之法，急忙后"
                      "退数步，一时间无法反击。\n" NOR;
                target->start_busy(7);
        } else
        {
                msg += CYN "可是$p" CYN "的看破了$P" CYN "的企图，丝"
                      "毫不为所动，让$P" CYN "的虚招没有起得任何作用。\n" NOR;
                me->start_busy(2);
        }
        message_combatd(msg, me, target);
	
}	

if (skill>500 && me && target)
{
msg = HIB "\n$N" HIB "挥手疾舞，施出逍遥折梅手「海渊式」，手法"
              "缥缈，虚虚实实罩向$n" HIB "要害。\n" NOR;

        
        ap = me->query_skill("hand");
        dp = target->query_skill("dodge");
        if (ap / 2 + random(ap) > dp || random(3)==0)
        {
                damage = me->query_skill("hand",1) * 2+200;

   target->add("qi",-damage*2);
		target->add("eff_qi",-damage*2);
                msg += HIR "霎时漫天掌影化为一抓，$p" HIR "闪"
                                           "避不及，被$N" HIR "五指插入胸膛，鲜血"
                                           "四处飞溅！\n" NOR;


                me->start_busy(2);
        } else 
        {
      
                msg += HIC "可是$p" HIC "身手敏捷，身形急转，巧妙的躲过了$P"
                       HIC "的攻击。\n"NOR;
                me->start_busy(2);
        }
        message_combatd(msg, me, target);	
}

if (skill>600 && me && target)
{
	msg = HIC "\n$N" HIC "双手虚虚实实的抓向$n"
              HIC "的要害，身法缥缈，手式奇特，令人难以捉摸。\n" NOR;

        ap = me->query_skill("hand") + me->query("str") * 20;
        dp = target->query_skill("dodge") + target->query("dex") * 20;
             
        if (ap / 2 + random(ap) > dp || random(3)==0)
	{
		damage = me->query_skill("hand",1)*2+300;
		me->add("neili", -100);
                target->add("qi",-damage*2);
		target->add("eff_qi",-damage*2);
                msg += HIR "$p" HIR "一个闪避不及，结果被$P"
                                           HIR "抓了个正中，浑身内息不由得一滞，气血翻涌。\n" NOR;

		me->start_busy(2);
	} else 
	{
		msg += HIC "可是$p" HIC "身手敏捷，巧妙的躲过了$P"
                       HIC "的攻击！\n"NOR;
		me->add("neili", -50);
		me->start_busy(3);
	}
	message_combatd(msg, me, target);
}
        return 1;
}
