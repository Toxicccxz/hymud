// more work needed to use this object to make poison
#include <ansi.h>
inherit ITEM;


void init()
{
        add_action("do_eat2", "mygift");
        add_action("do_eat", "ci");
        add_action("do_eat", "he");
        add_action("do_sleep", "xiuxi");
        add_action("do_xx", "xiuxing");
          add_action ("do_fly","chen");
}

void create()
{
	set_name(YEL"新手背包"NOR, ({"newbie beg", "beg"}));
        set("unit", "只");
	set("long", "包里面看上去有永远吃不完的干粮。可以又吃又喝并休息(he,ci,xiuxi)。");
set("long", YEL"新手专用，包里面看上去有永远吃不完的干粮。
如果你不知道，现在能做什么，请输入mygift 查看，系统会选择一个适合你的任务提示你。
你可以又吃又喝并休息和免费乘车,并可以修行(he,ci,xiuxi,chen,xiuxing)。
*@*可以带你乘(chen)到以下地方：*@*
＊＊ 北京(tam)        大理(dl)            泉州(qz)  ＊＊
＊＊ 少林(shl)        华山(hs)            灵鹫(lj)  ＊＊
＊＊ 武当(wd)         明教(mj)            扬州(gc)  ＊＊
＊＊ 星宿(xx)         雪山(xs)            峨眉(em)  ＊＊
＊＊ 全真(quz)        白驼山(bt)          古墓(gm)  ＊＊
＊＊ 苏州(sz)         归云庄(gyz)         襄阳(xy)  ＊＊
＊＊ 长安(ca)         成都(cd)            兰州(laz) ＊＊
＊＊ 荆州(jz)         盛京(yj)            武馆(wg)  ＊＊
＊＊ 昆明(km)         杭州(hz)            灵州(lz)  ＊＊
＊＊ 大车车站(dache)  扬州马厩(majiu) 扬州当铺(dp)  ＊＊
＊＊ 古村(job1)  磨药(job2)   伐木(job3) 唱戏(job4) ＊＊
＊＊ 打猎(job5)  送货(job6)   巡城(job7) 劫色(job8) ＊＊
＊＊ 迷宫(job9)  挑战(job10)                        ＊＊\n"NOR   
);
	set("no_get",1);
	set("no_drop",1);
		set("no_get", 1);
		set("no_put", 1);
		set("no_drop", 1);
             set("value", 0);
             set("material", "steel");
             set("no_drop", "这样东西不能离开你。\n");
        setup();
}

int do_eat2()
{
int exp;
object me = this_player();


if (me->is_busy())
return notify_fail("你正在忙？\n");
if (me->is_fighting())
return notify_fail("你正在打？\n");

tell_object(me,YEL "现在你的经验是"+chinese_number(me->query("combat_exp",1))+"。\n" NOR);
exp=(int)me->query("combat_exp",1);
if (exp<=80000)
tell_object(me,YEL "现在适合你的任务是新手任务："+HIR"chen job1\n"NOR+HIR"ask lao about job\n"+HIR"相关帮助help nbjob\n"NOR);

if (exp>80000 && exp<=120000)
tell_object(me,YEL "现在适合你的任务是新手任务第二阶段："+HIR"chen job10\n"NOR+HIR"ask bei chou about job\n"+HIR"相关帮助help nbjob\n"NOR);

if (exp>120000 && exp<=180000)
tell_object(me,YEL "现在适合你的任务是磨药任务："+HIR"chen job2\n"NOR+HIR"ask ping about job\n"+HIR"相关帮助help moyao\n"NOR);

if (exp>=180000 && exp<=300000)
tell_object(me,YEL "现在适合你的任务是巡城任务："+HIR"chen job7\n"NOR+HIR"ask wang about job\n"+HIR"相关帮助help xunchen\n"NOR);

if (exp>80000 && exp<=500000)
tell_object(me,YEL "现在适合你的任务是伐木任务："+HIR"chen job3\n"NOR+HIR"ask songque about job\n"+HIR"相关帮助help kanshu\n"NOR);

if (exp>=500000 && exp<=1000000)
tell_object(me,YEL "现在适合你的任务是唱戏任务："+HIR"chen job4\n"NOR+HIR"ask guan about job\n"+HIR"相关帮助help changxi\n"NOR);

if (exp>=180000 && exp<=1500000)
tell_object(me,YEL "现在适合你的任务是打猎任务："+HIR"chen job5\n"NOR+HIR"south 后杀死猎物获得奖励\n"+HIR"相关帮助help dalie\n"NOR);

if (exp>=1500000 && exp<=2500000)
tell_object(me,YEL "现在适合你的任务是采花任务："+HIR"chen job8\n"NOR+HIR"ask tian about job\n"+HIR"相关帮助help tianjob\n"NOR);

if (exp>80000 && exp<=2500000)
tell_object(me,YEL "如果加入了门派，可以做对练任务"+HIR"找到门派的任务吏\n"NOR+HIR"输入job后duilian 本门人员\n"+HIR"相关帮助help geren\n"NOR);

if (exp>1500000)
tell_object(me,YEL "你已经有一定经验了，介绍几个重要的任务给你:\n"+HIR"江湖任务:help taskjobs\n"NOR+HIR"门派任务：help geren \n"+HIR"其他任务help aboutquest\n"NOR);

if (exp>=300000 )
tell_object(me,YEL "现在你可以去迷宫探险了："+HIR"chen job9\n"NOR+"相关帮助help migong\n"NOR);

if (exp>=300000 )
tell_object(me,YEL "现在你可以去挑战洞窟了："+HIR"chen job10\n"+HIR"ask bei chou about challenge\n"NOR+"相关帮助help boss 新手试炼-挑战洞窟\n"NOR);

if (exp>2500000)
tell_object(me,YEL "已经可以自由闯荡江湖了。天高任鸟飞，海阔凭鱼跃。\n"NOR);


me->start_busy(1);
return 1;
}

