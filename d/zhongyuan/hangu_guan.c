inherit ROOM;
void create()
{
  set("short","函谷关");
  set("long",@LONG
函谷关东自崤山，西至潼关，因深险如函而得名，号称天险。战国时，六国
合纵攻秦，数十万人在关外耀武扬威地驻扎了几个月也没能攻破，只好各自散去
。函谷屯兵，就成了战国“六雄”的最后一次“回光返照”。
LONG);
  set("exits",([
    "east"   : __DIR__"xiaoshan1",
    "northwest"   : __DIR__"tongguan",
  ]));
   set("outdoors","zhongyuan");
  setup();
}

