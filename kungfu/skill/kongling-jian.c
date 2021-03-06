// kongling-jian.c
//  空灵剑法
inherit SKILL;

mapping *action = ({
        ([      "action":
        "$N使一招「仙人拱手」，手中$w幻一条疾光刺向$n的$l",
        "lian" :
        "$N使一招「仙人拱手」，手中$w幻一条疾光刺向左前方......",
                "jibie":7,
                "zhaoshi":"「仙人拱手」",
                "sen"  : 3,
                        "damage":330,
                        "dodge":                20  ,
                        "wound":                20   ,
                        "damage_type":  "刺伤"
        ]),
        ([      "action":
        "$N一招「日月辉煌」，纵身飘开数尺，手中$w斩向$n的$l",
                "lian":
        "$N一招「日月辉煌」，纵身飘开数尺，手中$w大开大阙，挥洒飘逸......",
                "jiebie":30,
                "zhaoshi":"「日月辉煌」",
                "sen" : 4,
                        "damage":230,
                        "dodge":                30,
                        "wound":                25 ,
                        "damage_type":  "割伤"
        ]),
        ([      "action":
        "$N手中$w中宫直进，一式「白蛇吐信」对准$n的肩井穴刺出一剑",
                "lian":
        "$N手中$w中宫直进，一式「白蛇吐信」对准左前方斜刺一剑......",
                "jibie":40,
                "limb":"肩头",
                "zhaoshi":"白蛇吐信",
                "sen": 4,
                        "dodge":30 ,
                "damage":230,
                "wound":30,
                        "damage_type":  "刺伤"
        ]),
        ([      "action":
        "$N的$w凭空一指，一招「金针指南」，$w跳动着刺向$n的颈部.......",
                "lian":
        "$N的$w凭空一指，一招「金针指南」，$w跳动着刺向上方.......",
                "jibie":62,
                "zhaoshi":"「金针指南」",
                "sen": 4,
                "limb":"颈部",
                        "damage":230,
                        "dodge":                20,
                        "wound":                40,
                        "damage_type":  "刺伤"
        ]),
    ([  "action":"$N左手捏了个剑诀，右手一招「二郎担山」，手中$w对准$n一点",
        "lian"  :"$N左手捏了个剑诀，右手一招「二郎担山」，手中$w轻轻一点。",
        "sen"   :4,
        "jibie" :20,
        "damage":230,
        "dodge" :20,
        "parry" :10,
        "zhaoshi":"「二郎担山」",
        "wound":25,
        "damage_type":"刺伤"    ]),
    ([  "action":"只见$N弓步上前，双手紧握$w，一招「凤凰展翼」，向$n的头部由下而上一撩",
        "lian"  :"$N一个弓步，使出一招「凤凰展翼」，手中$w往上一撩。",
        "sen"   :5,
        "damage":230,
        "jibie" :30,
        "dodge" :30,
        "zhaoshi":"「凤凰展翼」",
        "wound":40,
        "damage_type":"割伤"    ]),
    ([  "action":"$N手拿$w，一招「猛虎摆尾」，向$n的$l飞速一击",
        "lian"  :"$N手拿$w，一招「猛虎摆尾」，快速击出。",
        "sen"   :5,
        "jibie" :40,
        "damage":230,
        "dodge" :10,
        "parry" :10,
        "zhaoshi":"「猛虎摆尾」",
        "wound":30,
        "damage_type":"割伤"    ]),
    ([  "action":"$N一招「匪神之灵」，高举手中$w，向$n迎头一劈",
        "lian"  :"$N一招「匪神之灵」，手中$w凌空一劈。",
        "sen"   :3,
        "damage":230,
        "jibie" :5,
        "dodge" :20,
        "parry" :20,
        "zhaoshi":"「匪神之灵」",
        "wound":35,
        "damage_type":"割伤"    ]),
    ([  "action":"$N反手一招「匪机之微」，手中$w向$n的$l一抹",
        "lian"  :"$N手握$w，使出一招「匪机之微」向前顺势一抹。",
        "sen"   :5,
        "jibie" :10,
        "damage":230,
        "dodge" :30,
        "parry" :0,
        "zhaoshi":"「匪机之微」",
        "wound":50,
        "damage_type":"割伤" ]),
    ([  "action":"只见$N弓步上前，双手紧握$w，一招「乱山乔木」，向$n的头部由下而上一撩",
        "lian"  :"$N一个弓步，使出一招「乱山乔木」，手中$w往上一撩。",
        "sen"   :5,
        "damage":230,
        "jibie" :30,
        "dodge" :15,
        "parry" :20,
        "zhaoshi":"「乱山乔木」",
        "wound":50,
        "damage_type":"割伤"    ]),
    ([  "action":"$N手拿$w，一招「碧苔芳晖」，向$n的$l飞速一击",
        "lian"  :"$N手拿$w，一招「碧苔芳晖」，快速击出。",
        "sen"   :5,
        "damage":230,
        "jibie" :40,
        "dodge" :10,
        "parry" :15,
        "zhaoshi":"「碧苔芳晖」",
        "wound":60,
        "damage_type":"割伤"    ]),
        ([      "action":
"$N使出「清风与归」，$w连挥剑光霍霍斩向$n的$l",
                "lian" :
"$N使出「清风与归」，$w连挥，只见剑光霍霍，煞是惊人......",
                "zhaoshi":"「清风与归」",
                "jibie":20,
                "damage":230,
                "sen" :6,
                "dodge":                30,
                "wound":                60,
                "damage_type":  "割伤"
        ]),
        ([      "action":
"$N一招「诵之思之」，纵身飘开数尺，手中$w斩向$n的$l",
                "lian":
"$N一招「诵之思之」，纵身飘开数尺，手中$w大开大阙，挥洒飘逸......",
                "jiebie":30,
                "zhaoshi":"「诵之思之」",
                "sen" : 6,
                "damage":230,
                "dodge":                30,
                "wound":                50 ,
        "parry":        10,
                "damage_type":  "割伤"
        ]),
        ([      "action":
"$N纵身一跃，手中$w一招「终与俗违」，对准$n的气海斜斜刺出一剑",
                "lian" :
"$N纵身一跃，手中$w一招「终与俗违」，斜斜地向右下方刺去......",
                "jibie":50,
                "zhaoshi":"「终与俗违」",
                "sen"  :7,
                        "dodge":40,
                "limb":"小腹",
                "damage":230,
                "wound":40, 
                "damage":330,
                "damage_type":  "刺伤",
        ]),
});

