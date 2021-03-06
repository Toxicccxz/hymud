// qishang-cuff
#include <ansi.h>
inherit SKILL;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([      "action" : "$N在场中暴走，出手既快且狠，呼呼风响，一拳对准了$n背上的$l直击而至",
        "force" : 190,
        "dodge" : 55,
        "lvl" : 0,
        "damage_type" : "瘀伤"
]),
([      "action" : "$N以阴柔之气，左手一翻，格开$n手臂，接着砰的一拳，已结结实实打在$n$l",
        "force" : 240,
        "dodge" : 5,
        "parry" : 20,
        "damage": 260,

        "lvl" : 5,
        "damage_type" : "瘀伤"
]),
([      "action" : "$N乘$n开口说话，猛然出拳打去，只听砰的一声大响，这一次正巧是打在$n$l上",
        "force" : 260,
        "dodge" : 50,
        "parry" : 20,
        "damage": 250,

        "lvl" : 15,
        "damage_type" : "瘀伤"
]),
([      "action" : "$N拳出如风，砰砰接连四拳，都打在$n身上，但却似不关痛痒，便如清风拂体，柔丝抚身",
        "force" : 210,
        "dodge" : 55,
        "parry" : 20,
        "damage": 350,
        "lvl" : 25,
        "damage_type" : "内伤"
]),
([      "action" : "$N双目尽赤，一声吆喝，宛似凭空打了个霹雳，猛响声中，一拳直出打在$n的$l之上",
        "force" : 400,
        "dodge" : 15,
        "parry" : 20,
        "damage": 350,

        "lvl" : 45,
        "damage_type" : "瘀伤"
]),
([      "action" : "$N暗运几口真气，跨上一步，手臂骨格格作响，接着劈的一声，一拳打向$n$l",
        "force" : 300,
        "dodge" : 55,
        "parry" : 20,
        "damage": 350,

        "lvl" : 55,
        "damage_type" : "瘀伤"
]),
([      "action" : "$N一拳击出，缩回手臂，又发拳打，退了一步，运气数转，重又上前，挺拳猛击",
        "force" : 270,
        "dodge" : 55,
        "parry" : 20,
        "damage": 300,
        "lvl" : 65,
        "damage_type" : "瘀伤"
]),
([      "action" : "$N双臂一沉一扬，拳如巨刃开山，划出一道如狱气壁，直逼向$n，$n胸口一紧，只觉烦恶欲呕",
        "force" : 350,
        "dodge" : 15,
"parry" : 20,
    "damage": 350,

        "lvl" : 75,
        "damage_type" : "瘀伤"
]),
([      "action" : "$N大喝一声，双拳连环虚击，风声未起，拳上暗劲已如怒潮倒灌，海啸逆卷，袭向$n",
        "force" : 400,
        "dodge" : 55,
"parry" : 20,
    "damage": 380,

        "lvl" : 85,
        "damage_type" : "内伤"
]),
([      "action" : "$N双目微阖，步法飘忽，轻飘飘击出数拳，却是半点声息也无，$n蓦地察觉微风拂体，拳上阴劲已袭向后心",
        "force" : 300,
        "dodge" : 50,
"parry" : 20,
    "damage": 380,

        "lvl" : 75,
        "damage_type" : "内伤"
]),
    ([  "action":"$N左手握拳护胸，右手使出一招「烘云托月」，穿出击向$n的$l",
        "lian"  :"$N左手握拳护胸，右手使出一招「烘云托月」，慢慢体会其中韵味。",
        "zhaoshi":"「烘云托月」",
        "jibie" : 5,
        "parry":    30,
        "dodge":    10, 
        "sen" : 10,
        "wound":15, 
        "damage" : 200,
        "damage_type":  "瘀伤"
    ]),
    ([  "action":"$N右手虚晃，使出一招「虚敲实应」，左掌化虚为实击向$n的$l",
        "lian"  :"$N右手虚晃，使出一招「虚敲实应」，左掌化虚为实，缓缓击出。",
        "zhaoshi" : "「虚敲实应」",
        "jibie" : 10,
        "parry":15, 
        "dodge":15,
        "sen"  : 11,
        "damage" : 225,
        "damage_type":  "瘀伤"
    ]),
    ([  "action":"$N使出七伤拳法「行云流水」，弓步上前，双掌同时拍向$n的$l",
        "lian" : "$N使出七伤拳法「行云流水」，弓步向前，双掌向空中一拍。",
        "zhaoshi" : "「行云流水」",
        "jibie" : 7,
        "sen" : 12,
        "parry":30,  
        "wound":20, 
        "damage" : 350,
        "damage_type":  "瘀伤"
    ]),
    ([  "action":"$N使出一招「大落墨」，身形腾空跃起，对准$n的$l连续拍出三掌",
        "lian"  :"$N使出一招「大落墨」，身形腾空跃起，对着空气乱拍一通。",
        "zhaoshi" : "「大落墨」",
        "jibie" : 30,
        "parry":15, 
        "sen" : 10,
        "damage" : 350,
        "damage_type":  "瘀伤"
    ]),
    ([  "action":"$N左掌扬起，右掌五指一伸一划，一招「倒卷帘」击向$n的$l",
        "lian"  :"$N左掌扬起，右掌五指一伸一划，使出一招「倒卷帘」，好象在捏苍蝇。",
        "zhaoshi" : "「倒卷帘」",
        "jibie" : 35,
        "parry":20, 
        "wound":20, 
        "sen" : 12,
        "damage" : 310,
        "damage_type":  "瘀伤"
    ]),
    ([  "action":"$N身形飞舞，一招「哨探寻」，双掌同时向$n的$l出掌攻击",
        "lian" : "$N身形飞舞，使出一招「哨探寻」，双掌一出即回，虎虎生风。",
        "zhaoshi" : "「哨探寻」",
        "jibie" : 40,
        "parry":15, 
        "sen" : 10,
        "damage" : 345,
        "damage_type":  "瘀伤"
    ]),
    ([  "action":"$N大喝一声，一招「连山断岭」，掌力倾吐，掌风罩向$n全身",
        "lian" : "$N大喝一声，一招「连山断岭」，掌力倾吐，化出一阵掌风，足以开碑裂石。",
        "zhaoshi" : "「连山断岭」",
        "jibie" : 50,
        "sen" : 15,
        "parry":15,
        "wound":25, 
        "damage" : 360,
        "damage_type":  "瘀伤"
    ]),
});

