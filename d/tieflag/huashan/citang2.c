 inherit ROOM;
#include <ansi.h> 
void create()
{
        set("short", "荒废的祠堂");
        set("long", @LONG
祠堂里积满了灰尘，一些牌位凌乱地堆在神台上，两只烛台孤零零的立在神台
上。神龛里空空的，上面结满了蛛网，神龛后面是厚厚的幔布。这里似乎新近有人
来过，地面上印有很多杂乱的脚印。 
LONG
        );
    set("exits", ([ 
                "west" : __DIR__"citang1",
        ])); 
        set("item_desc", ([
                "幔布" : "长长厚厚的黑色幔布的更增添了这里神秘凄凉的气氛，你不由想掀开看看后面有什么。
（ｏｐｅｎ　ｃｕｒｔａｉｎ）。\n",      
                "curtain" : "长长厚厚的黑色幔布的更增添了这里神秘凄凉的气氛,你不由想掀开看看后面有什么。
（ｏｐｅｎ　ｃｕｒｔａｉｎ）。\n",
        ]) );  
        set("objects", ([
                __DIR__"obj/shentai" : 1, 
                "/kungfu/class/hu/yuzhenzi" : 1, 
        ]));
    set("indoors", "huashan");
    set("coor/x",-570);
    set("coor/y",-25);
    set("coor/z",30);
        setup();
} 
void init(){
        add_action("do_open", "open");
} 
int do_open(string arg)
{
        object player,kumei;
        player = this_player();
        if(arg != "幔布" && arg != "curtain") {
                return 0;
        }
        if ( player->query("marks/忠诚") == 1 
                   || player->query("marks/忠诚") == -1)
        {
                message_vision("$N掀开幔布，积尘飞扬，隐隐一个黑色人影掠过，又好象只是幻觉。\n",player);
                return 1;
        }
        kumei = new(__DIR__"npc/kumei.c");
        kumei->move(this_object());
        message_vision("$N试着掀开幔布。 \n\n\n",player);
        message_vision(HIB"忽然幔布动了一下，$N面前如鬼魅般出现一个$n。 \n\n\n"NOR,player,kumei);
        kumei->apprentice_me(player);
        return 1;
}  
