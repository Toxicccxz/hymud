// /d/map/zhongyuan/yunhe4.c
// by lala&lnwm, 1997-12-11
inherit ROOM;

void create()
{   
    set("short","扬子津");
    set("long",@LONG
真楚运河在这里流向西南的真州，因为真州又称仪征、仪真，故此段运河又
改名叫做仪扬运河，大批运送淮盐的船只都是从此路驶向真州去交换上行而来的
粮船所运送的漕米的。因而真州现在愈发的繁荣，大有取代扬州的势头，如果这
样安定的局面再持续百年的话，真州恐怕就会取代扬州成为天下最繁华的商埠了。
    这里还有一条支流，称为伊娄河，直接向南流到瓜洲入长江，成为从扬州入
江最近的水路。因为这里有真楚运河、仪扬运河和伊娄河三条水系交汇，所以又
称做三汊河。
LONG );
    set("exits",([
        "north"     : __DIR__"yunhe3",
        "south"     : __DIR__"yilou_he",
//      "southwest" :
    ]));                    
    set("outdoors","zhongyuan");
    setup();
}

