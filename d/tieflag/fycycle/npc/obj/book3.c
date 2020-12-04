 // An example book
inherit ITEM; 
void create()
{
        set_name("风尘简" , ({ "fengchen book", "book" }) );
        set_weight(600);
        set("unit", "本");
        set("long", "这是一册沉甸甸的竹简，乃风尘三侠之虬髯客游历海内诸国后呕心沥血写就。 
包罗万象，深奥无比。 \n");
        set("value", 100000);
        set("no_drop", 1);
        set("no_get", 1);
        set("no_sell", 1);
		set("skill", ([
                        "name":         "force",      //name of the skill
                        "exp_required": 100000 ,        //minimum combat experience required
			"jing_cost":    20+random(100),// jing cost every time study this
			"difficulty":	60,           // the base int to learn this skill
			"min_skill":	0,           // the minimum level you can learn
			"max_skill":	120            // the maximum level you can learn
		]) );
}
     
