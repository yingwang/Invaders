//
//  Rockes.hpp
//  Invaders
//
//  Created by Ying Wang on 2017-03-26.
//  Copyright © 2017 Ying. All rights reserved.
//

#ifndef Rockes_hpp
#define Rockes_hpp

#include <list>
#include <sstream>
#include <vector>

#include "Rocket.hpp"
#include "Header.hpp"

class Rockets
{
private:
    std::list<std::shared_ptr<Rocket>> rocketList;
    std::vector<uint16_t> positions;
    
public:
    Rockets();
    void Add(std::shared_ptr<Rocket> rocket);
    void Update();
    void Draw() const;
    std::vector<uint16_t>& Positions();
    void Remove(const int row, const int col);
};

#endif /* Rockes_hpp */
