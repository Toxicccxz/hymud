inherit ITEM;

void create()
{
        set_name("镣铐钥匙", ({ "yao shi", "shi" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一把小铁钥匙。\n");
                set("value", 100);
        }
}

