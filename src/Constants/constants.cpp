#include "constants.hpp"


int FLOORS[NUMBER_OF_LEVELS][LEVEL_HEIGHT][LEVEL_WIDTH] = { 
    {   // Level 1 floor
        { {0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, {0}, {0} },
        { {0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, {0}, {0} },
        { {0}, { 0}, { 9}, {10}, {10}, {10}, {10}, {10}, {10}, {10}, {10}, {10}, {10}, {10}, {10}, {10}, {10}, {10}, {10}, {11}, {0}, {0} },
        { {0}, { 0}, {17}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {19}, {0}, {0} },
        { {0}, { 0}, {17}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {19}, {0}, {0} },
        { {0}, { 0}, {25}, {26}, {26}, {26}, {26}, {26}, {26}, {26}, {26}, {26}, {26}, {26}, {26}, {26}, { 6}, {18}, {18}, {19}, {0}, {0} },
        { {0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, {17}, {18}, {18}, {19}, {0}, {0} },
        { {0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, {17}, {18}, {18}, {19}, {0}, {0} },
        { {0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, {17}, {18}, {18}, {19}, {0}, {0} },
        { {0}, { 0}, {25}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, {17}, {18}, {18}, {19}, {0}, {0} },
        { {0}, { 0}, { 9}, {10}, {10}, {10}, {10}, {10}, {10}, {10}, {10}, {10}, {10}, {10}, {10}, {10}, {14}, {18}, {18}, {19}, {0}, {0} },
        { {0}, { 0}, {17}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {19}, {0}, {0} },
        { {0}, { 0}, {25}, {26}, {26}, {26}, {26}, {26}, {26}, {26}, {26}, {26}, {26}, {26}, {26}, {26}, {26}, {26}, {26}, {27}, {0}, {0} },
        { {0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, {0}, {0} },
        { {0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, {0}, {0} },
    }, 
    {   // Level 2 floor
        { {0}, {0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, {0}, {0} }, 
        { {0}, {0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, {0}, {0} }, 
        { {0}, {0}, { 9}, {10}, {10}, {10}, {10}, {10}, {10}, {10}, {10}, {10}, {10}, {10}, {10}, {10}, {10}, {10}, {10}, {11}, {0}, {0} },
        { {0}, {0}, {17}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {19}, {0}, {0} },
        { {0}, {0}, {17}, {18}, {18}, {18}, {22}, {18}, {18}, {18}, {22}, {18}, {18}, {18}, {18}, {18}, { 5}, { 6}, {18}, {19}, {0}, {0} },
        { {0}, {0}, {17}, { 5}, {21}, { 5}, {26}, { 6}, {18}, {18}, {18}, {18}, {18}, {18}, { 5}, {26}, {21}, {18}, {18}, {19}, {0}, {0} },
        { {0}, {0}, {17}, {13}, {14}, {19}, { 0}, {17}, { 5}, { 6}, {18}, {18}, {18}, {18}, {19}, { 0}, {17}, {18}, {18}, {19}, {0}, {0} },
        { {0}, {0}, {17}, {18}, {18}, {19}, { 0}, {17}, {13}, {14}, {18}, {18}, {18}, {18}, {19}, { 0}, {17}, {18}, {18}, {19}, {0}, {0} },
        { {0}, {0}, {17}, {18}, {18}, {19}, { 0}, {17}, {18}, {18}, {18}, {18}, {18}, {18}, {19}, { 0}, {17}, {18}, {18}, {19}, {0}, {0} },
        { {0}, {0}, {17}, {18}, {18}, {19}, { 0}, {17}, {18}, {18}, {18}, {18}, { 5}, {21}, {19}, { 0}, {17}, {18}, {18}, {19}, {0}, {0} },
        { {0}, {0}, {17}, {18}, {18}, {13}, {10}, {14}, {18}, {18}, {18}, {18}, {13}, {14}, {13}, {10}, {14}, {18}, {18}, {19}, {0}, {0} },
        { {0}, {0}, {17}, {22}, {18}, {18}, {18}, {18}, {18}, {18}, {22}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {19}, {0}, {0} },
        { {0}, {0}, {25}, {26}, {26}, {26}, {26}, {26}, {26}, {26}, {26}, {26}, {26}, {26}, {26}, {26}, {26}, {26}, {26}, {27}, {0}, {0} },
        { {0}, {0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, {0}, {0} },
        { {0}, {0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, {0}, {0} },
    },
    {   // Level 3 floor
        { { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, {17}, {18}, {18}, {19}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0} }, 
        { { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, {17}, {18}, {18}, {19}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0} },
        { { 0}, { 0}, { 9}, {10}, {10}, {10}, {10}, {10}, {10}, {14}, {18}, {18}, {13}, {10}, {10}, {10}, {10}, {10}, {10}, {11}, { 0}, { 0} },
        { { 0}, { 0}, {17}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {19}, { 0}, { 0} },
        { { 0}, { 0}, {17}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {22}, {18}, {18}, {18}, {18}, {18}, {18}, {19}, { 0}, { 0} },
        { { 0}, { 0}, {17}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {19}, { 0}, { 0} },
        { {10}, {10}, {14}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {13}, {10}, {10} },
        { { 1}, { 2}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, { 2}, { 3} },
        { {26}, {26}, { 6}, {18}, {18}, {18}, {18}, {18}, { 5}, { 6}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, { 5}, {26}, {26} },
        { { 0}, { 0}, {17}, {18}, {18}, {18}, {18}, {18}, {13}, {14}, {18}, {18}, {18}, {18}, {22}, {18}, {18}, {18}, {18}, {19}, { 0}, { 0} },
        { { 0}, { 0}, {17}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {18}, {19}, { 0}, { 0} },
        { { 0}, { 0}, {25}, {26}, {26}, {26}, {26}, {26}, {26}, {26}, {26}, {26}, {26}, {26}, {26}, {26}, {26}, {26}, {26}, {27}, { 0}, { 0} },
        { { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0} },
        { { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0} },
        { { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0} }
    }
};

int LAVA[LEVEL_HEIGHT][LEVEL_WIDTH] = { 
        { {14}, {14}, {14}, {14}, {14}, {14}, {14}, {14}, { 8}, { 3}, { 3}, { 3}, { 3}, {12}, {14}, {14}, {14}, {14}, {14}, {14}, {14}, {14} },
        { {14}, {14}, {14}, {14}, {14}, {14}, {14}, {14}, { 8}, { 3}, { 3}, { 3}, { 3}, {12}, {14}, {14}, {14}, {14}, {14}, {14}, {14}, {14} }, 
        { {14}, { 8}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, {12}, {14} }, 
        { {14}, { 8}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, {12}, {14} },
        { {14}, { 8}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, {12}, {14} },
        { {14}, { 8}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, {12}, {14} },
        { { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3} },
        { { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3} },
        { { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3} },
        { { 7}, { 8}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, {12}, {14} },
        { {14}, { 8}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, {12}, {14} },
        { {14}, { 8}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, { 3}, {12}, {14} },
        { {14}, { 8}, { 9}, {10}, {11}, { 9}, {10}, {11}, { 9}, {10}, {11}, { 9}, {10}, {11}, { 9}, {10}, {11}, { 9}, {10}, {11}, {12}, {14} },
        { {14}, {15}, {16}, {17}, {18}, {16}, {17}, {18}, {16}, {17}, {18}, {16}, {17}, {18}, {16}, {17}, {18}, {16}, {17}, {18}, {19}, {14} }, 
        { {14}, {14}, {14}, {14}, {14}, {14}, {14}, {14}, {14}, {14}, {14}, {14}, {14}, {14}, {14}, {14}, {14}, {14}, {14}, {14}, {14}, {14} }
};

int MAPS[NUMBER_OF_LEVELS][LEVEL_HEIGHT][LEVEL_WIDTH] = { 
    {   // Level 1 map
        { {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16} },
        { {16}, { 3}, {13}, {13}, {13}, {13}, {13}, {13}, {13}, {13}, {13}, {13}, {13}, {13}, {13}, {13}, {13}, {13}, {13}, {13}, { 5}, {16} },
        { {16}, { 6}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, { 8}, {16} },
        { {16}, { 6}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, { 8}, {16} },
        { {16}, { 6}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, { 8}, {16} },
        { {16}, { 6}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, { 8}, {16} },
        { {16}, {12}, {13}, {13}, {13}, {13}, {13}, {13}, {13}, {13}, {13}, {13}, {13}, {13}, {13}, { 5}, {16}, {16}, {16}, {16}, { 8}, {16} },
        { {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, { 8}, {16}, {16}, {16}, {16}, { 8}, {16} },
        { {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, { 8}, {16}, {16}, {16}, {16}, { 8}, {16} },
        { {16}, { 3}, {13}, {13}, {13}, {13}, {13}, {13}, {13}, {13}, {13}, {13}, {13}, {13}, {13}, {14}, {16}, {16}, {16}, {16}, { 8}, {16} },
        { {16}, { 6}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, { 8}, {16} },
        { {16}, { 6}, {16}, {20}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, { 8}, {16} },
        { {16}, { 6}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, { 8}, {16} },
        { {16}, {12}, {13}, {13}, {13}, {13}, {13}, {13}, {13}, {13}, {13}, {13}, {13}, {13}, {13}, {13}, {13}, {13}, {13}, {13}, {14}, {16} },
        { {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16} }
    }, 
    {   // Level 2 map
        { {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16} },
        { {16}, { 3}, {13}, {13}, {13}, {13}, {13}, {13}, {13}, {13}, {13}, {13}, {13}, {13}, {13}, {13}, {13}, {13}, {13}, {13}, { 5}, {16} },
        { {16}, { 6}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, { 8}, {16} },
        { {16}, { 6}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, { 8}, {16} },
        { {16}, { 6}, {16}, {16}, {16}, { 3}, {13}, { 5}, {16}, {16}, {16}, {16}, {16}, {16}, { 3}, {13}, { 5}, {16}, {16}, {16}, { 8}, {16} },
        { {16}, { 6}, {16}, {16}, {16}, { 6}, {16}, { 8}, {16}, {16}, {16}, {16}, {16}, {16}, { 6}, {16}, { 8}, {16}, {16}, {16}, { 8}, {16} },
        { {16}, { 6}, {16}, {16}, {16}, { 6}, {16}, { 8}, {16}, {16}, {16}, {16}, {16}, {16}, { 6}, {16}, { 8}, {16}, {16}, {16}, { 8}, {16} },
        { {16}, { 6}, {20}, {16}, {16}, { 6}, {16}, { 8}, {16}, {16}, {16}, {16}, {16}, {16}, { 6}, {16}, { 8}, {16}, {16}, {20}, { 8}, {16} },
        { {16}, { 6}, {16}, {16}, {16}, { 6}, {16}, { 8}, {16}, {16}, {16}, {16}, {16}, {16}, { 6}, {16}, { 8}, {16}, {16}, {16}, { 8}, {16} },
        { {16}, { 6}, {16}, {16}, {16}, { 6}, {16}, { 8}, {16}, {16}, {16}, {16}, {16}, {16}, { 6}, {16}, { 8}, {16}, {16}, {16}, { 8}, {16} },
        { {16}, { 6}, {16}, {16}, {16}, {12}, {13}, {14}, {16}, {16}, {16}, {16}, {16}, {16}, {12}, {13}, {14}, {16}, {16}, {16}, { 8}, {16} },
        { {16}, { 6}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, { 8}, {16} },
        { {16}, { 6}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, { 8}, {16} },
        { {16}, {12}, {13}, {13}, {13}, {13}, {13}, {13}, {13}, {13}, {13}, {13}, {13}, {13}, {13}, {13}, {13}, {13}, {13}, {13}, {14}, {16} },
        { {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16} }    
    },
    {   // Level 3 map
        { {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, { 6}, {16}, {16}, { 8}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16} },
        { {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, { 6}, {16}, {16}, { 8}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16} }, 
        { {16}, {16}, { 3}, {13}, {13}, {13}, {13}, {13}, {13}, {23}, {16}, {16}, {17}, {13}, {13}, {13}, {13}, {13}, {13}, {13}, {29}, {16} },
        { {16}, {16}, { 6}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, { 6}, {16} },
        { {16}, {16}, { 6}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, { 6}, {16} },
        { {16}, {16}, { 6}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, { 6}, {16} },
        { {13}, {13}, {23}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {12}, {13} },
        { {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16} },
        { {13}, {13}, {29}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, { 3}, {13} },
        { {16}, {16}, { 6}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, { 6}, {16} },
        { {16}, {16}, { 6}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, { 6}, {16} },
        { {16}, {16}, { 6}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, { 6}, {16} },
        { {16}, {16}, {12}, {13}, {13}, {13}, {13}, {13}, {13}, {13}, {13}, {13}, {13}, {13}, {13}, {13}, {13}, {13}, {13}, {14}, {23}, {16} },
        { {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16} },
        { {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16}, {16} }    
    }
};

int PROPS[NUMBER_OF_LEVELS][LEVEL_HEIGHT][LEVEL_WIDTH] = { 
    {   // Level 1 props
        { {0}, { 0}, { 0}, {0}, {0}, { 0}, {0}, { 0}, {0}, {0}, { 0}, {0}, { 0}, {0}, { 0}, {0}, {0}, { 0}, {0}, {0}, {  0}, {0} },
        { {0}, { 0}, {26}, {0}, {0}, { 0}, {0}, {32}, {0}, {0}, { 0}, {0}, { 0}, {0}, {32}, {0}, {0}, { 0}, {0}, {0}, {  0}, {0} },
        { {0}, {33}, { 0}, {0}, {0}, { 0}, {0}, { 0}, {0}, {0}, { 0}, {0}, { 0}, {0}, { 0}, {0}, {0}, { 0}, {0}, {0}, {  0}, {0} },
        { {0}, { 0}, { 0}, {0}, {0}, { 0}, {0}, { 0}, {0}, {0}, { 0}, {0}, { 0}, {0}, { 0}, {0}, {0}, {24}, {0}, {0}, {-33}, {0} },
        { {0}, { 0}, { 0}, {0}, {0}, {31}, {0}, { 0}, {0}, {0}, {24}, {0}, { 0}, {0}, { 0}, {0}, {0}, { 0}, {0}, {0}, {  0}, {0} },
        { {0}, {33}, { 0}, {0}, {0}, { 0}, {0}, { 0}, {0}, {0}, { 0}, {0}, { 0}, {0}, { 0}, {0}, {0}, { 0}, {0}, {0}, {  0}, {0} },
        { {0}, { 0}, { 0}, {0}, {0}, { 0}, {0}, { 0}, {0}, {0}, { 0}, {0}, { 0}, {0}, { 0}, {0}, {0}, { 0}, {0}, {0}, {  0}, {0} },
        { {0}, { 0}, { 0}, {0}, {0}, { 0}, {0}, { 0}, {0}, {0}, { 0}, {0}, { 0}, {0}, { 0}, {0}, {0}, {24}, {0}, {0}, {  0}, {0} },
        { {0}, { 0}, { 0}, {0}, {0}, { 0}, {0}, { 0}, {0}, {0}, { 0}, {0}, { 0}, {0}, { 0}, {0}, {0}, { 0}, {0}, {0}, {-33}, {0} },
        { {0}, { 0}, { 0}, {0}, {0}, { 0}, {0}, {32}, {0}, {0}, { 0}, {0}, { 0}, {0}, {32}, {0}, {0}, { 0}, {0}, {0}, {  0}, {0} },
        { {0}, { 0}, { 0}, {0}, {0}, { 0}, {0}, { 0}, {0}, {0}, { 0}, {0}, { 0}, {0}, { 0}, {0}, {0}, { 0}, {0}, {0}, {  0}, {0} },
        { {0}, {33}, { 0}, {0}, {0}, { 0}, {0}, { 0}, {0}, {0}, { 0}, {0}, {24}, {0}, { 0}, {0}, {0}, { 0}, {0}, {0}, {  0}, {0} },
        { {0}, { 0}, { 0}, {0}, {0}, { 0}, {0}, { 0}, {0}, {0}, { 0}, {0}, { 0}, {0}, { 0}, {0}, {0}, { 0}, {0}, {0}, {  0}, {0} },
        { {0}, { 0}, { 0}, {0}, {0}, { 0}, {0}, { 0}, {0}, {0}, { 0}, {0}, { 0}, {0}, { 0}, {0}, {0}, { 0}, {0}, {0}, {  0}, {0} },
        { {0}, { 0}, { 0}, {0}, {0}, { 0}, {0}, { 0}, {0}, {0}, { 0}, {0}, { 0}, {0}, { 0}, {0}, {0}, { 0}, {0}, {0}, {  0}, {0} }
    },
    {   // Level 2 props
        { {0}, { 0}, { 0}, { 0}, { 0}, { 0}, {0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, {0}, { 0}, {0}, {0}, { 0}, { 0}, {0}, {  0}, {0} },
        { {0}, { 0}, { 0}, {32}, { 0}, { 0}, {0}, { 0}, { 0}, {32}, {26}, {32}, { 0}, {0}, { 0}, {0}, {0}, {32}, { 0}, {0}, {  0}, {0} },
        { {0}, {33}, { 0}, { 0}, { 0}, { 0}, {0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, {0}, { 0}, {0}, {0}, { 0}, { 0}, {0}, {-33}, {0} },
        { {0}, { 0}, { 0}, { 0}, { 0}, {24}, {0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, {0}, {24}, {0}, {0}, { 0}, { 0}, {0}, {  0}, {0} },
        { {0}, { 0}, { 0}, { 0}, { 0}, { 0}, {0}, { 0}, { 0}, { 0}, {24}, { 0}, { 0}, {0}, { 0}, {0}, {0}, { 0}, { 0}, {0}, {  0}, {0} },
        { {0}, { 0}, {24}, { 0}, { 0}, { 0}, {0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, {0}, { 0}, {0}, {0}, { 0}, { 0}, {0}, {  0}, {0} },
        { {0}, { 0}, { 0}, { 0}, { 0}, { 0}, {0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, {0}, { 0}, {0}, {0}, { 0}, { 0}, {0}, {  0}, {0} },
        { {0}, {33}, { 0}, { 0}, { 0}, { 0}, {0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, {0}, { 0}, {0}, {0}, {24}, { 0}, {0}, {-33}, {0} },
        { {0}, { 0}, { 0}, { 0}, { 0}, { 0}, {0}, { 0}, {24}, { 0}, { 0}, { 0}, { 0}, {0}, { 0}, {0}, {0}, { 0}, { 0}, {0}, {  0}, {0} },
        { {0}, { 0}, { 0}, { 0}, { 0}, { 0}, {0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, {0}, { 0}, {0}, {0}, { 0}, { 0}, {0}, {  0}, {0} },
        { {0}, { 0}, { 0}, { 0}, { 0}, { 0}, {0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, {0}, { 0}, {0}, {0}, { 0}, { 0}, {0}, {  0}, {0} },
        { {0}, { 0}, { 0}, { 0}, { 0}, { 0}, {0}, { 0}, { 0}, { 0}, { 0}, { 0}, {24}, {0}, { 0}, {0}, {0}, { 0}, { 0}, {0}, {  0}, {0} },
        { {0}, {33}, { 0}, {24}, { 0}, { 0}, {0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, {0}, { 0}, {0}, {0}, { 0}, {31}, {0}, {-33}, {0} },
        { {0}, { 0}, { 0}, { 0}, { 0}, { 0}, {0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, {0}, { 0}, {0}, {0}, { 0}, { 0}, {0}, {  0}, {0} },
        { {0}, { 0}, { 0}, { 0}, { 0}, { 0}, {0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, {0}, { 0}, {0}, {0}, { 0}, { 0}, {0}, {  0}, {0} }
    }, 
    // Level 3 props
    {
        { { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, {  0}, { 0}, { 0} },
        { { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, {  0}, { 0}, { 0} },
        { { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, {32}, { 0}, { 0}, { 0}, { 0}, {32}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, {  0}, { 0}, { 0} },
        { { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, {  0}, { 0}, { 0} },
        { { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, {  0}, { 0}, { 0} },
        { { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, {  0}, { 0}, { 0} },
        { { 0}, { 0}, {33}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, {-33}, { 0}, { 0} },
        { { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, {24}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, {  0}, { 0}, { 0} },
        { { 0}, { 0}, {33}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, {-33}, { 0}, { 0} },
        { { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, {  0}, { 0}, { 0} },
        { { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, {  0}, { 0}, { 0} },
        { { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, {20}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, {  0}, { 0}, { 0} },
        { { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, {  0}, { 0}, { 0} },
        { { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, {  0}, { 0}, { 0} },
        { { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, { 0}, {  0}, { 0}, { 0} }
    }
};

// Sound Constants

std::filesystem::path gamebgmpath[3] = { // bgm paths
    "../resources/MiniFantasy_Dungeon_Music/Music/Goblins_Dance_(Battle).wav",
    "../resources/MiniFantasy_Dungeon_Music/Music/Goblins_Dance_(Battle).wav",
    "../resources/BossFight.wav"
};

const sf::Time timers[] = { // level timers
    sf::seconds(60),
    sf::seconds(60),
    sf::seconds(90)
};

const sf::Vector2f characterSpawns[3] = { // character spawn points in each level
    sf::Vector2f(TILE_SIZE * SCALE * 3.5f, TILE_SIZE * SCALE * 11),
    sf::Vector2f(TILE_SIZE * SCALE * 2.5f, TILE_SIZE * SCALE * 7),
    sf::Vector2f(TILE_SIZE * SCALE * 10.5f, (TILE_SIZE * SCALE * 11 - 7.f))
};

const sf::FloatRect EnemySpawns[NUMBER_OF_LEVELS][3] = { // enemy spawns based on levels; max 3 spawns
    {// level 1
        sf::FloatRect({4 * TILE_SIZE * SCALE, 3 * TILE_SIZE * SCALE},{2 * SCALE * TILE_SIZE, 2 * SCALE * TILE_SIZE}),
        sf::FloatRect(),
        sf::FloatRect()
    },
    {// Level 2
        sf::FloatRect({10 * TILE_SIZE * SCALE, 5 * TILE_SIZE * SCALE},{4 * TILE_SIZE * SCALE, 7 * TILE_SIZE *SCALE}),
        sf::FloatRect({18 * TILE_SIZE * SCALE, 10 * TILE_SIZE * SCALE},{ 2 * TILE_SIZE * SCALE, 2 * TILE_SIZE * SCALE}),
        sf::FloatRect()
    },
    { // level 3
        sf::FloatRect({10 * TILE_SIZE * SCALE, 0},{2 * TILE_SIZE * SCALE, 2 * TILE_SIZE * SCALE}), // top spawn
        sf::FloatRect({0, 7 * TILE_SIZE * SCALE},{2 * TILE_SIZE * SCALE, .5f * TILE_SIZE * SCALE}), // left spawn
        sf::FloatRect({20 * TILE_SIZE * SCALE, 7 * TILE_SIZE * SCALE},{2 * TILE_SIZE * SCALE, .5f * TILE_SIZE * SCALE}) // right spawn
    }
}; 