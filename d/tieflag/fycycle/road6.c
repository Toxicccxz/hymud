 inherit ROOM;
void create()
{
        set("short", "城东小道");
        set("long", @LONG
这是风云城东的一条小道，也是从无名小镇去往风云城的必经之路。路上倒也有不少
行人。路边的护城河中流水声不绝。向东望去，是一座暗红色的山峰，上山的道路就
在南面。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  //"southeast" :AREA_PALACE"palace_path1",
  "northwest" : __DIR__"road5",
]));
        set("outdoors", "fengyun");  
        set("coor/x",80);
        set("coor/y",80);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}    
