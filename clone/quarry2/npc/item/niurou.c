#include <ansi.h>

inherit COMBINED_ITEM;
#include "meat.h"

void create()
{
        set_name(NOR + WHT "ţ��" NOR, ({ "niu rou", "niu", "rou" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", NOR + WHT "����һ��ɢ������������ţ�⡣\n" NOR);
                set("unit", "��");
                set("base_unit", "��");

                set("value", 340);
        }
        setup();
        set_amount(1);
}
