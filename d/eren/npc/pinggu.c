#include <ansi.h>
inherit NPC;  
void create()
{
        set_name(HIY"替补"NOR,({"guardian"}));
//      set("title","昆仑四鹫");
//      set("nickname","笑里藏刀");
        set("long", "一个十七八岁的少女，虽然穿着农家衣饰，却掩不住绝美之色。可是，
她的眼角总带着淡淡的哀伤。\n");
        set("attitude", "friendly");
        set("combat_exp", 2000000);
                        
        set("max_atman",800);
        set("atman",800);
        set("max_mana", 800);
        set("mana", 800);
        set("max_neili",1000);
        set("neili",1000);
                
        set("cor", 40);
        set("cps", 40);
        set("int",40);
        set("agi",40);
        
        set("inquiry", ([
                "小烟" : "小烟好像和几个孩子在竹林边玩",
                 "欧阳豆腐铺" : "欧阳豆腐铺生意越来越好，快盖过哈哈酒楼了。",
                "欧阳丁" :  "欧阳豆腐铺生意越来越好，快盖过哈哈酒楼了。",
                "欧阳当" :  "欧阳豆腐铺生意越来越好，快盖过哈哈酒楼了。",
                "ouyang ding" :  "欧阳豆腐铺生意越来越好，快盖过哈哈酒楼了。",
                "ouyang dang" :  "欧阳豆腐铺生意越来越好，快盖过哈哈酒楼了。",
                "哈哈酒楼": "哈哈酒楼当然是哈哈儿开的喽，听说他现在生意不好，正在为原料发愁呢。",
                "娇娇客栈": "娇娇客栈是屠娇娇的女儿开的。",
                "屠小娇": "娇娇客栈是屠娇娇的女儿屠小娇开的。",
                "恶人谷": "恶人们都跑光了，这恶人谷三字早已没人提了。",
                "燕南天": "燕大侠的名字谁人不晓，村里还有他的铁像呢。",
                "万春流": "万神医有起死回生之能。",
                "杜老爹": "杜老爹专打暗器，听说要打他的暗器，还得学好听风辨器才行。",
                "轩辕三光": "他输的只剩下那间当铺了。",
                "李大嘴": "大嘴是我爹，我爹对我很好，最近他有事到泰山去了。",                   
           ]));
        
        set("chat_chance", 1);
        set("chat_msg", ({
                "铁萍姑说：“你见到我爹爹就叫他快回家吧。”\n",
        }) );

        set_name("铁萍姑",({"tie pinggu","pinggu"}));
        set("age",18);
        set("gender","女性");
        set("force_factor",40);
        setup();
        carry_object(__DIR__"obj/pgcloth")->wear();
        
} 
void init()
{
        object ob; 
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) 
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
} 
void greeting(object ob)
{   
        if( !interactive(ob) || environment(ob) != environment() ){
                return;
        }
        if (ob->query("marks/救黑蜘蛛") && !ob->query("marks/蜘蛛恶人窟")) {
                message_vision(CYN"$N说：太谢谢你救了黑蜘蛛，他让我转告你，此地人人心怀叵测，唯神医万春
流乃燕大侠故交，更有"NOR+HIR"起死回生"NOR+CYN"之能。”\n"NOR, this_object(),ob);
                ob->set("marks/蜘蛛恶人窟",1);
           }
        return;
}   
