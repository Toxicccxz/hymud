//writen by lnwm
//luob.c

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(YEL "萝卜"NOR, ({"luob"}));
        set_weight(60);
        set("long", "一个黄澄橙的实芯大罗卜");
        set("unit", "个");
        set("value", 1);
        set("fruit_remaining", 3); 
        set("food_supply", 5); 
        set("water_supply", 5); 
        set("eat_msg", "$N拿起$n，嘎嘣咬了一口\n");
        set("end_msg", "$N啃完了这个$n。\n"); 
        set("over_msg", "萝卜你都不放过?\n"); 
        setup();
}
void init()
{
    add_action("do_eat","eat");
}

