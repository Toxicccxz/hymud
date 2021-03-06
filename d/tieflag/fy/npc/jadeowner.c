 inherit NPC;
inherit F_VENDOR; 
void create()
{
        set_name("商玉龙", ({ "seller", "jadeseller" }) );
        set("gender", "男性" );
        set("age", 49);
        set("title", "玉龙珠宝");
        set("long", "这是一位肥肥胖胖店掌柜。\n");
        set("combat_exp", 1000000);
        set("reward_npc", 1);
        set("difficulty", 6);
        set("str", 60);
        set("attitude", "friendly");
        set_skill("dodge", 100);
        set_skill("parry", 120);
        set("vendor_goods", ({
                __DIR__"obj/jade1",
                __DIR__"obj/jade2",
                __DIR__"obj/jade3",
                __DIR__"obj/jade4",
        })); 
        setup();
        carry_object("/clone/misc/cloth")->wear();
} 
void init()
{
        object ob; 
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_buy", "buy");add_action("do_list", "list");
        add_action("do_sell","sell");
}
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(10) ) {
                case 0:
                        say( " 店掌柜笑着道：这位"
                                + RANK_D->query_respect(ob)
                                + "，买玉吗？ \n");
                        break;
                case 1:
                        say( " 店掌柜笑着道：这位"
                                + RANK_D->query_respect(ob)
                                + "，玉是吉祥之物，买一块吧。 \n");
                        break;
                case 2:
                        say( " 店掌柜低声向你说道：这位"
                                + RANK_D->query_respect(ob)
                                + "，本店新增服务，专收无法出手\n的“奇珍异宝”....嘿嘿.... \n");
                        break; 
        }
} 
int do_sell(string arg)
{
        object ob;
        int value;
        if( !arg || !(ob = present(arg, this_player())) )
                return notify_fail("你要卖断什麽物品？\n");
        if( this_player()->is_busy() )
                return notify_fail("你上一个动作还没有完成，不能卖物品。\n");
        if( ob->query("money_id") )     return notify_fail("你要卖「钱」？\n");
        value = ob->query("value");
        if( !(value/10) ) return notify_fail("这样东西并不值很多钱。\n");
        if (!ob->query("thief_obj"))
        {
                return notify_fail("店掌柜摇头道：本店不收这类物品。\n");
        }
        message_vision("$N把身上的" + ob->query("name") + "偷偷塞给店掌柜....\n",this_player());
        command("whisper "+this_player()->query("id")+" 现金交易太扎眼，钱会转到你南宫银行的帐上。\n");
        command("snicker");
        this_player()->add("deposit",value/10);
        destruct(ob);
        this_player()->start_busy(1);
        return 1;
}
