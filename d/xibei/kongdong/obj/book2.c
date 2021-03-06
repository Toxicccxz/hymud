#include <ansi.h>
inherit ITEM;


void create()
{
	set_name(HIR"血衣"NOR, ({ "xue yi", "cloth" }));
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit","件");
		set("long","这是杀人刀法的图谱。
上面涂的密密麻麻，满是干了的血迹。\n");
		set("value",0);
		set("no_get", 1);
		set("no_give", 1);
		set("no_drop", 1);
		set("material","paper");
		set("cant_sell","伙计疑惑的看着你：“你有病呀，画的乱七八糟的破布也来卖。”\n");
		set("skill",([
			"name"			: "blade",
			"jing_cost"		: 0,
			"xiuwei_required"	: 5300,
			"literate_required"	: 150,
			"bonus_jilei"		: 0,
                        "max_jibie"		: 300,
			"bonus_xiuwei"		: 0,
			"max_xiuwei"       	: 5300,
		]) );
	}
}

varargs int move(mixed dest, int silent)
{
    object ob=this_object();

    if( ob->query("cant_move") )
    {
        destruct(ob);
        return 1;
    }
    return ::move(dest, silent);
}