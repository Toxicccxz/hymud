// r_horse.c
// by dicky

inherit NPC;

void create()
{
	set_name("青稞马", ({ "yili horse", "horse"}) ); 

	set("race", "野兽");
	set("gender", "雄性");
	set("unit","匹");
	set("age", 3);
	set("long", "这是一匹有名的青稞马。\n");

	set("str", 24);
	set("cor", 26);
	set("cps", 22);

	set("max_qi", 800);
	set("max_jing", 800);
	set("max_sen", 800);
	set("attitude", "peaceful");
	set("limbs", ({ "头部", "身体", "前蹄", "後蹄", "尾巴" }) );
	set("verbs", ({ "bite", "claw" }) );

	set("bellicosity", 10 ); 

	set_temp("apply/attack", 250);
	set_temp("apply/armor", 350);


	set("ride",1);	// 坐骑标记。

	set("ride_level",3);
	setup();
}
