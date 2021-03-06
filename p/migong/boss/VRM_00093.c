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
        set_maze_npcs(__DIR__"npc/0009/man4");

	// 迷宫中的怪物出现可能性
        //set_npcs_rate(50);

	//迷宫房间里的BOSS。
        set_exit_npcs(__DIR__"npc/0009/zhuangzhu4");

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
	set_link_entry_room(__DIR__"vrm09out2");

	//出口与区域的连接方向
	set_link_exit_dir("south");

	//出口与区域的连接档案名
	set_link_exit_room(__DIR__"vrm09out3");

	//入口房间短描述
	set_entry_short("圜丘");

	//入口房间描述
	set_entry_desc(@LONG
古时祭天之坛。《周礼·春官·大司乐》：“冬日至，于地上之
圜丘奏之。”贾公彦疏：“土之高者曰丘，取自然之丘圜者，象天圜也。
”圜丘为三层汉白玉石坛，坛面、台阶、栏杆所用的石块全是９或９的
倍数，因为中国古代认为１、３、５、７、９是阳数、天数，皇帝象征
天或太阳，所以皇帝祭天的地方用９为基数设计。
LONG
);

	//BOSS房间短描述
	set_exit_short("圜丘");

	//BOSS房间描述
	set_exit_desc(HIB"
古时祭天之坛。《周礼·春官·大司乐》：“冬日至，于地上之
圜丘奏之。”贾公彦疏：“土之高者曰丘，取自然之丘圜者，象天圜也。
”圜丘为三层汉白玉石坛，坛面、台阶、栏杆所用的石块全是９或９的
倍数，因为中国古代认为１、３、５、７、９是阳数、天数，皇帝象征
天或太阳，所以皇帝祭天的地方用９为基数设计。
"NOR);

	//迷宫房间的短描述
	set_maze_room_short("圜丘");

	//迷宫房间的描述，如果有多条描述，制造每个房
	//间的时候会从中随机选择一个。
	set_maze_room_desc(@LONG
古时祭天之坛。《周礼·春官·大司乐》：“冬日至，于地上之
圜丘奏之。”贾公彦疏：“土之高者曰丘，取自然之丘圜者，象天圜也。
”圜丘为三层汉白玉石坛，坛面、台阶、栏杆所用的石块全是９或９的
倍数，因为中国古代认为１、３、５、７、９是阳数、天数，皇帝象征
天或太阳，所以皇帝祭天的地方用９为基数设计。
LONG
);


        // 迷宫摧毁时间
        set_remove_time(3000); 

	// 迷宫房间是否为户外房间？
	set_outdoors(0);
}
