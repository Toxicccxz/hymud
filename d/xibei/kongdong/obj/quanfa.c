// jianshu.c

inherit ITEM;

void create()
{
    set_name("「格斗大全」", ({ "gedou daquan", "book", "shu" }));
    set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit", "本");
        set("long",     "这是一本普普通通的介绍基本拳法的书。\n");
        set("value", 20);
        set("material", "paper");
       set("skill", ([
                        "name"             :  "unarmed",  
                        "xiuwei_required"  : 0,
                        "literate_required" : 5,
                        "jing_cost"         : 10+random(10),
                        "max_lingwu"       : 20,
                        "bonus_jilei"      : 6,
//                      "bonus_xiuwei"     : 2,
//                      "max_xiuwei"       : 400,
                        "bonus_combat_exp" : 1,
                        "max_combat_exp"   : 100,
                        "bonus_social_exp" : 0,
                        "max_social_exp"   : 0,
                ]) );
        }
}