#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        int ap,dp,damage,chance;
        string msg;
        object weapon;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展「阎罗歌舞」？\n");
        if(!me->is_fighting())
                return notify_fail("「阎罗歌舞」只能在战斗中使用！\n");
   	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("这门绝学只能对战斗中的对手使用。\n");
   
    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "whip")
        return notify_fail(RED"开什么玩笑，武器不对？\n"NOR);

        if ( !wizardp(me) && me->query_skill_mapped("force") != "zhanzhuang-gong")
                return notify_fail("请使用四平大马站桩功!\n");
                
        if((int)me->query("max_neili") < 1000 )
                return notify_fail("你的内力不够！\n");
        if((int)me->query("neili") < 1000 )
                return notify_fail("你的内力不足！\n");
        if((int)me->query("jing") < 300 )
                return notify_fail("你的精神不足，没法子施用外功！\n");

    if ((int)me->query_skill("hellfire-whip", 1) < 60)
        return notify_fail("你的六道烈火鞭等级不够，使用这一招会有困难！\n");
        if((int)me->query_skill("yijinjing", 1) < 150)
                return notify_fail("你的易筋经级别还不够，使用这一招会有困难！\n");
    if ((int)me->query_skill("buddhism", 1) < 60)
        return notify_fail("你的禅宗心法还不够，使用这一招会有困难！\n");
        
        if((int)me->query_skill("hellfire-whip", 1) < 60)
                return notify_fail("你的六道烈火鞭修为还不够，使用这一招会有困难！\n");
        msg = HIR"\n$N手腕晃动如疾风，以疾风的速度瞬间绕着$n转了九千九百九十九圈,突然打出一鞭！\n"NOR;
        ap = me->query("combat_exp"); 

        dp = target->query("combat_exp"); 

        if( random(ap)> (dp/4)) 
        {
                damage = me->query_skill("whip",1) * 2 + me->query("force_factor");
                if (damage > 20000) damage = 19900+random(100);
                target->receive_damage("qi",damage,me);
                target->receive_wound("qi",damage,me);
         target->start_busy(5);
                msg += CYN"结果$n被$N的「阎罗歌舞」迷惑，未能躲闪！\n"NOR;
        }
        else 
                msg += "但是被$n躲开了。\n"NOR;
        message_vision(msg, me, target);
        if( damage > 0 ) COMBAT_D->report_status(target);
        me->add("neili",-200);
        me->start_busy(2);
        return 1;
}

