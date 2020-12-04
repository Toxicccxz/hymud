/// who.c
// From ES2
// Modified by Yu Jue@JY

#include <ansi.h>
#include <net/dns.h>

inherit F_CLEAN_UP;

int sort_user(object,object);

void create() { seteuid(getuid()); }

mixed main(object me, string arg, int remote)
{
	string str,hymsg, *option, fname = "";
	object *list, *ob;
	int i, ppl_cnt, cnt, count, wcnt = 0,hylv;
	int opt_long, opt_id, opt_wiz, opt_party,opt_long2;

	if( arg ) {
		option = explode(arg, " ");
		i = sizeof(option);
		while( i-- )
			switch(option[i]) {
				case "-m": opt_long2 = 1; break;
				case "-l": opt_long = 1; break;
				case "-i": opt_id = 1; break;
				case "-w": opt_wiz = 1; break;
				case "-f":
				case "-p": opt_party = 1; break;
				default:
/*
					if( wizardp(me)
					&&	option[i][0]=='@' ) {
						RWHO_Q->send_rwho_q(option[i][1..sizeof(option[i])],
							me, opt_long);
						write("��·ѶϢ���ͳ������Ժ�\n");
						return 1;
					}
*/
					return notify_fail("ָ���ʽ��who [-l|-i|-w|-p]\n");
			}
	}
        if (me->is_busy())
                return notify_fail("��������æ���ء�\n");
        if (me->is_fighting()) 
        return notify_fail("���������������!\n");
        me->start_busy(1);
	if( opt_long && !wizardp(me)) {
		if( (int)me->query("jing") < 50 )
			return notify_fail("��ľ���̫���ˣ�û�а취��֪������ҵ���ϸ���ϡ�\n");
		me->receive_damage("jing", 50);
	}

    str = HIG"�� " + MUD_NAME + "\n"NOR;
        str += HIG"\n��������������������������������������������������������������������������\n"NOR;
//	ob = filter_array(objects(), (: userp :));
	ob = filter_array(children(USER_OB),(: userp :));
	if (opt_party)
		ob = filter_array(ob, (: $1->query("family/family_name") ==
			$2->query("family/family_name") :), me);
	list = sort_array(ob, (: sort_user :));
	ppl_cnt = 0;
	cnt = 0;
	if( opt_long2 || opt_long || opt_wiz ) {
		i = sizeof(list);
		while( i-- ) {
ppl_cnt++;
			// Skip those users in login limbo.
			if( !environment(list[i]) ) continue;
			if( !me->visible(list[i]) ) continue;
            if( opt_wiz && !wiz_level(list[i]) ) continue;
            if( opt_long2 &&  !list[i]->query("hyvip")) continue;
			if (interactive(list[i])) ppl_cnt++;
			else
{
ppl_cnt++;
			 cnt++;
}
hylv   = (int)list[i]->query("hyvip"); 
hymsg="";
if( opt_long2)
{
if (hylv==0) hymsg="һ�����";
if (hylv==1) hymsg="������Ա";
if (hylv==2) hymsg="�м���Ա";
if (hylv==3) hymsg="�߼���Ա";		 
if (hylv==4) hymsg="�ǻһ�Ա";
}
			str = sprintf("%s%s%12s%s%s\n",
				str,hymsg,
				RANK_D->query_rank(list[i]),
				interactive(list[i])?(query_idle(list[i]) > 120?HIM "+" NOR:" "):HIG "*" NOR,
				list[i]->short(1)
			);
		}
	} else {
		i = sizeof(list);
		count = 0;
		while( i-- ) {
			// Skip those users in login limbo.
			if( !environment(list[i]) ) continue;
			if( !me->visible(list[i]) ) continue;
			if (!wiz_level(list[i]) && fname != list[i]->query("family/family_name")) {
			    fname = list[i]->query("family/family_name");
			    if (count % 5) str += "\n";
			    str += sprintf(HIY "%-10s" NOR, (fname?fname:"��ͨ����") + "��");
			    count = 1;
ppl_cnt++;
			}
			if (!wcnt && wiz_level(list[i])) {
			    if (count % 5) str += "\n";
			    str += sprintf(HIR "%-10s" NOR, "��ʦ��");
			    wcnt = 1;
			    count = 1;
ppl_cnt++;
			}
			if (!(count%5)) {
				count++;
				str += "          ";
ppl_cnt++;
			}
if (list[i]->query("gender")=="Ů��")
                        str = sprintf("%s%s%-9s"NOR"%s",
				str,
				interactive(list[i])?(query_idle(list[i]) > 120?HIM "+":" "):HIG "*",
				opt_id?capitalize(list[i]->query("id")): HIG+list[i]->name(1)+"("+list[i]->query("id")+")"NOR,
				++count%5 ? "": "\n"

			);
else if (list[i]->query("gender")=="����")
                        str = sprintf("%s%s%-9s"NOR"%s",
				str,
				interactive(list[i])?(query_idle(list[i]) > 120?HIM "+":" "):HIG "*",
				opt_id?capitalize(list[i]->query("id")): HIW+list[i]->name(1)+"("+list[i]->query("id")+")"NOR,
				++count%5 ? "": "\n"

			);
else 
                        str = sprintf("%s%s%-9s"NOR"%s",
				str,
				interactive(list[i])?(query_idle(list[i]) > 120?HIM "+":" "):HIG "*",
				opt_id?capitalize(list[i]->query("id")): HIY+list[i]->name(1)+"("+list[i]->query("id")+")"NOR,
				++count%5 ? "": "\n"

			);


			if (interactive(list[i])) ppl_cnt++;
			else
{
ppl_cnt++;
			 cnt++;
}
		}
		if( count%5 ) str += "\n";
	}
	str += HIG"��������������������������������������������������������������������������\n"NOR;
	str = sprintf(""HIG"%s"HIG"�� %d "HIG"λ��������У�%d "HIG"λ��Ҷ����У�ϵͳ������%s"HIG"\n* ��ʾ������  + ��ʾ������"NOR"", str, ppl_cnt,
		cnt, query_load_average());

//	if( remote ) return str;

	me->start_more(str);
	return 1;
}

int sort_user(object ob1, object ob2)
{
	string name1, name2;

	reset_eval_cost();
	if( wiz_level(ob1) != wiz_level(ob2) )
		return wiz_level(ob2)
			- wiz_level(ob1);
	
	name1 = ob1->query("family/family_name");
	name2 = ob2->query("family/family_name");

	if (intp(name1)) name1 = "";
	if (intp(name2)) name2 = "";
	if (name1 > name2) return -1;
	if (name1 < name2) return 1;

	return (int)ob2->query("combat_exp") - (int)ob1->query("combat_exp");
}

int help(object me)
{
write(@HELP
ָ���ʽ : who [-l|-i|-w|-p]

���ָ������г����������ϵ���Ҽ���ȼ���

-l ѡ���г��ϳ���ѶϢ��
-i ֻ�г���ҵ�Ӣ�Ĵ��š�
-p ֻ�г�ͬ�ŵ���ҡ�
-w ֻ�г��������е���ʦ��
-m ֻ�����л�Ա��Ϣ��

���ָ� finger
HELP
	);
	return 1;
}