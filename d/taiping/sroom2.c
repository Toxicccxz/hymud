 inherit ROOM;
void create()
{
        set("short", "���᷿");
        set("long", @LONG
�������쾮��һ��ƽ������һ�����߸ǣ������ϻ���͸�����������Ļ����¹�
��Ͷ�³�������Ӱ�������������ϣ�һ����һ�����ӣ����Ҳ�������ġ����겻����
ͣ������߷��Ĵ�������խ���ܣ�������ڹ�¡���ġ�
LONG
        );
        set("exits", ([ 
                "north": __DIR__"yuanzi",
        ]));
        set("item_desc", ([  
        ]));
        set("objects", ([
                __DIR__"npc/whiteman": 1,
                __DIR__"npc/whitewoman": 1,
        ]) );
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup(); 
}    