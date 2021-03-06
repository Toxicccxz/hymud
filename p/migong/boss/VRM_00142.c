#include <ansi.h>

inherit VRM_SERVER;

#define ENTER_ROOM_X    0
#define ENTER_ROOM_Y    0
#define ENTER_ROOM_Z    0

void create()
{
	// 迷宫房间所继承的物件的档案名称。
	set_inherit_room( ROOM ); set("no_clean_up",1);

	// 迷宫进入要求最低等级。

        set_lonely_create(1);


	//迷宫房间里的怪物。
        set_maze_npcs(__DIR__"npc/0014/man3");

	// 迷宫中的怪物出现可能性
        //set_npcs_rate(50);

	//迷宫房间里的BOSS。
        set_exit_npcs(__DIR__"npc/0014/zhuangzhu3");

	//迷宫的单边长
        set_maze_long(6); 

        set_npcs_rate(66);
        
        //set_lonely_create(1);


        set_maze_boxs(2);
        set_maze_traps(4); 

	//入口方向(出口在对面)
	set_entry_dir("north");

	//入口与区域的连接方向
	set_link_entry_dir("north");

	//入口与区域的连接档案名
	set_link_entry_room(__DIR__"vrm14out2");

	//出口与区域的连接方向
	set_link_exit_dir("south");

	//出口与区域的连接档案名
	set_link_exit_room(__DIR__"vrm14out3");

	//入口房间短描述
	set_entry_short("死亡峡");

	//入口房间描述
	set_entry_desc(@LONG
又称男人禁地。崔花婆从四川唐门逃出来后，恨透了天下男人，
隐居在死亡峡中，坐地为王。华中大侠黄剑飞等七位武林高手先后
在此落难，被有用铁链洞穿琵琶骨，不仅开功尽失，而且豪气全无
，生不如死。如果是那些藉藉无名的人误闯误撞走进死亡峡，崔花
婆便不问情由，一律抛进鳄鱼潭。只有张定远以血剑十二式与崔花
婆打成平手，活着走出死亡峡，算是一个例外。
LONG
);

	//BOSS房间短描述
	set_exit_short("死亡峡");

	//BOSS房间描述
	set_exit_desc(HIB"
又称男人禁地。崔花婆从四川唐门逃出来后，恨透了天下男人，
隐居在死亡峡中，坐地为王。华中大侠黄剑飞等七位武林高手先后
在此落难，被有用铁链洞穿琵琶骨，不仅开功尽失，而且豪气全无
，生不如死。如果是那些藉藉无名的人误闯误撞走进死亡峡，崔花
婆便不问情由，一律抛进鳄鱼潭。只有张定远以血剑十二式与崔花
婆打成平手，活着走出死亡峡，算是一个例外。
"NOR);

	//迷宫房间的短描述
	set_maze_room_short("死亡峡");

	//迷宫房间的描述，如果有多条描述，制造每个房
	//间的时候会从中随机选择一个。
	set_maze_room_desc(@LONG
又称男人禁地。崔花婆从四川唐门逃出来后，恨透了天下男人，
隐居在死亡峡中，坐地为王。华中大侠黄剑飞等七位武林高手先后
在此落难，被有用铁链洞穿琵琶骨，不仅开功尽失，而且豪气全无
，生不如死。如果是那些藉藉无名的人误闯误撞走进死亡峡，崔花
婆便不问情由，一律抛进鳄鱼潭。只有张定远以血剑十二式与崔花
婆打成平手，活着走出死亡峡，算是一个例外。
LONG
);


        // 迷宫摧毁时间
        set_remove_time(3000); 

	// 迷宫房间是否为户外房间？
	set_outdoors(0);
}
