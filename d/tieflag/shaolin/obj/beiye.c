 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ITEM;
#include <ansi.h>
void create()
{
        set_name(HIG"��Ҷ��"NOR, ({ "beiye","jing"}));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
                        "һ������ʦ��ʱ��ʮ��������Ѫд�ɵĻ���Ѫ��\n");
                set("value", 700);
                set("material", "stone");
                set("skill", ([
                        "name":                 "ranmu-daofa",     
                        "exp_required": 500000,         
                        "jing_cost":             10,     
                        "difficulty":   10,     
                        "literate": "banruo-zhang",
                        "max_skill":    99,
                        "liter_level":  50              
                ]) );
        }
} 