#include <ansi.h>

int update_condition(object me, int duration)
{
   int damage,damage2;
damage=me->query("qi")/8;
damage2=me->query("jing")/8;
if (damage > 7000) damage=7000;   
if (damage2 > 7000) damage2=7000;   	
	

    me->receive_damage("jing", damage2);
    me->receive_wound("jing", damage2);

      me->start_busy(random(3)+1);

    me->receive_damage("qi", damage);
    me->receive_wound("qi", damage);
	
me->start_busy(4);
        me->apply_condition("qx_snake_poison", duration - 1);
if (me)
{
        message_vision(BLU"$N�����巢������ɫ�����⣬����������ʹ����,Ť��ɹ�������.\n"NOR, me);
        tell_object(me, HIR "���е������߶������ˣ�\n" NOR );
}
        if( duration < 1 ) return 0;
        return 1;
}

