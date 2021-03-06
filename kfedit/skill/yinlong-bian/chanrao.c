#include <ansi.h>
#define DUO "「" HIC "天诛龙蛟诀" NOR "」"
inherit F_SSERVER;

int check_fight(object me, object target, object weapon, int skill);
void remove_effect(object me, object target, object weapon, int skill);

int perform(object me, object target)
{
        string msg;

        int ap, dp;
        int damage;
        
	int skill = me->query_skill("yinlong-bian", 1);
        object weapon = me->query_temp("weapon");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("缠绕诀只能对战斗中的对手使用。\n");

        if(me->query_skill("yinlong-bian",1) < 100)
                return notify_fail("你的九阴银龙鞭还不够娴熟，不会使用缠绕诀。\n");

        if( !weapon 
        ||      weapon->query("skill_type") != "whip"
        ||      me->query_skill_mapped("whip") != "yinlong-bian" ) 
                return notify_fail("你现在无法使用缠绕诀。\n");

        if( me->query("neili") < 1500 )
                return notify_fail("你的内力不够。\n");

      msg = HIW "$N" HIW "诡异的一笑，手中" + weapon->name() +
              HIW "犹如一条银龙猛然飞向$n" HIW "，正是九阴真经中的"
             "绝招「" HIC "天诛龙蛟诀" HIW "」！\n" NOR;

        ap = me->query_skill("whip") + me->query_skill("force");
        dp = target->query_skill("force") + target->query_skill("parry");

        if (ap * 11 / 20 + random(ap) > dp || random(3)==0)
        {
                damage = ap + random(ap)+100;
                me->add("neili", -100);
                me->start_busy(2);
                target->add("qi",-damage*2);
		target->add("eff_qi",-damage);
                msg += HIR "结果$n" HIR "一声惨叫，未能看破$N"
                                           HIR "的企图，被这一鞭硬击在胸口，鲜血飞"
                                           "溅，皮肉绽开！\n" NOR;

                message_combatd(msg, me, target);
                
        } else
        {
                me->start_busy(2);
                msg += CYN "可是$p" CYN "飞身一跃而起，躲避开了"
                       CYN "$P" CYN "的攻击！\n" NOR;
                message_combatd(msg, me, target);
        }

if (!target->is_busy())
{
	msg = HIG "$N使出缠绕诀，鞭子一挥向$n的双腿卷去！\n";

        me->start_busy(2);
        if((random(me->query("combat_exp")) > target->query("combat_exp")/3) 
          )
        {
		msg += HIY "结果$p被$P一卷，两条腿被结结实实的捆起来，在地上无法爬起。\n" NOR;
                target->start_busy(2);
		target->add_temp("apply/dodge", -skill/3);
		target->add_temp("apply/parry", -skill/3);
		target->add_temp("apply/armor", -skill/3);
		me->set_temp("jiuyin/chan", 1);
	        //me->start_perform(1, "缠绕诀");
		remove_call_out("check_fight");
	        call_out("check_fight", 1, me, target, weapon, skill);
		remove_call_out("remove_effect");
	        call_out("remove_effect", skill/20, me, target, weapon, skill);
        } 
        else {
                msg += HIW "可是$p看破了$P的缠绕诀，身子一跃便躲开了。\n" NOR;
	        //me->start_perform(8, "缠绕诀");
                me->start_busy(2);
        }
}        
        message_vision(msg, me, target);
        me->add("neili", -100);
        return 1;
}

int check_fight(object me, object target, object weapon, int skill)
{
        string msg;
        object wep;
	int neili, jiali;

        if (!me) return 1;
        if (!me->query_temp("jiuyin/chan")) return 1;

        if(!living(me) || !target){
           remove_effect(me, target, weapon, skill);
           return 1;
        }
        
        if(!objectp(wep = me->query_temp("weapon")) || wep->query("skill_type") != "whip"){
           remove_effect(me, target, weapon, skill);
           return 1;
           } 
        if(environment(me) != environment(target)){
           remove_effect(me, target, weapon, skill);
           return 1;
        }
        if(!me->is_fighting(target) && !me->is_killing(target->query("id"))){
           remove_effect(me, target, weapon, skill);
           return 1;
           }           
        if(wep != weapon){
           remove_effect(me, target, weapon, skill);
           return 1;
	   }
       if (userp(me) && me->query_skill_mapped("whip") != "yinlong-bian"){
           remove_effect(me, target, weapon, skill);
           return 1;
           }   
       if( me->query("neili") <= me->query_skill("yinlong-bian", 1)/2 ){
           remove_effect(me, target, weapon, skill);
           return 1;
           }           

       target->start_busy(2);
       //me->start_perform(3, "缠绕诀");
       if (!random(3) && me->query_skill("jiuyin-zhengong", 1) > 150) {
	   message_vision(HIB"$N趁着$n手忙脚乱之际，猛然攻出一招。\n"NOR, me, target);
	   me->add_temp("apply/attack", 200);
	   me->add_temp("apply/damage", 3000);
	   neili = me->query("neili");
	   jiali = me->query("jiali");
	   me->set("jiali", me->query_skill("jiuyin-zhengong", 1));
	   weapon->unequip(); 
	   COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
	   weapon->wield();
	   me->set("jiali", jiali);
	   //me->set("neili", neili-100);
	   me->add_temp("apply/attack", -200);
	   me->add_temp("apply/damage", -3000);
       }
       call_out("check_fight", 1, me, target, weapon, skill);
       return 1;
}       

void remove_effect(object me, object target, object weapon, int skill)
{
	if (!me->query_temp("jiuyin/chan")) return;
        me->delete_temp("jiuyin/chan");
	if (!target) return;
	message_vision(HIW"$n双腿略一用劲，挣脱了"+weapon->name()+"的束缚，从地上爬了起来。\n"NOR, me, target);
	target->add_temp("apply/dodge", skill/3);
	target->add_temp("apply/parry", skill/3);
	target->add_temp("apply/armor", skill/3);
}
