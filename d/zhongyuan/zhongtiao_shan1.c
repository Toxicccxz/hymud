// zhongtiao_shan1.c
inherit ROOM;

void create()
{   
    set("short","中条山");
    set("long",@LONG
中条山东西一百余里，横亘在黄河北岸。这里是八仙之一张果老云游修炼之
处，倒骑毛驴的张果老的形象一直在被民间的村头田野里流传着。据说唐朝时，
武后武则天，明皇李隆基都曾诏他进宫晋见，每次他都在传谕官前倒地而死，且
尸体立即腐烂生蛆，可过后不久，又有人见到他在山中闲游，神仙的生活真是美
妙啊！
LONG );
    set("exits",([
        "southwest" : __DIR__"fengling_du",
        "east" : __DIR__"zhongtiao_shan2"  ]) );
    set("outdoors","zhongyuan");
    setup();
}
