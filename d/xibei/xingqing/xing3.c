// room: xing3.c
//by lnwm 97-09-12


inherit ROOM;

void create()
{
        set("short", "黄河沿岸");
        set("long", @LONG
穿行在西北的崇山峻岭之中, 前面的道路越发艰苦. 黄河连年的泛滥将河道
两侧冲刷的异常松软. 几乎没有道路. 河岸两侧是险峻的高山, 山峰相扣, 挺拔
入天. 再往前就进入西夏国的国境了. 越往北越荒凉, 只有沉默的黄河在慢慢流
淌. 
LONG
        );
    set("exits", ([ 
                "southwest"     :       __DIR__ "xing2",
                "northeast"     :       __DIR__ "xing4",
        ]));
        set("outdoors","xingqing");
        setup();
}                       


