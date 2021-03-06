#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
 
int perform(object me, object target)
{
        string msg;
	int extra,damage;
	object weapon,ob;
        int ap, dp,skill;
        
	if(me->is_busy())
		return notify_fail("你现在没空！！\n");
	extra = me->query_skill("six-finger",1);
	skill = me->query_skill("six-finger",1);
        if( !target ) target = offensive_target(me);
if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
                return notify_fail("「六脉惊神」只能在战斗中使用。\n");
 
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("「六脉惊神」只能空手使用。\n");		

        if (me->query_skill("kurong-changong", 1)<70)
                return notify_fail("你的本门内功火候未到，！\n");
       	if(me->query_skill_mapped("force") != "kurong-changong")
		return notify_fail("没有枯荣禅功作为准备，无法使出！\n"); 
	 if( (int)me->query("neili") < 600 )
                return notify_fail("你的真气不够！\n");

        if( (int)me->query_skill("six-finger",1) < 180 )
                return notify_fail("你的六脉神剑火候不够，无法使用「六脉惊神」！\n");

        if( (int)me->query_skill("force",1) < 150 )
                return notify_fail("你的内功修为不够，无法使用「六脉惊神」！\n");
	damage=extra*3;
	if (damage<=1500) damage=1500;
	me->add_temp("apply/attack",150);
	me->add_temp("apply/damage",1200);
	weapon = me->query_temp("weapon");

        msg = CYN "$N心思涣乱，朝$n隔空遥指了几下，不料却使出了六脉剑法的精髓"HIY"[六脉惊神]"CYN"！" NOR;
       	         message_vision(msg, me, target);                
	 msg =  RED  "-------------------------------少商剑！" NOR;
	        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = GRN   "-------------------------------商阳剑！" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg =  MAG  "-------------------------------中冲剑！" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = YEL   "-------------------------------关冲剑！" NOR;
             	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = WHT   "-------------------------------少泽剑！" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = BLU   "-------------------------------少冲剑！" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->add_temp("apply/attack",-150);
	 me->add_temp("apply/damage",-1200);
if (skill>300 && me && target)
{
 msg = HIW "\n只见$N" HIW "一声轻笑，十指纷弹，剑气如奔，连绵无尽的缕缕剑气豁然贯向$n" HIW "！\n" NOR;

        ap = me->query_skill("six-finger", 1) +
             me->query_skill("finger", 1) / 2;
        dp = target->query_skill("force");

        if (ap / 2 + random(ap) > dp || random(3)==0)
        {
                msg += HIR "结果$p" HIR "被这纵横交错的剑气逼得手忙脚乱，应接不暇！\n" NOR;
                target->start_busy(4);
        } else
        {
                msg += CYN "可是$p" CYN "并不慌张，运起内功将$P"
                       CYN "的剑气尽数化解。\n" NOR;
                me->start_busy(1);
        }
        message_combatd(msg, me, target);	
	
}

if (skill>350 && me && target)
{
   msg = HIC "\n$N" HIC "中指一按，一股凌厉无伦的无形剑气直奔$n" HIC "胸前射去。\n" NOR;  

        ap = me->query_skill("force");
        dp = target->query_skill("force");
        weapon = target->query_temp("weapon");
        me->start_busy(2);
        if (ap / 2 + random(ap) > dp || random(3)==0)
        { 
                damage = ap + random(ap / 2)+500;
                if (! objectp(weapon) || weapon->query("skill_type") == "pin")
{
	if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
target->receive_damage("qi", damage*2,me);
target->receive_wound("qi", damage,me);
                msg +=HIR "只觉得胸前一阵剧痛，鲜血"
                                                   "自创口激射而出，眼前顿时一黑！\n" NOR;
 }
                else
                if (weapon->query("ownmake") || weapon->query("damage") > 800 ||
                    weapon->query("skill_type") == "hammer")
{
	if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
target->receive_damage("qi", damage*2,me);
target->receive_wound("qi", damage,me);
                msg +=HIR "$p" HIR "横" + weapon->name() + HIR "试图招架，"
                                                   HIR "怎奈这股剑气如此犀利，透过" + weapon->name() +
                                                   HIR "直震得$p" HIR "狂吐鲜血，五脏六腑都要翻转过来！\n" NOR;
}
                else
                {
                	if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
target->receive_damage("qi", damage*2,me);
target->receive_wound("qi", damage,me);
                msg +=HIR "$p" HIR "横转" + weapon->name() + HIR "，挡在胸"
                                                   "前，只听啪啦一声，" + weapon->name() +
                                                   HIR "碎成数截，激飞上天！\n$n" HIR "连退"
                                                   "几步，“哇”的吐了一口鲜血，脸色变的惨白。\n" NOR;

if (!weapon->query("systemmake") && !weapon->query("ownmake"))
{
                        weapon->move(environment(me));
}
                }
        } else
        {
                msg += CYN "可是$p" CYN "内功颇为深厚，轻轻将这道剑气化解于无形。\n" NOR;
        }
        message_combatd(msg, me, target);	
	
}	
	
        me->add("neili", -300);
        me->start_busy(2);

        return 1;
}

