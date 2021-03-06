 // explorer.c
#include <ansi.h>
inherit NPC;
void smart_fight(object who); 
void create()
{
        object weapon,armor;
        
        set_name("登山的勇者", ({"mountain climber"}) );
        set("gender", "男性" );
        set("age", 36);
        set("agi",30);
        set("cps",40);
        set("cor",40);
        
        set("class","beggar");
         set("long",
                "“自古华山一条路”，能在这十八盘上攀登的，自然是具有
强壮身躯的，大多还身怀武功。\n"
                );
        set("combat_exp", 2200000);
        
        set("chat_chance", 1);
        set("chat_msg", ({
                "登山者笑道：“这华山之险，也不过尔尔而已！”\n",
                "登山者指着峭壁上的鹰巢说：“戴上护臂，就可以试试上去把小鹰捉下来！”\n",
        }) );
        
            
        set("neili", 1000);
        set("max_neili",1000);
        set("force_factor", 20);
        set("atman", 100);
        set("max_atman", 100);
        set("mana", 500);
        set("max_mana", 500);
                  
	set("max_qi", 18000);
	set("max_jing", 18000);
	set("neili", 24000);
	set("max_neili", 24000);
	set("max_neili", 24000);
	set("jiali", 100);
	set("combat_exp", 8500000);
	set("score", 400000);

	set_skill("unarmed", 250);
	set_skill("force", 250);
	set_skill("huagong-dafa", 380);
	set_skill("throwing", 250);
	set_skill("feixing-shu", 380);
	set_skill("dodge", 250);
	set_skill("zhaixinggong", 380);
	set_skill("strike", 250);
	set_skill("chousui-zhang", 380);
	set_skill("claw", 350);
	set_skill("sanyin-wugongzhao", 380);
	set_skill("parry", 200);
	set_skill("staff", 300);
	set_skill("poison", 380);
	set_skill("tianshan-zhang", 380);
	set_skill("chanhun-suo", 380);
	set_skill("whip", 380);
	set_skill("literate", 150);
set_skill("blade", 250);
set_skill("xuantian-strike", 380);
set_skill("bingpo-blade", 380);

	map_skill("whip", "chanhun-suo");
	map_skill("force", "huagong-dafa");
	map_skill("dodge", "zhaixinggong");
	map_skill("strike", "chousui-zhang");
	map_skill("claw", "sanyin-wugongzhao");
	map_skill("parry", "chousui-zhang");
	map_skill("unarmed", "chousui-zhang");
	map_skill("staff", "tianshan-zhang");
	prepare_skill("strike", "chousui-zhang");
	prepare_skill("claw", "sanyin-wugongzhao"); 
        
            setup();
            carry_object(__DIR__"obj/shoe")->wear();
            armor=new("/clone/misc/cloth");
            armor->set_name(WHT"登山服"NOR,({"cloth"}) );
            armor->move(this_object());
            armor->wear(); 
            weapon=new("/clone/weapon/gangzhang");
            weapon->set_name(WHT"登山杖"NOR,({"staff"}) );
            
            weapon->move(this_object());
            weapon->wield(); 
            if (!random(5)) carry_object(__DIR__"obj/flower3");
            carry_object(__DIR__"obj/leathersleeves.c")->wear();
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
        if (!random(3)) who->perform_action("staff.banzijue");  
        return;
}     
