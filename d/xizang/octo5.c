 inherit ROOM;
void create()
{
        set("short", "八角街");
        set("long", @LONG
大昭寺外，围绕着寺院的八角街是布达拉宫里最繁华热闹的地方。所有最大的
客栈和商号都在这条街上。远处钟声不时的齐鸣。一声声梵唱随风飘来。宝塔的尖
顶在太阳下闪着金光，充满了神圣庄严肃穆的景象。
LONG
        );
        
        set("exits", ([ 
                "east" : __DIR__"octo4",
                "west" : __DIR__"octo6",
                "south" : __DIR__"work",
        ]));
        set("outdoors", "xizang");
set("objects", ([
                __DIR__"npc/lama" : 2,
        ]) );
    set("coor/x",-1230);
        set("coor/y",-30);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}    
