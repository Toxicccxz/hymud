// 送子观音 /d/city/chuzhou/npc/obj/songzi_guanyin.c
// by lala, 1997-12-16

inherit ITEM;

void create()
{
        set_name( "送子观音", ({"songzi guanyin", "guanyin", }));
        set_weight(50);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", @LONG
一个泥捏的怀抱胖婴孩的观音大士，这是无锡的特产，是件送给新婚夫妇的好礼
物。
LONG
    );
                set("unit", "个");
                set("value", 250);
        }
        setup();
}
