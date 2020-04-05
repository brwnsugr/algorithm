//
//  Point.h
//  practice
//
//  Created by Eun Ho Lee on 05/04/2020.
//  Copyright © 2020 Eun Ho Lee. All rights reserved.
//

#ifndef Point_hpp
#define Point_hpp

typedef struct _point // Declartion of Struct and named its name Point
{
    int xpos;
    int ypos;
} Point;

//Point 변수의 xpos, ypos 값 설정
void SetPointPos(Point * ppos, int xpos, int ypos);

//Point 변수의 xpos, ypos 정보 출력
void ShowPointPos(Point * ppos);

//두 Point 변수의 비교
int PointComp(Point * pos1, Point * pos2);

#endif /* Point_h */
