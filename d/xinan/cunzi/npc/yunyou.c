//Writen by lnwm (May.28.1997)
//yunyou.c

inherit NPC;

string do_show();
void create()
{
    set_name("游方道士", ({ "youfang daoshi","daoshi" }) );
    set("gender", "男性" );
    set("age", 40);
    set("long",
"身穿一身蓝布道袍的道人,看起来风尘仆仆,显然走过很远的路\n"
    );
    set("combat_exp", 100000);
    set("social_exp", 20000);
       set("force_factor", 10);
       set("max_force", 1000);
       set("force", 1000);


    set("inquiry", ([
        "来历"          : "我从青城山来,恰巧路过此地",     
        "找老头子"      : (:do_show:),
        "找人"          : "是呀,我是在找一个人",
        "找谁"          : "我说漏嘴了,呵呵,我可不能告诉你我找谁",
        ]) );

    set("chat_chance", 1);
    set("chat_msg",({
"云游道士自言自语地说:掌门说的就是这里呀.\n",
"云游道士四处张望着,好象在找什么东西.\n",
"云游道士叹了口气:为一个糟老头子,害的我走了这么远的路.\n",
(: random_move :),
        }) );
        
     setup();
     carry_object(__DIR__"obj/daopao")->wear();
}


string do_show()
{
    string msg;
    object ob,me;
    me = this_player();
    ob = this_object();
    command("sigh");
    command("say 我就是管不住自己,天大的秘密也要给我说漏");
    command("say 其实告诉你也无妨,我奉我们掌门之命,来找一位老师伯");
    command("say 他的道号叫做逍遥子,从我们山上失踪已有30年了");
    msg = "不行了，我得走了，后会有期!!";
    command("shake");
    me->set_temp("marks/yunyou",1);
    call_out("destroy_me",1,ob);
    return msg;
}       

void destroy_me(object ob)
{
    destruct(ob);
}


