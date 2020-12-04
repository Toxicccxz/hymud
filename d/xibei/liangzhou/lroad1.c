//lroad1.c

inherit ROOM;

void create()
{
        set("short","沙土路");
        set("long", @LONG
东边就是凉州的东门,出东门往东穿过河西走廊就能到达兰州,从那里
进入中原.虽说凉州是边塞要镇,但城中道路并不平整,车辆走过时,卷扬起
地上的沙土.到春秋狂风大作时,整个城中黄沙满天, 构成这边塞关隘的独
特风景.南北两侧是驿站,供执行公务的官差歇脚和更换座骑, 不时有快马
从门内急驰而出.
LONG
        );
        set("outdoors","liangzhou");
        set("exits", ([ 
                "north"         :       __DIR__ "yizhan1",
                "south"         :       __DIR__ "tudimiao",
                "west"          :       __DIR__ "lroad2",
                "east"          :       __DIR__ "dongmen",
                ])
        );
//      replace_program(ROOM);
        setup();
}

