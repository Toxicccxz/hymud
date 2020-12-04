// �ҹ�����    make joke by That. Nov.6.1997
#include <ansi.h>

inherit NPC;

string *rnd_say = ({
        "�����ҹ����ɣ����������µ�����Ӣ�ۡ�������˾�Ȼ����װ����ʶ���ǣ�",
        "Ϊʲ���������С�ӻ�û�����ֺ��Ǹ�С��Ů����һ���ˣ�",
        "��˭���Ը���һЩǮ��ҹè�ӵ�һǧ�����ӻ����ǵ�ʱ�����ٻ�����ɣ�",
        "���뿴������ɵ�ƨ�����ƽɳ����ʽ��",
        "�ɲ����Ը�����������Դ�㣿�´μ��������Ǹ�������ɲ�����ô���ˣ�",
        "���������ͺ¿�����ﲻ�Ƿ������������������",
        "�Ǹ�������ţ����Ϊʲô���������ǣ�",
        "���ŵ���ü��˵��Ư����",
        "���������������С�뵰����ȥ�ˣ�",
        "���������ʲô��",
        "�����ͷ�Ӻ���ǧ������һ�����⣡",
        "����Ⱥ����α���ӣ�����",
        "������ӯӯ��",
        "��..",
});

varargs void drool(string msg, string who);

void create()
{
        string name, id;

        set_name("�Ҹ���", ({ "taogen xian", "gen" }) );
        set("title", "��ͨ����");
        set("gender", "����");
        set("age", 66);
        set("attitude", "friendly");
        set("chat_chance", 30);
        set("chat_msg", ({
		(: command("eat1") :),
		(: command("goeat") :),
		(: command("mapi1") :),
		(: command("drinkcup") :),
		(: command("ugly") :),
		(: command("mapi") :),
		(: command("slogan2") :),
		(: command("zzz") :),
		(: command("lazy") :),
		(: command("slogan") :),
		(: drool :),
                (: drool :),
                (: drool :),
                (: drool :),
                (: drool :),
                (: drool :),
        }) );

	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 30);
	set("int", 40);
	set("con", 30);
	set("dex", 30);
	
	set("qi", 30000);
	set("max_qi", 30000);
	set("jing", 30000);
	set("max_jing", 30000);
	set("neili", 30000);
	set("max_neili", 30000);
	set("jiali", 60);
	
	set("combat_exp", 4000000);
	set("score", 100000);
	set_skill("blade", 250);
	set_skill("cuff", 250);
	set_skill("feiyan-huixiang", 250);
	set_skill("hand", 250);
	set_skill("finger", 250);
	set_skill("strike",250);
	set_skill("claw", 250);
	set_skill("unarmed",250);
	set_skill("force", 250);
	set_skill("zixia-shengong", 280);
	set_skill("dodge", 250);
	set_skill("parry", 250);
	set_skill("sword", 250);
	set_skill("huashan-sword", 250);
	set_skill("literate", 120);

	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: perform_action, "dodge.huiyanfeiwu" :),
		(: perform_action, "unarmed.liaorao" :),	
		(: perform_action, "unarmed.wuji" :),	
	      }) );
	
	map_skill("force", "zixia-shengong");
	map_skill("unarmed", "huashan-zhangfa");
	map_skill("dodge", "feiyan-huixiang");
	map_skill("parry", "huashan-sword");
	      
        setup();
        if( clonep() ) CHANNEL_D->register_relay_channel("chat");
}

int add_phrase(string who, string msg)
{
        msg = replace_string(msg, "?", "");
        msg = replace_string(msg, "��", "");
        msg = replace_string(msg, "��", "");
        msg = replace_string(msg, "!", "");
        msg = replace_string(msg, "��", "");
        msg = replace_string(msg, "��", "");
        msg = replace_string(msg, "��", "");
        msg = replace_string(msg, "Ү", "");
        msg = replace_string(msg, "��", "");

        if( msg!="" ) {
                add("memory/" + who, ({ msg }));
                return 1;
        } else return 0;
}

