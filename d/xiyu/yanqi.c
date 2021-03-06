/* yanqi.c
 * from XO Lib
 * a room of xiyu
 * created by hydra 19980427
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980427
 */

inherit ROOM;

void create()
{
    set( "short","焉耆" );
    set( "long",@LONG
焉耆是西域北道的要冲，西通天山山脉的大河裕勒河，东则控制着博斯腾湖
地区。在中原王朝与西域国家复杂而重要的冲突中，起着非常重要的作用。唐朝
曾在此设立都护府，是西部四大重镇之一。这里四面皆山，道险易守。境内泉水
溪流交织如带，物产丰富。
LONG
    );

    set( "exits",([ /* sizeof() ==3 */
        "northeast" : __DIR__"caoyuan1",
        "southeast" : __DIR__"lvzhou2",
        "southwest" : __DIR__"caoyuan2",
    ]) );
    set( "outdoors","xiyu");
    setup();
}


