 // An example book
inherit ITEM; 
void create()
{
        set_name("蝶恋花剑法秘笈" , ({ "deisword" }) );
        set_weight(600);
        set("unit", "本");
        set("long", "这是一本介绍蝶恋花剑法的武功秘笈\n");
        set("value", 0);
        set("skill", ([
                "name":                 "deisword",      
                "exp_required": 200000,       
                "jing_cost":             35,
                "difficulty":   30,  
                "max_skill":    60     
        ]) );
}
        
