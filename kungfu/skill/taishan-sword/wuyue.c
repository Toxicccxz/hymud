// feilong.c 华山剑法「夺命连环三仙剑」

#include <ansi.h>
#include <combat.h>

#define XIAN "「" HIM "五岳合一" NOR "」"

inherit F_SSERVER;

int perform(object me, object target)
{
        int damage;
        string msg;
        object weapon;
        int ap, dp, fp, pp,count;


        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(XIAN "只能在战斗中对对手使用。\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对！\n");

	if(me->is_busy())
		return notify_fail("你现在没空！！\n");

        if( !target || !target->is_character()
           || !me->is_fighting(target) || !living(target) )
                return notify_fail("只能对战斗中的对手使用。\n");
                
//	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
//		return notify_fail("这个绝技只能空手使用。\n");		
	if( (int)me->query("neili") < 2000  ) 
		return notify_fail("你的内力不够。\n");

	if( (int)me->query("neili") < me->query("max_neili")/7+200 ) 
		return notify_fail("你的内力不够。\n");

       if( !wizardp(me) &&(int)me->query_skill("taishan-sword", 1) < 500 )
		return notify_fail("你的本门外功不够!不能贯通使用！\n");

	if(!wizardp(me) && (int)me->query_skill("panshi-shengong", 1) < 500 )
		return notify_fail("你的本门内功不够高!不能贯通使用！\n");


//	if(!wizardp(me) && (int)me->query_skill("jiuyin-zhengong", 1) )
//		return notify_fail("你的杂学太多，无法对本门武功贯通使用！\n");

        if (!wizardp(me) && !me->query("guard/flag"))
		return notify_fail("你的江湖经验还不够，无法对本门武功贯通使用！\n");

        if (!wizardp(me) && !me->query("guard/ok"))
		return notify_fail("你还没有通过华山论剑! 无法对本门武功贯通使用！\n");

        if ( !wizardp(me) && me->query_skill_mapped("sword") == "love-sword")
                return notify_fail("用这门剑法，如何使用本门绝学!\n");


        if ( !wizardp(me) && me->query_skill_mapped("force") != "panshi-shengong")
                return notify_fail("不使用本门内功，如何使用本门绝学!\n");

//        if( !wizardp(me) && me->query_temp("weapon") )
//              return notify_fail("你必须空手才能使用本门绝学!\n");

        msg = HBWHT "$N贯通五岳剑派武学，使出了五岳剑派的绝学之精髓！\n" NOR;
message_vision(msg, me, target);               

if (me->query("hyvip")==4) 
	{me->add("neili",-500);}
	else
	{me->add("neili", -me->query("max_neili")/7);}



	message_combatd(BLU"$N"BLU"突然长啸一声 嵩山剑法，运气寒冰真气，举剑挺刺，在半空中划出道道剑光，空中气劲激荡，阵阵寒气向$n"BLU"奔袭而去！\n" NOR,me, target);

	me->add_temp("apply/attack", 200);
	me->add_temp("apply/damage", 3000);
	for(count=0;count<3;count++)
	{
		        msg =  HIW "$N大喝一声：接第"+chinese_number(count+1)+"道寒冰真气！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	}
target->receive_wound("qi",(me->query_skill("sword")+random(100))*3,me);
	me->add_temp("apply/attack", -200);
	me->add_temp("apply/damage", -3000);


        message_vision(HIG "但见寒光陡闪，恒山剑法 $N手中长剑越使越快，有如恒山的高低不平的奇峰，正是"+HIR"「恒山神峰」"NOR+HIC"！\n" NOR, me, target);
	me->add_temp("apply/attack", 200);    
        me->add_temp("apply/damage", 3000);
                target->receive_wound("qi",(me->query_skill("sword")+random(100))*3,me);
	for(count=0;count<3;count++)
	{
		        msg =  HIW "$N大喝一声：剑芒　第"+chinese_number(count+1)+"峰！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	}
	me->add_temp("apply/attack", -200);    
        me->add_temp("apply/damage", -3000);


	msg = CYN "$N使出　泰山剑法　泰山十八盘剑法之缠剑式，一把剑闪出十八道剑影！\n";

	if( random(me->query("combat_exp") ) > (int)target->query("combat_exp")/4 || random(3)==0)
	{
		target->receive_damage("qi",me->query_skill("sword")*3,me);
		target->receive_wound("qi",me->query_skill("sword")*3,me);
                msg +=HIR "$n" HIR "躲避不及，被$N"
                                           HIR "这一剑刺得口吐鲜血，接连后退。\n" NOR;

	} else
	{
		msg += HIC"可是$n看破了$N的剑招，一拧身跃出了剑影。\n" NOR;
		msg += HIY"$N却一下失去平衡，反陷入了被动。\n" NOR;

	}
	 message_combatd(msg, me, target);


	msg = HIC"$N"HIC"一声长啸，衡山剑法 剑附内力，一式「回风落雁」，"+weapon->name()+HIC"疾如闪电，瞬间罩住$n"HIC"全身各处大穴。\n剑影中，只见$N微一侧身，右手翻转，寒光中"+weapon->name()+"突然自上而下刺出，直指$n"HIC"身上要害 \n" NOR;
	message_combatd(msg, me, target);



	if( random(me->query("combat_exp") ) > (int)target->query("combat_exp")/4 || random(3)==0)
	{
		msg = HIY"$n顿时觉得眼前金光乱闪，双耳嗡嗡内鸣，不知那里一阵刺痛如针扎一般！\n" NOR;
target->receive_damage("qi",me->query_skill("sword")*3,me);
target->receive_wound("qi",me->query_skill("sword")*3,me);
	}
	else
	{
		msg =HIW"可是$n宁神静气，随手将$N的招数撇在一边。\n"NOR;
	}

        ap = me->query_skill("force")+150;
        dp = target->query_skill("dodge");
        fp = target->query_skill("force");
        pp = target->query_skill("parry");

        message_vision(HIW "\n$N" HIW "长啸一声，华山剑法 手中" + weapon->name() + HIW "随即不停转动，汹涌而"
                        "出，正是华山剑宗绝技「" HIM "夺命连环三仙剑" HIW "」，但是" + weapon->name() + HIW 
                        "\n剑锋突变，一剑顿时化为三剑，袭向$n" HIW "……\n" NOR, me, target);        

        msg = HIM "$N" HIM "将内力全都运到了剑上，呼的一剑，当头直劈。\n" NOR;
        if( random(me->query("combat_exp") ) > (int)target->query("combat_exp")/4 || random(3)==0)
{
                damage = ap + random(ap / 2)+100;
                target->receive_damage("qi",damage,me);
		target->receive_wound("qi",damage,me);
                msg +=HIR "$n" HIR "急忙后退，竟然躲避不及，被$N"
                                           HIR "这一剑震得口吐鲜血，接连后退。\n" NOR;
 }               
        else
        {
msg += CYN "$n" CYN "斜身闪开。\n" NOR;
        }

        msg += HIM "\n$N" HIM "圈转" + weapon->name() + HIM "，拦腰横削，剑势恢弘，剑气纵横，令人匪夷所思。\n" NOR;
       if( random(me->query("combat_exp") ) > (int)target->query("combat_exp")/4 || random(3)==0)
        {
                damage = ap + random(ap / 2)+100;
                target->receive_damage("qi",damage,me);
		target->receive_wound("qi",damage,me);

                msg +=HIR "此招来势当真快及，$n" HIR "哪里来得及闪"
                                           "避招架？只见$N" HIR "剑光闪过，$n"
                                           HIR "腰间霎时鲜血淋漓！\n" NOR;
        }
        else
              msg += CYN "$n" CYN "纵身从剑上越过。\n" NOR;
  
        msg += HIM "\n$N" HIM "长剑反撩，疾刺$p" HIM "后心，剑法之快，部位之准，当真闻所未闻。\n" NOR;
        if( random(me->query("combat_exp") ) > (int)target->query("combat_exp")/4 || random(3)==0)
 
  
          {
                damage = ap + random(ap / 2)+100;
                target->receive_damage("qi",damage,me);
		target->receive_wound("qi",damage,me);

                msg +=HIR "$n" HIR "身在空中，哪里来得及变招？只见$N"
                                           HIR "此剑掠过，$n" HIR "大声惨呼，鲜血四下飞溅！\n" NOR;
  
        }
else
                msg += CYN "$n" CYN "身在空中，不及变招，只能挥出一招，正击中$N"
                       CYN "剑上，略一借力，飘然避去。\n" NOR;
 
        me->start_busy(4);
        message_combatd(msg, me, target);
        return 1;
}
                                                                                                                                                                                                                                                                                                                                                                                                                              