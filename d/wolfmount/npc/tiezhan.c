 inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int got_me();
int leave();
void create()
{
        set_name("铁战", ({ "master tiezhan", "master"}) );
    set("nickname", HIY "战狼盗"NOR);
        set("gender", "男性" );
        set("age", 34);
        set("agi",30);
        set("per", 35);
        set("int",30);
        set("reward_npc", 1);
        set("difficulty", 2);
        set("attitude","friendly");
        set("max_neili", 1500);
        set("force", 1500);
        set("long","一个敞着衣襟，豪迈不羁的大汉；让人一见就觉得此人够义气。\n"); 
        create_family("狼山", 4, "大头领");
       set("rank_nogen",1); 
    set("student_title","巡山盗");
  
      set("inquiry", ([
           "leave" : (: leave :),
        ]) );
        
    set("combat_exp", 800000);
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
        carry_object(__DIR__"obj/cloth")->wear();
        carry_object(__DIR__"obj/pifeng")->wear();
    carry_object(__DIR__"obj/stonehammer")->wield();  
} 

int accept_fight(object me)
{
        if(me->query("class") == "wolfmount")
        {
            command("say 好！赢了我，你就可以去找狼山中更高深的师傅了！\n");
                return 1;
        }
        else
        {
                command("say 开什么玩笑？老子从来不打架，要动手就玩真的！\n");
                return 0;
        }
} 
void win_enemy(object loser)
{
    command("say 你就这点能耐啊？别跟别人说我是你师傅，丢人！丢人！\n");
} 
void lose_enemy(object winner)
{
    command("say 乖徒儿，不错不错。有前途！到山上找师爷师公学去吧。\n");
        winner->set_temp("marks/wolf_win_tiezhan",1);
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
int leave() {
        if (this_player()->query("class")!="wolfmount") return 0;
        message_vision(CYN"$N不屑地看了你一眼。\n"NOR, this_object(),this_player());
        message_vision(CYN"$N说：想走可以，以后别指望咱狼山的独门特技。\n"NOR,this_object(),this_player());
        return 1;
}        
