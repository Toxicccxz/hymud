 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ITEM;
void create()
{
        set_name("���㾭", ({ "jinbook" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
                        "���ǲؾ����е�һ�����顣\n");
                set("value", 70);
                set("material", "wood");
                set("skill", ([
                        "name":                 "force",        
                        "exp_required":         1000,           
                        "jing_cost":             10,     
                        "difficulty":   10,     
                        "max_skill":    90              
                ]) );
        }
        
}     