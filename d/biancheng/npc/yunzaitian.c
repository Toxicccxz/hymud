#include <ansi.h>
//inherit "/d/taiping/npc/smart_npc"; 
inherit NPC;
int show_me(); 
void create()
{
    set_name("云在天",({"yun zaitian","yun"}));
    set("title",HIW"烟中飞鹤"NOR);
    set("long","一身白衣如雪。这人年纪比花满天小些，但也有四十岁左右，圆圆的脸，面白微须，
不笑时已令人觉得很可亲。\n");
        set("gender","男性");
        set("age",42);
                    set("class","quanli");
    set("reward_npc", 1);
    set("difficulty", 10);

        set("int",22);
        set("cor",30);
        set("cps",20);
        set("str",40);
        
    //set_skill("dagger", 150);
       set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "blade.tiandirenmo" :),
                (: perform_action, "dodge.lianhuanbabu" :),
                (: perform_action, "blade.tiandirenmo" :),
        }) );
        set("combat_exp", 10000000);
        set("score", 200000);

        set_skill("dodge", 100);
        set_skill("parry",100);
        set_skill("dodge", 100);
        set_skill("force", 100);
        set_skill("literate", 80);
	set_skill("unarmed",60);
	set_skill("demon-steps",200);
	set_skill("demon-strike",200);
	set_skill("demon-force",200);
	set_skill("blade",150);
	set_skill("demon-blade",250);
        map_skill("dodge", "demon-steps");
	map_skill("force", "demon-force");
	map_skill("unarmed", "demon-strike");
	map_skill("blade","demon-blade");
	map_skill("parry","demon-blade");
    //map_skill("dagger","yuping-dagger");
        
        set("neili",1500);
        set("max_neili",1500);
        set("force_factor",120);
        set("max_atman",500);
        set("atman",500);
        set("max_mana",500);
        set("mana",500);
        set("combat_exp",4000000);  
        set_temp("apply/armor",300);
        set_temp("apply/attack", 200);
        set_temp("apply/damage", 250);
        
        set("attitude", "friendly");
                
        set("inquiry", ([
                "万马堂" :      (: show_me :),
                "马空群" :       (: show_me :),
                "马车"   :       (: show_me :),
                "花满天" :       (: show_me :),
        ]));
        
        set("death_msg",CYN"\n$N说：功亏一篑，我不甘心啊！ \n"NOR);             

        set("chat_chance",1);
        set("chat_msg",({
                name()+"道：“在下奉了三老板之命，请各位英雄今夜过去小酌。”\n"
        }) );                   
        
//        CHAR_D->setup_char(this_object());
//        auto_npc_setup("wang",200,160,0,"/obj/weapon/","fighter_w","lianxin-blade",2);
        
        setup();
        carry_object("/clone/weapon/gangdao")->wield();    
        carry_object("/clone/misc/cloth")->wear();    
    
}  
int show_me(){
        object me,ob;
        
        me=this_player();
        ob=this_object();       
        
        if (!me->query("wanma/马车")){
                message_vision(CYN"$N盯着$n，那凌厉的目光似乎要把$n看穿。\n",ob,me);
                command("say 万马堂要请的客人，花场主自然会请到。");
                command("say 万马堂不请的客人，再问也是多余。");
                return 1;
        }
        
        message_vision(CYN"$N一拱手说：三老板在迎宾处恭候大驾。\n"NOR,ob);
        me->set("wanma/迎宾",1);
        return 1;
}    
int accept_object(object me, object obj)
{
        object book;
        if( (string) obj->query("name") == HIG"珠花"NOR)
        {
                obj = new(__DIR__"obj/combinepaper");
                message_vision(CYN"$N说道：这正是我送给边城第一美人的啊，唉，居然都已经有裂痕了，我来补一补吧。哦，这是好东西，也给你一块。\n"+NOR"$N将"NOR + obj->name() + NOR"塞入$n手中。\n", 
                            this_object(),this_player() );

                        book = new(__DIR__"obj/combinepaper");
                        if(book) book->move(this_player());
                        
                        
           return 1;       
        }
        else {return notify_fail("云在天客气地鞠了个躬，「万马堂的人，不敢乱收别人的东西。」\n");}
            
        return 1;
} 
void die()
{
        int i;
        object killer,owner; 
        if(objectp(killer = query_temp("last_damage_from"))) {
             if(owner=killer->query("possessed")) killer = owner;
             killer->set_temp("wanma/杀云在天_ma", 1);
        }
        
        ::die(); 

}