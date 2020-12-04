// midao2.c
// by dicky

inherit ROOM;

void create()
{
  set("short","秘室");
  set("long", @LONG
你忽觉眼前一亮，真是别有洞天，你来到一间布置非常精美的秘室。
靠墙有一张床，上面躺着一个中年和尚，见你突然闯进来，和尚马上从
床上一跃而起，旁边的女孩受到惊吓，发出锐耳的尖叫声，她躲在床角
，混身直打哆索，用一双哀求的眼神看着你。
LONG  );

	set("exits",([
	"west"  :__DIR__"midao1",
	]));

	set("sleep_room", 1);

        set("objects",([
		__DIR__"npc/xiaojie" : 1,
		__DIR__"npc/heshang" : 1,
	]));

	setup();
	replace_program(ROOM);
}
