// created 4/12/1998 by bbs
#include <ansi.h>

inherit NPC;
inherit F_MASTER;
int tell_test();
int do_drop(object, object);

void create()
{
  set_name("哪吒", ({ "nezha santaizi", "nezha", "santaizi" }));
  set("title", "三坛海会之神");
  create_family("陷空山无底洞", 1, "弟子");
  set("class", "xian");
  set("long", "一位唇红齿白的美少年。\n");
  set("gender", "男性");
  set("age", 16);
  set("attitude", "heroism");
  set("rank_info/respect", "小太子");
  set("rank_info/rude", "乳臭未干的小儿");
  set("per", 40);
  set("str", 30);
  set("cor", 40);
  set("con", 40);
  set("int", 40);
  set("spi", 40);
  set("cps", 40);
  set("kar", 40);
  set("max_qi", 2000);
  set("max_gin", 1800);
  set("max_jing", 3000);
  set("neili", 2600);
  set("max_neili", 4000);
  set("force_factor", 100);
  set("max_mana", 3000);
  set("mana", 5000);
  set("mana_factor", 120);
  set("combat_exp", 1500000);
  set("daoxing", 2000000);
	set_skill("force", 250);
	set_skill("club", 300);
	set_skill("parry", 180);
	set_skill("dodge", 180);
	set_skill("yijinjing", 301);
	set_skill("hunyuan-yiqi", 200);
	set_skill("weituo-chu", 500);
	set_skill("shaolin-shenfa", 180);

	map_skill("force", "yijinjing");
	map_skill("club",  "weituo-chu");
	map_skill("parry", "weituo-chu");
	map_skill("dodge", "shaolin-shenfa");

	set_skill("blade", 550);
	set_skill("claw", 550);
	set_skill("club", 550);
	set_skill("cuff", 550);
	set_skill("finger", 550);
	set_skill("hand", 550);
	set_skill("staff", 550);
	set_skill("strike", 550);
	set_skill("sword", 550);

	set_skill("banruo-zhang", 590);
	set_skill("cibei-dao", 590);
	set_skill("damo-jian", 590);
	set_skill("fengyun-shou", 590);
	set_skill("fumo-jian", 590);
	set_skill("jingang-quan", 199);
	set_skill("longzhua-gong", 590);
	set_skill("luohan-quan", 590);
	set_skill("nianhua-zhi", 590);
	set_skill("pudu-zhang", 590);
	set_skill("qianye-shou", 590);
	set_skill("sanhua-zhang", 590);
	set_skill("weituo-gun", 590);
	set_skill("wuchang-zhang", 590);
	set_skill("xiuluo-dao", 590);
	set_skill("yingzhua-gong", 590);
	set_skill("yizhi-chan", 500);
	set_skill("zui-gun", 500);
	set_skill("buddhism", 500);
	map_skill("blade", "cibei-dao");
	map_skill("claw", "longzhua-gong");
	map_skill("club", "weituo-chu");
	map_skill("cuff", "luohan-quan");
	map_skill("finger", "nianhua-zhi");
	map_skill("hand", "fengyun-shou");
	map_skill("staff", "weituo-gun");
	map_skill("strike", "sanhua-zhang");
	map_skill("sword", "fumo-jian");

     set("chat_chance_combat", 90);
     set("chat_msg_combat", ({
                (: perform_action, "finger.fuxue" :),
                (: perform_action, "finger.fuxue" :),
                (: perform_action, "club.leidong" :),
                (: perform_action, "club.zuijiu" :),
                            }) );
        set_temp("apply/attack", 150);
        set_temp("apply/defense", 100);
        set_temp("apply/armor", 100);
        set_temp("apply/damage", 100);

  set("inquiry", ([
	"name": "我乃托塔天王三太子李哪吒是也。",
	"here": "这里是托塔天王府。",
"金砖"     : (: tell_test :),
	"rumors": "玉帝敕封家严为降魔大元帅，在下为三坛海会之神，专管降妖除魔。",
	"玉鼠精": "无底洞的玉鼠精？那是我爹的义女。",
	"火尖枪": "送人了！",
	]));
  setup();
        carry_object("/clone/armor/yinjia")->wear();
	carry_object(__DIR__"dragonstick")->wield();

}