string *parry_msg = ({
    "$n双手轻点，一招「拨云见日」，轻而易举的挡开了$N的一击。\n",
    "只见$n足不点地，一招「顺水推舟」，将$N的攻势化于无形。\n",
    "但见$n不退反进，双手一扬，使出一招「叶底摘花」，立刻化险为夷。\n",
});
    


string query_parry_msg(object weapon)
{   
    return parry_msg[random(sizeof(parry_msg))];
}
string  *msg = ({
""+(order[random(13)])+"$N一拳击出，拳风中竟带有刚柔三种不同的劲力，分击$n的全身上下三十六道要穴"NOR"",
""+(order[random(13)])+"$N暗吸一口真气，双拳平伸，左刚右柔连续打出四拳，带着四种不同之力击向$n的$l"NOR"",
""+(order[random(13)])+"$N默运神功，双拳无形无定，突然于空气中出现五种不同的劲力骤然击向$n的前胸"NOR"",
""+(order[random(13)])+"$N单拳一握，默运内息，六种不同劲力随着打出的拳风又低又快的击向$n的$l"NOR"",
""+(order[random(13)])+"只见$N双目紧闭深运内力，然后猛的大喝了一声，飞身扑下，以七种无比之劲力击向$n的全身"NOR"",
""+(order[random(13)])+"$N一声狂啸，双目赤红，拳路大开大阖，每一拳击出如诸神震怒，石破天惊，皆含催破内家真气的大威力"NOR"",

});

int valid_combine(string combo) { return combo=="shizi-zhan"; }

int valid_enable(string usage)
{
	return usage=="unarmed" || usage=="parry" || usage=="cuff";
}

