 inherit F_FOOD;
inherit ITEM;
#include <ansi.h>
void create()
{
    set_name(HIY"忘年丸"NOR , ({ "time pill" }) );
        set_weight(5);
        if( clonep() )
                set_default_object(__FILE__);
        else {
  set("long", RED
      "时间是世间上最厉害的毒药，最能杀人於无形。。。\n"
      "这颗难得一见的灵丹，据说正是时间的解药！\n"NOR); 
        set("unit", "个");
                set("no_drop", 1);
        set("no_sell", 1);
        set("no_give", 1);
        set("no_put", 1);

        set("lore",1);
        set("value", 0);
                set("food_remaining", 1);
                set("food_supply", 0);
                set("material", "food");
        }
        
}
int finish_eat()
{
        object me;
        int max_jing, max_kee, max_sen;
        int n;
        me = this_player();
        /*if (!me->query_temp("timer/zhuguo") && !me->query_temp("buffup/buffed_kee")) {
        max_jing = (int) me->query("max_jing");
        max_kee = (int) me->query("max_qi");
        max_sen = (int) me->query("max_jing");*/
        message_vision( HIY "\n四周的景物忽然不断旋转起来，$N双目变得迷惘。。。\n"NOR, me);
        message_vision( HIY "\n$N思想开始陷入了时光的漩涡。。。\n"NOR, me);
        message_vision( HIY "\n那成长中的豪言壮语，那年少的轻狂。。。\n"NOR, me);
        message_vision( HIY "\n那力量，那自信，那股不顾一切的勇气。。。\n"NOR, me);
        message_vision( HIY "\n那童年的秋千，那老家的池塘。。。\n"NOR, me);
        message_vision( HIY "\n一切，一切。。。\n"NOR, me);
        me->start_busy(5);
        n = random(1544332);
        if (me->query("mud_age") > 1544332) 
            { me->add("mud_age", - n);
            me->unconcious();
        	}else message_vision( HIY "\n$N猛然惊醒，但除了一额冷汗，别的什么也没发生。\n"NOR, me);
        destruct(this_object());
        return 1;
}    
