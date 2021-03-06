// 神话世界·西游记·版本４．５０
/* by cigar 2002.01 */
 
//【封日混天锤】??

inherit SKILL;
#include <ansi.h>
#include <combat.h>
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

#include "/kungfu/skill/eff_msg.h";
string* skill_head =({
        "$N沉稳脚步的一招 熊熊火焰",
        "$N双手一震，发出一招 炎日",
        "$N一提气，使出一招 封日",
        "$N一声长啸，使出 破烈日",
        "$N大呼一声使出 闷雷",
        "$N趁$n防御之际，一招 雷霆一击",
        "$N一招 盘古开天",
        "$N双手一震，发出一招 女涡补天",
        "$N一提气，使出一招 白蛇吐芯",
        "$N一声龙吟长啸，使出 混沌一破",
        "$N使出 蓄紧力发",

        "$N趁$n防御之际，一招 天道均衡",
});

string* skill_tail =({
        "，手中$w夹带着烈日般的热度，劈头盖脸地就向$n烧了下来。",
        "，对$n劈头盖脸的砸了下来。",
        "，手中$w斜斜借助烈日炎光砸向$n的$l",
        "，手中$w一阵横扫，靠炎日的威力直逼$n",
        "，直震的$n节节后退。",
        "，手中$w飘渺不定，闪闪发光，$n顿时手忙脚乱！",
        "，手中$w夹带着闷雷般的响声，劈头盖脸地就向$n砸了下来。",
        "，对$n劈头盖脸的砸了下来。",
        "，手中$w斜斜地砸向$n的$l",
        "，手中$w一阵横扫，直逼$n",
        "，直震的$n节节后退。",
        "，手中$w飘渺不定，$n顿时手忙脚乱！",
});
mapping *action = ({
  ([   "action":   "$N手中$w一转，卷着一股强劲的"+BLINK""+HIR"[炎炎烈日]"NOR"之火烧向$n的$l，
这一下又稳又猛又烈，势大力狠，眼见就到了$n身前",
     "dodge":   10,
     "parry":   10,
     "damage":   350,
     "damage_type":   "砸伤",
   ]),
   ([   "action":   "$N双手一紧，手中$w夹带着"+BLINK""+HIR"[封日]"NOR"般的威力，劈头盖脸地就向$n砸了过去",
     "dodge":   15,
     "parry":   15,
     "damage":   40,
     "damage_type":   "砸伤",
   ]),
   ([   "action":   "$N将$w高举过肩，蓄紧力发，对准$n的$l发出"+BLINK""+HIY"[烈日之光]"NOR"",
     "dodge":   20,
     "parry":   20,
     "damage":   335,
     "damage_type":   "砸伤",
   ]),
   ([   "action":   "$N身走轻灵，手中$w忽上忽下，甩出"+BLINK""+HIY"[熊熊火焰]"NOR"令人捉摸不清去路，
就在$n一恍惚间，“唰”地砸向$n的$l",
     "dodge":   10,
     "parry":   10,
     "damage":   325,
     "damage_type":   "砸伤",
   ]),
   ([   "action":   "$N趁与$n错身之时，倒转$w，锤柄砸向$n，
这一下如"+BLINK""+HIR"[烈火]"NOR"，悄无声息的射上了$n的$l",
     "dodge":   10,
     "parry":   10,
     "damage":  325,
     "damage_type":   "戳伤",
   ]),
   ([   "action":   "$N手持$w对着"+BLINK""+HIR"[炎日]"NOR"画了一个无形大圈，卷的周围沙土尘扬，
趁$n不能辨物之时，手中$w斜斜地封向$n的$l",
     "dodge":   20,
     "parry":   25,
     "damage":  340,
     "damage_type":   "砸伤",
   ]),
(["action" : "$N一声长啸，大锤直封$n，此招看似简单、看似无力，但是力道无穷浑厚，
相传源自盘古开天时所用的"+BLINK""+HIW"[破烈日]"NOR"无极招数。",
    "dodge" : 20,
    "damage" : 400,
    "lvl" : 120,
    "skill_name" : "烈日冰封",
    "damage_type" : "砸伤"
]),
  ([   "action":   "$N手中$w一转，卷着一股强劲的风力挥向$n的$l，
这一下又急又猛，势大力狠，眼见就到了$n身前",
     "dodge":   10,
     "parry":   10,
     "damage":   330,
     "damage_type":   "砸伤",
   ]),
   ([   "action":   "$N双手一震，手中$w夹带着闷雷般的响声，劈头盖脸地就向$n砸了过去",
     "dodge":   15,
     "parry":   15,
     "damage":   430,
     "damage_type":   "砸伤",
   ]),
   ([   "action":   "$N将$w高举过肩，蓄紧力发，对准$n的$l发出雷霆一击",
     "dodge":   20,
     "parry":   20,
     "damage":   435,
     "damage_type":   "砸伤",
   ]),
   ([   "action":   "$N身走轻灵，手中$w忽上忽下，令人捉摸不清去路，
就在$n一恍惚间，“唰”地砸向$n的$l",
     "dodge":   10,
     "parry":   10,
     "damage":   425,
     "damage_type":   "砸伤",
   ]),
   ([   "action":   "$N趁与$n错身之机，倒转$w，锤把戳向了$n，
这一下如白蛇吐芯，悄无声息的点上了$n的$l",
     "dodge":   10,
     "parry":   10,
     "damage":   420,
     "damage_type":   "戳伤",
   ]),
   ([   "action":   "$N紧握$w猛挥了个大圆，卷的周身长内沙土尘扬，
趁$n不能辨物之记，手中$w斜斜地砸向$n的$l",
     "dodge":   20,
     "parry":   25,
     "damage":   430,
     "damage_type":   "砸伤",
   ]),
(["action" : "$N一声龙吟长啸,大锤直击$n右肩，此招毫无花巧,但胜在力道雄浑，
相传源自盘古开天时所用的混沌一破。",
    "dodge" : 20,
    "damage" : 500,
    "lvl" : 120,
    "skill_name" : "混天一破",
    "damage_type" : "砸伤"
]),
});

