#include <ansi.h>;
inherit SKILL;

mapping *action = ({
([  "action" : "\n$Nһ�ǹ�ȭ������$n��$l��\n",
        "force" : 420,
        "dodge" : 1000,
        "damage": 200,
        "damage_type" : "ץ��",
]),
([      "action" : "$Nһ��ֱȭ��ֱ��$n��$l��",
        "force" : 420,
        "dodge" : 1000,
        "damage": 200,
        "damage_type" : "����"
]),
([      "action" : "$Nһ�ǰ�ȭ��ֱ��$n��$l��",
        "force" : 420,
        "dodge" : 1000,
        "damage": 200,
        "damage_type" : "����"
]),
([      "action" : "\n$Nһ����ȭ������$n��$l��",
        "force" : 420,
        "dodge" : 1000,
        "damage": 200,
                "damage_type" : "����"
]),
([      "action" : "$Nһ�����ȭ��ֱ��$n��Ҫ����λ��",
        "force" : 420,
        "dodge" : 1000,
        "damage": 200,
        "damage_type" : "����",
]),
});

int valid_enable(string usage) { return usage=="unarmed" ||  usage=="parry"|| usage=="hand"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("��ȭ��������֡�\n");
        if ((int)me->query("max_force") < 200)
                return notify_fail("�������̫�����޷���ȭ����\n");
        return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level = (int)me->query_skill("boxing", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if ((int)me->query("kee") < 30)
                return notify_fail("�������̫���ˡ�\n");
        if ((int)me->query("force") < 10)
                return notify_fail("�������������ȭ����\n");
        me->receive_damage("kee", 15);
        me->add("force", -5);
        return 1;
}


mixed hit_ob(object me, object victim,int damage_bonus)
        
{	
        if( damage_bonus > 100 ) 
{
        victim->receive_wound("qi", damage_bonus );	
        victim->receive_wound("qi", damage_bonus );
        return HIR "����ȭ!!һ��ȭӰ������һ����Ѫ��$n���������\n" NOR;	
}
        if( damage_bonus < 75 ) 
{
        victim->receive_wound("qi", damage_bonus );	
        victim->receive_wound("qi", damage_bonus );	
        return YEL "����ȭ!!һ��ȭӰ������$n�ƺ�һ��,���ӻ������Σ�\n" NOR;
}
else
{       
        victim->receive_wound("qi", damage_bonus );	
        victim->receive_wound("qi", damage_bonus );	
        return HIM "����ȭ!!һ��ȭӰ��������������������һ�����죬���Ͼ�����һЩѪ�Σ�\n" NOR;
}

}