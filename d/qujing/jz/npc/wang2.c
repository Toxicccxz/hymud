//Cracked by Roath
//ling.c happ@yszz
inherit NPC;inherit F_DEALER;
void create()
{
    
        set_name("��С��", ({"wang", "wang xiaoer", "xiaoer"}));
        set("title", "���ӵ��ϰ�");
        set("gender", "����");
        set("age", 42);
        set("long", "һ����ϲ��Ц�����ˡ�\n");
   set("str", 30);
   set("con", 30);
   set("spi", 30);
        set("combat_exp", 20000);
	set("combat_exp",20000);	
        set_skill("force", 50);
        set_skill("unarmed", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);
   set("neili", 200);
   set("max_neili", 200);
   set("force_factor", 5);
        set("vendor_goods", ({
                "/d/qujing/jz/obj/gbl",
                "/d/qujing/jz/obj/gouroutang",
                          }));
        setup();
   add_money("silver", 20);
}

void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
     call_out("greeting",1,ob);
        }
        add_action("do_buy", "buy");add_action("do_list", "list");

}
void greeting(object ob)
{
    if( !ob || !visible(ob) || environment(ob) != environment() ) return;
        switch( random(1) ) {
                case 0:
                        say( name()+"����������������򹷲���Ŷ���Ͽ���Ŷ��\n");
                        break;
        }
}