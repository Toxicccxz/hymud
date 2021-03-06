#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
    set("short","金城关");
    set("long",@LONG
由兰州向北渡过黄河，就可看见一座坚固的城堡，墙高四丈多，青砖砌就，
周围三四里，只南面有一座城门，城门上写着：“金城边塞”四个泼墨大字。这
里是朝廷边塞的最西边了，关城以北是一片荒野，衬着远处的天都山：那里已是
西夏境地。西边也是一片荒野，有些行人正在缓缓西行。
LONG);
    set("exits",([
        "west"   : __DIR__"huangye1",
        "northeast" : __DIR__"xingqing/xing0",
        "south" : "/d/lanzhou/nroad2",
    ]));

        set("objects", ([
                "/d/city/npc/wujiang" : 1,
                "/d/city/npc/bing" : 2,
                ]) );
    
    set("outdoors","xibei");
    setup();
}

