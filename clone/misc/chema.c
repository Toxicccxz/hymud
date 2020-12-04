// more work needed to use this object to make poison
#include <ansi.h>
inherit ITEM;


void init()
{
          add_action ("do_fly","chema");
}

void create()
{
	set_name(YEL"武林车马票"NOR, ({"chema piao", "piao"}));
        set("unit", "张");
set("long", YEL"为了方便大家。开通车马(chema)服务！\n
 目前你可以去的地方有如下:
北京(tam)  大理(dl) 泉州(qz) 少林(shl) 华山(hs) 灵鹫(lj) 武当(wd) 明教(mj)  扬州(gc) 神龙(sld)
星宿(xx)   雪山(xs) 峨眉(em) 全真(quz)白驼山(bt)古墓(gm) 苏州(sz)归云庄(gyz)襄阳(xy) 定襄(dx)  
长安(ca)   成都(cd) 兰州(laz)荆州(jz)  盛京(yj) 武馆(wg) 昆明(km) 杭州(hz)  灵州(lz) 巴陵(bl) 
福州城(fz) 沧州(cz) 宜兴(yx) 洛阳(ly)  岳阳(yy) 塘沽(tg) 延平(yp) 江陵(jl)无锡城(wx) 九江(jj)
盛京(sj)   宁远(ny) 长沙(cs) 南昌(nc)  贵阳(gy) 新疆(xj) 徐州(xz) 西藏(xiz) 太原(ty) 合肥(hf)
桃花(thd) 日本(jp) 安南(an) 高丽(cx)  金陵(nj) 海南(mp10)侠客(mp11)崆峒(mp12)梅庄(mp8)靖海(mp9)
红花(mp1)  青城(mp2)泰山派(mp3)嵩山(mp4) 衡山(mp5)恒山(mp6) 苗家(mp7) 慕容(mp13) 唐门 (mp14)
日月(mp15) 凌霄(mp16) 武功镇(wgz)伊犁(yl)关外(gw)车站(dache) 扬州马厩(majiu) 扬州当铺(dp) 
胡家(mp17) 铁掌(mp18) 落雁(mp19) 飞天(mp20)  五毒教(mp21)\n"NOR  
);

             set("value", 500);
             set("material", "steel");
        setup();
}

  int do_fly(string arg)
{

          string pla;
          object me = this_player();
if( me->query("jing") < 30 )
               return notify_fail("你精神不够旺盛，没力气做车马！\n");
if( me->query_temp("pending/team"))
               return notify_fail("你正和别人组队呢！\n");				

if( !environment(me)->query("outdoors") ) 
          return notify_fail(HIY"\n室外才能坐马车。\n"NOR);

    if (me->is_fighting()) 
        return notify_fail("你正打的热闹着呢!\n");
    if (me->is_busy()) 
        return notify_fail("你正热闹着呢!\n");
//if (me->query_temp("xhjob_start") || me->query_temp("wdhwjob") || me->query_temp("in_guard") || me->query_temp("job_name") ||me->query_temp("tmhw") || me->query_temp("qztjob") || me->query_temp("lxhw") || me->query_temp("player_working") || me->query_temp("shouwei"))
//return notify_fail("你正在做任务!\n");

if (me->query_temp("xhjob_start") || me->query_temp("wdhwjob") || me->query_temp("in_guard")   || me->query_temp("player_working") || me->query_temp("shouwei"))
return notify_fail("你正在做任务!\n");
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
"$N叫了个马夫，并把手中的武林车马票交给马夫，马夫牵来了马车。\n"+
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
     else if(arg=="fz") pla = "/d/fuzhou/majiu";							
else if(arg=="cz") pla = "/d/cangzhou/beimen";									     
else if(arg=="yx") pla = "/d/yixing/yixing";									
else if(arg=="tg") pla = "/d/tanggu/beimen";									
else if(arg=="ly") pla = "/d/luoyang/center";									
else if(arg=="yy") pla = "/d/yueyang/guangchang";		
else if(arg=="wgz") pla = "/d/quanzhen/guchang";			
else if(arg=="yp") pla = "/d/yanping/majiu";			
else if(arg=="jl") pla = "/d/jiangling/beimen";	
else if(arg=="wx") pla = "/d/wuxi/majiu";						
else if(arg=="yl") pla = "/d/xingxiu/majiu";
else if(arg=="gw") pla = "/d/guanwai/nancheng";
else if(arg=="ty") pla = "/d/taiyuan/xidajie1";
else if(arg=="sj") pla = "/d/fengtian/cross";
else if(arg=="ny") pla = "/d/ny/postoffice";
else if(arg=="cs") pla = "/d/changsha/guangchang";
else if(arg=="nc") pla = "/d/nanchang/center";
else if(arg=="gy") pla = "/d/guizhou/center";
else if(arg=="xj") pla = "/d/xinjiang/nanmen";
else if(arg=="xz") pla = "/d/xuzhou/xidajie";
else if(arg=="xiz") pla = "/d/xizang/citygate";
else if(arg=="thd") pla = "/d/taohua/haitan";
else if(arg=="sld") pla = "/d/shenlong/haitan";
else if(arg=="jp") pla = "/d/japan/haigang";
else if(arg=="an") pla = "/d/annan/matou";
else if(arg=="cx") pla = "/d/gaoli/gangkou";
else if(arg=="hf") pla = "/d/hefei/xidajie3";
else if(arg=="jj") pla = "/d/jiujiang/dongdajie2";
else if(arg=="bl") pla = "/d/baling/dongdajie1";
else if(arg=="dx") pla = "/d/dingxiang/beidajie1";

else if(arg=="mp1") pla = "/d/huizhu/zongduo";
else if(arg=="mp2") pla = "/d/qingcheng/qiandian";
else if(arg=="mp3") pla = "/d/taishan/riguan";
else if(arg=="mp4") pla = "/d/songshan/chanyuan";
else if(arg=="mp5") pla = "/d/henshan/zhurongdian";
else if(arg=="mp6") pla = "/d/hengshan/baiyunan";
else if(arg=="mp7") pla = "/d/zhongzhou/miaojia_houting";
else if(arg=="mp8") pla = "/d/meizhuang/xiaowu";
else if(arg=="mp9") pla = "/d/jinghai/jhd19";
else if(arg=="mp10") pla = "/d/hainan/jingtang";
else if(arg=="mp11") pla = "/d/xiakedao/shiroom24";
else if(arg=="mp12") pla = "/d/xibei/kongdong/xuanyuan_gong";
else if(arg=="mp13") pla = "/d/mr/yanziwu";
else if(arg=="mp14") pla = "/d/tangmen/dating";
else if(arg=="mp15") pla = "/d/heimuya/chengdedian";
else if(arg=="mp16") pla = "/d/lingxiao/dadian";
else if(arg=="mp17") pla = "/d/guanwai/xiaowu";
else if(arg=="mp18") pla = "/d/tiezhang/guangchang";
else if(arg=="mp19") pla = "/d/yandang/luoyan6";
else if(arg=="mp20") pla = "/d/feitian/daochang";
else if(arg=="mp21") pla = "/d/wudujiao/dating";
else if(arg=="nj") pla = "/d/jinling/zhongxin";		
               else {
               message_vision(HIR
"马车跑了半天，才发觉$N要去的地方根本没那个站。\n结果$N被马夫扔了下来，摔得鼻青脸肿！\n"NOR, me);
}
     if (me->move(pla)) {
       message_vision(YEL"\n到了！马车稳稳地停到地下，$N跳下了马车。对车夫挥了挥手。\n"NOR,me);
   me->set_temp("nbjob25",1);
   me->add("jing",-30);
   me->start_busy(3);
}
	destruct(this_object());
     return 1;
}