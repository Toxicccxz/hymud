// Room: /d/jinghai/jhd29.c

inherit ROOM;

void create()
{
	set("short", "ľ������");
	set("long", @LONG
�߽�����һ��ɼľ������ֱ�����ܣ�ľ����ÿ������ﶼ��
���˵�һ��ְҵ��������Ҫ���ڱ��Ī��Ĵ��ﱣס�����⿿
���������ӻ��ǲ����ģ�����Ҫ�����������ѵĴ��ܹ�������
���˵��Ĵ����Լ���ÿ��������һ�������ľ������������
�İڷ��Ÿ���ľ�����ߺ��ٵñ�ֱ�⻬��Բľ��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"jhd28",
]));

	setup();
	replace_program(ROOM);
}