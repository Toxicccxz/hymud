// Room: /d/yanjing/to_yj.c

inherit ROOM;

void create()
{
	set("short", "ʢ�����");
	set("long", @LONG
������������ֱͨ[��]�Ķ���[ʢ��],�������Ǹ�����·��,�ֱ�ͨ
��Į���ɹź;���,���ϵĻ�ѩ��δ��ȫ�ܻ�,�����Ѿ����ɱ���,����ȥ,
֨֨����.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : "/d/ny/droad2",
  "northeast" : __DIR__"to_yj1",
]));
	set("outdoors", "yanjing");

	setup();
	replace_program(ROOM);
}