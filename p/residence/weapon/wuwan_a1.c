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
	      set_name("[1;34mһ��[2;37;0m", ({ "longquan cloth", "cloth" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long", @LONG
[31m��Ȫ�˼伫Ʒ������������
[2;37;0m����һ�����ޱȼ�Ӳ��[1;36m���꺮����[2;37;0m����[1;33m�����˿[2;37;0m�Ƴɣ����߽������Ǯ��[31m��Ȫ֮��װ[2;37;0m��
�ۺ�����[35m�������[2;37;0m �������ޱȼ�̣�����[1;33m������ƥ[2;37;0m�ķ�������
������˼����ŷ��ţ�
[1;36m��[2;37;0m:[1;32mħ��[2;37;0m [36mľ[2;37;0m:[1;31m����[2;37;0m [31m��[2;37;0m:[1;31m��˫[2;37;0m [33m��[2;37;0m:[1;31m����[2;37;0m [1;35m��[2;37;0m:[1;31m����[2;37;0m 

���滹����һЩ���֣�
��Ӳ:[1;33m����[2;37;0m ��Դ:[32m�ֲ�[2;37;0m 
����:[33m�ܸ�[2;37;0m 
��ʯ:[1;36m����[2;37;0m ��ʯ:[31m����[2;37;0m ����:[33m�ܸ�[2;37;0m ����:[1;36m����[2;37;0m 
�Լ�һ�Ź�׭�֡� [1;32m����[2;37;0m ������һЩ�� [1;32m�ȷ�[2;37;0m ���ļ��ɡ�

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "wuwan");
		set("ownername", "����");
		set("value", 36000);
		set("armor_prop/intelligence",72);
		set("armor_prop/strength",72);
		set("armor_prop/karey",36);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",72);
		set("armor_prop/constitution",72);
    set("armor_prop/dodge", 79);
    set("armor_prop/parry", 63);
    set("armor_prop/attack", 72);


    set("armor_prop/armor", 1095);
    set("armor_prop/defense", 72);
    
    set("armor_prop/neili", 45);
    set("armor_prop/qi", 73);
    set("armor_prop/jing", 0);
    set("armor_prop/jingli", 0);
    set("armor_prop/damage", 140);

    set("wtypeA",0);
    set("wtypeB",15);
    set("wtypeC",0);
    set("wtypeD",12);
    set("wtypeE",14);
    set("wtypeF",15);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",9);
    set("wtypeL",9);
    
    
                set("skill", ([
                        "name": "staff",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 480,              
                ]) );		


		set("material", "default");
    set("sharpness", 27);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";