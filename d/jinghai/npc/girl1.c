inherit NPC;
 
void create()
{
        set_name("青衣女子", ({"girl"}));
        set("long", "一个身着青色布衣得年轻女子。\n");
        set("gender","女性");

        set("age",26);
        set("con",30);
        set("str",25);
        set("per",25);
        set("kar",25);
 
        set("combat_exp",10000+random(1000));

        setup();
        carry_object("/clone/misc/cloth")->wear();
}

