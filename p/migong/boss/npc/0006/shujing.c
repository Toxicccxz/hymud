#include <ansi.h>

inherit BOSS;

int showpower1();
int showpower2();
int combatpower();
int powerup();

void create()
{
	set_name("千年树精", ({ "qiannian shujing", "shujing", "shu jing" }) );
	set("name_color","HIG");
	set("gender", "男性");
	set("age", 22);
	set("long", 
HIG"这是一个成了精的老榕树，常年餐风饮露！\n\n"NOR);
        
	set("str", 148);
	set("con", 152);
	set("dex", 122);

	set("max_qi", 1825000);
	set("max_jing", 1825000);
	set("qi", 1825000);
	set("jing", 1825000);
set("combat_exp", 50000000);

	set("max_neili",320000);
	set("neili",320000);
	set("attitude", "aggressive");
	set("limbs", ({ "头部", "身体", "尾巴" }) );
	set("verbs", ({ "bite", "claw" }) );

        set("chat_chance", 5);
        set("chat_msg", ({
        	(: showpower1 :) ,
        	(: showpower2 :)
        }) );    
	
	



set_skill("zhuihun-biao", 680);
		set_skill("liuxing-biao", 680);
	set_skill("pili-biao",380);
	set_skill("force", 350);
	set_skill("biyun-xinfa", 680);
	set_skill("dodge", 350);
	set_skill("qiulinshiye", 680);
	set_skill("strike", 250);
	set_skill("unarmed",280);
	set_skill("biye-wu", 680);
	set_skill("parry", 280);
	set_skill("throwing", 680);
	set_skill("zimu-zhen", 680);
	set_skill("literate", 250);
	
	set_skill("dusha-zhang", 680);
	set_skill("lansha-shou", 680);
	set_skill("hand", 680);
	set_skill("strike", 680);
	map_skill("strike", "dusha-zhang");
	map_skill("hand", "lansha-shou");
	map_skill("force", "biyun-xinfa");
	map_skill("dodge", "qiulinshiye");
	map_skill("strike", "dusha-zhang");
	map_skill("unarmed","biye-wu");
	map_skill("parry", "biye-wu");
	map_skill("throwing", "zimu-zhen");
	map_skill("strike", "dusha-zhang");
	map_skill("hand", "lansha-shou");
	
	
	     set_skill("taiji-shengong",650);
      map_skill("force", "taiji-shengong");
	
	prepare_skill("strike", "dusha-zhang");
	prepare_skill("hand", "lansha-shou");
	
	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(: combatpower :),
				(: combatpower :),
						(: combatpower :),		
		(: perform_action, "throwing.poqizhen" :),
		(: perform_action, "throwing.dinhun" :),
(: perform_action, "throwing.qizigangbiao" :),
      (: perform_action, "throwing.tanghua" :),
		(: perform_action, "parry.wandu" :),
		(: perform_action, "parry.meng" :),
		(: perform_action, "strike.tianxie" :),
		(: perform_action, "strike.hantian" :),
		(: perform_action, "hand.canglong" :),
		(: perform_action, "hand.xiangyi" :),
		(: perform_action, "hand.luanpo" :),									
						
	}) );
	

	//set("combat_exp", 2000000+random(2000000));
        
	set_temp("apply/attack", 20+random(10));
	set_temp("apply/damage",2220+random(10));
	set_temp("apply/armor", 2220+random(10));
	
	set("bonus", 63000);
        // 物品奖励
	        set("bonus", random(100000)+5000);
	set("killer_reward", ([
                "FI&/clone/box/gbox"   :   10000,
                "RI&10"   :   8000,
                "GE&3"   :  8000,
               "KS&3"   :   8000,
                "BL&3"   :  8000,
                "RI&40"   :   3000,
                "GE&5"   :  3000,
                "JD&6"   :  3000,
                "YC&3"   :  3000,
                "WG&3"   :  3000,
               "KS&6"   :   500,
                "BL&6"   :  400,
                "YW&5"   :  400,
                "YA&5"   :  400,
                "TW&380"   :  1000,
                "TA&380"   :  1000,
"TZ&0"   :  400,
	]));


	setup();
	carry_object("/clone/money/gold")->set_amount(300);
	carry_object("/d/tangmen/obj/zimuzhen")->wield();
	// init_npc(this_object(), 6, 13, 0, 100);
// 自动配置NPC属性和技能，第一个参数必须。
// 第一个参数为NPC的OB
// 第二个参数为NPC的门派，1普陀2地府3方寸4月宫5雪山6五庄7龙宫8无底洞其他为基本，不设置为随机门派
// 第三个参数为NPC的技能，按NPC的等级设置(1:50)，缺省或0为不设置
// 第四个参数为NPC的属性和状态等级，按NPC的等级设置，缺省或0为不设置
// 第五个参数为NPC的强度，缺省为100
}

void init()
{
        object me, ob;

        ::init();
        if (! interactive(me = this_player()))
                return;
        
        if( !me->is_character() || me==this_object() || !me) return;
        if(me->query("vendetta/authority")) return;
        if(!userp(me)) return;
        
        remove_call_out("kill_ob");
        call_out("kill_ob", 0, me);
}

int showpower1()
{
	tell_object(environment(this_object()),HIG"\t林中吹来一阵阴风！差点把你卷走！\n"NOR);
	return 1;
}
int showpower2()
{
	tell_object(environment(this_object()),HIG"\t千年树精突然伸出一根根树枝向你卷了过来！\n"NOR);
	return 1;
}

int combatpower()
{
	if (this_object()->is_busy()) this_object()->start_busy(1);
	message_vision( HIG"\n$N全身发出“咯吱咯吱”的巨响，伸出树枝向你卷了过来！！\n" NOR,this_object());
	remove_call_out("powerup");
	call_out("powerup",random(10)+2);
	return 1;
}

int powerup()
{
	int dam, i , num;
	object *inv;
	message_vision( HIG"\n$N全身晃动．．．．．．整个大地都似乎被掀了起来，你足下一个不稳，差点跌在地上！！！\n",this_object());
        inv = all_inventory(environment(this_object()));
        num = sizeof(inv);
        if (num < 1) num = 1;
        if (num > 5) num = 5;
        dam = 26000 / num;
        for(i=sizeof(inv)-1; i>=0; i--)
        {
        	if( living(inv[i]) && inv[i] != this_object() )
        	{
        		//dam = dam - inv[i]->query_combat_level("DF_spells");
        		if(dam <0) dam = 0;
        		inv[i]->receive_wound("qi", dam);
        		inv[i]->receive_wound("jing", dam/3);
        		COMBAT_D->report_status(inv[i],1);
        	}
        }
        return 1;
}

