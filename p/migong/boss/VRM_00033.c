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
        set_maze_npcs(__DIR__"npc/0003/man4");

	// 迷宫中的怪物出现可能性
        //set_npcs_rate(50);

	//迷宫房间里的BOSS。
        set_exit_npcs(__DIR__"npc/0003/zhuangzhu4");

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
	set_link_entry_room(__DIR__"vrm03out2");

	//出口与区域的连接方向
	set_link_exit_dir("south");

	//出口与区域的连接档案名
	set_link_exit_room(__DIR__"vrm03out3");

	//入口房间短描述
	set_entry_short("香杏画舫");

	//入口房间描述
	set_entry_desc(@LONG
游弋在江南水乡的一只妓船，乃江湖上最负盛名之寻欢作乐处，其
宗旨是“无尽创意献温馨”，永久不变，而当了解了舫中内容后，诚知
此言不谬。香杏画舫相传为唐公主李香舫因厌倦空虚繁荣的宫廷生活，
抛冠入世而建造，使之成为天下第一醉生梦死之烟花去处。多少年来，
不知有多少富户子弟尽散家财，令多少风流浪子醉死其中。
LONG
);

	//BOSS房间短描述
	set_exit_short("香杏画舫");

	//BOSS房间描述
	set_exit_desc(HIB"
游弋在江南水乡的一只妓船，乃江湖上最负盛名之寻欢作乐处，其
宗旨是“无尽创意献温馨”，永久不变，而当了解了舫中内容后，诚知
此言不谬。香杏画舫相传为唐公主李香舫因厌倦空虚繁荣的宫廷生活，
抛冠入世而建造，使之成为天下第一醉生梦死之烟花去处。多少年来，
不知有多少富户子弟尽散家财，令多少风流浪子醉死其中。
"NOR);

	//迷宫房间的短描述
	set_maze_room_short("香杏画舫");

	//迷宫房间的描述，如果有多条描述，制造每个房
	//间的时候会从中随机选择一个。
	set_maze_room_desc(@LONG
游弋在江南水乡的一只妓船，乃江湖上最负盛名之寻欢作乐处，其
宗旨是“无尽创意献温馨”，永久不变，而当了解了舫中内容后，诚知
此言不谬。香杏画舫相传为唐公主李香舫因厌倦空虚繁荣的宫廷生活，
抛冠入世而建造，使之成为天下第一醉生梦死之烟花去处。多少年来，
不知有多少富户子弟尽散家财，令多少风流浪子醉死其中。
LONG
);


        // 迷宫摧毁时间
        set_remove_time(3000); 

	// 迷宫房间是否为户外房间？
	set_outdoors(0);
}
