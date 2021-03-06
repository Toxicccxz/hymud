 inherit NPC;
// inherit  F_MASTER;
void create()
{
    set_name("谢掌柜", ({ "xie zhanggui"}) );
    set("gender", "男性" );
    set("age", 42);
        set("title","神剑山庄 第二代无为清静楼掌柜");
    set("long",
        "这就是无为清静楼谢掌柜，大家一般叫他谢先生，据说武功已出神入化。\n");
    set("combat_exp", 3000000);
    set("reward_npc", 1);
    set("difficulty", 10); 
    set("attitude", "friendly");
    set("max_neili",1000);
    set("neili",1000);
    set("force_factor",60);
    set("atman",1000);
    set("max_atman",1000);
    set("fly_target",1);
set("max_qi", 22000);
	set("max_jing", 21000);
	set("neili", 43000);
	set("max_neili", 43000);
	set("jiali", 100);
	set("combat_exp", 8800000);
	set("score", 500000);

	set_skill("literate", 260);
	set_skill("force", 260);
	set_skill("dodge", 260);
	set_skill("unarmed", 260);
	set_skill("parry", 260);
	set_skill("whip", 300);
	set_skill("blade", 300);
	set_skill("sword", 300);
	set_skill("hand", 260);
	set_skill("claw", 300);
	set_skill("cuff", 300);
	set_skill("strike", 300);
	set_skill("houquan", 390);
	set_skill("yunlong-xinfa", 380);
	set_skill("yunlong-shengong", 380);
	set_skill("wuhu-duanmendao", 380);
	set_skill("yunlong-jian", 380);
	set_skill("yunlong-shenfa", 380);
	set_skill("yunlong-bian", 380);
	set_skill("yunlong-shou", 380);
	set_skill("yunlong-zhua", 380);
	set_skill("baihua-cuoquan", 380);
set_skill("bazhen-zhang", 380);

	map_skill("dodge", "yunlong-shenfa");
	map_skill("force", "yunlong-shengong");
	map_skill("unarmed", "baihua-cuoquan");
	map_skill("blade", "wuhu-duanmendao");
	map_skill("hand", "yunlong-shou");
	map_skill("parry", "baihua-cuoquan");
	map_skill("claw", "yunlong-zhua");
	map_skill("sword", "yunlong-jian");
	map_skill("whip", "yunlong-bian");

	map_skill("cuff", "baihua-cuoquan");
	map_skill("strike", "bazhen-zhang");
	
	prepare_skill("cuff", "baihua-cuoquan");
	prepare_skill("strike", "bazhen-zhang");

set("chat_chance_combat", 90);  
	set("chat_msg_combat", ({
                (: perform_action, "sword.slj" :),
                (: perform_action, "sword.duoming" :),
                (: perform_action, "sword.guang" :),
                (: perform_action, "sword.shen" :),
                (: perform_action, "sword.xunlei" :),
                (: perform_action, "sword.xian" :),

                (: perform_action, "cuff.hong" :),
                (: perform_action, "cuff.luan" :),
                (: perform_action, "cuff.yi" :),                	                	
                                
                (: perform_action, "strike.bafang" :),
                (: perform_action, "strike.baxianzuijiu" :),
                (: perform_action, "strike.jueming" :),                	                	


                (: perform_action, "claw.ji" :),
                (: perform_action, "claw.ningxue" :),
	}) );
/*
    create_family("神剑山庄", 2, "无为清静楼掌柜");
    set("rank_nogen",1);
    set("ranks",({"剑奴","剑手","剑士","剑侠","剑王","剑帝","剑圣","剑魂",
                      "剑罡","剑煞","剑仙","剑神"}));
    set("rank_levels",({ 32000,64000,128000,256000,512000,
                             1024000,1536000,2304000,3456000,
                             5187000,26244000 }));
*/ 
    set("chat_chance", 1);
    set("chat_msg", ({
        name()+"道：没想到无情小子在三少爷面前居然这么不堪一击。\n",
            name()+"道：你要去隐世楼非得杀了我才行。\n",
            }) );
    setup();
    add_money("coin", 50);
    carry_object(__DIR__"obj/qingcloth")->wear();
    carry_object(__DIR__"obj/blade")->wield();
} 
void init()
{
        object me,meizhi;
        if(interactive(me = this_player()) && !me->is_fighting() && userp(me) && me->query("marks/东林_神剑_燕十三"))
        {
                remove_call_out("greeting");
                call_out("greeting",2,me);
        }
        add_action("do_answer","answer");
}
void greeting(object me)
{
        if (objectp(me) && present(me,environment(this_object())))
        {
                if (!me->query_temp("pass_xiezhanggui"))
                {
                        message_vision("$N看了$n一眼，冷冷地说：“凭你的功夫，也想去挑战燕十三？ 
你见过燕十三的剑法吗？” (answer yes/no) \n",this_object(),me);
                        me->set_temp("inask",1); 
                }
                
        }
} 
int do_answer(string arg)
{
        object me;
        me = this_player();
        if (arg != "yes" && arg != "no")
   {
                return notify_fail("你只可答yes/no \n");
        }
        if (!me->query_temp("inask"))
        {
                return 0;
        }
        me->delete_temp("inask");
        if (arg == "yes")
        {
                message_vision("$N眼睛一亮，对$n道：“那你给我看看(show)他的剑法是什么样的？” \n",this_object(),me);
                add_action("do_show","show");
        }else
        {
                message_vision("$N对$n说“你连他的剑法都没见过，就不要去送死了。” \n",this_object(),me);
        }
        return 1;
} 
int do_show(string arg)
{
        object me,meizhi;
        me = this_player();
        if (arg != "meizhi" && arg != "削断的梅枝" && arg != "梅枝")
        {
                return 0;
        }
        if (!present("meizhi",me))
        {
                return notify_fail("你身上没有这样东西。\n");
        }
        if (me->query_temp("pass_xiezhanggui"))
        {
                return 0;
        }
        message_vision( "$n拿出削断的梅枝，稳稳地横在$N眼前。 
$N看着梅枝的断口，脸色渐渐变得灰暗，失魂落魄的 
呐呐道：“第十五剑，第十五剑。。。 你去吧。”\n ",this_object(),me);
        me->set_temp("pass_xiezhanggui",1);
        return 1; 
} 
/*
 void attempt_apprentice(object me)
{
    command("say 我只会几招三脚猫的功夫。。。\n");
    me->add_temp("tried",1);
    if(me->query_temp("tried") < random(10)+10)
        return;
    else
        command("smile");
    command("recruit " + me->query("id") );
    return;
} 
void recruit_apprentice(object ob)
{
    if( ::recruit_apprentice(ob) )
        ob->set("class", "blademan");
}
*/    
