 inherit ROOM;
void create()
{
        set("short", "南北大道");
        set("long", @LONG
这是一条主要大道。它上穿白山黑水，直达松花江。再通江南海口。
这条干线上商旅不绝。一条车痕向南方和北方伸展。
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"road5",
  "south" : __DIR__"road1",
  "east" : "/d/tieflag/qianfo/road1",
 "westup" : "/d/taoguan/sroad",
]));
        set("outdoors", "laowu");
        set("coor/x",0);
        set("coor/y",2000);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
} 
