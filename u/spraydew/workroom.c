// Room: /d/wizard/wizard_room.c

inherit ROOM;

void create()
{
	set("short", "星璇的休息室");
	set("long", @LONG
这里就是星璇的休息室了，居然四周墙壁光光，一点装修都没有
可见星璇有多懒了。
LONG );

	set("exits", ([ /* sizeof() == 1 */
	 	"down" : "/d/city/wumiao",
                "west" : "/d/wizard/wizard_room",
                "east" : "/d/wizard/guest_room",
	 	"north": "/d/death/outjail",
	 	"south": "/d/wizard/robot_court",
	 "up" : "/u/hxsd/neishi",
                "qujing" : "/d/jyguan/ximen",
	]));
 // set("objects", ([ /* sizeof() == 4 */
 //"/u/hxsd/npc1" : 1,
 //"/u/hxsd/npc2" : 1,

 //]))

	set("valid_startroom", "1");

	set("no_clean_up", 0);
	setup();

       call_other("/clone/board/wiz_b", "???");
	replace_program(ROOM);
}
