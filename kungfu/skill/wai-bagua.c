//wai-bagua.c 外八卦

#include <ansi.h>

inherit SKILL;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});
#include <combat.h>
#include "/kungfu/skill/eff_msg.h";

string *parry_msg = ({
        "可是却被$n利用八卦四方的巧劲轻轻御开，化解了$N这一击。\n",
        "但是被$n手中兵刃利用八卦劲巧妙地卸开。\n",
        "但是$n按照八卦方位，随手转动手中的$p，让$N只感无从下手。\n",
});

string *unarmed_parry_msg = ({
        "可是却被$n利用八卦四方的巧劲轻轻御开，化解了$N这一击。\n",
        "$n身形一转，双手按照八卦方位打出，使得$N所有的攻势全部落空。\n",
        "但是$N感觉像打到棉花上一样，力道已全被$n利用八卦劲卸去。\n",
});

mapping *action=({
([	"action" : "$N双掌一错，使出"+(order[random(13)])+"「乾字决」"NOR"，双拳一上一下对准$n的$l连拍三招",
        "force" : 60,
        "attack": 20,
        "dodge" : 40,
        "parry" : 5,
        "damage": 114,
        "lvl"   : 0,
	"skill_name" : "乾字决",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N绕着$n一转，满场游走，拳出如风，连绵不绝地击向$n，正是八卦拳中的"+(order[random(13)])+"「坤字决」"NOR"",
        "force" : 80,
        "attack": 25,
        "dodge" : 43,
        "parry" : 6,
        "damage": 117,
        "lvl"   : 20,
	"skill_name" : "坤字决",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N使出一招"+(order[random(13)])+"「巽字决」"NOR"，左拳虚击$n的前胸，一错身，右拳迅速横扫$n的太阳穴",
        "force" : 100,
        "attack": 28,
        "dodge" : 45,
        "parry" : 8,
        "damage": 110,
        "lvl"   : 40,
	"skill_name" : "巽字决",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N使一招"+(order[random(13)])+"「坎字决」"NOR"左拳击出，不等招式使老，右拳已从左拳之底穿出，对准$n的$l"+(order[random(13)])+"「呼」"NOR"地一拳",
        "force" : 120,
        "attack": 35,
        "dodge" : 47,
        "parry" : 11,
        "damage": 170,
        "lvl"   : 60,
	"skill_name" : "坎字决",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N使出一招"+(order[random(13)])+"「震字决」"NOR"，身形一低，左手护顶，右手已迅雷不及掩耳的一拳击向$n的裆部",
        "force" : 140,
        "attack": 40,
        "dodge" : 49,
        "parry" : 13,
        "damage": 120,
        "lvl"   : 90,
	"skill_name" : "震字决",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N左拳突然张开，拳开变掌，直击化为横扫，一招"+(order[random(13)])+"「兑字决」"NOR"便往$n的$l招呼过去",
        "force" : 200,
        "attack": 48,
        "dodge" : 54,
        "parry" : 18,
        "damage": 128,
        "lvl"   : 120,
	"skill_name" : "兑字决",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N一招"+(order[random(13)])+"「离字决」"NOR"，顿时幻出重重拳影，气势如虹，铺天盖地袭向$n全身",
        "force" : 280,
        "attack": 60,
        "dodge" : 63,
        "parry" : 23,
        "damage": 137,
        "lvl"   : 150,
	"skill_name" : "离字决",
	"damage_type" : "内伤"
]),
([	"action" : "$N微微一笑，手捏"+(order[random(13)])+"「艮字决」"NOR"，飞身跃起，半空中一脚踢向$n面门，却是个虚招。\n"
	           "说时迟那时快，只见$N一个倒翻，双拳已到了$n的$l",
        "force" : 290,
        "attack": 62,
        "dodge" : 65,
        "parry" : 25,
        "damage": 140,
        "lvl"   : 180,
	"skill_name" : "艮字决",
	"damage_type" : "内伤"
]),
});

