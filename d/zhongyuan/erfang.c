inherit ROOM;
void create()
{
  set("short","阿房旧址");
  set("long",@LONG
秦始皇灭六国后，因为不满足于原来宫殿的规模，曾在此地建起了“上可坐
万人，下可建五行旗”的阿房宫。谁料仅仅几年后，便在项羽点起的一场大火中
毁灭殆尽。如今宫殿早已荡然无存，只剩路南山脚下一块平坦的地基，还在向过
往的行人讲述着古老的故事。
LONG);
  set("exits",([
    "southeast"   : __DIR__"beijiao",
    "west"   : __DIR__"guandao2",
  ]));
   set("outdoors","zhongyuan");
   setup();
}

