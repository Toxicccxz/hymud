// 八宝印泥 /d/city/chuzhou/npc/obj/babao_yinni.c
// by lala, 1997-12-16

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name( REV RED"八宝印泥"NOR, ({"babao yinni", "yinni", }));
        set_weight(50);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", @LONG
这是福建漳州的特产。是采用麝香、珍珠、珊瑚、玛瑙等八种珍贵原料精制而成
的。历来为中外书法名家所喜好，并被列为皇家宫廷用品，在海外号称“国货之
光”。
LONG
    );
                set("unit", "盒");
                set("value", 700);
        }
        setup();
}
