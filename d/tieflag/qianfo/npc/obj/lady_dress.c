 // lady_dress.c
#include <armor.h>
#include <ansi.h> 
inherit CLOTH; 
void create()
{
        set_name(MAG"轻罗绸衫"NOR, ({ "lady dress", "dress" }) );
        set_weight(1200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是一件手工相当细致，几乎半透明的绸衫\n");
                set("unit", "件");
                set("value", 2000);
                set("material", "cloth");
                set("armor_prop/armor", 1);
                set("armor_prop/personality", 1);
                set("armor_prop/intelligence",1);
                set("female_only", 1);
        }
        
}  
