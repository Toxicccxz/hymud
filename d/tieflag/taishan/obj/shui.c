 inherit ITEM;
void create()
{
        set_name("��ɽ��ˮ", ({ "hill" , "water", "��ɽ��ˮ"}) );
        set_weight(500);
        set_max_encumbrance(80000);
        set("no_get", 1);
        set("no_shown", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ���ɽ��ˮ�ľ�ɫ��\n");
                set("value", 1);
        }
    setup();
} 
int is_container() { return 1; }   