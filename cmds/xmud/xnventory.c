//inventory.c
#include <ansi.h>
inherit F_CLEAN_UP;
object find_player(string target)
{
	int i;
	object *str;
	str=users();
	for (i=0;i<sizeof(str);i++)
		if (str[i]->query("id")==target)
			return str[i];
	return 0;
}
int main(object me, string arg)
{
	int i,amount,w_p;
	object *inv, ob,obj;
	mapping my;
	string *str,col_p;
	if( wizardp(me) && arg ) {
		ob = find_player(arg);
		if( !ob ) ob = find_living(arg);
		if( !ob ) ob = present(arg, environment(me));
	}
	if( !ob ) ob = me;
	inv = all_inventory(ob);
	if( !sizeof(inv) ) {
		write((ob==me)? "$xdwp#Ŀǰ������û���κζ�����\n"
			: "$xdwp#"+ob->name() + "����û��Я���κζ�����\n");
		return 1;
	}
	obj=first_inventory(ob);
	arg="";
        while(obj){
		reset_eval_cost();
		if (obj->query("equipped")  || obj->query("money_id")){
arg+=sprintf("$xdwp#%s%s \n",obj->query("equipped")? HIG "��" NOR:"  ",obj->short());
			obj = next_inventory(obj);
			continue;
		}
		if (!mapp(my))
		   	my=([obj->query("unit")+obj->short():1]);
		else{
			amount=my[obj->query("unit")+obj->short()];
		   	my[obj->query("unit")+obj->short()]=amount+1;
		}
		obj = next_inventory(obj);
	}
	if (mapp(my)){
		str=keys(my);
		for (i=0;i<sizeof(my);i++)
                arg+=sprintf("$xdwp#  %s%s\n",
my[str[i]]==1?"":CHINESE_D->chinese_number(my[str[i]]),
my[str[i]]==1?str[i][2..]:str[i]);
}
        w_p = (int)ob->query_encumbrance() * 100 / (int)ob->query_max_encumbrance();
        if (w_p < 30) col_p = HIB;
        else if(w_p < 70) col_p = HIY;
        else col_p = HIR;
	arg+="$#\n";
	printf("\n$xdwp#%s���ϴ��ŵ���Ʒ��(���� "+col_p+"%d%%"NOR")��\n"+"%s\n",
		(ob==me)? "��": ob->name(),
		w_p,
		arg);
	return 1;
}
int help (object me)
{
        write(@HELP
ָ���ʽ: inventory
 
���г���Ŀǰ������Я����������Ʒ��
 
ע : ��ָ����� " i " ���档
 
HELP
);
        return 1;
}