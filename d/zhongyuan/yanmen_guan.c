// yanmen_guan.c
inherit ROOM;

void create()
{   
    set("short","雁门关");
    set("long",@LONG
雁门关建在两山之间，东西皆是百丈峭壁，高不可攀，人称惟插雁双翅可飞
焉，故称“雁门”。如今的关隧每年修葺，城高七丈，门洞三重，各安有一块千
斤闸；城上关楼高耸，一队队士兵背挎强弓，一身铠甲在阳光下闪闪发光。关内
是一条长街，东西各有些店铺，各行买卖俱全，倒也热闹的如州府一般。出关就
是应、塑、云、阳各州，现在都被辽军占领着。
LONG );
    set("exits",([
        "southeast": __DIR__"daizhou" ]) );
    set("outdoors","zhongyuan");
    setup();
}

