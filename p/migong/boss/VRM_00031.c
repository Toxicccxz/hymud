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
        set_maze_npcs(__DIR__"npc/0003/man2");

	// 迷宫中的怪物出现可能性
        //set_npcs_rate(50);

	//迷宫房间里的BOSS。
        set_exit_npcs(__DIR__"npc/0003/zhuangzhu2");

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
	set_link_entry_room("/d/city/wumiao");

	//出口与区域的连接方向
	set_link_exit_dir("south");

	//出口与区域的连接档案名
	set_link_exit_room(__DIR__"vrm03out1");

	//入口房间短描述
	set_entry_short("金陵会武馆");

	//入口房间描述
	set_entry_desc(@LONG
江南武林道上群豪荟萃之地。每日卯时开堂，亥时关门。关门
之前，会武馆中所有人必须离开，纵有深仇大恨的要追杀，也要等
上几个时辰。因为会武馆有一个不成文的人，不论什么原因，都不
许动手。金陵会武馆既是一处不能动手的所在，时日渐久，遂成了
一处南北消息交汇之地，武林中几乎任何消息都会由此立刻遍传于
江湖之上。
LONG
);

	//BOSS房间短描述
	set_exit_short("金陵会武馆");

	//BOSS房间描述
	set_exit_desc(HIB"
江南武林道上群豪荟萃之地。每日卯时开堂，亥时关门。关门
之前，会武馆中所有人必须离开，纵有深仇大恨的要追杀，也要等
上几个时辰。因为会武馆有一个不成文的人，不论什么原因，都不
许动手。金陵会武馆既是一处不能动手的所在，时日渐久，遂成了
一处南北消息交汇之地，武林中几乎任何消息都会由此立刻遍传于
江湖之上。
"NOR);

	//迷宫房间的短描述
	set_maze_room_short("金陵会武馆");

	//迷宫房间的描述，如果有多条描述，制造每个房
	//间的时候会从中随机选择一个。
	set_maze_room_desc(@LONG
江南武林道上群豪荟萃之地。每日卯时开堂，亥时关门。关门
之前，会武馆中所有人必须离开，纵有深仇大恨的要追杀，也要等
上几个时辰。因为会武馆有一个不成文的人，不论什么原因，都不
许动手。金陵会武馆既是一处不能动手的所在，时日渐久，遂成了
一处南北消息交汇之地，武林中几乎任何消息都会由此立刻遍传于
江湖之上。
LONG
);


        // 迷宫摧毁时间
        set_remove_time(3000); 

	// 迷宫房间是否为户外房间？
	set_outdoors(0);
}
