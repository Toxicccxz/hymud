 // Room: damen.c --- by MapMaker
inherit ROOM; 
void create()
{
        set("short", "无垢山庄大门"); 
        set("long", @LONG
这里便是名满天下的无垢山庄了.自从二百年前连家远祖赤手空拳创建了无垢山
庄后，直到如今,只要是无垢山庄的子弟,无论走到何处,都势必被江湖中人所景仰。
因为在这个侠义之道愈来愈衰败的今天,大概只有『无垢山庄』可算是真正当之无愧
的"侠义无双"了.
LONG); 
        //{{ --- by MapMaker
        set("exits",([
        "south":__DIR__"yushijie1",
    "enter":__DIR__"dating",
        ]) );
        //}}
        set("outdoors", "taishanfy");
        set("coor/x",310);
       set("coor/y",2430);
        set("coor/z",150); 
        setup();
        replace_program(ROOM);
}   
