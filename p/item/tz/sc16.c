// necklace.c �Ǵ�
#include <ansi.h>   
#include <armor.h>
 
inherit SURCOAT;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});   
void create()
{
	set_name((order[random(13)])+"��ɽ�Ǵ�"NOR, ({ "surcoat16"}) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "leather");
		set("unit", "��");set("no_get",1); set("no_put",1);set("no_pawn",1);set("no_drop",1);set("no_beg",1);set("no_steal",1);set("systemmake",1);
		set("long", "����һ��Ƥ�ʵĿ�ɽ�Ǵ������Ա���������\n");
		set("value", 3200);
		set("armor_prop/dodge", 18);
set("armor_prop/intelligence",18);
set("armor_prop/armor", 238);
	}
	setup();
}