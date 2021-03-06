//天魔降伏
//modify by Wuyou@Sanjie

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        object *inv, obj;
        object weapon;
        int i,y, mypot,tapot,mystr,tastr,myexp,taexp,mylvl,talvl,j,j2;
        weapon = me->query_temp("weapon");

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展这一招「天魔降伏」？\n");

        if(!me->is_fighting())
                return notify_fail("「天魔降伏」只能在战斗中使用！\n");

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("这门绝学只能对战斗中的对手使用。\n");

    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "staff")
        return notify_fail(RED"开什么玩笑，武器不对？\n"NOR);

        if ( !wizardp(me) && me->query_skill_mapped("force") != "zhanzhuang-gong")
                return notify_fail("请使用四平大马站桩功!\n");
                
        if((int)me->query_skill("yijinjing", 1) < 150)
                return notify_fail("你的易筋经级别还不够，使用这一招会有困难！\n");
        if((int)me->query("max_neili") < 2000 )
                return notify_fail("你的内力不够！\n");

        if((int)me->query("neili") < 500 )
                return notify_fail("你的内力不足！\n");

        if((int)me->query("jing") < 500 )
                return notify_fail("你的精神不足，没法子施用外功！\n");

        if((int)me->query_skill("lunhui-zhang", 1) < 160)
                return notify_fail("你的轮回杖级别还不够，使用这一招会有困难！\n");
                
        if( time()-(int)me->query_temp("xiangfu_end") < 3 )  
                return notify_fail("你的内息尚未平复，不能再次使用天魔降伏。\n");                

        message_vision(HIY"$N口中念动"HIW"《金刚般若波罗蜜经》"HIY"：\n"NOR,me,target);
        message_vision(HIY"\n\t生死炽燃，苦恼无量，发大乘心，普济一切。\n"NOR,me,target);
        message_vision(HIY"\t愿代众生，受无量苦，令诸众生，毕竟大乐。\n"NOR,me,target);
        message_vision(HIY"\t凡所有相，皆是虚妄，诸相非相，即见如来。\n"NOR,me,target);
        message_vision(HIY"\t降伏其心，愿乐欲闻，即见如来，未为胜也。\n"NOR,me,target);
        message_vision(HIY"\t知我说法，如筏喻者，法尚应舍，何况非法。\n"NOR,me,target);
        message_vision(HIY"\t放下屠刀，立地成佛，佛说非身，是名大身!\n"NOR,me,target);
//      message_vision(HIR"\n$N手中的"+weapon->query("name")+HIR"发出阵阵霞光，只见几道金光射向$n……\n"NOR,me,target);
        message_vision(HIY"\n        〓〓"HIR"魑魅魍魉"HIW">>>>><<<<<"HIR"天魔降伏"HIY"〓〓\n"NOR,me,target);
        
        mystr=(int)me->query("str");
        tastr=(int)target->query("str");
        myexp=(int)me->query("combat_exp")/20;
        taexp=(int)target->query("combat_exp")/30;
        mylvl=(int)me->query_skill("staff")+(int)me->query_skill("lunhui-zhang");
        talvl=(int)target->query_skill("parry")+(int)target->query_skill("dodge");
        mypot=mystr*mylvl+myexp;
        tapot=tastr*talvl+taexp;
        y=random(3);
        if( mypot >tapot/2+random(tapot)/2) 
        {
                message_vision(HIY"\n$N两眼痴痴看着远方，意识好象受到了佛的召唤,似乎杀意全无，楞然矗立顾不及躲闪...\n\n"NOR, target);
                
j= random((int)me->query("max_neili")/4+(int)me->query("max_neili")/10+(int)me->query("force_factor"));
j2= random((int)me->query("max_jing")/4+(int)me->query("force_factor"));
if (!userp(me) && j > 5000) j=5000;
if (!userp(me) && j2 > 3000) j2=3000;

if ( j > 55000) j=55000;
if ( j2 > 53000) j2=53000;

                target->receive_damage("qi", 500 +j,me);
                target->receive_damage("jing", 300 +j2,me);    
                target->receive_wound("qi", 500 + j,me);
                target->receive_wound("jing", 300 + j2,me);    

                COMBAT_D->report_status(target);
                COMBAT_D->report_sen_status(target);         
                
        }
        else 
        {
                message_vision(HIG"谁知$N"HIG"竟然全无感觉，脸上杀气却越来越浓！\n"NOR, target);
        }
        
        me->start_busy(2);
        me->add("neili", -200);
        //me->receive_damage("jing", 60);
        me->set_temp("xiangfu_end",time());

        return 1;
}

