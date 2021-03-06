#include <ansi.h>
inherit NPC;
void smart_fight();
void smart_busy();
void smart_attack(); 
void create()
{
    set_name( "王若兰", ({ "wang ruolan", "wang","ruolan" }) );
        set("long", "王若兰是王老镖头的独生女儿，也是当今霸王枪法的唯一传人。
一袭白衣，显出她浮凸有致的娇好身材。一对秋水搬的双眸，正幽怨的望着丁喜。\n");
        set("attitude", "friendly");
        set("title", HIM "如花似玉"NOR);
        set("age", 17);
        set("gender", "女性" );
        set("cor", 40);
        set("cps", 25);
        set("per", 60);
        set("class","fugui");
        set("combat_exp", 4000000);
        set("reward_npc", 1);
        set("difficulty", 5);
        
        set("resistance/kee",30);
        set("resistance/gin",20);
        set("resistance/sen",30);
        
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: smart_fight() :),    
        }) ); 
        set("force",1000);
        set("max_neili",1000);
        set("force_factor",100);
        
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
	 
 	set_skill("fengmo-zhang",180);
	set_skill("liuhe-zhang",180);
set_skill("dagou-bang",80);
	set_skill("strike",190);
	set_skill("force", 250);             // 
	set_skill("force", 180);             // 基本内功
	set_skill("huntian-qigong", 330);    // 混天气功
	set_skill("dodge", 150);      	     // 基本躲闪
	set_skill("xiaoyaoyou", 320);        // 逍遥游
	set_skill("parry", 150);             // 基本招架
	set_skill("hand", 200);              // 基本手法

	set_skill("blade", 180);             // 基本刀法
	set_skill("liuhe-dao", 280);       // 四象六合刀
	set_skill("begging", 200);           // 叫化绝活
	set_skill("checking", 200);          // 道听途说
	set_skill("training", 200);          // 驭兽术
	set_skill("strike",285);  // 基本掌法

	set_skill("xianglong-zhang",285);

	map_skill("strike","lianhua-zhang");
	prepare_skill("strike","lianhua-zhang");

	
	map_skill("force", "huntian-qigong");
	map_skill("hand",  "suohou-gong");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("blade", "liuhe-blade");
	map_skill("parry", "yuejia-qiang");

	set_skill("yuejia-qiang", 380);        // 打狗棒法
	set_skill("suohou-gong", 380);        // 打狗棒法
set_skill("chansi-shou", 380);        // 打狗棒法
set_skill("claw", 380);        // 打狗棒法
set_skill("hand", 380);        // 打狗棒法	
set_skill("club", 380);        // 打狗棒法		
map_skill("parry", "yuejia-qiang");
map_skill("club", "yuejia-qiang");
map_skill("claw", "suohou-gong");
map_skill("hand", "chansi-shou");

	prepare_skill("hand",  "chansi-shou");
prepare_skill("claw",  "suohou-gong");


       set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "club.gong" :),
                (: perform_action, "club.qldj" :),
                (: perform_action, "club.zhtx" :),
                (: perform_action, "claw.suo" :),
                (: perform_action, "hand.qin" :),                
                (: perform_action, "hand.qinna" :),                
                (: perform_action, "dodge.gjtq" :),                                
                (: perform_action, "dodge.canghaiyixiao" :),                                
                (: perform_action, "dodge.maishou" :),                                
        }) ); 
        
        setup();
        carry_object(__DIR__"obj/white_cloth")->wear();
        carry_object(__DIR__"obj/gold_spear")->wield();
        add_money("gold", 5);
} 
int accept_object(object me, object obj)
{
        object book;
        if( (string) obj->query("name") == HIR"霸王枪"NOR)
        {
                message_vision("$N向$n道了个万福：\n",this_object(),me);
                command("smile");
                command("say 多谢这位" + RANK_D->query_respect(me) + "替我找回了丢失的霸王枪。\n");
                
                if (me->query("m_killer/归东景")) {
                        command ("say 作为答谢，这本霸王枪谱，就送给您吧！");
                        book = new(__DIR__"obj/bw_book");
                        if(book) book->move(me);
                        book = new(__DIR__"obj/spear_book");
                        if(book) book->move(me);
                        message_vision("$N从怀中掏出两本枪谱送给$n。\n",this_object(),me);
                } else
                        message_vision("$N似乎想从怀里拿些什么，看看四周，犹豫了一下又停住了。\n",this_object());
                if(!me->query("m_success/还霸王枪"))
                {
                        me->add("score",100);
                        me->set("m_success/还霸王枪",1);
                }
           return 1;       
        }
        else
        {
                command("lean");
                command("say 多谢这位" + RANK_D->query_respect(me) + "，什么我都不要，只要他在我身边就好。\n");
                return 0;
        }  
        return 1;
} 
