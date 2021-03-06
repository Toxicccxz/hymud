//xiuli-qiankun.c 袖里乾坤 5级拳法
//by wyh
#include <ansi.h>
inherit SKILL;

mapping *action = ({
        ([      "action":               
"$N双袖急挥出一片袖影，猛然一道青影直穿而出，一招「双树含秋色」，直拍向$n$l",
                "lian":
"$N双袖急挥出一片袖影，猛然一道青影直穿而出，一招「双树含秋色」，直甩出去",
                "zhaoshi":         "双树含秋色",
                "dodge":                40,
                "sen":                  4,
                "jibie":                  0,
                "parry":                30,
                "force":                70,
                "damage":               260,
                "damage_type":  "淤伤",
                                   ]),
        ([      "action":               
"$N身形飞转，双袖化作一道青色墙壁，一招「雁塔风霜古」，架住了$n的所有攻势",
                "lian":
"$N身形飞转，一招「雁塔风霜古」，双袖化作一道青色墙壁",
                "zhaoshi":         "雁塔风霜古",
                "dodge":                30,
                "parry":                100,
                "force":                60,
                "sen":                  5,
                "jibie":                 16,
                "damage":               230,
                "damage_type":  "淤伤",
                    ]),
        ([      "action":               
"$N身形稍顿，左袖一扬，一招「独拂秋霞眠」往$n的$l拍去",
                "lian":
"$N身法稍顿，左袖一扬，一招「独拂秋霞眠」直拍出去",
                "zhaoshi": "独拂秋霞眠",
                "dodge":               15,
                "sen":                  5,
                "parry":                30,
                "jibie":                 36,
                "force":                50,
                "damage":               240, 
                "damage_type":  "淤伤",
                       ]),
        ([      "action":               
"$N腰身一摆，陡然滑出数尺，右臂顺著来势一招「萝月挂朝镜」往$n攻去",
                "lian":
"$N腰身一摆，陡然滑出数尺，右臂顺著来势一招「萝月挂朝镜」攻了出去",
                "zhaoshi":   "萝月挂朝镜",
                "sen":                  6,
                "jibie":                 60,
                "dodge":                20,
                "parry":                50,
                "force":                70,
                "damage":               270,
                "damage_type":  "淤伤",
                     ]),
  ([      "action":               
"$N身形微晃，一招「松风鸣夜弦」绕至$n身后，以攻为守，一片袖影甩向$n",
                "lian":
"$N身形微晃，一招「松风鸣夜弦」直甩出去",
                "zhaoshi":         "松风鸣夜弦",
                "dodge":                15,
                "sen":                  7,
                "jibie":                 82,
                "parry":                55,
                "force":                100,
                "damage":               280,
                "damage_type":  "淤伤",
                                   ]),
        ([      "action":               
"$N飞身跃起，一招「潜光隐嵩岳」，一片袖影向$n头顶罩下",
                "lian":
"$N飞身跃起，一招「潜光隐嵩岳」，一片袖影直罩而下",
                "zhaoshi":         "潜光隐嵩岳", 
                "dodge":                20,
                "parry":                40,
                "force":                110,
                "sen":                  7,
                "jibie":                  310,
                "damage":               90,
                "damage_type":  "淤伤",
                    ]),

});

string  *parry_msg=({
    "$n一招「练魄栖云幄」，衣袖拂起，两只宽大的衣袖鼓风而前，便如是两道顺风的船帆.\n"
    "把$N的攻势尽数挡了回去。",
    "$n并不躲闪，右袖拂出，裹向$N的双手。",
    "$n身形飘出，一招「仙簌发清虚」跃在空中，双袖飞舞，如若一只彩蝶，躲开了$N这一击。",
    "$n双手一合，两袖立于身前，化作一股气墙，将$N的攻势尽数弹了回去。",
});
string query_parry_msg(object weapon)
{
    return parry_msg[random(sizeof(parry_msg))];
}

int valid_enable(string usage)
{
	return usage=="unarmed" || usage=="parry" || usage=="strike";
}

int valid_combine(string combo) { return combo=="wuyu-quan"; }

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int valid_learn(object me)
{
    if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
        return notify_fail("练袖里乾坤必须空手。\n");
    return 1;
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
	return __DIR__"xiuli-qiankun/"+func;
}


 





int ob_hit(object ob, object me, int damage)
{
	object weapon = me->query_temp("weapon");
        string msg,dodge_skill,*limbs;
        int i, j, level, p, q;
        string result;
        int ap, dp, mp;
        ap = (int)me->query("combat_exp");
        dp = (int)ob->query("combat_exp");
j=damage;
if (me->query_skill_mapped("force") != "taixuan-gong")
return damage;
if (me->query_skill_mapped("unarmed") != "taixuan-gong")
return damage;
        if ((int)me->query_skill("literate", 1)> 5 )	
return damage;

if (me->query("neili") < 500)
return damage;
 if (objectp(weapon = me->query_temp("weapon"))
        )
return damage;

             
  if (random(ap) < dp/2  
  && random(2)==0)
        {

                switch (random(2))
                {
                case 0:
                        result =  HIR "$n" HIR "默念太玄功口诀，太玄内"
                                            "劲齐聚于全身，$N" HIR "只觉这招攻在"
                                            "$n" HIR "身上\n，犹如碰到铜墙铁壁一般，"
                                            "丝毫不起作用。\n"NOR;
                        break;
                case 1:
                        result =  HIR "$N" HIR "一招击中$n" HIR "上身"
                                            "，可却犹如击在铜墙铁壁上一般\n，力道顿时"
                                            "消失得无影无踪。\n" NOR;
                        break;
                default:
                        result =  HIR "但见$n" HIR "一声轻啸，浑若无事"
                                            "的接下了$N" HIR "这一招，\n却没有受到"
                                            "半点伤害。\n" NOR;
                        break;
                }
message_vision(result,ob,me);
                                    if (!ob->is_busy()) ob->start_busy(3);
if ((int)me->query("qi") < (int)me->query("eff_qi")*2)
me->add("qi",damage/5+200);
if ((int)me->query("eff_qi") < (int)me->query("max_qi")*2)
me->add("eff_qi",damage/5+200);
            damage=100;
            j=100;
damage=-(damage/2);
j=damage;
            
            return j;

        }

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