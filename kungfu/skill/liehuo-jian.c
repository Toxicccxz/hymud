// liehuo-jian.c 烈火剑
#include <ansi.h>
#include <combat.h>

inherit SKILL;

mapping *action = ({
([      "action" : "$N一招「四海云飘」，$w似幻出片片白云，四面八方的罩向$n",
        "force" : 170,
        "dodge" : 15,
        "damage" : 120,
        "lvl" : 0,
        "skill_name" : "四海云飘",
        "damage_type" : "刺伤"
]),
([      "action" : "$N一招「四通八达」，剑锋乱指，攻向$n，$n根本不能分辩$w的来路",
        "force" : 190,
        "dodge" : 10,
        "damage" : 130,
        "lvl" : 19,
        "skill_name" : "四通八达",
        "damage_type" : "刺伤"
]),
([      "action" : "$N使出「在天一方」，$w幻一条飞练，带着一股寒气划向$n的$l",
        "force" : 110,
        "dodge" : 10,
        "damage" : 140,
        "lvl" : 29,
        "skill_name" : "在天一方",
        "damage_type" : "刺伤"
]),
([      "action" : "$N身子向上弹起，左手下指，一招「怪蟒翻身」，右手$w带着一团剑花，逼向$n的$l",
        "force" : 130,
        "dodge" : 5,
        "damage" : 150,
        "lvl" : 39,
        "skill_name" : "怪蟒翻身",
        "damage_type" : "刺伤"
]),
([      "action" : "$N一招「飞瀑倒悬」，左脚跃步落地，右手$w幻成一条雪白的瀑布，扫向$n的$l",
        "force" : 150,
        "dodge" : 5,
        "damage" : 160,
        "lvl" : 59,
        "skill_name" : "飞瀑倒悬",
        "damage_type" : "刺伤"
]),
([      "action" : "$N右腿半屈般蹲，$w平指，一招「无声无色」，剑尖无声无色的慢慢的刺向$n的$l",
        "force" : 170,
        "dodge" : 15,
        "damage" : 170,
        "lvl" : 79,
        "skill_name" : "无声无色",
        "damage_type" : "刺伤"
]),
([  "action" : "$N一招「万川归海」，$w在$n的周身飞舞，令$n眼花缭乱，剑身在半空中突然停住刺向$n的$l",
        "force" : 300,
        "dodge" : 5,
        "damage" : 280,
        "lvl" : 99,
        "skill_name" : "万川归海",
        "damage_type" : "刺伤"
]),
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力不够。\n");
        if ((int)me->query_skill("jiuyang-shengong", 1) < 20)
                return notify_fail("你的九阳神功火侯太浅。\n");
        return 1;
}
string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level   = (int) me->query_skill("liehuo-jian",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query("jing") < 50)
                return notify_fail("你的体力不够练烈火剑法。\n");
        me->receive_damage("jing", 30);
        return 1;
}
string perform_action_file(string action)
{
        return __DIR__"liehuo-jian/" + action;
}


mixed ob_hit(object me, object victim, int damage, int damage_bonus, int factor)
{
        object weapon1 = me->query_temp("weapon");
        object weapon2 = victim->query_temp("weapon");

        int ap, dp;
        string result;

	ap = (int)me->query("combat_exp",1)+(int)victim->query_skill("parry",1);

        dp = victim->query("combat_exp",1);
        if (objectp(weapon1))
                dp += victim->query_skill("dodge");
if (random(me->query_skill("jiuyang-shengong",1)) > 130
&& me->query("neili") < me->query("max_neili")
&& me->query_skill_mapped("force") == "jiuyang-shengong"
)
{
message_vision(HIR"$N运起九阳神功，全身内力源源不断的涌出!\n"NOR,me, victim);
me->add("neili",(random(me->query_skill("jiuyang-shengong",1))+180));
}

if (random(me->query_skill("jiuyang-shengong",1)) > 120
&& me->query("qi") < me->query("max_qi")
&& me->query_skill_mapped("force") == "jiuyang-shengong"
)
{
message_vision(RED"$N运起九阳神功，身上的伤好了很多!\n"NOR,me, victim);
me->add("qi",random(me->query_skill("jiuyang-shengong",1))+200);
if (me->query("eff_qi") < me->query("max_qi"))
me->add("eff_qi",random(me->query_skill("jiuyang-shengong",1))+200);
}


if (random(me->query_skill("qiankun-danuoyi",1)) > 120
&& me->is_busy()
&& me->query_skill_mapped("force") == "jiuyang-shengong"
&& random(2)==0
)
{
message_vision(HIC"$N暗运乾坤大挪移，本来忙乱的动作快了起来!\n"NOR,me, victim);
me->start_busy(1);
}
        if ( random(ap) > dp/3 
        && me->query("jiuyangok")
        && (int)me->query_temp("shield")
        && me->query_skill_mapped("force") == "jiuyang-shengong"
        ) {
                if ( objectp(weapon1)) {
                        if (damage + damage_bonus > 0)
                        {                 
				damage_bonus=-damage/3;
                                result = HIM"$n身子一侧，将$N兵刃上的力道卸去大半。\n"NOR;
                        }
                        else {
				result = MAG"$n身子一侧，将$N兵刃上的力道卸去大半。\n"NOR;
				damage_bonus=-damage/3;
			}
                }
                else if(!objectp(weapon1)){
                        if (damage + damage_bonus > 0)
			{
				damage_bonus=-damage/2;
			        result = HIG"$n九阳神功自然而然发出抗力，将$N的力道一挡。\n"NOR;                      
			}
                	else {
				result = MAG"$n九阳神功自然而然发出抗力，将$N的力道一挡。\n"NOR;
				damage_bonus=-damage/2;
			}
		}	

	}
if (result)
        message_vision(result,me,victim);
        return damage;
}




mixed hit_ob(object me, object victim, int damage_bonus)
{
        int lvl,nlvl;

        lvl = me->query_skill("jiuyang-shengong", 1);
        nlvl = me->query_skill("liuhuo-jian", 1);

        if (damage_bonus < 50
           || lvl < 150
           || me->query("neili") < 300
           || me->query_skill_mapped("force") != "jiuyang-shengong"
           || me->query_skill_mapped("unarmed") != "jiuyang-shengong"
		|| !me->query("jiuyangok") )
		return 0;

        if ((random(3)==0 && damage_bonus / 5 > victim->query_con()) || random(8)==0)
        {
	        me->add("neili", -5);
                victim->receive_wound("qi", (random(nlvl)) / 2+10, me);
                return random(2) ? HIR "只见$N" HIR "九阳内劲自体内迸发，真气随招式"
                                   "而荡漾，摧毁了$n" HIR "的真元！\n" NOR:

                                   HIR "$N" HIR "九阳神功的潜力发挥了出来，突然间$n"
                                   HIR "只感喉咙一甜，喷出一口鲜血！\n" NOR;
        }
}