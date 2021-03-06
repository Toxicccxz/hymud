// chan.c 缠剑诀 by stey

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h";

int perform(object me)
{
        string msg;
        object weapon, weapon2, target;
        int skill, ap, dp, damage;
int wound;

        int myskill,times;
        string number;
        myskill = (int)me->query_skill("bainiao-jian", 1);  

if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("只能在战斗中使用。\n");

 if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
        return notify_fail(RED"开什么玩笑，武器不对？\n"NOR);

        if ( !wizardp(me) && me->query_skill_mapped("force") != "honghua-shengong")
                return notify_fail("请使用红花神功!\n");

        if((int)me->query_skill("honghua-shengong",1) < 200)
                return notify_fail("你的红花神功还不够。。。\n"); 


        if((int)me->query_skill("bainiao-jian", 1) < 150)
                return notify_fail("你的百鸟剑法级别还不够，使用这一招会有困难！\n");

        if( me->query("con") < 20 || me->query("str") < 28 )
            return notify_fail("你的先天膂力根骨孱弱, 不能使用「缠剑诀」！\n");

        me->clean_up_enemy();
        target = me->select_opponent();
        skill = me->query_skill("bainiao-jian",1);

        if( !(me->is_fighting() ))
            return notify_fail("「缠剑诀」只能对战斗中的对手使用。\n");

        if (!objectp(weapon2 = target->query_temp("weapon")))
            return notify_fail("对方没有使用兵器，你用不了「缠剑诀」。\n");

        if( skill < 150)
            return notify_fail("你的百鸟剑法等级不够, 不能使用「缠剑诀」！\n");




        if( me->query("neili") < 300 )
            return notify_fail("你的内力不够，无法运用「缠剑诀」！\n");

        msg = HIC "$N手中的"YEL+weapon->query("name")+HIC"画出一道金光，斜刺一拉，「缠剑诀」！
"YEL+weapon->query("name")+HIC"剑尖正好缠在$n的"+weapon2->name()+"上。\n";
    message_combatd(msg, me, target, "");

        damage = 200 + random(skill);
        ap = me->query_skill("sword")/3 + skill;
        dp = target->query_skill("dodge")/2;
        if( dp < 1 )
            dp = 1;
        if( random(ap) > random(dp) )
        {
            if(userp(me))
                 me->add("neili",-30);
            msg = "$n顿时觉得眼前金光一闪，手腕一振，手中";
            msg += weapon2->name();
            msg += "脱手飞出！\n" NOR;
            me->start_busy(random(2));
            target->receive_damege("qi", damage);
            target->start_busy(3);
            weapon2->unequip();       
        }
        else
        {
            if(userp(me))
                 me->add("neili",-30);
            msg = "$n急运内力，将手中" + weapon2->name()+
"斜斜顺势一送一搭，抽了回来。\n"NOR;
            me->start_busy(3);
        }
    message_combatd(msg, me, target, "");
 if ((int)me->query_skill("bainiao-jian",1) > 200)
{
         damage = random((int)me->query_skill("sword")/3);
 message_vision(HIC"$N使出百鸟剑法的要旨「名可名 非常名」，连续几剑，浑无招式痕迹可循向$n刺去！\n"NOR,me,target, "");
           if (!target->is_busy()) target->start_busy(1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
   target->receive_damege("jing", damage/2);
                target->receive_damege("qi", damage+100);
        target->receive_wound("qi", random(damage));
     message_vision(HIC"$N酣畅淋漓地使了这招，剑意舒展.\n"NOR,me,target, "");   
        me->add("neili",-50);
}               

 if ((int)me->query_skill("bainiao-jian",1) > 380)
{
   if(myskill <260){
                times = 1;        
                number = "一";}
            else
                if (myskill <380){
                    times = 2;
                    number = "二";}
                else
                    if(myskill <420 ){
                           times = 3;
                           number = "三";}
                else
                    if(myskill <560 ){
                           times = 4;
                           number = "四";}
                else
                    if(myskill <660 ){
                           times = 5;
                           number = "五";}
                     else{ 
                           times = 6;
                           number = "六";}
      damage = random((int)me->query_skill("sword")/3);

       message_vision(HIM"\n$N突然剑招一变，手中的"+ weapon->query("name")+ HIB"无影无踪，浑身喷薄出凌厉的剑气。闪电般向$n攻出了"+number+"剑！\n"NOR,me,target, "");

        for(int i=1;i<=times;i++)
        {
        COMBAT_D->do_attack(me, target, weapon);
        COMBAT_D->report_status(target, 0);
   		target->receive_damege("jing", damage/3);
                target->receive_damege("qi", damage+1);
        target->receive_wound("qi", random(damage));
message_vision(HIR"\n结果$n被$N的『道可道 非常道』剑气穿心，眼前一黑，身子向后飞出丈许！！\n\n $n身上剑痕鲜血涌出......\n" NOR,me,target,"");
                COMBAT_D->report_status(target, 0);
        }
}       
me->add("neili",-50);
me->start_busy(2);

        return 1;
}