int valid_learn(object me)
{
        object ob;

        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力不够。\n");
        if ((int)me->query_skill("qingming-xuangong", 1) < 200)
                return notify_fail("你的青冥玄功火候太浅。\n");

        if ((int)me->query_skill("songfeng-jian", 1) < 200)
                return notify_fail("你的松风剑法火候太浅。\n");

        if ((int)me->query_skill("chuanhua", 1) < 200)
                return notify_fail("你的穿花绕树火候太浅。\n");

        if ((int)me->query_skill("wuying-leg", 1) < 200)
                return notify_fail("你的无影腿火候太浅。\n");

        if ((int)me->query_skill("cuixin-strike", 1) < 200)
                return notify_fail("你的摧心掌火候太浅。\n");           

        if ((int)me->query_skill("taoism", 1) < 200)
         return notify_fail("你的道法火候太浅。\n");


        if ((int)me->query_skill("chengzi18po", 1) < 200)
                return notify_fail("你的城字十八破太浅。\n");
                
        if ((int)me->query_skill("qingzi9da", 1) < 200)
                return notify_fail("你的青字九打太浅。\n");             
                

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "hammer" )
                return notify_fail("你必须先找一柄锤才能练封日混天锤。\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="hammer" || usage=="parry";
}


int practice_skill(object me)
{
    object ob;
        if( (int)me->query("qi") < 50
        ||      (int)me->query("neili") < 50 )
                return
notify_fail("你的内力或气不够，没有办法练习封日混天锤。\n");
 
 
        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力不够。\n");
        if ((int)me->query_skill("qingming-xuangong", 1) < 200)
                return notify_fail("你的青冥玄功火候太浅。\n");

        if ((int)me->query_skill("songfeng-jian", 1) < 200)
                return notify_fail("你的松风剑法火候太浅。\n");

        if ((int)me->query_skill("chuanhua", 1) < 200)
                return notify_fail("你的穿花绕树火候太浅。\n");

        if ((int)me->query_skill("wuying-leg", 1) < 200)
                return notify_fail("你的无影腿火候太浅。\n");

        if ((int)me->query_skill("cuixin-strike", 1) < 200)
                return notify_fail("你的摧心掌火候太浅。\n");           

        if ((int)me->query_skill("taoism", 1) < 200)
                return notify_fail("你的道法火候太浅。\n");


        if ((int)me->query_skill("chengzi18po", 1) < 200)
                return notify_fail("你的城字十八破太浅。\n");
                
        if ((int)me->query_skill("qingzi9da", 1) < 200)
                return notify_fail("你的青字九打太浅。\n");             
                

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "hammer" )
                return notify_fail("你必须先找一柄锤才能练封日混天锤。\n"); 
 
        me->receive_damage("qi", 30);
        me->add("neili", -35);
        //write("你按着所学练了一遍封日混天锤。\n");
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"frht-hammer/" + action;

}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

