// Copyright (C) 2003-2004, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <command.h>
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;


int perform(object me, object target)
{
        string msg;
        int ski_value, max_lv;
        int ap, dp, damage;
        object ob,weapon;
        ski_value = random(me->query_skill("mingyu-gong", 1));
        max_lv = me->query_skill("mingyu-gong", 1);

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("『魔气血杀』只能对战斗中的对手使用。\n");
  
        if( me->query_skill("mingyu-gong", 1) < 500 )
                return notify_fail("你的明玉功功力不足。 \n");
            if((int)me->query_skill("bingxue-xinfa",1) < 150)
                return notify_fail("你的冰雪心法修为不够。\n");        
        if( me->query_skill("force", 1) < 500 )
                return notify_fail("你的内功不够好。 \n");
        
        if(me->query("neili") < 1000)
                return notify_fail("你的内力不够。\n");
        
        if (me->query_skill_mapped("force") != "mingyu-gong") 
                return notify_fail("你现在没有激发明玉功为内功，难以施展『魔气血杀』。\n"); 
   
        msg = HIY "$N自残己身，以血气转换成杀气。\n
            ……$N身上发出一股强大的杀气……\n
    ■$N身上杀气逐渐地聚集在双手,在双手上形成两团魔气■\n
            $N倏地大喝一声－－魔 气 血 杀－－\n\n" NOR;

        ap = me->query_skill("force"); 
        dp = target->query_skill("force"); 
        
 if(random(3)==0 || (random(me->query("combat_exp",1)) >= target->query("combat_exp")/3))
        {
                msg += HIR BLINK "$N突然喉头一动～～　只见$N口中喷出一道血柱往$n射去～～\n
此乃魔气杀之
            最终杀招 『魔 血 气 杀』\n\n
$n遭到前所未有的打击,但$N也受伤不轻。\n" NOR;

                damage =  100+me->query_skill("force");
                damage *= 3;
                damage += random(damage);
                
                //fif (! target->is_busy())
                        //target->start_busy( (int)me->query_skill("mingyu-gong") / 100 + 3 );
                target->receive_wound("jing", damage,me);
                target->receive_wound("qi", damage,me);
                //me->receive_wound("qi", me->query("qi")* 5 /100);
                me->add("neili",-500);  
        }
        else if( random(4) > 2 )
        {
                msg += HIR BLINK"$N真气所转换的杀气不够大,对敌人毫无影响。\n" NOR;
                //me->receive_wound("qi", me->query("qi")*1/100);
                me->add("neili",-500);  
        }
        else
        {
                msg += HIR BLINK"$n受到强大的杀气伤害，动弹不得。\n" NOR;
                //me->receive_wound("qi", me->query("qi")* 1 /100);
                target->receive_damage("qi", (int)me->query_skill("mingyu-gong", 1)*2);
                
                //if (! target->is_busy())
                //target->start_busy(3);
                me->add("neili",-500);
        }
        
         message_vision(msg, me, target);
        
        me->add_temp("apply/attack", 100);
	me->add_temp("apply/damage",2000);
        msg = HIR  "\n$N使出［九重寒天掌］，全身飞速旋转，双掌一前一后，闪电般的击向$n！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	if (!target->is_busy()) target->start_busy(2);
        msg = HIC  "$N猛一个翻身，迅捷无比地向$n踢出飞天一腿！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        msg = HIC  "$N猛一个侧身，迅捷无比地向$n踢出灭天一腿！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        msg = HIC  "$N猛一个转身，迅捷无比地向$n踢出穿天一腿！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        msg = HIC  "$N猛一个跃身，迅捷无比地向$n踢出毁天一腿！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);	

if (random(2)==0)
{
        message_vision( MAG "$N被掌法产生的幻象所迷惑,显得两眼迷茫...， 伴随着重重的一声闷哼，一股血气从顶门喷涌而出！\n" NOR,target);
        target->receive_wound("qi",max_lv*3,me);
}

	me->add_temp("apply/attack", -100);
	me->add_temp("apply/damage",-2000);
        me->start_busy(2);
        message_vision(msg, me, target);
        return 1;
}