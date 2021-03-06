// 七剑连环指 By cigar 2002.04.23
#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h";
int perform(object me, object target)
{
        object weapon;
        string dodskill,msg;            
             
        int damage, p;  
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展这一招「七剑连环指」？\n");


        if(!me->is_fighting())
                return notify_fail("「七剑连环指」只能在战斗中使用！\n");

        if((int)me->query("max_neili") < 500 )
                return notify_fail("你的内力不够！\n");

        if((int)me->query("neili") < 500 )
                return notify_fail("你的内力不足！\n");

        if((int)me->query("jing") < 500 )
                return notify_fail("你的精神不足，没法子施用外功！\n");

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




        message_vision(HIC"\n$N使出七剑连环指，剑锋一转，右手食指跟着弹出，只见剑花指风相辉相映，直袭$n！\n"NOR,me,target);
       me->add_temp("apply/attack", 100);    
        me->add_temp("apply/damage", 1800);
            target->start_busy(1);
        msg=HIC"$N嫣然一笑，诡异之极，身法陡然加快！"NOR;
        me->set_temp("QJB_perform", 1);
            COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        msg=HIC"$N情急智生，提指向$n右眼刺去，！"NOR;
        me->set_temp("QJB_perform", 2);  
     COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        msg=HIC"$N双手合十互击，陡然向外一分，双掌顿时变得轻灵飘逸，灵动异常！"NOR;
        me->set_temp("QJB_perform", 3);
             COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        
        msg=HIC"$N这一下使得剑气纵横，竟然声震山谷。不明其理之人，无不骇异！！"NOR;
        me->set_temp("QJB_perform", 4);
     COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        
        msg=HIC"$N似有无穷弹力，似真似幻，无论$n怎么变招抢攻，总是被弹了出去！"NOR;
        me->set_temp("QJB_perform", 5);
             COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        
        msg=HIC"$N这时一声高喝，脸上殷红如血，不明其理之人，无不骇异！"NOR;
        me->set_temp("QJB_perform", 6);
     COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        
        msg=HIC"只听“啪”的一声，$N手中的利器被内力冲击，裂成了碎片，飞向$n"NOR;
        me->set_temp("QJB_perform", 7);
     COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        me->delete_temp("QJB_perform");
       me->add_temp("apply/attack", -100);    
        me->add_temp("apply/damage", -1800);



        if ((int)me->query_skill("bainiao-jian",1) > 350)
        {
       tell_object(me, HIW"\n\n你悄悄使出"BLU"风剑"HIW"，运起一股无形无质的阴寒之气，直插"+target->name()+"胸口玉堂穴要穴！\n\n"NOR); 
//      if(random(me->query_skill("force"))*(me->query_temp("fengdao")+1) >
      if(random(me->query_skill("force"))*3/2 >
         random(target->query_skill("force"))){                
           damage = me->query_skill("force");
           damage = damage + random(damage) + random(damage);
           if(target->query_skill("force")-50 > me->query_skill("force"))
             damage = damage/2 + random(damage);
           if(target->query_skill("force") > me->query_skill("force")*2)
             damage = random(50);
           if(me->query_skill("force") > target->query_skill("force")*2)
             damage = damage+random(damage);
           if(damage > 600){
              tell_object(target, HIB"\n\n突然之间，一股无形无质、锋如利剑的阴寒之气直插入你胸口的“玉堂穴”中！
"HIR"你霎时之间闭气窒息，全身动弹不得！\n\n"NOR);
              target->start_busy(3);
              }
           else if(damage <= 50){
              damage = 10;
              tell_object(target, HIY"\n突然之间，一股利如利剑般的阴寒之气直插你胸口的玉堂穴！
幸好你护体神功遍护全身，这股阴风刀虽利，却也伤你不得！\n\n"NOR);
              tell_object(me, HIY"你连运风剑的内劲，但见对方竟是毫不费力的抵挡了下来！\n\n"NOR);
              }
           else{
              tell_object(target, HIB"\n突然之间，一股阴劲如刀、如剑、如匕、如凿，直插入你胸口的“玉堂穴”中！
"HIR"你霎时之间闭气窒息，全身动弹不得！\n\n"NOR);
              target->start_busy(2);
              }
           target->receive_damage("qi", damage);
           target->receive_wound("qi", damage/3);
           target->add("neili", -damage/2); 
           p = (int)target->query("qi")*100/(int)target->query("max_qi");
           tell_room(environment(target), HIR + target->name()+"突然全身猛地一震，面如金纸，震退了数步，彷佛被什么人在胸口处猛击了一下似的！\n\n" NOR, ({ target })); 
           msg = damage_msg(damage, "内伤");
           msg += "( $n"+eff_status_msg(p)+" )\n"; 
           message_vision(msg, me, target);          
   
           me->start_busy(2);
           me->add("neili", -100);
           }
         
     else {       
          me->add("neili", -100);

          tell_object(me, HIY"结果风剑内劲还没触到"+target->name()+"的身体便已经散了。\n\n"NOR);
      
          }
}
        me->receive_damage("jing", 100);
        me->add("neili", -100);

me->start_busy(3);
        return 1;
}


