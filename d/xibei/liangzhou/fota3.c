//fota3.c

inherit ROOM;

void create()
{
        set("short","佛塔顶");
        set("long", @LONG
你爬到了佛塔的顶层，这里供奉着一座如来佛祖的金身塑像，供坛里上好
的檀香送出飘渺的烟雾。塔顶已经高过了凉州的城关，凭窗远眺，你仿佛已经
接近了湛蓝的天空。白云。
LONG
        );
        set("outdoors","liangzhou");
        set("exits", ([ 
                "down"          :       __DIR__ "fota2",                
                ])
        );
//      replace_program(ROOM);
        setup();
}

