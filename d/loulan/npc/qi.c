#include <ansi.h>
inherit F_MASTER;
inherit NPC;
int leave(); 
void create()
{
        set_name("独孤伤", ({ "dugu shang","dugu" }) );
        set("gender", "男性" );
        set("long",
"一个竹竿般瘦骨嶙峋的中年人，一件黑油油的皮衣像是蛇皮般裹在身上，\n整个人也像是条毒蛇，每一分，每一寸都潜伏着不可测量的凶险，正是快\n活王手下四使之气使，快活王手下第一高手。\n"
        );
        create_family("快活林", 1, "气使");
        set("attitude", "peaceful");
        set("rank_nogen",1);
        set("class","knight");
        set("reward_npc", 1);
        set("difficulty", 5);
    set("ranks",({"弟子","骑士","铁骑卫","铁骑统领","铁骑使",RED"欢乐右使"NOR,RED"欢乐左使"NOR,HIR"一字并肩王"NOR}));
        set("chat_chance_combat",50);
        set("chat_msg_combat",({
        (:perform_action,"axe.guifushengong":),
        (:perform_action,"dodge.fengliu":),
                }));
        set("age", 45);
        set("str", 30);
        set("cps", 40);
        set("int", 10);
        set("per", 4);
        set("cor", 40);
        set("agi", 30);
        set("combat_exp", 5500000);
        set("force_factor", 50);
        set_temp("apply/armor",50);
        set_temp("apply/damage",50);
        set("chat_chance", 1);
        set("chat_msg", ({
                "独孤伤冷哼一声，斜斜瞥了你一眼。\n",
        }) );
        set("combat_exp", 10000000);
        set("score", 200000);

        set_skill("dodge", 100);
        set_skill("parry",100);
        set_skill("dodge", 100);
        set_skill("force", 100);
        set_skill("literate", 80);
	set_skill("unarmed",260);
	set_skill("demon-steps",500);
	set_skill("demon-strike",500);
	set_skill("demon-force",500);
	set_skill("blade",150);
	set_skill("demon-blade",550);
	set_skill("xuanyuan-axe",550);
        map_skill("dodge", "demon-steps");
	map_skill("force", "demon-force");
	map_skill("unarmed", "demon-strike");
	map_skill("blade","demon-blade");
	map_skill("axe","xuanyuan-axe");
	map_skill("parry","demon-blade");

set("pubmaster",1);
        set("max_neili", 55000);
        set("neili", 55000);
        set("force_factor", 30);
	set("max_qi",92999);
        set("max_jing",29999);
	set("eff_qi",29999);
	set("qi",29999);
	set("eff_jing",29999);
	set("jing",29999);
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 600);
        setup();
  carry_object("clone/weapon/axe")->wield();
        carry_object(__DIR__"obj/foxcloth")->wear();
} 
void attempt_apprentice(object me)
{
        command("smile");
        command("recruit " + me->query("id") );
                return;
} 

int accept_fight(object me)
{
        if(me->query("family/family_name") == query("family/family_name") &&
           me->query("family/master_id") == query("id"))
        {
                command("say 好，你赢了我，你就可以去跟王爷学习了！\n");
           return 1;
        }
        else
        {
                command("say 无知小辈！关夫子门前卖大刀，让老夫教训你一下也好！\n");
                return 1;
        }
} 
void win_enemy(object loser)
{
    command("say 不成器的庸才！\n");
} 
void lose_enemy(object winner)
{
    command("say 哎，老了。。\n");
    winner->set_temp("marks/knight_win_dugu",1);
}  
int leave() {
        if (this_player()->query("class")!="knight") return 0;
        message_vision(CYN"$N一脚踢在$n的屁股上。\n"NOR, this_object(),this_player());
        message_vision(CYN"$N说：以后你的轩辕斧使不利索可别怪我。\n"NOR,this_object(),this_player());
        return 1;
}   
