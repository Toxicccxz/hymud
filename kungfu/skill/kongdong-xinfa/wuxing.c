#include <ansi.h>

inherit F_SSERVER;
void doblow(object);
int random_go(object victim,string* dirs);

int exert(object me)
{
        string msg,start;
        int busy_time, ap, dp ,msgnum ,damage;
object target;

        if( !target ) target = offensive_target(me);
        if ( !me->is_fighting() && !target) target=me;

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse() )
                return notify_fail("你要对谁施展这个法术？\n");

if ( target != me ) {
        if ( !me->is_fighting() )
                return notify_fail("这个法术只能在战斗中使用！\n");
   

}



        if((int)me->query_skill("taiyi",1) < 100)
                return notify_fail("你的太乙道法还不够。。。\n");

        if((int)me->query_skill("kongdong-xinfa",1) < 100)
                return notify_fail("你的崆峒心法还不够。。。\n"); 




        if ( target == me ) {

                if((int)me->query("neili") < 100 )
                        return notify_fail("你的内力不够！\n");
                if((int)me->query("jing") < 100 )
                        return notify_fail("你的精神没有办法有效集中！\n");


 if (me->is_busy())
                return notify_fail("你现在正忙！\n");
   

        if( me->is_fighting() )
                return notify_fail("战斗中无法使用五行转换！\n");
        if( me->is_ghost())
                return notify_fail("鬼魂无法使用五行转换！\n");

        if(environment(me)->query("no_fly")||environment(me)->query("no_death_penalty")
                || environment(me)->query("no_fly"))
                return notify_fail("此地不能使用五行转换。\n");  

if( !environment(me)->query("no_fight"))
return notify_fail("只有安全地点才能使用五行转换。\n");  

if(environment(me)->query("short")==BLU"山洞"NOR
       ||environment(me)->query("short")==WHT"钟乳石洞"NOR
       ||environment(me)->query("short")==YEL"岩洞"NOR
       ||environment(me)->query("short")==RED"熔岩洞"NOR
       ||environment(me)->query("short")==CYN"石洞"NOR
       ||environment(me)->query("magicroom")
       ||environment(me)->query("maze")      
       )
return notify_fail("只有安全地点才能使用五行转换。\n");   

                me->add("neili", -100);
   

                me->receive_damage("jing", 10);

                if( random(me->query_skill("taiyi")) < 20 ) {
                        
                        write("你失败了。\n");
                        return 1;
                }
        msgnum = random(5);
        switch ( msgnum ) {
        case 0:
            msg = WHT "$N口中喃喃地念著咒文，忽然大喝一声“疾！”\n"  +
            "只见$N化作一道黑气，无影无踪地消失了！\n\n"NOR ;
            break ;
        case 1:
            msg = HIY "$N口中喃喃地念著咒文，忽然大喝一声“疾！”\n"  +
            "只见$N化作一道金光，嗖地一声飞走了！\n\n"NOR ;
            break ;
        case 2:
            msg = HIR "$N口中喃喃地念著咒文，忽然大喝一声“疾！”\n"  +
            "只见$N化作一团火焰，然后消失得无影无踪！\n\n"NOR ;
            break ;
        case 3:
            msg = HIG "$N口中喃喃地念著咒文，忽然大喝一声“疾！”\n"  +
   

            "只见$N化作一段枯木，真身已不知去向！\n\n"NOR ;
            break ;
        case 4:
            msg = BLU "$N口中喃喃地念著咒文，忽然大喝一声“疾！”\n"  +
            "只见$N化作一团大雾，不知飘到哪里去了！\n\n"NOR ;
            break ;
        }

        message_vision(msg, me);


        switch ( msgnum ) {
        case 0:
            start="/d/death/mengpo";
            message("vision", WHT+me->name()+"的身影在一团黑气中凝结成形。\n"NOR,
              environment(me), me);
            tell_object(me, WHT"你的身影突然出现在一团黑气中。\n"NOR);
            break ;
        case 1:
            start="/d/city/wumiao";
            message("vision", HIY+me->name()+"突然从一道金光中跳了出来。\n"NOR,
              environment(me), me);
            tell_object(me, HIY"你的身影突然出现在一道金光中。\n"NOR);
   




            break ;
        case 2:
            start="/d/xibei/kongdong/xuanyuan_gong";
            message("vision", HIR+"突然火光一闪,"+me->name()+"从中冒了出来。\n"NOR,
              environment(me), me);
            tell_object(me, HIR"你的身影突然出现在一团火焰中。\n"NOR);
            break ;
        case 3:
            start="/d/wudang/sanqingdian";
            message("vision", HIG+"只见一段枯木裂开,"+me->name()+"从中钻了出来。\n"NOR,
              environment(me), me);
            tell_object(me, HIG"你的身影突然出现在一段枯木中。\n"NOR);
            break ;
        case 4:
            start="/d/kunlun/jingshenfeng";
            message("vision", BLU+"一股浓雾飘来，凝结成"+me->name()+"的身形。\n"NOR,
              environment(me), me);
            tell_object(me, BLU"你的身影突然出现在一团浓雾中。\n"NOR);
            break ;
        }
        me->move(start);
me->start_busy(5);
        return 2+random(3);
   
        }

        if((int)me->query_skill("taiyi") < 100)
                return notify_fail("你的太乙道法还不够。。。\n");

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("这门绝学只能对战斗中的对手使用。\n");

        if((int)me->query_skill("kongdong-xinfa",1) < 100)
                return notify_fail("你的崆峒心法还不够。。。\n"); 

        if((int)me->query("neili") < 200 )
                return notify_fail("你的内力不够！\n");
    
        if((int)me->query("jing") < 200 )
                return notify_fail("你的精神没有办法有效集中！\n");

        me->add("neili", -200);
        me->receive_damage("jing", 20);
   
        if( random(me->query_skill("taiyi")) < 40 ) {
                write("你失败了。\n");
                return 1;
        }

        if  (target->is_busy() ) 
        { 
                msgnum = random(4);}
                else  msgnum = random(5) ;
                switch ( msgnum ) {
                case 4:    
                        msg = WHT "$N口中喃喃地念著咒文，忽然大喝一声“疾！”\n"  +
                        "只见一团黑气罩在$n身上！\n\n"NOR ;
                        ap = me->query_skill("taiyi");
                        ap = ( ap * ap * ap / (4 * 400) ) * (int)me->query("jing");
                        ap += (int)me->query("combat_exp");
                        dp = target->query_skill("taiyi");
                        dp = dp * dp * dp ;
                        dp += (int)target->query("combat_exp");
                        break ;
                case 1:
                        msg = HIY "$N口中喃喃地念著咒文，忽然大喝一声“疾！”\n"  +
                           "只见一道金光射向$n！\n\n"NOR ;
                        ap = me->query_skill("taiyi");
                        ap = ( ap * ap * ap / 800 ) * (int)me->query("qi");
                        ap += (int)me->query("combat_exp");
                        dp = target->query_skill("taiyi");
                        dp = dp * dp * dp ;
                        dp += (int)target->query("combat_exp");
                        break;
                case 2:
                        msg = HIR "$N口中喃喃地念著咒文，忽然大喝一声“疾！”\n"  +
                        "只见一团火焰直逼$n！\n\n"NOR ;
                        ap = me->query_skill("taiyi");
                        ap = ( ap * ap * ap / 1600 ) * (int)me->query("jing");
                        ap += (int)me->query("combat_exp"); 
                        dp = target->query_skill("taiyi");
                        dp = dp * dp * dp ;
                        dp += (int)target->query("combat_exp");

                        break;
                case 3:
                        msg = HIG "$N口中喃喃地念著咒文，忽然大喝一声“疾！”\n"  +
                        "只见空中落下无数巨木，向$n当头砸下！\n\n"NOR ;
                        ap = me->query_skill("taiyi");
   


                        ap = ( ap * ap * ap / 1200 ) * (int)me->query("max_neili");
                        ap += (int)me->query("combat_exp"); 
                        dp = target->query_skill("taiyi");
                        dp = dp * dp * dp ;
                        dp += (int)target->query("combat_exp");
                        break;
                case 0:
                        msg = BLU "$N口中喃喃地念著咒文，忽然大喝一声“疾！”\n"  +
                        "只听一声海啸，一股巨浪正向$n冲来！\n\n"NOR ;
                        ap = me->query_skill("taiyi");
                        ap = ( ap * ap * ap / 2400 ) * (int)me->query("neili");
                        ap += (int)me->query("combat_exp"); 
                        dp = target->query_skill("taiyi");
                        dp = dp * dp * dp ;
                        dp += (int)target->query("combat_exp");
                        break;
                }
                if( random(ap + dp) > dp )  {

                        switch (msgnum) {

                        case 4:

                                busy_time  += (int)me->query("force_factor")/50;
                                   if ( busy_time < 0 ) busy_time = 0 ;
                                if (busy_time > 7) busy_time =8;            
                                target->start_busy(busy_time+2);
                                msg +=  WHT "\n$n被黑气笼罩，只觉得四周灰蒙蒙地一片，什么也看不清楚！\n" NOR;
                                break;
                        case 1:
                                damage = 200+(int)me->query("max_neili") / 10
                                + random((int)me->query("eff_qi") / 3);
                                damage -= (int)target->query("max_neili") / 15
                                + random((int)target->query("eff_qi") / 4);
                                damage += (int)me->query("force_factor")
                                - (int)target->query("force_factor");
                                if (damage > 0) msg +=  HIY "\n结果「嗤」地一声，金光从$n身上透体而过，
                 \n拖出一条长长的血箭，直射到两三丈外的地下！\n" NOR;
                                if (damage <= 0 ) 
                                {
                                        msg += HIY "\n但是$n运气硬挡了这一下，并无大碍 。\n" NOR;
                                        damage =10;
                                }
                                if (damage > 0) damage +=random((damage*(int)me->query_skill("taiyi"))/100);
                                if (damage >15000) damage=15000;
                                	
                                
                                               	if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
                       
                                if (damage > 0) target->receive_damage("qi", damage,me);
                                if (damage > 0) target->receive_wound("qi", damage/4,me);
                                break;
                           case 2:
                                damage = 100+(int)me->query("max_neili") / 10 +
                                random((int)me->query("eff_jing") / 5);
                                damage -= (int)target->query("max_neili") / 15 +
                                random((int)target->query("eff_jing") / 8);
                                damage+=(int)me->query("force_factor")-(int)target->query("force_factor");
                                if( damage > 0 ) msg +=  HIR "\n$n被火光一逼，只觉得眼花撩乱，心神不定，差点晕倒在地！\n" NOR;
                                if ( damage <=0 ) 
                                {
                                        msg += HIR "\n$n强敛心神，居然没受太大的影响。\n" NOR; 
                                        damage = 20;
                                 }
                                damage +=random((damage*(int)me->query_skill("taiyi"))/100);
                                 if (damage >15000) damage=15000;
                                	
                                               	if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;

 
                                target->receive_damage("jing", damage,me);
                                target->receive_wound("jing", damage/3,me);
                
                                break;
                        case 3:
                                damage = (int)me->query("max_neili") / 20 +
                                random((int)me->query("max_neili") / 10);
                                damage -= (int)target->query("max_neili") / 30 +
                                random((int)target->query("eff_neili") / 15);   
                                damage +=(int)me->query("force_factor")-(int)target->query("force_factor");
   






                                if( damage > 0 ) msg +=  HIG "\n$n被巨木砸个正着，似乎受了些内伤！\n" NOR;
                                if ( damage <=0 ) 
                                { 
                                        msg += HIG "\n$n见势不妙，左躲右闪，似乎只受了点擦伤。\n" NOR; 
                                        damage =5;
                                }
                                damage +=random((damage*(int)me->query_skill("taiyi"))/100);
  
  if (damage >15000) damage=15000;
                                if (( damage > 0 ) && (damage >=(int)target->query("neili"))) target->set("neili", 0); 
                                if ((damage >0) && (damage < (int)target->query("neili"))) target->add("neili", -damage);
        
                                break;  
                        case 0:
                                damage = (int)me->query("max_neili") / 10 +
                                random((int)me->query("max_neili") / 10);
                                damage -= (int)target->query("max_neili") / 15 +
                                random((int)target->query("max_neili") / 15);
                                damage+=(int)me->query("force_factor")-(int)target->query("force_factor");
                                if( damage > 0 ) msg +=  BLU "\n$n被巨浪淋得象落汤鸡，法力也消失了不少！\n" NOR;
                                if ( damage <=0 ) 
                                { 
                                        msg += BLU "\n$n觉得有点空荡荡的，似乎法力受了点影响。\n" NOR; 
                                        damage = 10 ;
                                }
                                
                                 
                                	

                                   if( damage > 0 ) damage +=random((damage*(int)me->query_skill("taiyi"))/100);
                                   	if (damage >15000) damage=15000;
                                if (( damage > 0 ) && (damage >=(int)target->query("neili"))) target-> set("neili", 0);
                                if (( damage > 0 ) && (damage < (int)target->query("neili"))) target-> add("neili", -damage);
                                target->start_busy(5);
                                break;
                        }
                } else {
                msg += "但是$n纵身一跃，躲开了这一击。\n";
        
        }
        message_vision(msg, me, target);
        if( ( damage > 0 ) && ( msgnum == 1 ))COMBAT_D->report_status(target);
        if( ( damage > 0 ) && ( msgnum == 2 ))COMBAT_D->report_sen_status(target);
me->start_busy(3);
        return 3+random(3);
}