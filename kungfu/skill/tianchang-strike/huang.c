// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// huang.c 地老天荒

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;


int perform(object me, object target)
{
        string msg;
        int skill, ap, dp, damage,i;
        object weapon;

                
        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! me->is_fighting(target))
                return notify_fail("「地老天荒」只能对战斗中的对手使用。\n");

        if (me->query_temp("weapon"))
                return notify_fail("必须空手才能施展「地老天荒」。\n");

        if (me->query_skill_mapped("strike") != "tianchang-strike")
                return notify_fail("你没有激发天偿掌法，无法施展「地老天荒」。\n");

        skill = me->query_skill("tianchang-strike", 1);

        if (skill < 100)
                return notify_fail("你的天偿掌法修为有限，不能使用「地老天荒」！\n");

        if (me->query("neili") < 150)
                return notify_fail("你的真气不够，无法运用「地老天荒」！\n");

        if (! living(target))
              return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = HIR "$N" HIR "“嚯”的一声震喝，提起掌来，只见掌心一片血红，倏的凌空拍出，"
              HIR "一股热风登时袭向$n" HIR "的胸前大穴。\n" NOR;

        ap = me->query_skill("strike",1);
        dp = target->query_skill("parry",1);
             
        if (ap / 2 + random(ap) > dp)
        {
                me->add("neili", -120);
                
                damage = me->query_skill("strike",1)*2;
                		target->add("qi",-damage);
		target->add("eff_qi",-damage/2);
                me->add("neili", -150);
		msg +=                     HIR "$n" HIR "一时间只觉得气血上涌，浑"
                                           "身如遭火焚，气息大乱，不由得吐了一口"
                                           "鲜血。\n" NOR;

        } else
        {
                me->add("neili",-50);
                msg += HIC "然而$n" HIC "内功深湛，丝毫不为$N"
                       HIC "的掌风所动，若无其事" NOR;
                
        }
        message_combatd(msg, me, target);


        me->add_temp("apply/attack", 50);
        me->add_temp("apply/damage", 500);

        for (i = 0; i < 4; i++)
        {
                if (! me->is_fighting(target))
                        break;
        	COMBAT_D->do_attack(me, target, weapon, 0);
        }


        me->add_temp("apply/attack", -50);
        me->add_temp("apply/damage", -500);
me->start_busy(3);
        return 1;
}
