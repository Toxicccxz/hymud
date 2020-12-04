// gargoyle.c

#include <ansi.h>
#include <login.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("王方平", ({ "wang fangping", "wang", "fangping" }));

set("long","王方平本是山中道士，后在丰都山同阴长生同修炼成仙，御封(「鬼王」。\n");
        set("attitude", "peaceful");
	set("per", 30);
	set("str", 25);
	set("int", 25);
        set("age", 30);
	set("title", "轮回司主");
	set("nickname", "鬼王");
        set("combat_exp", 850000);
  set("daoxing", 600000);

        set("max_gin", 1400);
        set("max_kee", 1400);
        set("max_sen", 1400);
	set("class", "youling");
	set("force", 2500);
	set("max_force", 1500);
	set("force_factor", 100);
	set("max_mana", 1500);
	set("mana", 2500);
	set("mana_factor", 100);




        set("nkgain", 400);

	set_temp("apply/dodge", 50);
	set_temp("apply/armor", 50);


create_family("阎罗地府", 2, "你好");

        setup();
	carry_object("/d/obj/weapon/stick/wuchangbang")->wield();
	carry_object("/d/obj/cloth/taijicloth")->wear();
}


void attempt_apprentice()
{
	object me;
	me = this_player();
        command("grin");

        command("say 很好，" + RANK_D->query_respect(me) +
"多加努力，他日必定有成。\n");
       command("recruit " + me->query("id") );
	me->set("class", "youling");
        return;
}
/*
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "youling");
		ob->set("title", "地府招魂司阴兵");
}

*/
�
