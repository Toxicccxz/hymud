
inherit NPC;

void create()
{
        set_name("小白兔", ({ "bai tu","tu"}) );
        set("race", "野兽");
        set("age", 2);
        set("long", "一只毛色雪白的小兔子，两只眼睛红红的,鼻子一煽一煽。\n"
                    "好可爱呦！\n");

        set("limbs", ({ "头部", "身体", "尾巴" }) );
        set("verbs", ({ "bite" }) );
        set("combat_exp", 800);
        setup();
}


