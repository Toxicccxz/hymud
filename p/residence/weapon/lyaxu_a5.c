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
	      set_name("[1;32m�����ֻ�[2;37;0m", ({ "moye cloth", "cloth" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long", @LONG
[31mĪа�����ޱȣ��ܿ���ٵأ�������ħ��
[2;37;0m����һ���ɾ��Լ�Ӳ��[1;36m���꺮����[2;37;0m����[1;33m�����˿[2;37;0m�Ƴɣ����Ľ�������Ǯ��[31mĪа֮��װ[2;37;0m��
�ۺ�����[35m�������[2;37;0m ���������Լ�̣�����[1;33m������ƥ[2;37;0m�ķ�������
������˼����ŷ��ţ�
[1;33m��[2;37;0m:[1;33m����[2;37;0m [36mľ[2;37;0m:[1;31m��Ԫ[2;37;0m [33m��[2;37;0m:[1;35m����[2;37;0m [1;35m��[2;37;0m:[1;36m����[2;37;0m 
[1;37m��[2;37;0m:[31m����[2;37;0m [1;34m��[2;37;0m:[1;36m����[2;37;0m 
���滹����һЩ���֣�
��Ӳ:[1;33m����[2;37;0m ��Դ:[33m�ܸ�[2;37;0m 
����:[33m�ܸ�[2;37;0m 
��ʯ:[31m����[2;37;0m ����:[1;34m����[2;37;0m ����:[31m����[2;37;0m ����:[32m�ֲ�[2;37;0m 
�Լ�һ�Ź�׭�֡� [1;32m����վ[2;37;0m ������һЩ�� [1;32m�ַ�[2;37;0m ���ļ��ɡ�

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "lyaxu");
		set("ownername", "����վ");
		set("value", 36000);
		set("armor_prop/intelligence",0);
		set("armor_prop/strength",24);
		set("armor_prop/karey",46);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",0);
		set("armor_prop/constitution",0);
    set("armor_prop/dodge", 0);
    set("armor_prop/parry", 68);
    set("armor_prop/attack", 0);


    set("armor_prop/armor", 840);
    set("armor_prop/defense", 0);
    
    set("armor_prop/neili", 80);
    set("armor_prop/qi", 63);
    set("armor_prop/jing", 36);
    set("armor_prop/jingli", 36);
    set("armor_prop/damage", 24);

    set("wtypeA",16);
    set("wtypeB",13);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",11);
    set("wtypeF",7);
    set("wtypeG",6);
    set("wtypeH",7);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    
    
                set("skill", ([
                        "name": "hand",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 480,              
                ]) );		


		set("material", "default");
    set("sharpness", 26);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";