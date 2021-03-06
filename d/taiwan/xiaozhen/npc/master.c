#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
  set_name("洞冥子", ({ "dongming zi","dongmingzi","dongming","master" }));

  set("gender", "男性");
  set("age", 87);

  set("str", 20);
  set("per", 20);
  set("cor", 30);
  set("cps", 75);
  set("kar", 50);
  set("int", 40);
  set("con", 40);
  set("spi", 40);

  set("long","他的双眼空空洞洞,似乎并没有注意你,只在眼
光一转间,才能看到少许生气,他坐得纹丝不动,
全身隐隐散发出一层红色光茫.\n");
  set("title", RED+"幽冥山庄"+NOR);
        set("shen_type",-1);
  set("nickname",YEL+"长老"+NOR);
  set("combat_exp", 2000000);
set_skill("literate",200);
  set_skill("unarmed", 200);
  set_skill("force", 200);

set_skill("blade",200);
set_skill("sword",200);
  set_skill("dodge", 200);
  set_skill("parry", 200);


   set("combat_exp", 9999999);
    set("score", random(90000));
    
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
			map_skill("strike", "yitian-zhang");
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

  set("inquiry", ([
	"name"    : "我是幽冥一派长老洞冥子,现在老一辈只剩下我一人了。",
	"here"    : "本教密室,你怎么进来的?。",
	"rumors"  : "消息？你不专心学艺，又来打听什么消息？",
      "杀人":"只要你杀过三十个人,老夫就收你作传人,少一个都不行!",
]) );

  create_family(RED+"幽冥山庄"+NOR, 3, "长老");

  setup();
    carry_object("/d/ghost/npc/obj/cloth3")->wear();
    carry_object("/d/ghost/npc/obj/hat")->wear();
    carry_object("/d/ghost/npc/obj/swordd")->wield();
	add_money("gold",3);
}
int accept_fight(object me)
{
  command("say 嘿嘿,老夫在此坐了六十年,哪还有年轻人的火气！");
  return 0;
}

