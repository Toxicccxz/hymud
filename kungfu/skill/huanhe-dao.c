//huanhe-dao.c.煊赫刀
//date:1997.9.11
//by dan
#include <ansi.h>     
inherit SKILL;

mapping * action=({
    ([  "action":
"$N冲天而起，一招「吴钩霜雪明」，$w带着凌厉的风声斩向$n的头部",
        "lian"  :
"$N冲天而起，一招「吴钩霜雪明」，$w带着凌厉的风声在空中飞舞。",
        "sen"   :8,
        "jibie" :5,
        "dodge" :20,
        "parry" :20,
        "damage" :330,
        "zhaoshi" : "「吴钩霜雪明」",
        "damage_type":"割伤"
        ]),
 ([  "action":
"$N暴喝一声，使出一招「将炙啖朱亥」，以刀当剑，$w闪电般刺向$n的胸。",
        "lian"  :
"$N暴喝一声，使出一招「将炙啖朱亥」，以刀当剑，$w闪电般刺出。",
        "sen"   :9,
        "jibie" :3,
        "dodge" :25,
        "parry" :15,
        "damage" :330,
        "zhaoshi" : "「将炙啖朱亥」",
        "damage_type":"割伤"
        ]),  
 ([     "action":
"$N使出一招「三杯吐然诺」，身形如醉酒一般，手中$w杂乱无章地向$n劈去。",
        "lian"  :
"$N使出一招「三杯吐然诺」，身形如醉酒一般，手中$w更是杂乱无章。",
        "sen"   :10,
        "jibie" :40,
        "dodge" :30,
        "parry" :0,
        "damage" :340,
        "zhaoshi" : "「三杯吐然诺」",
        "damage_type":"割伤"
        ]),
  ([    "action":
"$N不守反攻，一式「救赵挥金锤」手中$w如同开山巨斧一般向$n的$l砍去。",
        "lian"  :
"$N不守反攻，一式「救赵挥金锤」手中$w如同开山巨斧一般霍霍生风。",
        "sen"   :11,
        "jibie" :60,
        "dodge" :0,
        "parry" :30,
        "damage" :250,
        "zhaoshi" : "「救赵挥金锤」",
        "damage_type":"割伤"
        ]),
   ([  "action":
"$N藏刀内收，刀光如轮疾转，一招「不惭世上英」，$w卷向$n的$l。",
        "lian"  :
"$N藏刀内收，刀光如轮疾转，正是一招「不惭世上英」。",
        "sen"   :12,
        "jibie" :80,
        "dodge" :10,
        "parry" :30,
        "damage" :250,
        "zhaoshi" : "「不惭世上英」",
        "damage_type":"割伤"
        ]),
    ([  "action":
"$N突然扑到$n的面前，一招「谁能书阁下」，$w无声无息地劈向$n",
        "lian"  :
"$N突然向前一扑，一招「谁能书阁下」，$w无声无息地劈出。",
        "sen"   :12,
        "jibie" :100,
        "dodge" :30,
        "parry" :30,
        "damage" :360,
        "zhaoshi" : "「谁能书�  笙隆�",
        "damage_type":"割伤"
        ]),
});
string *parry_msg = ({
    "$n一抖$v，一招「将炙啖朱亥」，手中的$v化作一条长虹，磕开了$P的$w。\n",
    "$n一招「三杯吐然诺」将手中的$v舞得密不透风，封住了$N的攻势。\n",
    "$p使出一招「救赵挥金锤」，手中的$v化做漫天雪影，荡开了$N的$w。\n",
    "$n反手一招「不惭世上英」，整个人消失在一团光芒之中。\n",
    "$p使出一招「吴钩霜雪明」，$w直刺$N的双手。\n",
    "$p前跨一步，一招「谁能书阁下」，$w劈向$N的胸口。\n",
});

string *unarmed_parry_msg = ({
    "$n双拳齐出，一招「救赵挥金锤」，猛击$N的面门，逼得$N中途撤回$w。\n",
    "$n脚走阴阳，一招「将炙啖朱亥」，攻$N之必救。\n",
    "$n双手舞得密不透风，使出「三杯吐然诺」，封住了$N的攻势。\n",
    "$n身行飘忽，使出「不惭世上英」，避开了$N的这一招。\n",
    "但见$n一招「吴钩霜雪明」，迫得$N连连后退。\n",
    "$n使出一招「谁能书阁下」，缓缓推向$N的$l。\n",
});
     


