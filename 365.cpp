#include "dbg.h"

bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
    return false;
    /*
        设置 x > y,

        0, x,y,x+y,这三者就不说了，装满
        1. x - ny 把x装满，一直往y里面倒
        2. x % y 把x装满，然后往y倒，倒到x空为止
        3. x + (x%y) 在2的基础上把x倒满
        4. y - (x % y) 一直装满y并往x倒水，倒满x，y自己剩下一点
        5. 4的基础上把x倒了并把y倒x上，y再加满


    */
}