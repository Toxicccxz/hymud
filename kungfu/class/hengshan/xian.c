// Last Modified by Sir on May. 22 2001
// xian.c
inherit NPC;
inherit F_MASTER;

#include <command.h>
#include <ansi.h>
string ask_for_join();
string ask_me();
string ask_yao();
void create()
{
	set_name("����ʦ̫", ({ "dingxian shitai", "shitai", "dingxian" }) );
	set("long", "�����Ǻ�ɽ�ɵĶ���ʦ̫���������ݸߣ���ü��Ŀ��\n"
		"�����κ�ɽ�������ˡ�\n");
	set("gender", "Ů��");
	set("title", HIB"��ɽ�ɵ�ʮ��������"NOR);
	set("class", "bonze");
	set("age", 45);
	set("attitude", "peaceful");
	set("per", 24);
	set("str", 26);
	set("con", 30);
	set("dex", 30);
	set("int", 28);
	set("inquiry",([
		"���"  : "ƶ�᲻��ȵ��ӡ�",
		"����"  : "ƶ�᲻��ȵ��ӡ�",
		"����"  : "��ɽ���ӣ����ܻ��ס�",
		"�����ܵ���" : (: ask_yao :),
		"�ؼ�"	 : (: ask_me :),
		"�쳤�Ʒ���" : (: ask_me :),
	]));	
	set("no_get",1);
	
	set("chat_chance_combat", 90);
	set("chat_msg_combat", ({
		(: exert_function, "recover" :),
(: exert_function, "shield" :),
(: exert_function, "powerup" :),				
		(: perform_action, "sword.riluo" :),
		(: perform_action, "sword.shenfeng" :),	
		(: perform_action, "sword.wanjian" :),
		(: perform_action, "sword.xunlei" :),	
	(: perform_action, "dodge.lingxu" :),			
		(: command("unwield changjian") :),
		(: command("wield changjian") :),
		(: perform_action, "hand.break" :),
		(: perform_action, "strike.diezhang" :),
	}));


	set("max_qi", 24000);
	set("max_jing", 22000);
	set("neili", 24000);
	set("max_neili", 24000);
	set("jiali",100);
	set("jingli", 1500);
	set("max_jingli", 1500);
	set("combat_exp", 9000000);
	set("score", 1000);
	set("book_count", 1);
	set("yao_count", 1);
	
	set_skill("unarmed", 200);
	set_skill("sword", 300);
	set_skill("force", 200);
	set_skill("parry", 200);
	set_skill("dodge", 300);
	set_skill("strike", 200);
	set_skill("hand", 200);
	set_skill("buddhism", 350);
	set_skill("medicine", 380);
	set_skill("goplaying", 380);
	set_skill("baiyun-xinfa",380);	
	set_skill("hengshan-jian", 380);
	set_skill("chuanyun-shou",380);
	set_skill("tianchang-zhang",380); 
	set_skill("whip",180); 
	set_skill("rousi-whip",180); 
	set_skill("canxin-jian",388); 
	set_skill("lingxu-bu", 380);
	set_skill("literate", 150);
	
	map_skill("force","baiyun-xinfa");
	map_skill("sword", "canxin-jian");
	map_skill("strike","tianchang-zhang");
	map_skill("hand","chuanyun-shou");
	map_skill("parry", "canxin-jian");
	map_skill("dodge", "lingxu-bu");

	prepare_skill("hand", "chuanyun-shou");
	prepare_skill("strike", "tianchang-zhang");
		  set_temp("apply/armor", 200);
		  set_temp("apply/damage", 200);
	set_temp("apply/attack",200);
	set_temp("apply/defense",200);
	create_family("��ɽ��", 13, "����");
	setup();

	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/shaolin/obj/xuan-cloth")->wear();
}
void init()
{
    add_action("do_qiecuo","qiecuo");
}
void attempt_apprentice(object ob)
{
	string name, new_name;

	if ((string)ob->query("class")!="bonze" )
	{
		command ("say �����ӷ�ƶ�᲻���׼ҵ��ӡ�");
		return;
	}
	
	if ((int)ob->query_skill("baiyun-xinfa",1) < 90 )
	{
		command("say ��ı����ڹ��ķ������,�������Ը�������书��");
		return;
	}
	if ((int)ob->query("shen")<100000) 
	{
		command( "say �����ܶ�Ϊ����֮�٣����ܳ����²���\n");
		return;
	}
	command("say �����ӷ����գ����գ��ðɣ��Ҿ��������ˡ�");
	command("say ϣ������Ŭ�����ƣ��ö��������Թ���Һ�ɽ�ɡ�");
	command("recruit " + ob->query("id"));
	name = ob->query("name");
	new_name = "��" + name[2..3];
	command("say �ӽ��Ժ���ķ�������" + new_name + "��");	
	ob->set("name", new_name);
}


string ask_me()
{
	object ob;
	
	if (this_player()->query("family/family_name")!="��ɽ��")
		return RANK_D->query_respect(this_player()) +
		"�뱾�ɺ��޹ϸ����ɵ��书�伮�ɲ��ܽ����㡣";
	if (query("book_count") < 1)
		return "�������ˣ����ɵ��ؼ����ڴ˴���";
	add("book_count", -1);
	ob = new(__DIR__"tianchang-zhangpu");
	ob->move(this_player());
	command("rumor "+this_player()->query("name")+"�õ��쳤�Ʒ�������\n");
	return "�ðɣ��Ȿ���쳤�Ʒ��ס����û�ȥ�ú����С�";
}
string ask_yao()
{
	object ob;
	
	if (this_player()->query("family/master_id")!="dingxian shitai")
		return RANK_D->query_respect(this_player()) + 
		"���ҵ��ӣ���֪�˻��Ӻ�̸��";
	if (query("yao_count") < 1 || random(3) > 0)
		return "�������ˣ������ܵ�����ɸ����ˡ�";
	add("yao_count", -1);
	ob = new(__DIR__"baiyunwan");
	ob->move(this_player());
	return "�ðɣ����������ܵ�����ȸ���ɡ�";
}