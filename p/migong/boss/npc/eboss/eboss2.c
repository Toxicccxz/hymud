#include <ansi.h>
inherit BOSS;
int big_blowing();
#include "/d/migong/romnpc2.c"

mapping *data=({
(["id":"boss","title":"五路神","name":"施令威",]),
(["id":"boss","title":"红花会上代总舵主","name":"于万亭",]),
(["id":"boss","title":"青城派","name":"慧侣道人",]),
(["id":"boss","title":"天池怪侠","name":"袁士霄",]),
(["id":"boss","title":"绵里针","name":"陆菲青","sex":1,]),
(["id":"boss","title":"六扇门高手魔爪孙","name":"万庆澜",]),
(["id":"boss","title":"大内御前侍卫一苇渡江","name":"褚圆",]),
(["id":"boss","title":"镖局总镖头威震河朔","name":"王维扬",]),
(["id":"boss","title":"当世八卦门第一高手","name":"王剑英","sex":1,]),
(["id":"boss","title":"天山双鹰秃鹫","name":"陈正德",]),
(["id":"boss","title":"天山双鹰雪雕","name":"关明梅",]),
(["id":"boss","title":"关东六魔五魔","name":"阎世魁",]),
(["id":"boss","title":"关东六魔六魔","name":"阎世章",]),
(["id":"boss","title":"两湖豪杰玉判官","name":"贝人龙",]),
(["id":"boss","title":"焦文期盟弟铁臂罗汉","name":"罗信",]),
(["id":"boss","title":"金刀无敌","name":"王元霸",]),
(["id":"boss","title":"五云手","name":"万震山",]),
(["id":"boss","title":"陆地神龙","name":"言达平",]),
(["id":"boss","title":"太行山寨主","name":"吕通",]),
(["id":"boss","title":"血刀门五僧之首","name":"宝象",]),
(["id":"boss","title":"铁骨墨萼","name":"梅念笙",]),
(["id":"boss","title":"铁索横江","name":"戚长发",]),
(["id":"boss","title":"明教教主","name":"阳顶天",]),
(["id":"boss","title":"鹿杖客大弟子","name":"乌旺阿普",]),
(["id":"boss","title":"闪电娘娘","name":"卫四娘","sex":1,]),
(["id":"boss","title":"乾坤一剑","name":"震山子",]),
(["id":"boss","title":"摩天居士","name":"谢烟客",]),
(["id":"boss","title":"铁胆庄庄主铁胆","name":"周仲英","sex":1,]),
(["id":"boss","title":"温州太极门千手如来","name":"赵半山",]),
(["id":"boss","title":"广平太极门掌门","name":"孙刚峰",]),
(["id":"boss","title":"西岳华拳门","name":"姬老三",]),
(["id":"boss","title":"西岳华拳门","name":"","name":"蔡威",]),
(["id":"boss","title":"太监总管","name":"海大富",]),
(["id":"boss","title":"铁背苍龙","name":"柳大洪",]),
(["id":"boss","title":"摇头狮子","name":"吴立身",]),
(["id":"boss","title":"西夏一品堂堂主","name":"李延年",]),
(["id":"boss","title":"雷动于九天之上","name":"九翼道人",]),
(["id":"boss","title":"拈花寺住持","name":"黄眉僧",]),
(["id":"boss","title":"波斯总教教主山中老人","name":"霍山",]),
(["id":"boss","title":"上清观观主","name":"冲虚道长",]),
(["id":"boss","title":"玄素庄庄主黑白双剑","name":"石清",]),
(["id":"boss","title":"玄素庄庄主夫人黑白双剑","name":"闵柔","sex":1,]),
(["id":"boss","title":"丁氏双雄","name":"丁不三",]),
(["id":"boss","title":"丁氏双雄","name":"丁不四",]),
(["id":"boss","title":"八爪金龙","name":"司徒横",]),
(["id":"boss","title":"着手回春","name":"贝海石",]),
(["id":"boss","title":"铁背金獒","name":"焦公礼",]),
(["id":"boss","title":"莳花少妇","name":"石清露","sex":1,]),
(["id":"boss","title":"剑神","name":"卓不凡",]),
(["id":"boss","title":"游氏双雄","name":"游骥",]),
(["id":"boss","title":"游氏双雄","name":"游驹",]),
(["id":"boss","title":"秦家寨开山寨主","name":"秦公望",]),
(["id":"boss","title":"蓬莱派第七代掌门人","name":"海风子",]),
(["id":"boss","title":"蓬莱派第八代掌门人","name":"都灵子",]),
(["id":"boss","title":"伏牛派掌门","name":"柯百岁",]),
(["id":"boss","title":"柯百岁大弟子追魂鞭","name":"过彦之",]),
(["id":"boss","title":"金算盘","name":"崔百泉",]),
(["id":"boss","title":"幽谷客修罗刀","name":"秦红棉",]),
(["id":"boss","title":"神农帮帮主","name":"司空玄",]),
(["id":"boss","title":"鹰爪雁行门掌门","name":"汪铁鹗",]),
(["id":"boss","title":"天龙门北宗掌门人","name":"田归农",]),
(["id":"boss","title":"天龙门南宗掌门人威震天南","name":"殷吉",]),
(["id":"boss","title":"天龙门好手","name":"殷仲翔",]),
(["id":"boss","title":"天龙门掌剑双绝腾龙剑","name":"曹云奇",]),
(["id":"boss","title":"天龙门掌剑双绝回龙剑","name":"周云阳",]),
(["id":"boss","title":"天龙北宗第一高手七星手","name":"阮士中",]),
(["id":"boss","title":"毒手药王","name":"无嗔",]),
(["id":"boss","title":"毒手神枭","name":"石万嗔",]),
(["id":"boss","title":"三才剑掌门人甘霖惠七省大侠","name":"汤沛",]),
(["id":"boss","title":"黑龙门掌门人","name":"海兰弼",]),
(["id":"boss","title":"锺氏三雄","name":"锺兆文",]),
(["id":"boss","title":"锺氏三雄","name":"锺兆英",]),
(["id":"boss","title":"锺氏三雄","name":"锺兆能",]),
(["id":"boss","title":"八仙剑掌门人","name":"蓝秦",]),
(["id":"boss","title":"五虎门掌门人南霸天","name":"凤天南",]),
(["id":"boss","title":"韦陀双鹤","name":"万鹤声",]),
(["id":"boss","title":"韦陀双鹤","name":"刘鹤真",]),
(["id":"boss","title":"飞马镖局总镖头百胜神拳","name":"马行空",]),
(["id":"boss","title":"铃剑双侠","name":"汪啸风",]),
(["id":"boss","title":"崆峒五老","name":"唐文亮",]),
(["id":"boss","title":"崆峒五老","name":"宗维侠",]),
(["id":"boss","title":"崆峒五老一拳断岳","name":"常敬之",]),
(["id":"boss","title":"崆峒五老","name":"关能",]),
(["id":"boss","title":"圣手伽蓝","name":"捷远",]),
(["id":"boss","title":"神剑仙猿","name":"穆人清",]),
(["id":"boss","title":"神拳无敌","name":"归辛树",]),
(["id":"boss","title":"黄真弟子伏虎金刚","name":"崔希敏",]),
(["id":"boss","title":"归辛树三弟子五丁手","name":"刘培生",]),
(["id":"boss","title":"归辛树五弟子飞天魔女","name":"孙仲君","sex":1,]),
(["id":"boss","title":"归辛树大弟子没影子","name":"梅剑和",]),
(["id":"boss","title":"千变万劫","name":"木桑道人",]),
(["id":"boss","title":"仙都派第十代掌门祖师","name":"菊潭道长",]),
(["id":"boss","title":"仙都派第十二代掌门","name":"黄木道人",]),
(["id":"boss","title":"仙都派第十三代掌门","name":"水云道人",]),
(["id":"boss","title":"仙都派第十三代弟子","name":"闵子华",]),
(["id":"boss","title":"仙都派第十三代弟子","name":"洞玄道人",]),
(["id":"boss","title":"石梁五祖","name":"温方达",]),
(["id":"boss","title":"盖孟尝","name":"孟伯飞",]),
(["id":"boss","title":"八极拳掌门八臂哪吒","name":"秦耐之",]),
(["id":"boss","title":"三峡以西剑法第一","name":"长青子",]),
});
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

