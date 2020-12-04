#pragma save_binary
// shiao.c

inherit NPC;

void create()
{
	set_name("�����", ({ "adviser" }));
	set("title","��ʦ");
	set("gender", "����");
	set("age", 44);
	set("long",
        	"�������棬�ǲ��Զ��֣�������ǧ����Ȼ��éɽ�������еĸ�\n"
        	"�֣��������ȣ��ʹ󽫾����Ǿ��䡣\n");

	set("attitude", "peaceful");

	set("str", 20);
	set("int", 30);

	set("combat_exp", 1300000);
        
        set("inquiry", ([
        	"������" : "�ȿ�����ĳ�����˵�ޡ�\n",
        ]) );
        
      
	
	set("neili", 22600);
	set("max_neili", 22600);
	set("force_factor", 5);
        
        set("atman", 600);
        set("max_atman", 600);
        
        set("mana", 2000);
        set("max_mana", 1200);
	set("mana_factor", 5);
	set("max_qi",10000);
	set("max_jing",10000);
        set_skill("literate", 160);
        set_skill("magic", 160);
        set_skill("force", 325);
        set_skill("spells", 180);
        set_skill("unarmed", 230);
        set_skill("sword", 240);
        set_skill("parry", 235);
        set_skill("dodge", 240);
        
        set_skill("taoism", 260);
        set_skill("necromancy", 270);

        
        map_skill("magic", "taoism");
        map_skill("spells", "necromancy");
        map_skill("force", "gouyee");
        
        set_temp("apply/dodge",115);
        set_temp("apply/armor",115);
         
	setup();

	carry_object(__DIR__"obj/fan_sword")->wield();
	carry_object(__DIR__"obj/hat")->wear();
}

int accept_object(object who,object ob)
{
        if ( !ob->value() ) {
        	command("say л��!!");
                command("grin");
              //  call_out( (: destruct :), 1, ob);
                return 1;
	}
                                                                                                                                                                
	if( !who->query_temp("��Ӫ/swear") ) {
		if( ob->value() >= 800 ) {
            	   command("say �ü��ˣ��Ҿ͸�����һ�����ܰɡ�");
            	   command("say ����Ƭ�⻬��ɽ��ǰ����(swear) �Ұ�.....��");
                   command("say ����\����Է������ص���ม�");
                   who->set_temp("��Ӫ/swear", 1);
		   return 1;
		} else {
		   command("say Ǯ̫���˰ɣ�û�ա�");
		   return 1;
		}
	} else 
		command("say ��Ȼ����ô���ģ����Ҿ���ǿ�������ˡ�");
	
	return 1;
}