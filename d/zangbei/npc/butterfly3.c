#include <ansi.h>
inherit NPC;
int bite();
void create()
{
        set_name("��ԭ�̵�", ({ "butterfly" }) );
        set("race", "Ұ��");
        set("age", 1);
        set("long", "�����ĺ�����ɫ��Ѥ�ã���Ⱥ��ӵ��ڻ����з�����ȥ��\n");
        set("max_qi", 200);
        set("max_jing", 200);
        set("max_qi", 200);
        set("group","butterfly");
        set("str",10);
        
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([
                100:    (: bite() :),
        ]) );  
        
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: bite()  :),     
        }) );
        
        set("chat_chance",2);
        set("chat_msg",({
                "�ʵ�һ����򶫣�һ����������ڻ������������衣\n",
        }) );   
        set("self_go_msg",1);
        set("arrive_msg","��ԭ�̵����˹�����\n");
        set("leave_msg","��ԭ�̵��ɿ��ˡ�\n");
        set("limbs", ({ "ͷ��","����", "���","����", }) );
        set("verbs", ({ "bite" }) );
        set("combat_exp",200000000);
        set_skill("dodge", 600);
        setup();
}  
void init(){
        ::init();
        add_action("do_look", "look");
}  
int do_look(string arg) {
        if(arg == "butterfly"){
                write("�����ĺ�����ɫ��Ѥ�ã���Ⱥ��ӵ��ڻ����з�����ȥ������,����
��Խ�������Ķ�����������Խ��Σ�ա�\n");
                write("���������ų������졣\n");
                write("�����Ĳ��ֲ��ݣ��书����������"+BLU "����һ��"NOR+"�������ƺ����ᡣ\n");
                write("�����������������۷�״̬��\n");
                return 1;
        }
        return 0;
} 
int bite(){
        object ob,me,*enemy;
        int i;
        
        ob=this_object();
        enemy=ob->query_enemy();
        if (!random(3))
        for (i=0;i<sizeof(enemy);i++) {
                message_vision(YEL""+name()+"�����ų�����󻨷���ζѬ����ͷ�����ͣ����޶�־��\n"NOR,enemy[i]);
                tell_object(enemy[i],HIB"����û����˯��\n"NOR);
                enemy[i]->receive_wound("qi",enemy[i]->query("max_qi")/20,ob);
                COMBAT_D->report_status(enemy[i]);
        }       
        this_object()->start_busy(1);
        return 1;
} 