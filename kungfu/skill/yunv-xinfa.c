// yunv-xinfa.c 玉女心法
#include <ansi.h>
inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{

        if ( me->query("gender") == "无性")
                return notify_fail("你无根无性，阴阳难调，不能修习玉女心法。\n");

        if ((int)me->query_skill("force", 1) < 10)
                return notify_fail("你的基本内功火候还不够。\n");

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
		return notify_fail("你不先散了别派内功，怎能学玉女心经？！\n");
        return 1;
}

int practice_skill(object me)
{
        return notify_fail("玉女心法只能用学(learn)来增加熟练度。\n");
}

mapping exercise_msg(object me)
{
  return ([
    "status_msg" : HIC + me->name()+"姿态悠雅，神态清冷。" NOR,
    "start_my_msg" : "你轻轻的吸一口气，闭上眼睛，运起玉女心经，内息在脉络中开始运转。\n",
    "start_other_msg" : me->name()+"神态突然开始变的清冷无比，可是姿势又变的悠雅异常。\n",
    "halt_msg" : "$N内息一转，迅速收气，停止了内息的运转。\n",
    "end_my_msg" : "你慢慢收气，归入丹田，睁开眼睛，轻轻的吐了一口气。\n",
    "end_other_msg" : "只见"+me->name()+"睁开眼睛，轻轻的吐出了一口气，神态恢复自然。\n"
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
msg = HIC"$N"+HIC+"满场游走，招断意连，绵绵不绝，一招未毕，二招至 !$n双眼一花不知所措！\n" +NOR;
victim->receive_damage("qi", damage2);
victim->receive_wound("qi", damage2/2);
if (random(2)==0)
{
msg += HIY"$N"+HIY+"目光一闪，一把玉锋针扔出 !$n 一不当心，身上连中了几枚！\n" +NOR;	
victim->apply_condition("yf_poison",20);
}
  if (!victim->is_busy()) victim->start_busy(2);  
}

	return msg;

}