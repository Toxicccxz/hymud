// lifeheal.c

#include <ansi.h>

int exert(object me, object target)
{
int lvl;
lvl=(int)me->query_skill("linji-zhuang",1);
        if ((!target))
                return notify_fail("��Ҫ������Ϊ˭ʹ�����˾���\n");

        if( (int)me->query_skill("linji-zhuang",1) < 300 )
                return notify_fail("��������书��Ϊ������\n");

        if( (int)me->query("max_neili") < 550 )
                return notify_fail("���������Ϊ������\n");

        if( (int)me->query("neili") < 550)
                return notify_fail("�������������\n");

        if( !wizardp(me) && userp(me) && me->query("family/family_name") != "������")
                return notify_fail("�˾���ֻ�ж���������������Ĳ���ʹ�á�\n");

//        if(userp(me) && !wizardp(me) && me==target)
//                return notify_fail("���ܶ��Լ�ʹ�á�\n");

        if(userp(me) && !wizardp(me) && !userp(target))
                return notify_fail("���ܶԷ����ʹ�á�\n");

        if( target->query_condition("qihuifu"))
                return notify_fail("�Է����ڱ����˾��ظ���\n");

        if( me->query_condition("gong_busy"))
                return notify_fail("��Ŷ���ʹ�ù����˾� ���������û�лָ���\n");

        if( (int)target->query("qi") >= (int)target->query("max_qi") )
                return notify_fail( target->name() +
                        "û�����ˣ�����Ҫ�����ˣ�\n");

        message_combatd(
                HIG "$N�����ټ�ʮ��ׯ������������$n���ģ�һ˲�� ��ʮ������������$n����....\n"
                "�����ӷ����գ����գ� $N��ͷ��ð������ĺ��飬$n�³�һ����Ѫ����ɫ������������ˡ�\n" NOR,
                me, target );

    target->receive_curing("qi", 500 + (int)me->query_skill("force")/2 );
    target->add("qi", 500 + (int)me->query_skill("force")/2 );
    target->receive_curing("jing", 500 + (int)me->query_skill("force")/2 );
    target->add("jing", 500 + (int)me->query_skill("force")/2 );
    target->set_temp("huifusl",(lvl+100));   
   lvl=lvl/50;
   if (lvl>10) lvl=10;
    target->apply_condition("qihuifu",lvl);    
    me->apply_condition("gong_busy",3);
if (target==me) me->apply_condition("gong_busy",7);
    if( (int)target->query("qi") > (int)target->query("eff_qi") ) target->set("qi", (int)target->query("eff_qi"));
    if( userp(target) && (int)target->query("jing") > (int)target->query("eff_jing") ) target->set("jing", (int)target->query("eff_jing"));
    if( !userp(target) && (int)target->query("qi") > (int)target->query("max_qi") ) target->set("qi", (int)target->query("max_qi"));


me->add("neili", -250);
me->start_busy(2);
    return 1;
}
