//road19.c.驿道
//date:1997.8.26
//by dan

inherit ROOM;

void create()
{
    set("short","驿道");
    set("long",@LONG
脚下是黄土铺成的路面，整齐干净，不时有行人从身边擦肩而过. 周围建筑
较少, 只有一些供路人休息的凉棚, 现在也被巡查的马鹞军占据了. 军队出征都
从这里经过，这条驿道是都城和外界联系的交通要道。远处尘土飞扬，一队队马
鹞军乘骑而来，惊得行人四散奔逃。往南就是承天寺，在这里已经可以看见塔了。                                     
LONG);
   
    set("exits",([
        "south"   : __DIR__"road27",
        "east"    : __DIR__"road18",
        "west"    : __DIR__"door4",
    ]));
    set("objects",([
         __DIR__"npc/bing2" : 2,
    ]));
    set("outdoors","xingqing");
    setup();
}

