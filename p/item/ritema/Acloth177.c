#include <ansi.h> 
#include <armor.h>

inherit CLOTH;

string *du=({
"ice_poison",
"ill_dongshang",
"ill_fashao",
"ill_kesou",
"ill_shanghan",
"ill_zhongshu",
"xx_poison",
"cold_poison",
"flower_poison",
"rose_poison",
"x2_poison",
"sanpoison",
"scorpion_poison",
"anqi_poison",
"nx_poison",
"chilian_poison",
"yufeng_poison",
"insect_poison",
"xscold_poison",
});

string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});  
void create()
{
	      set_name("[34m百合之服装[2;37;0m", ({ "general cloth", "cloth" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
		set("long", @LONG
百合之服装[2;37;0m这是一件由非常坚硬的精钢加上[33m亚麻[2;37;0m制成，重三斤一两九钱的[34m百合之服装[2;37;0m。
综合评价[31m完美精致[2;37;0m 看起来非常坚固，具有[32m水准以上[2;37;0m的防护力！
上面刻了几个古符号：
[1;37m雷[2;37;0m:[31m精致[2;37;0m 
上面还刻了一些符字：
坚硬:[33m很高[2;37;0m 天渊:[32m极差[2;37;0m 巧制:[36m不错[2;37;0m 
体灵:[36m不错[2;37;0m 白石:[32m极差[2;37;0m 不老:[33m一般[2;37;0m 

LONG
);
    set("no_get",1);
	  set("no_put",1);
	  set("no_pawn",1);
	  set("no_drop",1);
	  set("no_beg",1);
	  set("no_steal",1);
	  set("systemmake",1);
		set("value", 2000);
		set("armor_prop/intelligence",0);
		set("armor_prop/strength",0);
		set("armor_prop/karey",0);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",2);
		set("armor_prop/constitution",0);
    set("armor_prop/dodge", 3);
    set("armor_prop/parry", 0);
    set("armor_prop/attack", 0);


    set("armor_prop/armor", 180);
    set("armor_prop/defense", 15);
    
    set("armor_prop/neili", 0);
    set("armor_prop/qi", 0);
    set("armor_prop/jing", 9);
    set("armor_prop/jingli", 9);
    set("armor_prop/damage", 0);

    set("wtypeA",0);
    set("wtypeB",0);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",0);
    set("wtypeG",6);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    
    
                set("skill", ([
                        "name": "leg",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 120,              
                ]) );		


		set("material", "default");
    set("sharpness", 4);
        }
        setup();
}



#include "/obj/ritem/armorzy.h";