#include <ansi.h>
inherit VRM_SERVER; 
 
#define ENTER_ROOM_X  0
#define ENTER_ROOM_Y  0
#define ENTER_ROOM_Z  0



void create() 
{ 
        //迷宫房间所继承的物件的档案名称。 
        set_inherit_room( ROOM ); set("no_clean_up",1);
                        
        //唯一房间
        //set_unique_room( unique_rooms ); 

        //迷宫房间里的怪物。 
                  
        
        //不算死亡
        //set_true_death_room(1);

        //迷宫的单边长 
        set_maze_long(5); 

        //set_npcs_rate(66);
        
        set_lonely_create(1);
                        
        //入口方向(出口在对面) 
        set_entry_dir("east"); 
                        
        //入口与区域的连接方向 
        set_link_entry_dir("east"); 
                        
        //入口与区域的连接档案名 
        set_link_entry_room("/d/city/wumiao"); 
                        
        //出口与区域的连接方向 
        set_link_exit_dir("west"); 
                        
        //出口与区域的连接档案名 
        set_link_exit_room("/d/city/wumiao"); 

        //迷宫房间里的BOSS。
        set_exit_npcs(__DIR__"npc/eboss/eboss7");
        
        
        // 迷宫入口的怪物。
//        set_entry_npcs( "/d/city/npc/liumang" );

        //set_maze_boxs(1);
        set_maze_traps(2); 
                        
        //以下是入口坐标
        //set_link_entry_room_x(ENTER_ROOM_X);
        //set_link_entry_room_y(ENTER_ROOM_Y);
        //set_link_entry_room_z(ENTER_ROOM_Z);
                        
        //普通房间描述
        set_maze_room_short(HIR"试练角斗场"NOR);
                        
        set_maze_room_desc(@LONG
地下角斗场中，角斗士们戴着黄金面具，穿着发着光泽的盔甲，
用铁剑和盾牌进行角斗或斗兽，与那些沙场上金戈铁马的将士不同
，他们没有冲锋的豪情，仅有一线生存的幻想观众。
LONG); 

        //入口房间短描述 
        set_entry_short(HIR"试练角斗场"NOR); 
                        
        //入口房间描述 
        set_entry_desc(@LONG
地下角斗场中，角斗士们戴着黄金面具，穿着发着光泽的盔甲，
用铁剑和盾牌进行角斗或斗兽，与那些沙场上金戈铁马的将士不同
，他们没有冲锋的豪情，仅有一线生存的幻想观众。
LONG);
                        
        //出口房间短描述 
        set_exit_short(HIR"试练角斗场"NOR); 
                        
        //出口房间描述 
        set_exit_desc(@LONG
地下角斗场中，角斗士们戴着黄金面具，穿着发着光泽的盔甲，
用铁剑和盾牌进行角斗或斗兽，与那些沙场上金戈铁马的将士不同
，他们没有冲锋的豪情，仅有一线生存的幻想观众。
LONG);

        // 迷宫房间是否为户外房间？ 
        set_outdoors(0);                                                

       // 迷宫刷新时间
        //set_maze_refresh(680); 
        
        // 迷宫摧毁时间
        set_remove_time(1080); 
} 



