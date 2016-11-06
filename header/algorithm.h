#ifndef ALGORITHM_H
#define ALGORITHM_H

struct Algorithm {
    Algorithm() {};
    virtual unsigned compute(Grid* g) = 0;
}
#endif