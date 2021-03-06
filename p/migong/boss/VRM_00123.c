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
        set_maze_npcs(__DIR__"npc/0012/man4");

	// 迷宫中的怪物出现可能性
        //set_npcs_rate(50);

	//迷宫房间里的BOSS。
        set_exit_npcs(__DIR__"npc/0012/zhuangzhu4");

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
	set_link_entry_room(__DIR__"vrm12out3");

	//出口与区域的连接方向
	set_link_exit_dir("south");

	//出口与区域的连接档案名
	set_link_exit_room("/d/city/wumiao");

	//入口房间短描述
	set_entry_short("天蚕坛");

	//入口房间描述
	set_entry_desc(@LONG
古时天子重万民，民以农难能可桑为本，故天子祭坛于北郊以祭
天蚕。随着时间的推移，天蚕坛渐被废置，最后变成了喇嘛们的火葬处。
边外的牧民，死后尸体都由喇嘛火葬，清兵入关后习俗仍未改，甚至边
火葬用的草，都物地由骆驼从关外运来。天蚕坛成为火葬处后，昔日庄
严、神圣的大殿里居然摆满了箱子，挂满了口袋，箱子里装的是死人，
口袋里盛的是骨灰，散发着无法形容的恶息。入夜之后，这里灯光灰暗
，犹如坟墓。
LONG
);

	//BOSS房间短描述
	set_exit_short("天蚕坛尽头");

	//BOSS房间描述
	set_exit_desc(HIB"
古时天子重万民，民以农难能可桑为本，故天子祭坛于北郊以祭
天蚕。随着时间的推移，天蚕坛渐被废置，最后变成了喇嘛们的火葬处。
边外的牧民，死后尸体都由喇嘛火葬，清兵入关后习俗仍未改，甚至边
火葬用的草，都物地由骆驼从关外运来。天蚕坛成为火葬处后，昔日庄
严、神圣的大殿里居然摆满了箱子，挂满了口袋，箱子里装的是死人，
口袋里盛的是骨灰，散发着无法形容的恶息。入夜之后，这里灯光灰暗
，犹如坟墓。
"NOR);

	//迷宫房间的短描述
	set_maze_room_short("天蚕坛");

	//迷宫房间的描述，如果有多条描述，制造每个房
	//间的时候会从中随机选择一个。
	set_maze_room_desc(@LONG
古时天子重万民，民以农难能可桑为本，故天子祭坛于北郊以祭
天蚕。随着时间的推移，天蚕坛渐被废置，最后变成了喇嘛们的火葬处。
边外的牧民，死后尸体都由喇嘛火葬，清兵入关后习俗仍未改，甚至边
火葬用的草，都物地由骆驼从关外运来。天蚕坛成为火葬处后，昔日庄
严、神圣的大殿里居然摆满了箱子，挂满了口袋，箱子里装的是死人，
口袋里盛的是骨灰，散发着无法形容的恶息。入夜之后，这里灯光灰暗
，犹如坟墓。
LONG
);


        // 迷宫摧毁时间
        set_remove_time(3000); 

	// 迷宫房间是否为户外房间？
	set_outdoors(0);
}
