 // force_book.c
inherit ITEM; 
void create()
{
        set_name("旧书", ({ "book" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long",
                        "这本旧书的纸张都已经泛黄了，上面居然记载着武道禅宗：嫁衣神功。\n"+
                        "传说中是一门极为厉害的内功，但至今为止，却无人能够练成。\n"+
                        "尤其是『为人作嫁』〔jiayi〕，只有施展出来，才知道有什么用处。\n"
                );
                set("value", 70);
                set("material", "paper");
		set("skill", ([
			"name":	      "force",	// name of the skill
			"exp_required":	0,	// minimum combat experience required
			"jing_cost":	30,	// jing cost every time study this
			"difficulty":	20,	// the base int to learn this skill
			"max_skill":	59
	
		]) );
        }
        setup();
}       
