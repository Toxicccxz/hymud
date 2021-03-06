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
        set_maze_npcs(__DIR__"npc/0004/man2");

	// 迷宫中的怪物出现可能性
        //set_npcs_rate(50);

	//迷宫房间里的BOSS。
        set_exit_npcs(__DIR__"npc/0004/zhuangzhu2");

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
	set_link_exit_room(__DIR__"vrm04out1");

	//入口房间短描述
	set_entry_short("幽灵山庄");

	//入口房间描述
	set_entry_desc(@LONG
这是一个黑暗而恐怖的地方，它四周以万丈深壑和千年沼泽与外世
相隔阻，人处其里，放眼四望，雾气蒙蒙，了无人烟。然而，就是在
这个荒芜、偏僻的野地，却隐藏着一批不凡的人，当年都是独霸一方
的豪杰、无人敢惹的凶神、或者一派掌门之尊，但他们当年又都曾犯
过不可饶恕的罪过而不见容于江湖，才不得不各自以十万两银子的代
价躲到这个地方当一个幽灵，惟幽灵山庄庄主老刀把子之马首是瞻。
LONG
);

	//BOSS房间短描述
	set_exit_short("幽灵山庄");

	//BOSS房间描述
	set_exit_desc(HIB"
这是一个黑暗而恐怖的地方，它四周以万丈深壑和千年沼泽与外世
相隔阻，人处其里，放眼四望，雾气蒙蒙，了无人烟。然而，就是在
这个荒芜、偏僻的野地，却隐藏着一批不凡的人，当年都是独霸一方
的豪杰、无人敢惹的凶神、或者一派掌门之尊，但他们当年又都曾犯
过不可饶恕的罪过而不见容于江湖，才不得不各自以十万两银子的代
价躲到这个地方当一个幽灵，惟幽灵山庄庄主老刀把子之马首是瞻。
"NOR);

	//迷宫房间的短描述
	set_maze_room_short("幽灵山庄");

	//迷宫房间的描述，如果有多条描述，制造每个房
	//间的时候会从中随机选择一个。
	set_maze_room_desc(@LONG
这是一个黑暗而恐怖的地方，它四周以万丈深壑和千年沼泽与外世
相隔阻，人处其里，放眼四望，雾气蒙蒙，了无人烟。然而，就是在
这个荒芜、偏僻的野地，却隐藏着一批不凡的人，当年都是独霸一方
的豪杰、无人敢惹的凶神、或者一派掌门之尊，但他们当年又都曾犯
过不可饶恕的罪过而不见容于江湖，才不得不各自以十万两银子的代
价躲到这个地方当一个幽灵，惟幽灵山庄庄主老刀把子之马首是瞻。
LONG
);


        // 迷宫摧毁时间
        set_remove_time(3000); 

	// 迷宫房间是否为户外房间？
	set_outdoors(0);
}
