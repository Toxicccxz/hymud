 inherit ROOM;
void create()
{
        set("short", "十八盘");
        set("long", @LONG
青石阶，此是上天街的必经之路，道路狭窄，直上而去，宛若天神垂顾
世人，放下的梯子，又好似天神贪恋人间美景，来凡间戏耍的捷径。
LONG
        );
        set("exits", ([ 
  "up" : __DIR__"nantian",
  "down" : __DIR__"duisong",
]));
        set("outdoors", "taishanfy");
        set("coor/x",320);
        set("coor/y",2390);
        set("coor/z",110);
        setup();
}
