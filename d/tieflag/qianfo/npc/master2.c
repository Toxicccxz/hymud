 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_for_join();
void create()
{
    set_name("参机大师", ({ "master can", "master", "can" }) ); 
    set("gender", "男性");
    set("age", 74);
    set("attitude", "peaceful");
    set("class", "bonze");
    set("apprentice_available", 3);
    set("reward_npc", 1);
    set("difficulty", 5);
    set("int", 30);
    set("spi", 30);
    set("con", 30); 
    set("fly_target",1);
    set("atman", 300);
    set("max_atman", 300);
    set("neili", 1000);
    set("max_neili", 1000);
    set("force_factor", 5);
    set("mana", 300);
    set("max_mana", 300); 
    set("combat_exp", 1000000);
    set("score", 9000); 
    set("inquiry", ([
        "剃度" : (: ask_for_join :),
        "出家" : (: ask_for_join :),
        "apprentice" : (: ask_for_join :),
        ]) ); 
    set_skill("staff", 120);
     set_skill("unarmed", 200);
        set_skill("dodge", 100);
		set_skill("dodge", 100);
        set_skill("staff", 200);
        set_skill("force", 180);
        set_skill("parry", 150);
        set_skill("literate", 140);
        set_skill("iron-cloth", 230);
        set_skill("bloodystrike", 150);
        set_skill("lamaism", 200);
        set_skill("jin-gang", 200);
        set_skill("spells",200);

        
        
        map_skill("unarmed", "bloodystrike");
        map_skill("iron-cloth", "jin-gang");
        
        set_temp("apply/iron-cloth",200); 
/*      set("chat_chance_combat", 70);
        set("chat_msg_combat", ({
                (: perform_action, "staff.longxianyuye" :),
                (: perform_action, "unarmed.fefawubian" :),
                (: cast_spell, "an" :),
        }) ); */
        
	set_skill("iron-cloth", 150);

	set_skill("bloodystrike", 300);
	set_skill("cloudstaff", 300);
	set_skill("bolomiduo", 300);
	set_skill("buddhism", 300);
        set_skill("jin-gang", 350);


	map_skill("unarmed", "bloodystrike");
        map_skill("force", "bolomiduo");
        map_skill("literate", "buddhism");
        map_skill("iron-cloth", "jin-gang");
        map_skill("staff", "cloudstaff");
        map_skill("parry", "cloudstaff");        
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "staff.siqijinlong" :),
                (: perform_action, "staff.longxianyuye" :),
        }) );
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 600);         
    
    
    create_family("兴国禅寺", 4, "住持"); 
    setup(); 
    carry_object(__DIR__"obj/staff")->wield();
    carry_object("/clone/misc/cloth")->wear(); 
}  
string ask_for_join()
{
    object me; 
    me = this_player();
            if (me->query("once_menpai/bonze") && me->query("class")!="bonze") {
                command("shake");
                command("say 施主反复无常，没有向佛之心。\n");
                return (string)me;
        }
   if(me->query("marry")){
                message_vision("$N抬头看了看$n：这位施主六根未净，还是请回吧。\n", 
                                this_object(), me);
                return (string)me;
        }       
    if( (string)me->query("class")=="bonze" )
        return "阿弥陀佛！你我同是出家人，何故跟老衲开这等玩笑？\n";
    if( (string)me->query("gender") != "男性" )
        return "阿弥陀佛！女施主，这里是寺庙，请你到尼庵去剃度吧。\n"; 
    me->set_temp("pending/join_bonze", 1);
    return "阿弥陀佛！善哉！善哉！施主若真心皈依我佛，请跪下(kneel)受戒。\n"
        ;
} 
int do_kneel()
{
    string *prename =
        ({ "空", "明", "圆", "净", "虚", "悟",
           "方", "渡", "慧", "法" });
    string name, new_name; 
    if( !this_player()->query_temp("pending/join_bonze") ) return 0;
    message_vision(
        HIC "$N双手合十，恭恭敬敬地跪了下来。\n\n"
        "$n伸出手掌，在$N头顶轻轻地摩挲了几下，将$N的头发尽数剃下．\n\n"NOR,
        this_player(), this_object() );
    name = this_player()->query("name");
    new_name = prename[random(sizeof(prename))] + name[0..1];
    command("say 从今以後你的法名叫做" + new_name + "。");
    command("smile");
    this_player()->delete_temp("pending/join_bonze");
    this_player()->set("name", new_name);
    this_player()->set("class", "bonze"); 
    return 1;
} 
void attempt_apprentice(object ob)
{
    if(ob->query("marry")){
                message_vision("$N抬头看了看$n：这位施主六根未净，还是请回吧。\n", 
                                this_object(), ob);
                return;
     }
    if (ob->query("once_menpai/bonze")) {
                command("shake");
                command("say 施主反复无常，没有向佛之心。\n");
                return;
        }
    
    if( query("apprentice_available") ) {
        if( find_call_out("do_recruit") != -1 )
            command("say 慢著，一个一个来。");
        else
            call_out("do_recruit", 2, ob);
    } else {
        command("say 老纳今天已经收够了弟子，不想再收徒了。");
    }
} 
void do_recruit(object ob)
{
    if( (string)ob->query("gender") != "男性" )
        command("say 阿弥陀佛，女施主不要跟老纳开玩笑。");
    else if( (string)ob->query("class") != "bonze" )
        command("say 阿弥陀佛，施主愿入佛门，请先到小寺剃度出家。");
    else {
        command("say 阿弥陀佛，善哉！善哉！");
        command("recruit " + ob->query("id") );
    }
} 
int recruit_apprentice(object ob)
{
    if( ::recruit_apprentice(ob) ) {
        add("apprentice_availavble", -1);
        return 1;
    }
} 
int accept_fight(object me)
{
    if( (string)me->query("class")=="bonze" )
        command("say 阿弥陀佛！出家人戒逞强恶斗！老衲不敢违反清规。");
    else
        command("say 施主既然身负绝艺，老衲佩服便是，也不必较量了。"); 
    return 0;
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
        if(id_class == "bonze"&& userp(victim)&&player!=victim)
        {
            message_vision(HIW
"$N对$n喝道：阿弥陀佛,出家人与世无争，却也不任人欺侮，施主请了！\n"NOR, this_object(),player);
            this_object()->kill_ob(player);
            player->kill_ob(this_object());
            if (!player->is_busy()) player->start_busy(2);
            return 0;
        } 
    }
    return 0;
}   
