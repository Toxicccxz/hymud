 inherit ROOM;
void create()
{
        set("short", "坟场");
        set("long", @LONG
阴惨惨的夜色，笼罩着阴惨惨的大地，这儿孤零零地有座十米见方的坟冢，四
周有石人石马，显然主人是附近的富绅。但是现在石人石马已经缺头断腿，坟头上
长满了荒草，见人走近，几只乌鸦呱呱地一哄而散。
LONG
        );
        set("outdoors", "biancheng");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);

        set("exits", ([
                "north" : __DIR__"cemetery6",
        ])); 
        setup();
}  
