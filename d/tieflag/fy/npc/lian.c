 inherit NPC;
#include <ansi.h>
inherit F_MASTER;
int time_period(int timep, object me);
int give_hint();
string sysmsg;
void create()
{
        set_name(HIG"连城璧"NOR, ({ "lian", "lian cheng bi", "chengbi" }) ); 
        set("gender", "男性");
        set("age", 29);
        set("long",
"当代武林年青一代中的领袖，无垢山庄的少主，万人仰慕的绝世奇才\n");
        set("attitude", "peaceful");
        set("str", 40);
        set("cor", 30);
        set("int", 24);
        set("cps", 30);
        set("chat_chance", 1);
        set("chat_msg", ({
                "连城璧向你拱了拱手道：＂这位英雄，今朝相遇，我连某深感荣幸！＂\n",
        }) );

        set("neili", 4000);
        set("max_neili", 80000);
        set("force_factor", 40); 
        set("combat_exp", 10000000);
        set("chat_chance", 5);
        set("chat_msg", ({
                (: random_move :),
        }) );
        set_skill("unarmed", 180);
        set_skill("force", 100);
        set_skill("iron-cloth", 100);
        set_temp("apply/attack",300);
        set_temp("apply/dodge", 200);
        set_temp("apply/parry", 200);
   set_temp("apply/damage",300); 
        set("title", "德高望重");
        setup(); 
        carry_object("/clone/misc/cloth")->wear();
}
int accept_fight(object me)
{
        command("say 想砌蹉武功！好！我连某理应奉陪，但拳脚无情，你小心了！");
        return 1;
}
