inherit ROOM;
void create()
{
  set("short","崤山");
  set("long",@LONG
崤山之险，自古闻名。秦穆公时，大将孟明视等人率军进攻郑国，
在此遭到晋国的伏击，全军覆没。现在虽然在山中开辟了官道，仍偶
尔有强盗打劫，到了夜里，豺狼等野兽也四处活动。
LONG);
  set("exits",([
    "east"   : __DIR__"xiaoshan3",
    "west"   : __DIR__"xiaoshan1",
  ]));
     set("objects",([
           __DIR__"npc/wolf" : 1,
      ]));
       set("outdoors","zhongyuan");
  setup();
}