int practice_skill(object me)
{
	if( (int)me->query("jing") < 30)
		return notify_fail("你的精神无法集中了，休息一下再练吧。\n");
	if( (int)me->query("qi") < 30 )
		return notify_fail("你现在手足酸软，休息一下再练吧。\n");
	if( (int)me->query("neili") < 10 )
		return notify_fail("你的内力不够了。\n");
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

	if( (int)me->query_skill("kongling-jian",1) < 200 )
		return notify_fail("你的空灵剑法不够。\n");

	if( (int)me->query_skill("luoriquan",1) < 200 )
		return notify_fail("你的落日神拳不够。\n");

	if( (int)me->query_skill("ill-quan",1) < 200 )
		return notify_fail("你的病维摩拳不够。\n");
	me->receive_damage("qi", 30);
	me->add("neili", -10);

	return 1;
}

string perform_action_file(string func)
{
	return __DIR__"qishang-cuff/"+func;
}

mapping query_action(object me, object weapon)
{
        int i, level, neili, force;
        level   = (int) me->query_skill("qishang-cuff",1);
        force = me->query_skill("force");
        neili = me->query("neili");
        me->delete_temp("qishang_hit", 1);

        if (level > 100 && force > 150 && neili > 500 
            && me->query("max_neili") > 1000
            && me->query("jiali")
            && random(me->query_str()) > 15
            && random(3)>0
            ){
            me->set_temp("qishang_hit", 1);
            return([      
                   "action": msg[random(sizeof(msg))],                   
                   "force" : 400+random(350),
                   "damage" : 400+random(350),
                   "dodge" : 50+random(100),
                   "damage_type" : random(2)?"瘀伤":"震伤",
                   ]);
            }

        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

void skill_improved(object me)
{
   object *ob;
   int i, skill;
   skill = me->query_skill("qishang-cuff", 1);
   if(me->query("max_neili") < skill*15 && skill < 200){
    switch(random(5)){
      case 0 : 
              tell_object(me, HIR"你肩头云门穴突然一阵轻微隐痛，是肺脉伤了！\n"NOR);
              me->add("max_neili", -random(70));
              break;      
      case 1 : 
              tell_object(me, HIR"你腿上无里穴突然酸痛难当，是肝脉伤了！\n"NOR);
              me->add("combat_exp", -random(5000));
              break;
      case 2 : 
              message_vision(HIR"$N心脉练伤，突然狂性大发、无法抑制了！\n"NOR, me);
              ob = all_inventory(environment(me));
              for(i=0; i<sizeof(ob); i++) {
                if(!living(ob[i]) || ob[i]==me ) continue;
                if(!ob[i]->is_fight(me) ) ob[i]->fight_ob(me);
                }
              break;
      case 3 : 
              tell_object(me, HIR"你上臂青灵穴突然一时麻痒难当，是心脉伤了！\n"NOR);
              me->add("max_qi", -random(70));
              break;
      case 4 : 
              tell_object(me, HIR"你突然觉得体内阴阳二气串行金木水火土五行，无法抑制了！\n"NOR);
              me->set_skill("qishang-cuff", skill-2);
              break;
      }
//     me->unconcious();
     }
}

mixed hit_ob(object me, object victim, int damage_bonus)
{


    if( damage_bonus < 60 ) return 0;
if (random(me->query_skill("qishang-cuff",1)) > 90
&& me->query_skill_mapped("force") == "kongdong-xinfa"
)
{
message_vision(HIR"$N被一拳打中，七者皆伤!\n"NOR,victim);
victim->receive_wound("qi", damage_bonus/2 );
}
    if(random(me->query_skill("qishang-cuff", 1)) > 50
       && random(me->query("neili")) > 500
       && random(me->query("combat_exp",1)) > victim->query("combat_exp",1)/3 ){
       if(victim->query("neili")/3 < me->query("neili"))
          victim->apply_condition("qishang_poison", 32+victim->query_condition("qishang_poison"));       
       else me->apply_condition("qishang_poison", 31+victim->query_condition("qishang_poison"));
        }
}    

int valid_learn(object me)
{
	if( me->query("max_neili") < 1000 )
		return notify_fail("你的内力不够，无法修炼。\n");

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

	if( (int)me->query_skill("kongling-jian",1) < 200 )
		return notify_fail("你的空灵剑法不够。\n");

	if( (int)me->query_skill("luoriquan",1) < 200 )
		return notify_fail("你的落日神拳不够。\n");

	if( (int)me->query_skill("ill-quan",1) < 200 )
		return notify_fail("你的病维摩拳不够。\n");
						
	return 1;
}