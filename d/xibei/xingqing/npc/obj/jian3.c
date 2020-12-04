// xuanquan.c

#include <weapon.h>

inherit SWORD;

void create()
{
        set_name("悬泉剑", ({ "xuanquan jian", "xuanquan", "jian" }) );
        set_weight(15000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long",
                        
"这把剑通体清澈透亮，微微透出寒光，据说是铸剑大师黢\n"
                        
"的得意之作，每逢月圆之夜便会自发长啸。\n");
                set("value", 2400);
                set("material", "blacksteel");
                set("wield_msg", 
"只听见「飕」地一声，$N的手中已经多了一把寒光四射的宝剑——$n。\n");
                set("unequip_msg", "$N将手中的$n插入腰间的剑鞘。\n");
        }
        init_sword(58);
        setup();
}
 

