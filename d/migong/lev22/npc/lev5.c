#include <ansi.h>
inherit NPC;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});


void create()

{
	mapping npc,mp,j;
	int i,k,a,b,c,d,e,f,temp;
   set_name(order[random(13)]+"泰坦巨人"NOR, ({ "titan"}));
	set("magicgift",4);
	set("magicset",1);
       set("zhuanbest",1);
       set("long",
"一只可怕的泰坦巨人。\n");
              set("attitude", "aggressive");
                set("vendetta/authority",1);
	       set("max_qi",500+random(500));
	set("combat_exp",69000000+random(8000000));
        set_skill("spells",1200+random(1000));
        set_skill("force",1200+random(1000));
	set_skill("unarmed",1200+random(1000));
	set_skill("sword",1200+random(1000));
	set_skill("club",1200+random(1000));
	set_skill("whip",450+random(300));
	set_skill("throwing",1200+random(1000));
	set_skill("parry",1200+random(1000));
	set_skill("force",690+random(300));	
      set_skill("magic-unarmed", 1200+random(1000));
      set_skill("magic-sword", 1200+random(1000));
      set_skill("magic-earth", 490+random(200));
      map_skill("sword", "magic-sword");
      map_skill("unarmed", "magic-unarmed");
      map_skill("parry", "magic-unarmed");
map_skill("spells", "magic-earth");
        set("no_get",1);
      set_skill("magic-dark", 1200+random(1000));
      set_skill("magic-light", 1200+random(1000));
      set_skill("magic-earth", 1200+random(1000));
      set_skill("magic-ice", 1200+random(1000));
      set_skill("magic-water", 1200+random(1000));
      set_skill("magic-fire", 1200+random(1000));
      set_skill("magic-unarmed", 1200+random(1000));
      set_skill("magic-sword", 1200+random(1000));
      map_skill("sword", "magic-sword");
      map_skill("unarmed", "magic-unarmed");
      map_skill("parry", "magic-unarmed");
	set_skill("force",750+random(300));
	set_skill("huntian-qigong",750+random(300));
	map_skill("force", "huntian-qigong");
b=89000+random(86000);
a=81000+random(88000);
d=150+random(60);
set("str",d);
set("dex",60+d);
set("int",d);
set("con",d);
set("per",d);
set("kar",d);
        set("jing",b);
        set("max_jing",b);
set("eff_jing",b);
        set("qi",a);
        set("max_qi",a);
set("eff_qi",a);

        set("neili",a);
        set("max_neili",a);
       
    set("age", 15);

        set("shen_type", -1);

        set("intellgent",1);

	set("pursuer",1);
	set_temp("apply/attack",150);
	set_temp("apply/defense",150);
	set_temp("apply/armor",5800);
	set_temp("apply/damage",1600);

 set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
    (: perform_action, "spells.Attach" :),
    (: perform_action, "spells.missile" :),
    (: perform_action, "spells.quake" :),
 }) );
