//blade.c 雁瓴刀
//Hydra copied from fenglei-dao

#include <weapon.h>
#include <armor.h>
#include <ansi.h>

inherit BLADE;

void create()
{
    set_name( YEL"雁瓴刀"NOR, ({ "yanling dao", "dao", "blade"}) );
    set_weight( 6000 );                     
    set( "long", "一把明晃晃的钢刀，拿在手里沉甸甸的，一看就知道是好刀。\n" );
    if ( clonep() )
        set_default_object( __FILE__ );
    else 
    {
        set( "unit", "把" );
        set( "value", 15000 );               
        set( "material", "steel" );         
    }
    init_blade( 40 );                       
    set( "wield_msg", "$N「唰」的一声抽出一把明晃晃的$n握在手中。\n" );
    set( "unwield_msg", "$N将手中的$n插入腰间的刀鞘。\n");

    setup();
}

