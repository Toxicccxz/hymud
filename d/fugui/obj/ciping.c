 inherit ITEM;
inherit F_LIQUID; 
void create()
{
        set_name("青瓷瓶", ({ "ping", "瓶" }) );
        set_weight(70);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一个青瓷瓶。\n");
                set("unit", "个");
                set("value", 1000);
                set("max_liquid", 1);
        } 
        set("liquid", ([
                "type": "water",
                "name": "解药",
                "remaining": 1,
                "drunk_apply": 10,
        ]) );
        
} 
void init()
{
        add_action("do_drink","drink");
} 
int do_drink(string arg)
{
    if(arg=="ping" || arg=="青瓷瓶") {
   if (this_object()->query("liquid/name")=="解药")
   {
        object me;
        me=this_player();
        message_vision("$N把青瓷瓶里的解药一口吞了下去！\n",me);
        me->clear_condition("redsnake");
        me->unconcious();
        destruct(this_object());
        return 1;
   }
 }
}     
