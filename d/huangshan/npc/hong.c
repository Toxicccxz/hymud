 //TIE@FY3`
inherit NPC;
void create()
{
        set_name("李红樱", ({ "hongying" }) );
        set("gender", "男性" );
        set("age", 53);
        set("long", "一个红袍老人，须发都已经白了，腰杆却还是挺的笔直，眼睛发出的光芒远比
剑锋还逼人。\n");
        set("combat_exp", 4000000);
        set("reward_npc", 1);
        set("difficulty", 5);
        set("no_busy",5);
        if (random(3)) set("attitude","friendly");
        set("neili", 1000);
        set("max_neili", 1000);
        set("force_factor", 50);
        set("resistance/gin",random(100));
        
        set("chat_chance", 1);
        set("chat_msg", ({
"李红樱道：红樱绿柳，剑中之精。\n",
                (: random_move :),
        }) );
        set_skill("throwing",200);
        set_skill("feidao",60);
        map_skill("throwing","feidao");
        setup();
        carry_object(__DIR__"obj/redcloth")->wear();
        carry_object(__DIR__"obj/7inch")->wield();
}
int heal_up()
{
        if(!query_temp("right_hand")) carry_object(__DIR__"obj/7inch")->wield();
        return ::heal_up() + 1; 
}     
