// kedian.c
// by dicky

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
	set("short","有间客店");
	set("long", 
"这是一家客栈，虽然它是侯集镇唯一一家客栈，但是这里显得格外的冷清
，只有几位江湖人物在里面低着头喝着酒，他们见你进来，只是略微的抬起头
，用异样的眼光扫视了你一下，便又低下头去喝着自己的酒，仿佛你已经不再
存在。店小二没有你预料的那样热情，他只是远远的站在柜台前，用眼睛细细
打量着你，见你也看着他，他才转过眼神，慢慢的欣赏着自己的手指。客栈正
面的墙上挂着一块醒目的牌子(paizi)。\n");
	set("valid_startroom", 1);
        set("no_sleep_room",1);
	set("item_desc", ([
		"paizi" : "楼上雅房，每夜五两白银。\n",
	]));
	set("objects", ([
		__DIR__"npc/xiaoer" : 1,
	]));

	set("exits", ([
	        "south" : __DIR__ "shilu1.c",
		"up" : __DIR__"kedian2",
	]));
	setup();
}

int valid_leave(object me, string dir)
{

	if ( !me->query_temp("rent_paid") && dir == "up" )
	return notify_fail("怎么着，想白住啊！\n");
	if ( me->query_temp("rent_paid") && dir == "west" )
	return notify_fail("客官已经付了银子，怎么不住店就走了呢！旁人还以为小店伺候不周呢！\n");
	return ::valid_leave(me, dir);
}
