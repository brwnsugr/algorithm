//
//  Point.cpp
//  practice
//
//  Created by Eun Ho Lee on 05/04/2020.
//  Copyright © 2020 Eun Ho Lee. All rights reserved.
//

#include <stdio.h>
#include "Point.hpp"

void SetPointPos(Point * ppos, int xpos, int ypos){
    ppos->xpos = xpos;
    ppos->ypos = ypos;
}

void ShowPointPos(Point * ppos){
    printf("[%d, %d] \n", ppos->xpos, ppos->ypos);
}

int PointComp(Point * pos1, Point * pos2){
    if(pos1->xpos == pos2->xpos && pos1->xpos != pos2->ypos){
        return 1;
    }
    else if(pos1->ypos == pos2->ypos && pos1->xpos != pos2->xpos){
        return 2;
    }
    else if(pos1->xpos == pos2->xpos && pos1->ypos == pos2->ypos){
        return 0;
    }
    else{
        return -1;
    }
    
}