string *parry_msg = ({
        "$n使出一招「如将白云」，手中的$v化做漫天雪影，封住了全身。。\n",
        "$n使出「反手」诀，身形拔起，$w反手刺出，登时瓦解了$N的攻势。。\n",
        "$n使出一招「脱帽看诗」，手中的$v飘忽不定，照出点点剑花，晃得$N睁不开眼睛。。\n",
        "$n手中的$v一抖，一招「但知旦暮」，向$N的左肩反削上去。\n",
});

string *unarmed_parry_msg = ({
        "$n使出一招「如将白云」，封住了$N的攻势。\n",
        "$n反手一招「脱帽看诗」，整个人化做一团幻影。\n",
        "$n使出一招「但知旦暮」，化掌为剑，拍向$N左肩。。\n",
        "$n双掌一挥，内力逼出，迫得$N连连后退。\n",
});




string query_parry_msg(object weapon)
{   
    if ( weapon )
        return parry_msg[random(sizeof(parry_msg))];
    else
        return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

int valid_enable(string usage)
{ return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
	if( me->query("max_neili") < 100 )
		return notify_fail("你的内力不够，无法修炼空灵剑法。\n");

	if( (int)me->query_skill("dahong-quan",1) < 200 )
		return notify_fail("你的大洪拳不够。\n");

	if( (int)me->query_skill("changquan",1) < 200 )
		return notify_fail("你的太祖长拳不够。\n");

	if( (int)me->query_skill("kongdong-xinfa",1) < 200 )
		return notify_fail("你的崆峒心法不够。\n");

	if( (int)me->query_skill("shizi-zhan",1) < 200 )
		return notify_fail("你的十字战不够。\n");

	if( (int)me->query_skill("luofeng",1) < 200 )
		return notify_fail("你的落风六式不够。\n");
						
	return 1;
}

mapping query_action(object me, object weapon)
{
	int i, level,n;

	level   = (int) me->query_skill("kongling-jian",1);

	n = sizeof(action);
	for(i=0;i<n;i++)
		if(level >= action[i]["lvl"])
			return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	object weapon;

	if(!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
	if( (int)me->query_skill("dahong-quan",1) < 200 )
		return notify_fail("你的大洪拳不够。\n");

	if( (int)me->query_skill("changquan",1) < 200 )
		return notify_fail("你的太祖长拳不够。\n");

	if( (int)me->query_skill("kongdong-xinfa",1) < 200 )
		return notify_fail("你的崆峒心法不够。\n");

	if( (int)me->query_skill("shizi-zhan",1) < 200 )
		return notify_fail("你的十字战不够。\n");

	if( (int)me->query_skill("luofeng",1) < 200 )
		return notify_fail("你的落风六式不够。\n");

	if((int)me->query("qi") < 50)
		return notify_fail("你的体力不够练空灵剑法。\n");
	me->receive_damage("qi", 30);
	return 1;
}

string perform_action_file(string func)
{
	return __DIR__"kongling-jian/"+func;
}

