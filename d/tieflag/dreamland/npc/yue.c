 // Copyright (C) 2001, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <ansi.h>
inherit NPC;
void dream_return(object me);
void create()
{
    set_name("岳飞", ({ "yue fei" }) );
    set("long",
        "一位银盔银甲，顶梁飘撒红缨的中年将军。\n");
    set("attitude", "friendly");
    set("chat_chance", 1);
    set("chat_msg", ({
                "岳飞面色凝重地望了往西北方向，喃喃到：不知道襄阳的主力现在到了何处。。。\n",
                "岳飞用力握住银枪杆，入神的关注着眼前的战局。 \n",
    }) );
        set("gender", "男性");
    set("title", "少保");
    set("nickname", "京西路宣抚副使");
    set("str", 250+random(10));
     set("dex", 250+random(10));
    set("cor", 40);
    set("cps", 25);
    set("per",38);
    set("int",30);
    set("max_qi",7000);
    set("max_jing",5000);
    set("max_sen",5000);
    set("max_neili",2000);
    set("neili",2000);
    set("eff_force",2000);
        set("age",40);
    set("combat_exp", 90000000);
    set_temp("apply/damage",500);
    set("qi", 32000);
	set("max_qi", 32000);
	set("jing", 33800);
	set("max_jing", 33800);
	set("neili", 32000);
	set("max_neili", 32000);
	set("jiali", 200);
	
	set("combat_exp", 1500000);
	set("score", 200000);
	set("shen", 100000);
	 	set_skill("fengmo-zhang",180);
	set_skill("liuhe-zhang",180);
set_skill("dagou-bang",80);
	set_skill("strike",190);
	set_skill("force", 250);             // 
	set_skill("force", 180);             // 基本内功
	set_skill("huntian-qigong", 330);    // 混天气功
	set_skill("dodge", 150);      	     // 基本躲闪
	set_skill("xiaoyaoyou", 320);        // 逍遥游
	set_skill("parry", 150);             // 基本招架
	set_skill("hand", 200);              // 基本手法

	set_skill("blade", 180);             // 基本刀法
	set_skill("liuhe-dao", 280);       // 四象六合刀
	set_skill("begging", 200);           // 叫化绝活
	set_skill("checking", 200);          // 道听途说
	set_skill("training", 200);          // 驭兽术
	set_skill("strike",285);  // 基本掌法

	set_skill("xianglong-zhang",285);

	map_skill("strike","lianhua-zhang");
	prepare_skill("strike","lianhua-zhang");

	
	map_skill("force", "huntian-qigong");
	map_skill("hand",  "suohou-gong");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("blade", "liuhe-blade");
	map_skill("parry", "yuejia-qiang");

	set_skill("yuejia-qiang", 880);        // 打狗棒法
	set_skill("suohou-gong", 380);        // 打狗棒法
set_skill("chansi-shou", 380);        // 打狗棒法
set_skill("claw", 380);        // 打狗棒法
set_skill("hand", 380);        // 打狗棒法	
set_skill("club", 380);        // 打狗棒法		
map_skill("parry", "yuejia-qiang");
map_skill("club", "yuejia-qiang");
map_skill("claw", "suohou-gong");
map_skill("hand", "chansi-shou");

	prepare_skill("hand",  "chansi-shou");
prepare_skill("claw",  "suohou-gong");

       set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "club.gong" :),
                (: perform_action, "club.qldj" :),
                (: perform_action, "club.zhtx" :),
                (: command("unwield yuejia qiang") :),
                (: command("wield yuejia qiang") :),
                (: perform_action, "claw.suo" :),
                (: perform_action, "hand.qin" :),                
                (: perform_action, "hand.qinna" :),                
                (: perform_action, "dodge.gjtq" :),                                
                (: perform_action, "dodge.canghaiyixiao" :),                                
                (: perform_action, "dodge.maishou" :),                                
        }) );
    set_temp("apply/armor",8500);
    set_temp("apply/damage",8500);
    set_temp("apply/dodge",200);
    set_temp("apply/attack",500);
    set_temp("apply/defense",200);
    setup();
    carry_object(__DIR__"obj/kuijia")->wear();
        carry_object(__DIR__"obj/silverhat")->wear();
        carry_object(__DIR__"obj/spear")->wield();
} 
void init(){
        ::init();
        add_action("do_hi", "hi");
        add_action("do_accept", "accept");
        add_action("do_confirm", "confirm");
} 
int do_accept(string arg){
        object me;
        me = this_player();
        if(!me->query_temp("marks/yue_ask")) {
                return 0;
                
        }
        if(arg == "yes") {
                remove_call_out("dream_return");
                message_vision(HIC"\n$N道：“学了我的枪法，从此就是冲杀在千军万马中，永不能享受衙门中的安逸了。\n"NOR,
                                this_object());
                message_vision(HIC"你真的愿意？”（ｃｏｎｆｉｒｍ　ｙｅｓ／ｎｏ）\n"NOR, this_object());
                me->delete_temp("marks/yue_ask");
                me->set_temp("marks/yue_confirm", 1);
                call_out("dream_return", 45);
        } else if(arg == "no"){
                remove_call_out("dream_return");
                dream_return(me);
        }
        return 1;
} 
int do_confirm(string arg){
        object me;
        me = this_player();
        
        if(!me->query_temp("marks/yue_confirm")){
                return 0;
        }
        if(arg == "yes"){
                remove_call_out("dream_return");
                message_vision("$N对$n说到：“好！国家正需要你这种栋梁！”\n", this_object(), me);
                message_vision("\n话音才落，$N突然沉声到：“那你还不快回去！”右手软闪电般击向$n天灵。\n", this_object(), me);
                tell_object(me, WHT"\n你之觉得一股刚阳的大力压得你透不过气来，眼前景色变得朦胧一片。\n"NOR);
                me->set("marks/官府/岳飞", 1);  
                dream_return(me);
        } else {
                remove_call_out("dream_return");
                dream_return(me);
        }
        return 1;
} 
int do_hi(string arg){
        object me;
        me = this_player();
        if(!arg) {
                return 0;
        } 
        if(arg == "yue fei" && me->query("marks/dreaming_yue")) {
                if(me->query_temp("marks/got_yue_attention")){
                        message_vision("$N双手抱拳，对岳飞作了个揖道：这位英雄请了！\n", me);
                        message_vision("\n$N长叹一声， ：”天意。。。 天意也！”\n", this_object());
                        message_vision("\n$N定了定神， 对$n一鞠：“这位"+ RANK_D->query_respect(me) + "请了， 恕鹏举失态。其实人生自古谁\n",
                                        this_object(), me);
                        message_vision("无死，唯有留取丹心照汗青而已。“ \n", this_object());
                        message_vision("\n$N用炯炯有神的双目看着$n，一字一顿的说到：”既然天意如此，岳某也无所\n",
                                        this_object(), me); 
                        message_vision("悔憾。只是这一身保家卫国的本领，未免可惜了。岳某愿倾囊而授，不知这位\n", 
                                        this_object()); 
                        message_vision(RANK_D->query_respect(me) +"可愿接受？（ａｃｃｅｐｔ　ｙｅｓ／ｎｏ）\n", this_object());
                        me->set_temp("marks/yue_ask", 1);
                   me->delete_temp("marks/got_yue_attention");
                        call_out("dream_return", 30, me);
                } else if(me->query("marks/dreaming_yue")){
                        message_vision("$N双手抱拳，对岳飞作了个揖道：这位英雄请了！\n", me);
                        message_vision("\n$N面色凝重的注视着远方好象完全没有注意到$n的存在。\n", this_object(), me);
                        me->set_temp("marks/hi_yue", 1);
                        remove_call_out("responed");
                        call_out("responed", 10, me);
                } else {
                        return 0;
                }
        } else {
                return 0;
        }
        return 1;
} 
void dream_return(object me){
        object room;
        if(environment(me) != environment(this_object()) || !interactive(me)){
                return 0;
        }
        if(!me->query("marks/官府/岳飞")) {
                message_vision("$N摇了摇头：”也罢。。。。“ \n", this_object());
                if(me->query("m_success/岳飞梦")){
                        me->add("score", 500);
                        me->add("combat_exp", 20000);
                        me->add("potential", 10000);
                }
        } else {
                tell_object(me, HIR"\n恍惚中你仿佛听到岳飞说到：“切记精忠报国四字。。。”\n"NOR);
        }
        set("in_action", 0);
        me->delete_temp("marks/yue_ask");
        me->delete("marks/大名湖畔纵横天下");
        me->delete("marks/操练岳家中平枪法");
        me->delete("marks/dreaming_yue");
        tell_object(me, HIY"\n你心中蓦然一惊，抬头看发现自己还是身在书库，原来那只不过是南柯一梦。\n\n"NOR);
        room = find_object("/d/jinan/shufang2");
        if(!objectp(room)){
                room = load_object("/d/jinan/shufang2");
   }
        me->move(room);
        me->set("startroom","/d/tieflag/fy/fqkhotel");
        if(!me->query("imbue/yuefei") ){
                me->start_busy(3);
                call_out("imbue_event", 2, me, room);
        }
} 
void responed(object me){
        if(environment(me) != environment(this_object()) || !interactive(me)){
                return 0;
        }
        message_vision(WHT"突然西北方的远处升起了一股狼烟！\n"NOR, me);
        message_vision("\n$N大叫一声“好极了！”仰天长笑, 欣喜的说到：“我们的主力攻克伊阳了！”\n", 
                        this_object());
        message_vision("\n$N这时回头注意到$n, “咦”了一声：这位" + RANK_D->query_respect(me)+"你是。。。。“\n", 
                        this_object(), me);      
        message_vision(YEL"\n$N下打量了$n一番，稍一沉吟，突然面起惊异之色，不禁后退了两步。\n"NOR, 
                        this_object(), me); 
        message_vision(YEL"$N摇了摇头，面色沧凉地说到：”怎么会这样， 怎么会这样。。。。“\n"NOR, 
                        this_object()); 
        me->set_temp("marks/got_yue_attention", 1); 
} 
int imbue_event(object me, object room){
        object weapon, ob, *inv, obj;
        string prop;
        int i; 
        if(!interactive(me) || environment(me) != room) {
                return 0;
        } 
        obj = me->query_temp("weapon");
       
                message_vision(HIR"\n一丝红缨飘缓缓的从空中飘落在$N的" + weapon->name() + HIR"上。。。\n"NOR,
                                me);
                message_vision(HIR"红丝隐去，一缕红光乍现在$N的" + weapon->name() + HIR"上，转眼又消失不见。\n"NOR, me);
                tell_object(me, "\n你不由得怀疑刚才的一切到底是梦是幻。。。\n");

                return 1;
        me->set("imbue/yuefei", 2);
        me->save();
        return 1;
}  
