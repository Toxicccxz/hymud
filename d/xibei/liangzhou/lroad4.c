//lroad4.c

inherit ROOM;

void create()
{
        set("short","沙土路");
        set("long", @LONG
凉州城的中心街道，虽适逢战乱，但凉州城内倒依然平静，行商走贩
来来往往，整条大街尘土飞扬,十分热闹。 这里是西夏辖区，许多个民族
在这里杂居，所以街上不同民族各种装束的人你都能见到。不过你发现还
是衣冠博带的汉人据多，往东就是凉州城的中心,一个很大的集市。南边是
一家外国人开的玉器店，北边是一家客栈。
LONG
        );
        set("outdoors","liangzhou");
        set("exits", ([ 
                "east"          :       __DIR__ "center",
                "west"          :       __DIR__ "lroad5",
                "south"         :       __DIR__ "yudian",
                "north"         :       __DIR__ "kezhan",
                ])
        );
//      replace_program(ROOM);
        setup();
}

