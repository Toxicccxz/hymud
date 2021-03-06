/* sheyao.c 印度蛇药
 * from XO Lib
 * a obj of gaochang.
 * created by hydra 19980427
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980427
 */

#include <ansi.h>

inherit ITEM;

void create()
{
    set_name( "印度蛇药" , ({"she yao", "pill", "yao" }));
    set_weight(30);
    if (clonep())
        set_default_object(__FILE__);
    else
    {
        set("long", "这是一枚印度产的蛇药，效果特别好。\n");
        set("unit", "枚");
        set("value", 5000);
    }
}


void init()
{
    add_action("do_eat", "eat" );
}

int do_eat( string arg )
{
    object me;
    int condition;
    me = this_player();

    if( !me->can_act() ) return notify_fail("你现在无法服药。\n");

    if( arg != "she yao" && arg != "pill" && arg != "yao" )
        return 0;

    if( !condition = me->query_condition("snake_poison") )
    {
        write("你没有被蛇咬伤，吃蛇药是没用的。\n"); 
        return 1;
    }

    condition -= 10;
    message_vision("$N从怀里掏出一枚蛇药，吃了下去。\n", me);
    if ( condition <= 0 )
    {
        tell_object( me, CYN"你觉得体内的毒性好象已经被控制住了。\n"NOR );
        me -> clear_condition( "snake_poison" );
    }
    else
    {
        tell_object( me,CYN"你觉得你中的蛇毒有所缓解。\n"NOR );
        me -> apply_condition( "snake_poison",condition );
    }
    
    destruct( this_object() );
    return 1;
}


