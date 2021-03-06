// 楚州文通塔顶层 /d/city/chuzhou/wentongta3.c
// by lala&lnwm, 1997-12-05

#define LOOK_CMD    "/cmds/verb/look"

inherit ROOM;
#include <ansi.h>

int look_dukou( object me );
int look_diaotai( object me );
int look_beimen( object me );
int look_tianbaolu( object me );
int look_beishi( object me );
int look_fumaxiang( object me );

void create()
{
    set("short", WHT"文通塔"NOR);
    set("long", @LONG
文通塔的顶层上居然有不少的游人，他们都挤在栏杆边上眺望楚州城的风光，
也有些人焦急的张望从淮河渡口到这里的大路，看看有没有自己正在等待的人。
从这里你可以看到淮河渡口、钓台、楚州北门、天宝路、北市以及驸马巷所发生
的一切事情。
LONG
    );
    set("not_startroom", 1);
    set("no_kill",  "yangzhou");
    set("detail", ([
        "淮河渡口" : (:look_dukou    :),
        "钓台"     : (:look_diaotai  :),
        "楚州北门" : (:look_beimen   :),
        "天宝路"   : (:look_tianbaolu:),
        "北市"     : (:look_beishi   :),
        "驸马巷"   : (:look_fumaxiang:),
    ]));        
    set("exits", ([
        "down"      : __DIR__"wentongta2",
    ]));
    set("objects", ([
    ]));
    setup();
}

int look_dukou( object me )
{
    object ob;
    
    if( !ob = find_object(__DIR__"dukou") )
        ob = load_object(__DIR__"dukou");
    message_vision(YEL"\n你极力远望，只看见：\n\n"NOR,me);
    LOOK_CMD->look_room(me, ob);
    return 1;
}

int look_diaotai( object me )
{
    object ob;
    
    if( !ob = find_object(__DIR__"diaotai") )
        ob = load_object(__DIR__"diaotai");
    message_vision(YEL"\n你极力远望，只看见：\n\n"NOR,me);
    LOOK_CMD->look_room(me, ob);
    return 1;
}

int look_beimen( object me )
{
    object ob;
    
    if( !ob = find_object(__DIR__"bei_men") )
        ob = load_object(__DIR__"bei_men");
    message_vision(YEL"\n你极力远望，只看见：\n\n"NOR,me);
    LOOK_CMD->look_room(me, ob);
    return 1;
}

int look_tianbaolu( object me )
{
    object ob;
    
    if( !ob = find_object(__DIR__"tianbao_lu") )
        ob = load_object(__DIR__"tianbao_lu");
    message_vision(YEL"\n你极力远望，只看见：\n\n"NOR,me);
    LOOK_CMD->look_room(me, ob);
    return 1;
}

int look_beishi( object me )
{
    object ob;
    
    if( !ob = find_object(__DIR__"beishi") )
        ob = load_object(__DIR__"beishi");
    message_vision(YEL"\n你极力远望，只看见：\n\n"NOR,me);
    LOOK_CMD->look_room(me, ob);
    return 1;
}

int look_fumaxiang( object me )
{
    object ob;
    
    if( !ob = find_object(__DIR__"fuma_xiang") )
        ob = load_object(__DIR__"fuma_xiang");
    message_vision(YEL"\n你极力远望，只看见：\n\n"NOR,me);
    LOOK_CMD->look_room(me, ob);
    return 1;
}
