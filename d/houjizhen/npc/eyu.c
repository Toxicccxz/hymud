// eyu.c
// by dicky

inherit NPC;

void create()
{
        set_name("鳄鱼", ({"e yu","eyu"}));
        set("race", "野兽");
        set("age", 100);
        set("long", "一条张开血盆大口的鳄鱼。\n");
        set("attitude", "aggressive");

        set("str", 35);
        set("cor", 35);

        set("limbs", ({ "头部", "身体", "脚部", "尾巴" }) );
        set("verbs", ({ "bite" }) );

        set("combat_exp", 500000);

	set_temp("apply/attack", 300);
	set_temp("apply/damage", 250);
        set_temp("apply/armor", 350);

        setup();
}

void unconcious()
{
        object ob;
        message_vision("$N抽搐了几下，身体缩在一起，死了。\n", this_object());
        ob = new(__DIR__"obj/wuming-blade");
        ob->move(environment(this_object()));
        destruct(this_object());	
}
