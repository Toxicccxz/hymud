//chadian.c

inherit ROOM;

void create()
{
        set("short","雅叶斋");
        set("long", @LONG
一家中原人开的茶叶铺子，你一进店，就闻到一股浓浓的茶香。店主
正忙着将刚从窖中搬出的茶叶分装在不同大小的罐子里，好象没看见你进
来。屋子沿墙有一排竹凳，还有一张长长的桌子，桌子中间放着几套茶具
你可以坐下来慢慢地品一壶碧罗春，再和店主聊一聊茶经。
LONG

        );
        set("exits", ([ 
                "north"         :       __DIR__ "lroad5",            
                ])
        );
        set( "objects",([
            __DIR__"npc/waiter":1,
        ]) );
//      replace_program(ROOM);
        setup();
}

