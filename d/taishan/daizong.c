// Room: /d/taishan/daizong.c
// Last Modified by winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "��ڷ�");
	set("long", @LONG
��ڷ����������緻��λ��̩���س��Ա�Լһ�������̨���ϣ�
��������ʽ���������׫����������������죬�޻���Ԫ������۳�
���𣬺�������򶫷������˴��ǵ�̩ɽ����ڡ��ഫ�����ϼԪ����
������ϷŪ������Ͷ���廨Ь�Զ�̩ɽ�ؽ磬�����ϼԪ��ֻ�ܰ��廨
Ь��ɽ�������˴����Ӵ�̩ɽ���Դ�Ϊ��㡣
���������ᶼ������ᶼ��ۣ�����ڤ��ʮ��������������������ˡ�
��ũ���Ƶۣ����԰����񡣷�������Ժ������������Ϊ��Ԫ�ۣ��붫
�����񶫻��۾��������ɰ���������ʯ������ϪȪ������
LONG );
	set("exits", ([
		"northup" : __DIR__"baihe",
		"south"   : __DIR__"daimiao",
		"north"   : "/d/tieflag/taishan/daizong",
		"southwest"   : "/d/jinan/road4",	
		"west"    : "/d/huanghe/huanghe5",
	]));
	set("objects", ([
  "/clone/misc/dache" : 1 ,
		"/quest/shan" :1,
		"/quest/jianghu/shi" :1,

	]));
		set("roomif","$botten#��������|ȡ������|��������:quest|give 20 silver to shan|give <��Ʒ> to xuan du$#");
	//set("no_fight", "1");
	set("outdoors", "taishan");
	set("coor/x", 400);
	set("coor/y", 530);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}