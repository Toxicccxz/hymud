 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "掖门");
        set("long", @LONG
这是一座小门，平常都是关着的，和马道相连，马匹车辆可以从这里直
达天王殿，八字墙和正门相掩映，别有一番风味。这里进去便是长长的马道。
LONG
        );
        set("exits", ([ 
  "westdown" : __DIR__"shandan",
  "northwest" : __DIR__"yingbi",
]));
        set("objects", ([
                __DIR__"npc/monk4" : 2,
       ]) );
        set("outdoors", "shaolinfy");
        set("coor/x",-200);
        set("coor/y",160);
        set("coor/z",40);
        setup();
}
int valid_leave(object me, string dir)
{
        object *inv;
        object ob;
        int i;
        if( userp(me))
        {
        if( me->query("class") != "shaolin" && dir == "northwest" && ob=present("shaolin monk", this_object()))
        {
                inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++)
                        if(inv[i]->query("shaolin_cloth") && (int)inv[i]->query("equipped"))
                                return 1;
                return notify_fail(ob->name()+"向你拱手道：没有游山牌，非东林弟子不可入内！！\n");
        }
        return 1;
        }
        else return 1;
} 
void reset()
{
        object *inv, ob;
        string *sname=({"圆们","圆心",});
        int i;
        ::reset();
        ob=present("shaolin monk", this_object());
        if(ob) ob->set("name","圆们");
        if(ob) ob->set("chat_chance_combat",50);
        inv = all_inventory();
        if(ob)  {
                ob->dismiss_team();
                for(i=0;i<sizeof(inv);i++)
                        if(inv[i]->query("id") == "shaolin monk" && inv[i] != ob)
                        if(i<=1) {
                        ob->add_team_member(inv[i]);
                        inv[i]->set("name",sname[i]);
                        inv[i]->set("chat_chance", 2);
                        inv[i]->set("chat_msg", ({
                                inv[i]->name()+"说道：听说昨天又有人从木人巷打下山去了！\n",
                        }) );
                }
        }
} 
