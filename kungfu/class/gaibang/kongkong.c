// kongkong.c �տն�

inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;

void consider();

void create()
{
	seteuid(getuid());
	set_name("�տն�", ({ "kong kong","beggar","qi gai","kong" }) );
	set("title", "������ؤ");
	set("gender", "����" );
	set("age", 53);
	set("long", "һ��������˪֮ɫ������ؤ��\n");
	set("attitude", "peaceful");
        set("class", "beggar");

	set("str", 75);
	set("con", 75);
	set("int", 75);
	set("dex", 75);
	set("kar", 100);

	set("max_qi", 5500);
	set("max_jing", 5100);
	set("neili", 11500);
	set("max_neili",11500);
	set("jiali", 30);
	set("shen_type", 0);

        set("startroom","/d/city/lichunyuan");

	set("thief", 0);
	set("combat_exp", 6500000);

	set_skill("force", 240); 
	set_skill("unarmed", 240);
	set_skill("sword", 250);
	set_skill("dodge", 250);
	set_skill("parry", 250);
	set_skill("stealing", 360);
	set_skill("begging", 360);
	set_skill("checking", 380); 
	set_skill("huntian-qigong", 340); 
	set_skill("xianglong-zhang", 340);
	set_skill("xiaoyaoyou", 350); 
	set_skill("training",230);
		set_skill("fengmo-zhang",350);
	set_skill("liuhe-zhang",350);
	set_skill("strike",390);
	map_skill("force", "huntian-qigong");
	map_skill("unarmed", "xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");
	set_temp("apply/attack",150);
	set_temp("apply/defense",150);
	set_temp("apply/armor",500);
	set_temp("apply/damage",400);
	create_family("ؤ��", 19, "�˴�����");

	set("chat_chance", 20);
	set("chat_msg", ({
		"�տն�˵��: ���ĵĴ�ү�ġ� ����Ҫ���ļ���ͭ��ɡ�\n",
		"�տն�������ش��˸���Ƿ��\n",
		"�տն�����׽ס�����ϵ�ʭ�ӣ����: ��������û�����⣬ȫ�����Ǹ�ҧ���ˡ� \n",
		(: random_move :)
	}) );

	setup();

        carry_object("/clone/food/jitui");
        carry_object("/clone/food/jiudai");
	add_money("silver", 10);
        
}

void attempt_apprentice(object ob)
{
	command("say �ðɣ�ϣ��" + RANK_D->query_respect(ob) +
	"�ܺú�ѧϰ�����书�������ڽ����д���һ����Ϊ��");
	command("recruit " + ob->query("id"));
}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) ) {
		remove_call_out("stealing");
		call_out("stealing", 1, ob);
	}
}

void stealing(object ob)
{
	mapping fam; 
 
	if( !ob || environment(ob) != environment() 
                || ((fam = ob->query("family")) && fam["family_name"] == "ؤ��")
                || (int)ob->query_skill("taoism", 1) > 200
                || ob->query_int() > 50
          ) return;
        if (!userp(ob)) return;
	switch( random(5) ) {
		case 0:
                       command("hehe " + ob->query("id"));
                       command("beg coin from " + ob->query("id"));
                       command("buy jitui");
		       break;
		case 1:
                       command("grin " + ob->query("id"));
                       command("steal silver from " + ob->query("id"));			
                       command("eat jitui");
		       break;
		case 2:
                       command("hi " + ob->query("id"));
                       command("steal gold from " + ob->query("id"));			
                       command("drink jiudai");
		       break;
		case 3:
                       command("pat " + ob->query("id"));
                       command("beg jiudai from " + ob->query("id"));	
                       command("eat jitui");
		       break;
		case 4:
                       command("walkby " + ob->query("id"));
                       command("beg jitui from " + ob->query("id"));	
                       command("drink jiudai");
		       break;
		case 5:
                       command("hi " + ob->query("id"));
                       command("steal thousand-cash from " + ob->query("id"));			
                       command("drink jiudai");
		       break;
	}
}


int accept_object(object me, object obj)
{
	if (obj->query("money_id") && obj->value() >= 1) {
        	 command("smile");
	         command("say ��л�� ! ��ʵ�һ����е�Ǯ�ģ����ֻ������������� !");
        	 command("give 10 silver to " + me->query("id"));
	}
        else {
        	 command("shake");
	         command("say ���ֶ�������Ҫ ! ��һ��ȥ !");
	         command("give " + obj->query("id") + " to " + me->query("id"));
//               obj->move(this_player());
        }

	return 1;
}

int accept_fight(object me)
{
	command("say " + RANK_D->query_respect(me) + "������С������뿪��\n");
	return 0;
}