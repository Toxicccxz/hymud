
#include <ansi.h>

#include <combat.h>

inherit F_SSERVER;


int perform(object me, object target)
{

        object weapon;
        int attackp, defendp,damage;
        string msg,str;
        if(!me->query_skill("daya-sword", 1)) return 0;

        if(me->query_temp("pfm-sha-time")+10>time())
        return notify_fail("������ˡ��ռ�ɱ�����������������á��ռ�ɱ����������\n");
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");

   if ( (int)me->query_skill("daya-sword", 1) < 380 && userp(me) ) return notify_fail("��Ĵ��Ž������������죡\n"); 
   	
        if(((int)me->query_skill("sword", 1) < 350) )
                return notify_fail("��Ľ����������򻹲�����죬�������á��ռ�ɱ����������\n");


    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
        return notify_fail(RED"��ʲô��Ц���������ԣ�\n"NOR);

        if ( !wizardp(me) && me->query_skill_mapped("force") != "wuzheng-xinfa")
                return notify_fail("��ʹ�������ķ�!\n");
        if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("���ž�ѧֻ�ܶ�ս���еĶ���ʹ�á�\n");
		

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("�ռ�ɱ��������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if( (int)me->query("max_neili") < 2500 )
                return notify_fail("���������Ϊ̫��������ʹ�������ռ�ɱ������������\n");
        if( (int)me->query("neili") < 2000 )
                return notify_fail("�������������\n");
       if(me->query_temp("daya-sha")) return notify_fail("���Ѿ��������ռ�ɱ������������ɱ���ˣ�\n");

   message_vision( HIR "$NͻȻ�����ü���ֲ�������һ��,ȫ����Ϊһ����ɫ����ֱ��$n��\n" NOR,
                me, target );

        attackp = me->query_skill("sword", 1) + me->query_skill("daya-sword", 1) + me->query_skill("force", 1) / 2;
        defendp = target->query_skill("force",1) + target->query_skill("parry",1);

        me->set_temp("daya-sha", 1);

        if( attackp / 2 + random(attackp) > defendp/10 || !living(target)  || random(3)==0)
        {
                  message_vision(HIY "$p��������������ܣ��͵�һ�����������Զ�ܡ���\n" NOR, me, target );
                tell_object(me, HIB "������ȫ����������������" + target->name() + "!\n" NOR);
                  message_vision(HIY "$p��ʱȫ������������,̱���ڵ�!����\n" NOR, me, target );
                tell_object(target, HIB "���ʱ����һ�ţ���Ѫ���ڣ����˲���!������\n"    NOR);

               

                target->add("neili", -1*((int)me->query_skill("unarmed", 1) + target->query("force_factor")) );
                if ( target->query("neili") <1 ) target->set("neili",target->qurey("max_neili")/10);


                damage=(int)me->query_skill("sword", 1)*2 - (int)target->query("talk",1);
                damage=damage+me->query_str()+random(me->query_temp("apply/damage"))+me->query_temp("apply/damage");
                if (damage <100) damage=80;
                target->receive_damage("qi", damage,me);
                target->receive_wound("qi", damage,me);
                me->set_temp("pfm-sfa-time",time());
        if ((target->query("eff_qi")< 0 || !living(target)) && userp(target))
        {
            str=target->name()+"��"+me->name()+"��"+HIW"�ռ�ɱ����һ��"+HIM"ɱ���ˡ�";
             message("channel:rumor",HIG"��"+HIR"��Ѫ����"HIG"��"+HIM"ĳ�ˣ�"+str+"\n"NOR,users());
       }
                target->start_busy(3 + random(2));
                me->add("neili", -100);
                 call_out("perform3", 1, me, target);

                call_out("del_sucked", 15, me);
        }
        else
        {
                message_vision(HIY "����$p������$P����ͼ��Ѹ�ٵرܿ����ռ�ɱ��������\n" NOR, me, target);

                call_out("del_sucked", 25, me);

        }

       me->set_temp("targett",target);
       return 1;
}

void del_sucked(object me)
{

        if ( me->query_temp("daya-sha"))
        me->delete_temp("daya-sha");

}

int perform3(object me, object target)
{

        object weapon;

        int damage;
        string msg,str;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
           return notify_fail("��΢΢��һЦ,�����ջؽ�������Ȼ����!!\n");

        msg = CYN "$N������Ȼ�����콣�������������������$n��\n"NOR;
       

        if (random(me->query_skill("daya-sword")) > target->query_skill("force")/2 || random(3)==0)
        {
                target->start_busy( (int)me->query_skill("daya-sword",1) / 200 + 1);

                damage = (int)me->query_skill("force", 1);
                damage = damage +  (int)me->query_skill("sword", 1);
                damage = damage +  (int)me->query_skill("daya-sword", 1);

                target->receive_damage("qi", damage,me);
                target->receive_wound("qi", damage/2,me);
                target->start_busy(3 + random(2));
                 if ((target->query("eff_qi")< 0 || !living(target)) && userp(target))
        {
            str=target->name()+"��"+me->name()+"��"+HIW"�ռ�ɱ���ڶ���"+HIM"ɱ���ˡ�";
             message("channel:rumor",HIG"��"+HIR"��Ѫ����"HIG"��"+HIM"ĳ�ˣ�"+str+"\n"NOR,users());
       }
              if( (int)me->query("neili") < damage/2 )
                //me->set("neili", 0);
                me->add("neili", -100);
                msg += HIR"ֻ��$N������Ϊһ�ߣ�����$n,\n$nֻ��һ���������Ķ�������ͷһ����Ѫ���������\n"NOR;
        } else
        {
                msg += CYN"����$p�͵���ǰһԾ,������$P�Ľ�����Χ��\n"NOR;
                me->add("neili", -100);
                me->start_busy(2);
        }
        message_vision(msg, me, target);
        call_out("perform4", 1, me, target);

        return 1;
}

int perform4(object me, object target)
{

        object weapon;

        int damage;
        string msg,str;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
           return notify_fail("��΢΢��һЦ,�����ջؽ�������Ȼ����!!\n");

        msg = CYN "$N����ͻ�䣬������������������-ɱ������ֱ����$n��\n"NOR;


        if (random(me->query_skill("daya-sword")) > target->query_skill("force")/2  || random(3)==0)
        {
                target->start_busy( (int)me->query_skill("daya-sword",1) / 200 + 1);

                damage = (int)me->query_skill("force", 1);
                damage = damage +  (int)me->query_skill("sword", 1);
                damage = damage +  (int)me->query_skill("daya-sword", 1);

                target->receive_damage("qi", damage*2,me);
                target->receive_wound("qi", damage,me);
                 if ((target->query("eff_qi")< 0 || !living(target)) && userp(target))
        {
            str=target->name()+"��"+me->name()+"��"+HIW"�ռ�ɱ��������-ɱ����"+HIM"ɱ���ˡ�";
             message("channel:rumor",HIG"��"+HIR"��Ѫ����"HIG"��"+HIM"ĳ�ˣ�"+str+"\n"NOR,users());
       }
              if( (int)me->query("neili") < damage/2 )
               // me->set("neili", 0);
                me->add("neili", -100);
                msg += HIR"ֻ��$N������Ϊһ��Ѫ��ɱ�⣬����$n,\n$nֻ��һ���������Ķ�������ͷһ����Ѫ���������\n"NOR;
        } else
        {
                msg += CYN"����$p�͵���ǰһ��һ��,������$P�Ľ�����Χ��\n"NOR;
                me->add("force", -100);
                me->start_busy(5);
        }
        message_vision(msg, me, target);
        call_out("perform5", 1, me, target);

        return 1;
}

int perform5(object me, object target)
{

        object weapon;

        int damage;
//
        string msg,str;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
           return notify_fail("��΢΢��һЦ,�����ջؽ�������Ȼ����!!\n");
        msg = CYN "$N����ͻ�䣬�������������Ľ���-��������ֱ����$n��\n"NOR;

        if (random(me->query_skill("daya-sword")) > target->query_skill("force")/2  || random(3)==0)
        {
                target->start_busy( (int)me->query_skill("daya-sword",1) / 200 + 1);

                damage = (int)me->query_skill("force", 1);
                damage = damage +  (int)me->query_skill("sword", 1);
                damage = damage +  (int)me->query_skill("daya-sword", 1);

                target->receive_damage("qi", damage*4,me);
                target->receive_wound("qi", damage*2,me);
                 if ((target->query("eff_qi")< 0 || !living(target)) && userp(target))
        {
            str=target->name()+"��"+me->name()+"��"+HIW"�ռ�ɱ��������-������"+HIM"ɱ���ˡ�";
             message("channel:rumor",HIG"��"+HIR"��Ѫ����"HIG"��"+HIM"ĳ�ˣ�"+str+"\n"NOR,users());
       }
              if( (int)me->query("neili") < damage/2 )
                //me->set("neili", 0);
                me->add("neili", -100);
                msg += HIR"ֻ��$N������Ϊʮ��Ѫ��ɱ�⣬����$n,\n$nֻ��һ���������Ķ�������ͷһ�𣬵�����Ѫ������������ˣ�\n"NOR;
        } else
        {
                msg += CYN"����$p�͵��ٴ���ǰһ��һ��,������$P�Ľ�����Χ��\n"NOR;
                me->add("neili", -100);
                me->start_busy(2);
        }
        message_vision(msg, me, target);
        return 1;
}

