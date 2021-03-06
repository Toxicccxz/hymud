// wear.c

#include <ansi.h>

inherit F_CLEAN_UP;

int do_wear(object me, object ob);

int main(object me, string arg)
{
	object ob, *inv;
	int i, count;

	if( !arg ) return notify_fail("你要穿戴什么？\n");
   if (me->is_busy()) return notify_fail("你正忙着呢!\n");
	if(arg=="all") {
		inv = all_inventory(me);
		for(count=0, i=0; i<sizeof(inv); i++) {
			if( inv[i]->query("equipped") ) continue;
			if((int)me->query_str() < (int)inv[i]->query("wear_str")) continue;
			if((int)me->query_con() < (int)inv[i]->query("wear_con")) continue;
			if((int)me->query("max_neili") < (int)inv[i]->query("wear_maxneili")) continue;
			if(do_wear(me, inv[i]) ) count ++;
		}
		write("Ok.\n");
		return 1;
	}

	if( !objectp(ob = present(arg, me)) )
		return notify_fail("你身上没有这样东西。\n");

	if( ob->query("equipped") )
		return notify_fail("你已经装备着了。\n");

	if (userp(me) && me->query("max_neili") < ob->query("wear_maxneili"))
		return notify_fail("你感觉全身气息翻腾，原来你内力不够，不能装备"+ob->name()+"。\n");
	if (userp(me) && me->query_con() < ob->query("wear_con"))
		return notify_fail("你想装备"+ob->name()+"，怎奈身体不够强壮，只好作罢。\n");
	if (userp(me) && me->query_str() < ob->query("wear_str"))
		return notify_fail("你想装备"+ob->name()+"，怎奈力量不够，只好作罢。\n");

	return do_wear(me, ob);
}

int do_wear(object me, object ob)
{
	string str;

	if( ob->query("id") == "jinsi jia" && me->query("age") >= 20)
		return notify_fail("你长大了，穿不上金丝甲了。\n");

	if( ob->query("female_only")
	&&      (string)me->query("gender") =="男性")
		return notify_fail("这是女人的衣衫，你一个大男人也想穿，羞也不羞？\n");

	if( ob->wear() ) {
		if( !stringp(str = ob->query("wear_msg")) )
			switch( ob->query("armor_type") ) {
				case "cloth":
				case "armor":
				case "boots":
					str = YEL "$N穿上一" + ob->query("unit") + "$n。\n" NOR;
					break;
				case "head":
				case "neck":
				case "wrists":
				case "finger":
				case "hands":
					str = YEL "$N戴上一" + ob->query("unit") + "$n。\n" NOR;
					break;
				case "waist":
					str = YEL "$N束起一" + ob->query("unit") + "$n。\n" NOR;
					break;
				case "wrists":
					str = YEL "$N套起一" + ob->query("unit") + "$n。\n" NOR;
					break;
				case "surcoat":
					str = YEL "$N扎起一" + ob->query("unit") + "$n。\n" NOR;
					break;
				case "shield":
					str = YEL "$N拿起一" + ob->query("unit") + "$n。\n" NOR;
					break;

				default:
					str = YEL "$N装备$n。\n" NOR;
			}
		message_vision(str, me, ob);

if (!me->query_temp("item/wielda") && (ob->query("makeritem")||ob->query("systemmake")))
{	
    if (ob->query("armor_prop/neili"))
{
    	me->add("neili",ob->query("armor_prop/neili")*500);
message_vision(HIB + ob->query("name") + HIB"射出一道柔和的蓝光，$N在神光的沐浴下感到内力异常的充沛！\n"NOR, me);
me->set_temp("item/wielda",1);
}    
    if (ob->query("armor_prop/qi"))
{
    	me->add("max_qi",ob->query("armor_prop/qi")*300);
    	me->add("eff_qi",ob->query("armor_prop/qi")*300);
      me->add("qi",ob->query("armor_prop/qi")*300);
message_vision(HIR + ob->query("name") + HIR"射出一道耀眼的红光，$N在神光的沐浴下感到体力异常的充沛！\n"NOR, me);
me->set_temp("item/wielda",1);
}    
    if (ob->query("armor_prop/jing"))
{
    	me->add("max_jing",ob->query("armor_prop/jing")*300);
    	me->add("eff_jing",ob->query("armor_prop/jing")*300);
      me->add("jing",ob->query("armor_prop/jing")*300);
message_vision(HIY + ob->query("name") + HIY"射出一道夺目的黄光，$N在神光的沐浴下感到精力异常的充沛！\n"NOR, me);
me->set_temp("item/wielda",1);
}   
    
    if (ob->query("armor_prop/jingli"))
{
      me->add("max_jingli",ob->query("armor_prop/jingli")*300);
      me->add("eff_jingli",ob->query("armor_prop/jingli")*300);
      me->add("jingli",ob->query("armor_prop/jingli")*300);
message_vision(HIC + ob->query("name") + HIC"射出一道夺目的绿光，$N在神光的沐浴下感到精神异常的充沛！\n"NOR, me);
me->set_temp("item/wielda",1);
}
}
if (userp(me) && me->query_temp("xmud")) 
{
	seteuid(getuid());
	me->force_me("xnventory");
}
		return 1;
	} else
		return 0;
}

int help(object me)
{
	write(@HELP
指令格式：wear <装备名称>
 
这个指令让你装备某件防具。
 
HELP
    );
    return 1;
}
