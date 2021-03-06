// Room: /d/jinghai/moon36.c

inherit ROOM;

void create()
{
	set("short", "牢房甬道");
	set("long", @LONG
这里是一条狭窄的过道，它是通向各个牢房得通道。四壁用
大块的青石砌成。甬道内只有墙壁上的小油灯，格外昏暗。偶尔
会听见还有滴答滴答的流水声音。甬道北侧有一扇[天牢]门。里
面不时传来大声得喊叫。令人毛骨悚然。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"moon31",
]));

	setup();
}
void init()
{
      add_action("do_open", "open");
}

int do_open(string arg)
{
	object me,room;

	me= this_player();
	if( !arg && arg != "铁闸" && arg != "zha")
		return notify_fail("要打开什么？\n");

	if( !objectp(present("tian key", me)) ) 
		return notify_fail("铁闸锁着呢，不用钥匙恐怕打不开。\n");

	if(!room = find_object(__DIR__"moon35"))
		room = load_object(__DIR__"moon35");
	if(!room)
		return notify_fail("铁闸无法打开。\n");

	if(!room->query("exits/out"))
	{
		room->set("exits/out",__FILE__);
		tell_room(room,"只听喀嚓一声，铁闸慢慢升起。\n");
	}
	set("exits/enter", __DIR__"moon35");

	tell_room(__FILE__,"只听喀嚓一声，铁闸慢慢升起。\n");
	call_out("close",5);
	return 1;
}

void close()
{
	object room = find_object(__DIR__"moon35");

	if(query("exits/enter"))
	{
		tell_room(__FILE__,"只听喀啦喀啦几声巨响铁闸自动关闭了。\n");
		delete("exits/enter");
	}

	if(!room)
		room = load_object(__DIR__"moon35");

	if(room && room->query("exits/out"))
	{
		room->delete("exits/out");
		tell_room(room,"只听喀啦喀啦几声巨响铁闸缓缓地关闭了。\n");
	}

}
