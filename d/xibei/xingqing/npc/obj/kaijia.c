// common armor by lin on March 4, 1997
#include <armor.h>
inherit ARMOR;
void create()
{
        set_name("护心甲", ({ "armor", }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","一个镔铁打就的护心甲。\n");
                set("unit", "套");
                set("value",300);
                set("material", "iron");
                set("armor_prop/armor", 4);
                set("armor_prop/defence", 4);
          
        }
        setup();
}