string make_reply()
{
}

void relay_channel(object ob, string channel, string msg)
{
        string who, phrase;

//        if( !userp(ob) || (channel != "chat") ) return;
        who = ob->query("name");

        // Don't process our own speech.
        if( ob==this_object() ) return;

        if( add_phrase(who, msg) && random(10) > 4 )
                drool(msg, ob->query("name"));
}

void relay_say(object ob, string msg)
{
        string who, phrase;

        if( !userp(ob) ) return;
        who = ob->query("name");

        // Don't process our own speech
        if( ob==this_object() ) return;

        if( add_phrase(who, msg) && random(10) > 4 )
                drool(msg, ob->query("name"));
}

void relay_emote(object ob, string verb)
{
        if( !userp(ob) ) return;

        switch(verb)
        {

        case "kick":
                if( random(10)<5 ) {
                        command("say Ϊʲ�����ң���ʹҮ��");
                        break;
                }
	case "hug":
	case "kiss":
	case "mo":
	case "18mo":
	case "nocloth":
	if ( (string) ob -> query ("gender") == "����" ||
             (string) ob -> query ("gender") == "����" )
	{
		command ("chat ����ɶ��"+ ob->query("name") + "���Ҿ�ϲ�������������\n") ;
		command("chat ˭��õ���" + RANK_D->query_rude(ob)+"����Ȼ������֮�á�\n");
	}
	else
	{
		command("giggle");
		command("chat �벻��"+ ob->query("name") +"�Զ��Ѷ����������ˡ��ٿ���û���ˣ�");
	}
		message_vision("$Nҡ��ҡͷ����$n����̾���������������Ǻο���?\n",this_object(), this_player());
        default:
                if( random(10)<5 )
                        command(verb + " " + ob->query("id"));
                else
                        drool();
        }
}

varargs void drool(string msg, string who)
{
        mapping mem;
        string *ob;

        mem = query("memory");
        if( !mapp(mem) ) return;

        if( !msg || !who) {
                ob = keys(mem);
                who = ob[random(sizeof(ob))];
                msg = mem[who][random(sizeof(mem[who]))];
        }

        if( (strsrch(msg, "Ϊʲ��") >= 0) ) {
                if( sscanf(msg, "%*sΪʲ��%s", msg)==2 ) msg = "Ϊʲ��" + msg;
                switch(random(8)) {
                case 0: command("say " + who + "��������������"); break;
                case 1: command("say ���" + msg + " ... "); break;
                case 2: command("say �� ... "); drool(); break;
                case 3: command("say ��������� ...."); break;
                case 4: command("say " + who + "��֪���������Ĵ𰸶���������Ҫô��"); break;
                case 5: command("say " + msg + "��"); break;
                case 6: command("say " + who + "���ܲ���˵���һ�㣿"); break;
                case 7: command("say " + who + "���Ҳ������ʵ�����"); break;
                }
        }
        else if( (strsrch(msg, "��") >= 0)
        ||      (strsrch(msg, "��") >= 0)
        ||      (strsrch(msg, "drooler") >= 0)
        ||      (strsrch(msg, "Drooler") >= 0)) {
                if( sscanf(msg, "%*s��%s", msg) == 2 ) msg = "��" + msg;
                msg = replace_string(msg, "��", "��");
                msg = replace_string(msg, "��", "��");
                switch(random(10)) {
                case 0: command("say " + who + "������˵" + msg + "��");break;
                case 1: command("say ��ȷ��" + msg + "��");     break;
                case 2: command("say " + msg + "������ʲ���ϵ��");     break;
                case 3: command("say �� ... " + who + "˵�ú�"); break;
                case 4: command("say " + who + "��Ϊʲ���" + msg + "��������Ȥ��"); break;
                case 5: command("say Ϊʲ������Ϊ" + msg + "��"); break;
                case 6: command("say ���������"); drool(); break;
                case 7: command("say �Ź�"); break;
                case 8: command("say ��һ���ɣ�"); break;
                case 9: command("say ��������� ...."); break;
                }
        }
        else if( (strsrch(msg, "��") >= 0)) {
                if( sscanf(msg, "%*s��%s", msg) == 2 ) msg = "��" + msg;
                msg = replace_string(msg, "��", "��");
                msg = replace_string(msg, "?", "");
                switch(random(8)) {
                case 0: command("say ����˵" + msg + "��"); break;
                case 1: command("say ��ģ�" + msg + "��");     break;
                case 2: command("say ���" + msg + "�����ܰ���ʲ��æ��");break
;
                case 3: command("hmm"); break;
                case 4: command("say ����Ϊ" + msg + "��"); break;
                case 5: command("say ����ͬ��"); break;
                case 6: command("say ��˵�ġ�" + msg + "���Ҳ��ܹ�ͬ"); break;
                case 7: command("say �йء�" + msg + "���Ļ��⵽��Ϊֹ����");;
                }
        } else {
                switch(random(20)) {
                        case 0: command("say Ϊʲ��˵" + msg + "?"); break;
                        case 1: command("say ��" + msg + "����ʲ����˼��"); break;
                        case 2: command("say " + msg + "��"); break;
                        case 3: command("grin"); break;
                        case 4: command("smile"); break;
                        case 5: command("?"); break;
                        case 6: command("say ...."); break;
                        case 7: command("hmm"); break;
                        case 8: command("say " + rnd_say[random(sizeof(rnd_say))]); break;
                        case 9: command("say ������֪��" + msg + "?"); break;
                        case 10: command("say �ո�" + who + "����˵�ˣ�" + msg);
                        case 11: command("say �ҵ�Ȼ֪����" + msg); break;
                        case 12: command("say Ȼ���أ�"); break;
                        case 13: command("say �����"); break;
                        case 14: command("say �Ҳ�������Ϊ��"); break;
                        default:
                                break;
                }
        }
}

