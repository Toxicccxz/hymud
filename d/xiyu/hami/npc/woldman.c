
#include <ansi.h>

inherit NPC;

void create()
{
    set_name( "哈密老人", ({ "hami laoren", "laoren"  }) );
    set( "gender", "男性" );                //性别：男
    set( "age", 60 );                
    set( "long", @LONG
本地的一个老人，看上去是很悠闲的样子，一个人在街到处转。
LONG );
    set( "attitude", "friendly" );

    setup();
    carry_object( "/clone/misc/cloth" )->wear();       //粗布衣
}

