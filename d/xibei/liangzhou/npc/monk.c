// Npc : monk.c
// hydra
inherit NPC;

void create()
{
    set_name( "和尚", ({ "he shang", "monk" }) );
    set("title","大云寺");
    set( "attribute", "friendly" );
    set( "gender", "男性" );
    set( "age", 27 );
    set( "long", @LONG
大云寺的一个和尚，正在呆呆的出神。
LONG
    );
    
    set( "str", 20 );
    set( "dex", 20 );
    set( "combat_exp", 3000 );
    set( "social_exp", 2000 );
        
    setup();
    carry_object("/clone/misc/cloth" )->wear();
}


