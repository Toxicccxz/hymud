#include <armor.h>
#include <ansi.h>
inherit HEAD; 
void create()
{
        set_name(HIY"二龙抢珠金抹额"NOR, ({ "doublepin"}) );
        set_weight(5);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一个名贵的二龙抢珠金抹额。豪华造型，古雅风情\n");
                set("unit", "个");
                set("value", 5000);
                set("armor_prop/armor", 30);
                set("armor_prop/personality", 5);
                set("wear_msg", "$N轻轻地把一个$n戴在头上。\n");
                set("unwield_msg", "$N轻轻地把$n从头上除了下来。\n");
                set("female_only", 1);
        }
        
}     
