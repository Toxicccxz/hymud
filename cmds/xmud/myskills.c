//Cracked by Roath
// skills.c

#include <ansi.h>

inherit F_CLEAN_UP;

string *skill_level_desc = ({
"初学乍练","初窥门径","粗通皮毛",
"略知一二","半生不熟","马马虎虎",
"略有小成","已有小成","渐入佳境",
"驾轻就熟","了然于胸","出类拔萃",
"略有大成","已有大成","心领神会",
"无可匹敌","神乎其技","出神入化",
"豁然贯通","登峰造极","技冠群雄",
"举世无双","一代宗师","震古铄今",
"傲视群雄","所向披靡","惊世骇俗",
"独步天下","深不可测","返朴归真", 
"天下无敌"
});

string *knowledge_level_desc = ({
"新学乍用","不甚了了","不知端倪",
"平淡无奇","司空见惯","初窥门径",
"略知一二","茅塞顿开","略识之无",
"滚瓜烂熟","马马虎虎","轻车熟路",
"运用自如","触类旁通","深入浅出",
"已有小成","心领神会","了然於胸",
"见多识广","无所不通","卓尔不群",
"满腹经纶","豁然贯通","博古通今",
"博大精深","超群绝伦","举世无双",
"独步天下","震古铄今","超凡入圣",
"深不可测"
});

string skill_level(string, int);

