//Writen by lnwm
//nongjia1.c

inherit ROOM;

void create()
{
    set("short", "农家");
    set("long", @LONG
这是一家简陋的农居，房子用木头做四壁，用茅草搭的顶棚，但屋内却
十分得整洁，靠门立着几样农具，一位村妇在门口坐着，不时停下手里的活
计向屋外张望一下。屋里还有一个男子在忙碌着，显然是这里的男主人。
LONG
    );
    set("exits", ([
        "southeast"     :    __DIR__ "lroad5",
        ]));
    set("objects", ([           
        __DIR__ "npc/man" : 1,
        __DIR__ "npc/woman" : 1,
    ]) );
    setup();
}


