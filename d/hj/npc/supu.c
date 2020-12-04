#include <ansi.h>
inherit NPC;
int ask_me();
string* goods = ({
       "/d/hj/obj/shoujuan",
       "/d/hj/obj/yangpi",
       __DIR__"obj/wandao",
       "/d/hj/obj/shoujuan",
       "/d/hj/obj/shoujuan",
       __DIR__"obj/bishou",
       "/d/hj/obj/jiunang",
       "/d/hj/obj/shoujuan",       
});

void create()
{
        set_name("����", ({ "supu"}));
        set("gender", "����");
        set("age", 21);
        set("long", "һ������Ĺ�����������, �����˵�һ��ʿ��³�˵Ķ��ӡ�\n");
        set("attitude", "heroism");
        set("combat_exp", 70000);
        set("shen", 3000);
        set("str", 32);
        set("int", 20);
        set("con", 24);
        set("dex", 20);
        set("max_qi", 60000);
        set("max_jing", 60000);
        set("neili", 50000);
        set("max_neili", 50000);
        set_skill("unarmed", 330);
        set_skill("blade", 340);
        set_skill("parry", 340);
        set_skill("dodge", 340);
        set("inquiry", ([
            "����" : "�������ҵ������ˣ���ÿ��ɱ��Ұ�Ƕ���������Ƥ��\n",
            "������" : "���ĸ質����������ˣ�����˵���������񳪵û��á�
���⼸��������һֱû���������裬һֱû�ڼ�������\n",
            "ˤ��" : (: ask_me :),
            "����" : (: ask_me :),
            "��үү" : "���Ǽ����˰����������������ҵ����ƣ���ҽţ����ƥ�ļ�����\n",
            "��³��" : "�����Ұ������ǹ�������ĵ�һ��ʿ��������\n",
        ]) );
        setup();
        set("chat_chance", 5);
        set("chat_msg", ({
"�����Ժ����µ�: ��ҲҪѧ�Ұ�����Ϊ�����˵�һ��ʿ��\n",
"������������: ���Ķ�ȥŪһ���ϵȵ���Ƥ���͸�������? \n",
        }) );
        
        set_skill("unarmed", 220);
        set_skill("dodge", 220);
        set_skill("parry", 230);
        set_skill("force", 250);
	set_skill("taixuan-gong", 250);
        set_skill("shenzhao-jing", 280);
        map_skill("dodge","taixuan-gong");
        map_skill("force","taixuan-gong");
        map_skill("parry", "taixuan-gong");
        map_skill("unarmed","taixuan-gong");
      set("jiali",100);
	set("szj/passed", 1);
	set("szj/over200", 1);
	set("book_count", 1);
	set("chat_chance_combat", 80);
       set("chat_msg_combat", ({
                (: perform_action, "parry.po" :),
                (: perform_action, "parry.jing" :),
                (: perform_action, "parry.xuan" :),
                (: perform_action, "parry.po" :),
                (: perform_action, "parry.taixuan" :),
                
        }) );
        
        carry_object(__DIR__"obj/wandao");
        carry_object(__DIR__"obj/yangao")->wear();
        carry_object("/d/hj/obj/jiunang");
}

