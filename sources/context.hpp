#ifndef __CONTEXT_H
#define __CONTEXT_H

struct Context
{
    FILE *fp;
    
    Context()
    {
        fp = nullptr;
    }
};

#endif
