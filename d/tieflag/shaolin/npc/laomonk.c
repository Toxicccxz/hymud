#include <ansi.h>
inherit NPC; 
void create()
{
        set_name("老老和尚", ({ "old monk", "monk" }) );
        set("gender", "男性" );
        set("age", 62);
        set("class","shaolin");
        set("nickname",HIR"一指定乾坤"NOR);
        set("vendetta_mark","shaolin");
        set("int", 30);
        set("cor",30);
        set("cps",60);
        set("mana",1000);
        set("max_mana",1000);
        set("resistance/kee",40);
        set("resistance/gin",40);
        set("resistance/sen",40);
        
        set("str",40+random(20));
        
        create_family("东林寺", 18, "老僧");
        set("long",
                "专门钻研各种武功的老僧.\n"
                );
       set("chat_chance", 1);
       set("chat_msg", ({
                name()+"埋首苦思，如中魔魇，一言不发．．\n",
                name()+"突然拍了拍头，喃喃道：非也，非也．．．\n",
                name()+"刚要挥笔于条幅之上，又突然停了下来．\n", 
        }) ); 
        set("attitude", "peaceful");
        set_skill("move", 200);
        set_skill("dodge", 200);
        set_skill("force", 140);
        set_skill("unarmed",200);
        set_skill("shaolin-shenfa",200);
        set_skill("jingang-quan",140);
        set_skill("hunyuan-yiqi",140);
        set_skill("yiyang-zhi",150);
           
        map_skill("dodge", "shaolin-shenfa");
        map_skill("force", "hunyuan-yiqi");
        map_skill("unarmed", "yiyang-zhi");
        
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
          (: perform_action, "unarmed.qiankun" :)
            }) );
        
        set("combat_exp", 5000000);
        setup();
        carry_object(__DIR__"obj/monklao_cloth")->wear();
        carry_object(__DIR__"obj/ironfist")->wield();
}    
