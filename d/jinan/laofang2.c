 inherit ROOM;
void create()
{
    set("short", "牢房");
        set("long", @LONG
这里是关押犯人的地方，不到十尺见方的牢房中没有床榻被褥，只有几堆枯黄
散发着难闻气味的稻草，不时的有大老鼠从你的脚下跑过，不知从那里飘来的腐臭
之气充斥着整个牢房。死寂黑暗的牢房里，不时从远处传来犯人的呼救声。
LONG
        );
    set("indoors", "jinan");
    set("coor/x",70);
    set("coor/y",1870);
    set("coor/z",0);
        set("valid_startroom",1);
        set("no_magic", 1);
    set("exits", ([ /* sizeof() == 3 */
        "north" : __DIR__"dalao1",
    ]));
        setup();
}
void init()
{
        this_player()->set("startroom", base_name(this_object()));

} 
