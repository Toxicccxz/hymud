// room: xing2.c
//by lnwm 97-09-12


inherit ROOM;

void create()
{
        set("short", "黄河沿岸");
        set("long", @LONG
越过天都山, 前面的道路越发艰苦. 黄河连年的泛滥将河道两侧冲刷的异常
松软. 几乎没有道路. 河岸两侧是险峻的高山, 山峰相扣, 挺拔入天. 再往前就
进入西夏国的国境了. 越往北越荒凉, 只有沉默的黄河在慢慢流淌. 
LONG
        );
    set("exits", ([ 
                "southwest"     :       __DIR__ "xing1",
                "northeast"     :       __DIR__ "xing3",
        ]));
        set("outdoors","xingqing");
        setup();
}                       