int ask_me()
{
        if ((int)this_player()->query_temp("supu_fight")) {
            command("say ���ǲ��Ǳ��Թ�����");
            return 1;
            } 
        if (!this_player()->query_temp("supu_accept")) {
            command("say ��ƾʲô���ұ����أ�");
            return 1;
            } 
        else {
        message_vision("$N����$nһ�ۣ��ò�̫��׼�ĺ���˵����
����δ���Ĳ�ԭ��һ��ʿ����λ����"+RANK_D->query_respect(this_player())+"��ͺ����д�(fight)���°ɣ�\n", this_object(), this_player());
        this_player()->set_temp("supu1", 1);
        return 1;
        }
}

int accept_fight()
{
        object me, ob;
        me = this_object();
        ob = this_player();
        if(me->query("eff_qi") < me->query("max_qi") || 
           me->query("qi") < me->query("eff_qi") ||
           me->query("neili") < me->query("max_neili")){
           message_vision(CYN"$N��$n˵���һ�û����Ϣ�ã����һ����ɡ�\n"NOR, ob, me);
           return 0;
           }
        if( ob->query_temp("supu1") ) {
        message_vision(CYN"$N��$n˵���ðɣ����Ҿ�ͬ���д꼸�аɣ��㵽Ϊֹ��\n"NOR, ob, me);
        remove_call_out("checking");
        call_out("checking", 1, me, ob);
        ob->delete_temp("supu1");
        ob->delete_temp("supu_accept");
        return 1;
        }
        else return 0;
}

int checking(object me, object ob)
{
        object good;
        int my_max_qi, his_max_qi;
	int i;
	object fang;

        my_max_qi  = (int)me->query("max_qi");
        his_max_qi = (int)ob->query("max_qi");
        if (me->is_fighting()){
                call_out("checking",1, me, ob);
                return 1;
                }
        if ( !present(ob, environment()) ) return 1; 
        if (( (int)me->query("qi")*100 / my_max_qi) <= 50 ) {
            message_vision(CYN"$N��$n��ס����̾�����Ǻ��˹�Ȼ��һ�㣬�ҷ����ˣ�����һЩ���\n"NOR, me, ob);
            good = new(goods[random(sizeof(goods))]); 
            good->move(ob);
            ob->set_temp("supu_fight", 1);
            message_vision("$N����$nһ�����\n", me, ob);
        if(!ob->query("jinyong/book6") && ob->query("combat_exp",1) >= 800000 )
{
	i = 200+random(800);
	ob->set("jinyong/book6",1);
	ob->add("combat_exp",i+9880);
	ob->add("potential",i*12);
	ob->add("mpgx",10);
	ob->add("expmax",2);
 message_vision(CYN"$N��$n˵������һ���´ﺣ����һ���������������鷳 �ܰ���һ����\n"NOR, me, ob);
	tell_object (ob,"��Ӯ����"+chinese_number(i+9880)+"�㾭��"+
	           chinese_number(i*12)+"��Ǳ��"+"ʮ�����ɹ��� ����ɳ����ޣ���\n");
        ob->save();
 }
            return 1;
            }
        if (( (int)ob->query("qi")*100 / his_max_qi) < 50 ){
                message_vision(CYN"$N����$nһƲ�죬˵�������Ǻ��˵���ѧ������ˡ�\n"NOR, me,ob);
                message_vision("$N��$n���˸��񣬴�ͷɥ�����뿪�����\n",ob, me);
                ob->move("/d/hj/road");
                message_vision("$N��ͷɥ�����߻�����\n", ob);
                return 1;
               }
        return 1;
}

int accept_object(object who, object ob)
{
        if( !who || environment(who) != environment() ) {return 0;}
        if ( !objectp(ob) ) {return 0; }
        if ( !present(ob, who) ) return notify_fail("��û�����������");
        if (userp(ob)) {
               command("? " + who->query("id"));
               command("say ���⺺��ǿ�������˴������ʲô��");
               this_object()->kill_ob(who);    
               return notify_fail("��⣬�����ˣ�\n");
               }


        if (!who->query_temp("killltl")){
                command("? "+(string)who->query("id"));
                command("say ���������ɱ����\n"NOR);                
            return 0;
        }  


        if ((string)ob->query("name") == "����Ƥ"){
                command("ah "+(string)who->query("id"));
                command("say ��ɱ���˴���ǣ�������Ҳ�Ǹ���ʿ��Ҫ��Ҫ����"HIY"����"CYN"һ�£�\n"NOR);                
                who->set_temp("supu_accept", 1);                                
            return 1;
        }        
        
        
        command("smile "+ (string)who->query("id"));
        command("say лл������");
        return 0;
}