//modify by Wuyou@Sanjie

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
 
int perform(object me, object target)
{
        object weapon, ob;
        string msg, string1;
        int count;
//object weapon;
        if( !target ) target = offensive_target(me);
        
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail(CYN"��Ҫ��˭ʩչ"HIW"���������֡�"CYN"��\n"NOR);
        
        if( !me->is_fighting(target) )
                return notify_fail(HIW"���������֡�"CYN"ֻ����ս��ʹ�á�\n"NOR);
                                  if( me->query_temp("yunlong_yushi"))
                return notify_fail(CYN"����δ�֣������ٴ��ظ�ʩչ"HIW"���������֡�"CYN"��\n");
if( !target ) target = offensive_target(me);
        
       
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ��\n");

        if( !wizardp(me) && me->query_temp("weapon") )
                return notify_fail("�������ֲ���ʹ�ñ��ž�ѧ!\n");

        if( objectp(me->query_temp("weapon")) )
return notify_fail("�������ֲ���ʹ�ñ��ž�ѧ!\n");
    if( (string)me->query_skill_mapped("force")!= "jinghai-force")
     return notify_fail("���뾸���񹦲��С�\n");

      if( (int)me->query_skill("jinghai-force", 1) < 60 )
                return notify_fail("��ľ����񹦻���Щ���\n");

        if( (int)me->query("neili") < 800 )
                return notify_fail(CYN"�������������\n");
                
        if( (int)me->query("qi") < 200 || (int)me->query("jing") < 200  )
                return notify_fail(CYN"������̫�����ˣ��޷�ʩչ"HIW"���������֡�"CYN"��\n"NOR);                
        
        if( (int)me->query_skill("dragonfight", 1) < 200 )
                return notify_fail(CYN"������β���������죬����ʹ��"HIW"���������֡�"CYN"��\n");
                                
                        

        msg = HIW "\n$NͻȻ��������������һ������������ʡ�$N�����м��ٴ���ʹ��"HIC"���β���"HIW"�ռ�����"HIR"�������֣�\n\n" NOR;
        message_vision(msg, me, target);
        target->start_busy(1);
        ob = me->select_opponent();
        me->delete_temp("yunlong");
        me->set_temp("yunlong",9);
        me->add("neili", -350);
        me->set_temp("yunlong_yushi",1);
        call_out("checking", 1, me, target);
        return 1;
}


void checking(object me, object target)
{
        string msg;
        int damage;
        damage = 10+(int)me->query_skill("dragonfight",1);
        
         if (me && !target) 
                {
                        tell_object(me, CYN"\n������û�к��˹��У������ջ����������ֵĹ��ơ�\n\n" NOR);
                        me->delete_temp("yunlong_yushi");
                        me->delete_temp("yunlong");
                        return;
                }
        
        if (!me || !target) return;
        if ( me->query_temp("yunlong")  ) 
        {

                if ( (int)me->query("neili") < 200  ) 
                {
                        tell_object(me, CYN"\n���������̲��㣬���ò�ֹͣ�������ֵĹ��ƣ�\n\n" NOR);
                        me->delete_temp("yunlong_yushi");
                        me->delete_temp("yunlong");
                        return;
                }
                else if ( me->query_skill_mapped("unarmed") != "dragonfight" ) 
                {
                        tell_object(me, WHT "\n�㲻��ʹ�����β������޷������������ֹ��У�\n\n" NOR);
                        me->delete_temp("yunlong_yushi");
                        me->delete_temp("yunlong");
                        return;
                }
                else if (!me->is_fighting() || !target) 
                {
                        tell_object(me, CYN"\n������û�к��˹��У������ջ����������ֵĹ��ơ�\n\n" NOR);
                        me->delete_temp("yunlong_yushi");
                        me->delete_temp("yunlong");
                        return;
                }
                else
                {
if (random(2)==0) target->start_busy(2);
me->add_temp("apply/attack", 180);
me->add_temp("apply/damage", 2200);
                        if ( me->query_temp("yunlong") ==9 )
                        {
                                msg = HIY "             ���P���Ա���\n\n" NOR;
                                msg += MAG "�����P������ʯ��������������\n" NOR;
                             	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
                        }
                        if ( me->query_temp("yunlong") ==8 )
                        {
                                msg = HIW "             ��������¡�\n\n" NOR;
                                msg += HIB "�����������ǧ��֮�⣬��Ȼ������\n" NOR;
                            	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
                        }
                        if ( me->query_temp("yunlong") ==7 )
                        {
                                msg = HIG "             �����������\n\n" NOR;
                                msg += HIC "�������ѳԾ�������ʳ�����������\n" NOR;
                              	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
                        }                       
                        if ( me->query_temp("yunlong") ==6 )
                        {
                                msg = HIR "             ������ŭɱ��\n\n" NOR;
                                msg += WHT "��������ɱ��������˫��Ѫ�ȣ��޷޶�����\n" NOR;
                               	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
                        }        
                        if ( me->query_temp("yunlong") ==5 )
                        {
                                msg = HIC "             �����������\n\n" NOR;
                                msg += CYN "���������Ӷ���𣬴���˽����Ȼ������\n" NOR;
                           	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
                        }  
                        if ( me->query_temp("yunlong") ==4 )
                        {
                                msg = HIR "             ������»��\n\n" NOR;
                                msg += HIM "���ӽ���Ⱥ��̻���Я��������\n" NOR;
                               	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
                        }  
                        if ( me->query_temp("yunlong") ==3 )
                        {
                                msg = WHT "             ��ſ��Ϸˮ��\n\n" NOR;
                                msg += HIY "����ſ�󷭽�����������ˮ�У�Я�������\n" NOR;
                               	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
                        }  
                        if ( me->query_temp("yunlong") ==2 )
                        {
                                msg = MAG "             ����ͼ��Ѩ��\n\n" NOR;
                                msg += HIW "���ӽ�ͼ���Ų�������ȥ�Ҵң�\n" NOR;
                               	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
                        }  
                        if ( me->query_temp("yunlong") ==1 )
                        {
                                msg = HIB "             �����γ�����\n\n" NOR;
                                msg += HIG "��������ͨ�����������߱߳���\n" NOR;
                             	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
                        }
me->add_temp("apply/attack", -180);
me->add_temp("apply/damage", -2200); 
                                                                                                                                                                        
                        me->add("neili", -20);
                        if( !target ) target = offensive_target(me);
        
                        if( !target
                        ||      !target->is_character()
                        ||      target->is_corpse()
                        ||      target==me)
                        {
                                me->delete_temp("yunlong_yushi");
                                me->delete_temp("yunlong");
                                return;
                        }
                                
                        if(random(me->query("combat_exp")) > target->query("combat_exp")/5)
                        {       
                                target->receive_damage("qi", damage*2,me);
                                target->receive_wound("qi", damage*2,me);
                                COMBAT_D->report_status(target, 0);     
                                COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
                        }
                        me->set_temp("yunlong", me->query_temp("yunlong")-1);
                        call_out("checking", 1, me, target);
                }
        }
        else 
        {
                message_vision(HIW "\n�ƿ���ɢ��$N��Ϊ���Σ���Ȼ������\n" NOR, me);
                me->delete_temp("yunlong");
                call_out("yunlong_end", 1, me);
        }
}  
void yunlong_end(object me, object target)
{

        
        me->delete_temp("yunlong_yushi");
        if ( me->query_temp("yunlong")  ) 
        {
                tell_object(me, HIR "\n�㰵�Ե�Ϣ������ƽ����ӿ��������\n\n" NOR);
        }
}
