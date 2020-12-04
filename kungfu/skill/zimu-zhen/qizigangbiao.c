#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra,i,lmt,l;
	object weapon;
	int skill, ap, dp, neili_wound, qi_wound;

	
       if( !target ) target = offensive_target(me);
       if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("[七子钢镖]只能对战斗中的对手使用。\n");
	if( (int)me->query_skill("biyun-xinfa", 1) < 60 )
                return notify_fail("你的碧云心法不够高。\n");
	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "throwing")
		return notify_fail("你使用的武器不对。\n");
		
        if( (int)me->query("neili", 1) < 400 )
                return notify_fail("你现在内力太弱。\n");

	weapon = me->query_temp("weapon");
	extra = me->query_skill("zimu-zhen",1);
	skill = me->query_skill("zimu-zhen",1);
	if ( extra < 200) return notify_fail("你的唐门暗器还不够纯熟！\n");
	msg = GRN  "$N使出唐门暗器中的七子钢镖，击向$n" NOR;
	message_vision(msg,me,target);
	me->add_temp("apply/attack",100);
	me->add_temp("apply/damage",1900);
        l=extra/30;
	lmt = random(l)+5;
	for(i=1;i<=lmt;i++)
	{
	msg =  BLU "第"+chinese_number(i)+"镖-->" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	}
	        me->add_temp("apply/attack",-100);
        me->add_temp("apply/damage",-1900);
	
if (extra > 200)
{
        target->apply_condition("chanchu_poison", 60);
        target->apply_condition("xiezi_poison", 60);
        target->apply_condition("wugong_poison", 60);
        target->apply_condition("snake_poison", 60);
        target->apply_condition("zhizhu_poison", 60);

}

if (extra > 300)
{
        target->apply_condition("tmzhuihun_poison", 60);
        target->apply_condition("tmpili_poison", 60);
        target->apply_condition("zm_poison", 60);
}
	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 ) {
        target->apply_condition("tmqidu_poison", 60);
	} 


if (skill>350 && me && target)
{
	msg = HIG "$N双目突然泛过怪异绿光,中指在不易察觉间微微一动,一点银星悄无声息打向$n眉心。\n"NOR;

	me->start_busy(1);
	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 || random(3)==0) {
		msg += HIR " 结果$p被$P的「定魂」打个正着，瞬间神志开始迷糊起来！\n" NOR;
                target->start_busy(8);
	
	target->apply_condition("anqi_poison", 30);
	target->apply_condition("tmzhuihun_poison", 30);
	target->apply_condition("tmpili_poison", 30);
        target->apply_condition("tmqidu_poison", 30);
	} else {
		msg += "可是$p在千钧一发之间闪身躲过了这一击。\n" NOR;
	}
	message_vision(msg, me, target);	
}	

if (skill>600 && me && target)
{
	me->add_temp("apply/attack", 100);	
	me->add_temp("apply/damage", 1900);
msg = RED "$N左手一扬，唐门独门暗器----第一朵令人闻风丧胆的唐花朝$n发了出去。\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	
msg = RED "$N左手一扬，唐门独门暗器----第二朵令人闻风丧胆的唐花朝$n发了出去。\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	
msg = RED "$N左手一扬，唐门独门暗器----第三朵令人闻风丧胆的唐花朝$n发了出去。\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	me->add_temp("apply/attack", -100);
	me->add_temp("apply/damage", -1900);
        me->add("neili",-10);

	msg = HIY "$N并指入刀，指缝间夹着三枚暗器,潜运内力，一式「破气针」，直奔$n的上、中、下丹田打去。\n";
	message_vision(msg, me, target);
 
	ap = me->query_skill("throwing") + skill;
	dp = target->query_skill("force") / 2;
	if( dp < 1 )
		dp = 1;
	if( random(ap) > dp || random(3)==0 )
	{
		msg = "$N「破气针」正中目标, $n顿时觉得丹田上一阵刺痛，\n";
		msg += "全身真气狂泄而出！\n" NOR;
	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 || random(3)==0) {
        target->apply_condition("tmqidu_poison", 30);
	} 
		neili_wound = 600 + (skill*3);
		if(neili_wound > target->query("neili"))
			neili_wound = target->query("neili");

		qi_wound = 600 + (skill*5);
		if(qi_wound > target->query("qi"))
			qi_wound = target->query("qi");
if (qi_wound <10) qi_wound=10;
if (qi_wound >30000) qi_wound=30000;
if (neili_wound <10) neili_wound=10;
if (neili_wound >30000) neili_wound=30000;
		target->add("neili", -neili_wound);
;
target->receive_wound("qi",qi_wound,me);
		target->start_busy(2);
        target->apply_condition("tmpili_poison", 30);

//		me->start_busy(random(2));
	}
	else
	{
		msg = "可是$n瞬间反应过来，腾挪跳跃，躲过了这次重创。\n"NOR;
		me->start_busy(2);
	}
	message_vision(msg, me, target);	
}
        me->add("neili",-200);
	me->start_busy(3);
	return 1;
}

