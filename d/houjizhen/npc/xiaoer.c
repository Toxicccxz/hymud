// waiter.c
// by dicky


inherit NPC;
inherit F_DEALER;

void create()
{
        set_name("店小二", ({ "xiao er", "xiao", "waiter" }) );
        set("gender", "男性" );
        set("age", 22);
        set("long",
                "这位店小二正笑咪咪地忙着，还不时拿起挂在脖子上的抹布擦脸。\n");
        set("combat_exp", 100);
        set("attitude", "friendly");
        set("rank_info/respect", "小二哥");
        set("inquiry", ([
                "name" : "不敢当，称呼我小二就好了。",
                "rumors" : "听说顾先生收藏了一些失传了的字画，不知是不是真的？",
                "here" : "这里是扬州呀，客官您竟然不知道？",
           ]) );
	set("vendor_goods", ({
		"/d/city/npc/obj/jitui",
		"/d/city/npc/obj/jiudai",
		"/d/city/npc/obj/baozi",
	}));

        setup();

        set("chat_chance", 10);
        set("chat_msg", ({
                "店小二嚷声说道，“天下第一大门派就是少林。”\n",
                "店小二伸出右大姆指，道，“天下第一帮么，自然是丐帮了。”\n",
		       }) );
}

void init()
{       
        object ob;
        ::init();

	add_action("do_buy", "buy");
	add_action("do_list", "list");
        if (base_name(environment()) != query("startroom"))
                return;

        if(interactive(ob = this_player()) && visible(ob) && ! is_fighting())
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if (!ob || !present(ob, environment()))
                return;
        switch(random(2)) {
                case 0:
                        say("店小二笑咪咪地说道：这位" + RANK_D->query_respect(ob) + 
                            "，进来喝杯茶，歇歇腿吧。\n");
                        break;
                case 1:
                        say("店小二用脖子上的毛巾抹了抹手，说道：这位" + RANK_D->query_respect(ob) +
                            "，请进请进。\n");
                        break;
        }
}


int accept_object(object who, object ob)
{
        
        if (ob->query("money_id") && ob->value() >= 500) 
        {
                tell_object(who, "小二一哈腰，说道：多谢您老，客官请上楼歇息。\n");
                who->set_temp("rent_paid",1);
                return 1;

        }
        return 0;
}

void relay_emote(object me,string arg)
{
        command(arg +" " + me->query("id"));
}
