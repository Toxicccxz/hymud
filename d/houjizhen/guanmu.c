// guanmu2.
// by dicky

inherit ROOM;

void create()
{
        set("short","灌木丛");
        set("long", @LONG
松林边上的灌木越来越多，路面上的荆棘不时的把你的手脚划破，一些长
草中常常倏的蹿出一条毒蛇，让你心惊胆颤。
LONG
        );

	set("outdoors", "houjizhen");

        set("exits", ([
                "southeast" :__DIR__"songlin2",
                "northup" :__DIR__"shanlu5",
        ]));
        
        setup();
        replace_program(ROOM);

}


