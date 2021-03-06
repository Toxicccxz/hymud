// panheng-zhang.c 磐恒掌
// Ffox 98-1-17 5:32

inherit SKILL;
mapping *action = ({
    ([   "action"  :"$N两手往外同时一拒，使出一招「硕果不食」，将$n拍开。",
         "lian"    :"$N两手往外同时一拒，使出一招「硕果不食」，向空气里拍去。",
         "zhaoshi" : "「硕果不食」",
         "sen"   : 5,
         "parry" : 15,
         "dodge" : 15,
         "jibie" : 0,
         "wound" : 10,    
         "damage": 225,
         "damage_type":  "瘀伤"
    ]),
    ([   "action"  :"$N将全身的气力运至左臂，使出一招「密云不雨」，向$n迎头砸下。",
         "lian"    :"$N将全身的气力运至左臂，使出一招「密云不雨」，用力砸下。",
         "zhaoshi" : "「密云不雨」",
         "damage" : 240,
         "wound"  : 15, 
         "sen"    : 10,
         "parry"  : 30,
         "dodge"  : 30,
         "jibie"  : 20,   
         "damage_type":  "瘀伤"
    ]),
    ([   "action"  :"$N仰头吸了一口气，使出一招「日中见斗」，陡然排出三掌，打得$n一个趔趄。",
         "lian"    :"$N仰头吸了一口气，使出一招「日中见斗」，陡然排出三掌，打在空气里。",
         "zhaoshi" : "「日中见斗」",
         "sen"   : 20,
         "jibie" : 40,
         "parry" : 45,
         "dodge" : 45,
         "damage": 255,
         "damage_type":  "瘀伤"
    ]),
    ([   "action": "$N使出一招「日中见沫」，左手拍向又掌，牵动全身，向$n飞身扑击。",
         "lian"  :"$N使出一招「日中见沫」，左手拍向又掌，牵动全身，向前飞身扑击。",
         "zhaoshi" : "「日中见沫」",
         "damage": 270,
         "wound" : 15, 
         "sen"   : 25,
         "parry" : 60,
         "dodge" : 60,
         "jibie" : 60,
         "damage_type":  "瘀伤"
    ]),
    ([   "action": "$N摆了一个错综八字步，两手轻挥，使出一招「明夷于飞」，一股掌气向$n扑去。",
         "lian"  : "$N摆了一个错综八字步，两手轻挥，使出一招「明夷于飞」，一股掌气向空气中漫开。",
         "zhaoshi" : "「明夷于飞」",
         "sen"  : 30,
         "jibie": 80,
         "parry" : 75,
         "dodge" : 75,
         "damage": 285,
         "damage_type":  "瘀伤"
    ]),
    ([   "action":"$N使出一招「枯木生华」，双掌错开，右掌拍出，左掌横切，将$n逼退三尺。",
         "lian" :"$N使出一招「枯木生华」，双掌错开，右掌拍出，左掌横切，往空中击去。",
         "zhaoshi" : "「枯木生华」",
         "sen"   : 35,
         "jibie" : 100,
         "damage": 300,
         "wound" : 20, 
         "parry" : 90,
         "dodge" : 90,
         "damage_type":  "瘀伤"
    ]),   
    ([   "action":"$N双掌向前平推，使出一招「不事王候」，层层热浪涌起，将$n打得飞出两丈开外。",
         "lian" :"$N双掌向前平推，使出一招「不事王候」，层层热浪涌起。",
         "zhaoshi" : "「不事王候」",
         "sen"   : 24,
         "jibie" : 120,
         "damage": 380,
         "wound" : 20, 
         "parry" : 70,
         "dodge" : 70,
         "damage_type":  "瘀伤"
    ]),   

});

string * parry_msg = ({
    "$n一招「玉柱擎天」，挥掌将$N拍开。\n",
    "$n双掌上托，使出一招「天王托塔」，迎头档住$N的这一招。"
    "$n双掌上扬，滴溜溜一个转身，轻松躲过。",
});
 
  
string query_parry_msg(object weapon)
{
    return parry_msg[random(sizeof(parry_msg))];
}

int valid_learn(object me)
{

	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("练这门武功必须空手。\n");
	return 1;
}

int valid_enable(string usage)
{
	return usage=="unarmed" || usage=="parry" || usage=="strike";
}
int valid_combine(string combo) { return combo=="lingxiao-shou"; }

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("jing") < 30)
		return notify_fail("你的精神无法集中了，休息一下再练吧。\n");
	if( (int)me->query("qi") < 30 )
		return notify_fail("你现在手足酸软，休息一下再练吧。\n");
	if( (int)me->query("neili") < 10 )
		return notify_fail("你的内力不够了。\n");

	me->receive_damage("qi", 30);
	me->add("neili", -10);

	return 1;
}

string perform_action_file(string func)
{
	return __DIR__"panheng-zhang/"+func;
}


