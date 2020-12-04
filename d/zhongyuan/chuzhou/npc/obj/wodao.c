// 日本倭刀 /d/city/chuzhou/npc/obj/wodao.c
// by lala, 1997-12-14

#include <weapon.h>
#include <ansi.h>

inherit BLADE;

void create()
{
        set_name("倭刀", ({ "wo dao", "blade"}) );
        set_weight(2500);
    set("long", @LONG
日本生产的刀，称为倭刀。日本的兵器打造技术很高，所采用的钢质地很好。因
此倭刀十分锋利，深受中原武林人士的喜爱。
LONG
    );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 5000);
                set("material", "steel");
        }
        init_blade(35);
        set("wield_msg", "$N「唰」的一声抽出一把寒光逼人的$n握在手中。\n");
        set("unwield_msg", "$N将手中的$n插入腰间的刀鞘。\n");
        setup();
}
