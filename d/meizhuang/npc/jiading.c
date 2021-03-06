// jiading.c
inherit NPC;

void create()
{
        set_name("家丁", ({
                "jia ding",
                "ding",
        }));
        set("long",
                "他是一位身着青衣的梅庄家丁，衣服的袖口上绣着一朵梅花。\n"
                "手中拿着一对判官笔，似乎有一身武艺。\n"
        );

        set("gender", "男性");
        set("attitude", "aggressive");
        set("class", "fighter");

        set("age", 20);
        set("shen_type", 1);
        set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 20);
        set("max_qi", 500);
        set("max_jing", 300);
        set("neili", 500);
        set("max_neili", 500);
        set("pursuer", 1);
        set("combat_exp", 2000);
        set("score", 1);

        set_skill("force", 90);
        set_skill("dodge", 90);
        set_skill("unarmed", 90);
        set_skill("parry", 90);
        set_skill("blade", 90);

create_family("梅庄", 3, "弟子");
        setup();

        carry_object(__DIR__"obj/panguan-bi")->wield();
        carry_object(__DIR__"obj/qingyi")->wield();
}

void init()
{
        object ob = this_player();

        ::init();

        if (interactive(ob))
        {
                remove_call_out("kill_ob");
                call_out("kill_ob", 1, ob);
        }
}

