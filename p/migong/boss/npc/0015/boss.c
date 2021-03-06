// This program is a part of NT mudlib
// boss 模板

#include <ansi.h>

inherit BOSS;
//inherit  NPC;
#include "/d/migong/romnpc.c"
int boss_attack();

void create()
{
	set_name( HIB "逍遥侯" NOR, ({ "xiaoyao hou", "xiaoyaohou", "boss" }) );
	set("long", HIB "他就是武林侏儒逍遥了，变态心理，精通各派武功和绝技"
	"喜欢戏弄、折磨天下武林高手 以杀人为乐！。\n\n" NOR);
	
	set("gender",  "男性");
	set("age", 60);
	set("no_get", 1);
	set("shen_type", -1);
	set("attitude", "aggressive");
	
	set("dex",150);
	set("con",150);
	set("int",150);
	set("str",150);
	
	set("combat_exp", 10000000);
	set("level", 15);
	set("qi", 1500000);
	set("max_qi", 1500000);
	set("jing", 1500000);
	set("max_jing", 1500000);
	set("neili", 700000);
	set("max_neili", 700000);
	set("neili", 700000);
	set("jiali", 500);
	
	set("chat_chance", 5);
	set("chat_msg", ({
	        HIB "逍遥侯指着你说，来试试我的玩偶阵吧！\n" NOR,
	}));
	
	set_temp("apply/attack", 600);
	set_temp("apply/damage", 1800);
	set_temp("apply/armor", 2800);
	set_temp("apply/defence",600);

	set_skill("dodge", 850);
	set_skill("force", 850);
	set_skill("unarmed", 850);
	set_skill("parry", 850); 
	set_skill("sword",850);
	set_skill("sharen-sword",800);
	set_skill("changquan",800);
	set_skill("shadowsteps",800);
	set_skill("cloudforce",800);
	map_skill("force", "cloudforce");
	map_skill("sword", "sharen-sword");
	map_skill("dodge", "shadowsteps");
	map_skill("parry", "changquan");
	map_skill("unarmed", "changquan");

	set("chat_chance_combat", 40);
	set("chat_msg_combat", ({
	(: perform_action, "sword.sharenruma" :),
	(: perform_action, "unarmed.yuhuan" :),
	        (: boss_attack :),
	}));
	
    set_temp("apply/reduce_damage", 40);
    set_temp("apply/reduce_busy", 10);
    set_temp("apply/add_busy", 2);
  	set("bonus", random(12000)+1200);
// 物品奖励 说明
// 掉落概率 10000为最大,必掉,5000为1/2机会,数字越小,掉落的可能越少.
// 掉落阵列关键字以 FI 起头表示为掉落某个特定物品
// 掉落阵列关键字以 RI  起头表示为掉落某个戒指 %d为等级(10-60) 
// 掉落阵列关键字以 GE 起头表示为掉落某个宝石 %d为等级(1-8)
// 掉落阵列关键字以 JD 起头表示为掉落某个打造用升级宝石 %d为等级(1-8)
// 掉落阵列关键字以 YC 起头表示为掉落药材 %d为无效参数("随机等级无效)
// 掉落阵列关键字以 WG 起头表示为掉落宝物装备 %d为无效参数
// 掉落阵列关键字以 KS 起头表示为掉落打造用矿石 %d为等级(1-10)
// 掉落阵列关键字以 BL 起头表示为掉落打造用布料 %d为等级(1-10)
// 掉落阵列关键字以 YW 起头表示为掉落打造武器用玉石 %d为等级(1-6)
// 掉落阵列关键字以 YA 起头表示为掉落打造防具用玉石 %d为等级(1-6)
// 掉落阵列关键字以 YW 起头表示为掉落打造武器用玉石 %d为等级(1-6)
// 掉落阵列关键字以 TW 起头表示为掉落打造武器 %d为等级 (0-480)
// 掉落阵列关键字以 TA 起头表示为掉落打造防具 %d为等级(0-480)


	set("killer_reward", ([
                "FI&/clone/box/gbox"   :   8000,
                "RI&10"   :   8000,
                "GE&4"   :  8000,
               "KS&3"   :   8000,
                "BL&3"   :  3000,
                "RI&30"   :   3000,
                "GE&3"   :  3000,
                "JD&4"   :  2000,
                "YC&1"   :  2000,
                "WG&1"   :  2000,
               "KS&5"   :   500,
                "BL&5"   :  500,
                "YW&3"   :  500,
                "YA&3"   :  500,
                "TW&180"   :  900,
                "TA&180"   :  900,
"TZ&0"   :  350,
	]));
	
    setup();
if (random(2)==0) initlvl(500+random(300));    
    carry_object("/clone/money/gold")->set_amount(30+random(420));
	carry_object(__DIR__"obj/cloth")->wear();
	//carry_object(__DIR__"obj/changjian")->wield();
}

void init()
{
	object me, ob;
	
	::init();
	set("nickname",HIR"武林侏儒"NOR);
	if (! interactive(me = this_player()))
	        return;
	
	if( !me->is_character() || me==this_object() || !me) return;
	if(me->query("vendetta/authority")) return;
	if(!userp(me)) return;
	
	remove_call_out("kill_ob");
	call_out("kill_ob", 0, me);
}

varargs void start_busy(mixed new_busy, mixed new_interrupt)
{
        return;
}

int boss_attack()
{
	if (this_object()->is_busy()) return 1;
	if (!this_object()->is_busy()) this_object()->start_busy(2);
	message_vision(HIB "$N" HIB "袍袖一挥，大喝一声：布阵！！ \n" NOR, this_object());
	
	remove_call_out("hurting");
	call_out("hurting", 0);
	return 1;
}

int hurting()
{
        int dam, i , num, busytime;
        object *inv;
        
        message_vision(HIB "玩偶阵启动，周转风景突变，天气也发生了变化"
       "使人不由自主产生种种错觉，以为自己也被魔法缩小，变成了玩偶人。\n" NOR,
                       this_object());
                       
        inv = all_inventory(environment(this_object()));        

        num = sizeof(inv);       
        if (num < 1) num = 1;
        if (num > 5) num = 5;
        
        dam = 10000 / num;
        busytime = 10 / num;
        
        for (i=sizeof(inv)-1; i>=0; i--)
        {
                if (living(inv[i]) && inv[i] != this_object())
                {                        
                      dam -= inv[i]->query_temp("apply/reduce_damage");
                      if (dam <0) dam = 0;
                      inv[i]->receive_damage("qi", dam);
                      inv[i]->receive_damage("jing", dam/3);
                      inv[i]->receive_wound("qi", dam);
                      inv[i]->receive_wound("jing", dam/3);
                      COMBAT_D->report_status(inv[i], 1);
                      if (!inv[i]->is_busy()) busytime -= inv[i]->query_temp("apply/reduce_busy");
                      if (busytime>0) inv[i]->start_busy(busytime);
                }
        }
        return 1;
}

mixed hit_ob(object me, object ob, int damage_bouns)
{
	int damage;
  	damage = 600 + random(600);
	ob->receive_wound("qi", damage);
  if (ob->query("neili",1)>1000)  ob->add("neili",-random(500));
	return "$N一招打中$n的顶门大穴，"HIB "$n" HIB "只觉真气外泄，人也变得昏昏沉沉，快晕倒了！\n" NOR;
}

