#include <ansi.h> 
inherit ROOM;

void create()
{
        set("short",HIC"�߶�"NOR);
        set("long",@LONG
�ö��߰���
LONG);

        set("maze", 1);
        set("no_clean_up", 1);
        set("no_magic", 1);
        set("virtual_room",1);
        set("outdoors", "forest");  
        
        set("objects",([
                "/p/migong/forest/npc/snake_king": 1,   
                "/p/migong/forest/npc/snake_big": 5, 
                "/p/migong/forest/npc/snake_baby": 5,   
                "/p/migong/forest/obj/box1": 1,      
        ]));
        setup();
}