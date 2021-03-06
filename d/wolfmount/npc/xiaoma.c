#include <ansi.h>
inherit NPC; 
void create()
{
        set_name("小马", ({"xiao ma","ma"}) );
        set("title" , "愤怒的");
        set("gender", "男性" );
        set("age", 22);
        set("agi",30);
        set("per", 30);
                set("no_arrest",1);
                set("no_heal",1);
        set("str",100);
        set("long",
        "一个倔强、骄傲，全身都充满了叛逆性的小伙，别人都管他叫愤怒的小马。\n浑身都是伤口，你似乎可以帮他包扎（ｃｕｒｅ）一下。\n"
        );
        set("force_factor", 50);
        set("max_jing", 3000);
        set("max_qi", 3000);
        set("max_jing", 3000);
        set("eff_jing", 2000);
        set("eff_qi", 2000);
        set("eff_jing", 2000);
        set("jing", 2000);
        set("qi", 2000);
        set("jing", 2000);
        set("max_neili", 2000);
        set("force", 2000);
        set("combat_exp", 2999999);
        set("score", 30000);
        set("chat_chance",1);     
        set("chat_msg",({
                "小马握紧了拳头，愤怒的火焰在眼中燃烧。\n",
        "“小琳，小琳！”小马在溪水中挣扎前爬，浑身鲜血染红了清澈如镜的溪水。\n",
        }) );
set("max_qi", 13500);
	set("max_jing", 11500);
	set("neili", 23000);
	set("max_neili", 23000);
	set("jiali", 150);

	set("combat_exp", 5900000);
	set("score", 800000);
    set_skill("cuff", 300);
    set_skill("strike", 100);
    set_skill("qingfu-shenfa", 100);
    set_skill("hanbing-mianzhang", 100);
    set_skill("sougu", 100);
    	set_skill("force", 160);
	set_skill("dodge", 140);
	set_skill("sword", 140);
	set_skill("blade", 140);
	set_skill("parry", 140);
	set_skill("cuff", 200);
	set_skill("blade", 140);
	set_skill("jinwu-daofa", 140);
	set_skill("jiuyang-shengong", 260);
	set_skill("lingxu-bu", 140);
    	set_skill("damo-jian", 140);
    	set_skill("qishang-quan", 380);
    	set_skill("hunyuan-zhang", 150);
    	set_skill("literate", 100);

	map_skill("force", "jiuyang-shengong");
	map_skill("dodge", "lingxu-bu");
	map_skill("cuff", "qishang-quan");
    	map_skill("parry", "hunyuan-zhang");
    	map_skill("sword", "damo-jian");
	map_skill("blade", "jinwu-daofa");

	prepare_skill("cuff","qishang-quan");
	set_temp("apply/attack", 200);
	set_temp("apply/defense", 200);
	set_temp("apply/damage", 660);
	set_temp("apply/armor", 660);
	set("chat_chance_combat", 200);
	set("chat_msg_combat", ({
		(: command("perform hunpofeiyang") :),
		(: command("perform youyouhunduan") :),


	}) );
                setup();
} 
void init()
{
        object ob; 
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) 
        {
                add_action("do_cure", "cure");
                add_action("do_answer","answer");
                add_action("do_accept","accept");
        }
} 
int do_cure(string arg)
{
        object me;
        me = this_player();
        if( arg != "xiao ma" ) 
                return notify_fail("你要为谁治疗？\n");
        else if( this_object()->query("xiaoma_cured") )
                return notify_fail("小马说：不用麻烦了，我的伤势已经差不多好了！\n");
        else
        {
                if ( me->query("neili") < 1000)
                {
                        return notify_fail("你的内力不够深厚，真气不够用来治疗！\n");
                }
                else
                {
                        write(HIW "你全身放松，坐下来为小马运功疗伤。\n"NOR);
                        message_vision(HIW"小马因痛苦而扭曲的面孔慢慢平静了下来，喘着气一时说不出话来。\n"NOR , me);
                        me->add("force",-1000);
                        this_object()->set("xiaoma_cured",1);
                        me->start_busy(5);
                        call_out("ask_help", 5, me);
                        return 1;
                }       
        }
        return 1;
} 
void ask_help(object me)
{
        object obj;
        if ( me->query("宿命B/泰山_日出") )
        {
                message_vision(HIY"小马无神的眼睛突然亮了起来，用一种奇怪的眼神看着$N。\n"NOR, me);
                message_vision(HIY"小马抱拳说道：这位"+RANK_D->query_respect(me)+"，不知是否能助我救出小琳？（Answer Yes／No）\n"NOR, me);
                me->set_temp("marks/wolf_xiaoma_asking",1);
        }
        else
        {
                message_vision(HIY"一会儿，小马无神的眼睛突然亮了起来，感激的看着$N。\n"NOR, me);
                message_vision(HIY"小马向$N一抱拳，道：“我的伤势并不大碍，不知可否再麻烦这位英雄，\n帮我救出老皮和小琳？”。（Accept Yes／No）\n"NOR, me);
                me->set_temp("marks/wolf_xiaoma_questing",1);
                return;
        }
} 
int do_answer(string arg)
{
        object me, obj;
        object room; 
        obj = this_object();
        me =this_player();
        if(!me->query_temp("marks/wolf_xiaoma_asking")) return 0;
        
        if( arg == "yes" || arg == "YES" )
        {
                me->delete_temp("marks/wolf_xiaoma_asking"); 
                message_vision("$N握紧拳头道：小琳被太阳使者的药物控制，我们就到太阳湖的花舟找\n太阳使者决一死战！花舟再见！\n", obj);
                me->set_temp("marks/wolf_xiaoma_good", 1); 
                message_vision("$N转身向远处的湖泊走去......\n", obj);
                obj->set("chat_chance",0);   
                room = find_object("/d/wolfmount/flowerboat");
                if(!objectp(room)) room = load_object("/d/wolfmount/flowerboat");
                obj->move(room);
                return 1;
        }
        else if ( arg == "no" || arg == "NO" )
        {
           message_vision("$N神色黯然：看来"+me->name()+"也帮不了我！\n", obj);
                me->delete_temp("marks/wolf_xiaoma_asking"); 
                return 1;
        }
        else 
        {
                tell_object(me, name()+"道：我不大明白你的意思哎！\n");
                return 1;
        }
} 
int do_accept(string arg)
{
        object me, obj;
        obj = this_object();
        me =this_player();
        if(!me->query_temp("marks/wolf_xiaoma_questing")) return 0;
        
        if( arg == "yes" || arg == "YES" )
        {
                message_vision("$N朗声笑道：多谢这位英雄！\n", obj);
                me->delete_temp("marks/wolf_xiaoma_questing"); 
                message_vision("$N神色凝重道：小琳被太阳使者的药物所控制，只有杀了太阳使者才会解除控制！\n", obj);
                me->set_temp("marks/wolf_xiaoma_normal", 1); 
                obj->set("chat_chance",0);
                return 1;
        }
        else if ( arg == "no" || arg == "NO" )
        {
                message_vision("$N长叹一声：求人不如求自己．大不了拼得一死！\n", obj);
                message_vision("$N转身离去，孤单的身影渐渐走远......\n", obj);
                me->delete_temp("marks/wolf_xiaoma_questing");
                destruct(obj);
                message_vision("$N失魂落魄，羞愧难当，为自己的懦夫行为感到万分后悔．\n",me);
                me->add("score",-100);
                return 1;
        }
        else 
        {
                tell_object(me, name()+"道：我不大明白你的意思哎！\n");
                return 1;
   }
} 
void die()
{
        object xiaolin;
        if (xiaolin = present("xiao lin",environment(this_object())))
        {
                xiaolin->set("xiaoma_died",1);
        }
        ::die();
}  
