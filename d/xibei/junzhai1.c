inherit ROOM;
void create()
{
    set("short","军寨");
    set("long",@LONG
西边是一座大军寨，周围以巨木垒墙，方圆将近一里，里面可见大帐，木屋
布置井然有序，一队队骑兵在空场上穿过。寨外是一片高粱地，几百匹军马在寨
南小河边饮水，吃草。一条驿道贴寨而过，向西北延伸。
LONG);
    set("exits",([
        "east"   : __DIR__"tuntian2",
        "north"  : __DIR__"tuntian3",
    ]));
 set("outdoors","xibei");
    setup();
}

