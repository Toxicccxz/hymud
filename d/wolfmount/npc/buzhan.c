 inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
        set_name("卜战", ({ "master bu", "master" }) );
        set("nickname", HIW"战狼王"NOR);
        set("gender", "男性" );
        set("apprentice_available", 5);
        set("reward_npc", 1);
        set("difficulty", 5);
        set("age", 46);
        set("int", 40);
        set("spi", 25);
        set("cor", 20);
        set("per", 40);
        set("attitude","heroism");
        set("max_neili", 200);
        set("force", 200);
        set("force_factor", 30); 
        set("long",
                "他闪着光的脸虽然枯瘦腊黄，却带着种说不出的慑人气概。\n"
        );
        set("chat_chance", 1);
        set("chat_msg", ({
                "卜战一手紧紧握着旱烟枪：俺那帮好孩儿死得真惨，谁杀了那天杀星常\n无意，老夫必倾囊以授。\n",
        }) );
        create_family("狼山", 3, "大头领");
         set("rank_nogen",1); 
        set("ranks",({ "小喽罗","大喽罗","小头目","大头目","大头领",RED"大盗"NOR,RED"盗帅"NOR,HIR"副山主"NOR }));
        set("combat_exp", 2200000);
        	set("max_qi", 24000);
	set("max_jing", 23000);
	set("neili", 64000);
	set("max_neili", 64000);
	set("jiali", 200);
	set("combat_exp", 9800000);
	set("score", 400000);
      	set_skill("hammer",380);
	set_skill("tiexue-hammer",320);
	set_skill("force", 260);
	set_skill("guiyuan-tunafa", 320);
	set_skill("dodge", 260);
	set_skill("shuishangpiao", 320);
	set_skill("strike", 280);
	set_skill("tiezhang-zhangfa", 350);
	set_skill("parry", 180);
	set_skill("literate", 100);
	set_skill("axe", 380);
	set_skill("duanyun-fu", 350);
	map_skill("hammer", "tiexue-hammer");
	set_skill("duanyun-fu", 350);
	set_skill("tongbi-zhang", 350);
	map_skill("force", "guiyuan-tunafa");
	map_skill("dodge", "shuishangpiao");
	map_skill("unarmed", "tiezhang-zhangfa");
	map_skill("strike", "tongbi-zhang");
	map_skill("parry", "tiezhang-zhangfa");
	prepare_skill("strike", "tiezhang-zhangfa");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "strike.chu" :),
                (: perform_action, "strike.juesha" :),
                (: perform_action, "strike.tui" :),
                (: perform_action, "strike.zhui" :),
                (: perform_action, "hammer.fanzhuan" :),
                (: perform_action, "unarmed.dao" :),
                (: perform_action, "unarmed.ying" :),
                (: perform_action, "unarmed.yin" :),
                (: perform_action, "unarmed.tianlei" :),
                (: perform_action, "unarmed.tiezhangxianglong" :),
                  (: perform_action, "unarmed.zhangdao" :),
		(: command("unwield bighammer") :),
		(: command("wield bighammer") :),
        }) );
        setup();
        carry_object(__DIR__"obj/silkcloth")->wear();
        carry_object(__DIR__"obj/hanyan")->wield();
       carry_object(__DIR__"obj/mysterypicture"); 
} 
void reset()
{
        set("apprentice_available", 5);
} 
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "wolfmount");
        add("apprentice_availavble", -1);
} 
void init()
{       
        ::init();
        add_action("do_killing", "kill");
        if( !query_heart_beat(this_object()) ) {
                set_heart_beat(1); 
        }
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
        if(id_class == "wolfmount"&& userp(victim)&&player!=victim)
        {
            message_vision(HIW
"$N对$n喝道：狼山子弟,同气连枝,不容外人欺侮！\n"NOR, this_object(),player);
            this_object()->kill_ob(player);
            player->kill_ob(this_object());
            if (!player->is_busy()) player->start_busy(2);
            return 0;
        } 
    }
    return 0;
}
