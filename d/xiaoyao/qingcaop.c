// qingcaop.c
// by shilling 97.2

inherit ROOM;

void create()
{
        set("short", "���ƺ");
        set("long", @LONG
�����������е�һƬ�Ƚϴ�Ŀյأ���Ի�����ƺ����Ϊ��������֮��
��������ƽʱ���������������ǲ�֪��Ϊʲô������ȴ�������˼����֡���
������һ�����ˡ�
LONG );
	set("exits", ([
		"north" : __DIR__"xiaodao3",
		"south" : __DIR__"xiaodao5",
		"east" : __DIR__"xiaodao4",
		"west" : __DIR__"xiaodao1",
	]));
	//set("roomif","$botten#��������|��������|�������|�Ͻ���Ʒ|��ȡ����|ȡ������|����|����|Ѱ������|Ѱ��ʧ��|�Ͻ�����:job|quest|ask shi about teamjob|give <��Ʒ> to shi|ask shi about gongxian|give 20 silver to shi|ask su about ����|ask su about ����|ask su about job|ask su about ʧ��|give <��Ʒ> to su$#");
	set("roomif","$botten#��������|��������|�������|�Ͻ���Ʒ|��ȡ����|ȡ������|����|����|Ѱ������|Ѱ��ʧ��:job|quest|ask shi about teamjob|give <��Ʒ> to shi|ask shi about gongxian|give 20 silver to shi|ask su about ����|ask su about ����|ask su about job|ask su about ʧ��$#");
	set("outdoors", "xiaoyao");
	set("objects", ([
		"quest/menpaijob/xiaoyao/suxingh": 1,
		"/d/biwu/champion_xy": 1,
"/d/xiaoyao/npc/dizi" : 4,	
    "/quest/menpai/xiaoyao/shi" : 1,
	]));
	set("valid_startroom", 1);
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
	"/clone/board/xiaoyao_b"->foo();
}