/* shangren2.c 波斯商人
 * from XO Lib
 * a npc of gaochang.
 * created by hydra 19980427
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980427
 */

#include <ansi.h>

inherit NPC;

inherit F_VENDOR;

string * persia_name = ({
"穆罕默德","法赫德","阿里",
});
string AskCamel( object );
void LoadCamel();

void create()
{
    seteuid( getuid() );
    set_name( persia_name[random(3)],({"bosi shangren", "shangren","persia" }) );
    set( "title",HIY"波斯商人"NOR );
    set("gender", "男性" );
    set( "long", @LONG
他是一名从波斯不远万里来这里来做生意的。带来了波斯的特产。
LONG
    );
    set( "age",33 );


    set_skill( "unarmed",700+random(300) );
    set_skill( "dodge",700+random(300) );
    set( "combat_exp", 50000 );
    set( "attitude", "friendly" );
      

	set("vendor_goods", ({
		__DIR__"obj/glass",
		__DIR__"obj/muxu",
		__DIR__"obj/xiangliao",
	}));
    set( "inquiry",([
        "买骆驼"  : (: AskCamel :),
    ]) );

    setup();
    carry_object("/clone/misc/cloth")->wear();
    add_money( "silver",5+random(3) );
}

void init()
{       
    ::init();
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}

string AskCamel( object me )
{
    me = this_player();
    me -> set_temp( "hydra/gaochang/buycamel",1 );
    return "你要买骆驼啊，好，五两黄金一匹。\n" ;
}

int accept_object( object me,object money )
{
    if( !me->query_temp( "hydra/gaochang/buycamel" ) )
        return 0;
    if( money -> value() < 50000 )
    {
        command( "say 不是跟你说了五两黄金一匹了吗？。" );
        return 0;
    }
    LoadCamel();
    me -> delete_temp( "hydra/gaochang/buycamel" );
    command( "say 好，那就卖给你一匹骆驼，在后院，你自己去牵吧。" );
    return 1;
}

void LoadCamel()
{
    object room,camel_ob;
    if( ! room = find_object( "/d/xiyu/gaochang/houyuan" ) )
        room = load_object( "/d/xiyu/gaochang/houyuan" );
    camel_ob = new( __DIR__"camel" );
    camel_ob -> move( room );
}

    
