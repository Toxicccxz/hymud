 inherit ROOM;
void create()
{
        set("short", "南北大道");
        set("long", @LONG
这条干线上商旅不绝。一条车痕向南方和北方伸展。
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"road1",
//  "south" : "/d/fycycle/fynorth",
]));
        set("outdoors", "laowu");
        set("coor/x",0);
        set("coor/y",1000);
        set("coor/z",0);
        setup();
}
void init()
{
        add_action("do_go","go"); 
} 
int do_go()
{
if(random(3)){
this_player()->move(this_object());
return 1;
}
}      
