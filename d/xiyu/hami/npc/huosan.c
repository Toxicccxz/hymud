// huosang.c     霍桑
// Ffox 98-4-30 14:14

inherit NPC;
inherit F_VENDOR;

void create()
{
    set_name( "霍桑", ({ "huo sang", "huo"  }) );
    set( "gender", "男性" );                //性别：男
    set( "age", 30 );                
    set( "long", @LONG
本地人……艺人………
LONG );
    set( "attitude", "friendly" );

    set( "chat_chance", 5 );
    set( "chat_msg", ({
    "霍桑看着门口，注意到你在旁边，很高兴地揍起了马头琴。",
    "霍桑揍完了马头琴，抬起头来。",
     }));

	set("vendor_goods", ({
		__DIR__"obj/matouqin",

	__DIR__"obj/putao_jiu",
	}));
    setup();
    carry_object( "/clone/misc/cloth" )->wear();       //粗布衣
}


void init()
{
    object ppl;
    ::init();
        add_action("do_list", "list");
        add_action("do_buy", "buy");
    call_out( "do_listen", 1 ,ppl );
}

void do_listen()
{
    write( "屋子里的人正在弹揍乐器，显然是一个艺人......\n");
}
