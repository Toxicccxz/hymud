#include <ansi.h>

#include <combat.h>
inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        string str;
        int snowsword,f,bufa,ini_damage_apply,times,damage;
        string desc_msg="";
        int sword_level;
        string msg;
        int ap, dp,qixue,eff_qi,max_qi,qi_pcg,dmg;
object victim;
                        
        snowsword = (int)me->query_skill("snowsword", 1);
        victim=target;
        f = (int)me->query_skill("bitao-shengong", 1);
        bufa = (int)me->query_skill("qiongya-bufa", 1);
       
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

       if( !wizardp(me) &&(int)me->query_skill("snowsword", 1) < 500 )
		return notify_fail("你的本门外功不够!不能贯通使用！\n");

	if(!wizardp(me) && (int)me->query_skill("bitao-shengong", 1) < 500 )
		return notify_fail("你的本门内功不够高!不能贯通使用！\n");


//	if(!wizardp(me) && (int)me->query_skill("jiuyin-zhengong", 1) )
//		return notify_fail("你的杂学太多，无法对本门武功贯通使用！\n");

        if (!wizardp(me) && !me->query("guard/flag"))
		return notify_fail("你的江湖经验还不够，无法对本门武功贯通使用！\n");

        if (!wizardp(me) && !me->query("guard/ok"))
		return notify_fail("你还没有通过华山论剑! 无法对本门武功贯通使用！\n");

        //if ( !wizardp(me) && me->query_skill_mapped("sword") == "snowsword")
          //      return notify_fail("用这门剑法，如何使用本门绝学!\n");


        if ( !wizardp(me) && me->query_skill_mapped("force") != "bitao-shengong")
                return notify_fail("不使用本门内功，如何使用本门绝学!\n");

//        if( !wizardp(me) && me->query_temp("weapon") )
//              return notify_fail("你必须空手才能使用本门绝学!\n");

        msg = HBWHT "$N贯通海南派武学，使出了海南派的绝学之精髓！\n" NOR;
