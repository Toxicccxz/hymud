// wuming-blade.c
// by dicky

#include <ansi.h>
#include <weapon.h>
inherit BLADE;

void create()
{
        set_name(HIR"无名宝刀"NOR, ({ "wuming baodao", "blade"}) );
        set_weight(15000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("value", 10);
		set("disappear",1);
                set("rigidity", 5);
                set("material", "steel");
                set("weapon_prop/dodge", 2);
                set("treasure",1);
                set("wield_str", 25);
                set("wield_msg", "只见寒光一闪，$N从身后抽出一把寒气森森的宝刀。\n");
                set("long", "此刀长约四尺，青光闪闪，是把削金断铁的利器\n");                
                set("unwield_msg","$N将无名宝刀小心的插回身后。\n");               
        }
        init_blade(350);
        setup();
}

