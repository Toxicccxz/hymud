// This program is a part of NT mudlib
// boss 模板

#include <ansi.h>


inherit BOSS;

int big_blowing();

void create()
{
	set_name(HIY "黄金巨龙" NOR, ({ "yellow dragon king", "dragon king", "dragon" }) );
	set("race", "野兽");
	set("gender", "雄性");
	set("age", 20);
	set("long", 
HIY"这是一条全身金黄，在黄沙中长大的神龙！它全身散发着金黄色的光芒！\n\n"NOR);

        set("dex",100);
        set("con",100);
        set("int",100);
        set("str",100);

         set("combat_exp", 50000000);
        set("level", 50);
        set("qi", 1780000);
        set("max_qi", 1780000);
        set("jing", 1780000);
        set("max_jing", 1780000);
        set("neili", 1780000);
        set("max_neili", 1780000);
        set("jiali", 2000);

        set("chat_chance", 5);
        set("chat_msg", ({
                HIB "突然一阵黄沙卷来！差点把你卷走！\n" NOR,
                HIB "黄金巨龙突然吐出一颗金黄的珠子，又卷了回去！\n" NOR,
        }));

        set("chat_chance_combat", 50 + random(20));
        set("chat_msg_combat", ({
    (: perform_action, "unarmed.penhuo" :),
    (: perform_action, "unarmed.tuwu" :),
    (: perform_action, "unarmed.yaoyao" :),
                (: big_blowing :),
        }));

   set_temp("apply/attack", 200);
        set_temp("apply/damage", 3600);
        set_temp("apply/armor", 3600);
        set_temp("apply/defence",200);
      set_skill("dodge", 600);
      set_skill("force", 600);
      set_skill("unarmed", 600);
      set_skill("dragon",680);
      set_skill("spells",680);
     set_skill("magic-old",650);
      map_skill("unarmed", "dragon");

      map_skill("dodge", "dragon");
      map_skill("spells", "magic-old");
           set_skill("taiji-shengong",650);
      map_skill("force", "taiji-shengong");
        set_temp("apply/add_xuruo", 60);
        set_temp("apply/reduce_damage", 80);
        set_temp("apply/reduce_busy", 20);
        set_temp("apply/add_busy", 5);
        
        set("bonus", random(70000)+5000);
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
                "FI&/clone/box/gbox"   :   10000,
                "RI&10"   :   8000,
                "GE&3"   :  8000,
               "KS&3"   :   8000,
                "BL&3"   :  8000,
                "RI&30"   :   4000,
                "GE&3"   :  4000,
                "JD&4"   :  4000,
                "YC&1"   :  4000,
                "WG&1"   :  4000,
               "KS&5"   :   800,
                "BL&5"   :  800,
                "YW&3"   :  800,
                "YA&3"   :  800,
                "TW&380"   :  1000,
                "TA&380"   :  1000,
"TZ&0"   :  300,
	]));


        setup();
        carry_object("/clone/money/gold")->set_amount(200);
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

int big_blowing()
{
	if (this_object()->is_busy()) this_object()->start_busy(1);
        message_vision(HIB "$N" HIB "从黄沙里深深地吸入一口气，全身发出耀眼的金色，"
                       "整个龙腹胀大了几倍！！\n" NOR, this_object());

        remove_call_out("hurting");
        call_out("hurting", random(2) + 1);
        return 1;
}

int hurting()
{
        int dam, i , num;
        object *inv;
        
        message_vision(HIB "$N" HIB "喷出一团巨大的黄沙．．．．．．整个天地都被黄沙吞没！！！\n" NOR,
                       this_object());
                       
        inv = all_inventory(environment(this_object()));        

        num = sizeof(inv);       
        if (num < 1) num = 1;
        if (num > 5) num = 5;
        
        dam = 26000 / num;
        
        for (i=sizeof(inv)-1; i>=0; i--)
        {
                if (living(inv[i]) && inv[i] != this_object())
                {
                        dam -= inv[i]->query_temp("apply/reduce_wind");
                        if (dam <0) dam = 0;
                        
                        inv[i]->receive_wound("qi", dam);
                        inv[i]->receive_wound("jing", dam/3);
                        COMBAT_D->report_status(inv[i], 1);
                }
        }
        return 1;
}

mixed hit_ob(object me, object ob, int damage_bouns)
{
        int damage;
        
        damage = 3100 + random(3100);
        damage -= ob->query_temp("apply/reduce_cold");
        if (damage < 0) damage = 0;
        ob->receive_wound("qi", damage);
        me->set("neili", me->query("max_neili"));
        return HIB "$N" HIB "“吼”的一声吐出一片黄沙，登时令$n"
               HIB "犹如千针加身。\n" NOR;
}

