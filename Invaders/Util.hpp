//
//  Util.hpp
//  Invaders
//
//  Created by Ying Wang on 2017-04-05.
//  Copyright © 2017 Ying. All rights reserved.
//

#ifndef Util_h
#define Util_h

#define BIT_SET(a,b) ((a) |= (1<<(b)))
#define BIT_CLEAR(a,b) ((a) &= ~(1<<(b)))
#define BIT_FLIP(a,b) ((a) ^= (1<<(b)))
#define BIT_CHECK(a,b) ((a) & (1<<(b)))

#endif /* Util_h */
