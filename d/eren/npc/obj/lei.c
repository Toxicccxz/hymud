#include <ansi.h>
#include <combat.h>
inherit ITEM; 
void create()
{       set_name( HIY"掌心雷"NOR, ({ "zhangxin lei" , "lei"}) );
        set_weight(10);
        set("unit", "颗");
        set("long", "一柄晶晶闪亮的圆形暗器，内藏火药，可以用来射人（shoot）。\n");
        set("value", 5000);
        set("level", 50);
        set("no_drop", 1);
        
} 
void init(){
        add_action("do_shoot", "shoot");
} 
int do_shoot(string arg){
        object me, target;
        int level, exp, t_exp, damage, exp_bonus, resist;
        string msg;
        
        me = this_player();
        if (!arg) return notify_fail("你要打谁？\n");
        if( me->is_busy() )
                return notify_fail("你上一个动作还没有完成！\n"); 
        target = present(arg,environment(me));
        
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) ) 
                return notify_fail( this_object()->name() + "只能对战斗中的对手使用。\n");      
        
        level = (int) query("level");
        damage = 0;
   
        t_exp = (int) target->query("combat_exp");
        exp   = (int) me->query("combat_exp");
        msg  = HIW"$N双掌缓缓在身前移动，目不转睛地盯着对手，忽然间，双掌移
动越来越快，似已化作了无数双。$N轻叱一声，一道寒光，随声暴
射而出。\n\n"NOR;
   if( random(exp)*level/20 + exp/2 > t_exp ) {
                damage = me->query_skill("perception",1)* level /10;
                damage = damage + random(damage);
                if (userp(me)) exp_bonus= me->query("combat_exp")/1000*damage/4000;
                damage = damage + exp_bonus;
                if (damage>6000) damage = 6000;
                msg +=  name() +HIW "象一道闪电击中了$n！！\n" NOR;
                target->receive_wound("qi",damage);
                target->receive_wound("jing", damage/4);
                } else
                msg += "但是被$n躲开了。\n"; 
        message_vision(msg, me, target);
        if( damage > 0 ) {
           target->set_temp("damaged_during_attack", 2);
           COMBAT_D->report_status(target);
        }
        me->start_busy(2);
        destruct(this_object());
        return 1;
}      
