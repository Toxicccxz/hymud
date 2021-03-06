#include <ansi.h>


inherit NPC;


void create()
{
        set_name("商宝震", ({"shang baozhen", "shang", "baozhen"}));
        set("gender", "男性");
        set("title", "商家堡少主");
        set("age", 17);
        set("long", @LONG
这便是商家堡的少主商宝震，只见他衣着华丽，
宛然一副富家公子的模样。
LONG);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 25);
        set("int", 20);
        set("con", 20);
        set("dex", 20);

        set("qi", 5000);
        set("max_qi", 5000);
        set("jing", 5000);
        set("max_jing", 5000);
        set("neili", 5000);
        set("max_neili", 5000);
        set("jiali", 120);
        set("combat_exp", 500000);
        set("score", 10000);

         set_skill("force", 300);
        set_skill("dodge", 250);
        set_skill("finger", 250);
        set_skill("parry", 250);
        set_skill("strike", 250);
        set_skill("sword", 280);
        set_skill("blade", 280);
        set_skill("literate", 260);
        set_skill("mahayana", 500);
        set_skill("buddhism", 500);
        set_skill("jinding-zhang", 180);
        set_skill("tiangang-zhi", 180);
        set_skill("huifeng-jian", 180);
        set_skill("yanxing-dao", 180);
        set_skill("zhutian-bu", 180);
        set_skill("linji-zhuang", 180);
        set_skill("bagua-dao", 180);
        set_skill("bagua-zhang", 180);
set_skill("unarmed", 280);
        set_skill("huixin-strike", 180);
        set_skill("piaoxue-hand", 180);
        set_skill("yinlong-whip", 180);
        set_skill("yitian-jian", 180);
        set_skill("whip", 220);
        set_skill("hand", 220);
        map_skill("force","linji-zhuang");
        map_skill("finger","tiangang-zhi");
        map_skill("dodge","zhutian-bu");
        map_skill("strike","jinding-zhang");
        map_skill("sword","huifeng-jian");
        map_skill("blade","bagua-dao");
        map_skill("parry","bagua-dao");
          map_skill("hand","piaoxue-hand");
        map_skill("strike","bagua-zhang");

        prepare_skill("strike", "bagua-zhang");

        set("chat_chance_combat", 99);
        set("chat_msg_combat", ({
                (: perform_action, "strike.ding" :),
                (: perform_action, "strike.jia" :),
                (: perform_action, "blade.feiyan" :),
                (: perform_action, "blade.huan" :),
                (: perform_action, "blade.mang" :),
                (: perform_action, "blade.sha" :),
                (: perform_action, "blade.tian" :),                                
        }) );  

        set("guarder", ([
                "refuse_other": CYN "$N" CYN "对$n" CYN "冷喝道："
                                "你给我站住！我们商家堡岂是由得外"
                                "人随便走动地方？" NOR,
                "refuse_carry": CYN "$N" CYN "对$n" CYN "喝道：你"
                                "背上背的是什么人？给我放下来！" NOR,
        ]));

        create_family("商家堡", 4, "少主");


        setup();

        carry_object("/clone/weapon/gangdao")->wield();
        carry_object("/clone/misc/cloth")->wear();

}

void attempt_apprentice(object ob)
{
        command("shake");
        command("say 你去找我爹爹或是娘亲好了，我自己的武功都没练好呢。");
}
