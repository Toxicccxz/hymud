// Room: /d/jinghai/zhuque4.c

inherit ROOM;

void create()
{
	set("short", "靖海朱雀堂大门");
	set("long", @LONG
这里是一座很大的庄院。气派宏伟的靖海朱雀堂大门耸立在
数十级台阶上，高高的门楼上，青铜雕成的双燕穿云图栩栩如生
，深红色大门上的铜环磨得锃亮，一股肃穆之气油然而生，你不
禁整了整衣襟，似乎有人正在暗中查看你的一举一动。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"zhuque1",
  "south" : __DIR__"zhuque6",
]));
        set("outdoors","jinghai");

	setup();
	replace_program(ROOM);
}
