//writen by lnwm
//jiangt.c

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(HIR "姜汤"NOR, ({"jiang tang","tang"}));
        set_weight(200);
        set("long", "冒着热气的姜汤,看着就叫人心里暖和");
        set("unit", "碗");
        set("value", 1);
        set("fruit_remaining", 3); 
        set("food_supply", 3);
        set("water_supply", 30); 
        set("eat_msg", "$N拿起$n，美美地喝了一口,顿时浑身暖和起来\n");
        set("end_msg", "$N喝光了碗里的姜汤\n"); 
        set("over_msg", "你已经喝饱了\n");
   set("core", "碗");    
   set("core_id", ({"wan"}) );
        set("core_unit", "只");    
        set("core_long", "一只空碗。\n"); 
 
        setup();
}
void init()
{
    add_action("do_eat","drink");
}