void create()
{
	mapping npc,mp,j;
	int i,k,a,b,c,d,e,f,temp;
	string sex;
	npc=data[random(8)+16];
	sex=npc["sex"];
	set_name(npc["name"]+NOR,({ npc["id"] }));
	set("title",(order[random(13)])+(npc["title"])+NOR);

if (sex)
set("gender", "女性" );
else set("gender", "男性" );
set("pubmaster",1);
        set("age", 32);
        set("str", 30);
        set("cor", 30);
        set("cps", 30);
        set("int", 30);
	set("per", 30);
        set("agi",25);
        set("dex",30);
        set("con",30);
       set("str" ,30);
       set("dex",30);
       set("int",30);
       set("per",30);
       set("kar",30);       
     set("age", 22+random(40));

	set("attitude","friendly");

        set("max_neili", 1145000);
        set("neili", 1145000);
        set("jing",118000+random(10000));
        set("max_jing",118000+random(10000));
set("eff_jing",118000+random(10000));
        set("qi",118000+random(10000));
        set("max_qi",118000+random(10000));
set("eff_qi",118000+random(10000));
 
        set_skill("parry", 490);
        set_skill("dodge", 490);
        set_skill("force", 490);
        set_skill("literate", 490);
	set_skill("sword", 490);
	set_skill("unarmed",490);
	set("combat_exp",15000000+random(5000000));
	set("magicset",1);
        set("zhuanbest",1);
        set("no_get",1);
        set("vendetta/authority",1);
        set_temp("apply/attack", 120);
        set_temp("apply/defense", 120);
        set_temp("apply/armor", 1800);
        set_temp("apply/damage", 1800);
        set("killer_reward", ([
                "FI&/clone/box/gbox"   :   8000,
                "TW&380"   :  500,
                "TA&380"   :  500,
                "RI&20"   :   500,
                "GE&3"   :  500,
                "JD&4"   :  500,
                "YC&2"   :  500,
                "WG&2"   :  500,
                "KS&3"   :   500,
                "BL&3"   :  500,
                "YW&3"   :  500,
                "YA&3"   :  500,
        ]));
	set("bonus", 8888+random(8888));

a=120000+random(60000);
b=120000+random(60000);
c=20000;
d=20+random(20);
set("str",d);
set("dex",20+d);
set("int",d);
set("con",d);
set("per",d);
set("kar",d);
        set("jing",b);
        set("max_jing",b);
set("eff_jing",b);
        set("qi",a);
        set("max_qi",a);
set("eff_qi",a);

        set("neili",c);
        set("max_neili",c);
        
        setup();
 	 initlvl(300+random(100),random(15));
}

