//bi.c.承天璧
//date:1997.8.28
//by dan   

#include <ansi.h>
#include <armor.h>
inherit WRISTS;   

void create()
{
        set_name(YEL"承天璧"NOR, ({ "cheng tian bi","bi" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是一块制作精美的玉璧. \n");
                set("unit", "块");
                set("value", 500000);
                set("material", "yu_stone");
                set("armor_prop/armor", 30);
                set("armor_prop/personality", 1);
                set("female_only", 1);
        }
        setup();
}

