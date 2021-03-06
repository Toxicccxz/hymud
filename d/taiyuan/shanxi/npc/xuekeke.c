#include <ansi.h>
inherit NPC;
int give_mail();
void create()
{
        set_name("薛可可", ({ "xue keke","xue" }) );
        set("nickname",HIY"月神"NOR);
        set("gender", "女性");
        set("age",19);
        set("class","quest_npc");
        set("npc_difficulty",20);
        set("organization/性质","正");
        set("combat_exp", 58000000);
        set("long","月色水波间，仿佛有  层淡淡的烟雾升起，烟雾间仿佛有一条淡
淡的人影。云开，月现，月光谈淡的照下来，恰巧照在她的脸上。
苍白的股，苍白如月。\n"
        );
        set("max_force",5000);
        set("force",5000);
        set("force_factor",150);
        set("max_kee",200000);
        set("max_gin",32000);
        set("max_sen",32000);
        set("con",40);
        set("int",27);
        set("resistance/kee",99);
        set("resistance/gin",99);
        set("resistance/sen",99);
  set("jing", 20000);
        set("eff_jing", 20000);
        set("max_jing", 20000);        
        set("qi", 22000);
        set("eff_qi", 22000);
        set("max_qi", 22000);
        set("max_jingli", 22000);
        set("neili", 40000);
        set("max_neili", 40000);
        set("max_jingqi",1000);
        set("combat_exp", 9000000);
        set_skill("dodge",300);
        set_skill("cuff",320);
        set_skill("unarmed",300);
        set_skill("parry",300);
        set_skill("blade",380);
         set_skill("feitian-yujianliu",380);
         set_skill("wuxing-dun",380);
        set_skill("shayi",380);
         set_skill("aikido",380);
         set_skill("shayi-xinfa",380);
        set_skill("shiren-jianfa",380);
        set_skill("shiren-quanfa",380);
        set_skill("force",300);
set_skill("huoxinliu-jianfa",380);

        set_skill("literate",250);
        map_skill("blade", "feitian-yujianliu");
        map_skill("force", "shayi-xinfa");
              map_skill("unarmed", "aikido");
        map_skill("dodge", "wuxing-dun");
        map_skill("parry", "shiren-jianfa");
        create_family("飞天御剑流", 5, "传人");
         set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.break" :),
                (: perform_action, "unarmed.qin" :),
                (: perform_action, "unarmed.niu" :),
                (: perform_action, "unarmed.yaozhan" :),
                (: perform_action, "blade.chaodao" :),
                (: perform_action, "blade.tianxiang" :),
                (: perform_action, "blade.longlianda" :),
                (: perform_action, "blade.suodi" :),
                (: perform_action, "blade.jiu" :),
                (: perform_action, "unarmed.sanchong" :),
        }));
        set("chat_chance", 1);
        set("chat_msg", ({
 "薛可可面对着黑暗的苍穹淡淡地道：“太阳是生，月是死，我相信此时
此刻，在那一座小楼的灯光下，他也一定在等待着月与死”\n",     }) );  
/*        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                        (:perform_action,"blade.yueshen-feidao":),
        }) ); */
                set("inquiry",([
                        "李坏":(:give_mail:),
                        ])      );
        setup();
        carry_object(__DIR__"obj/yueshencloth")->wear();
        carry_object(__DIR__"obj/yueshenblade")->wield();
} 
int give_mail()
{               object letter; 
                command("sigh");
                command("say 天下本来就有许多事情，有时候即使知道不对，也得做下去。");
                if(!this_object()->query("mail_given"))
                {
                        letter=new(__DIR__"obj/zhanshu");
                        message_vision("$N对$n说道：“请帮我把这封信交给李坏。”",this_object(),this_player());
                        letter->move(this_player());
                        this_object()->set("mail_given");
                }
                return 1;
} 
object offensive_target(object me)
{
        int sz;
        object *enemy; 
        enemy = me->query_enemy();
        if( !enemy || !arrayp(enemy) ) return 0; 
        sz = sizeof(enemy);
        if( sz > 4 ) sz = 4; 
        if( sz > 0 ) return enemy[random(sz)];
        else return 0;
}
 
