//writen by lnwm
//chaimen.c

inherit ROOM;

void create()
{
        set("short", "柴门");
        set("long", @LONG
你来到了一个农家小院的门口,小小的柴门紧闭着,整个院落里静悄悄
的.门两侧用树枝编成的门框上还挂着一幅正月里挂的对联,只是风吹日晒
使红纸退尽了颜色,墨迹也模糊了.你喊了两声,没人答应,看来主人都不在
家.
LONG
        );
        set("exits", ([ 
            "southeast"     :       __DIR__ "lroad3",
        ]));
        set("item_desc", ([
                "north" : "用树的枝条编的小门,风一吹过就发出呀呀的响声\n",
                "门": "用树的枝条编的小门,风一吹过就发出呀呀的响声\n",
                "door": "用树的枝条编的小门,风一吹过就发出呀呀的响声\n",

        ]) );
        set("outdoors","lnwm");
        setup();
}
void init()
{
        add_action("do_open",({"open", "pull"}) );
}
int valid_leave(object me,string dir)
{
    if( dir == "north" && !this_object()->query("exits/north") )
        write("北面一扇小门正关着.\n");
    return ::valid_leave(me,dir);
}
int do_open(string arg)
{
        object obj;
        object me;
        if(!arg || arg=="")
        {
                write("你要打开什么？\n");
                return 1;
        }
        if( arg == "men" || arg == "door" || arg == "门")
        {
                me = this_player();
                message_vision("$N把门轻轻地一拉,门就吱呀一声开了\n", me);
                if( !query("exits/north") )
                {
                set("exits/north", __DIR__ "yuanluo");
                call_out("close_path", 3);
                }
        return 1;
        }
        else
        {
                write("你不可以拉"+arg+"\n");
                return 1;
        }
}
void close_path()
{
        if( !query("exits/north") ) return;
        message("vision","一阵风轻轻吹过,小门呀的一声就合上了\n",this_object() );
        delete("exits/north");
}


