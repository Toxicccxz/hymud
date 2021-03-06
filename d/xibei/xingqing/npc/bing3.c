//bing3.c.侍卫军
//date:1997.8.24
//by dan      

#include <ansi.h>
inherit NPC;   

void create()
{
    set_name(YEL"侍卫军"NOR, ({ "shiwei jun" }));
    set( "age", 28 + random( 5 ) );
    set("title","");
    set("gender", "男性");
    set("long", "他是一名侍卫军军官，负责宫廷安全事物。\n");
    set("str",40);
    set("per", 25);
    set("combat_exp", 50000);
    set("max_jing",300);
    set("max_qi",700);
     set_skill("force", 180+random(180));

        set_skill("unarmed", 180+random(180));
        set_skill("blade", 180+random(180));
        set_skill("parry", 180+random(180));
        set_skill("dodge", 180+random(180));
        set_skill("kuang-blade", 180+random(180));
        map_skill("blade", "kuang-blade");
        map_skill("parry", "kuang-blade");
        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
        "侍卫军喝道：来啊！大家一起上,快把这个反贼拿下！\n",
                (: perform_action, "blade.leitingpili" :),
                (: perform_action, "blade.kuang" :),
        }) );

    setup(); 
    carry_object(__DIR__"obj/blade1")->wield();
    carry_object(__DIR__"obj/junfu")->wear();
    carry_object(__DIR__"obj/kaijia1")->wear();
    carry_object(__DIR__"obj/toukui1")->wear();
    carry_object(__DIR__"obj/zhan_pao")->wear();
    carry_object(__DIR__"obj/zao_sitao")->wear();
    carry_object(__DIR__"obj/pixue")->wear(); 
}      

void init()
{
    object ob;

    ::init();
    if ( interactive(ob = this_player()) && !is_fighting() )
    {
        remove_call_out("greeting");
        call_out("greeting", 1, ob);
    }
}

void greeting(object who)
{
    if ( !present( who, environment( this_object() ) ) )
        return;
    if ( who->query_condition("kill_xingqing") )
    {
        message_vision("侍卫军对着$N大喝一声：“杀人放火的刁民，快快受死吧！！！” \n",who);
        kill_ob(who);
        who->fight_ob(this_object());
        return;
    }
}

int accept_fight(object me)
{
    command("say 我看你今天是活得不耐烦了,"+ RANK_D->query_rude(me)+",去死吧！\n");
    //me->apply_condition("kill_xingqing", 360);
    kill_ob(me);
    return 1;
}

