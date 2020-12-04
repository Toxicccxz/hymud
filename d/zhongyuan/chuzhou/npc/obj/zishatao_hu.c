// 紫砂陶壶 /d/city/chuzhou/npc/obj/zishatao_hu.c

#include <ansi.h>

inherit ITEM;

inherit F_LIQUID;

void create()
{
    set_name(MAG"紫砂陶壶"NOR, ({"zishatao hu", "hu", "pot"}));
    set_weight(500);
    if (clonep())
        set_default_object(__FILE__);
    else {
        set("long", @LONG
一个用来装茶的紫砂陶壶，是宜兴的名产。
LONG
        );
        set("unit", "个");
        set("value", 3300);
        set("max_liquid", 10);
    }
}

void init()
{
    add_action("do_drink",  "drink");
    add_action("do_fill",   "fill");
}