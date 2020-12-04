// a skeleton for user rooms
inherit ROOM;
void create()
{
set("short", "新手联盟总部");
set("long", @LONG
这里是新手联盟的总部
这里是新手联盟的总部
这里是新手联盟的总部
这里是新手联盟的总部
这里是新手联盟的总部
这里是新手联盟的总部
这里是新手联盟的总部

LONG
);
        set("exits", ([
"east" : "/p/residence/name1433782392",
"west" : "/p/residence/name1433780026",
"north" : "/p/residence/name1433777901",
"down" : "/p/guangchang.c",
]));
set("objects", ([
       "/p/npc/weishi":2,
       ]) );
	set("owner", "name");
	set("class", "新手联盟　");
	set("valid_startroom",1);

//	set("no_fight",1);

setup();
}
void init()
{
	add_action("do_invite","invite");
	//add_action("do_setowner","setowner");
}
int valid_enter(object me)
{
	int flag;
// always let owner go in:
	 if((string)me->query("class") != (string)query("class")
	&&(string)query("invite") != (string)me->query("id")
	&&(string)me->query("id") != (string)query("owner"))
	return 1;	

}
int do_invite(string arg)
{
	object me;
	me= this_player();
	if((string)me->query("id") != (string)query("owner"))
	return 0;
	set("invite",arg);
	write("你邀请"+arg+"来你的房间。\n");
	return 1;
}

/*int do_setowner(string arg)
{
	string oldowner;
	oldowner = (string)query("owner");
	set("owner",arg);
	write("你将房间的主人暂时设为"+arg+"。\n");
	call_out("set_back",60, oldowner);
	return 1;
}

int set_back(string oldowner)
{
	set("owner", oldowner);
	return 1;
}
*/
varargs int valid_leave(object me, string dir)
{
	object *inv,kicker;
	int sizeinv,n,tt;



        if ((int)me->query_condition("killer")>1)
        {
        write("你正在被通辑中，不能进入自己的门派。\n");
        write("你被几个弟子打了出去。\n");
	call_out("kicking", 0, me);
        me->unconcious();
	return notify_fail("你不能进去!\n");
        }

        if ( me->query("family/family_name") != (string)query("class"))
        {
        write("这是别人的门派,你不能乱走。\n");
        write("你被几个弟子打了出去。\n");
	call_out("kicking", 0, me);
        me->unconcious();
	return notify_fail("你不能进去!\n");
        }
        else {
		inv=all_inventory(me);
		sizeinv=sizeof(inv);
	
		while (sizeinv--)
		{
       			if (inv[sizeinv]->is_character() && userp(inv[sizeinv])  )  
     				return notify_fail("你想进去拐卖人口？\n");
       		
		}
        return ::valid_leave(me, dir);
        }
}

void kicking(object me)
{
        me->move("d/city/wumiao");
}