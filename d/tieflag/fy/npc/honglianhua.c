 inherit NPC;
#include <ansi.h>
void smart_fight( object who); 
void create()
{
        set_name(HIR"红莲花"NOR, ({ "hong lianhua" }) );
        set("gender", "男性");
        set("age", 18);
        set("long",
"一个乾枯瘦小，却长着两只大眼睛的少年乞丐，手里拿着根竹竿，正瞧着你笑。\n"
);

      
        set("chat_chance", 1);
        set("chat_msg", ({
                "红莲花喃喃道：“这里面一定有一个大阴谋，是什么呢？”\n",
        }) );
          
        set("attitude", "friendly");
        set("title","少年乞丐");
        set("score", random(50000));
        set("reward_npc", 1);
        set("difficulty",20);
        set("class","beggar");
        
        set("combat_exp", 4000000);        
        set("int", 30);
        set("cps", 20);
        set("spi", 30);
        set("fle",50);
        
        set("neili", 1000);
        set("max_neili",1000);
        set("force_factor", 40);
        set("atman", 100);
        set("max_atman", 100);
        set("mana", 500);
        set("max_mana", 500);
        
        
          
        set_skill("move", 200);
        set_skill("force", 200);
        set_skill("unarmed", 180);
        set_skill("sword", 200);
        set_skill("parry", 180);
        set_skill("dodge", 180);
        set_skill("staff",200);
                        

        set_skill("xianglong-zhang",370);
        set_skill("unarmed",160);
        
        map_skill("unarmed","xianglong-zhang");


        
        set_temp("apply/dodge", 30);
        set_temp("apply/armor", 30);
        setup(); 
        add_money("gold", random(2));
        carry_object(__DIR__"obj/bamboo_staff")->wield();
        carry_object("/clone/misc/cloth")->wear();
} 
 
void smart_fight(object who)
{
        int i;
        object *enemy;
        enemy = this_object()->query_enemy();
        i = sizeof(enemy);
   if (i>1) {
                who->perform_action("staff.tianxiawugou");
                return;
        }
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) 
                if (enemy[i]->query_skill("iron-cloth")>200) {
                        if (this_object()->query_temp("weapon")){
                        command( "say 好厉害的硬功！会一会我的降龙十八掌！");
                        command("unwield staff");
                        who->perform_action("unarmed.xianglongwuhui");
                        }
                } else  {command("wield staff");
                        who->perform_action("staff.banzijue");  
                        }               
        }
        return;
} 
