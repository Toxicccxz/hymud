#include <ansi.h>

inherit VRM_SERVER;

#define ENTER_ROOM_X    0
#define ENTER_ROOM_Y    0
#define ENTER_ROOM_Z    0

void create()
{
	// 迷宫房间所继承的物件的档案名称。
	set_inherit_room( ROOM ); set("no_clean_up",1);

        set_lonely_create(1);

	//迷宫的单边长
        set_maze_long(8); 

        set_npcs_rate(66);
        



        set_maze_boxs(2);
        set_maze_traps(6); 


	//迷宫房间里的怪物。
	set_maze_npcs(__DIR__"npc/0008/beast");


	//迷宫房间里的BOSS。
	set_exit_npcs(__DIR__"npc/0008/leijiu");



	//入口方向(出口在对面)
	set_entry_dir("north");

	//入口与区域的连接方向
	set_link_entry_dir("north");

	//入口与区域的连接档案名
	set_link_entry_room("/d/city/wumiao");

	//出口与区域的连接方向
	set_link_exit_dir("south");

	//出口与区域的连接档案名
	set_link_exit_room("/d/city/wumiao");

	//入口房间短描述
	set_entry_short("回音山谷");

	//入口房间描述
	set_entry_desc(HIY"
	是一个纵深七百二十米的断岩绝壁。这是悬崖下的小山谷，周围一片寂静。
偶尔一个碎石落下，传来阵阵回声。抑或阵阵雷鸣，震耳欲聋。
"NOR);

	//BOSS房间短描述
	set_exit_short("回音山谷");

	//BOSS房间描述
	set_exit_desc(HIY"
	是一个纵深七百二十米的断岩绝壁。这是悬崖下的小山谷，周围一片寂静。
偶尔一个碎石落下，传来阵阵回声。抑或阵阵雷鸣，震耳欲聋。
"NOR);

	//迷宫房间的短描述
	set_maze_room_short("回音山谷");

	//迷宫房间的描述，如果有多条描述，制造每个房
	//间的时候会从中随机选择一个。
	set_maze_room_desc(HIY"
	是一个纵深七百二十米的断岩绝壁。这是悬崖下的小山谷，周围一片寂静。
偶尔一个碎石落下，传来阵阵回声。抑或阵阵雷鸣，震耳欲聋。
"NOR);
        // 迷宫摧毁时间
        set_remove_time(3000); 
	// 迷宫房间是否为户外房间？
	//set_outdoors(1);
}
