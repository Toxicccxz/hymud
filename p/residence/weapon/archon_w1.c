// gangjian.c

#include <ansi.h>
#include <weapon.h>

//inherit M_WEAPON;
//inherit F_GEMS;
inherit SWORD;

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

void create()
{
	set_name("[33m���֮��[2;37;0m", ({ "jinguang sword", "sword" }));
	set_weight(2933);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", @LONG
[33m���֮��[2;37;0m����һ�����ޱȼ�Ӳ��[1;37m����[2;37;0m�Ƴɣ�����������Ǯ��[33m���֮��[2;37;0m��
�ۺ�����[37m������˫[2;37;0m �������ޱȷ���������[1;33m������ƥ[2;37;0m��������
������˼����ŷ��ţ�
[37m��[2;37;0m:[33m�ܸ�[2;37;0m [40m��[2;37;0m:[33m�ܸ�[2;37;0m [36mľ[2;37;0m:[35m��׼[2;37;0m [32mˮ[2;37;0m:[1;32mħ��[2;37;0m [33m��[2;37;0m:[1;31m��˫[2;37;0m 
���滹����һЩ���֣�
����:[1;31m��˫[2;37;0m ����:[32m�ֲ�[2;37;0m 
����:[33m�ܸ�[2;37;0m ��ʯ:[33m�ܸ�[2;37;0m ����:[33m�ܸ�[2;37;0m 
����:[36m����[2;37;0m ����:[34mϸ��[2;37;0m 
�Լ�һ�Ź�׭�֡� [1;32mʥ��[2;37;0m ������һЩ�� [1;32m�ڹ�[2;37;0m ���ļ��ɡ�

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "archon");
		set("ownername", "ʥ��");
		set("value", 16000);
		set("weapon_prop/intelligence",24);
		set("weapon_prop/strength",32);
		set("weapon_prop/karey",40);
		set("weapon_prop/percao",24);
		set("weapon_prop/dexerity",24);
		set("weapon_prop/constitution",24);
    set("weapon_prop/dodge", 24);
    set("weapon_prop/parry", 43);
    set("weapon_prop/attack", 49);
    set("weapon_prop/armor", 36);
    set("weapon_prop/defense", 48);
    
    set("weapon_prop/neili", 40);
    set("weapon_prop/qi", 48);
    set("weapon_prop/jing", 48);
    set("weapon_prop/jingli", 40);
    set("weapon_prop/damage", 0);

    set("wtypeA",3);
    set("wtypeB",5);
    set("wtypeC",2);
    set("wtypeD",4);
    set("wtypeE",12);
    set("wtypeF",0);
    set("wtypeG",4);
    set("wtypeH",4);
    set("wtypeI",4);
    set("wtypeJ",4);
    set("wtypeK",2);
    set("wtypeL",2);
    

                set("skill", ([
                        "name": "force",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 320,              
                ]) );		
		set("base_unit", "��");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 12);

		set("wield_msg", "$N��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n���¡�\n");
	}
	
	init_sword(1116);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";