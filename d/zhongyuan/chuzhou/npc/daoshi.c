// 楚州道士 /d/city/chuzhou/npc/daoshi.c
// by lala, 1997-12-13

inherit NPC;
#include <ansi.h>

int ask_me();
int add_max_age( object ob, object me );

void create()
{
    set_name( "玉虚子", ({"yuxu zi", "yuxu", "daoshi"}) );
    set( "gender", "男性" );
    set( "age", 82 );
    set( "per", 27 );
    set( "class", "taoist" );
    set( "attribute", "friendly" );
    set( "title", YEL"真人"NOR );
    set( "long", @LONG
这就是上清宫的当家道士——玉虚子。他能掐会算，在楚州城大大的有名，甚至
就是当今皇上也曾经听说过他，曾经召他到东京去，赐给他“真人”的头衔。所
以在地方上连州县的地方官也要让他三分。到这里来找他算命，求天尊保佑的人
络绎不绝。
LONG
    );
    set("qi",400);
    set("max_qi",400);
    set("eff_kee",400);
    set("sen",400);
    set("max_sen",400);
    set("eff_sen",400);
    set( "positive_score", 10000 );
    set( "negative_score",  3000 );
    set( "combat_exp",    1500000 );

    set( "inquiry", ([
        "寿命"      :   (: ask_me :),
        "寿数"      :   (: ask_me :),
        "算命"      :   (: ask_me :),
        "命运"      :   (: ask_me :),
        "age"       :   (: ask_me :),
        "life"      :   (: ask_me :),
        "max age"   :   (: ask_me :),
        "max_age"   :   (: ask_me :),
    ]));
    setup();
    carry_object( "/clone/misc/cloth" )->wear();

    add_money( "silver", random(5) + 3 );
}

int ask_me()
{
    object me = this_player();
    object ob = this_object();
    object here = environment();
    int age = me->query("age");
    int m_age = me->query("max_age");
    
    if( here->query( "short" ) != WHT"上清宫"NOR )
    {
        command( "say “这个么……这里不方便，还是等贫道回去再说吧。”" );
        return 1;
    }        
    if( m_age > ( age + 12 ) )
    {
        command( "smile " + me->query( "id" ) );
        command( "say “这位" + RANK_D->query_respect( me ) 
            + "印堂发亮，精神焕发，说明阳寿还长，不必挂怀。”" );
        return 1;
    }
    command( "hmm" );
    command( "say “这位" + RANK_D->query_respect( me )
        + "印堂发暗，面有黑气，恐怕是天年不永，阳寿将尽了吧。”" );
    command( "say “不过呢，如果" + RANK_D->query_respect( me )
        + "乐善好施，广积阴德，那么也可以求天尊保佑以延年益寿。”" );
    me->set_temp_marks( "marks/chuzhou/可以捐款", 1 );
    return 1;
}

int accept_object( object me, object ob )
{
    int age = me->query("age");
    int m_age = me->query("max_age");
    int zhishu = ( m_age + 1 ) / 12;
    int i, money = 5000;
    int value = ob->value();
    
    if( value < 1 )
        return 0;
    if( !me->query_temp_marks( "marks/chuzhou/可以捐款" ) )
    {
        command( "say “多谢施舍，相信天尊一定会保佑你的。”" );
        return 1;
    }
    for( i = 1; i < zhishu; i++ )
        money = money * 2;
    money = money * ( 140 - me->query_kar() * 2 ) / 100;         
    if( value < money )
    {
        command( "shake" );
        command( "say “心不诚，是不会得到天尊的保佑的。”" );
        return 0;
    }
    call_out( "add_max_age", 1, ob, me );
    return 1;
}                    
                           
int add_max_age( object ob, object me )
{
    destruct( ob );
    me->add( "max_age", 1 );
    me->delete_temp_marks( "marks/chuzhou/可以捐款" );
    message_vision( "$N取朱砂水刷了一道黄表，用木剑挑了，在火上一烧，口中念念有辞。\n", this_object() );
    tell_object( me, "你突然感觉精神为之一振，精力旺盛了许多。\n" );
    return 1;
}    
                              
