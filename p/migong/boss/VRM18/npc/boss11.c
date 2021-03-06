#include <ansi.h>

inherit BOSS;
int boss_attack();
int boss_attack2();
int hurting();
int hurting1();
int hurting2();
int boss_hurting();
int boss_hurt();
int boss_init();
int boss_removedam();

void create()
{
	set_name( HIY "英招" NOR, ({ "ying zhao", "shenshou", "boss" }) );
	set("long", HIY "人面马身，有虎纹，生鸟翼，声音如榴"
		"号称是替天帝看花园的神，但看起来充其量不过是只神兽而已。\n\n" NOR);
set("nickname",HIR"上古神兽"NOR);	
	set("race", "野兽");
	set("gender", "雄性");
	set("age", 3000);
	set("no_get", 1);
	set("shen_type", -1);
	set("attitude", "aggressive");
	
	set("dex",400);
	set("con",400);
	set("int",400);
	set("str",400);
	
	set("combat_exp", 100000000);
	set("level", 18);
		set("qi", 3500000);
		set("max_qi", 3500000);
		set("jing", 3500000);
		set("max_jing", 3500000);
		set("neili", 3000000);
		set("max_neili", 3000000);
		set("jiali", 20000);
	
	set_skill("dodge", 1200);
	set_skill("force", 1200);
	set_skill("unarmed", 1200);
	set_skill("dragon",1250);
	set_skill("spells",1250);
	set_skill("magic-old",1250);
	map_skill("unarmed", "dragon");
	set("vendetta/authority",1);
	map_skill("dodge", "dragon");
	map_skill("spells", "magic-old");
	      set_skill("taiji-shengong", 800);
      map_skill("force", "taiji-shengong");
	set("chat_chance_combat", 90);
	set("chat_msg_combat", ({
		(: perform_action, "unarmed.penhuo" :),
		(: perform_action, "unarmed.tuwu" :),
		(: perform_action, "unarmed.yaoyao" :),
			(: boss_attack2 :),
			(: boss_attack2 :),
			(: boss_attack2 :),

	}));
			set_temp("bossdamage",0);
	set_temp("apply/dodge", 200);
	set_temp("apply/attack", 200);
	set_temp("apply/damage", 6600);
	set_temp("apply/armor", 6600);
	set_temp("apply/defence",200);
	
	// 物品奖励
	set("bonus", random(15000)+15000);
	set("killer_reward", ([
		"FI&/clone/box/gbox"   :   10000,
		"RI&10"   :   8000,
		"GE&5"   :  8000,
		"KS&3"   :   8000,
		"BL&3"   :  8000,
		"RI&60"   :   5000,
		"GE&6"   :  5000,
		"JD&7"   :  5000,
		"YC&4"   :  5000,
		"WG&4"   :  5000,
		"KS&7"   :  2600,
		"BL&8"   :  2600,
		"YW&5"   :  2600,
		"YA&5"   :  2600,
		"TW&300"   :  2000,
		"TA&300"   :  2000,
	  "TZ&0"   :  1600,	
		"TZ&1"   :  1300,		
	]));
	
	setup();
	carry_object("/clone/money/gold")->set_amount(random(500)+100);
}


void init( )

