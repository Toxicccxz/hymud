// shenliwan.c 福缘丹

#include <ansi.h>

inherit ITEM;

mapping valid_typesw = ([
	"sword":	"sword",
	"blade":	"blade",
	"hammer":	"hammer",
	"whip":     "whip",
	"club":     "club",
	"staff":     "staff",
	"throwing":     "throwing",
	"dagger":     "dagger",			
"axe":     "axe",				
]);

mapping valid_typesa = ([
	"hands":	"hands",
	"cloth":	"cloth",
	"armor":	"armor",
	"boots":     "boots",
	"head":     "head",
	"neck":     "neck",
	"surcoat":     "surcoat",
	"shield":     "shield",			
"waist":     "waist",		
"wrists":     "wrists",			
]);


void create()
{
	set_name(HIR "冶炼石" NOR, ({ "duanlian shi", "shi"}) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", "一块七彩的冶炼石，据说用(use)在购买武器，会有意想不到的效果。\n");
                set("value", 10000);
		set("no_put",1);
		set("unit", "块");
	}
}

void init()
{
	add_action("do_eat", "use");
}

int do_eat(string arg)
{
	object me;

        if (! arg)
                return notify_fail("你要买什么种类的？\n");

        me = this_player();


	switch(arg){
case "sword":	me->set_temp("buyweaponlbw","sword"); break;
case "blade":	me->set_temp("buyweaponlbw","blade");  break;
case "hammer":	me->set_temp("buyweaponlbw","hammer");  break;
case "whip":	me->set_temp("buyweaponlbw","whip");  break;
case "club":	me->set_temp("buyweaponlbw","club");  break;
case "staff":	me->set_temp("buyweaponlbw","staff");  break;
case "throwing":	me->set_temp("buyweaponlbw","throwing");  break;
case "dagger":	me->set_temp("buyweaponlbw","dagger");  break;
case "axe":	me->set_temp("buyweaponlbw","axe");  break;
	}

	switch(arg){
case "hands":	me->set_temp("buyweaponlba","hands"); break;
case "cloth":	me->set_temp("buyweaponlba","cloth"); break;
case "armor":	me->set_temp("buyweaponlba","armor"); break;
case "boots":	me->set_temp("buyweaponlba","boots"); break;
case "head":	me->set_temp("buyweaponlba","head"); break;
case "neck":	me->set_temp("buyweaponlba","neck"); break;
case "surcoat":	me->set_temp("buyweaponlba","surcoat"); break;
case "shield":	me->set_temp("buyweaponlba","shield"); break;
case "waist":	me->set_temp("buyweaponlba","waist"); break;
case "wrists":	me->set_temp("buyweaponlba","wrists"); break;
	}


        if (! me->query_temp("buyweaponlba") && ! me->query_temp("buyweaponlbw"))
{
message_vision( "武器可以选择 剑(sword) 刀(blade) 锤(hammer) 鞭(whip) 棍(club) \n"
		"武器还能选择 杖(staff)  暗器(throwing)  匕首(dagger) 斧(axe)\n"
		"防具可以选择 手套(hands) 服装(cloth) 披风(armor) 靴子(boots) 头盔(head)。\n"
		"防具还能选择 项链(neck)肚带(surcoat)盾牌(shield) 腰带(waist) 护腕(wrists)。\n"
    "你好好看一下吧！\n", this_player());
                return notify_fail("请正确选择你要买什么种类的？\n");
}


        message_vision("$N把" + this_object()->name() +
                       "拿出打碎成粉。\n", me);

                tell_object(me, HIR "用这些粉，下次购买武器知道买什么了。。\n" NOR);
//                me->set_temp("dlwok",1);

        destruct(this_object());
	return 1;
}
