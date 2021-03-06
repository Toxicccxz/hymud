#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

string *dodge_msg = ({
        "$N身形一缩，一招「夜遇苍鹰」，身形朝暗处遁去。\n",
        "$N霎时间已经不见踪影。原来是救命绝招「蝠去无踪」。\n",
        "$N似乎早已觉出不对，在$n发招之前就已以「笨鸟先飞」高跃避之。\n",
        "$N一招「灵蝠出洞」，果然奏效，挡开了$n。\n",
        "$N身形一闪，似欲向右避去。$n正待追击，只见$N已经向左跃开。\n"
        "$N好一招「良禽择木」！把$n闹的狼狈不堪。\n",
});

int perform(object me, object target)
{
        string msg;

int count;
        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("[中岳神风]只能在战斗中使用。\n");

  if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("只能在战斗中使用。\n");



        if ( !wizardp(me) && me->query_skill_mapped("force") != "hanbing-zhenqi")
                return notify_fail("请使用寒冰真气!\n");

        if((int)me->query_skill("hanbing-zhenqi",1) < 50)
                return notify_fail("你的寒冰真气还不够。。。\n"); 

        if((int)me->query("neili") < 500)
                return notify_fail(HIY "你现在真气不足。\n" HIY);
        if((int)me->query("qi") < 500)
                return notify_fail(HIY "你现在气不足。\n" HIY);

        if( target->is_busy() )
                return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧！\n");
        msg = HIW+dodge_msg[random(sizeof(dodge_msg))]+NOR;
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
count = (int)me->query_skill("zhongyuefeng") / 50 + 2;
  message_combatd(HIR "$N一式「风行中岳」，不退反进，全身忽地向前一纵，身行若风。\n" NOR, me);
if( count > 4 ) count = 4;
   while( count-- )
         {
  object ob;
  me->clean_up_enemy();
  ob = me->select_opponent();
  if( !ob || (environment(ob) != environment(me))) {

     break;
   }
  else

  message_combatd(HIY "$N换变身形，一抬一落 瞬间出招。.\n" NOR, me, ob);
COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
if (!me->query("double_attack"))
COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
  me->receive_damage("qi", 30);
  me->add("neili", -50);
 }

        return 1;
}