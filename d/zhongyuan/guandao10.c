inherit ROOM;
void create()
{
  set("short","官道");
  set("long",@LONG
宽阔平坦的大道笔直地通向开封，道宽十余丈，路面上的黄土压得结结实实
，飞马驰过也只是轻起尘埃。道边是两排高大的垂杨柳。一队队商旅车队在大道
上首尾相连，望不到头，行人络绎不绝，谈吐服饰各异；不时有骑马的行人从身
边掠过，偶尔还有骑兵身背信囊，腰挂路牌疾驰而过。大道南北皆是肥沃的良田
，农夫，耕牛间处其间，四四方方的大田中间夹着几处大宅院和整齐的村镇。
LONG);
  set("exits",([
    "east"   : __DIR__"guandao11",
    "west"  : __DIR__"guandao9",
  ]));
    set("outdoors","zhongyuan");
  setup();
}

