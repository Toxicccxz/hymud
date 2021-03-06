#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;
string get_name(string str)
{
        str="拜佛六式";
        return str;
}
string* skill_head1 =({
        HIW"$N身形稍退，使出一招 脱困老君炉",
        HIW"$N仰天长笑，看也不看，一招 勇斗二郎神",
        HIW"$N一个虎跳，使出 谈笑退天兵",
        HIW"$N一声巨喝，好一个 大闹阎罗府",
        HIW"$N使出 千钧澄玉宇",
        HIW"$N连翻几个筋斗云，一招 乾坤一棒",

});

string* skill_tail1 =({
        HIW"，手中$w迎风一抖，朝着$n劈头盖脸地砸将下来。",
        HIW"，随手一棒向$n当头砸下。",
        HIW"，越过$n头顶，手中$w抡个大圆，呼！地一声砸向$n$l。",
        HIW"，就在$n一愣之间，$N手中$w已是呼啸而至，扫向$n的$l。",
        HIW"，脚步跄踉，左一棒，右一棒，\n打得$n手忙脚乱，招架不迭。",
        HIW"，手中$w转得如风车一般，\n一连三棒从半空中击向$n顶门。",
});

string get_help(string str)                
{
        str="指令: ｐｅｒｆｏｒｍ　ｂａｉｆｏ\n"
        +"条件：释厄棍法法大于120级，最大内力大于1200，每用一次消耗100精神和200内力，"
        +"迅速向对方攻击五招，攻击力能让鬼神无一幸免。";
        return str;
}

int perform(object me, object target)
{
        object weapon;
        	string msg;
        int extra;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展这一招「拜佛五式」？\n");

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("这门绝学只能对战斗中的对手使用。\n");
        if(!me->is_fighting())
                return notify_fail("「拜佛五式」只能在战斗中使用！\n");
        if((int)me->query("max_neili") < 1200 )
                return notify_fail("你的内力不够！\n");
        if((int)me->query("jing") < 600 )
                return notify_fail("你的精神不足，没法子施用外功！\n");
        if((int)me->query_skill("buddha-club", 1) < 120)
                return notify_fail("你的释厄棍法级别还不够，使用这一招会有困难！\n");
        if((int)me->query_skill("yijinjing", 1) < 150)
                return notify_fail("你的易筋经级别还不够，使用这一招会有困难！\n");
    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "club")
        return notify_fail(RED"开什么玩笑，武器不对？\n"NOR);

        if ( !wizardp(me) && me->query_skill_mapped("force") != "zhanzhuang-gong")
                return notify_fail("请使用四平大马站桩功!\n");

        me->delete("env/brief_message");
        target->delete("env/brief_message");
        message_combatd(HIC"\n$N运足精神，身形一转使出灵台山绝学"HIW"「拜佛六式」"NOR+HIC"连续向$n攻出了六招！\n"NOR,me,target,"");
        extra=(int)me->query_skill("buddha-club", 1);
if (extra>=300) extra=300;
        me->add_temp("apply/attack", extra);
        me->add_temp("apply/damage", 2200); 

        if(!target->is_busy())
                target->start_busy(1);
        

	msg = skill_head1[0]+skill_tail1[random(sizeof(skill_tail1))]+"\n"NOR;   
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = skill_head1[1]+skill_tail1[random(sizeof(skill_tail1))]+"\n"NOR;   
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = skill_head1[2]+skill_tail1[random(sizeof(skill_tail1))]+"\n"NOR;   
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = skill_head1[3]+skill_tail1[random(sizeof(skill_tail1))]+"\n"NOR;   
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = skill_head1[4]+skill_tail1[random(sizeof(skill_tail1))]+"\n"NOR;   
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = skill_head1[5]+skill_tail1[random(sizeof(skill_tail1))]+"\n"NOR;   
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        
        me->add_temp("apply/attack", -extra);
        me->add_temp("apply/damage", -2200);

        //me->receive_damage("jing", 100);
        me->add("neili", -100);

        me->start_busy(2);
        return 1;
}



