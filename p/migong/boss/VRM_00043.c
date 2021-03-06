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
        set_maze_npcs(__DIR__"npc/0004/man4");

	// 迷宫中的怪物出现可能性
        //set_npcs_rate(50);

	//迷宫房间里的BOSS。
        set_exit_npcs(__DIR__"npc/0004/zhuangzhu4");

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
	set_link_entry_room(__DIR__"vrm04out2");

	//出口与区域的连接方向
	set_link_exit_dir("south");

	//出口与区域的连接档案名
	set_link_exit_room(__DIR__"vrm04out3");

	//入口房间短描述
	set_entry_short("栖霞古刹");

	//入口房间描述
	set_entry_desc(@LONG
栖霞山，居群山之中，林木阴翳，每届晚秋，满山红叶，灿烂有如晚
霞。小杜有诗“停车坐爱枫林晚，霜叶红于二月花”，即是为此间美景
陶醉所作。栖霞山深处，有一座栖霞西刹，相传为南齐僧绍所建。僧绍
本宦门之后，却淡于名利，终生未仕，为淡泊明志，乃建寺于此修炼，
隋唐二代对此寺均增建殿堂，宋明也大事修葺，所以规模宏伟，列为四
大丛林之一。
LONG
);

	//BOSS房间短描述
	set_exit_short("栖霞古刹");

	//BOSS房间描述
	set_exit_desc(HIB"
栖霞山，居群山之中，林木阴翳，每届晚秋，满山红叶，灿烂有如晚
霞。小杜有诗“停车坐爱枫林晚，霜叶红于二月花”，即是为此间美景
陶醉所作。栖霞山深处，有一座栖霞西刹，相传为南齐僧绍所建。僧绍
本宦门之后，却淡于名利，终生未仕，为淡泊明志，乃建寺于此修炼，
隋唐二代对此寺均增建殿堂，宋明也大事修葺，所以规模宏伟，列为四
大丛林之一。
"NOR);

	//迷宫房间的短描述
	set_maze_room_short("栖霞古刹");

	//迷宫房间的描述，如果有多条描述，制造每个房
	//间的时候会从中随机选择一个。
	set_maze_room_desc(@LONG
栖霞山，居群山之中，林木阴翳，每届晚秋，满山红叶，灿烂有如晚
霞。小杜有诗“停车坐爱枫林晚，霜叶红于二月花”，即是为此间美景
陶醉所作。栖霞山深处，有一座栖霞西刹，相传为南齐僧绍所建。僧绍
本宦门之后，却淡于名利，终生未仕，为淡泊明志，乃建寺于此修炼，
隋唐二代对此寺均增建殿堂，宋明也大事修葺，所以规模宏伟，列为四
大丛林之一。
LONG
);


        // 迷宫摧毁时间
        set_remove_time(3000); 

	// 迷宫房间是否为户外房间？
	set_outdoors(0);
}
