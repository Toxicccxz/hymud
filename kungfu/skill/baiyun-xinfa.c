// baiyun-xinfa.c 白云心法
// Last Modify by sir 5/17/2001

#include <ansi.h>

inherit FORCE;

string type() { return "martial"; }
string martialtype() { return "force"; }
int valid_enable(string usage) { return usage == "force"; }
int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 10; }
int power_point() { return 1; }

int valid_learn(object me)
{
	int i,nb,ny,ns;
	
	nb = (int)me->query_skill("buddhism", 1);
	ny = (int)me->query_skill("baiyun-xinfa", 1);
	ns = (int)me->query("guilty");
if (
	me->query_skill("bahuang-gong",1)
|| me->query_skill("xuantian-wuji",1)
	|| me->query_skill("beiming-shengong",1)
	|| me->query_skill("bibo-shengong",1)
	|| me->query_skill("hamagong",1)
	|| me->query_skill("huagong-dafa",1)
	|| me->query_skill("huntian-qigong",1)
	|| me->query_skill("hunyuan-yiqi",1)
	|| me->query_skill("jiuyang-shengong",1)
	|| me->query_skill("kuihua-xinfa",1)
	|| me->query_skill("kurong-changong",1)
	|| me->query_skill("linji-zhuang",1)
	|| me->query_skill("longxiang",1)
 	|| me->query_skill("shenlong-xinfa",1)
	|| me->query_skill("xiantian-qigong",1)
	|| me->query_skill("xiaowuxiang",1)
	|| me->query_skill("yijinjing",1)
	|| me->query_skill("yunv-xinfa",1)
	|| me->query_skill("yunlong-shengong",1)   ||
me->query_skill("shenghuo-shengong",1)    ||
me->query_skill("shenyuan-gong",1)   ||
me->query_skill("huashan-neigong",1)   ||
me->query_skill("zixia-shengong",1) ||
me->query_skill("shayi-xinfa",1)||
me->query_skill("biyun-xinfa",1)||
me->query_skill("bingxue-xinfa",1)||
me->query_skill("wudu-shengong",1)||
me->query_skill("taiji-shengong",1)||
me->query_skill("guiyuan-tunafa",1)||
me->query_skill("kongdong-xinfa",1)||
me->query_skill("taixuan-gong",1)||
me->query_skill("bitao-shengong",1)||
me->query_skill("jinghai-force",1)||
me->query_skill("wuzheng-xinfa",1)||
me->query_skill("lengyue-shengong",1)||
me->query_skill("huiyan-xinfa",1)||
me->query_skill("songshan-qigong",1)||
me->query_skill("hanbing-zhenqi",1)||
me->query_skill("panshi-shengong",1)||
me->query_skill("qingming-xuangong",1)||
me->query_skill("bluesea-force",1)||
me->query_skill("honghua-shengong",1)
 )
		return notify_fail("你不先散了别派内功，怎能学？！\n");
	if ( me->query("couple/have_couple") )
		return notify_fail("你尘缘未了，无法再学习白云心法！\n");	
	if ( me->query("gender") != "女性" )
		return notify_fail("白云心法只适合女性修练。\n");
	if ( me->query("sex/number") )
		return notify_fail("你非处女之身，无法修习白云心法！\n");	
	if (((string)me->query("class") != "bonze") && i > 29)
		return notify_fail("你不是尼姑，学不了高深的白云心法。\n");
	if ((int)me->query_skill("force", 1) < 10)
		return notify_fail("你的基本内功火候还不够。\n");

	if ( nb < 100 && nb <= ny )
		return notify_fail("你的禅宗心法修为不够，无法领会更高深的白云心法。\n");
	if ( ns > 0 ) 
		return notify_fail("你屡犯僧家数戒，无法领会更高深的白云心法。\n");
	return 1;
	
}

int practice_skill(object me)
{
	return notify_fail("白云心法只能用学(learn)的来增加熟练度。\n");
}
string exert_function_file(string func)
{
	return __DIR__"baiyun-xinfa/" + func;
}

int help(object me)
{
	write(HIC"\n白云心法："NOR"\n");
	write(@HELP

  恒山派内功

	学习要求：
		基本内功10级
		处女纯阴之体		
HELP
	);
        return 1;
}

