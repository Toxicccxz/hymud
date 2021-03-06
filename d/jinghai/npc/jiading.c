// shinv.c from mool

inherit NPC;
 
void create()
{
        set_name("护庄家丁", ({"jia ding",}));
        set("long", "一位彪形大汉,浓眉大眼.警惕的扫视这四周。\n");
        set("gender","男性");
        set("title","靖海山庄");

       set("chat_chance",2);
        set("chat_msg",({
        "家丁叹了口气道:我家主人为人正直!想不到却受到门派里的排斥。\n"
}));
        set("age",25);
        set("con",30);
        set("str",30);
        set("max_qi",1200);
        set("max_jing",1200);
        set("max_sen",1200);

        set_skill("dodge",200);
        set_skill("demon-blade",200);
        set_skill("parry",200);
        set_skill("unarmed",200);
        set_skill("blade",200);
create_family("靖海派", 3, "弟子");
        set("combat_exp",100000+random(30000));

        setup();
        carry_object("/clone/weapon/gangdao")->wield();
        carry_object("/clone/misc/cloth")->wear();
}

