 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ITEM;
void create()
{
        set_name("�����Ħ��ʯ��", ({ "damo" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
                        "һ��˫�ֺ�ʮ����òׯ�صĴ�Ħʯ������������һЩ�֡�\n");
                set("value", 70);
                set("material", "wood");
                set("no_get",1);
                set("no_drop",1);
                set("skill", ([
                        "name":                 "force",    
                        "exp_required":         1000,           
                        "jing_cost":             80,     
                        "difficulty":   20,     
                        "max_skill":    280              
                ]) );
        }
        
}       