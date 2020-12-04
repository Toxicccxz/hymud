 inherit NPC;
#include <ansi.h> 
void create()
{
        set_name("归东景", ({ "gui", "gui dong jing"}) );
        set("nickname", RED "福星高照"NOR);
        set("gender", "男性" );
        set("age", 44);
        set("per", 25);
        set("int",50);
        set("str",40);
        set("attitude","friendly");
        set("max_neili", 1500);
        set("force", 1500);
        set("force_factor", 90);
        
        set("reward_npc", 1);
        set("difficulty", 5);
        set("long",
                "一张方方正正的脸表情却很丰富，胡子又粗又密，却总是刮得很干净。\n"
        );
        set("chat_chance", 1);
        set("chat_msg", ({
"归东景得意地道：“丁喜，老夫已经重创百里长青，邓定候也成了我
的阶下囚。现在，这个小妞，也落到我的手里....依你的人材武功，
要是愿意和老夫携手，呵呵....称霸武林，指日可待啊。”\n",
        }) );
        set("combat_exp", 3500000);
        
     set_skill("strike",270);
        set_skill("finger",270);
        set_skill("dodge",280);
        set_skill("force", 270);
	set_skill("canhe-zhi", 300);
	set_skill("murong-jianfa",250);       
        set_skill("shenyuan-gong", 250);
	set_skill("yanling-shenfa", 250);   
	set_skill("xingyi-zhang",280);
        set_skill("douzhuan-xingyi", 280);
	set_skill("parry", 280);
	set_skill("sword", 260);
	set_skill("literate", 280);
        set_skill("murong-daofa", 280);
        set_skill("blade",260);
        
        map_skill("blade", "murong-daofa");
        map_skill("finger", "canhe-zhi");
	map_skill("force", "shenyuan-gong");
	map_skill("dodge", "yanling-shenfa");
	map_skill("strike", "xingyi-zhang");
        map_skill("parry", "douzhuan-xingyi");
	map_skill("sword", "murong-jianfa");
         map_skill("strike", "xingyi-zhang");
	prepare_skill("finger","canhe-zhi");
	prepare_skill("strike","xingyi-zhang");

        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 200);
        set_temp("apply/attack", 200);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "parry.xingyi" :),
                 (: perform_action, "parry.yihuajiemu" :),
                (: perform_action, "finger.ci" :),
                (: perform_action, "finger.dianxue" :),
                (: perform_action, "sword.kuangjian" :),
                (: perform_action, "sword.lianhuan" :),
                (: perform_action, "sword.qixing" :),
 		(: command("unwield sword") :),
		(: command("wield sword") :),           
                (: perform_action, "dodge.yanling" :),                
                   (: perform_action, "strike.riyue" :),
                	(: perform_action, "strike.xingdian" :),
        }));
        
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/gangjian")->wield();
} 
void init()
{
        object me;
        ::init();
        if( !query_heart_beat(this_object()) ) set_heart_beat(1); 
        if( interactive(me = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, me);
        }
        add_action("do_killing","kill");
} 
void greeting(object me)
{
        if( !me || environment(me) != environment() ) return;
        if((string)me->name() != "老山东")
        {
                message_vision("$N一见$n来，喝道：“什么人！胆敢乱闯本寨聚义厅，找死！”\n",this_object(),me);
                this_object()->kill_ob(me);
                me->kill_ob(this_object());
        }
        else
        {
                message_vision("$N笑道：“老山东，带了烧鸡来可否？待我与这位小姐风流快活\n一番，再来品尝你的手艺。”\n",this_object(),me);      
                message_vision("$N转头冲王若兰淫笑两声：“小妞，别着急......嘻嘻”\n",this_object(),me);                
        }
} 
int do_killing(string arg)
{
        object me,victim;
        string name;
   me = this_player();
        if( !arg) return 0;
        if( objectp(victim = present(arg, environment(this_object()))) && living(victim))
        {
                name = (string)victim->name();
                if( (string)name == "归东景"&&(string)me->name() == "老山东"&&!me->query("m_success/杀归东景") )
                {
                        message_vision("$N大惊失色道：“你不是老山东”。$n的突然攻击使$N露出了多处破绽！\n",this_object(),me);
                }
                else
                {
                        this_object()->kill_ob(me);
                        me->kill_ob(this_object());
                }
        }
} 
