
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

string *dodge_msg = ({
	"$N一招"HIC"「龙翔九天」"NOR"，右脚轻轻点地，身体「嗖」的向上笔直地纵起
丈余。\n",
	"$N一个"HIY"「龙游四海」"NOR"，双臂一张，行云流水般向后纵出。\n",
	"$N使出"MAG"「翩若惊鸿」"NOR"，身形不住闪动。\n",
	"$N使出"BLU"「神龙无影」"NOR"，$n眼前一花，已不见$n踪影。\n",
});

int perform(object me, object target)
{
        string msg;

int count;
        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("[游龙]只能在战斗中使用。\n");

  if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("只能在战斗中使用。\n");



        if ( !wizardp(me) && me->query_skill_mapped("force") != "honghua-shengong")
                return notify_fail("请使用红花神功!\n");

	if( (int)me->query_skill("honghua-shengong", 1) < 10 )
	return notify_fail("你的红花神功不够精熟，无法领会游龙身法。\n");

        if((int)me->query("neili") < 500)
                return notify_fail(HIY "你现在真气不足。\n" HIY);
        if((int)me->query("qi") < 500)
                return notify_fail(HIY "你现在气不足。\n" HIY);

        if( target->is_busy() )
                return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧！\n");

	msg = HIG+dodge_msg[random(sizeof(dodge_msg))]+NOR;
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 ) {
                msg += HIR "结果$p被$P绕得不知所措！\n" NOR;
                target->start_busy(5);
                me->add("neili", -100);
                       } else {
                msg +=  GRN"结果$P自己绕了个头晕眼花。\n"NOR;
                me->add("neili", -100);
                me->start_busy(2);
        }
        message_combatd(msg, me, target);

        return 1;
}
