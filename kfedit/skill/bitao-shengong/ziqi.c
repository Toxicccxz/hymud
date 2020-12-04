// drainerbolt.c
//2001,lestat
#include <ansi.h>

inherit F_SSERVER;

int exert(object me)
{
	string msg;
	int damage, ap, dp;
	int extradam;
object target;
        if( !target ) target = offensive_target(me);	




	if( !target
	||	!target->is_character()
	||	target->is_corpse()
	||	target==me)
		return notify_fail("你要对谁施展氤氲紫气？\n");

 if((int)me->query("neili") < 200)
                return notify_fail("你的内力不够！\n");

        if((int)me->query("jing") < 200 )
                return notify_fail("你无法集中精力！\n");

      if( !target ) target = offensive_target(me);
   	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("这门绝学只能对战斗中的对手使用。\n");
		
		        if((int)me->query_skill("buddhism",1) < 100)
                return notify_fail("你的禅宗心法还不够。。。\n");

        if((int)me->query_skill("bitao-shengong",1) < 100)
                return notify_fail("你的碧涛心法还不够。。。\n"); 

	me->add("neili", -25);
	me->receive_damage("jing", 20);

	if( random(me->query("max_neili")) < 20 ) {
		write("你失败了。\n");
		return 1;
	}

	msg = HIM "$N口中喃喃地念著咒文，左手一挥，手中聚起一团紫气射向$n！\n\n" NOR;

message_vision(HIY"\n累劫愿行不见声，六度万行唯依真。"NOR,me,target);
message_vision(HIY"\n华藏世界十愿王，法华会上显圣尊。"NOR,me,target);
message_vision(HIY"\n六牙白象常走动，峨嵋引领后来人。"NOR,me,target);
message_vision(HIY"\n千僧万德入乐土，娑婆诃时感圣恩。\n"NOR,me,target);

	ap = me->query_skill("buddhism");
	extradam = ap/2;
	ap = ( ap * ap /100 * ap / 4 ) * (int)me->query("jing") ;
	dp = target->query("combat_exp");
	if( random(ap + dp) > dp ) {
		damage = (int)me->query("max_neili") / 10 + random((int)me->query("eff_jing") / 20) + random(extradam);
		damage -= (int)target->query("max_neili") / 30 + random((int)me->query("eff_jing") / 15);
		if( damage > 0 ) {
			msg +=  MAG "结果「嗤」地一声，紫气从$p身上透体而过，拖出一条长长的七彩光气，光气绕了\n"
					"回转过来又从$N顶门注入$P的体内！\n" NOR;
			me->receive_heal("jing", damage/3);
			target->receive_wound("jing", damage/3);

			me->receive_heal("qi", damage/2);
			target->receive_wound("qi", damage/2);

			me->improve_skill("bitao-shengong", 1, 1);
		} else
			msg += HIB"结果「嗤」地一声，紫气从$p身上透体而过，无声无息地钻入地下！\n"NOR;
	} else
		msg += "但是被$n躲开了。\n";

	message_vision(msg, me, target);
	if( damage > 0 ) COMBAT_D->report_status(target);


	me->start_busy(3);
	return 1;
}

