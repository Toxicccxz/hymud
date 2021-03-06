//fuzhai_gelou2.c 阁楼
//Hydra

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short","阁楼");
    set("long", @LONG
阁楼的二楼是小姐的睡房，散发着磬人的香气。一张闺床放在里面，幔帐低
垂。床前一张书桌上放着文房四宝，旁边摆放着一张琴。墙壁上挂着一些书画，
都是小姐自己写的。
LONG
    );
    set("exits", ([ 
        "down"            :       __DIR__"fuzhai_gelou",
    ]) );
    set("objects",([
        __DIR__"npc/xiaojie"    :   1,
    ]) );

    setup();
}

void init()
{
    add_action("do_lie",({"lie","tang"}));
}

int do_lie( string arg )
{
    object ppl = this_player();
    int i;
    object env,*ob;
    
    //if ( !ppl->query_temp("凉州/can_lie") ) return 0;

    env = environment(ppl);
    ob = all_inventory(env);
    for ( i=0;i<sizeof(ob);i++ )
    {
        if ( !ob[i]->is_character() )
            continue;
        else if ( ob[i] == ppl )
            continue;
        else
            return notify_fail("现在这里人太多了，你还是让他们先都躲起来吧。\n");
    }
    
    message_vision(CYN"$N走到小姐床边，揭开绣被，鞋也不脱，满身肮脏的就躺在\n"
"香喷喷的被褥之上。\n然后盖上绸被，放下纱帐，熄灭灯烛，翻身朝里而卧。\n"NOR,ppl);
    ppl-> disable_command("verb","你还是躺在床上不要动弹，以免惊动飞贼。\n");
    call_out("rascal_come",10,ppl);
    return 1;
}
        
void rascal_come( object ppl )
{
    string msg;
    msg = GRN"约莫过了一个更次，你只听得着“拍”的一声，花园中投进一颗石子\n";
    msg +=   "来。过得片刻，围墙外窜进八人，径跃上楼，打着了火折子，走向小\n";
    msg +=   "姐床前，随即又吹熄火折。\n";
    msg +=   "其中四人走到床前，揭开帐子，将绸被兜头罩在你身上，牢牢搂住，\n";
    msg +=   "另外两人张开一只大布袋，抬起你放入袋中，抽动绳子，已把袋口收\n";
    msg +=   "紧。其中四人各执布袋一角。抬起布袋，跃下楼去。\n"NOR;
    tell_object( ppl,msg );
    ppl->disable_command("verb","你躲在袋中不要动弹，以免打草惊蛇。\n");
    call_out("rascal_leave",5,ppl);
}

void rascal_leave( object ppl )
{
    tell_object(ppl,YEL"你只觉得他们抬着你飞快的走着，许久。。。\n"NOR);
    call_out("arrive",3,ppl);
}

void arrive( object ppl )
{
    tell_object(ppl,YEL"他们到达了一处地方，把你扔在了地上。\n"NOR);
    tell_object(ppl,RED"只听得一人呵呵冷笑：想不到美人儿的大驾这么容易请到。\n"
"只听一阵劲风向你袭来，你情知不妙，急忙破袋而出！\n"NOR);    
    ppl->enable_path();
    ppl->move(__DIR__"citang");
}
