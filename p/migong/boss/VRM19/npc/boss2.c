#include <ansi.h>
inherit BOSS;
int big_blowing();
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""HIC"", ""HIC"", ""HIW"", ""HIC"",""HIC"", ""CYN"",""WHT"",""HIM"",""BLU""});


void create()

{
	mapping npc,mp,j;
	int i,k,a,b,c,d,e,f,temp;
   set_name(order[random(13)]+"希爾芙"NOR, ({ "sylph"}));
if (random(2)==0)
	set("magicgift",3);
else 	set("magicgift",4);
	set("magicset",1);
       set("title",HIC"风之精灵王"NOR);
       set("zhuanbest",1);
       set("long",
"一位可怕的风之精灵王。\n");
              set("attitude", "aggressive");
                set("vendetta/authority",1);
	       set("max_qi",500+random(500));
	set("combat_exp",45000000+random(8000000));
        set_skill("force",1250+random(300));
	set_skill("unarmed",1250+random(300));
	set_skill("sword",1250+random(300));
	set_skill("club",1250+random(300));
	set_skill("whip",1250+random(300));
	set_skill("throwing",1250+random(300));
	set_skill("parry",1250+random(300));
set_skill("spells",1200+random(300));
      set_skill("magic-unarmed", 1200+random(300));
      set_skill("magic-sword", 1200+random(200));
      set_skill("magic-earth", 1260+random(200));
      set_skill("magic-water", 1200+random(300));
      set_skill("magic-ice", 1260+random(200));
      map_skill("sword", "magic-sword");
      map_skill("unarmed", "magic-unarmed");
      map_skill("parry", "magic-unarmed");
map_skill("spells", "magic-ice");
      set_skill("taiji-shengong", 800);
      map_skill("force", "taiji-shengong");
        set("no_get",1);
	set_skill("force",1250+random(300));
	set_skill("huntian-qigong",1250+random(300));
	map_skill("force", "huntian-qigong");
b=4318000+random(968000);
a=4348000+random(968000);
d=118+random(80);
set("str",d);
set("dex",30+d);
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

        set("neili",a);
        set("max_neili",a);
       
    set("age", 15);

        set("shen_type", -1);

        set("intellgent",1);

	set("pursuer",1);
	set_temp("apply/attack",250);
	set_temp("apply/defense",250);
	set_temp("apply/armor",6600);
	set_temp("apply/damage",6600);


        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
               (: perform_action, "spells.invisibility" :),
               (: perform_action, "spells.lightningball" :),
               (: perform_action, "spells.resistance" :),
               (: perform_action, "spells.implosion" :),
               (: perform_action, "spells.lightningbolt" :),
               (: perform_action, "spells.stun" :),                                                            
               (: perform_action, "spells.summon" :),                                                            
               (: perform_action, "spells.holylightning" :),                                                            
                (: big_blowing :),
                (: big_blowing :), 
        }) );
// 物品奖励
	        set("bonus", random(100000)+9900);
	set("killer_reward", ([
                "/clone/magic/obj/armor14"   :   1500,
                "FI&/clone/box/gbox"   :   10000,
                "RI&10"   :   8000,
                "GE&4"   :  8000,
               "KS&5"   :   8000,
                "BL&5"   :  8000,
                "RI&60"   :   6000,
                "GE&6"   :  6000,
                "JD&7"   :  6000,
                "YC&4"   :  6000,
                "WG&4"   :  6000,
                "KS&7"   :  4000,
                "BL&8"   :  4000,
                "YW&5"   :  4000,
                "YA&5"   :  4000,
                "TW&480"   :  3000,
                "TA&480"   :  3000,
               "TZ&0"   :  1500,
               "TZ&1"   :  1300,
               "TZ&2"   :  1100,	
	]));

   setup();

carry_object(__DIR__"obj/sword")->wield();
carry_object(__DIR__"obj/cloth")->wear();
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

int big_blowing()
{
        message_vision(CYN "$N" CYN "从天空中的风中,吸取了风之力量，"
                       "天空中卷起了龙卷风！！\n" NOR, this_object());
if (this_object()->is_busy()) this_object()->start_busy(1);
	this_object()->clear_condition();
        remove_call_out("hurting");
        call_out("hurting", 3);
        return 1;
}


int hurting()
{
        int dam, i , num;
        object *inv;
        
        message_vision(CYN "$N" CYN "打出一道具大无比的龙卷风．．．．．．一切都被刮的东到西歪！！！\n" NOR,
                       this_object());
                       
        inv = all_inventory(environment(this_object()));        

        num = sizeof(inv);       
        if (num < 1) num = 1;
        if (num > 5) num = 5;
        
        dam = 26000 / num;
        
        for (i=sizeof(inv)-1; i>=0; i--)
        {
                if (living(inv[i]) && inv[i] != this_object() && userp(inv[i]))
                {
                        dam -= inv[i]->query_temp("apply/reduce_wind");
                        if (dam <0) dam = 10;
                        if (!inv[i]->is_busy())
{                        	
message_vision(CYN "$N" CYN "被风卷的不知所措 失去了行动力！！\n" NOR,inv[i]);
                        	 inv[i]->start_busy(5);
this_object()->clear_condition();
if (this_object()->is_busy()) this_object()->start_busy(1);
}                       inv[i]->apply_condition("new_poison4", 5); 	
                        inv[i]->receive_wound("qi", dam/2);
                        inv[i]->receive_wound("jing", dam/3);
                        if (inv[i]->query("neili",1)> 0)
{
                        inv[i]->add("neili",-dam);
        message_vision(CYN "$N" CYN "感觉全身的内力给大风吹的消散了！！\n" NOR,inv[i]);
}

                        if (inv[i]->query("max_neili",1)> 1000)
{
                        inv[i]->add("max_neili",-10);
        
}

                        COMBAT_D->report_status(inv[i], 1);
                }
        }
        return 1;
}