string query_parry_msg(object weapon)
{   
    if ( objectp( weapon ) )
        return parry_msg[random(sizeof(parry_msg))];
    else
        return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}
mapping query_action(object me, object weapon)
{
    return action[random(sizeof(action))];
}

int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力不够。\n");

        if ((int)me->query_skill("taixuan-gong", 1) < 100)
                return notify_fail("你的太玄神功火候太浅。\n");
 	if(me->query_skill("xiuli-qiankun", 1) < 250)
		return notify_fail("你的袖里乾坤修为不够，无法修炼。\n");
        if ((int)me->query_skill("literate", 1)> 5 )
                return notify_fail("你觉得煊赫刀深奥之极，一时间难以领会。\n");

	if(me->query_skill("wuyu-quan", 1) < 250)
		return notify_fail("你的五狱拳修为不够，无法修炼。\n");

	if(me->query_skill("sata-shenfa", 1) < 250)
		return notify_fail("你的飒沓身法修为不够，无法修炼。\n");

		
if (me->query_skill("huanhe-dao", 1) > 251)
{
			if(me->query_skill("sumi-jian", 1) < me->query_skill("huanhe-dao", 1))
		return notify_fail("你的素霓剑法修为不够，无法修炼。\n");
}		
        return 1;
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query("qi") < 50)
                return notify_fail("你的体力不够无法练习。\n");
	       if ((int)me->query_skill("taixuan-gong", 1) < 100)
                return notify_fail("你的太玄神功火候太浅。\n");
 	if(me->query_skill("xiuli-qiankun", 1) < 250)
		return notify_fail("你的袖里乾坤修为不够，无法修炼。\n");

	if(me->query_skill("wuyu-quan", 1) < 250)
		return notify_fail("你的五狱拳修为不够，无法修炼。\n");

	if(me->query_skill("sata-shenfa", 1) < 250)
		return notify_fail("你的飒沓身法修为不够，无法修炼。\n");

		
if (me->query_skill("huanhe-dao", 1) > 251)
{
			if(me->query_skill("sumi-jian", 1) < me->query_skill("huanhe-dao", 1))
		return notify_fail("你的素霓剑法修为不够，无法修炼。\n");
}		
        if ((int)me->query_skill("literate", 1)> 5 )
                return notify_fail("你觉得煊赫刀深奥之极，一时间难以领会。\n");

	
        me->receive_damage("qi", 25);
        return 1;
}

string perform_action_file(string func)
{
	return __DIR__"huanhe-dao/"+func;
}



mixed hit_ob(object me, object victim, int damage_bonus, int factor, string limb)
{       
int level, jiali, time,level2;
int i, ap, dpp, dpd, dpf,lvl;
	object weapon,weapon2;
	string type, msg;
	weapon = me->query_temp("weapon");
lvl = me->query_skill("taixuan-gong", 1);
        if (random(me->query_skill("taixuan-gong",1)) < 60 ||		             me->query_skill("force",1) < 100 )
        return 0;


if (me->query_skill_mapped("force") != "taixuan-gong")
return 0;
if (me->query("neili") < 500)
return 0;
if (me->query_skill_mapped("unarmed") != "taixuan-gong")
return 0;

        if ((int)me->query_skill("literate", 1)> 5 )	
return 0;
	jiali = me->query("jiali");

if (!jiali) jiali=90;
	if( damage_bonus > 20 && random(me->query_skill("taixuan-gong",1))>120 
	) {
	victim->receive_wound("qi", (random(jiali)+80));
return random(2) ? HIW "$N" HIW "一招攻出，竟卷起千层气浪，太玄内劲"
                                   "顿时源源不绝涌入$n" HIW "体内！\n" NOR:
                                   HIW "$N" HIW "太玄内劲迸发，$n" HIW "只感全身一"
                                   "震，登时“喀喀喀”断了数根肋骨！\n" NOR;
}
}