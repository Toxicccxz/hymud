 inherit NPC;
#include <ansi.h>
void create()
{
        set_name("火巨灵", ({ "monster" }) );
        set("long",
                "一个高大的，全身通红的巨人\n");
        set("age", 51);
        
        set("cor", 37); 
        set("combat_exp", 2000000);
                set("max_qi", 130000);
        set("max_jing", 120000);
        set("neili", 120000);
        set("max_neili", 120000);
    set_skill("force", 200);
	set_skill("shenlong-xinfa", 300);
        set_skill("dodge", 180);
	set_skill("yixingbu", 300);
        set_skill("hand", 200);
	set_skill("shenlong-bashi", 300);
        set_skill("strike", 200);
	set_skill("huagu-mianzhang", 300);
        set_skill("parry", 150);
        set_skill("staff", 200);
        set_skill("sword", 200);
        set_skill("zhaosheshu", 300);
        set_skill("yangsheshu", 300);
	set_skill("shedao-qigong", 300);
	set_skill("literate", 190);

	map_skill("force", "shenlong-xinfa");
	map_skill("dodge", "yixingbu");
	map_skill("hand", "shenlong-bashi");
	map_skill("strike", "huagu-mianzhang");
	map_skill("parry", "shedao-bashi");
        map_skill("staff", "shedao-qigong");
	prepare_skill("strike", "huagu-mianzhang");
	prepare_skill("hand", "shenlong-bashi");
	set("chat_chance_combat", 90);  
	set("chat_msg_combat", ({
                (: perform_action, "strike.hua" :),
                (: perform_action, "hand.bada" :),
                (: perform_action, "hand.shenlongtuwu" :),
                (: perform_action, "hand.shenlongtuwu" :),
                (: perform_action, "hand.yingxiong" :),                
                (: perform_action, "hand.yingxiong" :),                
                (: exert_function, "recover" :),
                (: exert_function, "recover" :),
                      }) );
        set("attitude", "aggressive");
        set_temp("apply/attack", 80);
        set_temp("apply/parry", 80);
        set_temp("apply/armor", 70);
        set_temp("apply/damage", 130);
        set_temp("apply/dodge", 70);
        set_temp("apply/armor_vs_fire",100);
        set_temp("apply/armor_vs_ice", -100);
        setup();
} 
void unconcious()
{
if( environment(find_living("dragon lord")))
{
message_vision("\n\n一股赤红的烈焰从沼泽深处射来，围绕着$N般旋不休！\n\n",this_object());
receive_curing("jing",1000);
receive_curing("qi",1000);
receive_curing("qi",1000);
receive_heal("jing",1000);
receive_heal("qi",1000);
receive_heal("qi",1000);
        COMBAT_D->report_status(this_object(),1);
return;
}
else
::unconcious();
return;
}
void die()
{
if(environment(find_living("dragon lord")))
{
message_vision(HIR "\n\n一股赤红的烈焰从沼泽深处射来，围绕着$N般旋不休！\n\n"NOR,this_object());
receive_curing("jing",1000);
receive_curing("qi",1000);
receive_curing("qi",1000);
receive_heal("jing",1000);
receive_heal("qi",1000);
receive_heal("qi",1000);
        COMBAT_D->report_status(this_object(),1);
return;
}
else
::die();
return;
}       
