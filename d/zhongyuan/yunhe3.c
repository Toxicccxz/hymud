// /d/map/zhongyuan/yunhe3.c
// by lala, 1997-12-11
inherit ROOM;

void create()
{   
    set("short","真楚运河边");
    set("long",@LONG
真楚运河绕过扬州，继续流向长江。河面上大小船只百舸争流，一片兴旺景
象。岸边绿柳拂风，相传这些柳树是隋炀帝杨广游幸江都的时候栽种的，因而又
称为：“杨柳”。运河再向南，就是运河同伊娄河交叉的扬子津。
LONG );
    set("exits",([
        "north"     : __DIR__"yunhe2",
        "south"     : __DIR__"yunhe4",
    ]));                    
    set("outdoors","zhongyuan");
    setup();
}

