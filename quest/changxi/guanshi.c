//侠客行100海洋版II（云起云落）
// guanshi.c 襄阳戏院管事
//星星lywin 2000/6/21 

#include <ansi.h>
#include <command.h>
inherit NPC;
void consider();
int do_gongzuo();
int ask_done();
int ask_done2();
#include "/quest/givegift.c"
mapping *changxi = ({ 
         ([ "changxi":"扬州","where":"city"   ]),
         ([ "changxi":"北京","where":"beijing"  ]),
         ([ "changxi":"成都","where":"chengdu"]),   
         ([ "changxi":"大理","where":"dali"   ]),   
         ([ "changxi":"佛山","where":"foshan" ]),   
         ([ "changxi":"泉州","where":"quanzhou"]),   
         ([ "changxi":"杭州","where":"hangzhou"]),   
         ([ "changxi":"灵州","where":"lingzhou"]),   
         ([ "changxi":"苏州","where":"suzhou"]),   
                   });

mapping *changxi2 = ({ 
         ([ "changxi":"扬州","where":"city"   ]),
         ([ "changxi":"北京","where":"beijing"  ]),
         ([ "changxi":"成都","where":"chengdu"]),   
         ([ "changxi":"大理","where":"dali"   ]),   
         ([ "changxi":"佛山","where":"foshan" ]),   
         ([ "changxi":"泉州","where":"quanzhou"]),   
         ([ "changxi":"杭州","where":"hangzhou"]),   
         ([ "changxi":"灵州","where":"lingzhou"]),   
         ([ "changxi":"苏州","where":"suzhou"]),   
         ([ "changxi":"中州","where":"zhongzhou"]),   
         ([ "changxi":"长沙","where":"changsha"]),   
         ([ "changxi":"南昌","where":"nanchang"]),   
         ([ "changxi":"贵州","where":"guizhou"]),   
         ([ "changxi":"济南","where":"jinan"]),   
         ([ "changxi":"碎叶","where":"suiye"]),            	         	         	         	         	
         ([ "changxi":"巴陵","where":"baling"]),   
         ([ "changxi":"合肥","where":"hefei"]),   
         ([ "changxi":"安南","where":"annan"]),   
         ([ "changxi":"金陵城","where":"jinling"]),   
         ([ "changxi":"岳阳","where":"yueyang"]),            	         	         	         	         	
         ([ "changxi":"延平","where":"yanping"]),   
         ([ "changxi":"高丽","where":"gaoli"]),   
         ([ "changxi":"九江","where":"jiujiang"]),   
         ([ "changxi":"新疆","where":"xinjiang"]),   
         ([ "changxi":"西藏","where":"xizang"]),   
         ([ "changxi":"定襄","where":"dingxiang"]),            	         	         	         	         	
                   });



 
 

 
 
 
mapping query_changxi2()
{
        return changxi2[random(sizeof(changxi2))];
}

mapping query_changxi()
{
        return changxi[random(sizeof(changxi))];
}

void create()
{
        set_name("管事", ({"guan shi", "guan"}));
        set("gender", "男性");
        set("age", 25);
        set("long", 
                "他是襄阳戏院的管事。\n");
        set("qi", 100);
        set("max_qi", 100);
        set("jing", 100);
        set("max_jing", 100);
        set("per", 25);
        
        set("combat_exp", 1500);
        set("score", 200);
        
        set("inquiry", ([
                "工作" : (: do_gongzuo :),
                "job"  : (: do_gongzuo :),
                "work" : (: do_gongzuo :),
                "over" : (: ask_done    :),
                "完成" : (: ask_done    :),
                "报酬" : (: ask_done    :),
                "fail" : (: ask_done2    :),
                "取消" : (: ask_done2   :),

        ]) );

        setup();
        carry_object("clone/cloth/cloth")->wear();
}
int do_gongzuo()
{      
        mapping changxi,changxiwhere;
        object me,ob;
        me = this_player(); 
        
    if( me->query_temp("obj/changxi")>0)
    {
                tell_object(me,"快去表演吧。\n");
                return 1;
    } 
    else 
    if( me->query("combat_exp")>1000000 && me->query("nbjob")!=29)
    {
                tell_object(me,"你已经很利害了，这种工作不合适你做了。\n");
                return 1;
    }


    if( me->query_condition("menpai_busy"))
    {
                tell_object(me,"你才来要过任务，休息一下吧。\n");
                return 1;
    }


    changxi = this_object()->query_changxi();
    changxiwhere = changxi["where"];

    if( me->query("combat_exp")>300000)
    {
    changxi = this_object()->query_changxi2();
    changxiwhere = changxi["where"];

    }
    message_vision(CYN"管事对$N说道：你去" + changxi["changxi"] + "的大街上表演一下吧。\n"NOR,me); 
        me->set_temp("obj/changxi", 1);
        me->set_temp("obj/where",changxiwhere);
        ob=new(__DIR__ "daoju");
        ob->move(me);
        return 1;   
}

int ask_done()
{      
int exp;
        object me,ob;
        me = this_player(); 
        
    if( me->query_temp("obj/changxi")< 1)
    {
                tell_object(me,"你曾来我这儿要过任务？。\n");
                return 1;
    } 
    if( me->query_temp("obj/done")< 1)
    {
                tell_object(me,"还没表演你就以为自己完成了？快去表演吧。\n");
                return 1;
    }
    message_vision(CYN"管事对$N说道：做得不错！给你些奖励吧。\n"NOR,me); 
    exp=60+random(30);
    if( me->query("combat_exp",1)>1000000) exp=10;
    me->add_temp("nbjob28",1);
    me->delete_temp("obj");
    ob=new("/clone/money/silver");
    ob->set_amount(5+random(10));
    ob->move(me);
exp=exp;
addnl(me,"exp",exp);
me->apply_condition("menpai_busy",3);
    if (ob = present("changxi daoju", this_player()))
    {
       message_vision("管事把唱戏道具收了回去！\n",me);
       destruct(ob);
       return 1;
    }
    return 1;
}



int ask_done2()
{      
int exp;
        object me,ob;
        me = this_player(); 
        
    if( me->query_temp("obj/changxi")< 1)
    {
                tell_object(me,"你曾来我这儿要过任务？。\n");
                return 1;
    } 
    me->start_busy(3);
    me->apply_condition("menpai_busy",3);

        me->set_temp("obj/changxi", 0);
        me->set_temp("obj/where",0);
        me->delete_temp("obj/changxi");
        me->delete_temp("obj/where");

 
    if (ob = present("changxi daoju", this_player()))
    {
       message_vision("管事把唱戏道具收了回去！\n",me);
       destruct(ob);
       return 1;
    }
    return 1;
}
