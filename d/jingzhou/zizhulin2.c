// Room: zizhulin
// congw 980829
inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������һƬ���̵İ�Χ֮�У�������ʧ�˷���
LONG
	);
        set("outdoors", "jingzhou");

	set("exits", ([
	"southdown" : __DIR__"zizhulin3",
	"north" : __DIR__"zizhulin1",
	"southup" : __DIR__"zizhulin3",
	"northdown" : __DIR__"zizhulin",
]));
	setup();
	replace_program(ROOM);
}
