#include <ansi.h>
inherit BOSS;
int big_blowing();
#include "/quest/menpai/romnpc.c"

mapping *data=({
(["id":"boss killer","title":"五路神","name":"施令威",]),
(["id":"boss killer","title":"红花会上代总舵主","name":"于万亭",]),
(["id":"boss killer","title":"青城派","name":"慧侣道人",]),
(["id":"boss killer","title":"天池怪侠","name":"袁士霄",]),
(["id":"boss killer","title":"绵里针","name":"陆菲青","sex":1,]),
(["id":"boss killer","title":"六扇门高手魔爪孙","name":"万庆澜",]),
(["id":"boss killer","title":"大内御前侍卫一苇渡江","name":"褚圆",]),
(["id":"boss killer","title":"镖局总镖头威震河朔","name":"王维扬",]),
(["id":"boss killer","title":"当世八卦门第一高手","name":"王剑英","sex":1,]),
(["id":"boss killer","title":"天山双鹰秃鹫","name":"陈正德",]),
(["id":"boss killer","title":"天山双鹰雪雕","name":"关明梅",]),
(["id":"boss killer","title":"关东六魔五魔","name":"阎世魁",]),
(["id":"boss killer","title":"关东六魔六魔","name":"阎世章",]),
(["id":"boss killer","title":"两湖豪杰玉判官","name":"贝人龙",]),
(["id":"boss killer","title":"焦文期盟弟铁臂罗汉","name":"罗信",]),
(["id":"boss killer","title":"金刀无敌","name":"王元霸",]),
(["id":"boss killer","title":"五云手","name":"万震山",]),
(["id":"boss killer","title":"陆地神龙","name":"言达平",]),
(["id":"boss killer","title":"太行山寨主","name":"吕通",]),
(["id":"boss killer","title":"血刀门五僧之首","name":"宝象",]),
(["id":"boss killer","title":"铁骨墨萼","name":"梅念笙",]),
(["id":"boss killer","title":"铁索横江","name":"戚长发",]),
(["id":"boss killer","title":"明教教主","name":"阳顶天",]),
(["id":"boss killer","title":"鹿杖客大弟子","name":"乌旺阿普",]),
(["id":"boss killer","title":"闪电娘娘","name":"卫四娘","sex":1,]),
(["id":"boss killer","title":"乾坤一剑","name":"震山子",]),
(["id":"boss killer","title":"摩天居士","name":"谢烟客",]),
(["id":"boss killer","title":"铁胆庄庄主铁胆","name":"周仲英","sex":1,]),
(["id":"boss killer","title":"温州太极门千手如来","name":"赵半山",]),
(["id":"boss killer","title":"广平太极门掌门","name":"孙刚峰",]),
(["id":"boss killer","title":"西岳华拳门","name":"姬老三",]),
(["id":"boss killer","title":"西岳华拳门","name":"","name":"蔡威",]),
(["id":"boss killer","title":"太监总管","name":"海大富",]),
(["id":"boss killer","title":"铁背苍龙","name":"柳大洪",]),
(["id":"boss killer","title":"摇头狮子","name":"吴立身",]),
(["id":"boss killer","title":"西夏一品堂堂主","name":"李延年",]),
(["id":"boss killer","title":"雷动于九天之上","name":"九翼道人",]),
(["id":"boss killer","title":"拈花寺住持","name":"黄眉僧",]),
(["id":"boss killer","title":"波斯总教教主山中老人","name":"霍山",]),
(["id":"boss killer","title":"上清观观主","name":"冲虚道长",]),
(["id":"boss killer","title":"玄素庄庄主黑白双剑","name":"石清",]),
(["id":"boss killer","title":"玄素庄庄主夫人黑白双剑","name":"闵柔","sex":1,]),
(["id":"boss killer","title":"丁氏双雄","name":"丁不三",]),
(["id":"boss killer","title":"丁氏双雄","name":"丁不四",]),
(["id":"boss killer","title":"八爪金龙","name":"司徒横",]),
(["id":"boss killer","title":"着手回春","name":"贝海石",]),
(["id":"boss killer","title":"铁背金獒","name":"焦公礼",]),
(["id":"boss killer","title":"莳花少妇","name":"石清露","sex":1,]),
(["id":"boss killer","title":"剑神","name":"卓不凡",]),
(["id":"boss killer","title":"游氏双雄","name":"游骥",]),
(["id":"boss killer","title":"游氏双雄","name":"游驹",]),
(["id":"boss killer","title":"秦家寨开山寨主","name":"秦公望",]),
(["id":"boss killer","title":"蓬莱派第七代掌门人","name":"海风子",]),
(["id":"boss killer","title":"蓬莱派第八代掌门人","name":"都灵子",]),
(["id":"boss killer","title":"伏牛派掌门","name":"柯百岁",]),
(["id":"boss killer","title":"柯百岁大弟子追魂鞭","name":"过彦之",]),
(["id":"boss killer","title":"金算盘","name":"崔百泉",]),
(["id":"boss killer","title":"幽谷客修罗刀","name":"秦红棉",]),
(["id":"boss killer","title":"神农帮帮主","name":"司空玄",]),
(["id":"boss killer","title":"鹰爪雁行门掌门","name":"汪铁鹗",]),
(["id":"boss killer","title":"天龙门北宗掌门人","name":"田归农",]),
(["id":"boss killer","title":"天龙门南宗掌门人威震天南","name":"殷吉",]),
(["id":"boss killer","title":"天龙门好手","name":"殷仲翔",]),
(["id":"boss killer","title":"天龙门掌剑双绝腾龙剑","name":"曹云奇",]),
(["id":"boss killer","title":"天龙门掌剑双绝回龙剑","name":"周云阳",]),
(["id":"boss killer","title":"天龙北宗第一高手七星手","name":"阮士中",]),
(["id":"boss killer","title":"毒手药王","name":"无嗔",]),
(["id":"boss killer","title":"毒手神枭","name":"石万嗔",]),
(["id":"boss killer","title":"三才剑掌门人甘霖惠七省大侠","name":"汤沛",]),
(["id":"boss killer","title":"黑龙门掌门人","name":"海兰弼",]),
(["id":"boss killer","title":"锺氏三雄","name":"锺兆文",]),
(["id":"boss killer","title":"锺氏三雄","name":"锺兆英",]),
(["id":"boss killer","title":"锺氏三雄","name":"锺兆能",]),
(["id":"boss killer","title":"八仙剑掌门人","name":"蓝秦",]),
(["id":"boss killer","title":"五虎门掌门人南霸天","name":"凤天南",]),
(["id":"boss killer","title":"韦陀双鹤","name":"万鹤声",]),
(["id":"boss killer","title":"韦陀双鹤","name":"刘鹤真",]),
(["id":"boss killer","title":"飞马镖局总镖头百胜神拳","name":"马行空",]),
(["id":"boss killer","title":"铃剑双侠","name":"汪啸风",]),
(["id":"boss killer","title":"崆峒五老","name":"唐文亮",]),
(["id":"boss killer","title":"崆峒五老","name":"宗维侠",]),
(["id":"boss killer","title":"崆峒五老一拳断岳","name":"常敬之",]),
(["id":"boss killer","title":"崆峒五老","name":"关能",]),
(["id":"boss killer","title":"圣手伽蓝","name":"捷远",]),
(["id":"boss killer","title":"神剑仙猿","name":"穆人清",]),
(["id":"boss killer","title":"神拳无敌","name":"归辛树",]),
(["id":"boss killer","title":"黄真弟子伏虎金刚","name":"崔希敏",]),
(["id":"boss killer","title":"归辛树三弟子五丁手","name":"刘培生",]),
(["id":"boss killer","title":"归辛树五弟子飞天魔女","name":"孙仲君","sex":1,]),
(["id":"boss killer","title":"归辛树大弟子没影子","name":"梅剑和",]),
(["id":"boss killer","title":"千变万劫","name":"木桑道人",]),
(["id":"boss killer","title":"仙都派第十代掌门祖师","name":"菊潭道长",]),
(["id":"boss killer","title":"仙都派第十二代掌门","name":"黄木道人",]),
(["id":"boss killer","title":"仙都派第十三代掌门","name":"水云道人",]),
(["id":"boss killer","title":"仙都派第十三代弟子","name":"闵子华",]),
(["id":"boss killer","title":"仙都派第十三代弟子","name":"洞玄道人",]),
(["id":"boss killer","title":"石梁五祖","name":"温方达",]),
(["id":"boss killer","title":"盖孟尝","name":"孟伯飞",]),
(["id":"boss killer","title":"八极拳掌门八臂哪吒","name":"秦耐之",]),
(["id":"boss killer","title":"三峡以西剑法第一","name":"长青子",]),
});
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

