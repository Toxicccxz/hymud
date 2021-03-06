#include <ansi.h>
inherit NPC;  
void create()
{
        set_name("杨铮", ({ "yang zheng","yang","zheng" }) );
        set("long",
                "一个瘦削、黝黑、沉静，还不到三十岁的汉子。\n"); 
        set("attitude", "friendly");
        set("age",32);
        set("str", 80);
        set("cor",70);
        set("agi",50); 
        set("con",70);
        set("title", HIW"捕头"NOR); 
        set("combat_exp", 4000000+random(1000000));
        set("max_neili",3000);
        set("force",3000);
         
    set_skill("leg", 380);             // 基本内功
    set_skill("force", 280);             // 基本内功
    set_skill("bibo-shengong", 380);     // 碧波神功
    set_skill("claw", 200);              // 基本爪法
    set_skill("hand", 320);              // 基本手法
    set_skill("finger", 320);            // 基本指法
    set_skill("tanzhi-shentong", 380);   // 弹指神通
    set_skill("unarmed", 280);           // 基本拳脚
    set_skill("strike", 280);            // 基本拳脚
    set_skill("luoying-zhang", 380);     // 落英神剑掌
    set_skill("xuanfeng-leg", 380);      // 旋风扫叶腿
    set_skill("dodge", 280);             // 基本躲闪
    set_skill("anying-fuxiang", 380);    // 暗影浮香
    set_skill("parry", 200);             // 基本招架
    set_skill("sword", 320);             // 基本剑法
    set_skill("luoying-shenjian", 380);  // 落英神剑
    set_skill("yuxiao-jian", 380);       // 玉箫剑法
    set_skill("lanhua-shou", 380);       // 兰花拂穴手
    set_skill("qimen-wuxing",380);       // 奇门五行
    set_skill("count",380);              // 阴阳八卦
    set_skill("literate",380);           // 读书识字
	  set_skill("chixin-jian", 380);             // 基本内功
    set_skill("canglang-bian", 380);             // 基本内功
    set_skill("whip", 380);             // 基本内功
    map_skill("strike"  , "luoying-zhang");
    map_skill("force"  , "bibo-shengong");
    map_skill("finger" , "tanzhi-shentong");
    map_skill("whip"   , "canglang-bian");
    map_skill("hand"   , "lanhua-shou");
    map_skill("unarmed", "xuanfeng-leg");
    map_skill("leg" , "xuanfeng-leg");
    map_skill("dodge"  , "anying-fuxiang");
    map_skill("sword"  , "chixin-jian");
    map_skill("parry"  , "luoying-zhang");    	

if (random(3)==0)
{
    	prepare_skill("strike", "luoying-zhang");
	prepare_skill("leg", "xuanfeng-leg");
}
else
{
	prepare_skill("finger", "tanzhi-shentong");
	prepare_skill("hand", "lanhua-shou");	
}
        set("chat_chance_combat", 99);
        set("chat_msg_combat", ({
                (: exert_function, "play" :),
                (: exert_function, "qimenzhen" :),
                (: exert_function, "roar" :),
                (: perform_action, "dodge.taohaimangmang" :),
                (: perform_action, "hand.fuxue" :),
                (: perform_action, "strike.shenjian" :),                
                (: perform_action, "strike.xuan" :),                
                (: perform_action, "strike.pikong" :),                
                (: perform_action, "leg.wuying" :),                
                (: perform_action, "leg.kuangfeng" :),                
                (: perform_action, "finger.huayu" :),                
                (: perform_action, "finger.jinglei" :),                
                (: perform_action, "finger.lingxi" :),                
		(: command("unwield yuxiao") :),
		(: command("wield yuxiao") :),
		(: command("unwield bian") :),
(: command("wield bian") :),
(: perform_action, "finger.ding" :), 
	(: perform_action, "finger.zhuan" :), 
(: perform_action, "sword.muyu" :),                
	(: perform_action, "sword.nosword" :),                
		(: perform_action, "sword.trhy" :),                
		(: perform_action, "whip.duoming" :),                
		(: perform_action, "whip.lang" :),                
		(: perform_action, "whip.tlyj" :),                
		(: perform_action, "whip.yljx" :),                									
 
        }));
        set("chat_chance", 1);
        set("chat_msg", ({
"杨铮紧握双拳，愤怒的眼睛中似乎喷得出火来。”\n"
}) );
/*
        set("inquiry", ([
                "劫镖案" : (: answer_robery :),
                "robery" : (: answer_robery :),
                "杨铮" : (: answer_yang :),
                "yang" : (: answer_yang :),
                "yang zheng" : (: answer_yang :),
                "狄青麟" : (: answer_di :),
                "di" : (: answer_di :),
                "di qinglin" : (: answer_di :),
        ])); 
*/
        setup(); 
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/gangjian")->wield();
}   
int accept_object(object who, object ob)
{
        object hook,sword,me,room;
        
        me=this_object();
        room=environment();
        if(ob->query("name")!=MAG"离别钩"NOR) return 0;
        if(!present("di qinglin",room)) return 0;
//      if(who->query_busy()) return 0;
//      if(me->query_busy()) return 0;
        
        set_temp("送离别钩的人",who);
        hook=new("/d/tieflag/obj/leavehook");
        hook->move(me);
        if(sword=present("sword",me))
        if(sword->query("equipped"))
                command("unwield sword");
        command("wield leave hook");
        return 1;
}
          
