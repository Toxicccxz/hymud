#include <ansi.h>
#include <command.h> 
inherit NPC; 
void create()
{ 
        set_name("李大娘",({"li daniang","daniang","li"}));
//      set("title",WHT"四大名捕"NOR);
        set("long", "她的笑容如春花开放，语声如春莺婉转。身材比左右的女人更丰满，相貌也更美。
血奴已是罕见的美人，仍未能与她相比。她就随随便便地坐在那里，已风情万种。\n");
        set("age",27);
        set("combat_exp", 8000000);
        set("attitude", "friendly");    
        set("max_atman", 1000);
        set("atman", 1000);
        set("max_mana", 600);
        set("mana", 600);
        set("max_force",1500);
        set("force",1500);
        set("force_factor",100); 
        set("str",40);
        set("cor", 40);
        set("cps", 40);
        set("agi",40);
        set("fle",100);
        
        set("resistance/gin",30);
        set("resistance/kee",30);
        set("resistance/sen",30);
        
//      setting up special NPC function: healer, defense, zombie-killer
//      defense_type: 1. xiaohun-sword; 2.xiaohun-whip;3 yue-strike;4 lingxi-zhi;
        
//      set("defense_type",random(2)+1);        
//      set("zombie-killer",1);
//      set("officer-killer",1);
//      set("dungeon_npc","check");
        

        setup();
        carry_object("/clone/misc/cloth")->wear();
}  
/*
void init() {
        
        object ob;
        ::init();
        add_action("do_answer","answer");
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}  
void greeting(object ob) {
        
        if( !ob || environment(ob) != environment() || ob->is_fighting()) return;
        call_out("ask_question_1",1,ob); 
}
*/ 
/*
void die() {
        object me, ob, owner;
        ob=this_object();       
        message_vision(HIR"$N忽然发出一阵凄厉的笑声：“十万神魔十万血，魔王还在，我是不会死的。”\n"NOR,ob);
        message_vision(HIR"$N忽然急退，穿入了东面的屏风之后。屏风之后是面宽阔的照壁。$N转入
了屏风便不再出现。\n"NOR,ob);
        destruct(ob);
} 
*/
