 // An example book
inherit ITEM; 
void create()
{
        set_name("��粽������" , ({ "fall-steps" }) );
        set_weight(600);
        set("unit", "��");
        set("lore",1);
        set("long", "����һ��������粽�����书���š�\n");
        set("value", 0);
        set("skill", ([
                "name":                 "fall-steps",      
                "exp_required": 200000,       
                "jing_cost":             1,
                "difficulty":   1,  
                "max_skill":    50     
        ]) );
}
 
void init(){ 
        if(this_player() != environment()) {
                add_action("do_get", "get");
        }
}  
int flower_gone(){
        message_vision("һ��紵������ҳ��ȻƬƬɢ��Ʈ�Ŷ�ȥ��\n", this_object());
        destruct(this_object());
        return 1;
} 
int do_get(string arg) {
        if (arg == query("id")) 
                call_out("flower_gone",600);
        return 0;
}        