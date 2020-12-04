 inherit NPC;
#include <ansi.h>
void create()
{
        set_name("小顽童", ({ "smart kid","kid" }) );
        set("gender", "男性" );
        set("title", GRN"精灵古怪"NOR );
        set("age", 12);
        set("str", 15);
        set("cor", 14);
        set("per", 14);
        set("cps", 9);
        set("int", 50);
        set("long", "一个古怪精灵的小顽童，挤眉弄眼得跑跑跳跳个不停。\n");
        set("chat_chance", 1);
        set("chat_msg", ({
        "小顽童嘻嘻笑道：老爷爷，你就算胜了，这样花一般的闺女，叫她一过门就做寡妇么？\n",
                "小顽童盯着瘦和尚的光头笑道：大师傅，要想我不告诉七姨太\n你在外面花差花差，除非。。嘿。\n",
                }) );
        set("combat_exp", 4000);
        set("attitude", "friendly");
        set("max_neili", 500);
        set("neili", 500);
        set("force_factor", 10);
        set_skill("force", 60);
        set_skill("unarmed", 30);
        set_skill("dodge", 60);
        setup();
        carry_object("/clone/misc/cloth")->wear();
}
int accept_fight(object me)
{
        command("say 救命啊！以大欺小！！\n");
        return 0;
} 
