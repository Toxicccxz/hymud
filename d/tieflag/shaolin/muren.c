 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "木人巷");
        set("long", @LONG
东林木人巷了，这里是出东林的第一关，经过多年苦修，能到
过木人巷的都已是东林精英，江湖上都是一流高手了。这里仅有一
条窄窄的过道，两侧全是木人，由机关控制，善使东林七十二绝技，
出手极重。
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"banruo",
  "north" : __DIR__"muma",
]));
        set("outdoors", "shaolinfy");
        set("no_magic",1);
        set("coor/x",-210);
        set("coor/y",390);
        set("coor/z",70);
        setup();
}
void init()
{
        delete("exits");
        if(userp(this_player())){
                remove_call_out("attack");
                call_out("attack",1+random(2),this_player());
        }
}  
int attack(object me)
{
        object muren;
        muren= new(__DIR__"npc/muren");
        muren->set("combat_exp",2000000+30000*random(100));
        muren->set_temp("apply/damage",500+50*random(10));
        muren->move(this_object());
        if (environment(me)==this_object())
                COMBAT_D->do_attack(muren,me);
   me->set_temp("last_damage_from","力闯东林木人巷未遂，被木人打死了。");
        if(present(me,this_object()) && random(9)){
                destruct(muren);
                call_out("attack",1+random(2),me);
        }
        else    {
                destruct(muren);
                if(present(me,this_object()))
                        set("exits/north", __DIR__"muma");
                me->delete_temp("last_damage_from");
        }
} 
