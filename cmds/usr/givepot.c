// nick.c
// by jackyboy @ cctx 98/12/12
#include <ansi.h>

inherit F_CLEAN_UP;
string replace_color(string,int);
int help(object);
int wiz_set(string,string,string,int);

int main(object me, string arg)
{
	string dest;
	int pot;
	object obj;
	if( !arg ) return help(me);	

	if(sscanf(arg,"%d %s",pot,dest)!=2)
         return help(me);	

    if (1==1)
return notify_fail("此命令已经停用！\n");
	
	//return notify_fail("这里没有"+pot+"玩家"+dest+"。\n");
	
 if(!objectp(obj = present(dest, environment(me))))
        return notify_fail("这里没有玩家"+dest+"。\n");
 
 if (!userp(obj))	return notify_fail("这里没有这个玩家。\n");
 if (!userp(me))	return notify_fail("这里没有这个玩家。\n");

if (pot<30)	return notify_fail("至少需要30点潜能！\n");

//    if ( me->query("zhuanshen"))
//return notify_fail("转生后不允许转换！\n");



	//if (me->query("jing")*10 < pot )	return notify_fail("你的精神状态不足以转化这么多潜能！\n");

    if( ((int)me->query("potential")-(int)me->query("learned_points")) >= pot ){
		//me->add("jing",-pot/10);
		me->add("potential",-pot);
		obj->add("potential",pot/10);
       	write("OK!\n");
	} else 	return notify_fail("你没有这么多潜能来转移！\n");
	
	
	message_vision("$N送了"+pot/10+"点潜能给$n 。\n", me,obj);
	write("转换成功.\n");
	return 1;
}




int help(object me)
{
	write(@HELP
指令格式 :givepot <潜能点> <玩家ID>

      把潜能送给别人。10点潜能转换1点送人
see also : hp
HELP
	);
	return 1;
}
