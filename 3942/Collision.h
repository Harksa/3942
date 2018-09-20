#pragma once

//
//  SDL Game Programming Book
//
//  Created by shaun mitchell on 28/03/2013.
//  Copyright (c) 2013 shaun mitchell. All rights reserved.
//

#include <SDL2/SDL.h>

const static int s_buffer = 4;

/**
 * \brief Permet de déterminer la collision entre deux SDL_Rect
 */
static bool IntersectRect(SDL_Rect A, SDL_Rect B) {
	const int aHBuf = A.h / s_buffer;
	const int aWBuf = A.w / s_buffer;

	const int bHBuf = B.h / s_buffer;
	const int bWBuf = B.w / s_buffer;
    
    // if the bottom of A is less than the top of B - no collision
    if((A.y + A.h) - aHBuf <= B.y + bHBuf)  { return false; }
    
    // if the top of A is more than the bottom of B = no collision
    if(A.y + aHBuf >= (B.y + B.h) - bHBuf)  { return false; }
    
    // if the right of A is less than the left of B - no collision
    if((A.x + A.w) - aWBuf <= B.x +  bWBuf) { return false; }
    
    // if the left of A is more than the right of B - no collision
    if(A.x + aWBuf >= (B.x + B.w) - bWBuf)  { return false; }
    
    // otherwise there has been a collision
    return true;
}
