// 楚州扬威镖局 /d/city/chuzhou/biaoju.c

inherit ROOM;

#include <ansi.h>

void create()
{
    set("short", YEL"扬威镖局"NOR);
    set("long", @LONG
楚州的扬威镖局说是镖局，其实不如说是家武馆更合适，因为镖局的林老镖
头在扬州等地的同行的竞争下，很久都没有接到过油水比较大的镖了。没有办法，
迫于无奈，林老镖头只好靠帮人练功夫和为客人寄放马匹牲口来挣银子维持镖局
了。门口有一块牌子上写了些扬威镖局的规矩。
LONG
    );
    set("no_kill",  "yangzhou");
    set("outdoors", "chuzhou" );
    set("detail", ([
        "牌子"  : "与人练功夫一次，收银五两。\n寄放马匹一匹，收钱五百文。\n",
        "paizi" : "与人练功夫一次，收银五两。\n寄放马匹一匹，收钱五百文。\n",
        "sign"  : "与人练功夫一次，收银五两。\n寄放马匹一匹，收钱五百文。\n",
    ]));        
    set("exits", ([
        "west"  : __DIR__"wuhua_jie",
//        "east"  : __DIR__"majiu",
        ]));
    set("objects", ([
        __DIR__"npc/biaojuboss" :   1,
//        __DIR__"npc/daughter"   :   1,
    ]));        
    setup();
}
