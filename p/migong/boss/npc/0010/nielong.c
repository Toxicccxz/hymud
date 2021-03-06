// This program is a part of NT mudlib
// boss 模板

#include <ansi.h>

inherit BOSS;

int big_blowing();

void create()
{
	set_name(HIR "九爪孽龙" NOR, ({ "jiuzhao nielong", "nielong", "nie long" }) );
	set("race", "野兽");
	set("gender", "雄性");
	set("age", 20);
	set("long", 
HIR"这是一条全身赤红，吸天地之间的火气而长大的孽龙！它全身散发着赤红色的火焰！\n\n"NOR);

        set("dex",100);
        set("con",100);
        set("int",100);
        set("str",100);

        set("combat_exp", 90000000);
        set("level", 10);
        set("qi", 2200000);
        set("max_qi", 2200000);
        set("jing", 2200000);
        set("max_jing", 2200000);
        set("neili", 2000000);
        set("max_neili", 2000000);
        set("neili", 4000000);
        set("jiali", 1000);

        set("chat_chance", 5);
        set("chat_msg", ({
                HIB "一团火焰卷了过来！差点把你烧成灰！\n" NOR,
                HIB "九爪孽龙突然吐出一团赤红的火焰！\n" NOR,
        }));

  set_skill("dodge", 800);
      set_skill("force", 800);
      set_skill("unarmed", 800);
      set_skill("dragon",850);
      set_skill("spells",850);
     set_skill("magic-old",850);
      map_skill("unarmed", "dragon");
     set_skill("taiji-shengong",1250);
      map_skill("force", "taiji-shengong");
      map_skill("dodge", "dragon");
      map_skill("spells", "magic-old");
        set("chat_chance_combat", 70);
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
        
        // 物品奖励
	        set("bonus", random(90000)+5000);
	set("killer_reward", ([
                "FI&/clone/box/gbox"   :   10000,
                "RI&10"   :   8000,
                "GE&3"   :  8000,
               "KS&3"   :   8000,
                "BL&3"   :  8000,
                "RI&60"   :   5000,
                "GE&5"   :  5000,
                "JD&6"   :  5000,
                "YC&4"   :  5000,
                "WG&4"   :  5000,
               "KS&6"   :   500,
                "BL&6"   :  500,
                "YW&5"   :  500,
                "YA&5"   :  500,
                "TW&480"   :  1000,
                "TA&480"   :  1000,
"TZ&0"   :  600,
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
        message_vision(HIB "$N" HIB "从火焰里深深地吸入一口火气，全身转为鲜红的火色，"
                       "整个龙腹胀大了几倍！！\n" NOR, this_object());

        remove_call_out("hurting");
        call_out("hurting", random(2) + 1);
        return 1;
}

int hurting()
{
        int dam, i , num;
        object *inv;
        
        message_vision(HIB "$N" HIB "吐出一股炽可焚金的火焰．．．．．．整个天地似乎都被燃烧着！！！\n" NOR,
                       this_object());
                       
        inv = all_inventory(environment(this_object()));        

        num = sizeof(inv);       
        if (num < 1) num = 1;
        if (num > 5) num = 5;
        
        dam = 28000 / num;
        
        for (i=sizeof(inv)-1; i>=0; i--)
        {
                if (living(inv[i]) && inv[i] != this_object())
                {
                        dam -= inv[i]->query_temp("apply/reduce_fire");
                        if (dam <0) dam = 0;
                        inv[i]->start_busy(2);
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
        
        damage = 3500 + random(3500);
        damage -= ob->query_temp("apply/reduce_cold");
        if (damage < 0) damage = 0;
        ob->receive_wound("qi", damage);
        me->set("neili", me->query("max_neili"));
        return HIB "$N" HIB "“哈”的一声吐出一团火球，登时令$n"
               HIB "浑身都被烧伤。\n" NOR;
}

