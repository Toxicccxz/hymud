//road28.c.驿道
//date:1997.8.26
//by dan

inherit ROOM;

void create()
{
    set("short","驿道");
    set("long",@LONG
脚下是黄土铺成的路面，整齐干净，不时有行人从身边擦肩而过. 周围建筑
较少, 只有一些供路人休息的凉棚。这条驿道通往高台寺, 以往上香的人很多。
由于又要打仗，驿道上负责治安的马鹞军加紧对来往客商的盘查，以防有细作混
入，千万别招惹他们。
LONG);
   
    set("exits",([
        "south"    : __DIR__"door6",
        "north"    : __DIR__"road12",
    ])); 
    set("outdoors","xingqing");
    setup();
}

