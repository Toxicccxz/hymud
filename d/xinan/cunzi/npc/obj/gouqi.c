//writen by lnwm
//gouqi.c

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(RED "枸杞"NOR, ({"gou qi"}));
        set_weight(60);
        set("long", "红红的圆圆的枸杞，是大补之物。");
        set("unit", "颗");
        set("value", 100);
        set("fruit_remaining", 2); 
        set("food_supply", 30); 
        set("water_supply", 0); 
        set("eat_msg", "$N拿起$n，一口放进嘴里。\n");
        set("end_msg", "$N吃完了$n,脸上浮起一层红晕。\n"); 
        set("over_msg", "你已经吃饱了，再多吃也不怕上火！\n"); 
        setup();
}
void init()
{
    add_action("do_eat","eat");
}

