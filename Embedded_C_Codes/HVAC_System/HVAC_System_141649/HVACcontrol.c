#include "HVACcontrol.h

void Heater_Control(unsigned int tempV)
{
    unsigned int h;
    if(tempV<460)
        h=255;
    else if(tempV>=460 && tempV<512)
        h=214;
    else if(tempV>=512 && tempV<563)
        h=178;
    else if(tempV>=563 && tempV<614)
        h=142;
    else if(tempV>=614 && tempV<665)
        h=108;
    else if(tempV>=665 && tempV<716)
        h=72;
    else if(tempV>=716 && tempV<=720)
        h=36;
}

void Cooler_Control(unsigned int tempV)
{
    unsigned int c;
    if(tempV>=747 && tempV<757)
        c=36;
    else if(tempV>=757 && tempV<768)
        c=64;
    else if(tempV>=768 && tempV<788)
        c=92;
    else if(tempV>=788 && tempV<792)
        c=114;
    else if(tempV>=792 && tempV<819)
        c=142;
    else if(tempV>=819 && tempV<839)
        c=170;
    else if(tempV>=839 && tempV<849)
        c=195;
    else if(tempV>=849 && tempV<870)
        c=220;
    else if(tempV>=870 && tempV<890)
        c=240;
    else if(tempV>=890)
        c=255;
}

void Dehumid_Control()
{

}
