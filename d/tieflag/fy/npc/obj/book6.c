 // spells_book.c
inherit ITEM; 
void create()
{
        set_name("符咒入门", ({ "spellsbook" }));
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long",
                        
"这似乎是一本符咒的简介，里面画着一些稀奇古怪的符号\n"
                );
                set("value", 1260);
                set("material", "paper");
		set("skill", ([
			"name":	      "spells",	// name of the skill
			"exp_required":	0,	// minimum combat experience required
			"jing_cost":	30,	// jing cost every time study this
			"difficulty":	20,	// the base int to learn this skill
			"max_skill":	59
	
		]) );
        }
        setup();
}
       
