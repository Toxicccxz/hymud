 inherit COMBINED_ITEM;
void create()
{
        set_name("梅树幼苗", ({ "tree", "plum tree" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","又软又轻的树苗，也许你可以用来造（ｍａｋｅ）些东西．\n");
                set("unit", "捆");
                set("base_unit", "根");
                set("base_weight", 10000);
                set("base_value", 1);
        }
        set_amount(1);
    
}
void init()
{
    if(this_player()==environment()) {
        add_action("do_make","make");
    }
} 
int do_make()
{
        object boat; 
        if(this_player()->query("str") < 16)
        return notify_fail("你年小体弱，无法造出小木舟。\n");
        if(query_amount() < 15)
        return notify_fail("才"+chinese_number(query_amount())+
        "根梅树幼苗，什么也造不出呀．．．\n");
        if((int)this_player()->query_encumbrance() + 150000 > (int)this_player()->query_max_encumbrance())
        return notify_fail("你的负重太大，无法造出小木舟。\n");
        seteuid(getuid());
        boat = new(__DIR__"boat");
        if(boat->move(this_player())){
        message_vision("$N用灵巧的双手造出了一只小木舟。\n", this_player());
        }
        if(!this_player()->query("m_success/木舟"))
        {
                this_player()->set("m_success/木舟",1);
                this_player()->add("score",150); 
        }
        destruct(this_object());
        return 1;
                        
}       
