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
	      set_name("[34m�ڲ���[2;37;0m", ({ "zhanlu cloth", "cloth" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long", @LONG
[31mտ¬��������������Ӳ���ھ���������ǧ�������
[2;37;0m����һ�����ޱȼ�Ӳ��[1;36m���꺮����[2;37;0m����[1;33m�����˿[2;37;0m�Ƴɣ����߽����һǮ��[31mտ¬֮��װ[2;37;0m��
�ۺ�����[35m�������[2;37;0m �������ޱȼ�̣�����[1;33m������ƥ[2;37;0m�ķ�������
������˼����ŷ��ţ�
[37m��[2;37;0m:[1;34m����[2;37;0m [1;33m��[2;37;0m:[31m����[2;37;0m [36mľ[2;37;0m:[1;33m��ʥ[2;37;0m [32mˮ[2;37;0m:[1;31m����[2;37;0m [1;35m��[2;37;0m:[1;33m��ʥ[2;37;0m 

���滹����һЩ���֣�
��Ӳ:[1;33m����[2;37;0m ����:[33m�ܸ�[2;37;0m ��Դ:[33m�ܸ�[2;37;0m 
����:[33m�ܸ�[2;37;0m ����:[33m�ܸ�[2;37;0m 
����:[1;36m����[2;37;0m ��ʯ:[31m����[2;37;0m ����:[31m����[2;37;0m 
�Լ�һ�Ź�׭�֡� [1;32m������[2;37;0m ������һЩ�� [1;32m����[2;37;0m ���ļ��ɡ�

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "eddie");
		set("ownername", "������");
		set("value", 36000);
		set("armor_prop/intelligence",72);
		set("armor_prop/strength",47);
		set("armor_prop/karey",43);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",0);
		set("armor_prop/constitution",46);
    set("armor_prop/dodge", 72);
    set("armor_prop/parry", 61);
    set("armor_prop/attack", 0);


    set("armor_prop/armor", 840);
    set("armor_prop/defense", 77);
    
    set("armor_prop/neili", 64);
    set("armor_prop/qi", 0);
    set("armor_prop/jing", 72);
    set("armor_prop/jingli", 0);
    set("armor_prop/damage", 64);

    set("wtypeA",6);
    set("wtypeB",10);
    set("wtypeC",14);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",10);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",8);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    
    
                set("skill", ([
                        "name": "club",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 480,              
                ]) );		


		set("material", "default");
    set("sharpness", 18);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";