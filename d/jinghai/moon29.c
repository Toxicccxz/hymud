// Room: /d/jinghai/moon29.c

inherit ROOM;

void create()
{
	set("short", "地牢看守房");
	set("long", @LONG
这里是看守们平常呆的地方，狭小而又昏暗的小屋内，码放
着一张小桌。几个空酒壶歪斜的放在桌子上。几个看守在这里昏
昏欲睡的坐着，墙上挂着个[刑具]盒子，是用来放锁犯人的工具
之类的东西。一道[铁闸]挡住了下到地牢的去路，没有钥匙是不
可能进去的。
LONG
	);
       set("item_desc", ([ 
	"铁闸" : "这是一个坚固大铁闸，铁闸旁边有一个钥匙孔。\n",
]));
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"moon28",
]));

	setup();
}
void init()
{
        add_action("do_open","open");
}

int do_open(string arg)
{
	object me,room;

	me= this_player();
	if( !arg && arg != "铁闸" && arg != "zha")
		return notify_fail("要打开什么？\n");

	if( !objectp(present("tie key", me)) ) 
		return notify_fail("铁闸锁着呢，不用钥匙恐怕打不开。\n");

	if(!room = find_object(__DIR__"moon30"))
		room = load_object(__DIR__"moon30");
	if(!room)
		return notify_fail("铁闸无法打开。\n");

	if(!room->query("exits/up"))
	{
		room->set("exits/up",__FILE__);
		tell_room(room,"只听喀嚓一声，头上的铁闸慢慢升起，露出了向上的出口。\n");
	}
	set("exits/down", __DIR__"moon30");

	tell_room(__FILE__,"只听喀嚓一声，铁闸慢慢升起，露出了向下的出口。\n");
	call_out("close",5);
	return 1;
}

void close()
{
	object room = find_object(__DIR__"moon30");

	if(query("exits/down"))
	{
		tell_room(__FILE__,"只听喀啦喀啦几声巨响铁闸自动关闭了。\n");
		delete("exits/down");
	}

	if(!room)
		room = load_object(__DIR__"moon30");

	if(room && room->query("exits/up"))
	{
		room->delete("exits/up");
		tell_room(room,"只听喀啦喀啦几声巨响头上的铁闸缓缓地关闭了。\n");
	}

}
