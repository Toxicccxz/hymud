#include <ansi.h>
#include <diary_write.h>

void init()
{
//        ::init();
        add_action("do_chat", "chat");
        add_action("do_chat","chat*");
        add_action("do_jiehun","jiehun");
        add_action("do_jiehun","marry");
        add_action("do_lihun","lihun");
}
int do_chat()
{
   object ob;
   ob=this_player(1);
  
   say(HIW "֪����ɫһ�����ȵ���������֮�ϣ�������������\n" NOR);
   tell_object(ob, HIR "�������۳���ǰ�������ɷ�˵��һ��������"
                  +"Ƥ������,���˹�ȥ��\n" NOR);
   ob->unconcious();
   return 0;
}


int do_lihun(string arg)
{
object me;
object ob;
object card;

object *inv;
int i;

me=this_player(1);

if(!arg)   {
             tell_object(me,"��Ҫ��˭��鰡��\n");
             return 1;
            }

if( !objectp(ob = find_player(arg)))
         {
            tell_object(me,"������᲻�ڡ�\n");
            return 1;
         }


 say(me->query("name")+"��Ҫ��"+ob->query("name")+"���.\n");

      if( me->query("couple/couple_id") !=arg )
        {
          say("֪���ɻ�Ŀ��˿�"+me->query("name")+
                "˵������û���������\n");
          return 1;
        }

      if(!me->query("couple/have_couple"))
        {
         say("֪�����ȵ���"+me->query("name")+
             "����û�а��£�������?��\n");
         return 1;
        }

      if(!present(arg,environment()))
        {
         say("֪��ҡҡͷ˵:��"+ob->query("name")+"���ڲ��������\n");
         return 1;
        }
      if( ob->query("want_lihun")==me->query("id") )
        {
         say("֪��̾Ϣ�������������ñ���ʧ������\n");

         inv=all_inventory(me);
         for(i=0;i<sizeof(inv);i++)      
            {
             if(inv[i]->query("id")=="jiehunzheng") 
              {
                destruct(inv[i]);
              }
            }
         inv=all_inventory(ob);
         for(i=0;i<sizeof(inv);i++)
            {
             if(inv[i]->query("id")=="jiehunzheng")
              {
                destruct(inv[i]);

              }
            }

         me->delete("couple");
         me->delete("want_marry");
         me->delete("want_lihun");
         me->delete("marry_ok");
         ob->delete("couple");
         ob->delete("want_marry");
         ob->delete("want_lihun");
         ob->delete("marry_ok");
         tell_object(me,"��Ļ�����ϵ�������\n");
         tell_object(ob,"��Ļ�����ϵ�������\n");
        diary_write(me,"��"+ob->query("name")+"������ϵ�������");
        diary_write(ob,"��"+me->query("name")+"������ϵ�������"); 
        message("shout", HIC "���ٸ�ͨ�桿��" + HIB + "�ֽ�" + me->query("name") + "��" 
         +ob->query("name") + "������ϵ�����\n" NOR,users());        
      }
      else
        {
         say("֪����:��"+me->query("name")+"����뷨��֪����"+
             ",������Ҫ����"+ob->query("name")+"����˼����\n");
         me->set("want_lihun",arg);
         return 1;
        }

return 1;
}



int do_jiehun(string arg)
{
object me;
object ob;
object card;
string mes1;
me=this_player(1);

if ( me->query("gender")=="����") 
           
           { tell_object(me,"�����޸�֮����ν�飿\n");
             return 1;}
if(!arg)   {
             tell_object(me,"���Լ����Լ���鰡��\n");
             return 1;
            }

if( (string)me->query("class")=="bonze" ) 
            {
             tell_object(me,"��������ô������Ҳ�뿪ɫ������?\n");
             return 1;
            }

if( !objectp(ob = find_player(arg)))
         {
            tell_object(me,"�������Ŀǰ����������ɣ�\n");
            return 1;
         }


      say(me->query("name")+"��Ҫ��"+ob->query("name")+"���.\n");
      
      if(me->query("age") <16)
        {
         say("֪��ҡҡͷ����Ȼ��û�ﵽ������䡣\n");
         return 1;
        }

      if(me->query("couple/couple_id")== arg )
        {
          say("֪���ɻ�Ŀ��˿�"+me->query("name")+
                "˵������������飿��\n");
          return 1;
        }
      if(me->query("id")== arg )
        {
          say("֪���ɻ�Ŀ��˿�"+me->query("name")+
                "˵:�����������񰡣���\n");
          return 1;
        }
      if(me->query("couple/have_couple")) 
        {
         say(HIW "֪����ŭ��һ�����Ӻȵ�����"+me->query("name")+
             "�����а��£������ػ飡��\n" NOR);
         say("�������۳���ǰ�������ɷ�˵��һ������"+
               me->query("name")+"Ƥ������,���˹�ȥ��\n");
         me->unconcious();
         return 1;
        }
      
if(!present(arg,environment()))
        {
         say("֪��ҡҡͷ˵:��"+ob->query("name")+"���ڲ��������\n");
         return 1;
        }
      if( ob->query("want_marry")== me->query("id") )
        {
         say("֪��΢Ц������ף��������ͷг�ϣ����޶��ġ���\n");   
         
         ob->set("couple/have_couple",1);
         ob->set("couple/couple_id", me->query("id"));
         ob->set("couple/couple_name", me->query("name"));
         if (me->query("gender")=="����")
          { ob->set("couple/couple_gender","�Ϲ�");}
         else
           { ob->set("couple/couple_gender","����");}
         
         me->set("couple/have_couple",1);
         me->set("couple/couple_id",ob->query("id"));
         me->set("couple/couple_name",ob->query("name"));
         if (ob->query("gender")=="����")
          { me->set("couple/couple_gender","�Ϲ�");}
         else
           {me->set("couple/couple_gender","����");}

         card= clone_object(__DIR__"obj/marry_card");
         card->set("name","���"+arg+"�Ľ��֤");
         card->move(me);
         card= clone_object(__DIR__"obj/marry_card");
         card->set("name","���"+me->query("id")+"�Ľ��֤");
         card->move(ob);
         say("֪���ݸ�"+ob->query("name")+"��"+me->query("name")
                  +"һ��һ�Ž��֤��.\n");
         diary_write(me,"��"+ob->query("name")+"ϲ������");
         diary_write(ob,"��"+me->query("name")+"ϲ������");
         me->delete("want_marry");
         ob->delete("want_marry");
         message("shout", HIC "���ٸ�ͨ�桿��" + HIR + "��ϲ" + me->query("name") + "��" 
         +ob->query("name") + "ϲ��������\n"+"\n"+
         " 
         ��        �� 
    ����������������������
         ��        ��
     ��������������������
       ������    ������
       ��  ��    ��  ��
       ������    ������
        ����      ����
     ��������������������
       ������    ������
       ��  ��    ��  ��
       ������    ������\n"             
          NOR,users());
         return 1 ;
       } 
      else
        {
         if( me->query("gender") == ob->query("gender") )
          {
           say ("֪����"+me->query("name")+
                  "���ÿ��°�ĭ���˹�ȥ���ȵ�����Ī�����ж���֮񱣿��\n");
           return 1;
          }
         say("֪��΢Ц��:��"+me->query("name")+",���������֪����"+
             ",������Ҫ����"+ob->query("name")+"����˼����\n");
         me->set("want_marry",arg);
         return 1;
        }

return 1;
}
