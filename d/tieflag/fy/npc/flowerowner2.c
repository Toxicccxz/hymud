 inherit NPC;
inherit F_VENDOR;
#include <ansi.h>
void create()
{
        set_name("花满城", ({ "huaman" }) );
        set("gender", "男性" );
        set("age", 81);
        set("title", BLU "月老"NOR);
        set("long",
                "这位老板正对你露出慈祥的笑容。\n");
        set("combat_exp", 350000);
        set("attitude", "friendly");
        set("per",20);
        set("vendor_goods", ({
                __DIR__"obj/purple_flower",
                __DIR__"obj/red_flower",
                __DIR__"obj/yellow_flower",
                __DIR__"obj/blue_flower",
                __DIR__"obj/white_flower",
                __DIR__"obj/black_flower",
        }));
        set_skill("unarmed",50);
        set_skill("dodge",50);
        setup();
        carry_object(__DIR__"obj/fycloth")->wear();
} 
