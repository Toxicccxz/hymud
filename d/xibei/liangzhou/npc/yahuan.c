// Npc : yuhuan.c  丫鬟
// hydra
inherit NPC;

void create()
{
    set_name( "丫鬟", ({ "ya huan", "yahuan" }) );
    set( "title","张府" );
    set( "attribute", "friendly" );
    set( "gender", "女性" );
    set( "age", 18 );
    set( "long", @LONG
服侍小姐的丫鬟
LONG
    );
    
    set( "per",30 );
    set( "int",26 );
    set( "str", 20 );
    set( "dex", 20 );
    set( "combat_exp", 3000 );
    set( "social_exp", 2000 );
        
    setup();
    carry_object( "/clone/misc/cloth" )->wear();
    
}


