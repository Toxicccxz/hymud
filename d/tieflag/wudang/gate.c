 inherit ROOM;
void create()
{
        set("short", "真武山门");
        set("long", @LONG
一座巍巍的山门，上面书写着“真武山”几个苍劲的大字。武当
山又名太和山，峰奇峦秀，涧险岩危，自古就被誉为“天下第一仙山”。
唐代起，几乎历代封建皇帝都极力扶植武当道教，到明朝，真武山以
“治世玄岳”的崇高地位成为全国道教的活动中心。远远望去，但见
群峰挺立，卓立云海。
LONG
        );
        set("exits", ([
                "north" : __DIR__"road1",
                "southup" : __DIR__"road2",
        ]));
        set("outdoors", "wudangfy");
        set("coor/x",100);
        set("coor/y",-80);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}       