string query_parry_msg(object weapon)
{
        return action[random(sizeof(action))]["parry_msg"];
}




mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        int level, jiali, time,level2,damage,damage2;
        object weapon;
        int i;
        object target;

        level   = (int) me->query_skill("frht-hammer",1);       
        weapon = me->query_temp("weapon");
        level = (int) me->query_skill("sword",1);
        level2= (int) me->query_skill("qingming-xuangong",1);
damage= (int) me->query("neili",1)/10;
damage2=random(me->query_skill("frht-hammer",1))+50;


if ( me->query_skill_mapped("force") == "qingming-xuangong")
{
        if( random(8)==1 && random(level) > 200)
        {
        if (userp(victim))
        victim->receive_wound("qi", (damage_bonus+level+100) ); 
        return HIY "「摧心诀!!」$N猛地一个侧身一闪，转到$n身后，右掌往$n后心印了下去。\n" NOR;
        }
 if (damage_bonus < 60) damage_bonus=60;
        if( random(8)==1 && random(level) > 180)
        {

        victim->receive_wound("qi", damage_bonus+50 );  
        return RED "摧心诀!! $n后心一震只觉得喉头一甜一条血丝从嘴角挂了下来！\n" NOR;
  }
}
if (random(8)==0 && level2>=300 && me->query_skill_mapped("force") == "qingming-xuangong")
{
if (victim->query("qi")>= damage )
{
victim->receive_damage("qi", damage);
        victim->receive_wound("qi", damage);
}
        return order[random(13)]+skill_head[random(sizeof(skill_head))]+skill_tail[random(sizeof(skill_tail))]+"\n"NOR;
}
if (damage_bonus <80) damage_bonus=80;
      if( random(me->query_skill("frht-hammer",1)) > 50 ) 
{
          victim->receive_wound("qi", damage2+120);
        return order[random(13)]+skill_head[random(sizeof(skill_head))]+skill_tail[random(sizeof(skill_tail))]+"\n"NOR;
}
}

int ob_hit(object ob, object me, int damage)
{
        object weapon = me->query_temp("weapon");
        string msg,dodge_skill,*limbs;
        int i, j, level, p, q;
        
        limbs = ob->query("limbs");
        level = me->query_skill("frht-hammer", 1);

        if( damage < 10 ) return 1;
          ob->start_busy(2);
             if ( random(3) == 0 && random(level) > 150){
         msg = RED"$N的左足反踢而起，直撩$n的下阴！不待$n退开站稳，右足连环反踢，将$n踢得一时无法还手！\n"NOR;
         msg += RED"「撩阴脚!!」。$N如影随形的踢出几脚，$n吐出一口鲜血!!。\n"NOR;
             ob->add("qi",-(level+100));
             ob->add("eff_qi",-(level+100));

if (userp(ob) && !ob->is_busy()) ob->start_busy(2);
        if (userp(me) && userp(ob) && ob->query("qi") > 50
        && ob->query("eff_qi") > 50)
{
if (ob->query("qi")/12 > 20)
             ob->add("qi",-ob->query("qi")/12);
if (ob->query("eff_qi")/12 > 20)
             ob->add("eff_qi",-ob->query("eff_qi")/12);
}

msg += damage_msg(damage, "瘀伤");
message_vision(msg, me, ob);
}

            return damage;
}


