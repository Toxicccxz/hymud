inherit NPC;

void create()
{
        set_name("白衣看守", ({"bai yi","bai"}));
        set("long", "一位面目黝黑的大汉。警惕的扫视这四周。\n");
        set("gender","男性");
        set("title","无名堡");

        set("age",25);
        set("con",30);
        set("str",20);
        set("max_qi",500);
        set("max_jing",500);
        set("max_sen",500);

        set_skill("dodge",50);
        set_skill("demon-blade",50);
        set_skill("parry",50);
        set_skill("unarmed",50);
        set_skill("blade",50);
 
        set("combat_exp",10000+random(3000));
 
        setup();
        carry_object("/clone/weapon/gangdao")->wield();
        carry_object("/clone/misc/cloth")->wear();
}

