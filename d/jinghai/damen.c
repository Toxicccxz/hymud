// yuanmen 庄院大门

inherit ROOM;
void create()
{
        set("short", "庄院大门");
        set("long", @LONG
一幢高墙阔院,　朱红大门. 门梁上高悬着雕金牌匾,上书
三个大字[桃花庄]．院墙两侧整齐的栽着桃树．门前打扫的干
干净净．回望东北方，一条蜿蜒小路不知道同乡什么地方．看
来需要自己去，找找路了．
LONG
        );

        set("exits", ([
                "south"           : __DIR__"dating",
                "west"            : __DIR__"qianyuan",
                "northeast"            : __DIR__"xiaoxi",
]));
        set( "GATE_ROOM",1 );
        set( "gate_dir",(["northeast" : __DIR__"xiaoxi"]) );
        set( "close_look",@LONG
这里是桃花庄正门。现在是天色以晚，庄门已经关上了。
静悄悄的只有守卫的家丁们还警惕的站在这里。
LONG
);
        set( "gate_name","山庄大门" );


        set("objects",([
        __DIR__"npc/jiading" : 2,
]));

        set("outdoors","jinghai");
        setup();
}

