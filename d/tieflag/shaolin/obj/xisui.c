 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit COMBINED_ITEM;
void create()
{
        set_name("洗髓经", ({ "xisui"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "捆");
                set("base_unit","卷");
                set("long",
                        "这是东林视为至宝的洗髓经.\n");
                set("value", 70);
                set("material", "paper");
                set("no_sell",1);
                set("no_get",1);
                set("no_drop",1); 
                set("skill", ([
                        "name":                 "yijinjing",        
                        "exp_required": 2000000,                
                        "jing_cost":             10,     
                        "difficulty":   123,     
                        "max_skill":    99,
                        "literate" : "banruo-zhang",
                        "liter_level":  50,
                ]) );
        }
        set_amount(1);
}      
