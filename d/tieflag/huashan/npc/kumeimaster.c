#include <ansi.h>
inherit F_MASTER;
inherit NPC;
int force_convert();
int leave();
void create() 
{
    set_name("枯梅大师", ({ "master kumei", "kumei","master"}));
    set("long", 
        "
这是一个白发苍苍的老妇，一张干枯瘦削的脸上满是伤疤，耳朵缺了半个，
眼睛也少了一只，剩下的一只眼睛半开半合，开合之间，精光暴射，无论谁也
不敢逼视。她身子很瘦小，但却有种说不出来的威严，无论谁人只要瞧上她 
一眼，连说话的声音都会压低些。
\n"
        );
    set("nickname", HIW "铁仙姑"NOR);
    set("gender", "女性");
    set("class","huashan");
    create_family("华山派", 16, "掌门");
    set("rank_nogen",1);
    set("student_title","弟子");
    set("reward_npc", 1);
    set("difficulty", 5);
    set("age", 59);
    set("int", 30);
    set("per", 3);
    set("con", 25);
    set("str",28);
    
      set("neili", 36400);
        set("max_neili", 36400);
        set("jiali", 50);
        set("max_qi",18200);
        set("max_jing",15200);

        set("combat_exp", 5400000);
        set("shen", 20000);
        set_temp("xunshan", 200);
        set("apprentice_available", 3);

        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.jm" :),
                (: perform_action, "sword.jianzhang" :),
                (: perform_action, "sword.jie" :),
                (: perform_action, "sword.xian" :),                
                (: perform_action, "dodge.huiyanfeiwu" :),                
                (: exert_function, "powerup" :),
        }) );


        set_skill("unarmed", 180);
        set_skill("sword", 290);
        set_skill("force", 200);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("literate", 200);
        set_skill("huashan-sword", 290);
        set_skill("zixia-shengong", 320);
        set_skill("hunyuan-zhang", 290);
        set_skill("poyu-quan", 290);
        set_skill("feiyan-huixiang", 290);
        set_skill("pixie-sword",280);
        set_skill("zhengqijue",200);

        map_skill("sword", "huashan-sword");
        map_skill("parry", "huashan-sword");
        map_skill("force", "zixia-shengong");
        map_skill("unarmed", "huashan-ken");
        map_skill("dodge", "feiyan-huixiang");        
        set("inquiry", ([
//              "hanmei-force" : (: force_convert :),
//              "寒梅心法" : (: force_convert :),
                "leave" : (: leave :),
        ])); 
        
        
    set("ranks",({"弟子","小侠","少侠","大侠","奇侠",WHT"狂侠"NOR,WHT"侠圣"NOR,HIW"隐侠"NOR}));
    setup();
        carry_object("/clone/weapon/gangjian")->wield();
        carry_object("/clone/misc/cloth")->wear();
}  
void attempt_apprentice(object ob)
{
    if (ob->query("gender")=="男性") {
           command("say 华山只收女子为徒。\n");
        return;
    }   
    if (ob->query_skill("sword",1) < 19) {
         command("say  你对剑术所知甚少，竟然想来拜我！");
                return;
    }
    if ((int)ob->query_skill("move",1) < 19 ) {
        command("say 阁下的身法似乎不能学武啊！");
                return;
    }
/*    if ((int)ob->query("age") > 15 ) {
        command("say 所谓少壮不努力，老大徒伤悲，我看阁下于武学一道没什么前途。");
                return;
    }*/ 
    command("recruit " + ob->query("id"));
} 
void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "huashan");
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
           if(id_class == "huashan"&& userp(victim)&& player!=victim)
        {
            message_vision(HIW
"$N对$n喝道：贫尼的徒弟，容不得阁下来管教！\n"NOR, this_object(),player);
            this_object()->kill_ob(player);
            player->kill_ob(this_object());
            if (!player->is_busy()) player->start_busy(2);
            return 0;
        } 
    }
    return 0;
}  
int leave() {
        if (this_player()->query("class")!="huashan") return 0;
        message_vision(CYN"$N冷笑一声，“华山竟然有这样的弟子。“\n"NOR, this_object());
        message_vision(CYN"$N说：寒梅心法和摘心手的秘诀你得留下。\n"NOR,this_object());
        return 1;
}  