int do_eat(string arg)
{
object me = this_player();
	if (!id(arg))
                return notify_fail("你要吃什么？\n");
if (!wizardp(me) && me->query("age") > 55)
return notify_fail("只有新手才能吃干粮!\n");
if (!wizardp(me) &&me->query("str") > 40)
return notify_fail("只有新手才能吃干粮!\n");
if (!wizardp(me) &&me->query("dex") > 40)
return notify_fail("只有新手才能吃干粮!\n");

if (me->is_busy())
return notify_fail("你正在忙？\n");
if (me->is_fighting())
return notify_fail("你正在打？\n");
if ((int)me->query("combat_exp") > 6500000 )
return notify_fail("只有新手才能吃干粮!\n");

if (me->query("food")*1.5 > me->max_food_capacity()
&& me->query("water")*1.5 > me->max_water_capacity())
return notify_fail("你现在不饿啦!\n");

message_vision(YEL "$N拿出干粮大吃大喝了一顿!!\n" NOR,me);
me->set("food",me->max_food_capacity());me->set("water",me->max_water_capacity());
if (me->query("qi") < 50 )
	me->add("qi",30);
if (me->query("jing") < 50 )
	me->add("jing",30);


me->start_busy(3);
}
int do_sleep(string arg)
{
object me = this_player();
	if (!id(arg))
                return notify_fail("你要用什么？\n");
if (!wizardp(me) &&me->query("age") > 55)
return notify_fail("只有新手才能用!\n");
if (!wizardp(me) &&me->query("str") > 40)
return notify_fail("只有新手才能用!\n");
if (!wizardp(me) &&me->query("dex") > 40)
return notify_fail("只有新手才能用!\n");

if (me->is_busy())
return notify_fail("你正在忙？\n");
if (me->is_fighting())
return notify_fail("你正在打？\n");
if ((int)me->query("combat_exp") > 6500000 )
return notify_fail("只有新手才能用!\n");

if (me->query("qi") > me->query("max_qi")
&& me->query("jing") > me->query("max_jing")
)
return notify_fail("你现在不累啦!\n");
message_vision(YEL "$N拿出新手背包铺在地上休息一会!!\n" NOR,me);
if (me->query("qi") < me->query("eff_qi"))
me->add("qi",me->query("eff_qi")/2);
if (me->query("jing") < me->query("eff_jing"))
me->add("jing",me->query("eff_jing")/2);


if (me->query("eff_qi") < me->query("max_qi"))
me->add("eff_qi",me->query("max_qi")/2);
if (me->query("eff_jing") < me->query("max_jing"))
me->add("eff_jing",me->query("max_jing")/2);
me->set_temp("isnbbg",1);
me->start_busy(3);
return notify_fail("你休息了一会!\n");
}

  int do_fly(string arg)
{

          string pla;
          object me = this_player();
if( me->query("jing") < 30 )
               return notify_fail("你精神不够旺盛，没力气做车马！\n");
if( me->query_temp("pending/team"))
               return notify_fail("你正和别人组队呢！\n");				

if (!wizardp(me) &&me->query("age") > 55)
return notify_fail("只有新手才能用!\n");
if (!wizardp(me) &&me->query("str") > 40)
return notify_fail("只有新手才能用!\n");
if (!wizardp(me) &&me->query("dex") > 40)
return notify_fail("只有新手才能用!\n");

//if( !environment(me)->query("outdoors") ) 
//          return notify_fail(HIY"\n室外才能坐马车。\n"NOR);


//if( environment(me)->query("chatroom") && environment(me)->query("pingan") )
// return notify_fail(HIY"\n附近好像叫不到马车。\n"NOR);

/*


if( !environment(me)->query("no_fight") && me->query("combat_exp") > 900000)
{
  message_vision("只有在安全区域才能找到马车!!!\n"
                 ,me);
      	return 1;
}

if( !environment(me)->query("no_fight") && me->query("str") > 31)
{
  message_vision("只有在安全区域才能找到马车!!!\n"
                 ,me);
      	return 1;
}

if( !environment(me)->query("no_fight") && me->query("zhuanshen"))
{
  message_vision("只有在安全区域才能找到马车!!!\n"
                 ,me);
      	return 1;
}
*/

if ( me->query_temp("in_guard")   || me->query_temp("player_working") || me->query_temp("shouwei"))
return notify_fail("你正在做任务!\n");

if (!wizardp(me) && me->query("age") > 55 && !wizardp(me))
{
  message_vision("只有小于等于55岁，才能免费坐马车!!!\n"
                 ,me);
      	return 1;
}
    if (me->is_fighting()) 
        return notify_fail("你正打的热闹着呢!\n");
    if (me->is_busy()) 
        return notify_fail("你正热闹着呢!\n");

          if (!arg)
              return notify_fail("你想去哪里？\n");
          if( !wizardp(me) && me->is_fighting()  ) 
          return notify_fail("这么危险，那还有时间去坐马车?\n");

          if (me->query_temp("pigging_seat"))
                return notify_fail("先离开拱猪桌才能行动。\n");
          if( environment(me)->query("light_up"))
               return notify_fail("赌场里不能坐马车!!\n");


          else {
          message_vision(HIY
"$N叫了个马夫，并出示了手中的武林车马票，马夫牵来了马车。\n"+
"$N坐上马车，大喝一声“走喽”，只见马夫驾驶着马车飞奔而去。。。\n\n"NOR, me);
}
          if(arg=="gc") pla = "/d/city/guangchang";
     else if(arg=="xx") pla = "/d/xingxiu/xxh1";
     else if(arg=="mj") pla = "/d/mingjiao/shanmen";
     else if(arg=="em") pla = "/d/emei/qingyinge";
     else if(arg=="shl") pla = "/d/shaolin/guangchang1";
     else if(arg=="lj") pla = "/d/lingjiu/damen";
     else if(arg=="dl") pla = "/d/dali/center";
     else if(arg=="xs") pla = "/d/xueshan/shanmen";
     else if(arg=="wd") pla = "/d/wudang/guangchang";
     else if(arg=="hs") pla = "/d/huashan/zhenyue";
     else if(arg=="tam") pla = "/d/beijing/tian_anm";
     else if(arg=="quz") pla = "/d/quanzhen/damen";
     else if(arg=="bt") pla = "/d/baituo/dating";
     else if(arg=="qz") pla = "/d/quanzhou/zhongxin";
     else if(arg=="gm") pla = "/d/gumu/mumen";
     else if(arg=="sz") pla = "/d/suzhou/canlangting";
     else if(arg=="gyz") pla = "/d/guiyun/taihu";
     else if(arg=="xy") pla = "/d/xiangyang/guangchang";
     else if(arg=="ca") pla = "/d/changan/ca";
     else if(arg=="cd") pla = "/d/chengdu/guangchang";
     else if(arg=="laz") pla = "/d/lanzhou/guangchang";
     else if(arg=="jz") pla = "/d/jingzhou/guangchang";
     else if(arg=="km") pla = "/d/kunming/jinrilou";
     else if(arg=="yj") pla = "/d/yanjing/street";               
     else if(arg=="wg") pla = "/d/wuguan/guanmen";
     else if(arg=="hz") pla = "/d/hangzhou/kedian";
     else if(arg=="lz") pla = "/d/lingzhou/center";
     else if(arg=="dache") pla = "/d/city/kedian";
     else if(arg=="majiu") pla = "/d/city/majiu";
     else if(arg=="wm") pla = "/d/city/wumiao";
     else if(arg=="dp") pla = "/d/city/dangpu2";
     else if(arg=="job1") pla = "/d/welcome/welcome";
     else if(arg=="job2") pla = "/d/city/yaopu";
     else if(arg=="job3") pla = "/quest/famu/shulin2";
     else if(arg=="job4") pla = "/quest/changxi/xiyuan";
     else if(arg=="job5") pla = "/d/welcome/fight3";
     else if(arg=="job6") pla = "/quest/songhuo/huowo";
     else if(arg=="job7") pla = "/d/pingan/bingyin";
     else if(arg=="job8") pla = "/d/henshan/huiyan";
     else if(arg=="job9") pla = "/d/migong/migong3";
     else if(arg=="job10") pla = "/d/city/kedian";
     
               else {
               message_vision(HIR
"马车跑了半天，才发觉$N要去的地方根本没那个站。\n结果$N被马夫扔了下来，摔得鼻青脸肿！\n"NOR, me);
}
     if (me->move(pla)) {
       message_vision(HIC"\n到了！马车稳稳地停到地下，$N跳下了马车。对车夫挥了挥手。\n"NOR,me);
if( me->query("age") <= 18 )
           me->add("jing",-10);
 else   me->add("jing",-30);
}
     return 1;
}

