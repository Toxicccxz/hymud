#include <ansi.h>
inherit NPC;
int ask_pearl();
void create()
{
 set_name("����֥", ({ "jin lingzhi","jin" }) );
 set("nickname", HIR"����"NOR );
 set("gender", "Ů��" );
 set("age", 22);
 set("str",20);
 set("max_qi",100);
 set("long",
"��ֱ������ӣ���죬һ˫�۾��ִ�����������Ҳ�Ҳ�����ô�������ǡ� \n" );
 set("combat_exp", 50000);
 set("chat_chance", 1);
 set("chat_msg", ({
 "����֥��������͵���ӵ��������ܵ�������ҲҪ�ҵ��㣡\n",
 "����֥С���ֹ�������ʵ��Ҳ������ȫ��׽���ģ�����֮�£�ʲô�ط��Ҷ���ʶ����\nֻ�����ֵط�û�������Ҿ�ƫ��ȥ���ƣ�����˭�Ұ��Ҹϳ�ȥ! \n",
        }) );
 set("attitude", "friendly");
 set("inquiry",([
        "����" : (: ask_pearl :),
        "pearl" : (: ask_pearl :),
    ]) );
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
(: perform_action, "sword.ai" :),
(: perform_action, "parry.wushuang" :),	
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :)
        }) );
