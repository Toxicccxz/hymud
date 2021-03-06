/* teacher.c 老先生
 * from XO Lib
 * a npc of gaochang
 * copied from yangzhou 19980430
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980430
 */


#include <ansi.h>

inherit NPC;
inherit F_DEALER;

void create()
{
    set_name(YEL "老先生" NOR,({ "lao xiansheng","xiansheng", "teacher"}) );
    set("gender", "男性" );
    set("age", 55);
    set("long", @LONG
老先生正忙着教几个西域商人在读书，摇头晃脑地口里念着之乎者也。。。
LONG
    );
    set( "rank_info/respect","老先生" );
    set("attitude", "peaceful");
    set("combat_exp", 10);
    set("social_exp", 100000);
    set("positive_score",100);
    set("str", 15);
    set("cor", 18);
    set("cps", 20);
    set("per", 21);

        set("vendor_goods", ({
                "/clone/book/lbook1",
                "/clone/book/lbook2",
                "/clone/book/lbook3",
//                "/clone/book/lbook4",
        }));


    set_skill("literate", 150);
    set("inquiry", ([
         "literate" : "你想学读书识字吗？给二两银子就可以了。",
         "读书识字" : "你想学读书识字吗？给二两银子就可以了。",                
    ]));
    setup();
    carry_object( "/clone/misc/cloth")->wear();
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}

int valid_teach( object me, string skill )
{
    if( !me->query( "hydra/gaochang/老先生" ) )
    {
        command( "say 我没有收过你这个弟子啊。。。" );
        return 0;
    }
    if ( skill != "literate" || me->query_jibie( "literate" ) > 49 )
        return 0;
    return 1;
}

int accept_object( object me, object ob )
{
    if ( ob->value() >= 2000 )
    {
        me->set( "hydra/gaochang/老先生",1 );
        message_vision("老先生对$N笑道：既然你如此有向学之心，我就教你吧。\n", me);
        return 1;
    }
    return 0;
}


