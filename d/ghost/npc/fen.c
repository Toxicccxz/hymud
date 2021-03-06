#include <ansi.h>
inherit NPC; 
void create()
{
        object          biao, bag; 
        set_name("粉燕子", ({ "fen yan zi", "fen" }) );
        set("nickname", "万里踏花");
        set("title", "大盗");
        set("gender", "男性");
        set("age", 27);
        set("per", 30);
        set("combat_exp", 50000);
        set("long",
                "一张少女般嫣红的脸，一身剪裁极和身的粉红色衣裳\n粉红色的腰带旁，斜挂着一支粉红色的腰囊。\n"
        );
        set("no_arrest",1);
      set_skill("zhuihun-biao", 380);
		set_skill("liuxing-biao", 380);
	set_skill("pili-biao",380);
	set_skill("force", 350);
	set_skill("biyun-xinfa", 380);
	set_skill("dodge", 350);
	set_skill("qiulinshiye", 380);
	set_skill("strike", 250);
	set_skill("unarmed",280);
	set_skill("biye-wu", 380);
	set_skill("parry", 280);
	set_skill("throwing", 380);
	set_skill("zimu-zhen", 380);
	set_skill("literate", 250);
	
	set_skill("dusha-zhang", 380);
	set_skill("lansha-shou", 380);
	set_skill("hand", 380);
	set_skill("strike", 380);
	map_skill("strike", "dusha-zhang");
	map_skill("hand", "lansha-shou");
	map_skill("force", "biyun-xinfa");
	map_skill("dodge", "qiulinshiye");
	map_skill("strike", "dusha-zhang");
	map_skill("unarmed","biye-wu");
	map_skill("parry", "biye-wu");
	map_skill("throwing", "zimu-zhen");
	map_skill("strike", "dusha-zhang");
	map_skill("hand", "lansha-shou");
	prepare_skill("strike", "dusha-zhang");
	prepare_skill("hand", "lansha-shou");


	set("chat_chance_combat", 98);
	set("chat_msg_combat", ({
		(: perform_action, "throwing.poqizhen" :),
		(: perform_action, "throwing.dinhun" :),
                (: perform_action, "throwing.qizigangbiao" :),
                (: perform_action, "throwing.tanghua" :),
		(: perform_action, "parry.wandu" :),
		(: perform_action, "parry.meng" :),
		(: perform_action, "strike.tianxie" :),
		(: perform_action, "strike.hantian" :),
		(: perform_action, "hand.canglong" :),
		(: perform_action, "hand.xiangyi" :),
		(: perform_action, "hand.luanpo" :),									
						
	}) );
        setup();
        biao = new(__DIR__"obj/biao");
        bag = new(__DIR__"obj/bag");
        biao->move(bag);
        bag->move(this_object());
        carry_object(__DIR__"obj/biao")->wield();
} 
void init()
{
        object          me; 
        ::init();
        if( interactive(me = this_player()) && !is_fighting() ) {
                call_out("greeting", 1, me);
        }
} 
int greeting(object who)
{
        object          env; 
        env = environment();
        if(present("ye gu hong", env)) {
                say( HIY "\n粉燕子上上下下打量着" + who->name() + "对叶孤鸿说道：这个人是我的，我不许你碰他。\n"NOR);
                say( HIY "叶孤鸿脸上露出种想呕吐的表情说道：男人女人你都要？\n"NOR);
                say( HIY "粉燕子笑了笑道：有时候我连你都想要。\n\n"NOR);
        }
        return 1;
}      
