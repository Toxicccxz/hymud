// regenerate.c

//inherit SSERVER;

int exert(object me, object target)
{
	int j,q,agea,inta,dexa;
	if (target != me) 
		return notify_fail("你只能用内功恢复自己的精力。\n");

	if( me->is_busy() )
		return notify_fail("你上一个动作还没有完成！\n");
	
	if ((int)me->query("neili") < 35)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("force",1) < 5)
		return notify_fail("你的基本内功不够。\n");

	j = (int)me->query("eff_jing") - (int)me->query("jing");
	if (j < 10)
		return notify_fail("你现在精气旺盛。\n");

	me->add("neili", -30);

q=20+(int)me->query_skill("force");

if (me->query("jing",1) <= me->query("max_jing",1) )
if (userp(me))q=q+me->query("per")*15;

		dexa=me->query("age",1);
		if (dexa >30) dexa=30;
if (userp(me)) q=q+me->query("int")*dexa;



if (me->query("zhuanshen"))
q=q*2;

if (me->query("zhuanbest"))
q=q*2;

if (me->query("4zhuan"))
q=q*2;


if (q>me->query("max_jing",1)) q=me->query("max_jing",1);

if (q>me->query("max_jing",1)) q=me->query("max_jing",1);


if ((int)me->query("eff_jing") <= (int)me->query("max_jing"))
{
	me->receive_heal("jing", q);
}
if ((int)me->query("jing") <= (int)me->query("eff_jing"))
{
	me->add("jing", q);	
}        message_combatd("$N深深吸了几口气，精神看起来好多了。\n", me);
//        me->start_busy(1);
me->set_temp("ishealnb",1);
        if( me->is_fighting() ) me->start_busy(2);
	
	return 1;
}

