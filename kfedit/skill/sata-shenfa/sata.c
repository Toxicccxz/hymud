#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

string *dodge_msg = ({
        "$N轻轻一纵，使个"YEL"「破山势」"NOR"，避开了这一招。\n",
        "$n眼一花，$N使出"HIR"「破火势」"NOR"一个筋斗从$N头顶越过。\n",
        "$N一声：好！一招"HIC"「破海势」"NOR"连翻几个筋斗，连影子都没了。\n",
        "$N左足一点，一招"HIG"「破林势」"NOR"腾空而起，$n眼一花。\n",
        "但是$N使一招"HIY"「破金势」"NOR"，身子轻轻飘了开去。$n眼一花。\n",
        "只见$N卷起一股疾风，身形亦腾风而起，正是“朝阳步”中的"HIW"「破天势」"NOR"！\n"
});

int perform(object me, object target)
{
        string msg;

int count;
        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("[飒沓朝阳步]只能在战斗中使用。\n");
  if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("只能在战斗中使用。\n");



        if ( !wizardp(me) && me->query_skill_mapped("force") != "taixuan-gong")
                return notify_fail("请使用太玄功!\n");

        if((int)me->query_skill("taixuan-gong",1) < 50)
                return notify_fail("你的太玄功还不够。。。\n"); 

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
count = (int)me->query_skill("sata-shenfa") / 60 + 2;
if( count > 5 ) count = 5;
   while( count-- )
         {
  object ob;
  me->clean_up_enemy();
  ob = me->select_opponent();
  if( !ob || (environment(ob) != environment(me))) {
  message_combatd(WHT "$N的卷起一股疾风，身形亦腾风而起。\n" NOR, me);
     break;
   }
  else

  message_combatd(HIG "$N一个筋斗翻起,从$n身旁连出数招 ...\n" NOR, me, ob);
  COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
if (!me->query("double_attack"))
 COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
  me->receive_damage("qi", 30);
  me->add("neili", -50);
 }

        return 1;
}