void init( )

{
	object ob;	
        remove_call_out("hunting");
	if( interactive(ob = this_player())  ) {
ob->start_busy(1);
        call_out("hunting",0);
        }
	if(!environment()->query("no_fight"))
        call_out("hunting",0);
}

void hunting()
{
	int i;
        object *ob;
        ob = all_inventory(environment());
        for(i=sizeof(ob)-1; i>=0; i--) {
        if( !ob[i]->is_character() || ob[i]==this_object() || !living(ob[i])) continue;
        if(ob[i]->query("vendetta/authority")) continue;
                kill_ob(ob[i]);
                ob[i]->fight(this_object());
        }
}

int hit_ob(object me, object ob, int damage)
{
	if (me->is_busy()) me->start_busy(1);
me->clear_condition();	

  if ( random(me->query("combat_exp"))>(int)ob->query("combat_exp")/3)
{
if (random(10)==0)
{
ob->apply_condition("new_poison1", 5); 
}
else if (random(9)==0)
{
ob->apply_condition("new_poison2", 5); 
}
else if (random(8)==0)
{
ob->apply_condition("new_poison3", 5); 
}
else if (random(7)==0)
{
ob->apply_condition("new_poison4", 5); 
}
else if (random(6)==0)
{
ob->apply_condition("new_poison5", 5); 
}
else if (random(5)==0)
{
ob->apply_condition("new_poison6", 5); 
}
        tell_object(ob, HIG "你觉得被打中的地方闪过一阵光华！\n" NOR );
}
}
int big_blowing()
{
if (this_object()->is_busy()) this_object()->start_busy(1);
	this_object()->clear_condition();
        return 1;
}