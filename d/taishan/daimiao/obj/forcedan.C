inherit F_FOOD;
inherit ITEM;
#include <ansi.h>
void create()
{
    set_name(HIG"东岳丹"NOR , ({ "pill" }) );
        set_weight(5);
        if( clonep() )
                set_default_object(__FILE__);
        else {
  set("long", HIG
      "一颗青翠碧绿的仙丹，幽香阵阵，闪闪生辉。\n"
      "据说服食以后会提高体能的极限！\n"NOR); 
        set("unit", "个");
//        set("no_drop", 1);
        set("no_sell", 1);
//        set("no_give", 1);
        set("no_put", 1);
        set("lore",1);
        set("value", 0);
                set("food_remaining", 1);
                set("food_supply", 0);
                set("material", "food");
        }
        
}
int finish_eat()
{
        object me;
        int force, atman, mana,maxforce,maxatman,maxmana;
        int n;
        me = this_player();
        force = (int) me->query("neili");

        maxforce = (int) me->query("max_neili");

        if ( !me->query_temp("timer/pill") && force <= 15*maxforce && atman <= 15*maxatman && mana <= 15*maxmana )
        {
            message_vision( HIG "$N只觉腹中暖洋洋的十分舒服，全身隐隐散发出一股清雅的香气。\n"NOR, me);
        if (me->query("combat_exp")>3000000) n=2;
            else if (me->query("combat_exp")>2500000) n=3;
                        else n=4;
            force = force * n;
            atman = atman * n;
            mana = mana * n;
            me->add("neili", force);

            me->set_temp("timer/pill",1);
            destruct(this_object());
            return 1;
        } else 
        message_vision( HIW "$N突然觉得腹内一阵剧痛，似乎丹药吃的过多，失去原有的功效了。\n"NOR, me);
        destruct(this_object());
        return 1;
} 