 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
#include <combat.h>
int kill_him();
int chuanren();
int leave();
void create()
{
    set_name("任慈", ({ "master renci", "master"}) );
    set("nickname", HIR "前任帮主"NOR);
    set("gender", "男性" );
    set("class","beggar");
    set("reward_npc", 1);
    set("difficulty", 15);
    set("age", 64);
    set("per", 25);
    set("int",30);
    set("str",36);
    set("attitude","friendly");
    
    set("max_neili", 1000);
    set("neili", 1000);
    set("force_factor", 90);
    
    set("long", "任慈是丐帮的前任帮主，只因近来身体多病才让位于南宫\n");
    create_family("丐帮", 6, "前任帮主");
    set("rank_nogen",1);
    set("ranks",({"堂外弟子","一袋弟子","两袋弟子","三袋弟子","四袋弟子",
                      "五袋弟子","六袋弟子","七袋弟子","八袋弟子",WHT"九袋弟子"NOR,
                      WHT"长老"NOR,HIW"龙头大哥"NOR}));
    set("rank_levels",({ 32000,64000,128000,256000,512000,
                             1024000,1536000,2304000,3456000,
                             5187000,26244000 }));     
    set("chat_chance_combat", 50);
    set("chat_msg_combat", ({
        (: perform_action, "unarmed.xianglongwuhui" :)
            }) );
        set("resistance/kee",50);
        set("resistance/gin",40);
        set("resistance/sen",40);
        
    set("combat_exp", 4000000);
    
  	set("qi", 25000);
	set("max_qi", 25000);
	set("jing", 22400);
	set("max_jing", 22400);
	set("neili", 58000);
	set("max_neili", 58000);
	set("jiali", 300);
	
	set("combat_exp", 8000000);
	set("score", 200000);
	set("shen", 100000);
	 
		set_skill("fengmo-zhang",380);
	set_skill("liuhe-zhang",380);
	set_skill("strike",390);
	set_skill("force", 300);             // 基本内功
	set_skill("huntian-qigong", 380);    // 混天气功
	set_skill("unarmed", 260);           // 基本拳脚
	set_skill("xianglong-zhang", 380);   // 降龙十八掌
	set_skill("dodge", 260);      	     // 基本躲闪
	set_skill("xiaoyaoyou", 380);        // 逍遥游
	set_skill("parry", 260);             // 基本招架
	set_skill("staff", 380);             // 基本棍杖
	set_skill("dagou-bang", 380);        // 打狗棒法
	set_skill("begging", 380);           // 叫化绝活
	set_skill("checking", 380);          // 道听途说
	set_skill("training", 380);         // 驭兽术
	
	map_skill("force", "huntian-qigong");
	map_skill("unarmed", "xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("parry", "dagou-bang");
	map_skill("staff", "dagou-bang");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "staff.chan" :),
                (: perform_action, "staff.ban" :),
                (: perform_action, "staff.feng" :),
                (: perform_action, "staff.zhuan" :),
                (: perform_action, "staff.luanda" :),
                (: perform_action, "staff.luanda" :),
                (: perform_action, "staff.luanda" :),
                (: perform_action, "staff.wugou" :),                
                (: command("unwield yuzhu zhang") :),
                (: command("wield yuzhu zhang") :),
                (: perform_action, "unarmed.kanglongwuhui" :),                
                (: perform_action, "unarmed.kanglongwuhui" :),                
                (: perform_action, "unarmed.kanglongwuhui" :),                
                (: perform_action, "unarmed.hui" :),                
                (: perform_action, "unarmed.fei" :),                
                (: perform_action, "unarmed.qu" :),                
                (: perform_action, "unarmed.zhen" :),                
                (: perform_action, "unarmed.leiting" :),                
                (: perform_action, "unarmed.xianglong" :),                                
                (: perform_action, "dodge.canghaiyixiao" :),                                
                (: perform_action, "dodge.maishou" :),                                
        }) );

     
    set("inquiry", ([
        "南宫灵" : (: kill_him :),
        "master nangong" : (: kill_him :),
        "chuanren" : (: chuanren :),
        "传人" : (: chuanren :),
        "leave" : (: leave :),
    ]));
	set_temp("apply/attack",200);
	set_temp("apply/defense",200);
	set_temp("apply/armor",500);
	set_temp("apply/damage",400);
    setup();
    carry_object(__DIR__"obj/9bagcloth")->wear();
        set_temp("apply/dodge",200);
        
}
void init(){
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
            remove_call_out("greeting");
            call_out("greeting", 2, ob);
        }
        add_action("do_killing", "kill");
} 
void greeting(object ob){
        if( !ob || environment(ob) != environment() ) return;
        if(!environment(this_object())->query("have_staff")) return;
        message_vision("\n$N颤巍巍地抬起头看了看$n，叹了口气道：“何时才能找到的丐帮传人？\n",
                        this_object(), ob); 
        message_vision("让我丐帮不落入奸人之手。。。”\n", this_object());
} 
void attempt_apprentice(object me)
{
    if(me->query("m_success/智平武林风波") && me->query("combat_exp")>1000000){
                command("say 看在你为武林除一大害的份上，我就收你为徒吧！\n");
        command("recruit " + me->query("id") );
    } else {
                command("sigh");
        command("say 我已经不再是帮主了，体力不行了，就只记得一点丐帮的绝技，你还是去找南宫吧！\n");
    }
} 
void recruit_apprentice(object ob){
    if( ::recruit_apprentice(ob) )
        ob->set("class", "beggar");
} 
int kill_him(){
    command("say 南宫对我甚为孝顺，每天清粥一碗，从未间断！\n");
    return 1;
} 
int chuanren(){
        object me, con, ob;
        string rank;
        me = this_player();
        if(!environment(this_object())->query("have_staff")){
           message_vision("$N摇摇头道：“丐帮已有传人。”\n", this_object());
                return 1;
        }
    rank = me->query("family/title");
    if(me->query("class") != "beggar"){ 
                message_vision("$N摇了摇头道：“你非我丐帮弟子，无法成为丐帮传人。”\n", this_object());
    } else if(rank == WHT"九袋弟子"NOR || rank == WHT"长老"NOR
            || rank == HIW"龙头大哥"NOR){
                message_vision("$N无神的双目突然亮了起来，沉吟半晌道：“你可愿与老朽过过招？若是赢了我这把老骨头，
那才。。。 （ｃｈａｌｌｅｎｇｅ）\n", this_object());
                add_action("do_challenge", "challenge");        
        } else {
                message_vision("$N强力从床上挣扎起来，盯着$n看了半天叹了口气，摇了摇头。\n", this_object(), me); 
        }
        return 1;
} 
int do_challenge(){
        object me, ob;
        int i;
        me = this_player();
        
        delete_temp("last_damage_from");
        message_vision("\n$N道：“接招。。。。”\n", this_object());
        for(i=0; i<10; i++) {
                 COMBAT_D->do_attack(me,this_object(),me->query_temp("weapon"));
            if(query_temp("last_damage_from") == me) {
                    break;
            }
        }
        if(query_temp("last_damage_from") == me) {
                message_vision("$N老泪纵横道：“好好，终于找到可造之才了，丐帮有救了。。。” \n", this_object());
                ob = new(__DIR__"obj/zhustaff");
                if(objectp(ob)){
                        message_vision("$N颤巍巍交给$n一根打狗棍，肃然道：“接下打狗棍，丐帮复兴这千钧重担就给你了。。”\n",
                                        this_object(), me); 
                        ob->move(me);
            me->set("title", "丐帮 第七代传人");
                        environment(this_object())->set("have_staff", 0);
                }
        } else {
   message_vision("$N摇头叹了口气。\n", this_object());
        }
        return 1;
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
        if(id_class == "beggar"&& userp(victim)&& player!=victim)
        {
            message_vision(HIW
"$N颤巍巍地道：对老夫的恩人无礼，老夫就是拼了这最后一口气也不会让你得逞！\n"NOR, this_object());
            this_object()->kill_ob(player);
            player->kill_ob(this_object());
            if (!player->is_busy()) player->start_busy(2);
            return 0;
        } 
    }
    return 0;
} 
int leave() {
        if (this_player()->query("class")!="beggar") return 0;
        message_vision(CYN"$N叹了口气道，“丐帮没指望了。“\n"NOR, this_object());
        message_vision(CYN"$N说：打狗棒法和混饨心诀是祖师爷留下来的，你走了就学不会了。\n"NOR,this_object());
        return 1;
}     
