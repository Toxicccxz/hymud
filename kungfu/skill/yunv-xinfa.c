// yunv-xinfa.c ��Ů�ķ�
#include <ansi.h>
inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{

        if ( me->query("gender") == "����")
                return notify_fail("���޸����ԣ������ѵ���������ϰ��Ů�ķ���\n");

        if ((int)me->query_skill("force", 1) < 10)
                return notify_fail("��Ļ����ڹ���򻹲�����\n");

	if (
	me->query_skill("bahuang-gong",1)
	|| me->query_skill("beiming-shengong",1)
	|| me->query_skill("bibo-shengong",1)
	|| me->query_skill("hamagong",1)
	|| me->query_skill("huagong-dafa",1)
	|| me->query_skill("huntian-qigong",1)
	|| me->query_skill("hunyuan-yiqi",1)
	|| me->query_skill("jiuyang-shengong",1)
	|| me->query_skill("kuihua-xinfa",1)
	|| me->query_skill("kurong-changong",1)
	|| me->query_skill("linji-zhuang",1)
	|| me->query_skill("longxiang",1)
 	|| me->query_skill("shenlong-xinfa",1)
	|| me->query_skill("taiji-shengong",1)
	|| me->query_skill("xiantian-qigong",1)
	|| me->query_skill("xiaowuxiang",1)
	|| me->query_skill("yijinjing",1)
	|| 	me->query_skill("yunlong-shengong",1)   ||
me->query_skill("shenghuo-shengong",1)    ||
me->query_skill("shenyuan-gong",1)   ||
me->query_skill("huashan-neigong",1)   ||
me->query_skill("zixia-shengong",1) ||
me->query_skill("xuantian-wuji",1)  ||
me->query_skill("bingxue-xinfa",1)||
me->query_skill("wudu-shengong",1)||
me->query_skill("guiyuan-tunafa",1) )
		return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ��Ů�ľ�����\n");
        return 1;
}

int practice_skill(object me)
{
        return notify_fail("��Ů�ķ�ֻ����ѧ(learn)�����������ȡ�\n");
}

mapping exercise_msg(object me)
{
  return ([
    "status_msg" : HIC + me->name()+"��̬���ţ���̬���䡣" NOR,
    "start_my_msg" : "���������һ�����������۾���������Ů�ľ�����Ϣ�������п�ʼ��ת��\n",
    "start_other_msg" : me->name()+"��̬ͻȻ��ʼ��������ޱȣ����������ֱ�������쳣��\n",
    "halt_msg" : "$N��Ϣһת��Ѹ��������ֹͣ����Ϣ����ת��\n",
    "end_my_msg" : "���������������뵤������۾������������һ������\n",
    "end_other_msg" : "ֻ��"+me->name()+"�����۾���������³���һ��������̬�ָ���Ȼ��\n"
          ]);
}
string exert_function_file(string func)
{
        return __DIR__"yunv-xinfa/" + func;
}


mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
object wp1,weapon;
        string msg;
        int p,j,skill, neili, neili1;
        int level,level2,damage2;
        level = (int) me->query_skill("unarmed",1);
        level2= (int) me->query_skill("yunv-xinfa",1);
        skill = me->query_skill("yunv-xinfa", 1);
        neili = me->query("neili");
        neili1 = victim->query("neili");
if ( level2<= 0) level2= (int) me->query_skill("yunv-xinfa",1);
damage2= (int) victim->query("neili",1)/10;
if (random(8)==0 && level2>=200 && (me->query_skill_mapped("force") == "yunv-xinfa"))
{

if (damage2> 5000)	damage2=5000;
msg = HIC"$N"+HIC+"�������ߣ��ж����������಻����һ��δ�ϣ������� !$n˫��һ����֪���룡\n" +NOR;
victim->receive_damage("qi", damage2);
victim->receive_wound("qi", damage2/2);
if (random(2)==0)
{
msg += HIY"$N"+HIY+"Ŀ��һ����һ��������ӳ� !$n һ�����ģ����������˼�ö��\n" +NOR;	
victim->apply_condition("yf_poison",20);
}
  if (!victim->is_busy()) victim->start_busy(2);  
}

	return msg;

}