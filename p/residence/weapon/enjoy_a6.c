#include <ansi.h> 
#include <armor.h>

inherit SURCOAT;

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
	      set_name("[1;31mδ��[2;37;0m", ({ "xuanyuan surcoat", "surcoat" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long", @LONG
[1;35m���ջƵ۳ִ�������ָ�ϳ��ϣ���������ɨ��������Ӧ�����ɣ������޶�ս��ȣ�
[2;37;0m����һ�����൱��Ӳ��[37m����[2;37;0m����[37m���˿[2;37;0m�Ƴɣ���һ�������Ǯ��[1;35m��ԯ֮�Ǵ�[2;37;0m��
�ۺ�����[1;36m��˫�޶�[2;37;0m �������൱��̣�����[34m����[2;37;0m�ķ�������
������˼����ŷ��ţ�
[1;33m��[2;37;0m:[1;31m��Ԫ[2;37;0m [32mˮ[2;37;0m:[1;31m��Ԫ[2;37;0m [33m��[2;37;0m:[35m��׼[2;37;0m [1;35m��[2;37;0m:[1;32mħ��[2;37;0m 

���滹����һЩ���֣�
��Ӳ:[1;33m����[2;37;0m ����:[32m�ֲ�[2;37;0m 
����:[1;36m����[2;37;0m ����:[35m��׼[2;37;0m ����:[35m��׼[2;37;0m 
�Լ�һ�Ź�׭�֡� [1;32m������[2;37;0m ������һЩ�� [1;32m�м�[2;37;0m ���ļ��ɡ�

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "enjoy");
		set("ownername", "������");
		set("value", 25000);
		set("armor_prop/intelligence",48);
		set("armor_prop/strength",40);
		set("armor_prop/karey",0);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",48);
		set("armor_prop/constitution",0);
    set("armor_prop/dodge", 56);
    set("armor_prop/parry", 0);
    set("armor_prop/attack", 0);


    set("armor_prop/armor", 284);
    set("armor_prop/defense", 32);
    
    set("armor_prop/neili", 48);
    set("armor_prop/qi", 70);
    set("armor_prop/jing", 58);
    set("armor_prop/jingli", 58);
    set("armor_prop/damage", 186);

    set("wtypeA",13);
    set("wtypeB",6);
    set("wtypeC",13);
    set("wtypeD",6);
    set("wtypeE",5);
    set("wtypeF",9);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",6);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",6);
    
    
                set("skill", ([
                        "name": "parry",
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