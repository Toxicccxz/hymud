// Room: /d/linzhi/lin06.c

#include <ansi.h>

inherit "/adm/daemons/vrm_server.c";

#define ENTER_ROOM_X    0
#define ENTER_ROOM_Y    0
#define ENTER_ROOM_Z    0

void create()
{
	set_inherit_room( ROOM );

//	set_maze_npcs(__DIR__"npc/maque");
        set_center_room("/d/city/guangchang");
        
        set_unique_room( ({
                "/d/city/wumiao",
                "/d/city/kedian",
                "/d/city/yaopu",
                "/d/city/wumiao2",
        }) ); 
        //迷宫房间里的怪物。 
        set_maze_npcs( ([
                "/d/city/npc/liumang": !random(3),  
        ]) );  
//npc机率
     set_npcs_rate(50);
//boss
    set_maze_boss("/d/city/npc/liumangtou");
        // 迷宫出口的怪物。
        set_exit_npcs( ([
                "/d/city/npc/liumang" : 1,
        ]) );
        // 迷宫入口的怪物。
        set_entry_npcs( "/d/city/npc/liumang" );



        set_maze_boxs(5);
        set_maze_traps(8);  
           
                //不算死亡              
        //set_maze_nodeath(1);

	set_maze_long(12);

	//入口方向(出口在对面)
	set_entry_dir("east");

	//入口与区域的连接方向
	set_link_entry_dir("east");

	//入口与区域的连接档案名
	set_link_entry_room(__DIR__"lin05");

	//出口与区域的连接方向
	set_link_exit_dir("west");

	//出口与区域的连接档案名
	set_link_exit_room(__DIR__"lin07");
set_lonely_create(1);

        //以下是入口坐标
        set_link_entry_room_x(ENTER_ROOM_X);
        set_link_entry_room_y(ENTER_ROOM_Y);
        set_link_entry_room_z(ENTER_ROOM_Z);


	//入口房间短描述
	set_entry_short("桃花沟");

	set_entry_desc(@LONG
你来到桃花沟，只见到处都是野生的桃树。这是一片天然的
桃林，不知从何时起有的。每年到了八月桃子成熟的季节，人们
会来这里采摘(pick)桃子。据当地老人讲，这桃子是神赏赐给子
民的。你走着走着，忽然觉得迷失了方向。
LONG
);

	//出口房间短描述
	set_exit_short("桃花沟");

	set_exit_desc(@LONG
你来到桃花沟，只见到处都是野生的桃树。这是一片天然的
桃林，不知从何时起有的。每年到了八月桃子成熟的季节，人们
会来这里采摘(pick)桃子。据当地老人讲，这桃子是神赏赐给子
民的。你走着走着，忽然觉得迷失了方向。
LONG
);


	//迷宫房间的短描述
	set_maze_room_short("桃花沟");

	//迷宫房间的描述，如果有多条描述，制造每个房
	//间的时候会从中随机选择一个。
	set_maze_room_desc(@LONG
你来到桃花沟，只见到处都是野生的桃树。这是一片天然的
桃林，不知从何时起有的。每年到了八月桃子成熟的季节，人们
会来这里采摘(pick)桃子。据当地老人讲，这桃子是神赏赐给子
民的。你走着走着，忽然觉得迷失了方向。
LONG
);

        // 迷宫房间是否为户外房间？ 
        set_outdoors(1); 
        
        // 迷宫刷新时间
        set_maze_refresh(1); 
        
        // 迷宫摧毁时间
        set_remove_time(2); 

}

string query_my_map(){  return read_file(__DIR__"lin06.map");}