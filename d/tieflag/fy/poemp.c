#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "探花诗台");
        set("long",  
"风云中的老老少少大都有吟诗对词的雅好。只要稍有灵感，就会带着笔墨到这
里来酝酿，等到灵光乍现那霎那，奋笔急书，以求千古名句。诗台正中朱笔入木狂
草：" + YEL"  
                       今日有酒今朝醉，
                       哪管它日剑割头！
                                       阿铁狂舞于酒后失意时。
"NOR
        );
        set("exits", ([ /* sizeof() == 4 */
          "south" : __DIR__"wcloud1",
          "up": __DIR__"poemp2",
]));
        set("objects", ([
        __DIR__"npc/yaren" : 1,
        __DIR__"npc/prince" : 1,
                        ]) );
        set("no_death_penalty",1);
        set("no_study",1);
        set("coor/x",-10);
        set("coor/y",1);
        set("coor/z",0);
        setup();
//        call_other( "/obj/board/poem_b", "???" );
}   
