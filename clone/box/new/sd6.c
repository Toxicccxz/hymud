// shield.c ţƤ��
#include <ansi.h>   
#include <armor.h>
 
inherit SHIELD;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});  
void create()
{
	set_name((order[random(13)])+"����֮��"NOR, ({ "shield6"}) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "leather");
		set("unit", "��");
		set("value", 1600);
		set("armor_prop/armor", 62);
		set("armor_prop/defense", 16);
set("armor_prop/strength",2);
	}
	setup();
}