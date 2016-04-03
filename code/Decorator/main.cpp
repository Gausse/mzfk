#include <iostream>
#include "classes.h"

int main(int argc, char *argv[])
{
    try
    {
        try
        {
            try
            {
                Exception* pEx = new Exception("Exception");
                throw pEx;
            }
            catch(Exception* pEx)
            {
                ChException* pChEx = new ChException("Child", pEx);
                throw pChEx;
            }
        }
        catch(ChException* pEx)
        {
            GrChException* pGrChEx = new GrChException("Grand", pEx);
            throw pGrChEx;
        }
    }
    catch(GrChException* pEx)
    {
        pEx->show();
        delete pEx;
    }

    return 0;
}
