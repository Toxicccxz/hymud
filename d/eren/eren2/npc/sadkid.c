 inherit NPC;
#include <ansi.h> 
int give_mission(); 
void create()
{
        set_name("小孩", ({ "sad kid","kid" }) );
        set("gender", "男性");
        set("age", 12);
        set("long",
                "一个十二三岁的小孩，闷闷不乐地坐在田埂上。\n"
        );
        set("chat_chance", 1);
        set("chat_msg", ({
                "小孩说：“小烟怎么不见了？“\n",       
        }) );
        set("inquiry", ([
                "小烟" : (: give_mission :),
                "xiaoyan" : (: give_mission :),
        ]));  
        set("combat_exp",1000);
        setup();
        carry_object("/clone/misc/cloth")->wear();
} 
int give_mission()      {
        object ob;
        ob=this_player();
        if (ob->query("m_success/灭马贼")||ob->query("marks/bandit_result")) {
                if (ob->query("marks/bandit_result")==1) {
                        command("say 小烟死了，再也不会回来了。");
                        return 1;
                        } else {
                                command("say 小烟走了，再也不会回来了。");      
                                return 1;
                        }
                }
        if (!ob->query_temp("eren/bandit_1")) {
                command("say 小烟是我的好朋友，刚才我们还在竹林边堆泥人玩，一晃就不见了。");
                ob->set_temp("eren/bandit_1",1);
        } else command ("say 你看见小烟了吗？你能帮我找到他吗？我很担心。");
        return 1;
   
}       
                        
                        
void init() {
        
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}  
void greeting(object ob) {
        
        object flower;
        
        if( !ob || environment(ob) != environment() ) return;
        if (ob->query("m_success/灭马贼")) return;
        
        if (ob->query("marks/bandit_result") && !ob->query_temp("eren/kid_result")) {
                command("say 小烟走了，再也不会回来了。");      
                message_vision(CYN"$N说：“这朵花是我们一起在草地上挖到的，看了就伤心，你拿去吧。\n"NOR,this_object());
                ob->set_temp("eren/kid_result",1);
                flower=new(__DIR__"obj/flower");
                message_vision(CYN"$N给你一朵花。\n"NOR,this_object());
                flower->move(ob);       
        }
        return;
}
