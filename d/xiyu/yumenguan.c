/* yumenguan.c
 * from XO Lib
 * a room of desert
 * created by hydra 19980407
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980407
 */

inherit ROOM;

void create()
{
    set( "short","玉门关外" );
    set( "long",@LONG
玉门关是西域通往中原的一个重要关卡。这里气候干燥，日照强烈，周围又
都是沙漠、戈壁，寸草不生，故王之涣有诗云“羌笛何须冤杨柳，春风不渡玉门
关”。抬头四望，眼前无树无草，只有青灰色的石子单调地铺满地面；戈壁、沙
漠中蒸腾起来的蜃气，构成了一幅幅幻景。
LONG
    );

    set( "exits",([ /* sizeof() ==2 */
        "west" : "/d/xibei/desert/shamo0",
        "southeast" : __DIR__"dunhuang",
    ]) );
    set( "outdoors","silk");
    setup();
}

void init()
{
    this_player() -> set( "hydra/desert/from","中原" );
}

