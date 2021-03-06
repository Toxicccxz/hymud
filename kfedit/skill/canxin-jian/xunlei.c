//迅雷 
//by junhyun@SK 

#include <ansi.h> 
#include <skill.h> 
#include <combat.h> 
#include <weapon.h> 


inherit F_SSERVER;

#include "/kungfu/skill/eff_msg.h";
string *zhaoshi_name = ({ 
        RED"$N手中$w晃动，「白虹贯日」使将出来，剑招奇变横生，$n瞧得心惊神眩，不知$N究竟出了多少招"NOR, 
        GRN"$N手上$w慢慢点出，突然间在空中一颤，一招「苍松迎客」，剑刃暗发嗡嗡之声，$w来路如鬼如魅，顷刻间竟然已绕到了$n背后"NOR, 
        YEL"$N$w如云雾变化，正是一招「天绅倒悬」，极尽诡奇之能事，动向无定，不可捉摸，$n觉一阵眼花缭乱，顿感穷於应付！ "NOR, 
        BLU"$N突然间身子往斜里窜出，使出「有凤来仪」，听$w陡发铮然之音，无数光环乱转，霎时之间已将$n裹在一团剑光之中"NOR, 
        MAG"$N全不理会对方攻势来路，使出一招「鹤翔紫盖」，变化莫测地攻向$n，剑势竟无丝毫迹象可寻"NOR, 
}); 
 
int perform(object me,object target) 
{ 
        object weapon; 
        mapping fam = me->query("family"); 
        mapping my_fam = me->query("family"); 
        int i=me->query_skill("canxin-jian",1); 
        int d=me->query_skill("baiyun-xinfa",1); 
        
        if( !target ) target = offensive_target(me); 

        if( !target || !me->is_fighting(target) || !living(target) 
        || environment(target)!=environment(me)) 
                return notify_fail(HIW"[迅雷]"NOR"只能对战斗中的对手使用。\n"); 

if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("只能在战斗中使用。\n");

 if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
        return notify_fail(RED"开什么玩笑，武器不对？\n"NOR);

        if ( !wizardp(me) && me->query_skill_mapped("force") != "baiyun-xinfa")
                return notify_fail("请使用白云心法!\n");

        if((int)me->query_skill("baiyun-xinfa",1) < 200)
                return notify_fail("你的白云心法还不够。。。\n"); 
                

        if( (int)me->query_skill("canxin-jian", 1) < 380 ) 
                return notify_fail("你的残心剑法还未练成，不能使用[迅雷]！\n"); 


        if (!objectp(weapon = me->query_temp("weapon")) || weapon->query("skill_type") != "sword" 
        || me->query_skill_mapped("sword") != "canxin-jian") 
                return notify_fail("你现在无法使用[迅雷]！\n"); 
        if(me->query_temp("shushan/xunlei")  ) 
                return notify_fail("你正在使用[迅雷]！\n"); 
        
        if((int)me->query("max_neili") < 5000 ) 
                return notify_fail("你的内力修为不够，不能使用[迅雷]！\n"); 
        if((int)me->query("neili") < 2000 ) 
                return notify_fail("你现在真气不足，不能使用[迅雷]！\n"); 
        if((int)me->query("jing") < 1500 ) 
                return notify_fail("你的精神状态太差了，不能使用[迅雷]！\n"); 
        if((int)me->query("qi") < 1500 ) 
                return notify_fail("你的气血太少了，不能使用[迅雷]！\n"); 
        message_vision(HIG" 
        $N仰天一声清啸，斜行而前，手中利剑横削直击，【疾风迅雷剑】当真是迅捷无比. 
        未到五六招，剑势中已发出隐隐风声，七八招后$N已和利剑合二为一。 
        顷刻间剑光剑气如急风暴雨般向$n身上招呼！\n"NOR, me,target); 
        me->set_temp("shushan/xunlei", 1); 
        target->start_busy(3); 
        call_out("check_fight", 2, me, 6); 
        return 1; 
} 

void remove_effect(object me) 
{ 
        if(!me) return; 
        me->delete_temp("shushan/xunlei"); 
        me->delete_temp("combat_yield"); 
        if(!living(me)) return; 
        message_vision(HIG"\n$N的"HIW"「迅雷」"HIG"绝技运用完毕，缓缓收招。\n"NOR, me); 
        me->start_perform(3,"「迅雷」"); 
        
} 

void check_fight(object me, int i) 
{ 
        object weapon, target; 
        string msg; 
        
        if (!me ) return;       
        target = offensive_target(me); 
         
        if( !living(me)  
        || !target  
        || !me->is_fighting(target)  
        || !living(target) 
        || environment(target)!=environment(me) 
        || !me->query_temp("shushan/xunlei")) 
                return remove_effect(me); 
        else if(me->query_skill_mapped("sword") != "canxin-jian"){ 
                tell_object(me, HIR"你临时改换剑法，不再使用「迅雷」绝技。\n"); 
                remove_effect(me); 
        } 

/*
        else if(me->query_skill_mapped("parry") != "canxin-jian"){ 
                tell_object(me, HIR"你临时改换招架，不再使用「迅雷」绝技。\n"); 
                remove_effect(me); 
        } 
*/
        else if (!objectp(weapon = me->query_temp("weapon")) || weapon->query("skill_type") != "sword"){ 
                tell_object(me, HIR"你临时改换武器，不再使用「迅雷」绝技。\n"); 
                remove_effect(me); 
        } 
       else if (i <=0 ){ 
                tell_object(me, HIR"你一口真气用完,不再使用「迅雷」绝技。\n"); 
                remove_effect(me); 
        }         
        else if(me->is_busy())  
                call_out("check_fight", 0, me, i); 
        else{ 
                message_vision(HIW"旁观众人只觉寒气逼人，脸上、手上被疾风刮得隐隐生疼，不由自主的后退。\n"NOR, me,target); 
                me->add_temp("apply/attack",200); 
                me->add_temp("apply/damage",3000);  
                me->set_temp("combat_exp",1); 
                me->set_temp("shushan/xunlei",1); 
                msg = zhaoshi_name[random(sizeof(zhaoshi_name))]; 
                COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg); 
                msg = zhaoshi_name[random(sizeof(zhaoshi_name))]; 
                COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg); 
                msg = zhaoshi_name[random(sizeof(zhaoshi_name))]; 
                COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg); 
                msg = zhaoshi_name[random(sizeof(zhaoshi_name))]; 
                COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg); 
                msg = zhaoshi_name[random(sizeof(zhaoshi_name))]; 
                COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg); 
                me->add_temp("apply/attack",-200); 
                me->add_temp("apply/damage",-3000); 
if (!me->is_busy()) me->start_busy(2);
        
                me->add("neili",-50); 
                if(me->query("gender")=="女性") me->add("neili",-30); 
                call_out("check_fight", 2, me, i-1); 
        } 
}          
