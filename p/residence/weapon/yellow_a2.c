#include <ansi.h> 
#include <armor.h>

inherit SHIELD;

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
	      set_name("[1;37m����֮��[2;37;0m", ({ "sanqing shield", "shield" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long", @LONG
[1;36m����������������Σ������컯��һ�����壡����ǡ�����һ����塣��
[2;37;0m����һ�����ޱȼ�Ӳ��[37m����[2;37;0m����[37m���˿[2;37;0m�Ƴɣ����Ľ�����һǮ��[1;36m����֮��[2;37;0m��
�ۺ�����[1;36m��˫�޶�[2;37;0m �������ޱȼ�̣�����[32mˮ׼����[2;37;0m�ķ�������
������˼����ŷ��ţ�
[1;33m��[2;37;0m:[1;36m����[2;37;0m [36mľ[2;37;0m:[1;33m��ʥ[2;37;0m [1;35m��[2;37;0m:[1;32mħ��[2;37;0m 
[1;37m��[2;37;0m:[35m��׼[2;37;0m 
���滹����һЩ���֣�
��Ӳ:[1;33m����[2;37;0m ����:[32m�ֲ�[2;37;0m ��Ԩ:[32m�ֲ�[2;37;0m ����:[31m����[2;37;0m 
��ʯ:[31m����[2;37;0m ��ʯ:[1;36m����[2;37;0m 
�Լ�һ�Ź�׭�֡� [1;32m��ҩʦ[2;37;0m ������һЩ�� [1;32m����[2;37;0m ���ļ��ɡ�

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "yellow");
		set("ownername", "��ҩʦ");
		set("value", 25000);
		set("armor_prop/intelligence",56);
		set("armor_prop/strength",56);
		set("armor_prop/karey",48);
		set("armor_prop/percao",48);
		set("armor_prop/dexerity",56);
		set("armor_prop/constitution",40);
    set("armor_prop/dodge", 65);
    set("armor_prop/parry", 71);
    set("armor_prop/attack", 56);


    set("armor_prop/armor", 621);
    set("armor_prop/defense", 0);
    
    set("armor_prop/neili", 56);
    set("armor_prop/qi", 48);
    set("armor_prop/jing", 0);
    set("armor_prop/jingli", 40);
    set("armor_prop/damage", 354);

    set("wtypeA",7);
    set("wtypeB",10);
    set("wtypeC",0);
    set("wtypeD",4);
    set("wtypeE",0);
    set("wtypeF",9);
    set("wtypeG",5);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",6);
    
    
                set("skill", ([
                        "name": "throwing",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 300,              
                ]) );		


		set("material", "default");
    set("sharpness", 16);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";