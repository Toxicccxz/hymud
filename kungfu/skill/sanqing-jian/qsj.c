//By exp
//changed by wuyou@sk_xyj 2002-12-6

#include <condition.h>
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

int perform(object me, object target)
{
        string str;
        string msg;
        int extra;
        object weapon;
        object ob,victim;              // 对手的武器
        int i,attack_time,skill,damage,lvl;        

        extra = me->query_skill("sanqing-jian",1);
            if (! target) target = offensive_target(me);
  if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对！\n");

	if(me->is_busy())
		return notify_fail("你现在没空！！\n");



        if (! target || ! me->is_fighting(target))
                return notify_fail("只能在战斗中对对手使用。\n");
                
//	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
//		return notify_fail("这个绝技只能空手使用。\n");		
	if( (int)me->query("neili") < 2000  ) 
		return notify_fail("你的内力不够。\n");

	if( (int)me->query("neili") < me->query("max_neili")/7+200 ) 
		return notify_fail("你的内力不够。\n");

       if( !wizardp(me) &&(int)me->query_skill("sanqing-jian", 1) < 500 )
		return notify_fail("你的本门外功不够!不能贯通使用！\n");

	if(!wizardp(me) && (int)me->query_skill("kongdong-xinfa", 1) < 500 )
		return notify_fail("你的本门内功不够高!不能贯通使用！\n");


//	if(!wizardp(me) && (int)me->query_skill("jiuyin-zhengong", 1) )
//		return notify_fail("你的杂学太多，无法对本门武功贯通使用！\n");

        if (!wizardp(me) && !me->query("guard/flag"))
		return notify_fail("你的江湖经验还不够，无法对本门武功贯通使用！\n");

        if (!wizardp(me) && !me->query("guard/ok"))
		return notify_fail("你还没有通过华山论剑! 无法对本门武功贯通使用！\n");

        //if ( !wizardp(me) && me->query_skill_mapped("sword") == "sanqing-jian")
          //      return notify_fail("用这门剑法，如何使用本门绝学!\n");


        if ( !wizardp(me) && me->query_skill_mapped("force") != "kongdong-xinfa")
                return notify_fail("不使用本门内功，如何使用本门绝学!\n");

//        if( !wizardp(me) && me->query_temp("weapon") )
//              return notify_fail("你必须空手才能使用本门绝学!\n");

        msg = HBWHT "$N贯通崆峒武学，使出了崆峒的绝学之精髓！\n" NOR;
message_vision(msg, me, target);               
victim=target;
if (me->query("hyvip")==4) 
	{me->add("neili",-500);}
	else
	{me->add("neili", -me->query("max_neili")/7);}


     
        lvl = me->query_skill("sanqing-jian", 1);   
victim=target;

        weapon = me->query_temp("weapon");
        if (extra > 200) extra=200;
        me->add_temp("apply/damage",2500);
        me->add_temp("apply/attack",200);
        msg=HIW"$N手中的"+ weapon->name()+  "一出鞘，就化做一道光华击向$n，
一道弧形的光华：灿烂、辉煌、美丽。\n" + HIG"光华在闪动、变幻、高高在上，轻云飘忽，$n
只觉得这道光华彷佛就在自己眉睫间，却又不能确定它在那里？
它的变化，几乎已超越了人类能力的极限，几乎已令人无法置信。"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg="可是它确实在那里，而且无处不在。
可是就在$n已确定它存在时，它忽然又不见了。"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg=WHT"又奇迹般忽然出现，又奇迹般忽然消失。"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg=HIR"所有的动作和变化，都已在一刹那间完成，终止。
就像是流星，却又像是闪电，却又比流星和闪电更接近奇迹。
因为催动这变化的力量，是由$N发出来的。"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       me->add_temp("apply/damage",-2500);
       me->add_temp("apply/attack",-200);
       //me->add("neili", -100);
       //me->start_busy(2);


       msg = HIM "$N轻声长叹,使出了「那一剑的风情」,剑招中带着三分惊艳,三分潇洒,三分可爱和一分不可一世。\n";

  if(random(me->query_skill("sword")*me->query("int") ) > ((int)target->query_skill("force")*target->query("int"))/3)
        {
 skill=me->query_skill("sanqing-jian",1);
                if (! objectp(ob = target->query_temp("weapon")))
                {
                        msg += HIM "那剑犹如一道电光闪过,却比彩虹更加绚丽!"NOR"\n"HIR"结果$n已为$N的剑意所伤,哇,的一声吐出一口鲜血。\n" NOR;
                        //me->start_busy(1);
                        damage = 700 + skill;
                target->receive_damage("qi", damage,me); 
                target->receive_wound("qi", damage,me);
                        //target->start_busy(random(3));
                      
        message_vision(msg, me, target);
                } else
                {
                          msg += HIM"那剑犹如一道电光闪过,却比彩虹更加绚丽!"NOR"\n"HIR"结果$n已为$N的剑意所伤,哇,的一声吐出一口鲜血。\n" NOR;
                          msg += YEL"那一剑,击掉了$n手里的"+ob->query("name")+"。\n"NOR;

                        ob->unequip();
                        damage = 700 + skill;
                target->receive_damage("qi", damage,me);
                        target->receive_wound("qi", damage,me);
                        //me->start_busy(1);
                        //target->start_busy(1);

        message_vision(msg, me, target);

                } 
            
        }
else
        {
                msg += HIM"那剑犹如一道电光闪过,却比彩虹更加绚丽!\n"NOR"\n"HIY"结果$n让自身真气灌注四周空间,消解了$N的剑意。\n" NOR;
                //me->start_busy(3);
                message_vision(msg, me, target);

        } 


msg = HIY "$N凝神定气，使出七伤拳总诀中的「" HIR "藏离诀" HIY "」，双拳势如雷霆，向$n击去。\n"NOR;
        message_vision(msg, me, target);	
 if(random(3)==0 || (random(me->query("combat_exp",1)) >= target->query("combat_exp")/3))
        {

                msg = HIG "$n被$N拳风扫中，只觉全身真气失却驾驭，往外急泻！\n"NOR;
target->receive_damage("qi", (me->query_skill("sanqing-jian",1)*2),me);
target->receive_wound("qi", (me->query_skill("kongdong-xinfa",1)*2),me); 
		//msg += "($n"+str+")\n";
        }
        else
        {
                msg = HIG "只见$n不慌不忙，轻轻一闪，躲过了$N的必杀一击！\n"NOR;
        }
        message_vision(msg, me, target);

 msg = HIY "$N凝神定气，使出七伤拳总诀中的「" HIR "摧肝肠诀" HIY "」，双拳势如雷霆，向$n击去。\n"NOR;
        message_vision(msg, me, target);	
 if(random(3)==0 || (random(me->query("combat_exp",1)) >= target->query("combat_exp")/3))
        {

              msg = HIG "$n前胸中了$N全力一击，只觉一阵剧痛，“哇”的一声喷出一口鲜血！\n"NOR;
target->receive_damage("qi", (me->query_skill("sanqing-jian",1)*2),me);
target->receive_wound("qi", (me->query_skill("kongdong-xinfa",1)*2),me); 
		//msg += "($n"+str+")\n";
        }
        else
        {
                msg = HIG "只见$n不慌不忙，轻轻一闪，躲过了$N的必杀一击！\n"NOR;
        }
        message_vision(msg, me, target);


        msg = HIY "$N" HIY "怒喝一声，双拳连环，施出绝招「" HIR "伤字诀" HIY "」，双拳迅猛无比"
              "的袭向$n" HIY "。\n" NOR;
        message_vision(msg, me, target);	
 if(random(3)==0 || (random(me->query("combat_exp",1)) >= target->query("combat_exp")/3))
        {

                msg = HIG "只见$P" HIG "这一拳把$p" HIG"飞了出去，重重的摔在地上，吐血不止！\n" NOR;
target->receive_damage("qi", (me->query_skill("sanqing-jian",1)*2),me);
target->receive_wound("qi", (me->query_skill("kongdong-xinfa",1)*2),me); 
		//msg += "($n"+str+")\n";
        }
        else
        {
                msg = HIG "只见$n不慌不忙，轻轻一闪，躲过了$N的必杀一击！\n"NOR;
        }
        message_vision(msg, me, target);

     msg = HIY "$N凝神定气，使出七伤拳总诀中的「" HIR "伤肺诀" HIY "」，双拳势如雷霆，向$n击去。\n"NOR;
        message_vision(msg, me, target);	
 if(random(3)==0 || (random(me->query("combat_exp",1)) >= target->query("combat_exp")/3))
        {


                msg = HIG "$N的拳风隐含风雷，“澎”的一声打在$n身上！\n$n只觉得呼吸不顺，顿时脚步慢了许多！\n"NOR;
target->receive_damage("qi", (me->query_skill("sanqing-jian",1)*2),me);
target->receive_wound("qi", (me->query_skill("kongdong-xinfa",1)*2),me); 
		//msg += "($n"+str+")\n";
        }
        else
        {
                msg = HIG "只见$n不慌不忙，轻轻一闪，躲过了$N的必杀一击！\n"NOR;
        }
        message_vision(msg, me, target);
        
       msg = HIY "$N凝神定气，使出七伤拳总诀中的「" HIR "损心诀" HIY "」，双拳势如雷霆，向$n击去。\n"NOR;
        message_vision(msg, me, target);	
 if(random(3)==0 || (random(me->query("combat_exp",1)) >= target->query("combat_exp")/3))
        {

msg = HIG "$N连环拳势如风雷，$n中了$N开山裂石的一拳，顿时心神大震，不能随意出招！\n"NOR;
target->receive_damage("qi", (me->query_skill("sanqing-jian",1)*2),me);
target->receive_wound("qi", (me->query_skill("kongdong-xinfa",1)*2),me); 
		//msg += "($n"+str+")\n";
        }
        else
        {
                msg = HIG "只见$n不慌不忙，轻轻一闪，躲过了$N的必杀一击！\n"NOR;
        }
        message_vision(msg, me, target);
        
       msg = HIY "$N凝神定气，使出七伤拳总诀中的「" HIR "意恍惚诀" HIY "」，双拳势如雷霆，向$n击去。\n"NOR;
        message_vision(msg, me, target);	
 if(random(3)==0 || (random(me->query("combat_exp",1)) >= target->query("combat_exp")/3))
        {
 msg = HIC "结果$N双拳击中时，却是若有若无。\n$n正在奇怪间，已被$N的真气制住，神情恍恍忽忽的！\n"NOR;
target->receive_damage("qi", (me->query_skill("sanqing-jian",1)*2),me);
target->receive_wound("qi", (me->query_skill("kongdong-xinfa",1)*2),me); 
		//msg += "($n"+str+")\n";
        }
        else
        {
                msg = HIG "只见$n不慌不忙，轻轻一闪，躲过了$N的必杀一击！\n"NOR;
        }
        message_vision(msg, me, target);

msg = HIY "$N凝神运功，使出“七伤拳”最后的绝招，七种股无比强劲的热气呼啸的扑向$n身上各大要穴。\n"+HIC "$n急提丹田之气与体内来回撞击的"+chinese_number(i)+"股劲气相扩。\n"NOR;
        message_vision(msg, me, target);	
 if(random(3)==0 || (random(me->query("combat_exp",1)) >= target->query("combat_exp")/3))
        {

msg = HIY"结果$n抵受不住$N的七种劲气在体内来回的撞击。"+GRN"\n($n"+HIR"所受的内伤着实不轻。"+GRN")\n"NOR;
target->receive_damage("qi", (me->query_skill("sanqing-jian",1)*4),me);
target->receive_wound("qi", (me->query_skill("kongdong-xinfa",1)*4),me); 
		//msg += "($n"+str+")\n";
        }
        else
        {
                msg = HIG "只见$n不慌不忙，轻轻一闪，躲过了$N的必杀一击！\n"NOR;
        }
        message_vision(msg, me, target);                                        


me->start_busy(4);


       return 1;
}

