 inherit ROOM;
void create()
{
        set("short", "ʮ����");
        set("long", @LONG
ɽ·����������У������ɼ���᾵Ĺ�ʯ���ң��������������ٻ��ƣ���ãã
��ɽ���п�ȥ����������ɭ�ɲ�������˱����µĵ��ƣ������ɽ��ʯ�䣬���ﴩ
�С�Ũ���в�ʱð��һ��˫������â�Ĺ��ۺݺݵض����������
LONG); 
        set("type","road");
        set("exits",([
        "northdown":__DIR__"18pan4",
        "southeast":__DIR__"18pan3",
        ]) );
        set("coor/x",-700);
        set("coor/y",-660);
        set("coor/z",20);
       set("outdoors", "wolfmount");
        set("objects",([
                __DIR__"npc/fwolfb":1,
                __DIR__"npc/fwolfc":1,
                __DIR__"npc/wenshun":1,
                __DIR__"npc/wenhe":1,
        ]) );
        setup();
        replace_program(ROOM);
}    