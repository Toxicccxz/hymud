 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
#include <ansi.h>
int tell_him();
void create()
{
    set_name("谷慧儿", ({ "gu huier", "huier" }) );
    set("gender", "女性" );
    set("age", 24);
    set("attitude","friendly");
    set("force_factor", 20);
    set("long", "\n");
    set("combat_exp", 100);
    set("inquiry", ([
        "死而复活" : (: tell_him :),
        "sierfuhuo" : (: tell_him:),
        ]));
    setup();
    carry_object("/clone/misc/cloth")->wear();
}
int is_ghost() { return 1; }  
void init()
{
    object ob;
    ::init();
    if( interactive(ob=this_player()) && ob->visible(this_object())
        && !ob->query_temp("marks/huier"))
    {
        call_out("greeting", 1, ob);
    }
}
void greeting(object ob)
{
    tell_object(ob,"谷慧儿道：帮帮我吧，最近恶鬼一到晚上就出来，\n");
    tell_object(ob,"你知不知道我死去的舅爷掌管这里的城隍庙，他有个印，可以制服恶鬼！\n"); 
    ob->set_temp("marks/huier",1);
}  
int tell_him()
{
    object me;
    me =this_player();
    if(me->query_temp("marks/qingbo") &&
       me->query_temp("marks/yuanji") &&
       me->query_temp("marks/jiuye")) {
        tell_object(me,"这你就问对人了，听说有一种药方（yaofang），这种药吃下去立刻
就死，可是过了三天还能复活！\n");
        me->set_temp("marks/yaofang",1);
        return 1;
    }
    return 0;
}  
int accept_object(object me, object obj)
{
    if(obj->query("huier")) {
        command("say 真的谢谢你了！这回我可以制服恶鬼了！\n");
        me->set_temp("marks/jiuye",1);
        return 1;
    }
    return 0;
}    
