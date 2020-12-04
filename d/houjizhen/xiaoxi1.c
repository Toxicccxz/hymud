// xiaoxi1.c
// by dicky

inherit ROOM;

void create()
{
        set("short", "山中小溪");
        set("long", @LONG
这是一条山中小溪，旁边长满了不知名的野花野草，周围安静极了，只
有小河流水在孱孱作响。一些口渴的动物在溪边喝水，远处偶尔传来男女欢
乐的嘻笑声，你不禁感到纳闷，这天荒地冻的地方，哪里来的欢笑声呢？你
不禁想探出源头，找出究竟。
LONG
        );
        
	set("outdoors", "houjizhen");
	set("resource/water", 1);

        set("exits", ([           
                "eastdown" : __DIR__"xiaoxi",
		"westup" : __DIR__"pubu",
        ]));


        setup();
	replace_program(ROOM);
}
