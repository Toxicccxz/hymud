inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void smart_fight(); 
void create()
{
    set_name( "玉兰溪" , ({ "master yu",  "master" }) );
    set("gender", "女性");
    set("title", "松谷庵 主持");
    set("nickname", HIC"空谷幽居"NOR);
    set("age", 46);
    set("long", "一个小尼庵的主持．\n");
        set("reward_npc", 1);
        set("difficulty", 2); 
    set("combat_exp", 1000000);
    set("score", 200000); 
    set("class", "mei"); 
    set("str", 20);
    set("int", 30);
    set("cor", 20);
    set("cps", 30);
    set("spi", 30); 
    set("neili", 2000);
    set("max_neili", 1000);
    set("force_factor", 30); 
    set("atman", 1400);
    set("max_atman", 1400); 
    set("mana", 4000);
    set("max_mana", 2000);
    set("mana_factor", 5); 
   set("apprentice_available", 50);
    create_family("松谷庵", 1, "主持");
    set("rank_nogen",1);
    set("ranks",({"杂工","伙头","尼姑","师姑","法师","长老","监院","主持"}));
    set_skill("literate", 180);
    set_skill("force", 200);
    set_skill("spells", 180);
    set_skill("unarmed", 150);
    set_skill("sword", 200);
    set_skill("lonely-sword", 220);
    set_skill("xianglong-zhang", 220);
    set_skill("iron-cloth", 180);
	set_skill("parry", 160);
    set_skill("dodge", 200);
    set_skill("xiantian-qigong", 180);
    set_skill("liuquan-steps", 200); 
    map_skill("unarmed", "xianglong-zhang");
    map_skill("sword", "lonely-sword");
    map_skill("force", "xiantian-qigong");
    map_skill("dodge", "liuquan-steps");  
    set_temp("apply/dodge", 200);
    set_temp("apply/armor", 20); 
    setup(); 
        carry_object("/clone/misc/cloth")->wear();
} 

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "mei");
        add("apprentice_availavble", -1);
}      
