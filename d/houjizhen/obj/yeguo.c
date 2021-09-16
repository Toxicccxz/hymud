// yeguo.c
// by dicky

#include <ansi.h>;
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(HIR"野果"NOR, ({"ye guo", "guo"}));
	set_weight(30);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", 
		"这是一只从树林里采来的野果，红彤彤的，发出阵阵诱人的芳香。\n");
		set("food_remaining", 5);
		set("food_supply", 50);
    	setup();
	}
}
