//dadian1.c.大殿
//date:1997.8.26
//by dan  

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short",YEL"大殿"NOR);
    set("long",@LONG
壮丽的寺院，这里按照中原的风格，飞檐重阁，用的是金碧辉煌的琉璃瓦，
在高原的阳光下宛如一座黄金寺院。大殿正中央供着几尊佛像，中间的一尊一手
拈花，一手平伸，脸上带着似笑非笑的神情，正是释伽牟尼佛。当今天子信奉佛
教，不仅自己执礼甚勤，还要求西夏子民也尊奉佛教，所以这里的香火很盛。放
香烛的神龛已经被烟火熏得变成了深黑色，表明这里人来人往是多么兴盛。神龛
前摆放着几个破旧的蒲团，专供信徒们顶礼膜拜。
LONG);
   
    set("exits",([
        "north"   : __DIR__"qiandian1",
        "south"   : __DIR__"tianjing1",
    ])); 
    set("objects", ([
          __DIR__"npc/heshang" : 1,
    ]) );
    setup();
}