void reset()
{
        delete("memory");
}

int accept_object()
{
        return 1;
}
void init()
{
	object ob;
	
	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		 remove_call_out("greeting");
		 call_out("greeting", 1, ob);
	}
	add_action("do_dajia","hit");
	add_action("do_dajia","fight");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	say( "�ҹ��������ȿֺ���к����������������ֵܺȾƣ�\n");
	message_vision("�Ҹ��ɣ�б��$Nһ�ۣ�ͻȻ�������������þ�������\n", ob);
	message_vision("��֦���������ӣ������������ӽ���Ҫһ�ߺȾƣ�һ�߿�����
	��$N�ֳɾſ飡\n", ob);
	message_vision("��Ҷ�����˹�����һ��ץס$N���µ����ҵ�һ���ҵ�һ��\n", ob);
	say("�һ��ɺ��Ŷ̹�������һƨ�����£���ƾͺȡ�\n");
	message_vision("��ʵ�ɳ���$N������Ƥ������һ�������ó���$Nֱð��\n", ob);
}

int do_dajia()
{
	object ob;
	
	ob = this_player();
	message_vision("�Ҹ��ɵ����ã���Ӯ���ң�����ܽ�ȥ�����С�ӣ�\n",this_object());
	ob->fight_ob(this_object());
	this_object()->kill_ob(ob);
	return 1;
}

void unconcious()
{
die();
}
void die()
{
        object ob, me, corpse;
        
        ob = this_object();
        me = query_temp("last_damage_from");
        if (!me) return;

        reincarnate();
        set("eff_qi", query("max_qi"));
        set("qi", query("max_qi"));
        set("eff_jing", query("max_jing"));
        set("jing", query("max_jing"));
        set("jingli", query("eff_jingli"));
        this_object()->clear_condition();
        
	if ((int)me->query("jinyong/book8")==3)
	{
		message_vision("$NЦ�������ֲ�������������Ϲ�ͷǿ���ˣ��úúã����Լ���ȥ�������ɡ�\n",ob);
		me->move("/d/jinyong/book8/huashan/luoyan");
	}
        
        return;
}