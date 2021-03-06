// 远途商人 /d/city/chuzhou/npc/west_seller1.c
// by lala, 1997-12-15

inherit NPC;

inherit F_VENDOR;

#include <ansi.h>

void create()
{
    set_name( "贵州客商", ({ "guizhou keshang", "keshang", "seller", }) );
    set( "title", HBYEL CYN"远途"WHT"商人"NOR );
    set( "gender", "男性" );
    set( "age", 25 + random(25) );
    set( "long", @LONG
这是个远路来的商人，带来了许多特产，正在大声的叫卖。
LONG
    );
    set( "attitude", "friendly" );

    set( "talk_msg",({
    }));
    set("qi",400);
    set("max_qi",400);
    set("eff_kee",400);
    set("sen",400);
    set("max_sen",400);
    set("eff_sen",400);
    set( "max_force",   500 );
    set( "force",       500 );
    set( "force_factor", 20 );
    set( "combat_exp",  10000 + random( 5000 ) );
    set( "social_exp",  20000 + random( 5000 ) );
    set( "positive_score",  100 + random( 500 ) );
    set( "negative_score",  100 + random( 500 ) );


    setup();

    carry_object( "/clone/misc/cloth" )->wear();

    add_money( "coin", 20 + random(31) );
}