int main(object me, string arg)
{
        object ob;
        mapping skl, lrn, map;
        string *sname, *mapped;
        int i,j;

        seteuid(getuid());

        if(!arg)
                ob = me;
        else{
                ob = present(arg, environment(me));
                if (!ob) ob = find_player(arg);
                if (!ob) ob = find_living(arg);
                if (!ob) return notify_fail("你要察看谁的技能？\n");
        }

        if( ob!=me && !wizardp(me) && !ob->is_apprentice_of(me)
        && !me->is_apprentice_of(ob) && !ob->is_spouse_of(me) && !ob->is_baby_of(me))
                return notify_fail("你要察看谁的技能？\n");
			//Add !me->visible(me) by play 2002.7.28  
			// temp removed !me->visible(me) because bug by Xuanyuan

        skl = ob->query_skills();
        if(!sizeof(skl)) {
                write("$mybase#"+(ob==me ? "你" : ob->name()) + "目前并没有学会任何技能。\n");
                return 1;
        }
        sname  = sort_array( keys(skl), (: strcmp :) );
        
        map = ob->query_skill_map();
        if( mapp(map) ) mapped = values(map);
        if( !mapped ) mapped = ({});

        lrn = ob->query_learned();
        if( !mapp(lrn) ) lrn = ([]);
        for(i=0; i<sizeof(skl); i++) {
                if(SKILL_D(sname[i])->type()=="knowledge"){
                j=j+1;
                }
        }
        //if(j>0) { printf("$mybase#┌%16s  ───────────────────────┐\n", ""+chinese_number(j)+"项知识");}
        for(i=0; i<sizeof(skl); i++) {
        	if(SKILL_D(sname[i])->type()=="knowledge"){
                printf("$mybase#%s%s%-30s" " - %3d/%6d %-5s \n", 
                        (member_array(sname[i], mapped)==-1? "  ": "□"),
                        (member_array(sname[i], mapped)==-1? "  ": "□"),
                        (to_chinese(sname[i]) + " (" + sname[i] + ")"),
                        skl[sname[i]], (int)lrn[sname[i]],
                        skill_level(SKILL_D(sname[i])->type(), skl[sname[i]])
                );
                }
        }
        j=0;
        for(i=0; i<sizeof(skl); i++) {
        	if(SKILL_D(sname[i])->type() != "knowledge" && (sname[i] == "force" || sname[i] == "cuff" || sname[i] == "strike" || sname[i] == "finger" || sname[i] == "claw" || sname[i] == "hand" ||sname[i] == "unarmed" || sname[i] == "kick" || sname[i] == "sword" || sname[i] == "blade" || sname[i] == "club" || sname[i] == "pike" || sname[i] == "staff" || sname[i] == "stick" || sname[i] == "hook" ||  sname[i] == "dodge" ||  sname[i] == "parry" || sname[i] == "whip" || sname[i] == "hammer" || sname[i] == "begging" || sname[i] == "training" || sname[i] == "checking" || sname[i] == "digging" || sname[i] == "swimming" || sname[i] == "feixing-shu" || sname[i] == "archery" || sname[i] == "throwing" || sname[i] == "jinshe-zhuifa" || sname[i] == "axe" || sname[i] == "beidou-zhenfa" )){
        	j=j+1;
                }
        }
        //if(j>0) { printf("$mybase#┌%16s  ───────────────────────┐\n", ""+chinese_number(j)+"项基本功夫");}
        for(i=0; i<sizeof(skl); i++) {
        	if(SKILL_D(sname[i])->type() != "knowledge" && (sname[i] == "force" || sname[i] == "cuff" || sname[i] == "strike" || sname[i] == "finger" || sname[i] == "claw" || sname[i] == "hand" ||sname[i] == "unarmed" || sname[i] == "kick" || sname[i] == "sword" || sname[i] == "blade" || sname[i] == "club" || sname[i] == "pike" || sname[i] == "staff" || sname[i] == "stick" || sname[i] == "hook" ||  sname[i] == "dodge" ||  sname[i] == "parry" || sname[i] == "whip" || sname[i] == "hammer" || sname[i] == "begging" || sname[i] == "training" || sname[i] == "checking" || sname[i] == "digging" || sname[i] == "swimming" || sname[i] == "feixing-shu" || sname[i] == "archery" || sname[i] == "throwing" || sname[i] == "jinshe-zhuifa" || sname[i] == "axe" || sname[i] == "beidou-zhenfa" )){
                printf("$mybase#%s%s%-30s" " - %3d/%6d %-5s \n", 
                        (member_array(sname[i], mapped)==-1? "  ": "□"),
                        (member_array(sname[i], mapped)==-1? "  ": "□"),
                        (to_chinese(sname[i]) + " (" + sname[i] + ")"),
                        skl[sname[i]], (int)lrn[sname[i]],
                        skill_level(SKILL_D(sname[i])->type(), skl[sname[i]])
                        
                );
                }
        }
        //if(j>0) { write("$mybase#└────────────────────────────────┘\n");}

	j=0;
        for(i=0; i<sizeof(skl); i++) {
        	if(SKILL_D(sname[i])->type() != "knowledge" && (sname[i] != "force" && sname[i] != "cuff" && sname[i] != "strike" && sname[i] != "finger" && sname[i] != "claw" && sname[i] != "hand" && sname[i] != "kick" && sname[i] != "sword" && sname[i] != "blade" && sname[i] != "club" && sname[i] != "pike" && sname[i] != "staff" && sname[i] != "stick" && sname[i] != "hook" && sname[i] != "dodge" && sname[i] != "parry" && sname[i] != "whip" && sname[i] != "hammer" && sname[i] != "begging" && sname[i] != "training" && sname[i] != "checking" && sname[i] != "digging" && sname[i] != "swimming" && sname[i] != "feixing-shu" && sname[i] != "archery" && sname[i] != "throwing" && sname[i] != "jinshe-zhuifa" && sname[i] != "axe"&& sname[i] != "unarmed" && sname[i] != "beidou-zhenfa" )){
        	j=j+1;
                }
        }
        //if(j>0) { printf("$myski#┌%16s  ───────────────────────┐\n", ""+chinese_number(j)+"项特殊功夫");}
        for(i=0; i<sizeof(skl); i++) {
        	if(SKILL_D(sname[i])->type() != "knowledge" && (sname[i] != "force" && sname[i] != "cuff" && sname[i] != "strike" && sname[i] != "finger" && sname[i] != "claw" && sname[i] != "hand" && sname[i] != "kick" && sname[i] != "sword" && sname[i] != "blade" && sname[i] != "club" && sname[i] != "pike" && sname[i] != "staff" && sname[i] != "stick" && sname[i] != "hook" && sname[i] != "dodge" && sname[i] != "parry" && sname[i] != "whip" && sname[i] != "hammer" && sname[i] != "begging" && sname[i] != "training" && sname[i] != "checking" && sname[i] != "digging" && sname[i] != "swimming"  && sname[i] != "feixing-shu" && sname[i] != "archery" && sname[i] != "throwing" && sname[i] != "jinshe-zhuifa" && sname[i] != "axe"&& sname[i] != "unarmed" && sname[i] != "beidou-zhenfa" )){
                printf("$myski#%s%s%-30s" " - %3d/%6d %-5s \n", 
                        (member_array(sname[i], mapped)==-1? "  ": "□"),
                        (member_array(sname[i], mapped)==-1? "  ": "□"),
                        (to_chinese(sname[i]) + " (" + sname[i] + ")"),
                        skl[sname[i]], (int)lrn[sname[i]],
                        skill_level(SKILL_D(sname[i])->type(), skl[sname[i]])
                        
                );
                }
        }
        write("$#\n");
        //if(j>0) { write("$myski#└────────────────────────────────┘\n");}
        return 1;
}

string skill_level(string type, int level)
{
        int grade;

        grade = level / 20;

        switch(type) {
                case "knowledge":
                        if( grade >= sizeof(knowledge_level_desc) )
                                grade = sizeof(knowledge_level_desc)-1;
                        return knowledge_level_desc[grade];
                default:
                        if( grade >= sizeof(skill_level_desc) )
                                grade = sizeof(skill_level_desc)-1;
                        return skill_level_desc[grade];
        }
}

int help(object me)
{
        write(@HELP
指令格式 : skills|cha [<某人>]

这个指令可以让你(你)查询所学过的技能。

你也可以指定一个和你有师徒关系的对象，用 skills 可以查知对方的技能状况。

巫师可以查询任何人或 NPC 的技能状况。

HELP
    );
    return 1;
}
