#include <ansi.h>
#include <combat.h>
inherit BOSS;
void do_stun();
void do_attack();
void create()
{
        string *names = ({"棕熊王","黑熊王","白熊王"}); 
        set_name( names[random(sizeof(names))], ({ "bear king","bear"}));
        set("vendetta_mark","bear");
        set("race", "野兽");
        set("gender", "雄性");
        set("age", 20);
        set("long", "这是一只凶猛的熊王。\n");
      
        set("str", 200);
        set("dex", 80);
        set("con", 200);
        set("resistance/qi",50);
        set("max_qi", 38000);
        set("max_jing", 38000);
        set("neili", 38000);
        set("max_neili", 38000);
        set("attitude", "peaceful");

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
	        (: do_attack() :),
        }) ); 

        set("limbs", ({ "头部", "身体", "前脚", "後脚", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) ); 
        set("combat_exp", 7000000);
          set("bonus", random(200)+200);
        set_temp("apply/attack", 1200);
        set_temp("apply/armor", 1000);
        set_temp("apply/unarmed_damage", 500);
        setup();
        carry_object(__DIR__"obj/bear_dan");
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
void do_stun() 
{
	object *enemies,enemy;
	string msg;
	int be_damaged;
	
	enemies = query_enemy();
	if (!enemies || sizeof(enemies)==0)
	        return;
	enemy = enemies[random(sizeof(enemies))];
	msg = HIC"\n$N突然站立起来，抡起熊掌朝$n拍来！\n"NOR;
	message_combatd(msg, this_object(), enemy);
	COMBAT_D->do_attack(this_object(),enemy, 0, 0);
	start_busy(2);
}

void do_attack() 
{
	object *enemies,enemy;
	string msg;
	int be_damaged,i;
	
	enemies = query_enemy();
	if (!enemies || sizeof(enemies)==0)
                return;
	enemy = enemies[random(sizeof(enemies))];
	msg = HIB"\n$N突然狂性大发，抡起熊掌朝$n拍来！\n"NOR;
	message_combatd(msg,this_object(),enemy);
	i = 3+random(3);
	while (i--)
	        COMBAT_D->do_attack(this_object(),enemy, 0, 0);

	start_busy(2);
}
