//writen by lnwm
//yan.c

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("盐", ({"salt"}));
        set_weight(200);
        set("long", "盐");
        set("unit", "袋");
        set("value", 1);
        set("fruit_remaining", 5); 
        set("food_supply", 0);//可以是-1吗？ 
        set("eat_msg", "$N拿起$n，就往嘴里倒,一定有毛病\n");
        set("end_msg", "$N居然吃光了袋里的盐，真可怕.\n"); 
        set("over_msg", "盐你也要吃饱??\n");
        set("core", "空口袋");    
        set("core_id", ({"dai"}) );
        set("core_unit", "只");    
        set("core_long", "空口袋。\n"); 
 
        setup();
}
void init()
{
    add_action("do_eat","eat");
}

