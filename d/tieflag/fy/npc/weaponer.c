 inherit NPC;
inherit F_VENDOR;
#include <ansi.h>
void create()
{
        set_name("诸葛小雷", ({ "zhuge" }) );
        set("gender", "男性" );
        set("age", 18);
        set("title", HIG "小急风剑"NOR);
        set("long",
                "当年金狮镖局大镖头诸葛雷的儿子，年纪轻轻，但手下的功夫已经有相当的火候。\n");
        set("combat_exp", 500000);
        set("attitude", "friendly");
        set("per",30);
        set("vendor_goods", ({
               "/clone/weapon/gangjian",
               "/clone/weapon/changqiang",
              __DIR__"obj/1staff.c",
               __DIR__"obj/knife.c",
               __DIR__"obj/dual_ring.c",
        }));
        set_skill("sword",50);
        set_skill("feixian-sword",350);
        set_skill("wuxing-dun",350);
        set_skill("dodge",50);
        set_skill("parry",50);
        map_skill("dodge","wuxing-dun");
        map_skill("parry", "feixian-sword");
        map_skill("sword","feixian-sword");
        setup();
        carry_object(__DIR__"obj/jinzhuang")->wear();
        carry_object("/clone/weapon/gangjian")->wield();
}
void init()
{
        add_action("do_buy", "buy");add_action("do_list", "list");
}  

