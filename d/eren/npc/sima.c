 inherit NPC;
void create()
{
        set_name("司马小烟", ({ "sima"}) );
        set("gender", "男性");
        set("age", 12);
        set("long",
                "一个十二三岁的小孩，眼中露出和其年龄不相符合的成熟。
他被反绑在柱子上，你可以解救他。(Loose)\n"
        );
        set("combat_exp",1000);
        set("loose",0);
        setup();
        carry_object("/clone/misc/cloth")->wear();
}  
                
