#include <weapon.h>

inherit CLUB;

void create()
{
        set_name("火尖枪", ({ "dragon stick","gun", "bang" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("value", 5000);
                set("material", "steel");
                set("long", "一根沉甸甸雕着盘龙的长枪。\n");
                set("wield_msg", "$N拿起一根$n，顺手舞了个枪花。\n");
                set("unwield_msg", "$N哼了一声，将$n插回后腰。\n");
        }
        init_club(650);
        setup();
}

