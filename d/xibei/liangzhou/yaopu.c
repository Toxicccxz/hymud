//yaopu.c

inherit ROOM;

void create()
{
        set("short","京云药铺");
        set("long", @LONG
凉州最大的一家药铺，你一进门，一股药香迎面扑来，宽宽的桐木柜
台上摆着许多的坛坛罐罐，柜台后面是一个巨大的药柜，上面有上百个装
药材的小匣子。店主笑容可鞠地站在柜台的后面招呼来往的客人。凉州的
药材和它的马一样，十分得出名。吸引了来自中原和西域的许多商人。如
果你恰好路过这里，不妨带两味有特色的回去。
LONG
        );
        set("exits", ([ 
                "south"         :       __DIR__ "lroad2",
                ])
        );
//      replace_program(ROOM);
        setup();
}

