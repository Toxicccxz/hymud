#include <ansi.h>
string *typew=({
"sword",
"blade",
"hammer",
"whip",
"club",
"staff",
"throwing",
"dagger",
"axe",
});
string *typea=({
"hands",
"cloth",
"armor",
"boots",
"head",
"neck",
"surcoat",
"shield",
"waist",
"wrists",
});

int give_jl(object me)
{
object env,envt,ob,corpse,obj;
mapping exit;
int maxpot,i2;
     object who;
      object *team;
	  int i=0,count=0,minexp,maxexp,a,exp,pot,neili;
int ckiller,rn;
      string where;
string file;
string *roomlines;
string location;
int mi,yi,yai,lv,lb,money;
    string *ob_list = ({
                "/clone/family/jinkuai",
                "/clone/family/jintiao",
                "/clone/family/xiaoyuanbao",
                "/clone/family/dayuanbao",
                "/clone/family/jinding",
        });
who =me;
seteuid(geteuid(this_object()));
if (!me) return 1;

        if(me->query("gender")=="男性")
    tell_object(me,"你迫不及待在敌人尸体寻找了一下，良久：\n");
        else
    tell_object(me,"你小心翼翼在敌人尸体寻找了一下，良久：\n");

if (!environment(me))
      {
tell_object(me,"你找了半天什么都没有找到！\n");
if (!me->is_busy()) me->start_busy(3);
return 1;
      }	 
env=environment(me);
    if(environment(me)->query("short")!=BLU"山洞"NOR
       && environment(me)->query("short")!=WHT"钟乳石洞"NOR
       && environment(me)->query("short")!=YEL"岩洞"NOR
       && environment(me)->query("short")!=RED"熔岩洞"NOR
       && environment(me)->query("short")!=CYN"石洞"NOR
       && environment(me)->query("short")!=RED"眠龙洞尽头"NOR
       && !environment(me)->query("magicroom")
       && !environment(me)->query("maze")  )
      {
tell_object(me,"你找了半天什么都没有找到！\n");
if (!me->is_busy()) me->start_busy(3);
return 1;
      }	 

if (random(3)==0)
{
if (random(20)==0)
{
ob = new(ob_list[random(sizeof(ob_list))]);
         ob->move(env);
        tell_object(who, HIM "你找到了一" + ob->query("unit") + ob->name() +
                        HIM "。\n" NOR);
return 1;
}

ob = new("/clone/money/silver");
if (random(3)==0) ob = new("/clone/money/gold");
if (random(3)==1) ob = new("/clone/money/coin");
        money=8+random(18);
        tell_object(who, HIY "你找到了" + money +
                        ob->query("base_unit") + ob->name() +
                        HIY "。\n" NOR);

        ob->set_amount(money);
        ob->move(env);
        return 1;
}

//1/12得到药材
if (random(18)==1)
	{
file = read_file("/clone/medicine/ycgift");
roomlines = explode(file,"\n");	
location = roomlines[random(sizeof(roomlines))];
           ob = new(location);
if (ob)
{
           ob->move(env);
        tell_object(who, HIM "你找到了一" + ob->query("unit") + ob->name() +
                        HIM "。\n" NOR);
}
return 1;
}


//1/60得到戒指
if (random(70) == 1 && !env->query("alrd"))
{
	i2=10;
if (random(3)==0) i2=20;
if (random(6)==0) i2=30;
if (random(9)==0) i2=40;
if (random(18)==0) i2=50;
if (random(32)==0) i2=60;	
             corpse=new("/clone/gem/ring"+random(i2));
             message_vision("$N得到一颗亮晶晶的戒指。\n",me);
message("channel:chat", HIM"【江湖谣言】听说"+me->name() + "找到了一枚"+corpse->query("name")+HIM"!"NOR"。\n", users());
             corpse->move(env);
environment(this_object())->set("alrd",1);
        
return 1;
}


//1/30得到特殊装备
if (random(35)==0  && !env->query("alrd"))
{
	file = read_file("/clone/medicine/wgift");
roomlines = explode(file,"\n");	
location = roomlines[random(sizeof(roomlines))];
           ob = new(location);
if (ob)
{
           ob->move(env);
        tell_object(who, HIM "你找到了一" + ob->query("unit") + ob->name() +
                        HIM "。\n" NOR);
message("channel:chat", HIM"【江湖谣言】听说"+me->name() + "找到了"+ob->query("name")+HIM"!"NOR"。\n", users());

}
    
return 1;
}

//特殊装备得到
//1/60机会
yai=random(100);
 if ((int)who->query("combat_exp",1) > 12000000 && random(2))
{
yai=yai+random(381);
}
else 
 if ((int)who->query("combat_exp",1) > 8500000 && random(2))
{
yai=yai+random(300);
}
else 
 if ((int)who->query("combat_exp",1) > 6500000 && random(2))
{
yai=yai+random(200);
}
else
 if ((int)who->query("combat_exp",1) > 5500000 && random(2))
{
yai=yai+random(100);
}
else if ((int)who->query("combat_exp",1) > 3500000 && random(2))
{
yai=yai+random(50);
}


if (yai>480) yai=479;
if (yai> 400 && random(3)==1) yai=random(400);
if (yai> 300 && random(3)==2) yai=random(300);
if (yai> 200 && random(3)==3) yai=random(200);
if (random(70)==1 )
{
ob = new("/p/item/ritemw/W"+typew[random(9)]+yai);
                ob->set("no_drop",0);
                ob->set("no_get",0);
           ob->move(env);
message("channel:chat", HIM"【江湖谣言】听说"+me->name() + "找到了"+ob->query("name")+HIM"!"NOR"。\n", users());

        tell_object(who, HIM "你找到了一" + ob->query("unit") + ob->name() +
                        HIM "。\n" NOR);
return 1;
}
else if (random(70)==2 )
{
ob = new("/p/item/ritema/A"+typea[random(10)]+yai);
                ob->set("no_drop",0);
                ob->set("no_get",0);
           ob->move(env);
message("channel:chat", HIM"【江湖谣言】听说"+me->name() + "找到了"+ob->query("name")+HIM"!"NOR"。\n", users());

        tell_object(who, HIM "你找到了一" + ob->query("unit") + ob->name() +
                        HIM "。\n" NOR);
     
return 1;
}


//基本装备
if (1==1)
	{
file = read_file("/clone/medicine/yb");
roomlines = explode(file,"\n");	
location = roomlines[random(sizeof(roomlines))];
           ob = new(location);
if (ob)
{
           ob->move(env);
        tell_object(who, HIM "你找到了一" + ob->query("unit") + ob->name() +
                        HIM "。\n" NOR);
}
return 1;
}


}
   