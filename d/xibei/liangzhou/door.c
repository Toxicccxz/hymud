//door.c
//Hydra 

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short","富家宅门");
        set("long", @LONG
这里是一个富家的大门。他的主人在凉州是数一数二的富人。大门漆成红色，
门的正上房写着两个大大的字--“张府”，两根门柱是由粗大的木头做成的，门
口的两边蹲着两头狮子，威风凛凛。两个家丁站在门口，细心守护着，一般人是
不让进宅的。
LONG
        );
        set("outdoors","liangzhou");
        set("exits", ([ 
                "south"         :       __DIR__ "lroad2",
                "north"         :       __DIR__"fuzhai1",
                ])
        );
        set("objects",([
                __DIR__"npc/jiading":2,
        ]) );
        setup();
}

void init()
{
    add_action( "do_say","say" );
}

int valid_leave( object ppl,string dir )
{
    object ob;
    if ( dir == "north" && !ppl->query_temp("凉州/allow_enter")
        && objectp( ob = present ( "jia ding", environment( ppl )  ) )
        && living(ob) )
    {
        message_vision("家丁对$N说道：未经老爷邀请，你不能进去。\n",ppl);
        return notify_fail("你被家丁拦住了去路。\n");
    }
    return ::valid_leave(ppl, dir);
}

int do_say( string arg )
{
    object me = this_player();
    if( arg != "我是妙庆方丈介绍来的" ) return 0;
    if( !present("jia ding",environment(me)) )
    {
        write("你准备说给谁听啊？\n");
        return 1;
    }
    
    if( me -> query_temp("凉州/have_noded") )
    {
        me->set_temp("凉州/allow_enter",1);
        tell_object( me,CYN"家丁道：原来大师是大云寺老方丈介绍来的。"
            "请进，请进\n"NOR);
        tell_object( me,CYN"跟我家主人说起方丈，他应该会相信你的。\n"NOR);
        return 1;        
    }
    else
    {
        tell_object( me,CYN"家丁道：看你獐头鼠目，不象好人，妙庆大师怎么会介绍你"
            "这种人呢！\n去去去！\n"NOR);
        return 1;
    }
}
