#include <ansi.h>
inherit NPC; 
void create()
{
        set_name("宋长清", ({ "song" }) );
        set("gender", "男性");
        set("age", 30);
        set("long",
                "宋长清乃武当火工道人，身着灰色道袍\n"
        );
        set("combat_exp", random(10000));
        set("class", "taoist");
        set("neili", random(300));
        set("max_neili", random(300)); 
        create_family("武当派", 58, "弟子"); 
       set("qi", 28000);
	set("max_qi", 28000);
	set("jing", 28000);
	set("max_jing", 28000);
	set("neili", 55000);
	set("max_neili", 55000);
	set("jiali", 100);
	set("combat_exp", 9000000);
	set("score", 600000);
	set("shen", 200000);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.zong" :),
                (: perform_action, "unarmed.zhenup" :),
                (: perform_action, "unarmed.tu" :),
                (: perform_action, "unarmed.zhan" :),
                (: perform_action, "unarmed.ji" :),
                (: perform_action, "unarmed.jielidali" :),
                (: perform_action, "hand.leiting" :),
                (: perform_action, "hand.mian" :),
                (: perform_action, "strike.zheng" :),	
                (: perform_action, "sword.lian" :),
                (: perform_action, "sword.chan" :),
                (: perform_action, "sword.chanup" :),
                (: perform_action, "sword.sui" :),
                (: perform_action, "sword.lian" :),
                (: perform_action, "sword.zhenwu" :),
                (: perform_action, "sword.lian" :),                
        }) );
set_skill("claw", 250);
set_skill("strike", 380);
	set_skill("force", 550);
	set_skill("taiji-shengong", 380);
	set_skill("dodge", 150);
	set_skill("tiyunzong", 380);
	set_skill("unarmed", 200);
	set_skill("taiji-quan", 380);
	set_skill("parry", 300);
	set_skill("sword", 300);
	set_skill("taiji-jian", 380);
	set_skill("liangyi-jian", 150);
	set_skill("wudang-array", 380);
	set_skill("array",100);
	set_skill("taoism", 500);
	set_skill("literate", 200);
	set_skill("yitian-tulong", 380);
	set_skill("juehu-shou", 380);
	set_skill("raozhi-roujian", 380);
	set_skill("wudang-mianzhang", 380);
	set_skill("hand", 280);
	set_skill("paiyun-shou", 380);
	set_skill("shenmen-jian", 380);
	set_skill("yitian-zhang", 280);
	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "taiji-quan");
	map_skill("sword", "taiji-jian");
		map_skill("hand", "paiyun-shou");
        setup(); 
        carry_object(__DIR__"obj/sword")->wield();
        carry_object(__DIR__"obj/cloth")->wear(); 
} 
void init()
{
        object ob; 
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
} 
int accept_fight(object me)
{
        if( (string)me->query("family/family_name")=="武当派" ) {
                command("nod");
                command("say 进招吧。");
                return 1;
        }
        command("say 武当派不和别派的人过招。");
        return 0;
} 
void greeting(object me)
{
        if( !me || environment(me) != environment() ) return;
        if( (string)me->query("family/family_name")!="武当派" ) {
                if( (string)me->name()!="彭长净" ) {
                        say( HIY "宋长清说道：这位" + RANK_D->query_respect(me)
                                + "请留步，后院乃武当重地，不可随便进入。\n"NOR);
                        } 
                else {
                        message_vision( HIY "$N上上下下打量了$n几眼说道：彭师哥到哪里去了？\n"NOR, this_object(), me);
                        message_vision( HIY "为什么脸色不好？若是身体不舒服，快到后院休息。\n"NOR, this_object(), me);
                }
        }
        else {
                say( HIY "宋长清说道：这位" + RANK_D->query_respect(me)
                        + "请后院休息，茶饭马上送到。\n"NOR);
        }
} 
