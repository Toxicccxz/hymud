#include <ansi.h>
inherit ITEM;
#include "/quest/menpai/givegift.c"
void create()
{
        set_name(HIR"�����ܼ�"NOR, ({ "mi jian"}));
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
                        "һ������ܼ�,�����Ÿ��������������ð���������(xiaohui)��\n");
                set("value", 0);
                set("material", "paper");
		 
         }
}
void init()
{    
	add_action("do_xiaohui", "xiaohui");
}

int do_xiaohui(string arg)
{
	string msg;
 object ob;
int exp,pot,base_exp,a;
	int i;
	object fang,who,where;
        int count,add_exp;
        object *team,boss,me;
object maxpot,obj;
ob = this_object();
me = this_player();
	who=me;
	where = environment(who);
              
		me=this_player();
        ob=this_object();
		if(!arg||arg!="mi jian") return notify_fail("��Ҫ����ʲô��\n");
        if(ob->query("okname")!= me->query("id")
			||me->query("mjb2job")!="���")
		return notify_fail("����º������û��ϵ��?\n");
		
		if (!present("mi jian",me) )
        return notify_fail("������û���ܼ���\n"); 
        //check ok

        fang = present("sha shou",where);
	if(fang)
	{
		who->start_busy(3);
         return notify_fail("���Ƚ�����е�ǿ�аɣ�\n");
	}

        fang = present("boss killer",where);
	if(fang)
	{
		who->start_busy(3);
 return notify_fail("���Ƚ�����е�ǿ�аɣ�\n");
	}

    if( me->is_busy() )
	return notify_fail("��Ķ�����û����ɡ�\n");
    if( me->is_fighting() )
        return notify_fail("�������������!��\n");



		message_vision("$N�ӻ����ͳ�һֻ���۵�ȼ���ܼ���\n"+HIR"ֻ�����䡹��һ�����ܼ��ڻ���������Ϊ�ҽ� ��\n"NOR, me);
       count=me->query_temp("team_count");
		if (count<2) count=2;	
               
		team=me->query_team();
		count=sizeof(team);
		//write("\n"+sprintf("%d",count));
if (!count)
{
		     exp=random(888)+888;
		     pot=exp*2/3+random(200);

me->clear_condition("mjb2_busy");		
me->clear_condition("mp2_kill");
me->delete("quest");
me->delete("task_time");
me->delete("mjb2job");
me->delete_temp("team_count");	
addnl(me,"exp",exp);
if (random(3)==0) addnl(me,"mpgx",1);
}	

		for(i=0;i<count;i++)
		{ if(team[i]!=0)
		{
			if (team[i]->query_condition("mjb2_busy"))
			{ 
			 add_exp=100;
		     exp=random(888)+888;
		     pot=exp*2/3+random(200);
		     team[i]->delete_temp("team_count");
             if (environment(me)==environment(team[i])) addnl(team[i],"exp",exp);

;
team[i]->clear_condition("mjb2_busy");		
team[i]->clear_condition("mp2_kill");
team[i]->delete("quest");
team[i]->delete("task_time");
team[i]->delete("mjb2job");
team[i]->delete_temp("team_count");
			}
			} 
		}



    me->start_busy(3);
       
		  me->delete_temp("team_count");
         	  
		  destruct(this_object());
          return 1;
}
