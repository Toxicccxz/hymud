 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "荒原");
        set("long", @LONG
干燥的土地，秋风卷起满天黄沙，在无边无际的荒原上咆哮而过。本没有路，
来往的行人车马多了，踏出一条三尺宽的车道，板结的地面上满是车辙划过的痕迹。
偶尔几骑快马驰过，奔向前方的小镇。道路左侧是一排高大的白杨树，象哨兵似傲
然地聳立。
LONG
        );
        set("exits", ([ 
                "east" : __DIR__"wild1",
                //"northwest" : __DIR__"wild3",
                "southwest" : __DIR__"woods",
        ]));
        set("objects", ([
        ]) );
        set("outdoors", "biancheng");
        set("coor/x",-1080);
        set("coor/y",100);
        set("coor/z",0);
        setup();
} 
void reset() {
        object badguy,*inv,room,boss,village;
        int count,i;
        mixed current_time;
        string *boss_name=({"baimian langzhong","one eye","tu laohu",});
        string boss1;
        
        ::reset();
        
        room=this_object();
        current_time=NATURE_D->get_current_time();
        
        inv=all_inventory();
        for (i=0;i<sizeof(inv);i++) {
                if (inv[i]->query("group")=="longhuzhai")
           if (random(8)==0) {
                        if (inv[i]->query("id")=="bandit") {
                                inv[i]->command("say 天晓也，扯呼。");
                                message_vision("$N一头钻进南边的树林里消失了。\n",inv[i]);
                                destruct (inv[i]);
                        } else {
                                room=find_object("/d/biancheng/village");
                                if (!room) destruct (inv[i]);
                                else {
                                        inv[i]->move(room);
                                        message_vision("$N从山寨外面走了进来。\n",inv[i]);
                                }
                        }
                        
                } else count++;
        }
        
        if (random(8)==0) {
                if (!count) {
                        for (i=0;i<3;i++)       {
                                badguy=new(__DIR__"npc/bandit");
                                badguy->set("attitude", "friendly");
                                badguy->move(room);
                        }
                        message_vision("只听刷拉拉一阵响，路旁的树林里窜出了几个土匪。\n",badguy);
                        badguy->command("say 月黑风高夜，杀人放火天。");
                }       
                if (!present(boss_name[0],room) && !present(boss_name[1],room) && !present(boss_name[2],room))
                for (i=0;i<6;i++) {
                        boss1=boss_name[random(sizeof(boss_name))];
                        boss=find_living(boss1);
                        if (boss && !boss->is_fighting()) {
                                badguy=present("bandit",room);
                                message_vision(CYN"$N诚惶诚恐地说：大王也来了。\n"NOR,badguy);
                                message_vision(CYN"$N一边往外走一边说，“我去看看孩儿们生意做的怎样。”\n"NOR,boss);
                                boss->move(room);
                                boss->command("pat bandit");
                                return;
                        }
                }       
   }
        return;
}  
int valid_leave(object obj, string dir){
        int i;
        object *inv;
        if(dir == "east" || dir == "southwest"){
                if (obj->query_temp("wild2_pass") || obj->query("combat_exp")<1000000) return 1;
                inv = all_inventory(this_object());
                for (i=0;i<sizeof(inv);i++){
                        if (userp(inv[i]) ||!inv[i]->is_character()
                                ||inv[i]->is_corpse()) 
                                        continue;
                        if (inv[i]->query("group")=="longhuzhai") 
                                return notify_fail(inv[i]->name()+"说：“此山是我开，此书是我栽，要打此路过，留下买路钱！”\n");
                }
        }       
        return 1;
}