/*
        set("inquiry", ([
            "��ʦ": (: out_master :),
        ]) );
*/            set("max_qi", 5000);
        set("max_jing", 2000);
        set("max_neili", 5000);
        set_skill("unarmed", 180);
        set_skill("sword", 200);
        set_skill("force", 200);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("literate", 100);
         set_skill("chongling-jian", 380);
        set_skill("huashan-sword", 200);
        set_skill("yunu-sword", 380);
        set_skill("zixia-shengong", 320);
        set_skill("huashan-ken", 200);
        set_skill("feiyan-huixiang", 200);
        set_skill("zhengqijue", 200);

        map_skill("sword", "chongling-jian");
        map_skill("parry", "yunu-sword");
        map_skill("force", "zixia-shengong");
        map_skill("unarmed", "huashan-ken");
        map_skill("dodge", "feiyan-huixiang");
 
 setup();
 carry_object("/clone/misc/cloth")->wear();

        carry_object("/clone/weapon/changjian")->wield();
}
void release_status(object player)
{
        
        //actually no need to delete marks, since the object will be destructed.
        //just for good habit.
        delete("marks/inaction");
        delete("marks/inask");
        if (player && present(this_object(),environment(player)))
        {
                message_vision("$N�����غ����������������������裬���׸�������ȥץ�����㲻ȥ���Լ�ȥ����\n",this_object());
                message_vision("$N�������뿪�ˡ�\n",this_object());
                destruct(this_object());
        }
        
}
int ask_pearl()
{
        object player;
        player = this_player();
        if (query("marks/inaction") || player->is_fighting(this_object()))
        {
                tell_object(player,"����֥��������æ��û�����㡣\n");
                return 1;
        }
        //check if jin is in her room
        if (base_name(environment()) != this_object()->query("startroom"))
        {
                message_vision("$Nһ˫���۾�����$n:���и���͵���ҵ����ӣ��ܽ���Ȫ���ˡ���\n",this_object(),player);
                return 1;
        }
        set("marks/inaction",1);
        set("marks/inask",1);
        set ("no_arrest",1);
        message_vision("$Nһ˫���۾�����$n:���и���͵���ҵ����ӣ��ܽ���Ȫ���ˡ���λ"+RANK_D->query_respect(player)+"
����׳׳������ȥ����ץ�����ò��ã���(answer yes/no) \n",this_object(),player);
        add_action("do_answer","answer");
        call_out("release_status",30,player);
        return 1;
}
void in_bathroom(object player)
{
        object tiehua,jin,dingfeng;
        jin = this_object();
        set("chat_chance", 0);
        if (!tiehua = present("nakedman",environment(jin)))
        {
                message_vision("$N�������������������Ҫ�ҵ������ڲ����ڡ������´������ɣ���\n",jin);
                if (player && present(player,environment()))
                {
                        message_vision("$N��$n������λ"+RANK_D->query_respect(player)+"���Ƕ�л���ˡ�\n",jin,player);
                }
                message_vision("$Nת����ȥ��\n",jin);
                destruct(jin);
                return;
        }
        message_vision("$N��$n��е����������͵���ӵ������������ӣ���\n\n",jin,tiehua);
        message_vision("$NЦ�����������������Ǻõ�������ϧ����һ�㡣
��������Ҳ������ˮ�������������е��ӡ��б��¡���\n\n",tiehua);
        message_vision("$N�����������ˣ�ͻȻ����һ���������ŵ��Ͻ����\n",jin);
        carry_object("/clone/weapon/gangjian");
        jin->command("wield sword");
        message_vision("\n$N��$n�ȵ������������ղ������������һ�� \n\n",jin,tiehua);
        message_vision("$Nʹ�������ʮ��ʽ���еڰ�ʽ���綯ǧ�塱ֱָ$n��ȥ��
��������������������˷���ȴ�ֲ��嵽����һ�����죡\n\n",jin,tiehua); 
        //have to use call out, too many messages :(
        call_out("bathroom_actiontwo",3,player);
}
void bathroom_actiontwo(object player)
{
        object jin, dingfeng;
        jin = this_object();
        message_vision("������ʱ��ͻ����Ӱһ����һ����������б���˽���!�������úÿ�! \n\n",jin);
        dingfeng = new(__DIR__"dingfeng");
        dingfeng->move(environment());
        message_vision("ֻ�����ġ���һ����$N�Ľ�����������ֻ�ּ�ס! \n\n",jin);
        message_vision("$N΢Ц�ŵ��������ղ����������Ľ��������ˣ���һ�С�������ѩ��ʹ�õ����� 
�������㣬���ڽ��ȣ����������ɻ����ʦֻ��Ҳ����Ϊ������������� \n\n",dingfeng);
        if (player && present(player,environment()))
        {
                tell_object(player,"�㲻���ɻ��������֥����ʹ���������ǡ����ʮ��ʽ���еڰ�ʽ���綯ǧ�塱������Ϊ��ƫƫҪָ¹Ϊ����? \n\n");
        }
        message_vision( "$N�ֵ�������λ���ѣ��������ϵõģ���������￴���±��棬�Ź��˰ɡ���\n\n",dingfeng );
        message_vision("$N��Ȼ����ŭ�ݣ�����Ȼ������������$nһ��ת�����ߡ�\n",jin,dingfeng);
        //dingfeng->move("/d/tieflag/huashan/path1");
        //jin->move("/d/tieflag/huashan/path1");
        message_vision("$N��$n�򶫱߻�����С����ȥ���ܿ���ʧ�ˡ�\n",jin,dingfeng );
        //delete("marks/inaction");
        //for caution, we should find that room again.
        //but jin won't be able to act in other place, let's leave it this way.
        //this_object()->move("/d/tieflag/huashan/path1");

        player->move("/d/tieflag/huashan/path1");
        environment(player)->open_path();
        destruct(dingfeng);
        destruct(jin);
        
        
}
int do_answer(string arg)
{
        object player,jin;
        player = this_player();
        jin = this_object();
        if (arg != "no" && arg != "yes")
        {
                return notify_fail("��ֻ�ܻش�yes/no��\n");
        }
        if (!query("marks/inask"))
        {
                return 0;
        }
        remove_call_out("release_status");
        delete("marks/inask");
   if (arg == "yes")
        {
                if ((string)player->query("gender")=="����")
                {
                        message_vision("$N�Ǻ�Ц����������С���ﵨ�Ӳ�С����ʲô�ط�����ȥ���ã��� 
�������ȥץ������\n",player);
                }else
                {
                        message_vision("$N��������͵͵Ц������������������Ҳû��ʶ�������� 
$N˵�����ã����ǽ�ȥץ������\n ",player);
                }
                player->move("/d/tieflag/huashan/yupond");
                jin->move("/d/tieflag/huashan/yupond");
                message_vision("$Nһ˫���۾�ת��תȥ��ˮ�����ÿ�����˶������ɵ�ͷƤ������\n",jin);
                call_out("in_bathroom",3,player);
                return 1;
        }
        if (arg == "no")
        {
                if ((string)player->query("gender")=="����")
                {
                        message_vision("$N��$n�Ǻ�Ц����������С���ﵨ�Ӳ�С���������˵����ÿɲ� 
����ȥ�ĵط����� \n",player,jin);
                }else
                {
                        message_vision("$N����$n�����룺��СѾͷ���ˡ� 
$N˵�������˵����ã�Ů������ô�ܽ�ȥ�أ��� \n",player,jin);
                }
                message_vision("$n�����ص���$Nһ�ۣ�ת��ͷ������$N�ˡ� \n",player,jin);
                delete("marks/inaction");
                delete("no_arrest");
                return 1;
        }
} 
int return_home(object home)
{
        //if jin is in action, don't make her returning home
        if (query("marks/inaction"))
        {
                return 1;
   }
        ::return_home(home); 
}    