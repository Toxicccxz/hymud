#include <ansi.h>
inherit NPC;

void create()
{
        set_name("�ϴ�",({"laoda"}));
        set("title","��ɱ��");
        set_temp("condition_type",RED"< ����һϢ >"NOR);
        set("long","
��������һϮ���£�����һ����д�����һ�ڴ��ʳ��������������ʻ��ڣ�
��ȴ��֪ȥ����Ҳ������һϢ��\n");
        set("gender","����");
        set("age",52);
        
        set("combat_exp",3200000);  
        set("no_heal",1);
        
        set("eff_kee",2000);
        set("eff_sen",2000);
        set("eff_gin",2000);
        set("qi",2000);
        set("jing",2000);
        set("jing",2000);
                
        set("inquiry", ([
                "*":    "�򡣡������򡣡���\n",
        ]));
                
  
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([
                10:     "\n�ϴ�˵���Ҹ���ƴ�ˣ�\n",
        ]) );           

        set("chat_chance",1);
        set("chat_msg",({
                "�ϴ󾪿ֵ�˵�����ǲ����ˣ��ǹ����ǹ�������\n",
           }) );                   

        delete_skill("xisui");
        setup();
        carry_object("/clone/misc/cloth")->wear();   
        add_money("gold",random(2)); 
    
} 
void init()
{       
        object ob; 
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1+random(3), ob);
        }
} 
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) {
                case 0:
                        message_vision("�ϴ󾪿ֵ�˵�����ǲ����ˣ��ǹ����ǹ�������\n",this_object());
                        break;
                case 1:
                        message_vision("�ϴ�����ﹾ�����������³�һ��Ѫ����\n",this_object());
                        break;
                case 2:
                        message_vision("�ϴ������������ڵ���������ʲô������\n",this_object());
                        break;
        }
}     