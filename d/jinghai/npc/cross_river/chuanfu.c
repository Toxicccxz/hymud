// Cross_river: chuanfu.c
// by Find.

inherit NPC;

protected object boat;
protected int max_passenger = 6;
protected string cross_msg = "过河";

// 接口函数
protected void set_max_passenger(int n)
{
	if(n > 0)
		max_passenger = n;
}

protected void set_cross_msg(string msg)
{
	if(!stringp(msg) || !strlen(msg))
		return;

	cross_msg = msg;
}
// 结束

void set_boat(object ob)
{
	if(!ob)
		return;

	boat = ob;
}

protected varargs int have_person(object where)
{
	object env;

	if(!where)
	{
		if(!env = environment())
		{
			call_out("do_leave",1);
			return 0;
		}
	}
	else
		env = where;

	return sizeof(filter_array(all_inventory(env), (: userp :)));
}

void shou_qian(int count)
{
	int n;

	remove_call_out("shou_qian");

	if(!boat)
	{
		call_out("do_leave",1);
		return;
	}

	if(count >= 4)
	{
		call_out("kai_chuan",1);
		return;
	}

	if( !have_person() && (count > 2) )
	{
		call_out("kai_chuan",1);
		return;
	}

	n = sizeof(filter_array(all_inventory(boat),(: userp :) ));
	if(n >= max_passenger)
	{
		call_out("kai_chuan",1);
		return;
	}

	if(count)
		say(sprintf("%s说道：“要%s的请赶紧上船。”\n", name(), cross_msg));
	call_out("shou_qian",6,++count);
}

void kai_chuan()
{
	object *inv, env = environment();
	int n;

	if(!env)
	{
		call_out("do_leave",1);
		return;
	}

	if(!boat)
	{
		call_out("do_leave",1);
		return;
	}

	if( n = sizeof(inv = all_inventory(boat)) )
	{
		for(int i=0;i<n;i++)
		{
			object ride;
	
			if(inv[i] && userp(inv[i]) && !inv[i]->query_temp("payed_duchuan"))
			{
				message_vision(name()+"走上来对$N说道：“已经到啦，您快下船吧”，说着把$N推了下去。\n",inv[i]);
				if(ride = inv[i]->query_temp("on_rided"))
					ride->move(env);
				inv[i]->move(env);
				tell_room(env,sprintf("把%s从船上推了下来。\n",name(), inv[i]->name()),({inv[i]}));
			}
		}
	}

	tell_room(env,sprintf("%s走上船收起踏板。\n",name()));

	this_object()->move(boat);
	env->delete("exits/enter");
	boat->delete("exits/out");

	message_vision("$N走上来收起踏板。\n$N喊道：“开船喽！大家坐好！”\n", this_object());

	boat->leave_bank();
}

// 此函数可被重载来灵活设定各种条件
int accept_object(object me,object obj)
{
	if(!boat)
	{
		call_out("do_leave",1);
		return 0;
	}

	if(me->query_temp("payed_duchuan"))
		return notify_fail(sprintf("%s说道：您老已经赏了船钱了，不用再破费。\n", name()));

	if(!obj->query("money_id"))
		return 0;

	if(obj->value() < 100)
		return notify_fail(sprintf("%s说道：“每位一两银子，小本生意，概不赊欠。”\n", name()));

	if(sizeof(filter_array(all_inventory(boat),(: userp :) )) >= max_passenger)
		return notify_fail(sprintf("%s说道：%s上人已经满啦，您老等下一趟吧。\n",
			name(), boat->query("short")));

	me->set_temp("payed_duchuan",1);

	tell_object(me, sprintf("%s说道：谢赏，您老快上去吧，就要开船啦。\n", name()));

	return 1;
}

// 意外函数
void unconcious()
{
	call_out("do_die",2);
	return ::unconcious();
}

void do_die()
{
	::die();
}

void do_leave()
{
	destruct(this_object());
}
// END 意外函数
