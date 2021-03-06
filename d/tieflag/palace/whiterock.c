 inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "白石");
        set("long", @LONG
这是一块巨大的白色山石，大约可以容纳六七个人。石头的表面异常
平滑，令人惊奇的是石面上的几块黑色印痕，不知是天然而成，或是人为
的痕迹。向下望，可以看到碧兰的湖水；向上望，只见上面云雾缭绕，不
知还有多高才会到顶。
LONG
        );
    set("item_desc", ([
        "黑色印痕" : "好像是人的足印般大小，也许你可以试着踩一踩（step）。\n",
     ])); 
        set("outdoors","fengyun");
        set("coor/x",200);
        set("coor/y",-30);
        set("coor/z",30);
        setup();
} 
void init()
{
        add_action("do_climb", "climb");
        add_action("do_step", "step");
} 
int do_step(string arg)
{
        if(!arg || arg != "黑色印痕" )
                return notify_fail("你要踩什么？\n");
        message_vision(HIY "$N一脚踩在石面上的黑色印痕，只听到＂吱呀＂一声，\n崖壁上裂开了一道门户！\n"NOR, this_player());
        set("exits/enter", __DIR__"holeopen2");
        if(!this_player()->query("m_success/白石"))
        {
                this_player()->set("m_success/白石",1);
                this_player()->add("score",50);
                this_player()->add("potential",100);
                this_player()->add("combat_exp",1000);
                tell_object(this_player(),WHT"真聪明，你被奖励了！\n"NOR);
                tell_object(this_player(),WHT"50点评价，100点潜能，1000点经验。\n"NOR);
        }
        return 1;
} 
int do_climb(string arg)
{
        object  me;
        int     mlvl; 
        if(!arg || (arg != "up" && arg != "down")) {
                write("你要往上或下爬？\n");
                return 1;
        }
        me = this_player();
        if( arg == "up") {
                message_vision(HIY "\n$N小心翼翼地向上爬去，身形慢慢被云雾遮掩。\n"NOR, me);
                message_vision(HIR "\n$N手上一个没抓稳，从危崖上掉了下去！\n"NOR, me);
                me->move(__DIR__"yadi");
                me->receive_wound("qi", 50);
                me->receive_wound("jing", 50);
                me->receive_wound("jing", 50);
                message_vision(HIR "\n$N从危崖上掉了下来，重重的摔在了地上！\n"NOR, me);
                me->unconcious();
        }
        else {
                message_vision(HIY "$N小心翼翼地向下爬去，身形慢慢被云雾遮掩。"NOR, me);
                me->move(__DIR__"yadi");
        }
        return 1;
}  
