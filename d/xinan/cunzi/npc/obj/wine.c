#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;
void create()
{
    set_name(RED"酒坛子"NOR, ({"jiu tanzi", "tanzi", "jiu"}));
    set_weight(3000);
    if (clonep())
        set_default_object(__FILE__);
    else {
        set("long", "一个专门用来装蛇酒的酒坛子。\n");
        set("unit", "个");
        set("value", 1000);
        set("over_value",3);
        set("max_liquid", 50);
    }
    // because a container can contain different liquid
    // we set it to contain wine at the beginning
    set("liquid", ([
        "type": "alcohol",
        "name": "蛇酒",
        "remaining": 30,
        "drink_apply" : 10,
        "drunk_apply": 10,
    ]));
}

