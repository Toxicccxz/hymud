// a skeleton for user rooms
inherit ROOM;
void create()
{
set("short", "���������ܲ�");
set("long", @LONG
�������������˵��ܲ�
�������������˵��ܲ�
�������������˵��ܲ�
�������������˵��ܲ�
�������������˵��ܲ�
�������������˵��ܲ�
�������������˵��ܲ�

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
	set("class", "�������ˡ�");
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
	write("������"+arg+"����ķ��䡣\n");
	return 1;
}

/*int do_setowner(string arg)
{
	string oldowner;
	oldowner = (string)query("owner");
	set("owner",arg);
	write("�㽫�����������ʱ��Ϊ"+arg+"��\n");
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
        write("�����ڱ�ͨ���У����ܽ����Լ������ɡ�\n");
        write("�㱻�������Ӵ��˳�ȥ��\n");
	call_out("kicking", 0, me);
        me->unconcious();
	return notify_fail("�㲻�ܽ�ȥ!\n");
        }

        if ( me->query("family/family_name") != (string)query("class"))
        {
        write("���Ǳ��˵�����,�㲻�����ߡ�\n");
        write("�㱻�������Ӵ��˳�ȥ��\n");
	call_out("kicking", 0, me);
        me->unconcious();
	return notify_fail("�㲻�ܽ�ȥ!\n");
        }
        else {
		inv=all_inventory(me);
		sizeinv=sizeof(inv);
	
		while (sizeinv--)
		{
       			if (inv[sizeinv]->is_character() && userp(inv[sizeinv])  )  
     				return notify_fail("�����ȥ�����˿ڣ�\n");
       		
		}
        return ::valid_leave(me, dir);
        }
}

void kicking(object me)
{
        me->move("d/city/wumiao");
}