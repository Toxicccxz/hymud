
// Room: /d/snow/deaprec.c

inherit ROOM;
#include <ansi.h>

void create()
{
        set("coor",({-20,5040,20}));
        set("short", CYN"绝情谷"NOR);
        set("long",
"[36m建设中！玩家留步。。。。。。。[2;37;0m\n"
);
	set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"droad2",
]));
        set("item_desc",([
                        "tablet":@TEXT
!!!!!!!!!擅入此谷者，杀无赦!!!!!!!!!!
TEXT])); 
	setup();
}
