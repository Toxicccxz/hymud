//1997-3-10 by qyz

inherit ROOM;

//string *things = ({
//            "/clone/misc/chabei",
//            "/clone/misc/chahu",
//            "/clone/misc/hongcha",
//            "/clone/misc/lvcha",
//          "/d/menpai/kongdong/obj/yaochi",
//            });


#include <room.h>


void create()
{
	set("short","轩辕宫");
	set("long",@LONG
走进宫门，正面是高大的彩色三清塑像，周围放着历代皇帝举行祭典时用过
的祭器和乐器，前面放着一个香台，香台上几根香烛放出微弱的光芒，一阵阵烟
雾从香炉里袅袅升起，令人如入仙境，正中神龛有二龙戏珠和双凤朝仪装饰，龛
内供奉身着龙袍，脚踏云履，手捧宝剑的真武坐像。
LONG);
	set("exits",
	([
          "east" : __DIR__"18_yuan",
          "west" : __DIR__"yuhuang_ge",
          "south" : __DIR__"zhaohe_tang",
          "north" : __DIR__"lingzhi_yuan",
          	]));
      set("valid_startroom", "1");
    set("need_clean","崆峒派");
	set("roomif","$botten#对练任务|个人任务|组队任务|上交物品|换取奖励|取消任务:job|quest|ask shi about teamjob|give <物品> to shi|ask shi about gongxian|give 20 silver to shi$#");
	set("objects" , ([
		__DIR__"npc/kdizi1" : 3 ,
		__DIR__"npc/mu" : 1 ,
		__DIR__"npc/song" : 1,
		__DIR__"npc/xia" : 1,
"/quest/menpai/newmp/shi11" : 1,
"/d/biwu/champion_kd" : 1,	
		]) );

    setup();
}
void reset()
{
	string s_obj;
	::reset(); 
	switch(random(5))
	{
	case 0:
		s_obj = __DIR__"obj/yaochi";
		break;
	case 1:
		s_obj = __DIR__"obj/book5";
		break;
	case 2:
		s_obj = __DIR__"obj/book1";
		break;	
	case 3:
		s_obj = __DIR__"obj/book4";
		break;						
	default:
		s_obj = __DIR__"obj/yaochi";
		break;
	}
	set("search_things", ([
		"香炉" :  s_obj,
		]) );
}