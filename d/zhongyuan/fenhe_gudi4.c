// fenhe_gudi4.c
inherit ROOM;

void create()
{   
    set("short","汾河谷地");
    set("long",@LONG
汾河谷地平原狭长，吕梁山、太岳山列于东西两侧，汾河的河水灌溉在这一
代狭长的平原谷地，气候温和，水源丰富，是汾州最为富饶地区。人口稠密，商
业也很发达。一条平整的官道沿着汾河岸边，南北延伸，是联系太原府进关中的
重要通道。道边每隔几十里就有一处可以歇脚换马的驿站，不过，只有官府中人
才能够使用。
LONG );
    set("exits",([
        "south" : __DIR__"fenhe_gudi3",
        "northeast" : __DIR__"fenhe_gudi5"  ]) );
    set("outdoors","zhongyuan");
    setup();
}
