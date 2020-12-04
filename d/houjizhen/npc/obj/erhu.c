// erhu.c
// by dicky

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("二胡", ({"er hu","erhu"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一把比较考究的民间乐器二胡。你可以演奏(play)它。\n");
                set("value", 100);
        }
        setup();
}

void init()
{
        add_action("do_play", "play");
}

int do_play(string arg)
{
        if (!id(arg))
                return notify_fail("你要演奏什么？\n");
        switch( random(3) ) {
                case 0:
                        message_vision(CYN"$N拉起二胡，深情地唱道：\n"NOR
CYN"在那遥远的地方，有位好姑娘。每当人们走过她的毡房，总要把她\n"NOR
CYN"深情地凝望。\n"NOR, this_player());
                        break;
                case 1:
                        message_vision(CYN"$N拉起二胡，快乐地唱道：\n"NOR
CYN"嫁人不要嫁给别人，一定要嫁给我，带上你的妹妹，带上你的嫁妆，\n一起到大坂城来。\n"NOR, this_player());
                        break;
                case 2:
                        message_vision(CYN"$N拉起二胡，哀伤地唱道：\n"NOR
CYN"离家的孩子，流浪在外边，没有那好衣裳，也没有好烟，好不容易找份工作，\n辛勤把活干，"NOR
CYN"心里头流着泪，脸上流着汗。\n"NOR, this_player());
                        break;
        }
        return 1;
}

