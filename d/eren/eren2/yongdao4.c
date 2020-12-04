 inherit ROOM;
#include <ansi.h> 
void create()
{
        set("short", "白石道");
        set("long", @LONG
再走数十步後，向右一转，这黑暗狭窄的洞穴，竟豁然开朗起来。石道两旁，
都砌着白玉般晶莹光滑的石块，顶上隐隐有灯光透出却瞧不见灯是嵌在那里的。
没有守卫，但暗藏杀机。
LONG
        );
        set("exits", ([ 
                "eastdown" : __DIR__"yongdao5",
                "westup" : __DIR__"yongdao3",
        ]));
        set("indoors", "eren");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
}  
int valid_leave(object me,string dir)
{
        object alert_room;
                
        if(userp(me) && dir == "eastdown")      {
                alert_room = find_object(__DIR__"yongdao3a");
                if(!objectp(alert_room)) 
                        alert_room = load_object(__DIR__"yongdao3a");           
                if (alert_room->query("trap")) {
                        message_vision(HIR"耳边忽有破空之声，几枝利矢从漆黑的角落里向$N射来！\n"NOR, this_player());
                        if (random(me->query_skill("perception",1))>100 || random(me->query_skill("dodge",1)>100))
                                message_vision(YEL"$N听风辨器，腾身而起，在间不容发之刻躲开了暗箭。\n"NOR,me);
                        else {
                                message_vision(YEL"$N躲闪不及，被射了个正着。\n"NOR,me);
                                me->receive_wound("jing",me->query("eff_jing")/3);
                                me->receive_wound("qi",me->query("eff_qi")/3);
                                me->receive_wound("jing",me->query("eff_jing")/3);
                        }                                       
                }       
   }
        return 1;
}    
