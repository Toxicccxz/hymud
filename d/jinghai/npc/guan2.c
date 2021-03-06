#include <ansi.h>

inherit NPC;

int ask_book(object who,string topic);
int ask_all(object who);

protected string *books = ({
"jingyiforce",
"bibo-sword",
"fengyu-piaoxiang",
});

protected string all_msg;

protected void make_book_msg()
{
	if( !all_msg )
		all_msg = "";

	foreach(string tmp in books)
		all_msg += sprintf("    %s(%s)\n", to_chinese(tmp), tmp);
}

void create()
{
        set_name("年轻管事", ({ "guan shi","guan" }) );

	
        set("class","jinghai");
        set("title","明月寨");

        set("gender", "男性" );
        set("age", 33);
        set("long", "这是一位儒生打扮得中年汉子。\n");
        set("attitude", "peaceful");
        set("inquiry",([
	"book" : (: ask_all :),
        "借书" : (: ask_book :),
]));
 
        set("combat_exp", 300000);
        set("str", 67);
        set("max_qi",1200);
        set("qi",1200);
        set("max_jing",1200);
        set("jing",1200);
        set("max_sen",1200);
        set("sen",1200);
        set("neili", 1200);
        set("max_neili", 1200);
        set("atman", 1200);
        set("max_atman", 1200);
        set("mana", 1200);
        set("max_mana", 1200);
        set("force_factor", 100);

        set_skill("unarmed",260);
        set_skill("dodge",260);
        set_skill("parry",250);
        set_skill("force",200);

	make_book_msg();
        setup();
 
        carry_object("/clone/misc/cloth")->wear();
}

int ask_book(object who,string topic)
{
        int n;
        string file;
        object book_ob;

        if(!who
	|| (who->query("class") != "jinghai")
	|| !stringp(topic)
	|| !environment()
	|| (base_name(environment()) != query("startroom")) )
		return 0;

        if( ((n = member_array(topic,books)) == -1)
        && ( (n = member_array(topic,map_array(books,(: to_chinese :)))) == -1))
                return 0;
 
        file = sprintf(__DIR__"obj/%s_book",books[n]);
        if(file_size(file+".c") <= 0 || !book_ob = new(file))
                return 0;

        message_vision(sprintf("$N从身后拿出一本%s交给了$n。\n",book_ob->name()),
                this_object(),who);
        book_ob->move(who);

        command("say 奉寨主之命，本派典籍不可携出书房。\n");
        return 1;
}

int accept_object(object who,object ob)
{
        if(!who || !ob)
                return 0;

        if(ob->is_jinghai_book())
        {
                call_out("destruct_book",1);
                return 1;
        }
        else
                return 0;
}

void destruct_book()
{
        int i,n;
        object *inv;

        inv = all_inventory(this_object());
        if(!n = sizeof(inv))
                return;

        for(i=0;i<n;i++)
                if(inv[i]->is_jinghai_book())
                        destruct(inv[i]);
}

int ask_all(object who)
{

	tell_object(who, sprintf("\n管事说道：我这只有这些武功的入门书籍：\n%s\n", all_msg));
	return 1;
}