int valid_combine(string combo) { return combo=="bluesea-force" ; }
string query_parry_msg(object weapon)
{
        if (weapon)
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

int valid_enable(string usage)
{
        return usage == "unarmed" || usage == "cuff" || usage == "parry";
}

int valid_learn(object me)
{

	if( (string)me->query("family/family_name")!="雁荡派")
return notify_fail("这门武功要找雁荡派的落雁老人才能学！\n");

        if ((int)me->query_skill("parry", 1) < 100)
                return notify_fail("你的基本招架技巧掌握的还不够熟练，无法学习外八卦。\n");

        if ((int)me->query_skill("parry", 1) < (int)me->query_skill("wai-bagua", 1))
                return notify_fail("你的基本招架水平有限，无法领会更高深的外八卦。\n");

        return 1;
}

int practice_skill(object me)
{
        if (me->query_skill("wai-bagua", 1) < 100)
                return notify_fail("你对外八卦神功的了解甚浅，还不足以自行锻炼。\n");

        if ((int)me->query("qi") < 70)
                return notify_fail("你的体力太低了。\n");

        if ((int)me->query("neili") < 100)
                return notify_fail("你的内力不够练护体神功。\n");

        me->receive_damage("qi", 50);
        me->add("neili", -60);
        return 1;
}



mixed hit_ob(object me, object victim,int damage_bonus)
        
{	
        int i, level;
        object target;
object weapon;
        level   = (int) me->query_skill("wai-bagua",1);
//        target = me->select_opponent();
        weapon = me->query_temp("weapon");

	if( random(3)==1 && random(level) > 180)
	{
        if (userp(victim))
        victim->receive_wound("qi", (damage_bonus+level+100) );	
        //victim->start_busy(3);
        return HIG "「八卦无极拳!!」$N忽然变快脚下沿八卦方位疾走，双掌虚虚实实地拍向$n。\n" NOR;
	}
if (damage_bonus < 60) damage_bonus=60;
	if( random(3)==1 && random(level) > 180)
	{

        victim->receive_wound("qi", damage_bonus );	
        return HIR "乾坤无量!! $n喷出几口鲜血，脸色变得煞白！\n" NOR;
  }
}

int ob_hit(object ob, object me, int damage)
{
	object weapon = me->query_temp("weapon");
        string msg,dodge_skill,*limbs;
        int i, j, level, p, q;
        
        limbs = ob->query("limbs");
        level = me->query_skill("wai-bagua", 1);

        if( damage < 10 ) return 1;
          ob->start_busy(2);
            if ( random(3) == 0 && random(level) > 180){

                switch(random(3))
                {
                case 0:
                        msg =WHT "$n" WHT "身形忽然按照八卦方"
                                             "位转个不停，$N" WHT "这一招竟然"
                                             "无从下手。\n" NOR;
                        break;
                case 1:
                        msg =WHT "$n" WHT "单掌利用八卦四方的"
                                             "巧劲轻轻一托，$N" WHT "登时拿捏"
                                             "不准力道，不禁泛起一阵有心无力"
                                             "的感觉。\n" NOR;
                        break;

                default:
                        msg =WHT "$N" WHT "一招眼看击中了$n"
                                             WHT "，然而$n" WHT "轻轻一格，"
                                             "将$N" WHT "的攻击利用八卦巧劲"
                                             "化于无形。\n"NOR;
                        break;
                }
damage=damage/3;
if (damage<10) damage=10;

        if (me->query("qi") < me->query("max_qi") )
{
if (me->query("qi") < me->query("max_qi"))
             me->add("qi",me->query("qi")/10);
if (me->query("eff_qi") < me->query("max_qi"))
             me->add("eff_qi",me->query("max_qi")/10);
}
msg += "$n神色一变,恢复了些活力！\n";
//msg += damage_msg(damage, "瘀伤");
message_vision(msg, ob, me);
}

            return damage;
}



int query_effect_parry(object attacker, object me)
{
        int lvl;

        lvl = me->query_skill("wai-bagua", 1);
        if (lvl < 100) return 0;
        if (lvl < 150) return 20;
        if (lvl < 200) return 40;
        if (lvl < 250) return 50;
        if (lvl < 300) return 60;
        if (lvl < 350) return 70;
        return 80;
}

string perform_action_file(string action)
{
        return __DIR__"wai-bagua/" + action;
}


string query_skill_name(int level)
{
        int i;
        for (i = sizeof(action)-1; i >= 0; i--)
                if (level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level = (int)me->query_skill("wai-bagua", 1);
        for (i = sizeof(action); i > 0; i--)
                if (level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}