void create()
{
	mapping npc,mp,j;
	int i,k,a,b,c,d,e,f,temp;
	string sex;
	npc=data[random(8)+56];
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
set("isteamjob",1);
        set("max_neili", 1145000);
        set("neili", 1145000);
        set("jing",118000+random(10000));
        set("max_jing",118000+random(10000));
set("eff_jing",118000+random(10000));
        set("qi",118000+random(10000));
        set("max_qi",118000+random(10000));
set("eff_qi",118000+random(10000));
 
        set_skill("parry", 420);
        set_skill("dodge", 420);
        set_skill("force", 420);
        set_skill("literate", 420);
	set_skill("sword", 420);
	set_skill("unarmed",420);
	set("combat_exp",1000000+random(2000000));
	set("magicset",1);
        set("zhuanbest",1);
        set("no_get",1);
        //set("vendetta/authority",1);
        if (random(2)==0)
        {
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 2800);
        set_temp("apply/damage", 2800);
}
        set("killer_reward", ([
                "FI&/clone/box/gbox"   :   6000,
                "TW&480"   :  300,
                "TA&480"   :  300,
                "RI&40"   :   300,
                "GE&3"   :  300,
                "JD&3"   :  300,
                "YC&3"   :  300,
                "WG&3"   :  300,
                "KS&3"   :   300,
                "BL&3"   :  300,
                "YW&3"   :  300,
                "YA&3"   :  300,
        ]));
	set("bonus", 5888+random(5888));

a=270000+random(80000);
b=270000+random(80000);
c=50000;
d=35+random(35);
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
 	 initlvl(550+random(100));
}

void init()
{
        remove_call_out("leave");
        call_out("leave",300);
}

void leave()
{
        object ob = this_object();
        if (!ob->is_fighting()) {
                message_vision(this_object()->query("name") + "钻进路边的杂草，不见了。\n" NOR,this_object());
                destruct(this_object());
                }
        else call_out("leave",30);
}
int do_back(object me)
{                       
        me = this_object();
  tell_room(environment(me), me->query("name")+"匆匆忙忙的离开了。\n", ({me}));	
  destruct(me); 
  return 1;
}
void die()
{
int i,pot,exp;
	object killer;
	exp= random(60)+30;
	pot= exp*2/3;
	if(objectp(killer = query_temp("last_damage_from")))
{
        	tell_object(killer,"你战败了高强的敌人！。\n");
       killer->add("mpgx",1);	
}
	::die();

return ;
}