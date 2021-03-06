/* waiter.c
 * from XO Lib
 * a npc of gaochang
 * copied from lanzhou 19980427
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980427
 */


inherit NPC;
inherit F_DEALER;


void create()
{
    set_name( "店小二", ({ "xiao er", "xiaoer", "waiter" }) );
    set( "gender", "男性" );                //性别：男
    set( "age", 22 );                       //年龄：22
    set( "attitude", "friendly" );          //态度：友善
    set( "rank_info/respect", "小二哥" );   //敬称：小二哥
    set( "long", @LONG
    店小二身穿青布衣衫，正笑眯眯地看着你，等你点菜或是租房。
LONG
    );


    set( "combat_exp",  7500 );             //战斗经验：7500

    set( "inquiry", ([
        "租房"      :   "呃，客官要租房？好，一天三两银子。",
        "住店"      :   "客官是要租房吧？",
    ]) );
    set( "talk_msg", ({
        "“住店一天五两银子，管保你人财安全。”",
    }) );

	set("vendor_goods", ({
		"/d/xingxiu/npc/obj/yangrou",
		"/d/lanzhouchen/npc/obj/paomo",
		"/d/city/npc/obj/jiudai",
		"/d/lanzhou/npc/obj/jiouhulu",
		"/d/lanzhou/npc/obj/maoniurou",
	}));

    setup();
    carry_object( "/clone/misc/cloth" )->wear();       //青布衣衫
}

void init()
{
    object ppl;

    ::init();

        add_action("do_list", "list");
        add_action("do_buy", "buy");

    if ( !userp( ppl = this_player() ) 
         )
        return;
    remove_call_out( "Greeting" );
    call_out( "Greeting", 1, ppl );
}

void Greeting( object ppl )
{
    if ( !ppl 
        || environment( ppl ) != environment() ) 
        return;
    switch( random( 3 ) ) 
    {
        case 0:
            say( "店小二笑咪咪地说道：“这位" + RANK_D->query_respect( ppl )
                + "，进来歇歇腿吧。这里可以住店哪！”\n");
            break;
        case 1:
            say( "店小二用脖子上的毛巾抹了抹手，说道：“这位" 
                + RANK_D->query_respect( ppl ) + "，来点什么？”\n");
            break;
        case 2:
            say( "店小二叫道：“刚出笼的小笼包子啊，皮薄馅多，客官要不要来一点？”\n" );
            break;
    }
}

int accept_object( object ppl, object obj )
{
    if ( obj->value() >= 5000 ) 
    {
        message_vision( "店小二收下钱，笑眯眯地说：“客房在楼上，您现在"
            + "就可以上去了。”\n", ppl );
        ppl->set_temp( "hydra/gaochang/住店", 1 );
        return 1;
     } 
     return 0;
}

