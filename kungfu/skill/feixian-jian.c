inherit SKILL;
mapping *action = ({
    ([
      "action":
"$N手腕一抖，$w剑尖化为五道白光，分别向$n的咽喉、左右肩、和左右脚腕疾刺",
	"damage":	150,
      "damage_type":	"刺伤",
      ]),
    ([
      "action":
"$N脚下步步生莲，手中$w在身前一划,一片扇形白光向$n扑去。\n"
"$n识得这招「轻罗小扇」的威力，连忙躲避不迭",
	"damage":	280,
      "damage_type":	"割伤",
      ]),
    ([
      "action":
"$N纵身跃起，手中$w带起万道银光，向$n的面门点去。\n"
"这招「乱洒星罗」果然把$n逼得手忙脚乱",
	"damage":	210,
      "damage_type":	"刺伤",
      ]),
	
    ([
      "action":
"$N身如被狂风所吹,裙裾飘飘，手中$w向$n轻点数下！\n"
"这招「姑射仙人」玄妙非常，大有仙气,$n简直惊呆了",
	"damage":	340,
      "damage_type":	"刺伤",
      ]),
    ([
      "action":
"$N长袖飘舞,身形急转,转眼间就成了一片白雾。一道剑光从白雾中击向$n!\n"
"这招「月下轻舞」先保己,后伤敌,已立于不败之地",
	"damage":	270,
      "damage_type":	"刺伤",
      ]),
    ([
      "action":
"$N身随剑走，迅速无伦地在$n周围布下一道剑网。\n"
"$n只见周围无数人影，随时都有可能有一柄$w从意想不到的\n"
"位置刺来，实在是危机重重",
	"damage":	300,
      "damage_type":	"刺伤",
      ]),
});

int valid_learn(object me)
{
    object ob;

    if (!(ob = me->query_temp("weapon"))
	||	(string)ob->query("skill_type") != "sword" )
	return notify_fail("你必须先找一把剑才能练剑法。\n");
    
    return 1;
}

int valid_enable(string usage)
{
    return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
    return action[random(sizeof(action))];
}

int practice_skill(object me)
{

    if ((int)me->query("qi") < 30)
	return notify_fail("你的气太低，再练下去会有危险的！\n");
    if ((int)me->query("neili") < 5)
	return notify_fail("你的内力不够，没有办法运用飞仙剑法。\n");
    me->receive_damage("qi", 30);
	me->add("neili", -5);
    //write("你按著所学练了一遍飞仙剑法。\n");
    return 1;
}

int power_point()	{	return 1.75;	}
int hard_point()	{	return 2.5;	}

string perform_action_file(string func)
{
	return __DIR__"feixian-jian/"+func;
}
