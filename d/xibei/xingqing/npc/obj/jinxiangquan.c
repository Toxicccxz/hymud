//jinxiangquan.c.金项圈  
//date:1997.8.27
//by dan 

#include <armor.h>
inherit HEAD;  

void create()
{
        set_name("金项圈", ({ "xiang quan", }) );
        set_weight(90);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是一件用黄金打成的项圈。\n");
                set("unit", "只");
                set("value", 1200);
                set("material", "iron");
                set("armor_prop/armor", 3);
                set("armor_prop/personality", 1);
                set("female_only", 1);
        }
        setup();
}