if (random(16)==0)
{
set("nickname",HIY"武功高超"NOR);
        set_skill("spells",1200+random(1000));
        set_skill("force",1200+random(1000));
	set_skill("unarmed",1200+random(1000));
	set_skill("sword",1200+random(1000));
	set_skill("club",1200+random(1000));
	set_skill("whip",1200+random(1000));
	set_skill("throwing",1200+random(1000));
	set_skill("parry",1200+random(1000));
}
else
if (random(16)==0)
{
set("nickname",MAG"魔法强大"NOR);
      set_skill("magic-unarmed", 1200+random(1000));
      set_skill("magic-sword", 1200+random(1000));
      set_skill("magic-ice", 1200+random(1000));
      set_skill("magic-water", 1200+random(1000));
      set_skill("magic-fire", 1200+random(1000));
      set_skill("magic-earth", 1200+random(1000));
      set_skill("magic-light", 1200+random(1000));
      set_skill("magic-dark", 1200+random(1000));
}
else
if (random(16)==0)
{
set("nickname",HIB"经验丰富"NOR);
set("combat_exp",50000000+random(48000000));
}
else
if (random(16)==0)
{
set("nickname",HIR"强大不死"NOR);
set("dex",300);
        set("jing",600000);
        set("max_jing",600000);
        set("eff_jing",600000);
        set("qi",600000);
        set("max_qi",600000);
        set("eff_qi",600000);
        set("neili",600000);
        set("max_neili",600000);
	set("combat_exp",10000000);
}
else
if (random(16)==0)
{
set("nickname",HIC"超级加强"NOR);
d=88+random(88);
set("str",d);
set("dex",30+d);
set("int",d);
set("con",d);
set("per",d);
set("kar",d);
}
else
if (random(16)==0)
{
set("dex",300);
        set("jing",100000);
        set("max_jing",100000);
        set("eff_jing",100000);
        set("qi",100000);
        set("max_qi",100000);
        set("eff_qi",100000);
        set("neili",100000);
        set("max_neili",100000);
      set_skill("magic-unarmed", 1200+random(1000));
      set_skill("magic-sword", 1200+random(1000));
      set_skill("magic-ice", 1200+random(1000));
      set_skill("magic-water", 1200+random(1000));
      set_skill("magic-fire", 1200+random(1000));
      set_skill("magic-earth", 1200+random(1000));
      set_skill("magic-light", 1200+random(1000));
      set_skill("magic-dark", 1200+random(1000));
        set_skill("spells",1200+random(1000));
        set_skill("force",1200+random(1000));
	set_skill("unarmed",1200+random(1000));
	set_skill("sword",1200+random(1000));
	set_skill("club",1200+random(1000));
	set_skill("whip",1200+random(1000));
	set_skill("throwing",1200+random(1000));
	set_skill("parry",1200+random(1000));
set("nickname",HIC"完美无敌"NOR);
d=88+random(88);
set("str",d);
set("dex",30+d);
set("int",d);
set("con",d);
set("per",d);
set("kar",d);
}
   setup();

//carry_object(__DIR__"obj/sword")->wield();
carry_object(__DIR__"obj/cloth")->wear();
}

void init( )

{
	object ob;	
        remove_call_out("hunting");
	if( interactive(ob = this_player())  ) {
ob->start_busy(1);
        call_out("hunting",0);
        }
	if(!environment()->query("no_fight"))
        call_out("hunting",0);
}

void hunting()
{
	int i;
        object *ob;
        ob = all_inventory(environment());
        for(i=sizeof(ob)-1; i>=0; i--) {
        if( !ob[i]->is_character() || ob[i]==this_object() || !living(ob[i])) continue;
        if(ob[i]->query("vendetta/authority")) continue;
                kill_ob(ob[i]);
                ob[i]->fight(this_object());
        }
}

void die()
{
        object ob, me, corpse;
        
        ob = this_object();
        me = query_temp("last_damage_from");
if (!me) return;        
              me->add("score",1);
        message_vision(RED"$N,倒地而亡，不动弹了。\n"NOR,ob,me);
        if((int)me->query("combat_exp") < ob->query("combat_exp"))   {
        message("vision", me->name() + HIG"成功消灭"+ob->query("name")+",增加了200经验和100潜能。\n"NOR, me);
        me->add("combat_exp",200);
        me->add("potential",100);
              me->add("score",1);
        destruct(ob);
        }
 
               destruct(ob);
        return;
}

int hit_ob(object me, object ob, int damage)
{
string msg;
        if(random((int)me->query("combat_exp")) > ob->query("combat_exp")/2)   
{
             ob->add("qi",-ob->query("qi")/30);
             ob->add("eff_qi",-ob->query("eff_qi")/30);
             ob->add("jing",-ob->query("jing")/30);
             ob->add("eff_jing",-ob->query("eff_jing")/30);
ob->apply_condition("sanxiao_poison", 2);
           msg = HIR"$N"HIR"手拿闪电"HIR"$n"HIR"被闪电包围了!!\n"NOR;
            message_vision(msg, me, ob);
}
}