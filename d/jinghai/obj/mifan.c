inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("糯米饭", ({ "mi fan","mi" }) );
        set_weight(350);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一个碗喷香的糯米饭。\n");
                set("unit", "个");
                set("food_remaining", 4);
                set("food_supply", 30);
        }
        setup();
}

