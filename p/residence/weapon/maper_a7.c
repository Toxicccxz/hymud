#include <ansi.h> 
#include <armor.h>

inherit NECK;

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
	      set_name("[1;36m�ŵ���֮��[2;37;0m", ({ "shentong neck", "neck" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long", @LONG
[1;31m�����ͨ������Ҫƽ�ƣ���Ҫ���У����۹˼⣬���������ȣ�
��������Ȼ����������࣬������ͣ�磬���绨��������ֶ���
[2;37;0m����һ�����ޱȼ�Ӳ��[37m����[2;37;0m����[1;37m����˿[2;37;0m�Ƴɣ����Ľ�������Ǯ��[1;31m��֮ͨ����[2;37;0m��
�ۺ�����[1;36m��˫�޶�[2;37;0m �������ޱȼ�̣�����[34m����[2;37;0m�ķ�������
������˼����ŷ��ţ�
[36mľ[2;37;0m:[1;35m����[2;37;0m [33m��[2;37;0m:[1;34m����[2;37;0m [1;35m��[2;37;0m:[1;32mħ��[2;37;0m 
[1;37m��[2;37;0m:[1;31m����[2;37;0m 
���滹����һЩ���֣�
��Ӳ:[1;31m����[2;37;0m ����:[34mϸ��[2;37;0m ����:[31m����[2;37;0m 
��ʯ:[1;36m����[2;37;0m ����:[32m�ֲ�[2;37;0m ����:[35m��׼[2;37;0m 
�Լ�һ�Ź�׭�֡� [1;32m��ͼһ��[2;37;0m ������һЩ�� [1;32m����[2;37;0m ���ļ��ɡ�

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "maper");
		set("ownername", "��ͼһ��");
		set("value", 25000);
		set("armor_prop/intelligence",48);
		set("armor_prop/strength",48);
		set("armor_prop/karey",48);
		set("armor_prop/percao",48);
		set("armor_prop/dexerity",0);
		set("armor_prop/constitution",27);
    set("armor_prop/dodge", 73);
    set("armor_prop/parry", 0);
    set("armor_prop/attack", 48);


    set("armor_prop/armor", 282);
    set("armor_prop/defense", 48);
    
    set("armor_prop/neili", 48);
    set("armor_prop/qi", 32);
    set("armor_prop/jing", 54);
    set("armor_prop/jingli", 54);
    set("armor_prop/damage", 156);

    set("wtypeA",0);
    set("wtypeB",11);
    set("wtypeC",0);
    set("wtypeD",5);
    set("wtypeE",8);
    set("wtypeF",9);
    set("wtypeG",14);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",5);
    set("wtypeL",6);
    
    
                set("skill", ([
                        "name": "hammer",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 300,              
                ]) );		


		set("material", "default");
    set("sharpness", 15);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";