{
	object ob;	
        remove_call_out("hunting");
	if( interactive(ob = this_player())  ) {
ob->start_busy(2);
this_object()->delete_temp("boss_attack2");
        call_out("hunting",0);
	message_vision(HIB "$N" HIG "人为财死，鸟为食亡，又有人为了看不见摸不着的宝物来送死了！！ \n" NOR, this_object());

        }
this_object()->delete_temp("boss_attack2");
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


int boss_init()
{	
	message_vision(HIB "$N" HIG "人为财死，鸟为食亡，又有人为了看不见摸不着的宝物来送死了！！ \n" NOR, this_object());
		//remove_call_out("boss_hurting");
		//call_out("boss_hurting", 3); // 每三秒检查一次
		//remove_call_out("boss_attack");
		//call_out("boss_attack", 10); // 战斗10秒后施放特殊技能
//return 1;
}

int boss_attack2()
{	
if (!this_object()->query_temp("boss_attack2"))
{
message_vision(HIB "$N" HIR "进入战斗姿态,挥动双翼，飞上天空！！ \n" NOR, this_object());
//	remove_call_out("boss_hurt");
//call_out("boss_hurt", 3,this_object());
		remove_call_out("boss_hurting");
		call_out("boss_hurting", 3); // 每三秒检查一次
		remove_call_out("boss_attack");
		call_out("boss_attack", 6); // 战斗10秒后施放特殊技能
this_object()->set_temp("boss_attack2",1);
}
	return 1;
}

int boss_hurting()
{

	if( ((int)this_object()->query("eff_qi") < (int)this_object()->query("max_qi") / 5 )||((int)this_object()->query("eff_jing") < (int)this_object()->query("max_jing") / 5 ))
	{
		//少于20%气血或者精气的时候狂暴
		remove_call_out("hurting2");
		call_out("hurting2", 0, this_object());
	}

	remove_call_out("boss_hurting");
	call_out("boss_hurting", 3, this_object()); // 每三秒检查一次



	return 1;
}

int boss_attack()
{	
	message_vision(HIY "$N" HIY "挥动双翼，飞上天空，口中念念有词，祈祷上天的力量！！ \n" NOR, this_object());
	remove_call_out("boss_hurt");
	call_out("boss_hurt", 3,this_object());
	return 1;
}

int boss_hurt()
{
	if (this_object()->is_busy()) 
	{
		//busy时施放另外一种技能

		remove_call_out("hurting1");
		call_out("hurting1", 0, this_object()); 
	}
	else
	{
		remove_call_out("hurting");
		call_out("hurting", 0,this_object());
	}
	return 1;
}

int hurting()
{
	int dam, dam1,i , num;
	object *inv;
	
	message_vision(HIY "突然间狂风大作，周转风景突变，天气也发生了变化"
		"风大的使人想站都站不稳，即使使出千斤坠，也感觉快被狂风卷走。\n" NOR,
	this_object());
	
	inv = all_inventory(environment(this_object()));        
	
	num = sizeof(inv);       
	if (num < 1) num = 1;
	if (num > 5) num = 5;
	
	dam = 19000 / num;
	if (this_object()->query_temp("bossdamage")==1)
	{
		dam = dam * 2;//光环存在就伤害加倍
	}

	set_temp("bossdamage",1);//命中后有伤害光环，下次伤害加倍。
	remove_call_out("boss_removedam");
	call_out("boss_removedam", 40, this_object()); 

	for (i=sizeof(inv)-1; i>=0; i--)
	{
		if (living(inv[i]) && inv[i] != this_object() && inv[i]->is_fighting(this_object()))
		{                        
			dam1 = dam - inv[i]->query_temp("apply/reduce_damage");
			if (dam1 <0) dam1 = 0;
			inv[i]->apply_condition("new_poison3", 3);
			inv[i]->receive_damage("qi", dam1); //不考虑减伤的话，伤害最低也有3000（组队情况下，不组队伤害单独承受）
			inv[i]->receive_damage("jing", dam1/3);  //不考虑减伤的话，伤害最低也有1000（组队情况下，不组队伤害单独承受），主要伤气血，精气来源不多
			inv[i]->receive_wound("qi", dam1);
			inv[i]->receive_wound("jing", dam1/3);
			COMBAT_D->report_status(inv[i], 1);
		}
	}
	//30秒后继续施放特殊技能
	remove_call_out("boss_attack");
	call_out("boss_attack", 20, this_object()); 
	
	return 1;
}

int boss_removedam()
{
	set_temp("bossdamage",0);
}

int hurting1()
{
	int i , num,busy_time,busy_time1;
	object *inv;
	
	message_vision(HIR "霎时间天空乌云密布，电闪雷鸣，瓢泼大雨倾盆而下"
		"风雨中，英招突然被一层红色光环笼罩，别的好像什么都看不清楚了\n" NOR,
	this_object());
	
	inv = all_inventory(environment(this_object()));        
	
	num = sizeof(inv);       
	busy_time = 10 / num;//组队的人越多，busy越短
	
	for (i=sizeof(inv)-1; i>=0; i--)
	{
		if (living(inv[i]) && inv[i] != this_object() && inv[i]->is_fighting(this_object()))
		{                        
			busy_time1 = busy_time -  inv[i]->query_temp("apply/reduce_busy");
			if (busy_time1>0) inv[i]->start_busy(busy_time);
		}
	}
	
	message_vision(HIB "$N" HIB "缓缓落下，身上的光环似乎又恢复了它少许战斗力！！ \n" NOR, this_object());
	//恢复%2的状态
        this_object()->receive_curing("qi", this_object()->query("max_qi")/100);
        this_object()->receive_curing("jing", this_object()->query("max_jing")/100);

	//30秒后继续施放特殊技能
	remove_call_out("boss_attack");
	call_out("boss_attack", 30, this_object()); 
	
	return 1;
}

int hurting2()
{
	int i , num;
	object *inv;
	
	inv = all_inventory(environment(this_object()));        
	//this_object()->delete_temp("boss_hurting");
	message_vision(HIY "$N" HIY "逐渐开始不耐烦了，念起咒语，你好像觉得自己的体力在一点一点消失！！ \n" NOR, this_object());
	//狂暴模式下每三秒掉10%
	for (i=sizeof(inv)-1; i>=0; i--)
	{
		if (living(inv[i]) && inv[i] != this_object() && inv[i]->is_fighting(this_object()))
		{                       
			inv[i]->apply_condition("new_poison3", 3);
			inv[i]->receive_damage("qi", inv[i]->query("max_qi")/10); 
			inv[i]->receive_damage("jing", inv[i]->query("max_jing")/10);  
			inv[i]->receive_wound("qi", inv[i]->query("max_qi")/10);
			inv[i]->receive_wound("jing", inv[i]->query("max_jing")/10);	
			//有光环伤害加倍。
			if (this_object()->query_temp("bossdamage")==1)
			{
				inv[i]->receive_damage("qi", inv[i]->query("max_qi")/10); 
				inv[i]->receive_damage("jing", inv[i]->query("max_jing")/10);  
				inv[i]->receive_wound("qi", inv[i]->query("max_qi")/10);
				inv[i]->receive_wound("jing", inv[i]->query("max_jing")/10);	
			}
		}
	}	
	return 1;
}

int hit_ob(object me, object ob, int damage)
{
  if ( random(me->query("combat_exp"))>(int)ob->query("combat_exp")/3)
{
        ob->apply_condition("new_poison3", 3);
        tell_object(ob, HIR "你觉得被打中的地方闪过一阵光华！\n" NOR );
}
}
