// yizhang.c     驿长
// Ffox 98-4-30 14:14
inherit NPC;

void create()
{
    set_name( "驿长", ({ "yi zhang", "yizhang", "zhang"  }) );
    set( "gender", "男性" );                //性别：男
    set( "age", 35 );                
    set( "long", @LONG
本地人……艺人………
LONG );
    set( "attitude", "friendly" );

    setup();
    carry_object( "/clone/misc/cloth" )->wear();       //粗布衣
}

