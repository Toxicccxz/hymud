#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        string dodskill,msg;
        int extra;
        int tmp;
        int damage, ap, dp;
        object weapon;
        extra = me->query_skill("bainiao-jian",1);

 if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
        return notify_fail(RED"开什么玩笑，武器不对？\n"NOR);

        if ( !wizardp(me) && me->query_skill_mapped("force") != "honghua-shengong")
                return notify_fail("请使用红花神功!\n");

        if((int)me->query_skill("honghua-shengong",1) < 200)
                return notify_fail("你的红花神功还不够。。。\n"); 

        if ( extra < 200) return notify_fail("你的百鸟剑法还不够纯熟！\n");     
       
        if( (int)me->query("neili") < 800 )      
                return notify_fail("你的内力不够。\n");

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［九剑妖魂］只能对战斗中的对手使用。\n");
        me->add_temp("apply/attack",200	);
        me->add_temp("apply/damage",1800);
        me->add("neili", -50);
        weapon = me->query_temp("weapon");
        if(!target->is_busy()) target->start_busy(2);
        message_vision(RED  "\n\n$N腾空跃起，变换身形，瞬移北斗七星位，手中的"+ weapon->name() +RED"划出森然剑气，剑剑逼向$n ！\n\n" NOR, me, target);
        message_vision(HIC  "「妖气冲天」，$N手中"+ weapon->name() +HIC"带着一阵寒意直刺$n！" NOR, me, target);
         COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIR  "\n「魂飞魄散」，$N手中"+ weapon->name() +HIR"带着冷冷的剑气斜刺$n！" NOR, me, target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIY  "\n「妖兽噬天」，$N手中"+ weapon->name() +HIY"落叶般横扫$n！" NOR, me, target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIW  "\n「十万神魔」，$N手中"+ weapon->name() +HIW"闪电般猛劈$n！" NOR, me, target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(MAG  "\n「群魔乱舞」，$N手中"+ weapon->name() +MAG"携阵阵妖气直扑$n！" NOR, me, target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIY  "\n「妖极天世」，$N手中"+ weapon->name() +HIY"迅雷般刺向$n！" NOR, me, target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIG  "\n「鬼魅人间」，$N手中"+ weapon->name() +HIG"猛然化为一团紫气冲向$n！" NOR, me, target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIC  "\n「魔影幢幢」，$N手中"+ weapon->name() +HIC"随道道寒光飞向$n！" NOR, me, target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIM  "\n「魔光魅影」，$N手中"+ weapon->name() +HIM"化为万千幻影刺向$n！" NOR, me, target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(RED  "\n$N收剑后退，手中"+ weapon->name() +RED"还缠绕着阵阵妖魂,好一招"+HIW"“九剑妖魂”！" NOR, me, target);
       me->add("neili",-50);
        
        me->add_temp("apply/attack",-200);
        me->add_temp("apply/damage",-1800);

        if ((int)me->query_skill("bainiao-jian",1) > 550)
        {
        me->add("neili", -50);
        msg = HIW
 "\n$N身形渐渐变慢，突然一声怒喝，手中的剑幻化成一片光网
瞬间连出十剑，一个巨大的
"RED"
           ]@         
           ]b      ____        ]@
           ][      @~~~~J[~    ]@
        ___ P____  ]    i[     ]@
       ~~~~]@~~~   J_____U  d  ]@
           ][   /'__ J___   ]i ]@
           ]@'J~ ~~~~]~~d[' jl ]@
           d[       d[  ]@  J[ ]@
         ]%][       d'  ][  i' ]@
      _d~  ]@      a'   d[     ]@
           ][    _r~    ad     ]a
           J[   ~     _a'      J[
          _r                  J~ 
"NOR"\n"HIW"字浮现在$n眼前，\n"NOR;

        ap = me->query_skill("bainiao-jian", 1);
        ap = ( ap * ap * ap / (4 * 400) );
        ap = ap*250 + (int)me->query("combat_exp");
        dp = target->query_skill("parry");
   dp = ( dp * dp * dp / (7 * 400) );
   dp = dp*250 + target->query("combat_exp");
    if( random((ap + dp)/1000) <  dp/1200 ) {
  msg += HIY "$n慌忙中左躲右闪，狼狈的躲开了致命的八剑！\n\n"NOR;
           message_vision(msg, me, target);
   } else {
                damage = 50+(int)me->query_skill("bainiao-jian",1)*2 +
        (int)me->query("jing") / 200 + random((int)me->query("jing") / 150 ) +
        (int)me->query("qi") / 250 + random((int)me->query("qi") / 150 );
  msg += HIR "\n$n顿时被这快如闪电的八剑击中！\n\n" NOR;
     damage +=random(10);
                        target->receive_damage("jing", damage/3);
                        target->receive_damage("qi", damage);
       target->receive_wound("qi", damage/2);
                        
           message_vision(msg, me, target);
      }
    }	
       me->start_busy(3);
        return 1;
}

