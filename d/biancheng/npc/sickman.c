#include <ansi.h>
//inherit "/d/taiping/npc/smart_npc"; 
inherit NPC;
int show_me(); 
void create()
{
        set_name("陶保义",({"tao baoyi","tao","baoyi"}));
        set("title","忧心忡忡");
        set("long","陶保义是赶车的把式，自从前年媳妇得了种怪病，到处投医，家里变得越来越穷。\n");
        
        set("gender","男性");
        set("attitude", "friendly");
        set("group","citizen");
        
        set("combat_exp",500000);  
        set("age",42);
                
        set("int",40);
        set("cor",40);
        set("cps",40);
        
        set_skill("unarmed",200);
        set_skill("dodge",150);
        set_skill("parry",160);
        set_skill("force",180);
        set_skill("move",200); 
                
        set("max_neili",200+random(500));
        set("neili",query("max_neili"));
        set("force_factor",30);
        
        
        set("inquiry", ([
                "陶氏" :        (: show_me :),
                "媳妇" :         (: show_me :),
                "怪病" :         (: show_me :),
                "病" :           (: show_me :),
                "新药" :         (: show_me :),
                "药" :          (: show_me :),
                "药方" :        "这药方要龙鲤鱼作药引子，我上哪儿去找呀？\n",
                "龙鲤鱼" :      "我上哪儿去找龙鲤鱼呀？\n",
                "药引子" :      "我上哪儿去找龙鲤鱼呀？\n",
        ])); 
        set("death_msg",CYN"\n$N恨恨地说：“你的心真狠，连穷人都不放过。”\n"NOR);      
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([
                10: name()+"叫道：“来人啊，强盗上门抢劫啦！”\n", 
        ]) );      
        set("chat_chance_combat", 100);
/*        set("chat_msg_combat", ({
             (: auto_smart_fight(20) :),
        }) );*/
        set("chat_chance",1);
        set("chat_msg",({
//              name()+"捶着脑袋长呼短吁地说：“看来孩子他娘是熬不过这个大年了。。”\n",
        }) );                   
        
        setup();
        carry_object("/clone/misc/cloth")->wear();    
}   
int show_me()   {
        object me,ob;
        
        me=this_player();
        ob=this_object();
        if (me->query("wanma/义助陶氏")) {
                command("say 多亏你找来了药引子，我媳妇现在病好多了，赶明儿咱们再添个大胖小子。");
                return 1;
        }
        command("say 自从我媳妇得了这病，也不知看了多少名医，吃了多少方子，却没什么用处。");
        command("say 我到内地跑了一次，终于在风云城找到了“赛华佗”，他给了我一张药方。");
        command("say 不过，这药方要龙鲤鱼作药引子，我上哪儿去找呀？");
        command("cry tao baoyi");
        me->set_temp("wanma/找龙鲤鱼",1);
        return 1;
}   
int accept_object(object who, object ob)
{
        if (ob->name()==HIY"龙鲤鱼"NOR) {
                command("touch "+who->get_id());
                command("say 太感谢了，我决不会忘记英雄的大恩大德的！");
                if (!who->query("wanma/义助陶氏")) {
                        who->set("wanma/义助陶氏",1);
                        who->add("combat_exp",1000);
                        who->add("potential",200);
                        who->add("wanma/声誉",1);
                        tell_object(who,HIW"你被奖励了！一千点实战经验，二百点潜能！\n"NOR);
                   tell_object(who,HIW"你在这个边远小镇的声誉上升了！\n"NOR);
                } 
                return 1;               
        }
        return 0;
}                        
                                
