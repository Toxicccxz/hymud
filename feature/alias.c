#include <ansi.h>
// alias.c
#pragma save_binary
#include <command.h>
#include <login.h>
#define MAX_REPEAT 50
#define MAX_ALIASES 40
#define HISTORY_BUFFER_SIZE 10
mapping alias;
static string *history, last_input;
static int last_cmd, repeat_cnt = 0;
static int last_time=time(), cmd_cnt=0, cmd_cnt1=0, cmd_cnt2=0;
string process_input(string str)
{
    string *args, command, argstr,verb,arg,file,cmd;
    int i, j,curr_time;
    int cq, cj;
    object ob,dest;
    object me = this_player();
    if (!me ) return "什么？";
    if (userp(me))
    	{
if (userp(me) && me->is_ghost() && !environment(me)->query("deathroom"))
{
                message_vision(HIC "死人怎么到阳间来了?一阵阴气包围了$N。\n" NOR, me);
                message_vision(HIG "$N的魂魄回到了阴间。\n" NOR, me);
		me->set("jing", 10);
		me->set("eff_jing", 10);
		me->set("qi", 10);
		me->set("eff_qi", 10);
		me->move(DEATH_ROOM);
}
}
    if (!query_heart_beat(me))
    {
    write("由于你没有心跳，请重新登陆!!\n");
    "/cmds/usr/quithy"->main(me);
    }
    if( !me )   return "什么？";
    if( me->query_temp("testrobot") )   return "什么？";
    if( me->query_temp("disable_inputs") )   return HIR"什么？\n"NOR;
    if( me->query_temp("block_msg/all") )   return HIR"你看不见什么,什么都不能做!\n"NOR;
	if(!living(this_object())) return "";
	if(str && str != "")
	cmd_cnt++;
	if(cmd_cnt>60) {  //threshold for how many commands can be
			  //input every few seconds.(determined below)
	curr_time=time();

	if(me && curr_time-last_time<5) {
		if(cmd_cnt1==0){
		cmd_cnt2=cmd_cnt/(curr_time-last_time+1);
		
write("你一次输入太多命令了，
请稍后再试！\n");
	}
	cmd_cnt1++;
	if(cmd_cnt1> 60) cmd_cnt1=0;
		last_time=curr_time;
	     //in case of flooding, has to wait a few
	     //seconds without input to be able to
	     //input again.
		return "";  //flooding detected. ignore input.
	} else {
			cmd_cnt2=cmd_cnt/(curr_time-last_time+1);
			last_time=curr_time;
			cmd_cnt=0;
			cmd_cnt1=0;
		}
	}
 
	if( str[0]=='!' ) {
		if( pointerp(history) && sizeof(history) ) {
			if( sscanf(str, "!%d", i) )
				str = (string)history[(HISTORY_BUFFER_SIZE + last_cmd - i) % 
HISTORY_BUFFER_SIZE];
					else
				str = history[last_cmd];
			} else
			return "";

		} else {
			if( !pointerp(history) ) history = allocate(HISTORY_BUFFER_SIZE);
			last_cmd = (last_cmd + 1) % HISTORY_BUFFER_SIZE;
			history[last_cmd] = str;
		}

	if( mapp(alias) ) {

		if( !undefinedp(alias[str]) )
			return replace_string( alias[str], "$*", "" );

		if( sscanf(str, "%s %s", cmd, argstr)==2 && 
!undefinedp(alias[cmd]) ) {
			cmd = replace_string( alias[cmd], "$*", argstr );
			args = explode(argstr, " ");
			if( (j = sizeof(args)) )
				for(i=0; i<j; i++)
					cmd = replace_string( cmd, "$" + (i+1), args[i] );
			return cmd;
		}
	}

    command=(string)ALIAS_D->process_global_alias(str);
  if (command=="south" && environment(me)->query("hxsdmigong")) command="go south";
	if (command=="north" && environment(me)->query("hxsdmigong")) command="go north";
	if (command=="west" && environment(me)->query("hxsdmigong")) command="go west";
	if (command=="east" && environment(me)->query("hxsdmigong")) command="go east";

        if( this_object()->query_encoding() )
                str = LANGUAGE_D->toGB(str);

    if (!living(this_object())){
        if (sscanf(command,"%s %s",verb,arg)!=2) verb=command;
        file="/cmds/usr/"+verb+".c";
      if (file_size(file)>0){
         file->main(this_object(),arg);
         return "";
      }
        else if( EMOTE_D->do_emote( this_object(), verb, arg ) )
            return "";
        else if( CHANNEL_D->do_channel( this_object(), verb, arg ) )
            return "";
    }
    return command;
}
int set_alias(string verb, string replace)
{
	if( !replace ) {
		if( mapp(alias) ) map_delete(alias, verb);
		return 1;
	} else {
		if( !mapp(alias) ) alias = ([ verb:replace ]);
		else if( sizeof(alias) > MAX_ALIASES )
        return notify_fail("您设定的 alias 太多了，请先删掉一些不常用的。\n");		else alias[verb] = replace;
		return 1;
	}
}
mapping query_all_alias()
{
    return alias;
}