void heart_beat()
{
        object di,yang,room,hook,ying,who;
        int rival,msg;
        
        ::heart_beat();
        yang=this_object();
        room=environment();
        di=present("di qinglin",room);
        ying=present("ying wuwu",room);
        
        if(query("killed_di"))
        {
           who=ying->query("busy_object");
                call_out("leave_room",3,ying,who);
                delete("killed_di");
        }
        if(msg=query("leaving_msg"))
        {
        if(msg==3)
                message_vision(HIG"$N默默擦去离别钩上的血迹，疲惫不堪的嘴角突然露出了一丝微笑。\n"NOR,yang);
        if(msg==2)
                message_vision(HIG"$N喃喃自语道：“素文，案子结了，我终于可以回家了。”\n"NOR,yang);
        if(msg==1)
                {
                message_vision(HIG"斜阳似血，$N拖着疲惫的身影默默地离开麒麟阁。\n\n"NOR,yang);                  
                destruct(yang);
                }
        add("leaving_msg",-1);
        }
        if(rival=query("begin_rival"))
        {
                if(rival==4)
                {
                        command("say 莲姑是你杀的？");
                        di->set("begin_rival",4);
                }
                else
                {
                        if(rival==3)
                                command("say 失劫的镖银也在你这里？");
                        if(rival==2)
                                command("hmm");
                        if(rival==1)
                                command("say 我就知道你一定会这样做的，因为你太骄傲，太不把别人放在眼里。");
                        di->add("begin_rival",-1);
                } 
        } 
        
        
        if (!query_temp("perform_libie"))
        if (objectp(di))
        if (yang->is_fighting(di))
   if (yang->query_busy())
        if (hook=present("leave hook",yang))
        if (hook->query("equipped"))
        {
                set_temp("perform_libie",1);
                yang->start_call_out( (: call_other, __FILE__, "perform_libie" ,yang,di:), 2);
        }
}
        
void perform_libie(object yang, object di)
{
        message_vision(HIB"\n$N倏地欺近身来，身行猛然凝岳不动。\n\n离别钩交至右手，划向自己左臂。\n"HIR
"\n血光起，\n\n"HIB"$N左臂断落\n\n离别钩又斜斜飞起，直至$n咽喉。\n\n$n大惊之下，早已躲避不及。\n
"HIR"血光又起\n\n"HIB"$n直挺挺的倒落。。。\n"NOR,yang,di);
        yang->start_busy(1);
        di->die();
        delete_temp("perform_libie");
        return;
} 
int do_rival(object di)
{
        if(!objectp(di)) return 0;
        set("begin_rival",4);
        return 1;
} 
void die()
{
        int i;
        object di,ying,room,corpse,*inv;
        object me;
        
        me=this_player();
        room=environment();
        di=present("di qinglin",room);
        di->set("yang_die",1);
        corpse=new("/d/libie/obj/yangcorpse1");
        corpse->move(room);
        inv=all_inventory(this_object());
        i=sizeof(inv);
        while(i--)
                inv[i]->move(corpse);
        
   message("vision",HIR"\n杨铮双目圆睁，不甘心的倒了下去。。。\n"NOR,room);
   message("vision",HIR"在倒下的最后一刻，杨铮用尽最后的一丝力量帮$N解开穴道。\n"NOR,me);
        destruct(this_object());
} 
void leave_room(object ying,object who)
{       
        object yang,room;
        
        room=environment();
        yang=this_object();
        message_vision(HIW"$N给$n解开穴道。\n\n"NOR,yang,who);
        who->start_busy(1);
        if (who->query("libie/离别钩_杀死狄青麟")!=1 
                && who->query("libie/离别钩_杀死狄青麟")!=2) {
                who->add("score",500);
                who->add("potential",500);
                who->add("combat_exp",20000);
                }
        who->set("libie/离别钩_杀死狄青麟",2);
        set("leaving_msg",3);
}   
