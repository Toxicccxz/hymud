/* glass.c  玻璃
 * from XO Lib
 * a obj of gaochang
 * created by hydra 19980427
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980427
 */

inherit ITEM;

#include <ansi.h>

void create()
{
    set_name( HIY"玻璃"NOR,({"bo li","boli","glass" }) );
    set_weight( 100 );
    if( clonep() )
        set_default_object( __FILE__ );
    else 
    {
        set( "long","一种奇怪的透明的东西\n" );
        set( "unit","块" );
        set( "value",5000 );
    }
    setup();
}
