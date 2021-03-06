 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int got_me();
int leave();
void create()
{
    set_name("空慎", ({ "master kong", "master"}) );
    set("nickname", HIG "无为" NOR);
    set("vendetta_mark","shaolin");
    set("gender", "男性" );
    set("reward_npc", 1);
        set("difficulty", 1);
    set("age", 64);
    set("agi",30);
    set("per", 35);
    set("int",30);
    set("cps",80);
    set("attitude","friendly");
    set("max_neili", 500);
    set("neili", 500);
    set("long","东林第二十三代的师傅，他专门传授东林俗家弟子武功。\n"
        );
    set("inquiry", ([
        "出家前" : (: got_me :),
        "chujiaqian" :  (: got_me :),
        "leave" : (: leave :),
                       
        ]) );
    create_family("东林寺", 23, "长老");
    set("student_title","俗家弟子");
        
    set("chat_chance_combat", 20);
    set("chat_msg_combat", ({
        (: perform_action, "unarmed.qianshouqianbian" :)
            }) );
    set("combat_exp", 100000);
    set_skill("move", 80);
    set_skill("dodge", 80);
    set_skill("force", 80);
    set_skill("literate", 100);
    set_skill("unarmed",80);
    set_skill("shaolin-shenfa",80);
    set_skill("jingang-quan",80);
    set_skill("blade", 80);
    set_skill("xiuluo-dao",80);
    set_skill("yizhi-chan",80);
    set_skill("damo-jian",80);
    set_skill("hunyuan-yiqi",80);
    map_skill("blade","xiuluo-dao");
    map_skill("dodge", "shaolin-shenfa");
    map_skill("force", "yijinjing");
    map_skill("unarmed", "jingang-quan");
    setup();
    carry_object(__DIR__"obj/monk22_cloth")->wear();
}  
void attempt_apprentice(object me)
{
    if(me->query("gender") != "男性")
    {
        command("say 善哉，善哉，这位女施主请回吧，本寺只收男弟子。。。\n");
        return;
        }
        if(me->query("marry")){
                message_vision("$N抬头看了看$n：这位施主六根未净，还是请回吧。\n", 
                                this_object(), me);
                return;
        }
        else  {
    if(((int)me->query_skill("jingang-quan",1)>=15 && 
        (int)me->query_skill("hunyuan-yiqi",1)>=10 &&
        (int)me->query_skill("shaolin-shenfa",1)>=15) /*|| me->query_temp("marks/go_head_to_app_mas_kong")*/)
    {
        if (me->query("once_menpai/shaolin")) {
                command("shake");
                command("say 施主既已离开东林，何苦再回来呢？\n");
                return;
   }
        me->set("once_menpai/shaolin",1);
        command("smile");
        command("recruit " + me->query("id") );
        return;
    }
    else
    {
        command("smile");
        command("say 拜师要有诚意，你先去学学碑文吧！\n");
        return;
                } 
    }
} 
void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "shaolin");
} 
int accept_fight(object me)
{
        if(me->query("class") == "shaolin")
        {
        command("say 好，你赢了我，你就可以去找东林中更高深的师傅了！\n");
        return 1;
        }
        else
        {
        command("say 阿弥陀佛！贫僧武功低微，施主不要开这种玩笑。\n");
        return 0;
        }
}
void win_enemy(object loser)
{
command("say 阿弥陀佛！徒儿还要努力呀！\n");
}
void lose_enemy(object winner)
{
command("say 阿弥陀佛！你可以去找别的师傅去深造了。\n");
winner->set_temp("won_master_kong",1);
} 
int got_me()
{
command("sigh");
command("say 出家前的事不提也罢！\n");
return 1;
} 
void init()
{       
        ::init();
        add_action("do_killing", "kill"); 
} 
int do_killing(string arg)
{
    object player, victim;
    string id,id_class;
    player = this_player();
    if(!arg || arg == "") return 0;
    victim = present(arg, environment(player));
        if(!objectp(victim))
                return notify_fail("这里没有这个人。\n");
    if(living(victim))
    {
        id_class=victim->query("class");
        id=victim->query("id");
        if(id_class == "shaolin"&& userp(victim)&&player!=victim)
        {
            message_vision(HIW
"$N对$n喝道：阿弥陀佛,佛门清静之地,岂可妄起杀心?施主请恕老衲得罪了！\n"NOR, this_object(),player);
            this_object()->kill_ob(player);
            player->kill_ob(this_object());
            if (!player->is_busy()) player->start_busy(2);
            return 0;
        } 
    }
    return 0;
}  
int leave() {
        if (this_player()->query("class")!="shaolin") return 0;
        message_vision(CYN"$N合掌道：阿弥陀佛，既是无缘，何必再留,以后也不要再回来了。\n"NOR, this_object(),this_player());
   return 1;
}        
