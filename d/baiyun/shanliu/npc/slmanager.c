//by xiaolang
inherit NPC;
#include <ansi.h> 
int test_dart();
void create_level(object who,string name, int exp); 
void create()
{
    set_name("杨总管", ({ "shanliu manager" }) );
    set("gender", "男性" );
    set("age", 32);
    set("force",500);
    set("title","山流");
    set("force_factor",20);
    set("max_neili",500);    

    set("int", 30);
    set("long",
        "没有人知道杨总管的真实名字，大家一般都叫他总管，\n他看起来非常的平凡普通，但却非常干练。\n"
        );
    set("chat_chance", 2);
    set("chat_msg", ({
            }) );
    
    set_skill("unarmed", 400);

    
    set("combat_exp", 35000000);
    setup();
    carry_object("/clone/misc/cloth")->wear();
//    carry_object("/d/taishan/npc/obj/hxshoes")->wear();
} 
