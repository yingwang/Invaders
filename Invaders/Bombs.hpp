//
//  Bombs.hpp
//  Invaders
//
//  Created by Ying Wang on 2017-03-26.
//  Copyright © 2017 Ying. All rights reserved.
//

#ifndef Bombs_hpp
#define Bombs_hpp

#include <list>
#include <sstream>
#include <vector>

#include "Bomb.hpp"
#include "Header.hpp"

class Bombs
{
private:
    std::list<std::shared_ptr<Bomb>> bombList;
    std::vector<uint16_t> positions;
    
public:
    Bombs();
    void Add(std::shared_ptr<Bomb> Bomb);
    void Update();
    void Draw() const;
    std::vector<uint16_t>& Positions();
    void Remove(const int row, const int col);
};

#endif /* Bombs_hpp */
