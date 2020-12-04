// invocation.c

#include <ansi.h>
inherit F_SSERVER;

string get_name(string str)
{
        str="天兵护法";
        return str;
}


int exert(object me)
{
        int invocation_time;
        object soldier;
object target;
int skill;    


        if( !me->is_fighting() )
                return notify_fail("只有战斗中才能召唤天将！\n");
        
        invocation_time=60+(200-(int)me->query_skill("taoism"));
        if(invocation_time<30) invocation_time=30;
        	
        	
        if((time()-me->query_temp("last_invocation"))<invocation_time)
            return notify_fail("你刚叫过天将，他们都被你叫烦了！\n");

        if((int)me->query_skill("taoism",1) < 100)
                return notify_fail("你的基本道术还不能自由运用！\n");

        if( (int)me->query("neili") < 550 )
                return notify_fail("你的法力不够了！\n");

        if( (int)me->query("jing") < 280 )
                return notify_fail("你的精神无法集中！\n");

if (!userp(me) && me->query_temp("nozh"))
	return notify_fail("分身无法再分身！\n");
if (!userp(me) &&  me->query_temp("zhrs",1)>30)
return notify_fail("超出一次战斗上限。\n");
        message_vision(HIY"$N撒下一把金豆,喃喃地念了几句咒语。天兵天将急急行如律!! \n"NOR, me);

        me->add("neili", -150);
        me->receive_damage("neili", 80);
   

        skill=(int)me->query_skill("panshi-shengong",1);
        skill=skill*0.7;
        soldier = new("/d/biwu/hs");
        soldier->move(environment(me));
        soldier->set_temp("invoker",me);
        soldier->set("possessed", me);
	      soldier->set_name(HIY+this_player()->query("name")+"的护法天将"NOR,({"tianjiang"}));
        soldier->invocation(me);
        soldier->initlvl(skill,18);
        soldier->set_temp("nozh",1);
if (!userp(me)) me->add_temp("zhrs",1);

 message_vision(HIY"$N "+HIY"喝道：尊法旨 斩妖除魔！! \n"NOR, soldier,me);

        me->set_temp("last_invocation",time());
        me->start_busy(2+random(2));

        return 3+random(5);
}