int do_xx(string arg)
{
object me = this_player();
	if (!id(arg))
                return notify_fail("你要用什么？\n");
if (!wizardp(me) && me->query("age") > 55)
return notify_fail("只有新手才能用!\n");
if (!wizardp(me) && me->query("str") > 40)
return notify_fail("只有新手才能用!\n");
if (!wizardp(me) && me->query("dex") > 40)
return notify_fail("只有新手才能用!\n");

if (me->is_busy())
return notify_fail("你正在忙！\n");
if (me->is_fighting())
return notify_fail("你正在打！\n");
if ((int)me->query("combat_exp") > 6500000 )
return notify_fail("只有新手才能用!\n");

if ( (int)me->query("jing") < 30 || (int)me->query("qi") < 30 )
return notify_fail("你的身体太累了，没办法修行。!\n");

	if (me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着呢！\n");



if (me->query_temp("working") >=1)
{
	write(""+me->query("name")+"心如静水，渐入定境。\n");
}
else
{
	message_vision(YEL "$N拿出新手背包铺在地上开始打坐修行!!\n" NOR,me);
	write(""+me->query("name")+"收摄心神，开始打坐修行。\n");
}
	

	me->add_temp("working",1);
if (me->query("qi") < me->query("max_qi"))
me->add("qi",me->query("max_qi")/5);
if (me->query("jing") < me->query("max_jing"))
me->add("jing",me->query("max_jing")/5);
me->start_busy(6);

if (me->query_temp("working") >=6)
	call_out("work_end", 1, me);

return 1;
}


int work_end(object me)
{
	object ob1;
	int add_exp,add_pot,add_score;
	me->delete_temp("working");
	write("终于修行完了,你获得一些奖励。”\n");
	me->receive_damage("jing",me->query("jing")/8);
	me->receive_damage("qi",me->query("qi")/8);

		add_exp=2+random(3);
		add_pot=1+random(2);
if ((int)me->query("combat_exp",1) < 1200000 && !me->query("zhuanshen") && !me->query("zhuanbest")  && !me->query("guard/flag"))
{
		add_exp=3+random(4);
		add_pot=2+random(2);

}

		add_score=1+random(1);
		me->add("combat_exp",add_exp);
		me->add("potential",add_pot);
		//me->add("score",add_score);
		ob1 = new("/clone/money/silver");
		ob1->set_amount(add_score);
		ob1->move(me);	
		tell_object(me,HIW"你得到了:"
			+ chinese_number(add_exp) + "点实战经验，"
			+ chinese_number(add_pot) + "点潜能。\n"NOR);		
				
	if ( me->query_temp("working") ) me->delete_temp("working");
	return 1;
}