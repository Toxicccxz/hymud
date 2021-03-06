/* shamo3.c
 * from XO Lib
 * a room of desert
 * created by hydra 19980325
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980407
 */

#define DIR   __DIR__"shamo7"
//define the correct way

#include "shamo.h"

public int month;
mapping *exit = ({
    ([ "forward" : __DIR__"shamo7",
         "right" : __FILE__,
         "backward":__DIR__"shamo2",
         "left" : __FILE__,
       ]),
    ([ "right" : __DIR__"shamo7",
         "backward" : __FILE__,
         "left":__DIR__"shamo2",
         "forward" : __FILE__,
       ]),
    ([ "backward" : __DIR__"shamo7",
         "left" : __FILE__,
         "forward":__DIR__"shamo2",
         "right": __FILE__,
       ]),
    ([ "left" : __DIR__"shamo7",
         "forward" : __FILE__,
         "right":__DIR__"shamo2",
         "backward" : __FILE__,
       ]),
});


void create()
{

    set( "short","大沙漠" );
    SetLong();
    set( "exits",exit[random( 4 )] );
    
    set( "outdoors","desert");
    set( "not_startroom",1 );
    setup();
}

void init()
{
    add_action( "do_look",({ "look","l" }) );
    eventClear( this_object() );
    SetLong();
    remove_call_out( "check_month" );
    call_out( "check_month",1 );
    remove_call_out("greet_me");
    call_out( "greet_me",1,this_player());
}

//中国沙漠中最常见的大风天气有两中，“黄龙吸沙”--即龙卷风，“沙暴”
//前者一般发生在6、7月份，后者4、5月份。写的程序没有必要那么讲究，
//统一做成沙暴，在4-7月份发生。
void check_month()
{   
    month = localtime( time_tick )[ LT_MON ] + 1;
    if( month > 7 || month <4  )
        call_out( "before_storm",10 );    //4-7月有沙暴
    else 
        call_out( "check_month",100 );    //其他月份没有
}

void before_storm()
{
    message( "vision",RED"突然你感觉到脚下的沙子在震动。。。。。。\n"NOR,this_object() );
    message( "vision",RED"你抬头向四周望了一下，你发现在远处的空中一团黑色的"
"烟雾在不停\n的扭动着，你隐隐感觉到有一丝不祥之兆。。。\n"NOR,this_object() );
    call_out( "check_storm",10 );
}

//判断沙暴是否移动到这里来，有2/3的概率会
void check_storm()
{
    if( random( 60 ) >40 )
    {
        message( "vision",YEL"那团黑色的东西在空中盘旋了半天后，渐渐的远离而"
"去了。\n"NOR,this_object() );
    call_out( "check_month",450 );
    }
    else
    {
        message( "vision",RED"只见那团烟雾，伴随着巨大的旋风慢慢的向近处移动"
"过来，迎面而来\n的沙子，迷的你睁不开双眼。\n"NOR,this_object() );
        call_out( "sand_storm",5 );
    }
}

//发生沙暴的过程：
void sand_storm()
{
    object *all,*inv;
    int i,j,rannum;

    message( "vision",RED"伴随着风的呼啸声，沙子被卷到了半空，形成了螺旋式的擎"
"天圆柱。\n"NOR,this_object() );
    all = all_inventory( this_object() );
    for ( i=0; i<sizeof(all); i++ )
    {
        if ( !living( all[i] ) && !userp( all[i] ) )
        {
            destruct( all[i] );             //不是living,dest掉
            continue;
        }
        if ( !userp( all[i] ) ) 
        {
            all[i]->die();                  //非ppl,直接die
            continue;
        }
        else
        {
            inv = all_inventory( all[i] );    //ppl的情况
            for ( j=0;j<sizeof( inv );j++ ) 
            {                                 //身上东西全没了
                inv[j] -> move( environment( all[i] ) );
                destruct( inv[j] );
            }   
            tell_object( all[i],"你感觉到一股巨大的力量把你托到了半空，然后你又掉了下来。\n" );
            rannum = random( 100 );
            if( rannum >97 )
            {
                switch( random( 10 ) )
                {
                    case 1:                    //刮到楼兰废墟　２/1000的几率
                        all[i] -> move( __DIR__"loulan1" );    
                        all[i] -> unconcious();          
                        break;
                    default:                   //直接死亡　18/1000的几率
                        all[i] -> die();
                       break;
                }
            }  
            else if( rannum >89 )              //　刮到绿洲　7/100的概率
            {
                all[i] -> move( __DIR__"lvzhou" );
                all[i] -> unconcious();
            }
            else                                //沙漠中的任何一个room 9/100的概率
            {
                all[i] -> move( __DIR__"shamo" + rannum/9 );
                all[i] -> unconcious();
            }
        }
        message( "vision","突然从空中掉下一物，掉在了地上。\n",
environment( all[i] ),({ all[i] }) );
    }
    call_out( "check_month",300 );
}