message_vision(msg, me, target);               
victim=target;
if (me->query("hyvip")==4) 
	{me->add("neili",-500);}
	else
	{me->add("neili", -me->query("max_neili")/7);}
   

               
                
        sword_level=(int)(snowsword/50);




        
  //      if( time()-(int)me->query_temp("wuxue_end") < 3 )
  //              return notify_fail("绝招用多就不灵了！\n");
                
        if ( sword_level <= 1 ) desc_msg = "" ; 
        else desc_msg = chinese_number(sword_level);
        if ( sword_level > 9 ) desc_msg = "百";
   



        ini_damage_apply = me->query_temp("apply/damage");
        me->add_temp("apply/attack", 200);	
        me->add_temp("apply/damage", 2800);
        message_vision(HIW"\n$N轻叱一声，脚尖一点，身体急速上旋，在半空中一个折腰。
同时手腕轻抖，剑光闪动幻作漫天飞雪卷向$n。\n"NOR,me,target);
        target->start_busy(2);
        damage=1;
        //前三剑
        message_vision(HIC"\n$N同时使出风回雪舞剑的前三招，在半空中压向$n。\n"NOR,me,target);
        

        target->receive_damage("qi", (random(me->query_skill("bitao-shengong",1))+10),me);

        me->set_temp("WX_perform", 6);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        //再两剑
//        if( snowsword > 99 && f > 99 && bufa > 99 )
//           {
                message_vision(HIC"\n$N身体斜斜向上飘出，也不回头，反手就刺出了两招。\n"NOR,me);

             

                me->set_temp("WX_perform", 8);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
target->receive_damage("qi", (random(me->query_skill("bitao-shengong",1))+10),me);
//        }
      
        //最后三剑
//        if( snowsword > 149 && f > 149 && bufa > 149 )
//        {
                message_vision(HIC"\n$N斜斜一再个翻身，长剑幻作千百支冰箭，夹着一股寒风扑向$n。\n"NOR,me,target);
                    

                me->set_temp("WX_perform", 9);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
   
target->receive_damage("qi", (random(me->query_skill("bitao-shengong",1))+10),me);
                    
//        }
        me->add_temp("apply/attack", -200);	               
        me->delete_temp("WX_perform");
        me->add_temp("apply/damage",-2800);


damage=me->query_skill("snowsword", 1)+random(100);   
         //message_vision(HIY"\n$N忽然跳出战圈，向$n念道："NOR,me,target);
        message_vision(HIY"$N语音清脆，越念越是冲和安静，全身隐隐发出圣洁的光辉。"NOR,me,target);
            message_vision(HIC"\n身從無相中受生。猶如幻出諸形象。幻人心識本來無。罪福皆空無所住。"NOR,me,target);
 if(random(3)==0 || (random(me->query("combat_exp",1)) >= target->query("combat_exp")/3))
{            
                   
                message_vision(
                 "\n $n突然脸色苍白，似乎体力不支，竟呕出一口血来…",
                 me, target );

            target->receive_wound("qi",damage,me);
            target->receive_damage("qi",damage,me);
}
            message_vision(HIG"\n起諸善法本是幻，造諸惡業亦是幻。身如聚沫心如風，幻出無根無實性。"NOR,me,target);  
 if(random(3)==0 || (random(me->query("combat_exp",1)) >= target->query("combat_exp")/3))
{            

                message_vision(
                 "\n $n突然脸色苍白，似乎体力不支，竟呕出一口血来…",
                 me, target );
            damage=damage+100;
            target->receive_wound("qi",damage,me);
            target->receive_damage("qi",damage,me);
}
            message_vision(HIR"\n假借四大以為身，心本無生因境有，前境若無心亦無，罪福如幻起亦滅。"NOR,me,target);
 if(random(3)==0 || (random(me->query("combat_exp",1)) >= target->query("combat_exp")/3))
{         
                message_vision(
                 "\n $n突然脸色苍白，似乎体力不支，竟呕出一口血来…",
                 me, target );
damage=damage+100;
if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
            target->receive_wound("qi",damage,me);
            target->receive_damage("qi",damage,me);
}


            message_vision(HIW"\n見身無實是佛身，了心如幻是佛幻，了得身心本性空，斯人與佛何殊別。"NOR,me,target);
                         if(random(3)==0 || (random(me->query("combat_exp",1)) >= target->query("combat_exp")/3))
{           
                message_vision(
                 "\n $n突然脸色苍白，似乎体力不支，竟呕出一口血来…",
                 me, target );
damage=damage+100;
if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
            target->receive_wound("qi",damage,me);
            target->receive_damage("qi",damage,me);
}
            message_vision(RED"\n佛不見身知是佛，若實有知別無佛，智者能知罪性空，坦然不怖於生死。"NOR,me,target);

                        if(random(3)==0 || (random(me->query("combat_exp",1)) >= target->query("combat_exp")/3))
{          
                message_vision(
                 "\n $n突然脸色苍白，似乎体力不支，竟呕出一口血来…",
                 me, target );
damage=damage+100;
if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
            target->receive_wound("qi",damage,me);
            target->receive_damage("qi",damage,me);
}
            message_vision(GRN"\n一切众生性清淨，從本無生無可滅，即此身心是幻生，幻化之中無罪福。"NOR,me,target);
                      
if(random(3)==0 || (random(me->query("combat_exp",1)) >= target->query("combat_exp")/3))
{           
                message_vision(
                 "\n $n突然脸色苍白，似乎体力不支，竟呕出一口血来…",
                 me, target );
damage=damage+100;
if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
            target->receive_wound("qi",damage,me);
            target->receive_damage("qi",damage,me);
}



            message_vision(YEL"\n法本法無法，無法法亦法，今付無法時，法法何曾法。"NOR,me,target);
 if(random(3)==0 || (random(me->query("combat_exp",1)) >= target->query("combat_exp")/3))
{          
                 message_vision(
                 "\n $n突然脸色苍白，似乎体力不支，竟呕出一口血来…",
                 me, target );
damage=damage+100;

 	if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
            target->receive_wound("qi",damage,me);
            target->receive_damage("qi",damage,me);
}




            message_vision(HIB"\n諸行無常，是生滅法，生滅滅已，寂滅為樂。"NOR,me,target);
 if(random(3)==0 || (random(me->query("combat_exp",1)) >= target->query("combat_exp")/3))
{          
                message_vision(
                 "\n $n突然脸色苍白，似乎体力不支，竟呕出一口血来…",
                 me, target );
damage=damage+100;

 	if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
            target->receive_wound("qi",damage,me);
            target->receive_damage("qi",damage,me);
}



       message_vision(WHT"\n凡俗諸猛熾，何能致火爇，請尊三昧火，闍維金色身。"NOR,me,target);
 if(random(3)==0 || (random(me->query("combat_exp",1)) >= target->query("combat_exp")/3))
{          
                message_vision(
                 "\n $n突然脸色苍白，似乎体力不支，竟呕出一口血来…",
                 me, target );
damage=damage+100;

 	if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
            target->receive_wound("qi",damage,me);
            target->receive_damage("qi",damage,me);
}



            message_vision(BLU"\n菩提道上来，随缘现镜台。妙有续慧命，真空无尘埃。"NOR,me,target);
                        if(random(3)==0 || (random(me->query("combat_exp",1)) >= target->query("combat_exp")/3))
{          
                message_vision(
                 "\n $n突然脸色苍白，似乎体力不支，竟呕出一口血来…",
                 me, target );
damage=damage+100;


  	if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
            target->receive_wound("qi",damage,me);
            target->receive_damage("qi",damage,me);
}

 

         message_vision(HIY"\n$N双手合十，轻念佛偈：\n" NOR,me,target);
message_vision(HIC"“一切恩爱会，无常难得久。\n"NOR,me,target);
message_vision(HIC"  生世多畏惧，命危于晨露。\n"NOR,me,target);
message_vision(HIC"  由爱故生忧，由爱故生怖。\n"NOR,me,target);
message_vision(HIC"  若离于爱者，无忧亦无怖。”\n"NOR,me,target);
message_vision(HIB" $N叹道:是耶?非耶?化作蝴蝶......
忽然招式一变舞起一片剑花,似彩蝶翻飞般罩向$n\n"NOR,me,target);
   

                 
        ap = me->query_skill("snowsword", 1);
        ap = ap * ap * ap /10;
        ap = ap + (int)me->query("combat_exp");
        dp = target->query_skill("parry");
        dp = dp * dp * dp /20;   
        dp = dp + target->query("combat_exp");
        dp = dp*qi_pcg/50;  
 if(random(3)==0 || (random(me->query("combat_exp",1)) >= target->query("combat_exp")/3))
  {
target->receive_damage("qi", (me->query_skill("snowsword",1)*4),me);
target->receive_wound("qi", (me->query_skill("snowsword",1)*4),me);   

                   message_vision(HIM "$n躲闪不及,剑花中但见一只彩蝶穿身而过！\n"NOR, me, target);
                   COMBAT_D->report_status(target); 

         } else {
                            message_vision(HIW"$n一见情势不妙，一个鱼跃,跳出圈外。\n"NOR, me, target);

           }
        
      
        


            msg = HIW"$N银牙一咬，突然高高纵起，凝聚全身功力，人剑合一，"
                 +"化做一道白光，疾风般扑向$n！\n" NOR;
        ap = me->query_skill("snowsword", 1);
        ap = ap * ap * ap /10;
        ap = ap + (int)me->query("combat_exp");
        dp = target->query_skill("parry");
        dp = dp * dp * dp /10;   
        dp = dp + target->query("combat_exp");
        dp = dp*qi_pcg/50;  //more badly you're hurt, more chance you will succeed
 if(random(3)==0 || (random(me->query("combat_exp",1)) >= target->query("combat_exp")/3))
  {
target->receive_damage("qi", (me->query_skill("bitao-shengong",1)*4),me);
target->receive_wound("qi", (me->query_skill("bitao-shengong",1)*4),me);   
                msg += HIW "$n不料$N如此决绝，为此气势所慑，竟然楞在当地，忘了招架。
说时迟，那时快，这道白光已在$n身上当胸穿过！\n"NOR;
                message_vision(msg, me, target);



                COMBAT_D->report_status(target); 
         } 
         else {

                msg += HIW "$n一见情势不妙，连忙就地一滚，虽于千钧一发之际躲过雷霆一击，却也狼狈不堪，吓得魂飞魄散，一时间动弹不得。\n"NOR;
                message_vision(msg, me, target);

         }
    
    



me->start_busy(4);
        //me->set_temp("wuxue_end",time());
        return 1;
}
