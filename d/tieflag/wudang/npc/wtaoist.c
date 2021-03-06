#include <ansi.h>
inherit NPC; 
void create()
{
        set_name("知客道人", ({ "waiter taoist", "taoist", "waiter" }) );
        set("gender", "男性");
        set("long",
                "武当派知客道人，身着青色道袍、头戴黄色道冠。\n"
        );
        set("combat_exp", 10000+random(20000));
        set("score", 200);
        set("class", "wudang");
        set("neili", random(300));
        set("max_neili", random(300)); 
        create_family("武当派", 58, "弟子"); 
        set("qi", 28000);
	set("max_qi", 28000);
	set("jing", 28000);
	set("max_jing", 28000);
	set("neili", 55000);
	set("max_neili", 55000);
	set("jiali", 100);
	set("combat_exp", 9000000);
	set("score", 600000);
	set("shen", 200000);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.zong" :),
                (: perform_action, "unarmed.zhenup" :),
                (: perform_action, "unarmed.tu" :),
                (: perform_action, "unarmed.zhan" :),
                (: perform_action, "unarmed.ji" :),
                (: perform_action, "unarmed.jielidali" :),
                (: perform_action, "hand.leiting" :),
                (: perform_action, "hand.mian" :),
                (: perform_action, "strike.zheng" :),	
                (: perform_action, "sword.lian" :),
                (: perform_action, "sword.chan" :),
                (: perform_action, "sword.chanup" :),
                (: perform_action, "sword.sui" :),
                (: perform_action, "sword.lian" :),
                (: perform_action, "sword.zhenwu" :),
                (: perform_action, "sword.lian" :),                
        }) );
set_skill("claw", 250);
set_skill("strike", 380);
	set_skill("force", 550);
	set_skill("taiji-shengong", 380);
	set_skill("dodge", 150);
	set_skill("tiyunzong", 380);
	set_skill("unarmed", 200);
	set_skill("taiji-quan", 380);
	set_skill("parry", 300);
	set_skill("sword", 300);
	set_skill("taiji-jian", 380);
	set_skill("liangyi-jian", 150);
	set_skill("wudang-array", 380);
	set_skill("array",100);
	set_skill("taoism", 500);
	set_skill("literate", 200);
	set_skill("yitian-tulong", 380);
	set_skill("juehu-shou", 380);
	set_skill("raozhi-roujian", 380);
	set_skill("wudang-mianzhang", 380);
	set_skill("hand", 280);
	set_skill("paiyun-shou", 380);
	set_skill("shenmen-jian", 380);
	set_skill("yitian-zhang", 280);
	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "taiji-quan");
	map_skill("sword", "taiji-jian");
		map_skill("hand", "paiyun-shou");
        
        setup(); 
        carry_object(__DIR__"obj/cloth1")->wear();
        carry_object(__DIR__"obj/hat")->wear(); 
} 
void init()
{
        object          me; 
        ::init();
        if( interactive(me = this_player()) && !is_fighting() ) {
                if( me->query_temp("marks/许廉龙")) call_out("rockkill", 1, me);
                if( me->query_temp("marks/偷书"))   call_out("stealbook", 1, me);
                if( me->query_temp("marks/七星剑")) call_out("stealsword", 1, me);
        }
} 
int accept_fight(object me)
{
        if( (string)me->query("family/family_name")=="武当派" ) {
                command("nod");
                command("say 进招吧。");
                return 1;
        }
        command("say 武当派不和别派的人过招。");
        return 0;
}  
int rockkill(object me)
{
        me->set_temp("marks/许廉龙", 0);
        message_vision(HIR"知客道人对$N喝道：" + RANK_D->query_rude(me)+"，竟敢在武当山杀我武当弟子！拿命来！\n"NOR,me);
        this_object()->kill_ob(me);
        return 1;
}
 
int stealbook(object me)
{
        me->set_temp("marks/偷书", 0);
        if(random(me->query("kar")) < 15) {
                say( HIR "知客道人对" + me->name() + "喝道：" + RANK_D->query_rude(me)
                        + "，竟敢在武当山偷东西！拿命来！\n"NOR);
                this_object()->kill_ob(me);
        }
        return 1;
} 
/*
int stealsword(object me)
{
        string  *skname;
        mapping skills;
   int     i; 
        me->set_temp("marks/七星剑", 0);
        if(random(me->query("kar")) < 29){
                if( (string)me->query("family/family_name")=="武当派" ) {
                        say( HIR "知客道人对" + me->name() + "喝道：" + RANK_D->query_rude(me)
                        + "，你身为武当弟子，竟敢偷我武当山镇山之宝！你不配作武当弟子！\n"NOR);
                        me->delete("family");
                        me->set("title", "武当弃徒");
                        me->set("score", 0);
                        skills = me->query_skills();
                        if( mapp(skills) ) {
                                skname = keys(skills);
                                for(i=0; i<sizeof(skname); i++)
                                skills[skname[i]] /= 2;
                        }
                        me->add("betrayer", 1);
                        me->set("marks/武当弃徒", 1);
                        tell_object(me, "\n你被开革出师门了！\n\n");
                }
                else {
                        say( HIR "知客道人对" + me->name() + "喝道：" + RANK_D->query_rude(me)
                                + "，竟敢偷我武当山镇山之宝！拿命来！\n"NOR);
                        this_object()->kill_ob(me);                
                }
        }
        return 1;
}
*/ 
