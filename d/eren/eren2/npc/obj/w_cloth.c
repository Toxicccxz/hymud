#include <ansi.h>
#include <armor.h>
inherit ARMOR;
void create()
{
        set_name(WHT"白衣"NOR, ({ "cloth"}) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("material", "vine");
                set("long", "一件丝做的白色衣服。\n");
                set("value", 1000);
                set("armor_prop/armor", 50);
        }
        
}     
