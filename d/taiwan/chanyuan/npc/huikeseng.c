
inherit NPC;

int do_action1();

void create()
{
  
   set_name("会客僧",({ "seng ren","seng","ren"}));
   set("gender", "男性" );
   set("class","bonze");
   set("long","这是净念禅院会客僧，你可以向他要些香烛。");
   set("combat_exp",50000);
   set("inquiry",([
     "香烛":(:do_action1:),
     ]));
  setup();
  
}

int do_action1()
{
   object ob,obj;
   int value;
   
   ob=this_player();
   
   value=50;
   switch(MONEY_D->player_pay(ob,value)){
   	case 0:
   	case 2:
   	command("say 希望施主能给我们一点香火钱啊！");
   	return 1;
   	default:break;
   }
   obj=new(__DIR__"obj/xiangzhu");
   obj->move(ob);
   tell_object(ob,query("name")+"给了你一"+obj->query("unit")+
     obj->query("name")+"。\n");
   return 1;
}